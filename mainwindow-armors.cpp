#include "mainwindow.h"
#include "ui_mainwindow.h"

//ALL ARMOR RELATED FUNCTIONS

void MainWindow::ClearArmorList()
{
    while (ui->listWidget_armors_list->count() > 0)
    {
        ui->listWidget_armors_list->clear();
    }
}

void MainWindow::AddArmorToList()
{
    QString selected_armorname;
    selected_armorname = ui->treeWidget_armor_list->currentItem()->text(0);

    for (int i=0; i<Armors.size(); i++)
    {
        if (Armors.at(i).ArmorName == selected_armorname)
        {
            ui->listWidget_armors_list->insertItem(ui->listWidget_armors_list->count(),new QListWidgetItem(Armors.at(i).ArmorName));
            ui->listWidget_armors_list_preview->insertItem(ui->listWidget_armors_list_preview->count(),new QListWidgetItem(Armors.at(i).ArmorName));
        }
    }
}

void MainWindow::RemoveArmorFromList()
{
    if(ui->listWidget_armors_list_preview->count() >0)
    {
        int selected_row = ui->listWidget_armors_list_preview->currentRow();
        ui->listWidget_armors_list->takeItem(selected_row);
        ui->listWidget_armors_list_preview->takeItem(selected_row);
    }
}

void MainWindow::RemoveArmorFromPlayer(int armorID, int playerID)
{
    for(int i=0;i<PlayerArmors.size();i++)
    {
        if(PlayerArmors.at(i).PlayerID == playerID && PlayerArmors.at(i).ArmorID == armorID)
            PlayerArmors.remove(i);
    }
}

void MainWindow::AddArmorToPlayer(int armorID, int playerID)
{
    C_PlayerArmor armor;
    armor.PlayerID = playerID;
    armor.ArmorID = armorID;
    PlayerArmors.append(armor);
}

int MainWindow::GetArmorIDFromArmorName(QString armorName)
{
    int armorID = 9999;
    for(int i=0;i<Armors.size();i++)
    {
        if(Armors.at(i).ArmorName == armorName )
            armorID = Armors.at(i).ArmorID;
    }
    return armorID;
}

QString MainWindow::GetArmorNameFromArmorID(int armorID)
{
    QString armorName = "NoSuchArmor";
    for(int i=0;i<Armors.size();i++)
    {
        if(Armors.at(i).ArmorID == armorID )
            armorName = Armors.at(i).ArmorName;
    }
    return armorName;
}

bool MainWindow::PlayerHasArmor(int playerID, int armorID)
{
    playerID = GetPlayerIndex(playerID);

    for(int i=0;i<PlayerArmors.size();i++)
    {
        if(PlayerArmors.at(i).PlayerID == playerID && PlayerArmors.at(i).ArmorID == armorID)
            return true;
    }
    return false;
}

//ALL ARMOR MOD RELATED FUNCTIONS

void MainWindow::AddArmorModToList()
{
    QString selected_modname;
    selected_modname = ui->comboBox_mod_armor_name->currentText();

    if(selected_modname != "Brak")
    {
        for (int i=0; i<ArmModList.size(); i++)
        {
            if (ArmModList.at(i).ArmorModName == selected_modname)
            {
                ui->listWidget_armormods_list->insertItem(ui->listWidget_armormods_list->count(),new QListWidgetItem(ArmModList.at(i).ArmorModName));
                ui->listWidget_armormods_list_preview->insertItem(ui->listWidget_armormods_list_preview->count(),new QListWidgetItem(ArmModList.at(i).ArmorModName));
            }
        }
    }
}

void MainWindow::RemoveArmorModFromList()
{
    if(ui->listWidget_armormods_list_preview->count()>0)
    {
        int selected_row = ui->listWidget_armormods_list_preview->currentRow();
        ui->listWidget_armormods_list->takeItem(selected_row);
        ui->listWidget_armormods_list_preview->takeItem(selected_row);
    }
}

void MainWindow::AddArmorModToPlayer(int armorModID, int playerID)
{
    C_PlayerArmorMods armormod;
    armormod.PlayerID = playerID;
    armormod.ArmorModID = armorModID;
    PlayerArmorMods.append(armormod);
}

void MainWindow::RemoveArmorModFromPlayer(int armorModID, int playerID)
{
    for(int i=0;i<PlayerArmorMods.size();i++)
    {
        if(PlayerArmorMods.at(i).PlayerID == playerID && PlayerArmorMods.at(i).ArmorModID == armorModID)
            PlayerArmorMods.remove(i);
    }
}

QString MainWindow::GetArmorModNameFromArmorModID(int modid)
{
    QString armmodname = "Brak";
    for (int i=0;i<ArmModList.size(); i++)
    {
        if(ArmModList.at(i).ModID == modid) armmodname = ArmModList.at(i).ArmorModName;
    }
    return armmodname;
}

int MainWindow::GetArmorModIDFromArmorModName(QString modName)
{
    int armmodID = 0;
    for (int i=0;i<ArmModList.size(); i++)
    {
        if(ArmModList.at(i).ArmorModName == modName) armmodID = ArmModList.at(i).ModID;
    }
    return armmodID;
}

bool MainWindow::PlayerHasArmorMod(int playerID, int armorModID)
{
    playerID = GetPlayerIndex(playerID);

    for(int i=0;i<PlayerArmorMods.size();i++)
    {
        if(PlayerArmorMods.at(i).PlayerID == playerID && PlayerArmorMods.at(i).ArmorModID == armorModID)
            return true;
    }
    return false;
}

void MainWindow::ClearArmorModList()
{
    while (ui->listWidget_armormods_list->count() > 0)
    {
        ui->listWidget_armormods_list->clear();
    }
}
