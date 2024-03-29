#include "mainwindow.h"
#include "ui_mainwindow.h"

//General
void MainWindow::LoadPlayerGeneralTab(int playerID)
{
    //Loads selected player's data into the "Ogólne" Tab

    int playerIndex = GetPlayerIndex(playerID);

    ui->lineEdit_player_name->setText(Players.at(playerIndex).PlayerName);
    //ui->lineEdit_player_race->setText(Players.at(playerIndex).PlayerRace);
    ui->comboBox_player_race->setCurrentText(Players.at(playerIndex).PlayerRace);
    ui->lineEdit_player_class->setText(Players.at(playerIndex).PlayerClass);
    if(Players.at(playerIndex).PlayerType == "Gracz")
        ui->comboBox_player_type->setCurrentIndex(0);
    else
        ui->comboBox_player_type->setCurrentIndex(1);
    ui->lineEdit_armor_current->setText(QString::number(Players.at(playerIndex).ArmorCurrent));
    ui->lineEdit_armor_full->setText(QString::number(Players.at(playerIndex).ArmorMax));
    ui->lineEdit_shield_current->setText(QString::number(Players.at(playerIndex).ShieldCurrent));
    ui->lineEdit_shield_full->setText(QString::number(Players.at(playerIndex).ShieldMax));
    //ui->lineEdit_barrier_current->setText(QString::number(Players.at(playerIndex).BarrierCurrent));

    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID)
            ui->listWidget_player_conditions->addItem(GetEffectNameFromEffectID(PlayerActiveEffects.at(i).EffectID));

    ui->plainTextEdit->setPlainText(Players.at(playerIndex).Notes);

}

//Skill related
//void MainWindow::LoadPlayerSpecialization(int playerID)
//{
//    //Loads selected player's specialization into the "Zdolności Tab"

//    int playerIndex = GetPlayerIndex(playerID);

//    ui->comboBox_specialization->setCurrentText("Brak");
//    ui->label_skill_specialization->setText("Umiejętność specjalizacji:");

//    if(Players.at(playerIndex).SpecializationSkill != "NoSpecialization")
//    {
//        for (int j=0; j<Skills.size(); j++)
//        {
//            if(Skills.at(j).SkillName == Players.at(playerIndex).SpecializationSkill)
//            {
//                ui->comboBox_specialization->setCurrentText(Players.at(playerIndex).SpecializationSkill);
//                QString specialization_label = Players.at(playerIndex).SpecializationSkill + ":";
//                ui->label_skill_specialization->setText(specialization_label);
//            }
//        }
//    }
//}

void MainWindow::LoadPlayerMasteries(int playerID)
{
    int playerIndex = GetPlayerIndex(playerID);

    ui->lineEdit_skill_calcvalue_bojowe->setText(QString::number(Players.at(playerIndex).MasteryBattle)+"%");
    ui->lineEdit_skill_calcvalue_biotyczne->setText(QString::number(Players.at(playerIndex).MasteryBiotic)+"%");
    ui->lineEdit_skill_calcvalue_technologiczne->setText(QString::number(Players.at(playerIndex).MasteryTechno)+"%");
    //ui->lineEdit_skill_calcvalue_specialization->setText(QString::number(Players.at(playerIndex).MasterySpec)+"%");
}

void MainWindow::LoadPlayerSkillsTab(int playerID)
{
    //Loads selected player's data into the "Zdolności" Tab
    //LoadPlayerSpecialization(playerID);
    LoadPlayerMasteries(playerID);
    LoadPlayerSkillsIntoTable(playerID);

}

void MainWindow::LoadPlayerSkillsIntoTable(int playerID)
{
    ClearSkillTable();

    for (int i=0; i<PlayerSkills.size(); i++)
    {
        for (int j=0; j<Skills.size(); j++)
        {

            if (PlayerSkills.at(i).PlayerID == playerID && Skills.at(j).SkillID == PlayerSkills.at(i).SkillID)
            {
                int new_row = ui->tableWidget_skills->rowCount();
                ui->tableWidget_skills->insertRow(new_row);
                ui->tableWidget_skills->setItem(new_row,0,new QTableWidgetItem(Skills.at(j).SkillName));
                ui->tableWidget_skills->setItem(new_row,1,new QTableWidgetItem(Skills.at(j).SkillLevel));
                ui->tableWidget_skills->setItem(new_row,2,new QTableWidgetItem(QString::number(Skills.at(j).Cost))); //QString::number because Cost is an integer
                ui->tableWidget_skills->setItem(new_row,3,new QTableWidgetItem(Skills.at(j).SkillType));

                ui->tableWidget_skills->item(new_row,0)->setTextAlignment(Qt::AlignVCenter);
                ui->tableWidget_skills->item(new_row,1)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_skills->item(new_row,2)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_skills->item(new_row,3)->setTextAlignment(Qt::AlignCenter);

                ui->tableWidget_skills_preview->insertRow(new_row);
                ui->tableWidget_skills_preview->setItem(new_row,0,new QTableWidgetItem(Skills.at(j).SkillName));
                ui->tableWidget_skills_preview->setItem(new_row,1,new QTableWidgetItem(Skills.at(j).SkillLevel));

                ui->tableWidget_skills_preview->item(new_row,0)->setTextAlignment(Qt::AlignVCenter);
                ui->tableWidget_skills_preview->item(new_row,1)->setTextAlignment(Qt::AlignCenter);

            }
        }
    }
}

//Weapon Related
void MainWindow::LoadPlayerWeaponsIntoTable(int playerID)
{
    ClearWeaponTable();

    for (int i=0; i<PlayerWeapons.size(); i++)
    {
        for (int j=0; j<Weapons.size(); j++)
        {

            if (PlayerWeapons.at(i).PlayerID == playerID && Weapons.at(j).WeaponID == PlayerWeapons.at(i).WeaponID)
            {
                int new_row = ui->tableWidget_weapons->rowCount();
                ui->tableWidget_weapons->insertRow(new_row);
                ui->tableWidget_weapons->setItem(new_row,0,new QTableWidgetItem(Weapons.at(j).WeaponName));
                ui->tableWidget_weapons->setItem(new_row,1,new QTableWidgetItem(QString::number(Weapons.at(j).DmgBase)));
                ui->tableWidget_weapons->setItem(new_row,2,new QTableWidgetItem(QString::number(Weapons.at(j).Acc)));
                ui->tableWidget_weapons->setItem(new_row,3,new QTableWidgetItem(QString::number(Weapons.at(j).Recoil)));
                ui->tableWidget_weapons->setItem(new_row,4,new QTableWidgetItem(GetActionCostFromCost(Weapons.at(j).Cost)));
                ui->tableWidget_weapons->setItem(new_row,5,new QTableWidgetItem(Weapons.at(j).WeaponType));
                QString modName1 = GetWpnModNameFromWpnModID(PlayerWeapons.at(i).ModID);
                ui->tableWidget_weapons->setItem(new_row,6,new QTableWidgetItem(modName1));
                QString modName2 = "Brak";
                ui->tableWidget_weapons->setItem(new_row,7,new QTableWidgetItem(modName2));

                ui->tableWidget_weapons->item(new_row,0)->setTextAlignment(Qt::AlignVCenter);
                ui->tableWidget_weapons->item(new_row,1)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_weapons->item(new_row,2)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_weapons->item(new_row,3)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_weapons->item(new_row,4)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_weapons->item(new_row,5)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_weapons->item(new_row,6)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_weapons->item(new_row,7)->setTextAlignment(Qt::AlignCenter);

                ui->tableWidget_weapons_preview->insertRow(new_row);
                ui->tableWidget_weapons_preview->setItem(new_row,0,new QTableWidgetItem(Weapons.at(j).WeaponName));
                ui->tableWidget_weapons_preview->setItem(new_row,1,new QTableWidgetItem(Weapons.at(j).WeaponType));
                ui->tableWidget_weapons_preview->setItem(new_row,2,new QTableWidgetItem(modName1));
                ui->tableWidget_weapons_preview->setItem(new_row,3,new QTableWidgetItem(modName2));

                ui->tableWidget_weapons_preview->item(new_row,0)->setTextAlignment(Qt::AlignVCenter);
                ui->tableWidget_weapons_preview->item(new_row,1)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_weapons_preview->item(new_row,2)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_weapons_preview->item(new_row,3)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
}


void MainWindow::LoadPlayerWeaponsTab(int playerID)
{
    LoadPlayerWeaponsIntoTable(playerID);
    LoadPlayerAmmoIntoTable(playerID);
}

void MainWindow::LoadPlayerAmmoIntoTable(int playerID)
{
    ClearAmmoTable();

    for (int i=0; i<PlayerWeapons.size(); i++)
    {
        for (int j=0; j<Weapons.size(); j++)
        {
            if (PlayerWeapons.at(i).PlayerID == playerID && Weapons.at(j).WeaponID == PlayerWeapons.at(i).WeaponID)
            {
                int AmmoLeft = GetCurrentAmmoInPlayerWeaponFromWeaponID(Weapons.at(j).WeaponID,playerID);
                int new_row = ui->tableWidget_wpn_ammo->rowCount();
                ui->tableWidget_wpn_ammo->insertRow(new_row);
                ui->tableWidget_wpn_ammo->setItem(new_row,0,new QTableWidgetItem(Weapons.at(j).WeaponName));
                ui->tableWidget_wpn_ammo->setItem(new_row,1,new QTableWidgetItem(QString::number(AmmoLeft)));
                ui->tableWidget_wpn_ammo->setItem(new_row,2,new QTableWidgetItem(QString::number(Weapons.at(j).AmmoMaxInClip)));

                ui->tableWidget_wpn_ammo->item(new_row,0)->setTextAlignment(Qt::AlignVCenter);
                ui->tableWidget_wpn_ammo->item(new_row,1)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_wpn_ammo->item(new_row,2)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_wpn_ammo->item(new_row,0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                ui->tableWidget_wpn_ammo->item(new_row,2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            }
        }
    }
}

//Generator Related
void MainWindow::LoadPlayerGeneratorIntoTable(int playerID)
{
    ClearGeneratorTable();

    for (int i=0; i<PlayerGenerators.size(); i++)
    {
        for (int j=0; j<Generators.size(); j++)
        {

            if (PlayerGenerators.at(i).PlayerID == playerID && Generators.at(j).GeneratorID == PlayerGenerators.at(i).GeneratorID)
            {
                int new_row = ui->tableWidget_generators->rowCount();
                ui->tableWidget_generators->insertRow(new_row);
                ui->tableWidget_generators->setItem(new_row,0,new QTableWidgetItem(Generators.at(j).GeneratorName));
                ui->tableWidget_generators->setItem(new_row,1,new QTableWidgetItem(QString::number(Generators.at(j).ShieldPower)));
                ui->tableWidget_generators->setItem(new_row,2,new QTableWidgetItem(QString::number(Generators.at(j).Recharge)));
                ui->tableWidget_generators->setItem(new_row,3,new QTableWidgetItem(Generators.at(j).HasAbility));

                ui->tableWidget_generators_preview->insertRow(new_row);
                ui->tableWidget_generators_preview->setItem(new_row,0,new QTableWidgetItem(Generators.at(j).GeneratorName));
                ui->tableWidget_generators_preview->setItem(new_row,1,new QTableWidgetItem(QString::number(Generators.at(j).ShieldPower)));
                ui->tableWidget_generators_preview->setItem(new_row,2,new QTableWidgetItem(QString::number(Generators.at(j).Recharge)));
                ui->tableWidget_generators_preview->setItem(new_row,3,new QTableWidgetItem(Generators.at(j).HasAbility));

                ui->tableWidget_generators->item(new_row,0)->setTextAlignment(Qt::AlignVCenter);
                ui->tableWidget_generators->item(new_row,1)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_generators->item(new_row,2)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_generators->item(new_row,3)->setTextAlignment(Qt::AlignCenter);

                ui->tableWidget_generators_preview->item(new_row,0)->setTextAlignment(Qt::AlignVCenter);
                ui->tableWidget_generators_preview->item(new_row,1)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_generators_preview->item(new_row,2)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_generators_preview->item(new_row,3)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
}

//Omnikey Related
void MainWindow::LoadPlayerOmnikey(int playerID)
{
    int itemID = 0;
    for (int i=0;i<PlayerOmnikeys.size();i++)
    {
        if(PlayerOmnikeys.at(i).PlayerID == playerID)
            itemID = PlayerOmnikeys.at(i).OmnikeyID;
    }
    ui->comboBox_omnikey_name->setCurrentIndex(itemID);
}

void MainWindow::LoadPlayerOmnikeyMod(int playerID)
{
    int itemID = 0;
    for (int i=0;i<PlayerOmnikeyMods.size();i++)
    {
        if(PlayerOmnikeyMods.at(i).PlayerID == playerID)
            itemID = PlayerOmnikeyMods.at(i).OmnikeyModID;
    }
    ui->comboBox_omnikey_submod_name->setCurrentIndex(itemID);
}

void MainWindow::LoadPlayerOmniblade(int playerID)
{
    int itemID = 0;
    for (int i=0;i<PlayerOmniblades.size();i++)
    {
        if(PlayerOmniblades.at(i).PlayerID == playerID)
            itemID = PlayerOmniblades.at(i).OmnibladeID;
    }
    ui->comboBox_omniblade_type->setCurrentIndex(itemID);
}

void MainWindow::LoadPlayerOmnibladeMod(int playerID)
{
    int itemID = 0;
    for (int i=0;i<PlayerOmnibladeMods.size();i++)
    {
        if(PlayerOmnibladeMods.at(i).PlayerID == playerID)
            itemID = PlayerOmnibladeMods.at(i).OmnibladeModID;
    }
    ui->comboBox_omniblade_mod_name->setCurrentIndex(itemID);
}

void MainWindow::LoadPlayerEquipementTab(int playerID)
{
    LoadPlayerGeneratorIntoTable(playerID);
    LoadGeneratorCharges(playerID);
    LoadPlayerOmnikey(playerID);
    LoadPlayerOmnikeyMod(playerID);
    LoadPlayerOmniblade(playerID);
    LoadPlayerOmnibladeMod(playerID);
}

//Armor related

void MainWindow::LoadPlayerArmorsList(int playerID)
{
    for (int i=0;i<PlayerArmors.size();i++)
    {
        if(PlayerArmors.at(i).PlayerID == playerID)
        {
            QString armorName = GetArmorNameFromArmorID(PlayerArmors.at(i).ArmorID);
            ui->listWidget_armors_list->addItem(armorName);
            ui->listWidget_armors_list_preview->addItem(armorName);
        }
    }
}

void MainWindow::LoadPlayerArmorModsList(int playerID)
{
    for (int i=0;i<PlayerArmorMods.size();i++)
    {
        if(PlayerArmorMods.at(i).PlayerID == playerID)
        {
            QString armorName = GetArmorModNameFromArmorModID(PlayerArmorMods.at(i).ArmorModID);
            ui->listWidget_armormods_list->addItem(armorName);
            ui->listWidget_armormods_list_preview->addItem(armorName);
        }
    }
}

void MainWindow::LoadPlayerArmorsTab(int playerID)
{
    LoadPlayerArmorsList(playerID);
    LoadPlayerArmorModsList(playerID);
}

//Main
void MainWindow::LoadPlayer(int id)
{
LoadPlayerGeneralTab(id);
LoadPlayerSkillsTab(id);
LoadPlayerWeaponsTab(id);
LoadPlayerArmorsTab(id);
LoadPlayerEquipementTab(id);
ui->tabWidget->setCurrentIndex(0);
currentlySelectedPlayerID = GetActivePlayerID();
}

void MainWindow::SavePlayerNotesToVector(int playerID)
{
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
            Players[i].Notes = ui->plainTextEdit->toPlainText();
}

void MainWindow::LoadGeneratorCharges(int playerID)
{
    QString chargesLeft = "0";
    for(int i=0;i<PlayerGenerators.size();i++)
    {
        if(PlayerGenerators.at(i).PlayerID == playerID)
            chargesLeft = QString::number(PlayerGenerators.at(i).ChargesLeft);
    }

    //ui->lineEdit_gen_charges_left->setText(chargesLeft);
}
