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

void calculator::setPlayerStats(int playerID)
{
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
        {
            ui->label_current_armor->setText(QString::number(Players.at(i).ArmorCurrent));
            ui->label_max_armor->setText(QString::number(Players.at(i).ArmorMax));
            ui->label_current_shield->setText(QString::number(Players.at(i).ShieldCurrent));
            ui->label_max_shield->setText(QString::number(Players.at(i).ShieldMax));
        }
}

void calculator::setPlayerActiveEffects(int playerID)
{
    ui->listWidget_player_conditions->clear();
    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID)
            ui->listWidget_player_conditions->addItem(GetEffectNameFromEffectID(PlayerActiveEffects.at(i).EffectID));
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
        else
            return 0;
    }
}

QString calculator::GetPlayerSpecializationSkill(int playerID)
{
    QString skill = "Unknown specialiation skill!";
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
            skill = Players.at(i).SpecializationSkill;
    return skill;
}

int calculator::GetPlayersArmorCostReduction(int playerID)
{
    int cost_red = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID)
                    cost_red += Armors.at(j).ActionSkillCost;
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
    int mod = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID)
                    mod += Armors.at(j).WpnLevelDifficulty;
    return mod;
}

int calculator::GetPlayersArmorSkillAccModifier(int playerID)
{
    int mod = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID)
                    mod += Armors.at(j).AdditionalSkillAcc;
    return mod;
}

int calculator::GetPlayersArmorSkillDiffLevelModifier(int playerID)
{
    int mod = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID)
                    mod += Armors.at(j).SkillLevelDifficulty;
    return mod;
}

int calculator::GetPlayersArmorMeeleeDiffLevelModifier(int playerID)
{
    int mod = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID)
                    mod += Armors.at(j).MeeleeLevelDifficulty;
    return mod;
}
