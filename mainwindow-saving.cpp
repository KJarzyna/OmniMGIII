#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::SaveGeneralTabToVector(int playerID)
{
    int playerIndex = GetPlayerIndex(playerID);
    Players[playerIndex].PlayerName = ui->lineEdit_player_name->text();
    Players[playerIndex].PlayerRace = ui->lineEdit_player_race->text();
    Players[playerIndex].PlayerClass = ui->lineEdit_player_class->text();
    Players[playerIndex].PlayerType = ui->comboBox_player_type->currentText();

    Players[playerIndex].ArmorCurrent = ui->lineEdit_armor_current->text().toInt();
    Players[playerIndex].ArmorMax = ui->lineEdit_armor_full->text().toInt();
    Players[playerIndex].ShieldCurrent = ui->lineEdit_shield_current->text().toInt();
    Players[playerIndex].ShieldMax = ui->lineEdit_shield_full->text().toInt();

    //Players[playerIndex].ActiveEffects = ui->lineEdit_player_activeeffect->text();
    //Players[playerIndex].Status = ui->lineEdit_player_status->text();
}

void MainWindow::SaveGeneralTab(int playerID)
{
    SaveGeneralTabToVector(playerID);
}

void MainWindow::SaveSkillsTabToVector(int playerID)
{
    int playerIndex = GetPlayerIndex(playerID);

    CalculatePlayerMasteries(playerID);
    Players[playerIndex].SpecializationSkill = ui->comboBox_specialization->currentText();

    RemoveAllPlayerSkillsFromVector(playerID);
    AddAllPlayerSkillsToVector(playerID);
}

void MainWindow::RemoveAllPlayerSkillsFromVector(int playerID)
{
    for (int i=0;i<PlayerSkills.size();i++)
    {
        if(PlayerSkills.at(i).PlayerID == playerID)
        {
            PlayerSkills.remove(i);
            i=i-1;
        }
    }
}

void MainWindow::AddAllPlayerSkillsToVector(int playerID)
{
    QString skillName, skillLevel;
    int skillID;
    for (int i=0;i<ui->tableWidget_skills->rowCount();i++)
    {
        skillName = ui->tableWidget_skills->item(i,0)->text();
        skillLevel = ui->tableWidget_skills->item(i,1)->text();
        skillID = GetSkillIDFromSkillNameAndLevel(skillName, skillLevel);

        C_PlayerSkill player_skill;
        player_skill.PlayerID = playerID;
        player_skill.SkillID = skillID;
        PlayerSkills.append(player_skill);
    }
}

void MainWindow::SaveSkillsTab(int playerID)
{
    SaveSkillsTabToVector(playerID);
}
