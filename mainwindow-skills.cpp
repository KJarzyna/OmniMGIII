#include "mainwindow.h"
#include "ui_mainwindow.h"

//ALL SKILL RELATED FUNCTIONS

void MainWindow::AddSkillToTable()
{
    QString selected_skillname, selected_skilllevel;
    selected_skillname = ui->treeWidget_skill_list->currentItem()->text(0);
    selected_skilllevel = ui->comboBox_skill_level->currentText();

    for (int i=0; i<Skills.size(); i++)
    {
        if (Skills.at(i).SkillName == selected_skillname && Skills.at(i).SkillLevel == selected_skilllevel)
        {
            ui->tableWidget_skills->insertRow(ui->tableWidget_skills->rowCount());
            ui->tableWidget_skills->setItem(ui->tableWidget_skills->rowCount()-1,0,new QTableWidgetItem(Skills.at(i).SkillName));
            ui->tableWidget_skills->setItem(ui->tableWidget_skills->rowCount()-1,1,new QTableWidgetItem(Skills.at(i).SkillLevel));
            ui->tableWidget_skills->setItem(ui->tableWidget_skills->rowCount()-1,2,new QTableWidgetItem(QString::number(Skills.at(i).Cost))); //QString::number because Cost is an integer
            ui->tableWidget_skills->setItem(ui->tableWidget_skills->rowCount()-1,3,new QTableWidgetItem(Skills.at(i).SkillType));
        }
    }
}

void MainWindow::AddSkillToPlayer(int skillID, int playerID)
{
    C_PlayerSkill skill;
    skill.PlayerID = playerID;
    skill.SkillID = skillID;
    PlayerSkills.append(skill);
}

void MainWindow::RemoveSkillFromTable()
{
    int playerID = 0;
    int selected_row = ui->tableWidget_skills->currentRow();

    if(ui->tableWidget_skills->item(selected_row,0)->text() == Players.at(playerID).SpecializationSkill)
    {
        RemoveSpecializationFromPlayer(playerID);
    }

    ui->tableWidget_skills->removeRow(selected_row);
}

void MainWindow::RemoveSkillFromPlayer(int skillID, int playerID)
{
    for(int i=0;i<PlayerSkills.size();i++)
    {
        if(PlayerSkills.at(i).PlayerID == playerID && PlayerSkills.at(i).SkillID == skillID)
            PlayerSkills.remove(i);
    }
}

void MainWindow::RemoveSpecializationFromPlayer(int playerID)
{
    Players.value(playerID).SpecializationSkill = "NoSpecialization";
    ui->comboBox_specialization->setCurrentIndex(0);
}

void MainWindow::ClearSkillTable()
{
    while (ui->tableWidget_skills->rowCount() > 0)
{
        ui->tableWidget_skills->removeRow(ui->tableWidget_skills->rowCount()-1);
    }
}

void MainWindow::CalculatePlayerMasteries(int playerID)
{
    int PointsBattle = 0;
    int PointsTechno = 0;
    int PointsBiotic = 0;
    int PointsSpec = 0;

    int baseBattle = 30;
    int baseBiotic = 30;
    int baseTechno = 30;

    int MasteryBattle = 0;
    int MasteryBiotic = 0;
    int MasteryTechno = 0;
    int MasterySpec = 0;

    PointsBattle = GetPlayerMasteryPoints(playerID, "Bojowe");
    PointsBiotic = GetPlayerMasteryPoints(playerID, "Biotyczne");
    PointsTechno = GetPlayerMasteryPoints(playerID, "Technologiczne");

    if(GetPlayerSpecializationType(playerID) == "Bojowe")
    {
        baseBattle = 20;
        PointsSpec = PointsBattle;
    }
    else if(GetPlayerSpecializationType(playerID) == "Biotyczne")
    {
        baseBiotic = 20;
        PointsSpec = PointsBiotic;
    }
    else if(GetPlayerSpecializationType(playerID) == "Technologiczne")
    {
        baseTechno = 20;
        PointsSpec = PointsTechno;
    }


    if(GetPlayerSpecializationType(playerID) == "NoSpecialization")
    {
        MasteryBattle = baseBattle + PointsBattle*5;
        MasteryBiotic = baseBiotic + PointsBiotic*5;
        MasteryTechno = baseTechno + PointsTechno*5;
    }
    else
    {
        MasteryBattle = baseBattle + PointsBattle*5;
        MasteryBiotic = baseBiotic + PointsBiotic*5;
        MasteryTechno = baseTechno + PointsTechno*5;
        MasterySpec = 50 + PointsSpec*5;
    }

    if (MasteryBattle > 90) MasteryBattle = 90;
    if (MasteryBiotic > 90) MasteryBiotic = 90;
    if (MasteryTechno > 90) MasteryTechno = 90;
    if (MasterySpec > 90) MasterySpec = 90;

    int playerIndex = GetPlayerIndex(playerID);

    Players[playerIndex].MasteryBattle = MasteryBattle;
    Players[playerIndex].MasteryBiotic = MasteryBiotic;
    Players[playerIndex].MasteryTechno = MasteryTechno;
    Players[playerIndex].MasterySpec = MasterySpec;

}

int MainWindow::GetPlayerMasteryPoints(int playerID, QString mastery)
{
    int masteryPoints = 0;

    for (int i=0; i<PlayerSkills.size(); i++)
    {
        if (PlayerSkills.at(i).PlayerID == playerID)
        {
            for (int j=0; j<Skills.size(); j++)
            {
                if (Skills.at(j).SkillID == PlayerSkills.at(i).SkillID)
                {
                    if (Skills.at(j).SkillType == mastery)
                    {
                        masteryPoints += Skills.at(j).SkillLevel.left(1).toInt();
                    }

                    else if (Skills.at(j).SkillType == "Klasowe")
                    {
                        if (Skills.at(j).SkillName == "Nowa" && mastery == "Biotyczne")
                        {
                            masteryPoints += Skills.at(j).SkillLevel.left(1).toInt();
                        }
                        else if (Skills.at(j).SkillName == "Szarża Biotyczna" && mastery == "Biotyczne")
                        {
                            masteryPoints += Skills.at(j).SkillLevel.left(1).toInt();
                        }
                        else if (Skills.at(j).SkillName == "Pancerz Technologiczny" && mastery == "Technologiczne")
                        {
                            masteryPoints += Skills.at(j).SkillLevel.left(1).toInt();

                        }
                        else if (Skills.at(j).SkillName == "Kamuflaż Taktyczny" && mastery == "Technologiczne")
                        {
                            masteryPoints += Skills.at(j).SkillLevel.left(1).toInt();
                        }

                        else if (Skills.at(j).SkillName == "Amunicja Dysrupcyjna" && mastery == "Bojowe")
                        {
                             masteryPoints += Skills.at(j).SkillLevel.left(1).toInt();
                        }
                    }
     }}}}
    return masteryPoints;
}

QString MainWindow::GetPlayerSpecializationType(int playerID)
{
    QString specialization_type = "NoSpecialization";

    int playerIndex = GetPlayerIndex(playerID);

        if(Players.at(playerIndex).SpecializationSkill != "NoSpecialization")
        {
            for (int j=0;j<Skills.size();j++)
            {
                if(Skills.at(j).SkillName == Players.at(playerIndex).SpecializationSkill)
                {
                   specialization_type = Skills.at(j).SkillType;
                }
            }
        }

    return specialization_type;
}

int MainWindow::GetSkillIDFromSkillNameAndLevel(QString skillName, QString skillLevel)
{
    int skillID = 9999;
    for(int i=0;i<Skills.size();i++)
    {
        if(Skills.at(i).SkillName == skillName && Skills.at(i).SkillLevel == skillLevel)
            skillID = Skills.at(i).SkillID;
    }
    return skillID;
}

QString MainWindow::GetSkillNameFromSkillID(int skillID)
{
    QString skillName = "NO_SUCH_SKILL";
    for(int i=0;i<Skills.size();i++)
    {
        if(Skills.at(i).SkillID == skillID)
            skillName = Skills.at(i).SkillName;
    }
    return skillName;
}

bool MainWindow::PlayerHasSkill(int playerID, QString skillName)
{
    playerID = GetPlayerIndex(playerID);

    for(int i=0;i<PlayerSkills.size();i++)
    {
        if(PlayerSkills.at(i).PlayerID == playerID && GetSkillNameFromSkillID(PlayerSkills.at(i).SkillID) == skillName)
            return true;
    }
    return false;
}