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

    setCriticalTreshold(crit_sum);

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

int calculator::GetSumOfAccModifiers()
{
    AdditionalItemAndDifficulty.clear();
    int acc_sum = 0;
    for(int i=0;i<ui->tableWidget_AccMod->rowCount();i++)
    {
        QSpinBox *spinbox = qobject_cast<QSpinBox*>(ui->tableWidget_AccMod->cellWidget(i,1));
        acc_sum += spinbox->value();

        C_ItemModificator item;
        item.name = ui->tableWidget_AccMod->item(i,0)->text();
        item.value = spinbox->value();
        AdditionalItemAndDifficulty.append(item);
    }
    return acc_sum;
}

int calculator::GetSumOfDmgModifiers()
{
    AdditionalItemAndDamage.clear();
    int dmg_sum = 0;
    for(int i=0;i<ui->tableWidget_DmgMod->rowCount();i++)
    {
        QSpinBox *spinbox = qobject_cast<QSpinBox*>(ui->tableWidget_DmgMod->cellWidget(i,1));
        dmg_sum += spinbox->value();

        C_ItemModificator item;
        item.name = ui->tableWidget_DmgMod->item(i,0)->text();
        item.value = spinbox->value();
        AdditionalItemAndDamage.append(item);
    }
    return dmg_sum;
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

    difficulty_value += GetSumOfAccModifiers();

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

