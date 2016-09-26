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
    InitializePlayerList();

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

void MainWindow::ClearAllTabs()
{
    ClearGeneralTab();
    ClearSkillTable();
    SetSpecializationToDefault();
    SetMasteriesToZero();
    ClearWeaponTable();
    ClearAmmoTable();
    ClearArmorList();
    ClearArmorModList();
    ClearGeneratorTable();
    SetGeneratorChargesToZero();
    SetOmnikeyToDefault();
    SetOmnikeyModToDefault();
    SetOmnibladeToDefault();
    SetOmnibladeModToDefault();

}

void MainWindow::ClearGeneralTab()
{
    ui->lineEdit_player_name->clear();
    ui->lineEdit_player_class->clear();
    ui->lineEdit_player_race->clear();
    ui->lineEdit_armor_current->clear();
    ui->lineEdit_armor_full->clear();
    ui->lineEdit_shield_current->clear();
    ui->lineEdit_shield_full->clear();
    ui->listWidget_player_conditions->clear();
    ui->comboBox_player_type->setCurrentIndex(0);
}

int MainWindow::GetActivePlayerID()
{
    int currentRow = ui->comboBox_select_player->currentIndex();
    int playerID = PlayersModel->item(currentRow,1)->text().toInt();
    return playerID;
}

int MainWindow::FindLastUsedPlayerID()
{
    int lastID = -1;

    for (int i=0; i<Players.size();i++)
        if(Players.at(i).PlayerID > lastID)
            lastID = Players.at(i).PlayerID;

    return lastID;
}

void MainWindow::AddNewPlayerToVector(QString playerName, int playerID)
{

    C_Player newplayer;
    newplayer.PlayerID = playerID;
    newplayer.PlayerName = playerName;
    newplayer.PlayerRace = "";
    newplayer.PlayerType = "Gracz";
    newplayer.PlayerClass = "";
    newplayer.ArmorCurrent = 500;
    newplayer.ArmorMax = 500;
    newplayer.ShieldCurrent = 200;
    newplayer.ShieldMax = 200;
    newplayer.MasteryBattle = 30;
    newplayer.MasteryBiotic = 30;
    newplayer.MasteryTechno = 30;
    newplayer.MasterySpec = 0;

    Players.append(newplayer);
}

void MainWindow::AddNewPlayerToModel(QString playerName, int playerID)
{
    int newRow = PlayersModel->rowCount();
    PlayersModel->setItem(newRow,0,new QStandardItem(playerName));
    PlayersModel->setItem(newRow,1,new QStandardItem(QString::number(playerID)));
}

void MainWindow::DeletePlayerFromVector(int playerID)
{
    for (int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
            Players.remove(i);
}

void MainWindow::DeletePlayerFromModel(int playerID)
{
    for (int i=0;i<PlayersModel->rowCount();i++)
        if(PlayersModel->item(i,1)->text() == QString::number(playerID))
            PlayersModel->removeRow(i,QModelIndex());
}

void MainWindow::SaveAll()
{
    int playerID = GetActivePlayerID();
    SaveGeneralTab(playerID);
    SaveSkillsTab(playerID);


    ReadWriteData csv;
    if(!csv.WritePlayersFromVectorToFile(Players,"Data/players.csv"))
        qDebug() << "Zapis players.csv nie powiódł się!";
    if(!csv.WritePlayerSkillFromVectorToFile(PlayerSkills, "Data/player_skills.csv"))
        qDebug() << "Zapis player_skills.csv nie powiódł się!";
    if(!csv.WritePlayerWeaponsFromVectorToFile(PlayerWeapons, "Data/player_weapons.csv"))
        qDebug() << "Zapis player_weapons.csv nie powiódł się!";
    if(!csv.WritePlayerArmorsFromVectorToFile(PlayerArmors, "Data/player_armors.csv"))
        qDebug() << "Zapis player_armors.csv nie powiódł się!";
    if(!csv.WritePlayerArmorModsFromVectorToFile(PlayerArmorMods, "Data/player_armormods.csv"))
        qDebug() << "Zapis player_armormods.csv nie powiódł się!";
    if(!csv.WritePlayerGeneratorsFromVectorToFile(PlayerGenerators, "Data/player_generators.csv"))
        qDebug() << "Zapis player_generators.csv nie powiódł się!";
    if(!csv.WritePlayerOmnikeysFromVectorToFile(PlayerOmnikeys, "Data/player_omnikeys.csv"))
        qDebug() << "Zapis player_omnikeys.csv nie powiódł się!";
    if(!csv.WritePlayerOmnikeyModsFromVectorToFile(PlayerOmnikeyMods, "Data/player_omnikeymods.csv"))
        qDebug() << "Zapis player_omnikeymods.csv nie powiódł się!";
    if(!csv.WritePlayerOmnibladesFromVectorToFile(PlayerOmniblades, "Data/player_omniblades.csv"))
        qDebug() << "Zapis player_omniblades.csv nie powiódł się!";
    if(!csv.WritePlayerOmnibladeModsFromVectorToFile(PlayerOmnibladeMods, "Data/player_omniblademods.csv"))
        qDebug() << "Zapis player_omniblademods.csv nie powiódł się!";
    if(!csv.WritePlayerActiveEffectsFromVectorToFile(PlayerActiveEffects, "Data/player_activeeffects.csv"))
        qDebug() << "Zapis player_activeeffects.csv nie powiódł się!";

    ui->statusBar->showMessage("Zapis zakończony!", 3000);
}

//SLOTS

void MainWindow::on_pushButton_skill_add_clicked()
{
    if(!ui->treeWidget_skill_list->selectedItems().isEmpty())
    {
        int playerID = GetActivePlayerID();;
        int skillID = GetSkillIDFromSkillNameAndLevel(ui->treeWidget_skill_list->currentItem()->text(0),ui->comboBox_skill_level->currentText());
        AddSkillToTable();
        AddSkillToPlayer(skillID, playerID);
    }

}

void MainWindow::on_pushButton_skill_remove_clicked()
{
    if(!ui->tableWidget_skills->selectedItems().isEmpty())
    {
        int playerID = GetActivePlayerID();;
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
    SaveSkillsTabToVector(GetActivePlayerID());
    CalculatePlayerMasteries(GetActivePlayerID());
    LoadPlayerMasteries(GetActivePlayerID());
    LoadPlayerSpecialization(GetActivePlayerID());
}

void MainWindow::on_comboBox_specialization_activated(const QString selectedItem)
{
    int playerIndex = GetPlayerIndex(GetActivePlayerID());

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
    SaveAll();
}

void MainWindow::on_pushButton_weapon_add_clicked()
{
    if(!ui->treeWidget_weapon_list->selectedItems().isEmpty())
    {
        int playerID = GetActivePlayerID();;
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
        int playerID = GetActivePlayerID();;
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
        int playerID = GetActivePlayerID();;
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
        int playerID = GetActivePlayerID();;
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
        int playerID = GetActivePlayerID();;
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
        int playerID = GetActivePlayerID();;
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
        int playerID = GetActivePlayerID();;
        int armorModID;
        QString armorModName = ui->listWidget_armormods_list->item(ui->listWidget_armormods_list->currentRow())->text();

        armorModID = GetArmorModIDFromArmorModName(armorModName);
        RemoveArmorModFromList();
        RemoveArmorModFromPlayer(armorModID, playerID);
    }
}

void MainWindow::on_pushButton_generator_add_clicked()
{
        int playerID = GetActivePlayerID();;
        int generatorID = GetGeneratorIDFromGeneratorName(ui->comboBox_generator_name->currentText());

        if(ui->tableWidget_generators->rowCount()<1)
        {
            AddGeneratorToTable();
            AddGeneratorToPlayer(generatorID,playerID);
            ui->lineEdit_gen_charges_left->setText(ui->tableWidget_generators->item(0,2)->text());
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
        int playerID = GetActivePlayerID();;
        int generatorID;
        QString generatorName = ui->tableWidget_generators->item(ui->tableWidget_generators->currentRow(),0)->text();

        generatorID = GetGeneratorIDFromGeneratorName(generatorName);
        RemoveGeneratorFromTable();
        RemoveGeneratorFromPlayer(generatorID, playerID);
    }
}

void MainWindow::on_comboBox_omnikey_name_activated(const QString &arg1)
{
    int playerID = GetActivePlayerID();;
    RemoveOmnikeyFromPlayer(playerID);
    int omnikeyID = GetOmnikeyIDFromOmnikeyName(arg1);
    AddOmnikeyToPlayer(omnikeyID, playerID);
}

void MainWindow::on_comboBox_omnikey_submod_name_activated(const QString &arg1)
{
    int playerID = GetActivePlayerID();;
    RemoveOmnikeyModFromPlayer(playerID);
    int omnikeyID = GetOmnikeyModIDFromOmnikeyModName(arg1);
    AddOmnikeyModToPlayer(omnikeyID, playerID);
}

void MainWindow::on_comboBox_omniblade_type_activated(const QString &arg1)
{
    int playerID = GetActivePlayerID();;
    RemoveOmnibladeFromPlayer(playerID);
    int omnibladeID = GetOmnibladeIDFromOmnibladeName(arg1);
    AddOmnibladeToPlayer(omnibladeID, playerID);
}

void MainWindow::on_comboBox_omniblade_mod_name_activated(const QString &arg1)
{
    int playerID = GetActivePlayerID();;
    RemoveOmnibladeModFromPlayer(playerID);
    int omnibladeID = GetOmnibladeModIDFromOmnibladeModName(arg1);
    AddOmnibladeModToPlayer(omnibladeID, playerID);

}

void MainWindow::on_lineEdit_gen_charges_left_textEdited(const QString &arg1)
{
    int playerID = GetActivePlayerID();;
    int charges = arg1.toInt();
    for(int i=0;i<PlayerGenerators.size();i++)
    {
        if(PlayerGenerators.at(i).PlayerID == playerID)
            PlayerGenerators[i].ChargesLeft = charges;
    }
}

void MainWindow::on_pushButton_reloadAll_clicked()
{
    int playerID = GetActivePlayerID();;
    ReloadAll(playerID);
}

void MainWindow::on_treeWidget_weapon_list_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    on_pushButton_weapon_add_clicked();
}

void MainWindow::on_pushButton_add_activeEffect_clicked()
{
    int playerID = GetActivePlayerID();;
    DialogBox_ActiveEffect *box = new DialogBox_ActiveEffect;
    box->setAttribute(Qt::WA_DeleteOnClose);
    box->AddEffectsToRightList(ActiveEffect);
    box->AddEffectsToLeftList(ActiveEffect,PlayerActiveEffects,playerID);
    connect(box,SIGNAL(sendActiveEffectList(QStringList)),this,SLOT(addActiveEffectsToWidgetList(QStringList)));
    box->show();
}

void MainWindow::on_tableWidget_wpn_ammo_cellChanged(int row, int column)
{
    //Change AmmoLeft to new value in player_weapons vector
    if(column == 1)
    {
        int playerID = GetActivePlayerID();

        QString newAmmoLeft = ui->tableWidget_wpn_ammo->item(row, column)->text();

        QString affectedWeaponName = ui->tableWidget_wpn_ammo->item(row,0)->text();
        int affectedWeaponID = GetWeaponIDFromWeaponName(affectedWeaponName);

        for(int i=0;i<PlayerWeapons.size();i++)
            if(PlayerWeapons.at(i).PlayerID == playerID && PlayerWeapons.at(i).WeaponID == affectedWeaponID)
            {
                PlayerWeapons[i].AmmoLeft = newAmmoLeft.toInt();
            }
    }

}


void MainWindow::on_comboBox_select_player_activated(const QString &arg1)
{
    ClearAllTabs();
    int playerID = GetActivePlayerID();
    LoadPlayer(playerID);
    ui->tabWidget->setCurrentIndex(0);

}


void MainWindow::on_lineEdit_player_name_textEdited(const QString &arg1)
{
    int currentRow = ui->comboBox_select_player->currentIndex();
    PlayersModel->item(currentRow,0)->setText(arg1);

    int playerID = GetActivePlayerID();
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
            Players[i].PlayerName = arg1;
}

void MainWindow::on_pushButton_addNewPlayer_clicked()
{
    int newID = FindLastUsedPlayerID() + 1;
    AddNewPlayerToVector("Nowy gracz", newID);
    AddNewPlayerToModel("Nowy gracz", newID);
    ui->comboBox_select_player->setCurrentIndex(ui->comboBox_select_player->count()-1);
    ClearAllTabs();
    LoadPlayer(newID);
}

void MainWindow::on_pushButton_deletePlayer_clicked()
{
    int playerID = GetActivePlayerID();
    if(ui->comboBox_select_player->count() > 1)
    {
        DeletePlayerFromVector(playerID);
        DeletePlayerFromModel(playerID);
        ui->comboBox_select_player->setCurrentIndex(0);
        LoadPlayer(Players.at(0).PlayerID);
    }
}

void MainWindow::on_actionOmni_Kalkulator_triggered()
{

    dialogbox_save_module *box = new dialogbox_save_module;
    box->setAttribute(Qt::WA_DeleteOnClose);
    connect(box,SIGNAL(SaveSignal(bool)),this,SLOT(CalculatorModuleSlot(bool)));
    box->show();
}

void MainWindow::CalculatorModuleSlot(bool savesignal)
{
    if(savesignal)
    {
        SaveAll();
        OpenCalculatorModule();
    }
}

void MainWindow::OpenCalculatorModule()
{
    calculator *calcModule = new calculator;
    calcModule->setAttribute(Qt::WA_DeleteOnClose);
    calcModule->show();
}
