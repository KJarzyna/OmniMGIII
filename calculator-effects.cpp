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

        //Skan Taktyczny - Cel
        for(int i=167;i<184;i++)
        {
            if(isPlayerHasEffect(selectedTargetID,i))
            {
                C_ItemModificator item;
                item.name = "Efekt od Skanu Taktycznego (1)";
                item.value = 5;
                AdditionalItemAndCritical.append(item);
            }
        }

        if(isPlayerHasEffect(selectedTargetID,171) || isPlayerHasEffect(selectedTargetID,174) || isPlayerHasEffect(selectedTargetID,175) || // Skanowanie 4B
                isPlayerHasEffect(selectedTargetID,179) || isPlayerHasEffect(selectedTargetID,180) || isPlayerHasEffect(selectedTargetID,181) ||
                isPlayerHasEffect(selectedTargetID,183))
        {
            C_ItemModificator item;
            item.name = "Dodatkowy efekt od Skanu Taktycznego (4B)";
            item.value = 5;
            AdditionalItemAndCritical.append(item);
        }

        if(isPlayerHasEffect(selectedTargetID,172) || isPlayerHasEffect(selectedTargetID,174) || isPlayerHasEffect(selectedTargetID,176) || // Skanowanie 5A
                isPlayerHasEffect(selectedTargetID,177) || isPlayerHasEffect(selectedTargetID,181) || isPlayerHasEffect(selectedTargetID,183))
        {
            C_ItemModificator item;
            item.name = "Dodatkowy efekt od Skanu Taktycznego (5A)";
            item.value = -1;
            AdditionalItemAndDifficulty.append(item);
        }

        if(isPlayerHasEffect(selectedTargetID,176) || isPlayerHasEffect(selectedTargetID,180) || isPlayerHasEffect(selectedTargetID,181) || // Skanowanie 6A
                isPlayerHasEffect(selectedTargetID,182))
        {
            C_ItemModificator item;
            item.name = "Dodatkowy efekt od Skanu Taktycznego (6A)";
            item.value = -99;
            AdditionalItemAndActionCost.append(item);
        }

        //Pancerz Technologiczny - Gracz
        for(int i=184;i<201;i++)
        {
            if(isPlayerHasEffect(selectedPlayerID,i))
            {
                C_ItemModificator item;
                item.name = "Efekt od Pancerza Technologicznego (1)";
                item.value = 3;
                AdditionalItemAndActionCost.append(item);
            }
        }

        if(isPlayerHasEffect(selectedPlayerID,190) || isPlayerHasEffect(selectedPlayerID,192 || isPlayerHasEffect(selectedPlayerID,195) || isPlayerHasEffect(selectedPlayerID,196) ||
           isPlayerHasEffect(selectedPlayerID,197) || isPlayerHasEffect(selectedPlayerID,199)))
        {
            C_ItemModificator item;
            item.name = "Efekt od Pancerza Technologicznego (5B)";
            item.value = -2;
            AdditionalItemAndActionCost.append(item);
        }

        if(isPlayerHasEffect(selectedPlayerID,194) || isPlayerHasEffect(selectedPlayerID,195 || isPlayerHasEffect(selectedPlayerID,196) || isPlayerHasEffect(selectedPlayerID,200)))
        {
            C_ItemModificator item;
            item.name = "Efekt od Pancerza Technologicznego (6B)";
            item.value = -2;
            AdditionalItemAndActionCost.append(item);
        }

        //Amunicja Dysrupcyjna
        for(int i=218;i<235;i++)
            if(isPlayerHasEffect(selectedPlayerID,i))
            {
                //5B
                if(i==224 || i==226 || i==229 || i==230 || i==231 || i==233)
                {
                    C_ItemModificator item;
                    item.name = "Dodatkowy efekt od Amunicji Dysrupcyjnej (5B)";
                    item.value = 5;
                    AdditionalItemAndCritical.append(item);
                }
            }

        //Amunicja Zapalająca
        for(int i=235;i<252;i++)
            if(isPlayerHasEffect(selectedPlayerID,i))
            {
                //5B
                if(i==241 || i==243 || i==246 || i==247 || i==248 || i==250)
                {
                    C_ItemModificator item;
                    item.name = "Dodatkowy efekt od Amunicji Zapalającej (5B)";
                    item.value = 5;
                    AdditionalItemAndCritical.append(item);
                }
            }

        //Amunicja Krio
        for(int i=252;i<269;i++)
            if(isPlayerHasEffect(selectedPlayerID,i))
            {
                //5B
                if(i==258 || i==260 || i==263 || i==264 || i==265 || i==267)
                {
                    C_ItemModificator item;
                    item.name = "Dodatkowy efekt od Krio-Amunicji (5B)";
                    item.value = 5;
                    AdditionalItemAndCritical.append(item);
                }
            }

        //Amunicja PrzeciwPancerna
        for(int i=269;i<286;i++)
            if(isPlayerHasEffect(selectedPlayerID,i))
            {
                //5B
                if(i==275 || i==277 || i==280 || i==281 || i==282 || i==284)
                {
                    C_ItemModificator item;
                    item.name = "Dodatkowy efekt od Przeciwpancernej (5B)";
                    item.value = 5;
                    AdditionalItemAndCritical.append(item);
                }
            }

        //Amunicja Odkształcająca
        for(int i=286;i<303;i++)
            if(isPlayerHasEffect(selectedPlayerID,i))
            {
                //5B
                if(i==292 || i==294 || i==297 || i==298 || i==299 || i==301)
                {
                    C_ItemModificator item;
                    item.name = "Dodatkowy efekt od Odkształcającej (5B)";
                    item.value = 5;
                    AdditionalItemAndCritical.append(item);
                }
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

    //Skan Taktyczny 4A - Cel
    if(isPlayerHasEffect(selectedTargetID,170) || isPlayerHasEffect(selectedTargetID,172) || isPlayerHasEffect(selectedTargetID,173) || // Skanowanie 4A
            isPlayerHasEffect(selectedTargetID,176) || isPlayerHasEffect(selectedTargetID,177) || isPlayerHasEffect(selectedTargetID,178) ||
            isPlayerHasEffect(selectedTargetID,182))
    {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt od Skanu Taktycznego (4A)";
        item.value = 25;
        AdditionalItemAndDamage.append(item);
    }

    //Szarża Biotyczna 6B - Cel
    if(isActionSkillRelated(GetCurrentActionID()) && selectedActionItemID == 525 || selectedActionItemID == 526 || selectedActionItemID == 527 || selectedActionItemID == 531)
    {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt od Szarży Biotycznej (6B))";
        item.value = 100;
        AdditionalItemAndDamage.append(item);
    }

    //Pancerz Technologiczny - Gracz
    for(int i=184;i<201;i++)
    {
        if(isActionMeeleeRelated(GetCurrentActionID()) && isPlayerHasEffect(selectedPlayerID,i))
        {
            C_ItemModificator item;
            item.name = "Efekt od Pancerza Technologicznego (1)";
            item.value = 25;
            AdditionalItemAndDamage.append(item);
        }
    }

    //Pancerz Technologiczny 4A - Gracz
    if(isActionMeeleeRelated(GetCurrentActionID()) && (isPlayerHasEffect(selectedPlayerID,187) || isPlayerHasEffect(selectedPlayerID,189) || isPlayerHasEffect(selectedPlayerID,190) ||
       isPlayerHasEffect(selectedPlayerID,193) || isPlayerHasEffect(selectedPlayerID,194) || isPlayerHasEffect(selectedPlayerID,195) || isPlayerHasEffect(selectedPlayerID,199)))
    {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt od Pancerza Technologicznego (4A)";
        item.value = 25;
        AdditionalItemAndDamage.append(item);
    }

    //Pancerz Technologiczny 5A - Gracz
    if(isActionSkillRelated(GetCurrentActionID()) && isActionDealDamage(GetCurrentActionID()) && (isPlayerHasEffect(selectedPlayerID,189) || isPlayerHasEffect(selectedPlayerID,191) ||
       isPlayerHasEffect(selectedPlayerID,193) || isPlayerHasEffect(selectedPlayerID,194) || isPlayerHasEffect(selectedPlayerID,198) || isPlayerHasEffect(selectedPlayerID,200)))
    {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt od Pancerza Technologicznego (5A)";
        item.value = 50;
        AdditionalItemAndDamage.append(item);
    }

    //Pancerz Technologiczny - Cel
    for(int i=184;i<201;i++)
    {
        if(isPlayerHasEffect(selectedTargetID,i))
        {
            C_ItemModificator item;
            item.name = "Efekt od Pancerza Technologicznego (1)";
            item.value = -50;
            AdditionalItemAndDamage.append(item);
        }
    }

    //Pancerz Technologiczny 6A - Cel
    if(isPlayerHasEffect(selectedTargetID,193) || isPlayerHasEffect(selectedTargetID,197 || isPlayerHasEffect(selectedTargetID,198) || isPlayerHasEffect(selectedTargetID,199)))
    {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt od Pancerza Technologicznego (6A)";
        item.value = -50;
        AdditionalItemAndDamage.append(item);
    }

    //Kamuflaż Taktyczny - Gracz
    for(int i=201;i<218;i++)
    {
        if((isActionMeeleeRelated(GetCurrentActionID()) || isActionWeaponRelated(GetCurrentActionID())) && isPlayerHasEffect(selectedPlayerID,i))
        {
            C_ItemModificator item;
            item.name = "Efekt od Kamuflaża Taktycznego (1)";
            item.value = 50;
            AdditionalItemAndDamage.append(item);
        }
    }

    //Kamuflaż Taktyczny 4A - Gracz
    if(isActionMeeleeRelated(GetCurrentActionID()) && (isPlayerHasEffect(selectedPlayerID,204) || isPlayerHasEffect(selectedPlayerID,206) || isPlayerHasEffect(selectedPlayerID,207) ||
       isPlayerHasEffect(selectedPlayerID,210) || isPlayerHasEffect(selectedPlayerID,211) || isPlayerHasEffect(selectedPlayerID,212) || isPlayerHasEffect(selectedPlayerID,216)))
    {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt od Kamuflaża Taktycznego (4A)";
        item.value = 50;
        AdditionalItemAndDamage.append(item);
    }

    //Kamuflaż Taktyczny 4B - Gracz
    if(isActionWeaponRelated(GetCurrentActionID()) && (isPlayerHasEffect(selectedPlayerID,205) || isPlayerHasEffect(selectedPlayerID,208) || isPlayerHasEffect(selectedPlayerID,209) ||
       isPlayerHasEffect(selectedPlayerID,213) || isPlayerHasEffect(selectedPlayerID,214) || isPlayerHasEffect(selectedPlayerID,215) || isPlayerHasEffect(selectedPlayerID,217)))
    {
        C_ItemModificator item;
        item.name = "Dodatkowy efekt od Kamuflaża Taktycznego (4B)";
        item.value = 50;
        AdditionalItemAndDamage.append(item);
    }

    //AMUNICJE

    //Amunicja Dysrupcyjna
    for(int i=218;i<235;i++)
        if(isPlayerHasEffect(selectedPlayerID,i))
        {
            //2
            if(i>218 && i<235 && isPlayerHasShield(selectedTargetID))
            {
                C_ItemModificator item;
                item.name = "Dodatkowy efekt od Amunicji Dysrupcyjnej (2)";
                item.value = 30;
                AdditionalItemAndDamage.append(item);
            }
            //3
            if(i>219 && i<235 && isPlayerHasShield(selectedTargetID))
            {
                C_ItemModificator item;
                item.name = "Dodatkowy efekt od Amunicji Dysrupcyjnej (3)";
                item.value = 20;
                AdditionalItemAndDamage.append(item);
            }
            //4A
            if((i==221 || i==223 || i==224 || i==227 || i==228 || i==229 || i==233) && isPlayerHasShield(selectedTargetID))
            {
                C_ItemModificator item;
                item.name = "Dodatkowy efekt od Amunicji Dysrupcyjnej (4A)";
                item.value = 30;
                AdditionalItemAndDamage.append(item);
            }
        }

    //Amunicja Przeciwpancerna
    for(int i=269;i<286;i++)
        if(isPlayerHasEffect(selectedPlayerID,i))
        {
            //2
            if(i>269 && i<286 && !isPlayerHasShield(selectedTargetID))
            {
                C_ItemModificator item;
                item.name = "Dodatkowy efekt od Amunicji Przeciwpancernej (2)";
                item.value = 25;
                AdditionalItemAndDamage.append(item);
            }
            //4B
            if((i==273 || i==276 || i==277 || i==281 || i==282 || i==283 || i==285) && !isPlayerHasShield(selectedTargetID))
            {
                C_ItemModificator item;
                item.name = "Dodatkowy efekt od Amunicji Przeciwpancernej (4B)";
                item.value = 25;
                AdditionalItemAndDamage.append(item);
            }

        }

    //Amunicja Odkształcająca
    for(int i=286;i<303;i++)
        if(isPlayerHasEffect(selectedPlayerID,i))
        {
            //2
            if(i>286 && i<303 && !isPlayerHasShield(selectedTargetID))
            {
                C_ItemModificator item;
                item.name = "Dodatkowy efekt od Amunicji Odkształcającej (2)";
                item.value = 25;
                AdditionalItemAndDamage.append(item);
            }
            //5A
            if((i==291 || i==293 || i==295 || i==296 || i==300 || i==302) && !isPlayerHasShield(selectedTargetID))
            {
                C_ItemModificator item;
                item.name = "Dodatkowy efekt od Amunicji Odkształcającej (5A)";
                item.value = 25;
                AdditionalItemAndDamage.append(item);
            }

        }


}

bool calculator::isPlayerHasAmmoActive(int playerID)
{
    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID && GetEffectNameFromEffectID(PlayerActiveEffects.at(i).EffectID).contains("Amunicja"))
                return true;
   return false;
}

