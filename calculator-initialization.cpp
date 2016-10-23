#include "calculator.h"
#include "ui_calculator.h"

void calculator::InitializeAccModTable()
{
    ui->tableWidget_AccMod->setColumnWidth(0,300);
    ui->tableWidget_AccMod->setColumnWidth(1,50);
    ui->tableWidget_AccMod->horizontalHeader()->setStretchLastSection(true);

}

void calculator::InitializeDmgModTable()
{
    ui->tableWidget_DmgMod->setColumnWidth(0,300);
    ui->tableWidget_DmgMod->setColumnWidth(1,50);
    ui->tableWidget_DmgMod->horizontalHeader()->setStretchLastSection(true);

}

void calculator::InitializePlayersComboBox()
{
    //Create and populate custom Model with Players Name and PlayersID, where PlayerID is hidden
    comboboxPlayersModel = new QStandardItemModel(Players.size(),2,this);
    for (int i=0; i<Players.size();i++)
    {
        comboboxPlayersModel->setItem(i,0,new QStandardItem(Players.at(i).PlayerName));
        comboboxPlayersModel->setItem(i,1,new QStandardItem(QString::number(Players.at(i).PlayerID)));
    }
    ui->comboBox_select_player->setModel(comboboxPlayersModel);
    selectedPlayerID = comboboxPlayersModel->item(0,1)->text().toInt();
    selectedPlayerName = comboboxPlayersModel->item(0,0)->text();
}

void calculator::InitializeActionsComboBox()
{
    comboboxActionModel = new QStandardItemModel(Actions.size(),3,this);

    comboboxActionModel->setItem(0,0,new QStandardItem("--Wybierz akcję--"));
    comboboxActionModel->setItem(0,1,new QStandardItem("-1"));
    comboboxActionModel->setItem(0,2,new QStandardItem("9999"));

    for (int i=0; i<Actions.size();i++)
    {
        comboboxActionModel->setItem(i+1,0,new QStandardItem(Actions.at(i).Name));
        comboboxActionModel->setItem(i+1,1,new QStandardItem(QString::number(Actions.at(i).ID)));
        comboboxActionModel->setItem(i+1,2,new QStandardItem(QString::number(Actions.at(i).Cost)));
    }
    ui->comboBox_select_action->setModel(comboboxActionModel);
}

void calculator::InitializeTargetsComboBox()
{
    comboboxTargetsModel = new QStandardItemModel(Players.size(),2,this);
    comboboxTargetsModel->setItem(0,0,new QStandardItem("--Wybierz cel--"));
    comboboxTargetsModel->setItem(0,1,new QStandardItem("-1"));

    for (int i=0; i<Players.size();i++)
    {
        comboboxTargetsModel->setItem(i+1,0,new QStandardItem(Players.at(i).PlayerName));
        comboboxTargetsModel->setItem(i+1,1,new QStandardItem(QString::number(Players.at(i).PlayerID)));
    }
    comboboxTargetsModel->removeRow(1,QModelIndex());
    ui->comboBox_select_target->setModel(comboboxTargetsModel);

    selectedTargetID = -1;
    selectedTargetName = "Nie wybrano celu";
}

void calculator::InitializeDifficultyLevel()
{
    difficulty_level_name = "Nie wybrano poziomu trudności";
}

void calculator::InitializePlayerStats()
{
    int playerID = comboboxPlayersModel->item(0,1)->text().toInt();
    setVisualPlayerStats(playerID);
    setVisualPlayerActiveEffects(playerID);
}
