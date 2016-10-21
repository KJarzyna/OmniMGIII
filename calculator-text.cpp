#include "calculator.h"
#include "ui_calculator.h"

//TEXT
QString calculator::GetVisualTextFromSelectedInfo()
{
    QString full_text;

    full_text = GetVisualHeader();
    full_text += "<br>";
    if(isActionHasSuccessCheck(GetCurrentActionID()))
    {
        full_text += GetVisualSuccessCheck();
        full_text += "<br><br>";
        full_text += "Szansa na sukces przy: &lt;";
        full_text += QString::number(successTreshold);
        full_text += "%";
        full_text += "<br>";
        full_text += GetVisualCriticalCheck();
        for(int i=0;i<GetVisualEffectCheck().size();i++)
            full_text += GetVisualEffectCheck().at(i);

        full_text += "<br><br>";
        full_text += "[dice]";
        full_text += GetDiceTypeForActionID(GetCurrentActionID());
        full_text += "[/dice]";

        //full_text += "<br><br>";
        //full_text += GetVisualCalculationSteps();
    }

    return full_text;
}

QString calculator::GetFinalVisualTextFromSelectedInfo()
{
    QString full_text;

    if(isActionHasSuccessCheck(GetCurrentActionID()))
    {

        full_text = GetVisualSuccessResult();
        full_text += "<br>";

        full_text += GetVisualDamageResult();

        full_text += GetVisualTargetArmorAndShieldLeftResult();

        full_text += "<br><br>";
        full_text += GetVisualCalculationSteps();
    }
    else if(GetCurrentActionID() == 6 || GetCurrentActionID() == 9) // Generator Regeneration or Omni Usage
    {
        full_text += GetVisualTargetArmorAndShieldLeftResult();
    }
    else
        full_text = "Brak innych obliczeń do wykonania.";

    return full_text;
}

QString calculator::GetVisualHeader()
{
    QString header;
    QString player = "<font color=#FF8000> " + selectedPlayerName + "</font>";
    QString action = "<font color=#0080FF> [" + selectedActionName.toUpper() + "]</font>";
    QString cost = "<font color=#0080FF> [" + selectedActionCostName + "]</font>";
    QString target = "";
    if(isActionNeedTarget(GetCurrentActionID()))
        target = "<font color=#FF0000> [CEL: " + selectedTargetName + "]</font>";

    header = player + action + cost + target;
    return header;
}

QString calculator::GetVisualSuccessCheck()
{
    int currentActionID = GetCurrentActionID();

    if(isActionHasSuccessCheck(currentActionID))
    {
        QString success;
        success.append(QString::number(GetBaseSuccessTreshold(currentActionID)));

        if(isActionWeaponRelated(currentActionID))
        {
            success.append(" + ");
            success.append(QString::number(GetWeaponAccFromWeaponID(selectedActionItemID)));
            success.append(" [Celność]");

            if(GetPlayersArmorWpnAccModifier(selectedPlayerID) != 0)
            {
                success.append(" + ");
                success.append(QString::number(GetPlayersArmorWpnAccModifier(selectedPlayerID)));
                success.append(" [Pancerz]");
            }
        }
        else if(isActionMeeleeRelated(currentActionID))
        {
            success.append(" + ");
            success.append(QString::number(GetOmnibladeAccFromOmnibladeID(GetPlayersOmnibladeID(selectedPlayerID))));
            success.append(" [Celność omni-ostrza]");
        }

        else if(isActionSkillRelated(currentActionID) || isActionAmmoRelated(currentActionID))
        {
            if(GetSkillAccFromSkillID(selectedActionItemID) != 0)
            {
                success.append(" + ");
                success.append(QString::number(GetSkillAccFromSkillID(selectedActionItemID)));
                success.append(" [Poziom zdolności]");
            }

            if(GetPlayersArmorSkillAccModifier(selectedPlayerID) != 0)
            {
                success.append(" + ");
                success.append(QString::number(GetPlayersArmorSkillAccModifier(selectedPlayerID)));
                success.append(" [Pancerz]");
            }
        }

        success.append(" + ");
        success.append(QString::number(GetDifficultyModifierFromValue(GetFinalDifficultyValueForActionID(currentActionID))));
        success.append(" [Poziom ");
        success.append(GetDifficultyNameFromValue(GetFinalDifficultyValueForActionID(currentActionID)));
        success.append("]");

        success.append(" = ");
        success.append(QString::number(successTreshold));
        success.append("%");
        return success;
    }
}

QString calculator::GetVisualCriticalCheck()
{
    QString crit = "Trafienie krytyczne przy: &#60;";
    crit.append(QString::number(criticalTreshold));
    crit.append("%");
    return crit;
}

QStringList calculator::GetVisualEffectCheck()
{
    QStringList chance;
    if(isActionSkillRelated(GetCurrentActionID()))
    {
        if(GetSkillStunChanceFromSkillID(selectedActionItemID) != 0)
        {
            QString chance_value = QString::number(GetSkillStunChanceFromSkillID(selectedActionItemID));
            QString chance_full = "<br>Ogłuszenie przy: &#60;" + chance_value + "%";
            chance.append(chance_full);
        }
        if(GetSkillKnockoutChanceFromSkillID(selectedActionItemID) != 0)
        {
            QString chance_value = QString::number(GetSkillKnockoutChanceFromSkillID(selectedActionItemID));
            QString chance_full = "<br>Powalenie przy: &#60;" + chance_value + "%";
            chance.append(chance_full);
        }
        if(GetSkillChillChanceFromSkillID(selectedActionItemID) != 0)
        {
            QString chance_value = QString::number(GetSkillChillChanceFromSkillID(selectedActionItemID));
            QString chance_full = "<br>Schłodzenie przy: &#60;" + chance_value + "%";
            chance.append(chance_full);
        }
        if(GetSkillFlameChanceFromSkillID(selectedActionItemID) != 0)
        {
            QString chance_value = QString::number(GetSkillFlameChanceFromSkillID(selectedActionItemID));
            QString chance_full = "<br>Podpalenie przy: &#60;" + chance_value + "%";
            chance.append(chance_full);
        }
        if(GetSkillUpliftChanceFromSkillID(selectedActionItemID) != 0)
        {
            QString chance_value = QString::number(GetSkillUpliftChanceFromSkillID(selectedActionItemID));
            QString chance_full = "<br>Podniesienie przy: &#60;" + chance_value + "%";
            chance.append(chance_full);
        }
    }

    return chance;
}

QString calculator::GetVisualCalculationSteps()
{
    QString text = "<font color=#8040BF>[fabuleoff]</font><br>";

    text += GetVisualCalculationSteps_Damage();
    text += GetVisualCalculationSteps_Difficulty();
    text += GetVisualCalculationSteps_Accuracy();
    text += GetVisualCalculationSteps_Cost();
    text += GetVisualCalculationSteps_Critical();

    text += "<font color=#8040BF>[/fabuleoff]</font><br>";

    return text;
}

QString calculator::GetVisualTargetArmorAndShieldLeftResult()
{
    QString text = "";
    QString shield_max = "", shield_current = "", armor_max = "", armor_current = "";

    if(isActionNeedTarget(GetCurrentActionID()) && GetNumberOfSuccess() > 0 && !isActionMeeleeRelated(GetCurrentActionID()))
    {
        text += "<br><br>";
        text += selectedTargetName + ":<br>";

        for(int i=0;i<Players.size();i++)
            if(Players.at(i).PlayerID == selectedTargetID)
            {
                shield_max = QString::number(Players.at(i).ShieldMax);
                armor_max = QString::number(Players.at(i).ArmorMax);

                shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedTargetID,GetFinalDamageDealt()));
                if(Players.at(i).ShieldCurrent == 0)
                    armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedTargetID,GetFinalDamageDealt()));
                else
                    armor_current = QString::number(Players.at(i).ArmorCurrent);
            }

        text += "Tarcze <font color=#0080FF>";
        text += shield_current + "/" + shield_max + "</font> ";
        text += "Pancerz <font color=#FFBF00>";
        text += armor_current + "/" + armor_max + "</font><br>";
    }

    else if(GetNumberOfSuccess() > 0 && isActionMeeleeRelated(GetCurrentActionID()))        //Meelee Damage
    {
        text += "<br><br>";
        text += selectedTargetName + ":<br>";

        for(int i=0;i<Players.size();i++)
            if(Players.at(i).PlayerID == selectedTargetID)
            {
                shield_max = QString::number(Players.at(i).ShieldMax);
                armor_max = QString::number(Players.at(i).ArmorMax);

                shield_current = QString::number(Players.at(i).ShieldCurrent);
                armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedTargetID,GetFinalDamageDealt()));
            }

        text += "Tarcze <font color=#0080FF>";
        text += shield_current + "/" + shield_max + "</font> ";
        text += "Pancerz <font color=#FFBF00>";
        text += armor_current + "/" + armor_max + "</font><br>";
    }

    else if(GetCurrentActionID() == 6)                                          // Shield Regeneration
    {
        text += selectedPlayerName + ":<br>";

        for(int i=0;i<Players.size();i++)
            if(Players.at(i).PlayerID == selectedPlayerID)
            {
                shield_max = QString::number(Players.at(i).ShieldMax);
                armor_max = QString::number(Players.at(i).ArmorMax);

                shield_current = QString::number(Players.at(i).ShieldMax);
                armor_current = QString::number(Players.at(i).ArmorCurrent);
            }

        text += "Tarcze <font color=#0080FF>";
        text += shield_current + "/" + shield_max + "</font> ";
        text += "Pancerz <font color=#FFBF00>";
        text += armor_current + "/" + armor_max + "</font><br>";
    }

    else if(GetCurrentActionID() == 9)                                          // Armor Regeneration
    {
        if(selectedActionItemID == 0)
            text += selectedPlayerName + ":<br>";
        else
            text += selectedTargetName + ":<br>";

        for(int i=0;i<Players.size();i++)
        {
            if(selectedActionItemID == 0 && Players.at(i).PlayerID == selectedPlayerID)
            {
                shield_max = QString::number(Players.at(i).ShieldMax);
                armor_max = QString::number(Players.at(i).ArmorMax);

                shield_current = QString::number(Players.at(i).ShieldCurrent);

                int armorRepaired = Players.at(i).ArmorMax*(0.2 + GetPlayerTechnoBuffFromOmnikey(selectedPlayerID)*0.01);
                int armorNew = GetPlayerArmorCurrentAfterDamage(selectedPlayerID,-armorRepaired);
                armor_current = QString::number(armorNew);
            }
            else if(selectedActionItemID == 1 && Players.at(i).PlayerID == selectedTargetID)
            {
                shield_max = QString::number(Players.at(i).ShieldMax);
                armor_max = QString::number(Players.at(i).ArmorMax);

                shield_current = QString::number(Players.at(i).ShieldCurrent);

                int armorRepaired = Players.at(i).ArmorMax*(0.2 + GetPlayerTechnoBuffFromOmnikey(selectedTargetID)*0.1);
                int armorNew = GetPlayerArmorCurrentAfterDamage(selectedTargetID,-armorRepaired);
                armor_current = QString::number(armorNew);
            }
        }

        text += "Tarcze <font color=#0080FF>";
        text += shield_current + "/" + shield_max + "</font> ";
        text += "Pancerz <font color=#FFBF00>";
        text += armor_current + "/" + armor_max + "</font><br>";
    }

    return text;
}

QString calculator::GetVisualSuccessResult()
{
    QString result;
    result = "<font color=#00FFFF>Efekt: </font>";
    if(isActionHasSuccessCheck(GetCurrentActionID()))
    {
        if(dice_results.size() == 1)
        {
            if(isActionNeedTarget(GetCurrentActionID()) && isCriticalHit())
                result += "Trafienie krytyczne!";
            else if(isActionNeedTarget(GetCurrentActionID()) && GetNumberOfSuccess() > 0)
                result += "Trafienie!";
            else if(isActionNeedTarget(GetCurrentActionID()) && GetNumberOfSuccess() == 0)
                result += "Pudło!";
            else if(!isActionNeedTarget(GetCurrentActionID()) && GetNumberOfSuccess() > 0)
                result += "Sukces!";
            else
                result += "Porażka!";
        }
        else if(dice_results.size() == 4)
        {
            if(GetNumberOfSuccess() > 0)
            {
                result += "Trafienie na ";
                result += QString::number(GetNumberOfSuccess());
                result += " kościach!";
            }
            if(isCriticalHit())
                result += " Trafienie krytyczne!";
        }
        else
            result = "";
    }
    else
        result = "";

    return result;
}

QString calculator::GetVisualDamageResult()
{
    QString result;
    if(GetNumberOfSuccess() > 0 && isActionDealDamage(GetCurrentActionID()))
    {
        result = "<font color=#00FFFF>Zadane obrażenia: </font>";
        result += QString::number(GetFinalDamageDealt());
        return result;
    }
    else
        return "";
}

QString calculator::GetVisualCalculationSteps_Damage()
{
    QString text = "";

    if(isActionDealDamage(GetCurrentActionID()) && GetNumberOfSuccess() > 0)
    {
        if(dice_results.size() > 1)
        {
            text += "Obrażenia:<br>";

            if(ItemAndDamage.size() > 0 || AdditionalItemAndDamage.size() > 0)
                text += QString::number(GetBaseDamageDealt()) + " [Obrażenia bazowe]<br>";

            for(int i=0;i<ItemAndDamage.size();i++)
            {
                if(ItemAndDamage.at(i).value > 0)
                    text += "+";
                text +=  QString::number(ItemAndDamage.at(i).value) + " [" + ItemAndDamage.at(i).name + "]";
                text += "<br>";
            }
            for(int i=0;i<AdditionalItemAndDamage.size();i++)
            {
                if(AdditionalItemAndDamage.at(i).value > 0)
                    text += "+";
                text += QString::number(AdditionalItemAndDamage.at(i).value) + " [" + AdditionalItemAndDamage.at(i).name + "]";
                text += "<br>";
            }

            text += QString::number(GetModifiedBaseDamageDealt()) + "*" + QString::number(GetNumberOfSuccess()) + "*0.25";

            if(isCriticalHit())
            {
                text += "*1.3";
                text += " = " + QString::number(GetFinalDamageDealt()) + "<br>";
            }
            else
                text += " = " + QString::number(GetFinalDamageDealt()) + "<br>";

            text += "<br>";
        }
        else if(dice_results.size() == 1 && isCriticalHit())
        {
            text += "Obrażenia:<br>";

            if(ItemAndDamage.size() > 0 || AdditionalItemAndDamage.size() > 0)
                text += QString::number(GetBaseDamageDealt()) + " [Obrażenia bazowe]<br>";
            for(int i=0;i<ItemAndDamage.size();i++)
            {
                if(ItemAndDamage.at(i).value > 0)
                    text += "+";
                text += QString::number(ItemAndDamage.at(i).value) + " [" + ItemAndDamage.at(i).name + "]";
                text += "<br>";
            }
            for(int i=0;i<AdditionalItemAndDamage.size();i++)
            {
                if(AdditionalItemAndDamage.at(i).value > 0)
                    text += "+";
                text += QString::number(AdditionalItemAndDamage.at(i).value) + " [" + AdditionalItemAndDamage.at(i).name + "]";
                text += "<br>";
            }

            text += QString::number(GetModifiedBaseDamageDealt()) + "*1.3 = " + QString::number(GetFinalDamageDealt()) + "<br>";
            text += "<br>";
        }
        else if(dice_results.size() == 1 && (ItemAndDamage.size() > 0 || AdditionalItemAndDamage.size() > 0))
        {
            text += "Obrażenia:<br>";

            if(ItemAndDamage.size() > 0 || AdditionalItemAndDamage.size() > 0)
                text += QString::number(GetBaseDamageDealt()) + " [Obrażenia bazowe]<br>";
            for(int i=0;i<ItemAndDamage.size();i++)
            {
                if(ItemAndDamage.at(i).value > 0)
                    text += "+";
                text += QString::number(ItemAndDamage.at(i).value) + " [" + ItemAndDamage.at(i).name + "]";
                text += "<br>";
            }
            for(int i=0;i<AdditionalItemAndDamage.size();i++)
            {
                if(AdditionalItemAndDamage.at(i).value > 0)
                    text += "+";
                text += QString::number(AdditionalItemAndDamage.at(i).value) + " [" + AdditionalItemAndDamage.at(i).name + "]";
                text += "<br>";
            }

            text += QString::number(GetFinalDamageDealt()) + "<br>";
            text += "<br>";
        }
    }

    return text;
}

QString calculator::GetVisualCalculationSteps_Accuracy()
{
    QString text = "";
    if(ItemAndAccuracy.size() > 0)
    {
        text += "Premia do trafienia:";

        for(int i=0;i<ItemAndAccuracy.size();i++)
        {
            text += "<br>";
            if(ItemAndAccuracy.at(i).value > 0)
                text += "+";
            text += QString::number(ItemAndAccuracy.at(i).value) + " [" + ItemAndAccuracy.at(i).name + "]";
        }
        text += "<br><br>";
    }
    return text;
}

QString calculator::GetVisualCalculationSteps_Difficulty()
{
    QString text = "";
    if(ItemAndDifficulty.size() > 0 || AdditionalItemAndDifficulty.size() > 0)
    {
        text += "Poziom trudności:";
        text += "<br>";
        text += difficulty_level_name;
        if(!difficulty_reason.isEmpty() && !difficulty_reason.isNull())
            text += " [" + difficulty_reason + "]";

        for(int i=0;i<ItemAndDifficulty.size();i++)
        {
            text += "<br>";
            if(ItemAndDifficulty.at(i).value > 0)
                text += "+";
            text += QString::number(ItemAndDifficulty.at(i).value) + " [" + ItemAndDifficulty.at(i).name + "]";
        }

        for(int i=0;i<AdditionalItemAndDifficulty.size();i++)
        {
            text += "<br>";
            if(AdditionalItemAndDifficulty.at(i).value > 0)
                text += "+";
            text += QString::number(AdditionalItemAndDifficulty.at(i).value) + " [" + AdditionalItemAndDifficulty.at(i).name + "]";
        }

        text += "<br><br>";
    }

    return text;
}

QString calculator::GetVisualCalculationSteps_Critical()
{
    QString text = "";

    if(ItemAndCritical.size() > 0)
    {
        text += "Premia do szansy na trafienie krytyczne:";

        for(int i=0;i<ItemAndCritical.size();i++)
        {
            text += "<br>";
            if(ItemAndCritical.at(i).value > 0)
                text += "+";
            text += QString::number(ItemAndCritical.at(i).value) + " [" + ItemAndCritical.at(i).name + "]";
        }
        text += "<br><br>";
    }

    return text;
}

QString calculator::GetVisualCalculationSteps_Cost()
{
    QString text = "";

    if(ItemAndActionCost.size() > 0)
    {
        text += "Zmiana kosztu akcji:";

        for(int i=0;i<ItemAndActionCost.size();i++)
        {
            text += "<br>";
            if(ItemAndActionCost.at(i).value > 0)
                text += "+";
            text += QString::number(ItemAndActionCost.at(i).value) + " [" + ItemAndActionCost.at(i).name + "]";
        }
        text += "<br><br>";
    }

    return text;
}

void calculator::setVisualTextToWidget(QString text)
{
    ui->textEdit_turn_1->setText(text);
}

void calculator::setVisualTextToSecondWidget(QString text)
{
    ui->textEdit_turn_2->setText(text);
}
