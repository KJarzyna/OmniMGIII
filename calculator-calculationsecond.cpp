#include "calculator.h"
#include "ui_calculator.h"

//CALCULATION PART 2
void calculator::PopUpDicesQuestion()
{
    dialogbox_postcalculation *box = new dialogbox_postcalculation();
    box->setAttribute(Qt::WA_DeleteOnClose);
    if(GetCurrentActionID() == 1 || GetCurrentActionID() == 2 )
        box->InitializeDices(4);
    else
        box->InitializeDices(1);
    box->show();
    connect(box,SIGNAL(DiceResults(QVector<int>)),this,SLOT(GetDiceResults(QVector<int>)));
    connect(box,SIGNAL(DialogBoxClosed()),this,SLOT(DiceDialogBoxClosed()));
}

void calculator::DiceDialogBoxClosed()
{
    setEnableAfterSecondCalculations(true);
    setVisualTextToSecondWidget(GetFinalVisualTextFromSelectedInfo());
}

int calculator::GetNumberOfSuccess()
{
    int numOfsuccess = 0;
    for(int i=0;i<dice_results.size();i++)
        if(dice_results.at(i) < successTreshold)
            numOfsuccess++;
   return numOfsuccess;
}

bool calculator::isCriticalHit()
{
    //check for Critical Hit on number of dices (numDices)

    if(GetNumberOfSuccess() > 0)
    {
        if(dice_results.at(0) < criticalTreshold)
            return true;
        return false;
    }
    else
        return false;
}

int calculator::GetBaseDamageDealt()
{
    int damage = 0;
    if(isActionWeaponRelated(GetCurrentActionID()))
    {
        damage = GetWeaponBaseDamageFromWeaponID(selectedActionItemID);

    }
    else if(isActionSkillRelated(GetCurrentActionID()))
    {
        if(isPlayerHasShield(selectedTargetID))
            damage = GetSkillDamageToShieldFromSkillID(selectedActionItemID);
        else
            damage = GetSkillDamageToArmorFromSkillID(selectedActionItemID);
    }
    else if(isActionMeeleeRelated(GetCurrentActionID()))
    {
        if(GetCurrentActionID() == 10)
            damage = GetLightMeeleeDamageFromPlayerRace(selectedPlayerID);
        else
            damage = GetHeavyMeeleeDamageFromPlayerRace(selectedPlayerID);

    }

    return damage;

}

int calculator::GetModifiedBaseDamageDealt()
{
    //Base damage + armor/special weapon effects/special ammo + Dmg Modifiers
    int damage = GetBaseDamageDealt();

    if(isActionWeaponRelated(GetCurrentActionID()) && !isPlayerHasShield(selectedTargetID))
        GetWeaponDamageToArmorFromWeaponID(selectedActionItemID);
    else if (isActionWeaponRelated(GetCurrentActionID()) && isPlayerHasShield(selectedTargetID))
        GetWeaponDamageToShieldFromWeaponID(selectedActionItemID);
    else if(isActionMeeleeRelated(GetCurrentActionID()))
        GetOmnibladeDamageFromOmnibladeID(selectedActionItemID);

    GetSumOfWidgetDmgModifiers();
    SumAllDamageModificators();

    for(int i=0;i<SumItemAndDamage.size();i++)
        damage += SumItemAndDamage.at(i).value;

    return damage;
}

int calculator::GetFinalDamageDealt()
{
    //DamageModified + crits, number of success
    int damage = GetModifiedBaseDamageDealt();

    if(dice_results.size()>1)
        damage = floor(damage*GetNumberOfSuccess()*0.25);

    if(isCriticalHit())
        damage = floor(damage*1.3);
    return damage;
}

void calculator::ImplementAfterCalculationChanges()
{
    int actionID = GetCurrentActionID();

    //Perform changes to player armor/shield after taking damage
    if(isActionDealDamage(actionID) && GetNumberOfSuccess() > 0 && !isActionMeeleeRelated(actionID))
    {
        int damage_dealt = GetFinalDamageDealt();

        if(isPlayerHasShield(selectedTargetID))
            setPlayerCurrentShield(selectedTargetID,GetPlayerShieldCurrentAfterDamage(selectedTargetID,damage_dealt));
        else
            setPlayerCurrentArmor(selectedTargetID,GetPlayerArmorCurrentAfterDamage(selectedTargetID,damage_dealt));

        if(isActionWeaponRelated(actionID))
            subtractAmmoFromPlayerWeapon(selectedPlayerID,selectedActionItemID);
    }
    //Perform changes to player armor after taking meelee damage
    else if(isActionMeeleeRelated(actionID) && GetNumberOfSuccess() > 0)
    {
        int damage_dealt = GetFinalDamageDealt();
        setPlayerCurrentArmor(selectedTargetID,GetPlayerArmorCurrentAfterDamage(selectedTargetID,damage_dealt));
    }
    //Shield regeneration
    else if(actionID == 6)
    {
        setPlayerCurrentShield(selectedPlayerID,GetPlayerMaxShield(selectedPlayerID));
    }
    //Armor regeneration
    else if(actionID == 9)
    {
        int playerID = 9999;
        if(selectedActionItemID == 0)
            playerID = selectedPlayerID;
        else if(selectedActionItemID == 1)
            playerID = selectedTargetID;

        int armorRepaired = GetPlayerMaxArmor(playerID)*(0.2 + GetPlayerTechnoBuffFromOmnikey(selectedPlayerID)*0.01);
        int armorNew = GetPlayerArmorCurrentAfterDamage(playerID,-armorRepaired);
        setPlayerCurrentArmor(playerID,armorNew);
    }
    //Weapon reloaded
    else if(actionID == 5)
    {
        reloadPlayerWeapon(selectedPlayerID,selectedActionItemID);
    }

    //Add effect to target
    if(isActionSkillRelated(actionID) && GetSkillTargetFromSkillID(selectedActionItemID) == "target" && GetNumberOfSuccess() > 0 && isSkillEffectApplicableToPlayer(selectedTargetID,selectedActionItemID))
    {
        for(int i=0;i<GetSkillEffectsFromSkillID(selectedActionItemID).size();i++)
            AddEffectToPlayer(selectedTargetID,GetSkillEffectsFromSkillID(selectedActionItemID).at(i));
    }
    //Add effect to player
    else if(isActionSkillRelated(actionID) && GetSkillTargetFromSkillID(selectedActionItemID) == "self" && GetNumberOfSuccess() > 0 && isSkillEffectApplicableToPlayer(selectedTargetID,selectedActionItemID))
    {
        for(int i=0;i<GetSkillEffectsFromSkillID(selectedActionItemID).size();i++)
            AddEffectToPlayer(selectedPlayerID,GetSkillEffectsFromSkillID(selectedActionItemID).at(i));
        setVisualPlayerActiveEffects(selectedPlayerID);
    }
    //Add "Ranny" to player
    if(isActionDealDamage(actionID) && GetNumberOfSuccess() > 0 && (!isPlayerHasShield(selectedTargetID) || isActionMeeleeRelated(actionID)))
        if(GetPlayerArmorCurrentAfterDamage(selectedTargetID,0) < GetPlayerMaxArmor(selectedTargetID)*0.5)
        {
            if(GetPlayerActiveEffectsIDs(selectedTargetID).contains(0))
            {
                RemoveEffectFromPlayer(selectedTargetID,0);
                AddEffectToPlayer(selectedTargetID,1);
            }
            else if(!GetPlayerActiveEffectsIDs(selectedTargetID).contains(1))
                AddEffectToPlayer(selectedTargetID,0);
        }
}
