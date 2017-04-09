#include "calculator.h"
#include "ui_calculator.h"

//TEXT

void calculator::setVisualPlayerStats(int playerID)
{
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
        {
            ui->label_current_armor->setText(QString::number(Players.at(i).ArmorCurrent));
            ui->label_max_armor->setText(QString::number(Players.at(i).ArmorMax));
            ui->label_current_shield->setText(QString::number(Players.at(i).ShieldCurrent));
            ui->label_max_shield->setText(QString::number(Players.at(i).ShieldMax));
            ui->label_current_barrier->setText(QString::number(Players.at(i).BarrierCurrent));
        }
}

void calculator::setVisualPlayerActiveEffects(int playerID)
{
    ui->listWidget_player_conditions->clear();
    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID)
            ui->listWidget_player_conditions->addItem(GetEffectNameFromEffectID(PlayerActiveEffects.at(i).EffectID));
}

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
    }

    return full_text;
}

QString calculator::GetFinalVisualTextFromSelectedInfo()
{
    QString full_text;

    if(isActionHasSuccessCheck(GetCurrentActionID()))
    {

        full_text = GetVisualSuccessResult();
        for(int i=0;i<GetVisualEffectSuccess().size();i++)
            full_text += GetVisualEffectSuccess().at(i);
        full_text += "<br>";

        full_text += GetVisualDamageResult();

        full_text += GetVisualTargetArmorAndShieldLeftResult();
        full_text += GetVisualTargetEffects();

        full_text += "<br><br>";
        full_text += GetVisualCalculationSteps();
    }
    else if(GetCurrentActionID() == 6 || GetCurrentActionID() == 9) // Generator Regeneration or Omni Usage
    {
        full_text += GetVisualTargetArmorAndShieldLeftResult();
        full_text += GetVisualTargetEffects();
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
    QString crit = "";
    if(isActionNeedTarget(GetCurrentActionID()))
    {
        crit = "Trafienie krytyczne przy: &#60;";
        crit.append(QString::number(criticalTreshold));
        crit.append("%");
    }

    return crit;
}

QStringList calculator::GetVisualEffectCheck()
{
    QStringList chance;
    if(isActionSkillRelated(GetCurrentActionID()) && isActionNeedTarget(GetCurrentActionID()))
    {
        if(GetSkillEffectChanceFromSkillID(selectedActionItemID,3) != 0)
        {
            QString chance_value = QString::number(GetSkillEffectChanceFromSkillID(selectedActionItemID,3));
            if(isPlayerHasShield(selectedTargetID) && !isSkillWorksWithShields(selectedActionItemID))
                chance_value = "0";

            QString chance_full = "<br>Ogłuszenie przy: &#60;" + chance_value + "%";
            if(isPlayerHasShield(selectedTargetID) && !isSkillWorksWithShields(selectedActionItemID))
                chance_full += " (Cel okryty tarczami!)";
            chance.append(chance_full);
        }
        if(GetSkillEffectChanceFromSkillID(selectedActionItemID,2) != 0)
        {
            QString chance_value = QString::number(GetSkillEffectChanceFromSkillID(selectedActionItemID,2));
            if(isPlayerHasShield(selectedTargetID) && !isSkillWorksWithShields(selectedActionItemID))
                chance_value = "0";

            QString chance_full = "<br>Powalenie przy: &#60;" + chance_value + "%";
            if(isPlayerHasShield(selectedTargetID) && !isSkillWorksWithShields(selectedActionItemID))
                chance_full += " (Cel okryty tarczami!)";
            chance.append(chance_full);
        }
        if(GetSkillEffectChanceFromSkillID(selectedActionItemID,4) != 0)
        {
            QString chance_value = QString::number(GetSkillEffectChanceFromSkillID(selectedActionItemID,4));
            if(isPlayerHasShield(selectedTargetID) && !isSkillWorksWithShields(selectedActionItemID))
                chance_value = "0";

            QString chance_full = "<br>Schłodzenie przy: &#60;" + chance_value + "%";
            if(isPlayerHasShield(selectedTargetID) && !isSkillWorksWithShields(selectedActionItemID))
                chance_full += " (Cel okryty tarczami!)";
            chance.append(chance_full);
        }
        if(GetSkillEffectChanceFromSkillID(selectedActionItemID,5) != 0)
        {
            QString chance_value = QString::number(GetSkillEffectChanceFromSkillID(selectedActionItemID,5));
            if(isPlayerHasShield(selectedTargetID) && !isSkillWorksWithShields(selectedActionItemID))
                chance_value = "0";

            QString chance_full = "<br>Podpalenie przy: &#60;" + chance_value + "%";
            if(isPlayerHasShield(selectedTargetID) && !isSkillWorksWithShields(selectedActionItemID))
                chance_full += " (Cel okryty tarczami!)";
            chance.append(chance_full);
        }
        if(GetSkillEffectChanceFromSkillID(selectedActionItemID,6) != 0)
        {
            QString chance_value = QString::number(GetSkillEffectChanceFromSkillID(selectedActionItemID,6));
            if(isPlayerHasShield(selectedTargetID) && !isSkillWorksWithShields(selectedActionItemID))
                chance_value = "0";

            QString chance_full = "<br>Podniesienie przy: &#60;" + chance_value + "%";
            if(isPlayerHasShield(selectedTargetID) && !isSkillWorksWithShields(selectedActionItemID))
                chance_full += " (Cel okryty tarczami!)";
            chance.append(chance_full);
        }
    }

    return chance;
}

QStringList calculator::GetVisualEffectSuccess()
{
    QStringList list;
    int actionID = GetCurrentActionID();
    if(GetNumberOfSuccess() > 0 && isActionSkillRelated(actionID) && isActionNeedTarget(actionID) && isSkillEffectApplicableToPlayer(selectedTargetID,selectedActionItemID))
    {
        if(GetSkillEffectChanceFromSkillID(selectedActionItemID,2) > dice_results.at(0))
            list.append(" Powalenie!");
        if(GetSkillEffectChanceFromSkillID(selectedActionItemID,3) > dice_results.at(0))
            list.append(" Ogłuszenie!");
        if(GetSkillEffectChanceFromSkillID(selectedActionItemID,4) > dice_results.at(0))
            list.append(" Schłodzenie!");
        if(GetSkillEffectChanceFromSkillID(selectedActionItemID,5) > dice_results.at(0))
            list.append(" Podpalenie!");
        if(GetSkillEffectChanceFromSkillID(selectedActionItemID,6) > dice_results.at(0))
            list.append(" Podniesienie!");
    }

    if(list.isEmpty())
        list.append("");
    return list;
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
    QString shield_max = "0", shield_current = "0", armor_max = "0", armor_current = "0", barrier = "0";

    if(isActionNeedTarget(GetCurrentActionID()) && GetNumberOfSuccess() > 0 && !isActionMeeleeRelated(GetCurrentActionID()))
    {
        text += "<br><br>";
        text += selectedTargetName + ":<br>";

        shield_max = QString::number(GetPlayerMaxShield(selectedTargetID));
        armor_max = QString::number(GetPlayerMaxArmor(selectedTargetID));

        if(isPlayerHasBarrier(selectedTargetID))
        {
            barrier = QString::number(GetPlayerBarrierAfterDamage(selectedTargetID,GetFinalDamageDealt()));
            shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedTargetID,0));
            armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedTargetID,0));
        }
        else if(!isPlayerHasBarrier(selectedTargetID) && isPlayerHasShield(selectedTargetID))
        {
            shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedTargetID,GetFinalDamageDealt()));
            armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedTargetID,0));
        }
        else if(!isPlayerHasShield(selectedTargetID) && !isPlayerHasBarrier(selectedTargetID))
            armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedTargetID,GetFinalDamageDealt()));
        else
            armor_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedTargetID,0));

        if(isPlayerHasBarrier(selectedTargetID))
        {
            text += "Bariera <font color=#BF80FF>";
            text += barrier + "</font> ";
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


        shield_max = QString::number(GetPlayerMaxShield(selectedTargetID));
        armor_max = QString::number(GetPlayerMaxArmor(selectedTargetID));
        barrier = QString::number(GetPlayerBarrierAfterDamage(selectedTargetID,0));

        shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedTargetID,0));
        armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedTargetID,GetFinalDamageDealt()));

        if(isPlayerHasBarrier(selectedTargetID))
        {
            text += "Bariera <font color=#BF80FF>";
            text += barrier + "</font> ";
        }
        text += "Tarcze <font color=#0080FF>";
        text += shield_current + "/" + shield_max + "</font> ";
        text += "Pancerz <font color=#FFBF00>";
        text += armor_current + "/" + armor_max + "</font><br>";
    }

    else if(isActionSkillRelated(GetCurrentActionID()) && selectedActionItemID > 50 && selectedActionItemID < 68)    // Barrier Regeneration
    {
        text += selectedPlayerName + ":<br>";
        shield_max = QString::number(GetPlayerMaxShield(selectedPlayerID));
        armor_max = QString::number(GetPlayerMaxArmor(selectedPlayerID));

        barrier = QString::number(GetSkillBarrierFromSkillID(selectedActionItemID));
        shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedPlayerID,0));
        armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedPlayerID,0));

        text += "Bariera <font color=#BF80FF>";
        text += barrier + "</font> ";
        text += "Tarcze <font color=#0080FF>";
        text += shield_current + "/" + shield_max + "</font> ";
        text += "Pancerz <font color=#FFBF00>";
        text += armor_current + "/" + armor_max + "</font><br>";
    }

    else if(GetCurrentActionID() == 6)                                          // Shield Regeneration
    {
        text += selectedPlayerName + ":<br>";
        shield_max = QString::number(GetPlayerMaxShield(selectedPlayerID));
        armor_max = QString::number(GetPlayerMaxArmor(selectedPlayerID));

        barrier = QString::number(GetPlayerBarrierAfterDamage(selectedPlayerID,0));
        shield_current = QString::number(GetPlayerMaxShield(selectedPlayerID));
        armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedPlayerID,0));

        if(isPlayerHasBarrier(selectedPlayerID))
        {
            text += "Bariera <font color=#BF80FF>";
            text += barrier + "</font> ";
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

        if(selectedActionItemID == 0)
        {
            shield_max = QString::number(GetPlayerMaxShield(selectedPlayerID));
            armor_max = QString::number(GetPlayerMaxArmor(selectedPlayerID));

            shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedPlayerID,0));

            int armorRepaired = GetPlayerMaxArmor(selectedPlayerID)*(0.2 + GetPlayerTechnoBuffFromOmnikey(selectedPlayerID)*0.01);
            int armorNew = GetPlayerArmorCurrentAfterDamage(selectedPlayerID,-armorRepaired);
            armor_current = QString::number(armorNew);
        }
        else if(selectedActionItemID == 1)
        {
            shield_max = QString::number(GetPlayerMaxShield(selectedTargetID));
            armor_max = QString::number(GetPlayerMaxArmor(selectedTargetID));

            shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedTargetID,0));

            int armorRepaired = GetPlayerMaxArmor(selectedTargetID)*(0.2 + GetPlayerTechnoBuffFromOmnikey(selectedTargetID)*0.1);
            int armorNew = GetPlayerArmorCurrentAfterDamage(selectedTargetID,-armorRepaired);
            armor_current = QString::number(armorNew);
        }


        if(selectedActionItemID == 0 && isPlayerHasBarrier(selectedPlayerID))
        {
            text += "Bariera <font color=#BF80FF>";
            text += GetPlayerBarrierAfterDamage(selectedPlayerID,0) + "</font> ";
        }
        else if(selectedActionItemID == 1 && isPlayerHasBarrier(selectedTargetID))
        {
            text += "Bariera <font color=#BF80FF>";
            text += GetPlayerBarrierAfterDamage(selectedTargetID,0) + "</font> ";
        }
        text += "Tarcze <font color=#0080FF>";
        text += shield_current + "/" + shield_max + "</font> ";
        text += "Pancerz <font color=#FFBF00>";
        text += armor_current + "/" + armor_max + "</font><br>";
    }


    if(isActionSkillRelated(GetCurrentActionID()) && selectedActionItemID > 88 && selectedActionItemID < 110)    // Phase Disruptor
    {
        text += "<br>" + selectedPlayerName + ":<br>";
        shield_max = QString::number(GetPlayerMaxShield(selectedPlayerID));
        armor_max = QString::number(GetPlayerMaxArmor(selectedPlayerID));

        barrier = QString::number(GetPlayerBarrierAfterDamage(selectedPlayerID,0));
        shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedPlayerID,GetSkillSelfShieldDrainFromSKillID(selectedActionItemID)));
        armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedPlayerID,0));

        if(isPlayerHasBarrier(selectedPlayerID))
        {
            text += "Bariera <font color=#BF80FF>";
            text += barrier + "</font> ";
        }
        text += "Tarcze <font color=#0080FF>";
        text += shield_current + "/" + shield_max + "</font> ";
        text += "Pancerz <font color=#FFBF00>";
        text += armor_current + "/" + armor_max + "</font><br>";
    }

    if(isActionSkillRelated(GetCurrentActionID()) && selectedActionItemID > 463 && selectedActionItemID < 481)    // Wyssanie Energii
    {
        text += "<br>" + selectedPlayerName + ":<br>";
        shield_max = QString::number(GetPlayerMaxShield(selectedPlayerID));
        armor_max = QString::number(GetPlayerMaxArmor(selectedPlayerID));

        barrier = QString::number(GetPlayerBarrierAfterDamage(selectedPlayerID,0));

        int i =selectedActionItemID;
        if(GetPlayerShieldCurrentAfterDamage(selectedTargetID,0) != 0)
        {
            int shieldDrained = GetPlayerShieldCurrentAfterDamage(selectedTargetID,GetSkillDamageToShieldFromSkillID(selectedActionItemID));
            if(shieldDrained == 0)
                shieldDrained = -GetPlayerShieldCurrentAfterDamage(selectedTargetID,0);
            else
                shieldDrained = GetSkillSelfShieldDrainFromSKillID(selectedActionItemID);

            if(i != 467 && i != 469 && i != 470 && i != 473 && i != 474 && i != 475 && i != 479) //Not allowed to boost shield over MaxShield
            {
                if(GetPlayerShieldCurrentAfterDamage(selectedPlayerID,0) != GetPlayerMaxShield(selectedPlayerID))
                {
                    if(GetPlayerShieldCurrentAfterDamage(selectedPlayerID,shieldDrained) > GetPlayerMaxShield(selectedPlayerID))
                        shield_current = QString::number(GetPlayerMaxShield(selectedPlayerID));
                    else
                        shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedPlayerID,shieldDrained));
                }
            }
            else
                shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedPlayerID,shieldDrained));
        }
        else
            shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedPlayerID,0));

        //shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedPlayerID,GetSkillSelfShieldDrainFromSKillID(selectedActionItemID)));
        armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedPlayerID,0));

        if(isPlayerHasBarrier(selectedPlayerID))
        {
            text += "Bariera <font color=#BF80FF>";
            text += barrier + "</font> ";
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

    SumAllDamageModificators();

    if(isActionDealDamage(GetCurrentActionID()) && GetNumberOfSuccess() > 0)
    {
        if(dice_results.size() > 1)
        {
            text += "Obrażenia:<br>";

            if(SumItemAndDamage.size() > 0)
                text += QString::number(GetBaseDamageDealt()) + " [Obrażenia bazowe]<br>";

            for(int i=0;i<SumItemAndDamage.size();i++)
            {
                if(SumItemAndDamage.at(i).value > 0)
                    text += "+";
                text +=  QString::number(SumItemAndDamage.at(i).value) + " [" + SumItemAndDamage.at(i).name + "]";
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

            if(SumItemAndDamage.size() > 0)
                text += QString::number(GetBaseDamageDealt()) + " [Obrażenia bazowe]<br>";
            for(int i=0;i<SumItemAndDamage.size();i++)
            {
                if(SumItemAndDamage.at(i).value > 0)
                    text += "+";
                text += QString::number(SumItemAndDamage.at(i).value) + " [" + SumItemAndDamage.at(i).name + "]";
                text += "<br>";
            }

            text += QString::number(GetModifiedBaseDamageDealt()) + "*1.3 = " + QString::number(GetFinalDamageDealt()) + "<br>";
            text += "<br>";
        }
        else if(dice_results.size() == 1 && SumItemAndDamage.size() > 0)
        {
            text += "Obrażenia:<br>";

            if(SumItemAndDamage.size() > 0)
                text += QString::number(GetBaseDamageDealt()) + " [Obrażenia bazowe]<br>";
            for(int i=0;i<SumItemAndDamage.size();i++)
            {
                if(SumItemAndDamage.at(i).value > 0)
                    text += "+";
                text += QString::number(SumItemAndDamage.at(i).value) + " [" + SumItemAndDamage.at(i).name + "]";
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
    SumAllDifficultyModificators();

    if(SumItemAndDifficulty.size() > 0)
    {
        text += "Poziom trudności:";
        text += "<br>";
        text += difficulty_level_name;
        if(!difficulty_reason.isEmpty() && !difficulty_reason.isNull())
            text += " [" + difficulty_reason + "]";

        for(int i=0;i<SumItemAndDifficulty.size();i++)
        {
            text += "<br>";
            if(SumItemAndDifficulty.at(i).value > 0)
                text += "+";
            text += QString::number(SumItemAndDifficulty.at(i).value) + " [" + SumItemAndDifficulty.at(i).name + "]";
        }

        text += "<br><br>";
    }

    return text;
}

QString calculator::GetVisualCalculationSteps_Critical()
{
    QString text = "";

    if(ItemAndCritical.size() > 0 || AdditionalItemAndCritical.size() > 0)
    {
        text += "Premia do szansy na trafienie krytyczne:";

        for(int i=0;i<ItemAndCritical.size();i++)
        {
            text += "<br>";
            if(ItemAndCritical.at(i).value > 0)
                text += "+";
            text += QString::number(ItemAndCritical.at(i).value) + " [" + ItemAndCritical.at(i).name + "]";
        }
        for(int i=0;i<AdditionalItemAndCritical.size();i++)
        {
            text += "<br>";
            if(AdditionalItemAndCritical.at(i).value > 0)
                text += "+";
            text += QString::number(AdditionalItemAndCritical.at(i).value) + " [" + AdditionalItemAndCritical.at(i).name + "]";
        }
        text += "<br><br>";
    }

    return text;
}

QString calculator::GetVisualCalculationSteps_Cost()
{
    QString text = "";

    SumAllActionCostModificators();

    if(SumItemAndActionCost.size() > 0)
    {
        text += "Zmiana kosztu akcji:";

        for(int i=0;i<SumItemAndActionCost.size();i++)
        {
            text += "<br>";
            if(SumItemAndActionCost.at(i).value > 0)
                text += "+";
            text += QString::number(SumItemAndActionCost.at(i).value) + " [" + SumItemAndActionCost.at(i).name + "]";
        }
        text += "<br><br>";
    }

    return text;
}

QString calculator::GetVisualTargetEffects()
{
    QString text = "";
    int actionID = GetCurrentActionID();
    for(int i=0;i<GetPlayerActiveEffects(selectedTargetID).size();i++)
        text += GetPlayerActiveEffects(selectedTargetID).at(i) + ", ";

    //Add new effect to target
    if(isActionSkillRelated(actionID) && GetSkillTargetFromSkillID(selectedActionItemID) == "target" && GetNumberOfSuccess() > 0 && isSkillEffectApplicableToPlayer(selectedTargetID,selectedActionItemID))
    {
        for(int i=0;i<GetSkillEffectsFromSkillID(selectedActionItemID).size();i++)
            text += GetEffectNameFromEffectID(GetSkillEffectsFromSkillID(selectedActionItemID).at(i)) + ", ";
    }

    //Add new "Ranny" effect to target
    if(isActionDealDamage(actionID) && GetNumberOfSuccess() > 0 && (!isPlayerHasShield(selectedTargetID) || isActionMeeleeRelated(actionID)))
        if(GetPlayerArmorCurrentAfterDamage(selectedTargetID,GetFinalDamageDealt()) < GetPlayerMaxArmor(selectedTargetID)*0.5)
        {
            if(GetPlayerActiveEffectsIDs(selectedTargetID).contains(0))
                text.replace(GetEffectNameFromEffectID(0),GetEffectNameFromEffectID(1));
            else if(!GetPlayerActiveEffectsIDs(selectedTargetID).contains(1))
                text += GetEffectNameFromEffectID(0) + ", ";
        }

    if(!text.isEmpty())
        text.chop(2);

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

QString calculator::ConvertVisualTextToCitadelFormat(QString text)
{
    text.replace("<font color","[color");
    text.replace("</font>", "[/color]");
    text.replace("<br>","\n");
    text.replace(">","]");
    text.replace("&#60;","<");
    text.replace("&lt;","<");
    return text;

}
