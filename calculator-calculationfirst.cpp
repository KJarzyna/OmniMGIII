#include "calculator.h"
#include "ui_calculator.h"

//CALCULATION
void calculator::CalculateSuccessTresholdForActionID(int actionID)
{

    int success = GetBaseSuccessTreshold(actionID);
    int difficulty = GetDifficultyModifierFromValue(GetFinalDifficultyValueForActionID(actionID));
    int armor = GetActionAccModifierForActionIDandPlayerID(actionID,selectedPlayerID);
    int weapon_acc = 0;
    int skill_acc = 0;

    if(isActionWeaponRelated(actionID))
        weapon_acc = GetWeaponAccFromWeaponID(selectedActionItemID);
    else if(isActionMeeleeRelated(actionID))
        weapon_acc = GetOmnibladeAccFromOmnibladeID(GetPlayersOmnibladeID(selectedPlayerID));
    else if(isActionSkillRelated(actionID) || isActionAmmoRelated(actionID))
        skill_acc = GetSkillAccFromSkillID(selectedActionItemID);

    int treshold = success + weapon_acc + difficulty + armor + skill_acc;
    if(treshold > 90)
        treshold = 90;
    else if(treshold < 0)
        treshold = 0;
    setSuccessTreshold(treshold);
}

void calculator::CalculateCriticalTresholdForActionID(int actionID)
{
    int base = 5;
    int crit_sum = base + GetPlayersArmorCriticalChanceModifier(selectedPlayerID);

    for(int i=0;i<AdditionalItemAndCritical.size();i++)
        crit_sum+=AdditionalItemAndCritical.at(i).value;

    setCriticalTreshold(crit_sum);

}

void calculator::CalculateFinalActionCostForActionID(int actionID)
{
    int cost = 100;
    if(actionID != 7)
        cost = GetActionCostFromActionID(actionID);
    else
        cost = GetSkillCostFromSkillID(selectedActionItemID);

   if(GetPlayersArmorCostReduction(selectedPlayerID) != 0)
       cost = cost + GetPlayersArmorCostReduction(selectedPlayerID);

   SumAllActionCostModificators();

    if(!SumItemAndActionCost.isEmpty())
        for(int i=0;i<SumItemAndActionCost.size();i++)
            cost += SumItemAndActionCost.at(i).value;

    QString actionType = GetActionTypeFromActionCost(cost);
    setSelectedActionCostName(actionType);
}

int calculator::GetBaseSuccessTreshold(int actionID)
{
    int success;
    if(isActionWeaponRelated(actionID)) // Get base success for weapons
    {
        success = 50;
    }
    else if(isActionSkillRelated(actionID)) // Get base success for skills
    {
        if (!selectedActionItemName.contains(GetPlayerSpecializationSkill(selectedPlayerID)))
            success = GetPlayerSkillMastery(selectedPlayerID,GetSkillTypeFromSkillID(selectedActionItemID));
        else
            success = GetPlayerSkillMastery(selectedPlayerID,"Specjalizacja");
    }
    else if(isActionMeeleeRelated(actionID)) // Get base success for omniblades
    {
        success = GetPlayerEvasiveness(selectedTargetID);
    }
    else if(isActionAmmoRelated(actionID)) // // Get base success for special ammo activation
    {
        success = GetPlayerSkillMastery(selectedPlayerID,"Bojowe");
    }
    else
    {
       success = 0;
    }

    return success;
}

int calculator::GetSumOfWidgetDiffModifiers()
{
    WidgetItemAndDifficulty.clear();
    int acc_sum = 0;
    for(int i=0;i<ui->tableWidget_AccMod->rowCount();i++)
    {
        QSpinBox *spinbox = qobject_cast<QSpinBox*>(ui->tableWidget_AccMod->cellWidget(i,1));
        C_ItemModificator item;
        item.name = ui->tableWidget_AccMod->item(i,0)->text();
        item.value = spinbox->value();
        WidgetItemAndDifficulty.append(item);
    }

    for(int i=0;i<WidgetItemAndDifficulty.size();i++)
        acc_sum += WidgetItemAndDifficulty.at(i).value;

    return acc_sum;
}

int calculator::GetSumOfWidgetDmgModifiers()
{
    WidgetItemAndDamage.clear();
    int dmg_sum = 0;
    for(int i=0;i<ui->tableWidget_DmgMod->rowCount();i++)
    {
        QSpinBox *spinbox = qobject_cast<QSpinBox*>(ui->tableWidget_DmgMod->cellWidget(i,1));

        C_ItemModificator item;
        item.name = ui->tableWidget_DmgMod->item(i,0)->text();
        item.value = spinbox->value();
        WidgetItemAndDamage.append(item);
    }

    for(int i=0;i<WidgetItemAndDamage.size();i++)
        dmg_sum += WidgetItemAndDamage.at(i).value;

    return dmg_sum;
}

int calculator::GetSumOfAdditionalDiffModifiers()
{
    int acc_sum = 0;

    for(int i=0;i<AdditionalItemAndDifficulty.size();i++)
        acc_sum += AdditionalItemAndDifficulty.at(i).value;

    return acc_sum;
}

int calculator::GetDifficultyValueFromName(QString diff_name)
{
    if(diff_name == "Bardzo łatwy")
        return 1;
    else if(diff_name == "Łatwy")
        return 2;
    else if(diff_name == "Normalny")
        return 3;
    else if(diff_name == "Trudny")
        return 4;
    else if(diff_name == "Bardzo trudny")
        return 5;
    else if(diff_name == "Niemożliwy")
        return 6;
    else
        return 99;
}

int calculator::GetDifficultyModifierFromValue(int val)
{
    switch(val)
    {
    case 1:
        return 30;
    case 2:
        return 15;
    case 3:
        return 0;
    case 4:
        return -15;
    case 5:
        return -30;
    case 6:
        return -50;
    default:
        return 9999;
    }
}

int calculator::GetFinalDifficultyValueForActionID(int actionID)
{
    int difficulty_value = GetDifficultyValueFromName(difficulty_level_name);

    if(isActionWeaponRelated(actionID)) // Weapons
    {
        difficulty_value += GetPlayersArmorWpnDiffLevelModifier(selectedPlayerID);
    }
    else if(isActionSkillRelated(actionID)) // Skills
    {
        difficulty_value += GetPlayersArmorSkillDiffLevelModifier(selectedPlayerID);
    }
    else if(isActionMeeleeRelated(actionID)) // Meelee (base of player evasiveness + weapon acc)
    {
        difficulty_value += GetPlayersArmorMeeleeDiffLevelModifier(selectedPlayerID);
    }
    else if(isActionAmmoRelated(actionID)) // Ammo
    {
        difficulty_value += GetPlayersArmorSkillDiffLevelModifier(selectedPlayerID);
    }
    else
    {
        difficulty_value = difficulty_value;
    }

    difficulty_value += GetSumOfWidgetDiffModifiers();
    difficulty_value += GetSumOfAdditionalDiffModifiers();

    if(difficulty_value < 1)
        difficulty_value = 1;
    else if(difficulty_value > 6)
        difficulty_value = 6;

    return difficulty_value;

}

QString calculator::GetDifficultyNameFromValue(int val)
{
    if(val == 1)
        return "Bardzo łatwy";
    else if(val == 2)
        return "Łatwy";
    else if(val == 3)
        return "Normalny";
    else if(val == 4)
        return "Trudny";
    else if(val == 5)
        return "Bardzo trudny";
    else if(val == 6)
        return "Niemożliwy";
    else
        return "Nieznany";
}

QString calculator::GetDiceTypeForActionID(int actionID)
{
    if(actionID == 1 || actionID == 2)
        return "4d100";
    else
        return "1d100";
}

bool calculator::CheckForWarnings()
{
    //Player Don't Have Enough Ammo
    if(isActionWeaponRelated(GetCurrentActionID()) && GetAmmoLeftInPlayersWeapon(selectedPlayerID,selectedActionItemID) == 0)
    {
        QString warning = selectedPlayerName + " nie posiada pocisków w magazynku " + selectedActionItemName + "!";
        PopUpWarning(warning);
        return false;
    }

    //Player Don't Have Shield and Can't Use Dirsuptor
    if(isActionSkillRelated(GetCurrentActionID()) && selectedActionItemID > 88 && selectedActionItemID < 110 && !isPlayerHasShield(selectedPlayerID))
    {
        QString warning = selectedPlayerName + " nie posiada tarcz! Nie można skorzystać z Dysruptora Fazowego!";
        PopUpWarning(warning);
        return false;
    }

    //Player is under Sabotage
    if(isActionWeaponRelated(GetCurrentActionID()) && isPlayerHasEffect(selectedPlayerID,166))
    {
        QString warning = selectedPlayerName + " nie może oddać strzału! Broń pod efektem Sabotażu!";
        PopUpWarning(warning);
        return false;
    }

    //Player is under Ogłuszenie
    if(isPlayerHasEffect(selectedPlayerID,3))
    {
        QString warning = selectedPlayerName + " nie może wykonywać akcji, bo jest pod efektem Ogłuszenia!";
        PopUpWarning(warning);
        return false;
    }
    return true;
}

void calculator::PopUpWarning(QString text)
{
    dialogbox_warning_generic *box = new dialogbox_warning_generic();
    box->setAttribute(Qt::WA_DeleteOnClose);
    box->setWarningLabel(text);
    box->show();
}

void calculator::setCriticalTreshold(int treshold)
{
    criticalTreshold = treshold;
}

void calculator::SumAllDifficultyModificators()
{
    SumItemAndDifficulty.clear();
    for(int i=0;i<ItemAndDifficulty.size();i++)
        SumItemAndDifficulty.append(ItemAndDifficulty.at(i));
    for(int i=0;i<WidgetItemAndDifficulty.size();i++)
        SumItemAndDifficulty.append(WidgetItemAndDifficulty.at(i));
    for(int i=0;i<AdditionalItemAndDifficulty.size();i++)
        SumItemAndDifficulty.append(AdditionalItemAndDifficulty.at(i));
}

void calculator::SumAllDamageModificators()
{
    SumItemAndDamage.clear();
    for(int i=0;i<ItemAndDamage.size();i++)
        SumItemAndDamage.append(ItemAndDamage.at(i));
    for(int i=0;i<WidgetItemAndDamage.size();i++)
        SumItemAndDamage.append(WidgetItemAndDamage.at(i));
    for(int i=0;i<AdditionalItemAndDamage.size();i++)
        SumItemAndDamage.append(AdditionalItemAndDamage.at(i));
}

void calculator::SumAllActionCostModificators()
{
    SumItemAndActionCost.clear();
    for(int i=0;i<ItemAndActionCost.size();i++)
        SumItemAndActionCost.append(ItemAndActionCost.at(i));
    for(int i=0;i<AdditionalItemAndActionCost.size();i++)
        SumItemAndActionCost.append(AdditionalItemAndActionCost.at(i));
}
