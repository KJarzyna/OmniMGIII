#include "calculator.h"
#include "ui_calculator.h"

QString calculator::GetEffectNameFromEffectID(int ID)
{
    QString name = "NoName";
    for(int i=0;i<ActiveEffect.size();i++)
    {
        if(ActiveEffect.at(i).ID == ID)
            name = ActiveEffect.at(i).Name;
    }
    return name;
}

int calculator::GetEffectIDFromEffectName(QString name)
{
    int id = 9999;
    for(int i=0;i<ActiveEffect.size();i++)
        if(ActiveEffect.at(i).Name == name)
            id = ActiveEffect.at(i).ID;

    return id;
}

void calculator::AddEffectToPlayer(int playerID, int effectID)
{
    C_PlayerActiveEffect item;
    item.PlayerID = playerID;
    item.EffectID = effectID;
    PlayerActiveEffects.append(item);
}

QVector<int> calculator::GetSkillEffectsFromSkillID(int skillID)
{
    QVector<int> list;
    for(int i=0;i<SkillActiveEffects.size();i++)
        if(SkillActiveEffects.at(i).SkillID == skillID)
            list.append(SkillActiveEffects.at(i).EffectID);
    return list;
}

void calculator::RemoveAllEffectsFromPlayer(int playerID)
{
    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID)
        {
            PlayerActiveEffects.remove(i);
            i--;
        }
}

void calculator::RemoveEffectFromPlayer(int playerID, int effectID)
{
    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID && PlayerActiveEffects.at(i).EffectID == effectID)
        {
            PlayerActiveEffects.remove(i);
            i--;
        }
}

void calculator::PerformAdditionalEffects()
{
     //Ranny 1
    if(isPlayerHasEffect(selectedPlayerID,0))
    {
        C_ItemModificator item;
        item.name = GetEffectNameFromEffectID(0);
        item.value = 1;
        AdditionalItemAndDifficulty.append(item);
    }
     //Ranny 2
    if(isPlayerHasEffect(selectedPlayerID,1))
    {
        C_ItemModificator item;
        item.name = GetEffectNameFromEffectID(0);
        item.value = 2;
        AdditionalItemAndDifficulty.append(item);
    }
     //Powalenie
    if(isPlayerHasEffect(selectedPlayerID,2) && GetActionCostAfterCalculations(GetCurrentActionID()) > 2) //Powalenie
    {
        C_ItemModificator item;
        item.name = GetEffectNameFromEffectID(2);
        item.value = 1;
        AdditionalItemAndDifficulty.append(item);
    }
    //Ogłuszony
//    if(isPlayerHasEffect(selectedPlayerID,3))
//    {
//        dialogbox_warning_generic *box = new dialogbox_warning_generic;
//        box->setAttribute(Qt::WA_DeleteOnClose);
//        box->setWarningLabel("Postać jest ogłuszona! Nie może wykonywać akcji!");
//        box->show();
//    }
    //Schłodzony - Gracz
    if(isPlayerHasEffect(selectedPlayerID,4))
    {
        C_ItemModificator item;
        item.name = GetEffectNameFromEffectID(4);
        item.value = 2;
        AdditionalItemAndActionCost.append(item);
    }
    //Schłodzony - Cel
    if(isPlayerHasEffect(selectedTargetID,4))
    {
        C_ItemModificator item;
        item.name = "Cel " + GetEffectNameFromEffectID(4);
        item.value = -1;
        AdditionalItemAndDifficulty.append(item);
    }
    //Podpalony
    if(isPlayerHasEffect(selectedPlayerID,5))
    {
        C_ItemModificator item;
        item.name = GetEffectNameFromEffectID(4);
        item.value = 1;
        AdditionalItemAndDifficulty.append(item);
    }
    //Podniesiony - Gracz
    if(isPlayerHasEffect(selectedPlayerID,6))
    {
        C_ItemModificator item;
        item.name = GetEffectNameFromEffectID(4);
        item.value = 2;
        AdditionalItemAndDifficulty.append(item);
    }
    //Podniesiony - Cel
    if(isPlayerHasEffect(selectedTargetID,6))
    {
        C_ItemModificator item;
        item.name = "Cel " + GetEffectNameFromEffectID(4);
        item.value = -2;
        AdditionalItemAndDifficulty.append(item);
    }
    //Bariera
    if((isPlayerHasEffect(selectedPlayerID,7) || isPlayerHasEffect(selectedPlayerID,8) || isPlayerHasEffect(selectedPlayerID,9) ||
        isPlayerHasEffect(selectedPlayerID,10) || isPlayerHasEffect(selectedPlayerID,11) || isPlayerHasEffect(selectedPlayerID,13) ||
        isPlayerHasEffect(selectedPlayerID,15) || isPlayerHasEffect(selectedPlayerID,18) || isPlayerHasEffect(selectedPlayerID,19) ||
        isPlayerHasEffect(selectedPlayerID,20) || isPlayerHasEffect(selectedPlayerID,22)) && isActionSkillRelated(GetCurrentActionID()))
    {
        C_ItemModificator item;
        item.name = "Bariera";
        item.value = 5;
        AdditionalItemAndActionCost.append(item);
    }
    //Bariera - 5A
    if((isPlayerHasEffect(selectedPlayerID,12) || isPlayerHasEffect(selectedPlayerID,14)
            || isPlayerHasEffect(selectedPlayerID,16) || isPlayerHasEffect(selectedPlayerID,17) || isPlayerHasEffect(selectedPlayerID,21)
            || isPlayerHasEffect(selectedPlayerID,23)) && isActionSkillRelated(GetCurrentActionID()))
    {
        C_ItemModificator item;
        item.name = "Bariera";
        item.value = 3;
        AdditionalItemAndActionCost.append(item);
    }
    //Zastój - Gracz
    for(int i=24;i<41;i++)
        if(isPlayerHasEffect(selectedPlayerID,i))
        {
            dialogbox_warning_generic *box = new dialogbox_warning_generic;
            box->setAttribute(Qt::WA_DeleteOnClose);
            box->setWarningLabel("Postać jest pod wpływem Zastoju! Nie może wykonywać akcji!");
            box->show();
        }

    //Zastój 4B - Cel
    for(int i=24;i<41;i++)
        if(isPlayerHasEffect(selectedPlayerID,28) || isPlayerHasEffect(selectedPlayerID,31) || isPlayerHasEffect(selectedPlayerID,32) ||
            isPlayerHasEffect(selectedPlayerID,36) || isPlayerHasEffect(selectedPlayerID,37 || isPlayerHasEffect(selectedPlayerID,38) ||
            isPlayerHasEffect(selectedPlayerID,40)))
        {
            C_ItemModificator item;
            item.name = "Zastój";
            item.value = 50;
            AdditionalItemAndDamage.append(item);
        }

    //Kula Biotyczna 4A - Cel
    if(isPlayerHasEffect(selectedTargetID,44) || isPlayerHasEffect(selectedTargetID,46) || isPlayerHasEffect(selectedTargetID,47) ||
            isPlayerHasEffect(selectedTargetID,50) || isPlayerHasEffect(selectedTargetID,51) || isPlayerHasEffect(selectedTargetID,52) ||
            isPlayerHasEffect(selectedTargetID,56))
    {
        C_ItemModificator item;
        item.name = "Cel pod działaniem Kuli Biotycznej";
        item.value = -1;
        AdditionalItemAndDifficulty.append(item);
    }

    //Kula Biotyczna 5A - Gracz
    if(GetCurrentActionID() == 6 && (isPlayerHasEffect(selectedPlayerID,46) || isPlayerHasEffect(selectedPlayerID,48) || isPlayerHasEffect(selectedPlayerID,50) ||
            isPlayerHasEffect(selectedPlayerID,51) || isPlayerHasEffect(selectedPlayerID,55) || isPlayerHasEffect(selectedPlayerID,57)))
    {
        C_ItemModificator item;
        item.name = "Gracz pod działaniem Kuli Biotycznej";
        item.value = -99;
        AdditionalItemAndActionCost.append(item);
    }

    //Skupienie Biotyczne - Cel
    for(int i=58;i<75;i++)
        if(isPlayerHasEffect(selectedTargetID,i))
        {
            C_ItemModificator item;
            item.name = "Cel pod działaniem Skupienia Biotycznego";
            item.value = 1;
            AdditionalItemAndDifficulty.append(item);

            item.name = "Cel pod działaniem Skupienia Biotycznego";
            item.value = -25;
            AdditionalItemAndDamage.append(item);
        }
    //Skupienie Biotyczne 4A - Cel
    if(isPlayerHasEffect(selectedTargetID,61) || isPlayerHasEffect(selectedTargetID,63) || isPlayerHasEffect(selectedTargetID,64) ||
            isPlayerHasEffect(selectedTargetID,67) || isPlayerHasEffect(selectedTargetID,68) || isPlayerHasEffect(selectedTargetID,69) ||
            isPlayerHasEffect(selectedTargetID,73))
    {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt Skupienia Biotycznego 4A";
        item.value = -25;
        AdditionalItemAndDamage.append(item);
    }

    //Skupienie Biotyczne - Gracz
    for(int i=58;i<75;i++)
        if(isActionMeeleeRelated(GetCurrentActionID()) && isPlayerHasEffect(selectedPlayerID,i))
        {
            C_ItemModificator item;
            item.name = GetEffectNameFromEffectID(i);
            item.value = 25;
            AdditionalItemAndDamage.append(item);
        }

    //Skupienie Biotyczne 4B - Gracz
    if(isActionMeeleeRelated(GetCurrentActionID()) && (isPlayerHasEffect(selectedPlayerID,62) || isPlayerHasEffect(selectedPlayerID,65) ||
            isPlayerHasEffect(selectedPlayerID,66) || isPlayerHasEffect(selectedPlayerID,70) || isPlayerHasEffect(selectedPlayerID,71) ||
            isPlayerHasEffect(selectedPlayerID,72) || isPlayerHasEffect(selectedPlayerID,74)))
    {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt Skupienia Biotycznego 4B";
        item.value = 25;
        AdditionalItemAndDamage.append(item);
    }

    //Skupienie Biotyczne 5A - Gracz
    if(isActionSkillRelated(GetCurrentActionID()) && GetSkillTypeFromSkillID(selectedActionItemID) == "Biotyczne" &&
            (isPlayerHasEffect(selectedPlayerID,63) || isPlayerHasEffect(selectedPlayerID,65) ||
            isPlayerHasEffect(selectedPlayerID,67) || isPlayerHasEffect(selectedPlayerID,68) || isPlayerHasEffect(selectedPlayerID,72) ||
            isPlayerHasEffect(selectedPlayerID,74)))
    {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt Skupienia Biotycznego 5A";
        item.value = -1;
        AdditionalItemAndActionCost.append(item);
    }
    //Skupienie Biotyczne 6B - Gracz
    if(isActionSkillRelated(GetCurrentActionID()) &&
            (isPlayerHasEffect(selectedPlayerID,68) || isPlayerHasEffect(selectedPlayerID,69) ||
            isPlayerHasEffect(selectedPlayerID,70) || isPlayerHasEffect(selectedPlayerID,74)))
    {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt Skupienia Biotycznego 6B";
        item.value = -1;
        AdditionalItemAndDifficulty.append(item);
    }

    //Skok Adrenaliny - Gracz
    for(int i=75;i<92;i++)
        if(isPlayerHasEffect(selectedPlayerID,i))
        {
            C_ItemModificator item;
            item.name = GetEffectNameFromEffectID(i);
            item.value = 5;
            AdditionalItemAndCritical.append(item);
        }
    //Skok Adrenaliny 2 - Gracz
    for(int i=76;i<92;i++)
        if(isActionDealDamage(GetCurrentActionID()) && isPlayerHasEffect(selectedPlayerID,i))
        {
            C_ItemModificator item;
            item.name = GetEffectNameFromEffectID(i);
            item.value = -1;
            AdditionalItemAndDifficulty.append(item);
        }

    //Skok Adrenaliny 6B - Gracz
    if(isPlayerHasEffect(selectedPlayerID,85) || isPlayerHasEffect(selectedPlayerID,86) ||
            isPlayerHasEffect(selectedPlayerID,91) || isPlayerHasEffect(selectedPlayerID,87))
        {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt od Skoku Adrenaliny 6B";
        item.value = 5;
        AdditionalItemAndCritical.append(item);
        }

    //Skok Adrenaliny 2 - Cel
    for(int i=76;i<92;i++)
        if(isPlayerHasEffect(selectedTargetID,i))
        {
            C_ItemModificator item;
            item.name = "Cel pod działaniem Skoku Adrenaliny";
            item.value = 1;
            AdditionalItemAndDifficulty.append(item);
        }

    //Pakiet Stymulantów - Gracz
    for(int i=92;i<109;i++)
        if(isActionDealDamage(GetCurrentActionID()) && isPlayerHasEffect(selectedPlayerID,i))
        {
            C_ItemModificator item;
            item.name = GetEffectNameFromEffectID(i);
            item.value = -1;
            AdditionalItemAndDifficulty.append(item);
        }
    //Pakiet Stymulantów - Cel
    for(int i=92;i<109;i++)
        if(isPlayerHasEffect(selectedTargetID,i))
        {
            C_ItemModificator item;
            item.name = "Cel pod działaniem efektu " + GetEffectNameFromEffectID(i);
            item.value = -30;
            AdditionalItemAndDamage.append(item);
        }
    //Pakiet Stymulantów 3- Cel
    for(int i=94;i<109;i++)
        if(isPlayerHasEffect(selectedTargetID,i))
        {
            C_ItemModificator item;
            item.name = "Dodatkowy efekt Pakietu Stymulantów 3";
            item.value = -20;
            AdditionalItemAndDamage.append(item);
        }

    //Szkolenie Bojowe 2 - Gracz
    for(int i=110;i<126;i++)
        if(isPlayerHasEffect(selectedPlayerID,i))
        {
            C_ItemModificator item;
            item.name = GetEffectNameFromEffectID(i);
            item.value = 5;
            AdditionalItemAndCritical.append(item);
        }
    //Szkolenie Bojowe 5A - Gracz
        if((isActionAmmoRelated(GetCurrentActionID()) || GetCurrentActionID() ==  5) && isPlayerHasEffect(selectedPlayerID,114) || isPlayerHasEffect(selectedPlayerID,116) || isPlayerHasEffect(selectedPlayerID,118) ||
                isPlayerHasEffect(selectedPlayerID,119) || isPlayerHasEffect(selectedPlayerID,123) || isPlayerHasEffect(selectedPlayerID,125))
        {
            C_ItemModificator item;
            item.name = "Dodatkowy efekt Szkolenia Bojowego 5A";
            item.value = -99;
            AdditionalItemAndActionCost.append(item);
        }
        //Szkolenie Bojowe 5B - Gracz
        if(isActionDealDamage(GetCurrentActionID()) && (isPlayerHasEffect(selectedPlayerID,143) || isPlayerHasEffect(selectedPlayerID,145)) &&
                (isPlayerHasEffect(selectedPlayerID,115) || isPlayerHasEffect(selectedPlayerID,117) || isPlayerHasEffect(selectedPlayerID,120) ||
                 isPlayerHasEffect(selectedPlayerID,121) || isPlayerHasEffect(selectedPlayerID,122) || isPlayerHasEffect(selectedPlayerID,124)))
        {
            C_ItemModificator item;
            item.name = "Dodatkowy efekt Szkolenia Bojowego 5B";
            item.value = -1;
            AdditionalItemAndDifficulty.append(item);
        }
        //Szkolenie Bojowe 6B - Gracz
        if(isActionDealDamage(GetCurrentActionID()) && isPlayerHasEffect(selectedPlayerID,143) &&
                (isPlayerHasEffect(selectedPlayerID,119) || isPlayerHasEffect(selectedPlayerID,120) || isPlayerHasEffect(selectedPlayerID,121) ||
                 isPlayerHasEffect(selectedPlayerID,125)))
        {
            C_ItemModificator item;
            item.name = "Dodatkowy efekt Szkolenia Bojowego 6B";
            item.value = 10;
            AdditionalItemAndCritical.append(item);
        }

        //Umocnienie - Gracz
        for(int i=126;i<143;i++)
            if(isActionDealDamage(GetCurrentActionID()) && isPlayerHasEffect(selectedPlayerID,i))
            {
                C_ItemModificator item;
                item.name = GetEffectNameFromEffectID(i);
                item.value = 2;
                AdditionalItemAndDifficulty.append(item);
            }
        //Umocnienie 4A - Gracz
        if(isActionDealDamage(GetCurrentActionID()) && (isPlayerHasEffect(selectedPlayerID,129) || isPlayerHasEffect(selectedPlayerID,131) ||
        isPlayerHasEffect(selectedPlayerID,132) || isPlayerHasEffect(selectedPlayerID,135) || isPlayerHasEffect(selectedPlayerID,136) ||
        isPlayerHasEffect(selectedPlayerID,137) || isPlayerHasEffect(selectedPlayerID,141)))
        {
            C_ItemModificator item;
            item.name = "Dodatkowy efekt Umocnienia 4A";
            item.value = -1;
            AdditionalItemAndDifficulty.append(item);
        }

        //Przymierzenie
        if(isActionWeaponRelated(GetCurrentActionID()) && (isPlayerHasEffect(selectedPlayerID,143)))
        {
            C_ItemModificator item;
            item.name = GetEffectNameFromEffectID(143);
            item.value = -1;
            AdditionalItemAndDifficulty.append(item);
        }
        //Koncentracja
        if(isActionSkillRelated(GetCurrentActionID()) && (isPlayerHasEffect(selectedPlayerID,144)))
        {
            C_ItemModificator item;
            item.name = GetEffectNameFromEffectID(144);
            item.value = -1;
            AdditionalItemAndDifficulty.append(item);
        }
        //Precyzja lekka
        if(isActionMeeleeRelated(GetCurrentActionID()) && (isPlayerHasEffect(selectedPlayerID,145)))
        {
            C_ItemModificator item;
            item.name = GetEffectNameFromEffectID(145);
            item.value = -1;
            AdditionalItemAndDifficulty.append(item);
        }
        //Precyzja skupiona
        if(isActionMeeleeRelated(GetCurrentActionID()) && (isPlayerHasEffect(selectedPlayerID,146)))
        {
            C_ItemModificator item;
            item.name = GetEffectNameFromEffectID(146);
            item.value = -2;
            AdditionalItemAndDifficulty.append(item);
        }
        //Pozycja obronna lekka
        if(isActionMeeleeRelated(GetCurrentActionID()) && (isPlayerHasEffect(selectedTargetID,147)))
        {
            C_ItemModificator item;
            item.name = GetEffectNameFromEffectID(147);
            item.value = 1;
            AdditionalItemAndDifficulty.append(item);
        }
        //Pozycja obronna skupiona
        if(isActionMeeleeRelated(GetCurrentActionID()) && (isPlayerHasEffect(selectedTargetID,148)))
        {
            C_ItemModificator item;
            item.name = GetEffectNameFromEffectID(148);
            item.value = 2;
            AdditionalItemAndDifficulty.append(item);
        }

        //Spalenie - Cel
        for(int i=297;i<314;i++)
            if(isActionSkillRelated(GetCurrentActionID()) && selectedActionItemID == i && isPlayerHasEffect(selectedTargetID,4))
            {
                C_ItemModificator item;
                item.name = "Dodatkowy efekt od Spalenia (cel Schłodzony)";
                item.value = +100;
                AdditionalItemAndDamage.append(item);
            }

        //Kriowybuch - Cel
        for(int i=341;i<358;i++)
            if(isActionSkillRelated(GetCurrentActionID()) && selectedActionItemID == i && isPlayerHasEffect(selectedTargetID,5))
            {
                C_ItemModificator item;
                item.name = "Dodatkowy efekt od Kriowybuchu (cel Podpalony)";
                item.value = +100;
                AdditionalItemAndDamage.append(item);
            }

        //Sabotaż - Gracz
        if(isPlayerHasEffect(selectedPlayerID,166))
            {
                C_ItemModificator item;
                item.name = "Zmniejszone obrażenia od Sabotażu 3";
                item.value = -0.5*GetModifiedBaseDamageDealt();
                AdditionalItemAndDamage.append(item);
            }

        //Natychmiastowe Zamrożenie - Cel
        for(int i=447;i<464;i++)
            if(isActionSkillRelated(GetCurrentActionID()) && selectedActionItemID == i && isPlayerHasEffect(selectedTargetID,5))
            {
                C_ItemModificator item;
                item.name = "Dodatkowy efekt od Natychmiastowego Zamrożenia (cel Podpalony)";
                item.value = +50;
                AdditionalItemAndDamage.append(item);
            }

}

void calculator::PerformAdditionalEffectsAfterHit()
{
    //Skok Adrenaliny 4A - Gracz
    if(isCriticalHit() && (isPlayerHasEffect(selectedPlayerID,78) || isPlayerHasEffect(selectedPlayerID,80) || isPlayerHasEffect(selectedPlayerID,81) ||
            isPlayerHasEffect(selectedPlayerID,84) || isPlayerHasEffect(selectedPlayerID,85) || isPlayerHasEffect(selectedPlayerID,86) ||
            isPlayerHasEffect(selectedPlayerID,90)))
        {
        C_ItemModificator item;
        item.name = "Dodatkowe 10% obrażeń krytycznych od Skoku Adrenaliny 4A";
        item.value = 0.1*GetModifiedBaseDamageDealt();
        AdditionalItemAndDamage.append(item);
        }

    //Skok Adrenaliny 6B cd - Gracz
    if(isCriticalHit() && (isPlayerHasEffect(selectedPlayerID,85) || isPlayerHasEffect(selectedPlayerID,86) ||
            isPlayerHasEffect(selectedPlayerID,91) || isPlayerHasEffect(selectedPlayerID,87)))
        {
        C_ItemModificator item;
        item.name = "Dodatkowe 10% obrażeń krytycznych od Skoku Adrenaliny 6B";
        item.value = 0.1*GetModifiedBaseDamageDealt();
        AdditionalItemAndDamage.append(item);
        }

    //Rzut 5A - Cel
    if(isActionSkillRelated(GetCurrentActionID()) && (selectedActionItemID == 5 || selectedActionItemID == 7 ||
        selectedActionItemID == 9 || selectedActionItemID == 10 || selectedActionItemID == 14 ||
        selectedActionItemID == 16) && isPlayerHasEffect(selectedTargetID,6))
        {
        C_ItemModificator item;
        item.name = "2 x więcej obrażeń od Rzutu 5A (Cel Podniesiony)";
        item.value = 2*GetModifiedBaseDamageDealt();
        AdditionalItemAndDamage.append(item);
        }


    //Odkształcenie 4A - Cel
    if(isActionSkillRelated(GetCurrentActionID()) && (selectedActionItemID == 113 || selectedActionItemID == 115 ||
        selectedActionItemID == 116 || selectedActionItemID == 119 || selectedActionItemID == 120 ||
        selectedActionItemID == 121 || selectedActionItemID == 125) && isPlayerHasEffect(selectedTargetID,6))
        {
        C_ItemModificator item;
        item.name = "Dodatkowe 100 obrażeń od Odkształcenia 4A (Cel Podniesiony)";
        item.value = 100;
        AdditionalItemAndDamage.append(item);
        }

    //Przeciążenie 5A - Cel
    if(isCriticalHit() && isPlayerHasShield(selectedTargetID) && isActionSkillRelated(GetCurrentActionID()) && (selectedActionItemID == 319 ||
    selectedActionItemID == 321 || selectedActionItemID == 323 || selectedActionItemID == 324 || selectedActionItemID == 328 ||
    selectedActionItemID == 330))
        {
        C_ItemModificator item;
        item.name = "Podwójne obrażenia krytyczne od Przeciążenia 5A";
        item.value = GetModifiedBaseDamageDealt();
        AdditionalItemAndDamage.append(item);
        }

}
