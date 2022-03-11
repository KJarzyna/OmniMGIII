#include "mainwindow.h"
#include "ui_mainwindow.h"

//ALL WEAPONS RELATED FUNCTIONS


void MainWindow::ClearWeaponTable()
{
    while (ui->tableWidget_weapons->rowCount() > 0)
    {
        ui->tableWidget_weapons->removeRow(ui->tableWidget_weapons->rowCount()-1);
    }

    while (ui->tableWidget_weapons_preview->rowCount() > 0)
    {
        ui->tableWidget_weapons_preview->removeRow(ui->tableWidget_weapons_preview->rowCount()-1);
    }
}

void MainWindow::AddWeaponToTable()
{
    QString selected_weaponname;
    selected_weaponname = ui->treeWidget_weapon_list->currentItem()->text(0);

    for (int i=0; i<Weapons.size(); i++)
    {
        if (Weapons.at(i).WeaponName == selected_weaponname)
        {
            int new_row = ui->tableWidget_weapons->rowCount();
            ui->tableWidget_weapons->insertRow(new_row);
            ui->tableWidget_weapons->setItem(new_row,0,new QTableWidgetItem(Weapons.at(i).WeaponName));
            ui->tableWidget_weapons->setItem(new_row,1,new QTableWidgetItem(QString::number(Weapons.at(i).DmgBase)));
            ui->tableWidget_weapons->setItem(new_row,2,new QTableWidgetItem(QString::number(Weapons.at(i).Acc)));
            ui->tableWidget_weapons->setItem(new_row,3,new QTableWidgetItem(QString::number(Weapons.at(i).Recoil)));
            ui->tableWidget_weapons->setItem(new_row,4,new QTableWidgetItem(GetActionCostFromCost(Weapons.at(i).Cost)));
            ui->tableWidget_weapons->setItem(new_row,5,new QTableWidgetItem(Weapons.at(i).WeaponType));
            ui->tableWidget_weapons->setItem(new_row,6,new QTableWidgetItem("Brak"));
            ui->tableWidget_weapons->setItem(new_row,7,new QTableWidgetItem("Brak"));

            ui->tableWidget_weapons_preview->insertRow(new_row);
            ui->tableWidget_weapons_preview->setItem(new_row,0,new QTableWidgetItem(Weapons.at(i).WeaponName));
            ui->tableWidget_weapons_preview->setItem(new_row,1,new QTableWidgetItem(Weapons.at(i).WeaponType));
            ui->tableWidget_weapons_preview->setItem(new_row,2,new QTableWidgetItem("Brak"));
            ui->tableWidget_weapons_preview->setItem(new_row,3,new QTableWidgetItem("Brak"));

            ui->tableWidget_weapons->item(new_row,0)->setTextAlignment(Qt::AlignVCenter);
            ui->tableWidget_weapons->item(new_row,1)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_weapons->item(new_row,2)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_weapons->item(new_row,3)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_weapons->item(new_row,4)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_weapons->item(new_row,5)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_weapons->item(new_row,6)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_weapons->item(new_row,7)->setTextAlignment(Qt::AlignCenter);

            ui->tableWidget_weapons_preview->item(new_row,0)->setTextAlignment(Qt::AlignVCenter);
            ui->tableWidget_weapons_preview->item(new_row,1)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_weapons_preview->item(new_row,2)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_weapons_preview->item(new_row,3)->setTextAlignment(Qt::AlignCenter);
        }
    }
}


void MainWindow::RemoveWeaponFromTable()
{
    int selected_row = ui->tableWidget_weapons_preview->currentRow();
    ui->tableWidget_weapons->removeRow(selected_row);
    ui->tableWidget_weapons_preview->removeRow(selected_row);
}


void MainWindow::RemoveWeaponFromPlayer(int weaponID, int playerID)
{
    for(int i=0;i<PlayerWeapons.size();i++)
    {
        if(PlayerWeapons.at(i).PlayerID == playerID && PlayerWeapons.at(i).WeaponID == weaponID)
            PlayerWeapons.remove(i);
    }
}

void MainWindow::AddWeaponToPlayer(int weaponID, int playerID)
{
    int AmmoMax = 0;
    for (int i=0;i<Weapons.size();i++)
    {
        if(Weapons.at(i).WeaponID == weaponID)
            AmmoMax = Weapons.at(i).AmmoMaxInClip;
    }

    C_PlayerWeapon weapon;
    weapon.PlayerID = playerID;
    weapon.WeaponID = weaponID;
    weapon.ModID = 0;
    weapon.AmmoLeft = AmmoMax;
    PlayerWeapons.append(weapon);

}

int MainWindow::GetWeaponIDFromWeaponName(QString weaponName)
{
    int weaponID = 9999;
    for(int i=0;i<Weapons.size();i++)
    {
        if(Weapons.at(i).WeaponName == weaponName )
            weaponID = Weapons.at(i).WeaponID;
    }
    return weaponID;
}

QString MainWindow::GetWeaponNameFromWeaponID(int weaponID)
{
    QString weaponname = "Brak";
    for (int i=0;i<Weapons.size(); i++)
    {
        if(Weapons.at(i).WeaponID == weaponID) weaponname = Weapons.at(i).WeaponName;
    }
    return weaponname;
}


int MainWindow::GetCurrentAmmoInPlayerWeaponFromWeaponID(int weaponID, int playerID)
{
    int ammo = 0;

    for (int i=0;i<PlayerWeapons.size(); i++)
    {
        if(PlayerWeapons.at(i).WeaponID == weaponID && PlayerWeapons.at(i).PlayerID == playerID) ammo = PlayerWeapons.at(i).AmmoLeft;
    }
    return ammo;
}

// WEAPON MODS REALTED FUNCTIONS
void MainWindow::AddWpnModToTable(int selected_col)
{
    QString selected_modname;
    selected_modname = ui->treeWidget_wpnmod_list->currentItem()->text(0);

    for (int i=0; i<WpnModList.size(); i++)
    {
        if (WpnModList.at(i).ModName == selected_modname)
        {
            int selectedWeaponInTable = ui->tableWidget_weapons_preview->currentRow();
            if(selected_col == 2)
            {
                ui->tableWidget_weapons->setItem(selectedWeaponInTable,7,new QTableWidgetItem(WpnModList.at(i).ModName));
                ui->tableWidget_weapons_preview->setItem(selectedWeaponInTable,2,new QTableWidgetItem(WpnModList.at(i).ModName));
                ui->tableWidget_weapons->item(selectedWeaponInTable,7)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_weapons_preview->item(selectedWeaponInTable,2)->setTextAlignment(Qt::AlignCenter);
            }
            else if(selected_col == 3)
            {
                ui->tableWidget_weapons->setItem(selectedWeaponInTable,8,new QTableWidgetItem(WpnModList.at(i).ModName));
                ui->tableWidget_weapons_preview->setItem(selectedWeaponInTable,3,new QTableWidgetItem(WpnModList.at(i).ModName));
                ui->tableWidget_weapons->item(selectedWeaponInTable,8)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_weapons_preview->item(selectedWeaponInTable,3)->setTextAlignment(Qt::AlignCenter);
            }
            else;
        }
    }
}

void MainWindow::RemoveWpnModFromTable()
{
    if(ui->tableWidget_weapons_preview->rowCount()>0)
    {
        int selected_row = ui->tableWidget_weapons_preview->currentRow();
        int selected_col = ui->tableWidget_weapons_preview->currentColumn();
        if(selected_col == 2)
        {
            ui->tableWidget_weapons->item(selected_row,7)->setText("Brak");
            ui->tableWidget_weapons_preview->item(selected_row,2)->setText("Brak");
        }
        else if(selected_col == 3)
        {
            ui->tableWidget_weapons->item(selected_row,8)->setText("Brak");
            ui->tableWidget_weapons_preview->item(selected_row,3)->setText("Brak");
        }
        else;
    }
}

void MainWindow::AddWpnModToPlayer(int wpnModID, int weaponID, int playerID)
{
    for (int i=0;i<PlayerWeapons.size();i++)
    {
        if(PlayerWeapons.at(i).PlayerID == playerID && PlayerWeapons.at(i).WeaponID == weaponID)
            PlayerWeapons[i].ModID = wpnModID;
    }
}

void MainWindow::RemoveWpnModFromPlayer(int weaponID, int playerID)
{
    for(int i=0;i<PlayerWeapons.size();i++)
    {
        if(PlayerWeapons.at(i).PlayerID == playerID && PlayerWeapons.at(i).WeaponID == weaponID)
            PlayerWeapons[i].ModID = 0;
    }
}

bool MainWindow::isModTypeGoodWithWpnType(int weaponModID, int weaponID)
{
    QString wpnModType = "ModNoType";
    QString wpnType = "WpnNoType";

    for (int i=0;i<WpnModList.size();i++)
    {
        if(WpnModList.at(i).ModID == weaponModID)
            wpnModType = WpnModList.at(i).ModType;
    }

    for (int i=0;i<Weapons.size();i++)
    {
        if(Weapons.at(i).WeaponID == weaponID)
            wpnType = Weapons.at(i).WeaponType;
    }

    if (wpnModType.contains(wpnType))
        return true;
    else
        return false;
}

QString MainWindow::GetWpnModNameFromWpnModID(int modid)
{
    QString wpnmodname = "Brak";
    for (int i=0;i<WpnModList.size(); i++)
    {
        if(WpnModList.at(i).ModID == modid) wpnmodname = WpnModList.at(i).ModName;
    }
    return wpnmodname;
}

int MainWindow::GetWpnModIDFromWpnModName(QString modName)
{
    int wpnmodID = 0;
    for (int i=0;i<WpnModList.size(); i++)
    {
        if(WpnModList.at(i).ModName == modName) wpnmodID = WpnModList.at(i).ModID;
    }
    return wpnmodID;
}

// AMMO REALTED FUNCTIONS
void MainWindow::ClearAmmoTable()
{
    while (ui->tableWidget_wpn_ammo->rowCount() > 0)
        ui->tableWidget_wpn_ammo->removeRow(ui->tableWidget_wpn_ammo->rowCount()-1);
}

void MainWindow::AddWeaponToAmmoTable()
{
        QString selected_weaponname;
        selected_weaponname = ui->treeWidget_weapon_list->currentItem()->text(0);


        for (int i=0; i<Weapons.size(); i++)
        {
            if (Weapons.at(i).WeaponName == selected_weaponname)
            {
                //int AmmoLeft = GetCurrentAmmoInPlayerWeaponFromWeaponID(Weapons.at(i).WeaponID,playerID);
                int new_row = ui->tableWidget_wpn_ammo->rowCount();
                ui->tableWidget_wpn_ammo->insertRow(new_row);
                ui->tableWidget_wpn_ammo->setRowHeight(new_row,20);
                ui->tableWidget_wpn_ammo->setItem(new_row,0,new QTableWidgetItem(Weapons.at(i).WeaponName));
                ui->tableWidget_wpn_ammo->setItem(new_row,1,new QTableWidgetItem(QString::number(Weapons.at(i).AmmoMaxInClip)));
                ui->tableWidget_wpn_ammo->setItem(new_row,2,new QTableWidgetItem(QString::number(Weapons.at(i).AmmoMaxInClip)));
                ui->tableWidget_wpn_ammo->item(new_row,2)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_wpn_ammo->item(new_row,1)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_wpn_ammo->item(new_row,0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            }
        }

}

void MainWindow::RemoveWeaponFromAmmoTable()
{
    int selected_row = ui->tableWidget_weapons->currentRow();
    ui->tableWidget_wpn_ammo->removeRow(selected_row);
}

int MainWindow::GetMaxAmmoOfWeaponFromWeaponName(QString Name)
{
    int MaxAmmo = 0;
    for(int i=0;i<Weapons.size();i++)
    {
        if(Weapons.at(i).WeaponName == Name)
        {
            MaxAmmo = Weapons.at(i).AmmoMaxInClip;
        }
    }

    return MaxAmmo;
}

// CALCULATOR FOR NOW

void MainWindow::Reload(int playerID, int weaponID)
{
    QString weaponName = GetWeaponNameFromWeaponID(weaponID);

    for(int i=0;i<ui->tableWidget_wpn_ammo->rowCount();i++)
    {
        if(ui->tableWidget_wpn_ammo->item(i,0)->text() == weaponName)
        {
            int ammoMax = GetMaxAmmoOfWeaponFromWeaponName(weaponName);
            ui->tableWidget_wpn_ammo->item(i,1)->setText(QString::number(ammoMax));
        }
    }

    for(int i=0;i<PlayerWeapons.size();i++)
    {
        if(PlayerWeapons.at(i).PlayerID == playerID && PlayerWeapons.at(i).WeaponID == weaponID)
            PlayerWeapons[i].AmmoLeft = GetMaxAmmoOfWeaponFromWeaponName(weaponName);
    }
}

void MainWindow::ReloadAll(int playerID, int selected_row)
{
    int weaponID = GetWeaponIDFromWeaponName(ui->tableWidget_wpn_ammo->item(selected_row,0)->text());

    for(int i=0;i<PlayerWeapons.size();i++)
    {
       if(PlayerWeapons.at(i).PlayerID == playerID && PlayerWeapons.at(i).WeaponID == weaponID)
           Reload(playerID,weaponID);
    }
}
