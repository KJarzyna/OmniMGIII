#include "calculator.h"
#include "ui_calculator.h"

QString calculator::GetPlayerNameFromPlayerID(int playerID)
{
    QString playerName = "NoPlayerNameForThisID";

    for (int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
            playerName = Players.at(i).PlayerName;
    return playerName;
}

void calculator::RemovePlayerFromTargetModel(int playerID)
{
    for(int i=0;i<comboboxTargetsModel->rowCount();i++)
        if(comboboxTargetsModel->item(i,1)->text().toInt() == playerID)
            comboboxTargetsModel->removeRow(i,QModelIndex());
}

void calculator::AddPlayerToTargetModel(int playerID)
{
    comboboxTargetsModel->insertRows(comboboxTargetsModel->rowCount(),1,QModelIndex());
    comboboxTargetsModel->setItem(comboboxTargetsModel->rowCount()-1,0,new QStandardItem(GetPlayerNameFromPlayerID(playerID)));
    comboboxTargetsModel->setItem(comboboxTargetsModel->rowCount()-1,1,new QStandardItem(QString::number(playerID)));
}

int calculator::GetPlayerSkillMastery(int playerID, QString skillType)
{
    for(int i=0;i<Players.size();i++)
    {
        if(Players.at(i).PlayerID == playerID && skillType == "Technologiczne")
            return Players.at(i).MasteryTechno;
        else if(Players.at(i).PlayerID == playerID && skillType == "Bojowe")
            return Players.at(i).MasteryBattle;
        else if(Players.at(i).PlayerID == playerID && skillType == "Biotyczne")
            return Players.at(i).MasteryBiotic;
        else if(Players.at(i).PlayerID == playerID && skillType == "Specjalizacja")
            return Players.at(i).MasterySpec;
    }
    return 0;
}

QString calculator::GetPlayerSpecializationSkill(int playerID)
{
    QString skill = "Unknown specialiation skill!";
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
            skill = Players.at(i).SpecializationSkill;
    return skill;
}

QStringList calculator::GetPlayerActiveEffects(int playerID)
{
    QStringList list;
    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID)
            list.append(GetEffectNameFromEffectID(PlayerActiveEffects.at(i).EffectID));

    return list;
}

QVector<int> calculator::GetPlayerActiveEffectsIDs(int playerID)
{
    QVector<int> list;
    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID)
            list.append(PlayerActiveEffects.at(i).EffectID);

    return list;
}

int calculator::GetPlayersArmorCostReduction(int playerID)
{
    ItemAndActionCost.clear();
    int cost_red = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID && Armors.at(j).ActionSkillCost != 0)
                {
                    C_ItemModificator item;
                    item.name = Armors.at(j).ArmorName;
                    item.value = Armors.at(j).ActionSkillCost;
                    ItemAndActionCost.append(item);

                    cost_red += Armors.at(j).ActionSkillCost;
                }
    return cost_red;
}

int calculator::GetPlayerEvasiveness(int playerID)
{
    for(int i=0;i<Players.size();i++)
    {
        if(Players.at(i).PlayerID == playerID)
        {
            if(Players.at(i).PlayerRace == "Człowiek" || Players.at(i).PlayerRace == "Asari")
                return 50;
            else if(Players.at(i).PlayerRace == "Turianin" || Players.at(i).PlayerRace == "Batarianin")
                return 55;
            else if(Players.at(i).PlayerRace == "Quarianin" || Players.at(i).PlayerRace == "Salarianin")
                return 40;
            else if(Players.at(i).PlayerRace == "Geth" || Players.at(i).PlayerRace == "Kroganin")
                return 60;
            else if(Players.at(i).PlayerRace == "Vorcha" || Players.at(i).PlayerRace == "Drell")
                return 45;
            else
                return 50;
        }
    }
}

int calculator::GetPlayersArmorWpnAccModifier(int playerID)
{
    int mod = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID)
                    mod += Armors.at(j).AdditionalWpnAcc;
    return mod;
}

int calculator::GetPlayersArmorWpnDiffLevelModifier(int playerID)
{
    ItemAndDifficulty.clear();
    int mod = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID && Armors.at(j).WpnLevelDifficulty != 0)
                {
                    C_ItemModificator item;
                    item.name = Armors.at(j).ArmorName;
                    item.value = Armors.at(j).WpnLevelDifficulty;
                    ItemAndDifficulty.append(item);

                    mod += Armors.at(j).WpnLevelDifficulty;
                }
    return mod;
}

int calculator::GetPlayersArmorSkillAccModifier(int playerID)
{
    ItemAndAccuracy.clear();
    int mod = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID && Armors.at(j).AdditionalSkillAcc != 0)
                {
                    C_ItemModificator item;
                    item.name = Armors.at(j).ArmorName;
                    item.value = Armors.at(j).AdditionalSkillAcc;
                    ItemAndAccuracy.append(item);

                    mod += Armors.at(j).AdditionalSkillAcc;
                }
    return mod;
}

int calculator::GetPlayersArmorSkillDiffLevelModifier(int playerID)
{
    ItemAndDifficulty.clear();
    int mod = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID && Armors.at(j).SkillLevelDifficulty != 0)
                {
                    C_ItemModificator item;
                    item.name = Armors.at(j).ArmorName;
                    item.value = Armors.at(j).SkillLevelDifficulty;
                    ItemAndDifficulty.append(item);

                    mod += Armors.at(j).SkillLevelDifficulty;
                }
    return mod;
}

int calculator::GetPlayersArmorMeeleeDiffLevelModifier(int playerID)
{
    ItemAndDifficulty.clear();
    int mod = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID && Armors.at(j).MeeleeLevelDifficulty != 0)
                {
                    C_ItemModificator item;
                    item.name = Armors.at(j).ArmorName;
                    item.value = Armors.at(j).MeeleeLevelDifficulty;
                    ItemAndDifficulty.append(item);

                    mod += Armors.at(j).MeeleeLevelDifficulty;
                }
    return mod;
}

int calculator::GetPlayersOmnibladeID(int playerID)
{
    int ID = 9999;
    for(int i=0;i<PlayerOmniblades.size();i++)
        if(PlayerOmniblades.at(i).PlayerID == playerID)
            ID = PlayerOmniblades.at(i).OmnibladeID;
    return ID;
}

int calculator::GetPlayersArmorCriticalChanceModifier(int playerID)
{
    ItemAndCritical.clear();
    int mod = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID && Armors.at(j).AdditionalCritChance != 0)
                {
                    C_ItemModificator item;
                    item.name = Armors.at(j).ArmorName;
                    item.value = Armors.at(j).AdditionalCritChance;
                    ItemAndCritical.append(item);

                    mod += Armors.at(j).AdditionalCritChance;
                }
    return mod;
}

bool calculator::isPlayerHasShield(int playerID)
{
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID && Players.at(i).ShieldCurrent > 0)
            return true;
   return false;
}

bool calculator::isPlayerHasBarrier(int playerID)
{
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID && Players.at(i).BarrierCurrent > 0)
            return true;
   return false;
}

bool calculator::isPlayerHasEffect(int playerID, int effectID)
{
    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID && PlayerActiveEffects.at(i).EffectID == effectID)
            return true;
   return false;
}

int calculator::GetPlayerArmorCurrentAfterDamage(int playerID, int damage)
{
    int output = 99999;
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
        {
            output = Players.at(i).ArmorCurrent - damage;

            if(output > Players.at(i).ArmorMax)
                output = Players.at(i).ArmorMax;
        }

    return output;

}

int calculator::GetPlayerMaxShield(int playerID)
{
    int output = 0;
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
            output = Players.at(i).ShieldMax;
    return output;
}

int calculator::GetPlayerMaxArmor(int playerID)
{
    int output = 0;
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
            output = Players.at(i).ArmorMax;
    return output;
}

int calculator::GetPlayerShieldCurrentAfterDamage(int playerID, int damage)
{
    int output = 99999;
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
            output = Players.at(i).ShieldCurrent - damage;

    if(output < 0)
        output = 0;

    return output;

}

int calculator::GetPlayerBarrierAfterDamage(int playerID, int damage)
{
    int output = 99999;
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
            output = Players.at(i).BarrierCurrent - damage;

    if(output < 0)
        output = 0;

    return output;

}

int calculator::GetPlayerTechnoBuffFromOmnikey(int playerID)
{
    int output = 0;
    int omniID = 99999;
    for(int i=0;i<PlayerOmnikeys.size();i++)
        if(PlayerOmnikeys.at(i).PlayerID == playerID)
            omniID = PlayerOmnikeys.at(i).OmnikeyID;
    for(int i=0;i<Omnikeys.size();i++)
        if(Omnikeys.at(i).ID == omniID)
            output = Omnikeys.at(i).TechnoBuff;

    return output;
}

void calculator::setPlayerCurrentArmor(int playerID, int value)
{
     for(int i=0;i<Players.size();i++)
         if(Players.at(i).PlayerID == playerID)
             Players[i].ArmorCurrent = value;
}

void calculator::setPlayerCurrentShield(int playerID, int value)
{
     for(int i=0;i<Players.size();i++)
         if(Players.at(i).PlayerID == playerID)
             Players[i].ShieldCurrent = value;
}

void calculator::setPlayerBarrier(int playerID, int value)
{
     for(int i=0;i<Players.size();i++)
         if(Players.at(i).PlayerID == playerID)
             Players[i].BarrierCurrent = value;
}

void calculator::reloadPlayerWeapon(int playerID, int weaponID)
{
    int ammoMax = 0;
    for(int i=0;i<Weapons.size();i++)
        if(Weapons.at(i).WeaponID == weaponID)
            ammoMax = Weapons.at(i).AmmoMaxInClip;

    for(int i=0;i<PlayerWeapons.size();i++)
        if(PlayerWeapons.at(i).PlayerID == playerID && PlayerWeapons.at(i).WeaponID == weaponID)
            PlayerWeapons[i].AmmoLeft = ammoMax;
}

void calculator::subtractAmmoFromPlayerWeapon(int playerID, int weaponID)
{
    int ammoPerShot = 0;
    int ammoLeft = 0;
    for(int i=0;i<Weapons.size();i++)
        if(Weapons.at(i).WeaponID == weaponID)
            ammoPerShot = Weapons.at(i).AmmoPerShot;

    for(int i=0;i<PlayerWeapons.size();i++)
        if(PlayerWeapons.at(i).PlayerID == playerID && PlayerWeapons.at(i).WeaponID == weaponID)
        {
            ammoLeft = PlayerWeapons.at(i).AmmoLeft;
            if(ammoLeft - ammoPerShot < 0)
                PlayerWeapons[i].AmmoLeft = 0;
            else
                PlayerWeapons[i].AmmoLeft = PlayerWeapons.at(i).AmmoLeft - ammoPerShot;
        }
}
