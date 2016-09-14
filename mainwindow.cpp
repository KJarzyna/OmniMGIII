#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>

#include "mainwindow-initialization.cpp"
#include "mainwindow-loading.cpp"
#include "mainwindow-saving.cpp"
#include "mainwindow-skills.cpp"
#include "mainwindow-weapons.cpp"
#include "mainwindow-armors.cpp"
#include "mainwindow-generators.cpp"
#include "mainwindow-omnikeys.cpp"
#include "mainwindow-effects.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ReadDataFromFiles();

    InitializeWeaponTableSize();
    InitializeSkillTableSize();
    InitializeGeneratorTableSize();
    InitializeSkillListTreeWidget();
    InitializeSkillListSpecialization();
    InitializeWeaponListTreeWidget();
    InitializeWpnModListTreeWidget();
    InitializeArmorListTreeWidget();
    InitializeArmorModList();
    InitializeGeneratorList();
    InitializeOmnikeyList();
    InitializeOmnikeyModsList();
    InitializeOmnibladesList();
    InitializeOmnibladeModsList();
    InitializeAmmoLeftList();

    LoadPlayer(0);

    CalculatePlayerMasteries(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//General
int MainWindow::GetPlayerIndex(int playerID)
{
    int playerIndex = 9999;
    for (int i=0;i<Players.size(); i++)
    {
        if(Players.at(i).PlayerID == playerID) playerIndex = i;
    }
    return playerIndex;
}

bool MainWindow::ReadDataFromFiles()
{
    ReadWriteData csv;
    csv.ReadPlayersFromFileAndLoadToVector("Data/players.csv", Players);
    csv.ReadSkillsFromFileAndLoadToVector("Data/skills.csv", Skills);
    csv.ReadSkillListFromFileAndLoadToVector("Data/skills_baselist.csv", SkillList);
    csv.ReadPlayerSkillFromFileAndLoadToVector("Data/player_skills.csv", PlayerSkills);
    csv.ReadWeaponListFromFileAndLoadToVector("Data/weapons_baselist.csv", WeaponList);
    csv.ReadWeaponsFromFileAndLoadToVector("Data/weapons.csv", Weapons);
    csv.ReadPlayerWeaponsFromFileAndLoadToVector("Data/player_weapons.csv", PlayerWeapons);
    csv.ReadWpnModListFromFileAndLoadToVector("Data/wpnmods_baselist.csv", WpnModList);
    csv.ReadArmorListFromFileAndLoadToVector("Data/armors_baselist.csv", ArmorList);
    csv.ReadArmorsFromFileAndLoadToVector("Data/armors.csv", Armors);
    csv.ReadPlayerArmorsFromFileAndLoadToVector("Data/player_armors.csv", PlayerArmors);
    csv.ReadArmorModListFromFileAndLoadToVector("Data/armmods_baselist.csv", ArmModList);
    csv.ReadPlayerArmorModsFromFileAndLoadToVector("Data/player_armormods.csv", PlayerArmorMods);
    csv.ReadGeneratorsFromFileAndLoadToVector("Data/generators.csv", Generators);
    csv.ReadPlayerGeneratorsFromFileAndLoadToVector("Data/player_generators.csv", PlayerGenerators);
    csv.ReadOmnikeysFromFileAndLoadToVector("Data/omnikeys.csv", Omnikeys);
    csv.ReadPlayerOmnikeysFromFileAndLoadToVector("Data/player_omnikeys.csv", PlayerOmnikeys);
    csv.ReadOmnikeyModsFromFileAndLoadToVector("Data/omnikeymods.csv", OmnikeyMods);
    csv.ReadPlayerOmnikeyModsFromFileAndLoadToVector("Data/player_omnikeymods.csv", PlayerOmnikeyMods);
    csv.ReadOmnibladesFromFileAndLoadToVector("Data/omniblades.csv", Omniblades);
    csv.ReadPlayerOmnibladesFromFileAndLoadToVector("Data/player_omniblades.csv", PlayerOmniblades);
    csv.ReadOmnibladeModsFromFileAndLoadToVector("Data/omniblademods.csv", OmnibladeMods);
    csv.ReadPlayerOmnibladeModsFromFileAndLoadToVector("Data/player_omniblademods.csv", PlayerOmnibladeMods);
    csv.ReadActiveEffectsFromFileAndLoadToVector("Data/activeeffects.csv", ActiveEffect);
    csv.ReadPlayerActiveEffectsFromFileAndLoadToVector("Data/player_activeeffects.csv", PlayerActiveEffects);
    return true;
}

QString MainWindow::GetActionCostFromCost(int cost)
{
    if (cost <3)
        return "AM";
    else if (cost == 50)
        return "AM+AD";
    else
        return "AD";
}

//SLOTS

void MainWindow::on_pushButton_skill_add_clicked()
{
    if(!ui->treeWidget_skill_list->selectedItems().isEmpty())
    {
        int playerID = 0;
        int skillID = GetSkillIDFromSkillNameAndLevel(ui->treeWidget_skill_list->currentItem()->text(0),ui->comboBox_skill_level->currentText());
        AddSkillToTable();
        AddSkillToPlayer(skillID, playerID);
    }

}

void MainWindow::on_pushButton_skill_remove_clicked()
{
    if(!ui->tableWidget_skills->selectedItems().isEmpty())
    {
        int playerID = 0;
        int skillID;
        QString skillName = ui->tableWidget_skills->item(ui->tableWidget_skills->currentRow(),0)->text();
        QString skillLevel = ui->tableWidget_skills->item(ui->tableWidget_skills->currentRow(),1)->text();
        skillID = GetSkillIDFromSkillNameAndLevel(skillName,skillLevel);

        RemoveSkillFromTable();
        RemoveSkillFromPlayer(skillID,playerID);
    }

}

void MainWindow::on_pushButton_calculate_skills_clicked()
{
    SaveSkillsTabToVector(0);
    CalculatePlayerMasteries(0);
    LoadPlayerMasteries(0);
    LoadPlayerSpecialization(0);
}

void MainWindow::on_comboBox_specialization_activated(const QString selectedItem)
{
    int playerIndex = GetPlayerIndex(0);

    if(PlayerHasSkill(playerIndex,selectedItem))
        Players[playerIndex].SpecializationSkill = selectedItem;
    else
    {
        ui->comboBox_specialization->setCurrentIndex(0);
        QMessageBox msgbox;
        msgbox.setText("Nie posiadasz tej zdolności!");
        msgbox.exec();
    }

}

void MainWindow::on_actionZapisz_triggered()
{
    int playerID = 0;
    SaveGeneralTab(playerID);
    SaveSkillsTab(playerID);

    ReadWriteData csv;
    csv.WritePlayersFromVectorToFile(Players,"Data/players.csv");
    csv.WritePlayerSkillFromVectorToFile(PlayerSkills, "Data/player_skills.csv");
    csv.WritePlayerWeaponsFromVectorToFile(PlayerWeapons, "Data/player_weapons.csv");
}

void MainWindow::on_pushButton_weapon_add_clicked()
{
    if(!ui->treeWidget_weapon_list->selectedItems().isEmpty())
    {
        int playerID = 0;
        int weaponID = GetWeaponIDFromWeaponName(ui->treeWidget_weapon_list->currentItem()->text(0));
        AddWeaponToTable();
        AddWeaponToAmmoTable();
        AddWeaponToPlayer(weaponID,playerID);
    }
}

void MainWindow::on_pushButton_weapon_remove_clicked()
{
    if(!ui->tableWidget_weapons->selectedItems().isEmpty())
    {
        int playerID = 0;
        int weaponID;
        QString weaponName = ui->tableWidget_weapons->item(ui->tableWidget_weapons->currentRow(),0)->text();

        weaponID = GetWeaponIDFromWeaponName(weaponName);
        RemoveWeaponFromAmmoTable();
        RemoveWeaponFromTable();
        RemoveWeaponFromPlayer(weaponID, playerID);
    }
}

void MainWindow::on_pushButton_mod_add_clicked()
{
    if(!ui->treeWidget_wpnmod_list->selectedItems().isEmpty() && !ui->tableWidget_weapons->selectedItems().isEmpty())
    {
        int playerID = 0;
        int selected_row = ui->tableWidget_weapons->currentRow();
        QString selected_weapon_name = ui->tableWidget_weapons->item(selected_row,0)->text();
        QString selected_mod_name = ui->treeWidget_wpnmod_list->currentItem()->text(0);
        int weaponID = GetWeaponIDFromWeaponName(selected_weapon_name);
        int weaponModID = GetWpnModIDFromWpnModName(selected_mod_name);

        if(isModTypeGoodWithWpnType(weaponModID,weaponID))
        {
            AddWpnModToTable();
            AddWpnModToPlayer(weaponModID, weaponID, playerID);
        }
        else
        {
            QMessageBox msgbox;
            msgbox.setText("Ten mod nie pasuje do tej broni!");
            msgbox.exec();
        }
    }
}

void MainWindow::on_pushButton_mod_remove_clicked()
{
    if(!ui->tableWidget_weapons->selectedItems().isEmpty())
        RemoveWpnModFromTable();
}

void MainWindow::on_pushButton_armor_add_clicked()
{
    if(!ui->treeWidget_armor_list->selectedItems().isEmpty())
    {
        int playerID = 0;
        int armorID = GetArmorIDFromArmorName(ui->treeWidget_armor_list->currentItem()->text(0));
        if(!PlayerHasArmor(playerID, armorID))
        {
            AddArmorToList();
            AddArmorToPlayer(armorID,playerID);
        }
        else
        {
            QMessageBox msgbox;
            msgbox.setText("Gracz już posiada ten element pancerza!");
            msgbox.exec();
        }

    }
}

void MainWindow::on_pushButton_armor_remove_clicked()
{
    if(!ui->listWidget_armors_list->selectedItems().isEmpty())
    {
        int playerID = 0;
        int armorID;
        QString armorName = ui->listWidget_armors_list->item(ui->listWidget_armors_list->currentRow())->text();

        armorID = GetArmorIDFromArmorName(armorName);
        RemoveArmorFromList();
        RemoveArmorFromPlayer(armorID, playerID);
    }
}

void MainWindow::on_pushButton_mod_armor_add_clicked()
{
    if(ui->comboBox_mod_armor_name->currentText() != "Brak")
    {
        int playerID = 0;
        int armorModID = GetArmorModIDFromArmorModName(ui->comboBox_mod_armor_name->currentText());
        if (ui->listWidget_armormods_list->count() >= 2)
        {
            QMessageBox msgbox;
            msgbox.setText("Maksymalna liczba modyfikacji pancerza osiągnięta!");
            msgbox.exec();
        }
        else if(!PlayerHasArmorMod(playerID, armorModID))
        {
            AddArmorModToList();
            AddArmorModToPlayer(armorModID,playerID);
        }
        else
        {
            QMessageBox msgbox;
            msgbox.setText("Gracz już posiada tą modyfikację pancerza!");
            msgbox.exec();
        }

    }
}

void MainWindow::on_pushButton_mod_armor_remove_clicked()
{
    if(!ui->listWidget_armormods_list->selectedItems().isEmpty())
    {
        int playerID = 0;
        int armorModID;
        QString armorModName = ui->listWidget_armormods_list->item(ui->listWidget_armormods_list->currentRow())->text();

        armorModID = GetArmorModIDFromArmorModName(armorModName);
        RemoveArmorModFromList();
        RemoveArmorModFromPlayer(armorModID, playerID);
    }
}

void MainWindow::on_pushButton_generator_add_clicked()
{
        int playerID = 0;
        int generatorID = GetGeneratorIDFromGeneratorName(ui->comboBox_generator_name->currentText());

        if(ui->tableWidget_generators->rowCount()<1)
        {
            AddGeneratorToTable();
            AddGeneratorToPlayer(generatorID,playerID);
        }
        else
        {
            QMessageBox msgbox;
            msgbox.setText("Gracz już posiada maksymalną liczbę generatorów!");
            msgbox.exec();
        }
}

void MainWindow::on_pushButton_generator_remove_clicked()
{
    if(!ui->tableWidget_generators->selectedItems().isEmpty())
    {
        int playerID = 0;
        int generatorID;
        QString generatorName = ui->tableWidget_generators->item(ui->tableWidget_generators->currentRow(),0)->text();

        generatorID = GetGeneratorIDFromGeneratorName(generatorName);
        RemoveGeneratorFromTable();
        RemoveGeneratorFromPlayer(generatorID, playerID);
    }
}

void MainWindow::on_comboBox_omnikey_name_activated(const QString &arg1)
{
    int playerID = 0;
    RemoveOmnikeyFromPlayer(playerID);
    int omnikeyID = GetOmnikeyIDFromOmnikeyName(arg1);
    AddOmnikeyToPlayer(omnikeyID, playerID);
}

void MainWindow::on_comboBox_omnikey_submod_name_activated(const QString &arg1)
{
    int playerID = 0;
    RemoveOmnikeyModFromPlayer(playerID);
    int omnikeyID = GetOmnikeyModIDFromOmnikeyModName(arg1);
    AddOmnikeyModToPlayer(omnikeyID, playerID);
}

void MainWindow::on_comboBox_omniblade_type_activated(const QString &arg1)
{
    int playerID = 0;
    RemoveOmnibladeFromPlayer(playerID);
    int omnibladeID = GetOmnibladeIDFromOmnibladeName(arg1);
    AddOmnibladeToPlayer(omnibladeID, playerID);
}

void MainWindow::on_comboBox_omniblade_mod_name_activated(const QString &arg1)
{
    int playerID = 0;
    RemoveOmnibladeModFromPlayer(playerID);
    int omnibladeID = GetOmnibladeModIDFromOmnibladeModName(arg1);
    AddOmnibladeModToPlayer(omnibladeID, playerID);

}

void MainWindow::on_lineEdit_gen_charges_left_textEdited(const QString &arg1)
{
    int playerID = 0;
    int charges = arg1.toInt();
    for(int i=0;i<PlayerGenerators.size();i++)
    {
        if(PlayerGenerators.at(i).PlayerID == playerID)
            PlayerGenerators[i].ChargesLeft = charges;
    }
}

void MainWindow::on_pushButton_reloadAll_clicked()
{
    int playerID = 0;
    ReloadAll(playerID);
}

void MainWindow::on_treeWidget_weapon_list_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    on_pushButton_weapon_add_clicked();
}

void MainWindow::on_pushButton_add_activeEffect_clicked()
{
    int playerID = 0;
    DialogBox_ActiveEffect *box = new DialogBox_ActiveEffect;
    box->setAttribute(Qt::WA_DeleteOnClose);
    box->AddEffectsToRightList(ActiveEffect);
    box->AddEffectsToLeftList(ActiveEffect,PlayerActiveEffects,playerID);
    connect(box,SIGNAL(sendActiveEffectList(QStringList)),this,SLOT(addActiveEffectsToWidgetList(QStringList)));
    box->show();
}


