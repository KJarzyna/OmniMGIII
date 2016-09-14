#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialogbox_activeeffect.h"

void MainWindow::InitializeWeaponTableSize()
{
    ui->tableWidget_weapons->setColumnWidth(0,200);
    ui->tableWidget_weapons->setColumnWidth(1,80);
    ui->tableWidget_weapons->setColumnWidth(2,80);
    ui->tableWidget_weapons->setColumnWidth(3,100);
    ui->tableWidget_weapons->setColumnWidth(4,60);
    ui->tableWidget_weapons->setColumnWidth(5,90);
    ui->tableWidget_weapons->setColumnWidth(6,70);
    ui->tableWidget_weapons->setColumnWidth(7,160);
    ui->tableWidget_weapons->horizontalHeader()->setStretchLastSection(true);

}

void MainWindow::InitializeSkillTableSize()
{
    ui->tableWidget_skills->setColumnWidth(0,200);
    ui->tableWidget_skills->setColumnWidth(1,80);
    ui->tableWidget_skills->setColumnWidth(2,80);
    ui->tableWidget_skills->setColumnWidth(3,120);
    ui->tableWidget_skills->horizontalHeader()->setStretchLastSection(true);

}

void MainWindow::InitializeGeneratorTableSize()
{
    ui->tableWidget_generators->setColumnWidth(0,200);
    ui->tableWidget_generators->setColumnWidth(1,80);
    ui->tableWidget_generators->setColumnWidth(2,120);
    ui->tableWidget_generators->setColumnWidth(3,140);
    ui->tableWidget_generators->setColumnWidth(4,160);
    ui->tableWidget_generators->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_generators->verticalHeader()->setStretchLastSection(true);
}

void MainWindow::InitializeSkillListTreeWidget()
{
    //Fill up TreeWidget_skill_list with list of available skills from SkillList vector

    QTreeWidget *tree = ui->treeWidget_skill_list;

    for(int i=0; i<SkillList.size(); i++)
    {
        if (SkillList.at(i).SkillType == "Biotyczne")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_skill_list->topLevelItem(0);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,SkillList.at(i).SkillName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (SkillList.at(i).SkillType == "Bojowe")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_skill_list->topLevelItem(1);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,SkillList.at(i).SkillName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (SkillList.at(i).SkillType == "Technologiczne")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_skill_list->topLevelItem(2);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,SkillList.at(i).SkillName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (SkillList.at(i).SkillType == "Klasowe")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_skill_list->topLevelItem(3);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,SkillList.at(i).SkillName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (SkillList.at(i).SkillType == "Amunicja")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_skill_list->topLevelItem(4);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,SkillList.at(i).SkillName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }

    }

}

void MainWindow::InitializeSkillListSpecialization()
{
    for (int i=0; i<SkillList.size(); i++)
    {
        ui->comboBox_specialization->addItem(SkillList.at(i).SkillName);
    }
}

void MainWindow::InitializeWeaponListTreeWidget()
{
    //Fill up TreeWidget_weapon_list with list of available weapons from Weapons vector

    QTreeWidget *tree = ui->treeWidget_weapon_list;

    for(int i=0; i<WeaponList.size(); i++)
    {
        if (WeaponList.at(i).WeaponType == "PC")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_weapon_list->topLevelItem(0);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,WeaponList.at(i).WeaponName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (WeaponList.at(i).WeaponType == "PM")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_weapon_list->topLevelItem(1);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,WeaponList.at(i).WeaponName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (WeaponList.at(i).WeaponType == "KS")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_weapon_list->topLevelItem(2);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,WeaponList.at(i).WeaponName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (WeaponList.at(i).WeaponType == "KW")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_weapon_list->topLevelItem(3);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,WeaponList.at(i).WeaponName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (WeaponList.at(i).WeaponType == "STRZ")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_weapon_list->topLevelItem(4);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,WeaponList.at(i).WeaponName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
    }
}

void MainWindow::InitializeWpnModListTreeWidget()
{
    //Fill up TreeWidget_wpnmod_list with list of available mods from WpnModList vector

    QTreeWidget *tree = ui->treeWidget_wpnmod_list;

    for(int i=0; i<WpnModList.size(); i++)
    {
        if (WpnModList.at(i).ModType.contains("PC"))
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_wpnmod_list->topLevelItem(0);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,WpnModList.at(i).ModName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        if (WpnModList.at(i).ModType.contains("PM"))
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_wpnmod_list->topLevelItem(1);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,WpnModList.at(i).ModName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        if (WpnModList.at(i).ModType.contains("KS"))
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_wpnmod_list->topLevelItem(2);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,WpnModList.at(i).ModName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        if (WpnModList.at(i).ModType.contains("KW"))
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_wpnmod_list->topLevelItem(3);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,WpnModList.at(i).ModName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        if (WpnModList.at(i).ModType.contains("STRZ"))
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_wpnmod_list->topLevelItem(4);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,WpnModList.at(i).ModName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }

    }

}

void MainWindow::InitializeArmorListTreeWidget()
{
    //Fill up TreeWidget_armor_list with list of available armors from armors vector

    QTreeWidget *tree = ui->treeWidget_armor_list;

    for(int i=0; i<ArmorList.size(); i++)
    {
        if (ArmorList.at(i).ArmorType == "H")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_armor_list->topLevelItem(0);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,ArmorList.at(i).ArmorName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (ArmorList.at(i).ArmorType == "NAP")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_armor_list->topLevelItem(1);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,ArmorList.at(i).ArmorName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (ArmorList.at(i).ArmorType == "NAR")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_armor_list->topLevelItem(2);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,ArmorList.at(i).ArmorName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (ArmorList.at(i).ArmorType == "NAG")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_armor_list->topLevelItem(3);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,ArmorList.at(i).ArmorName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (ArmorList.at(i).ArmorType == "R")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_armor_list->topLevelItem(4);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,ArmorList.at(i).ArmorName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
        else if (ArmorList.at(i).ArmorType == "SPEC")
        {
            QTreeWidgetItem *topLevel = ui->treeWidget_armor_list->topLevelItem(5);
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,ArmorList.at(i).ArmorName);
            topLevel->addChild(item);
            tree->addTopLevelItem(topLevel);
        }
    }
}

void MainWindow::InitializeArmorModList()
{
    for (int i=0; i<ArmModList.size(); i++)
    {
        ui->comboBox_mod_armor_name->addItem(ArmModList.at(i).ArmorModName);
    }
}

void MainWindow::InitializeGeneratorList()
{
    for (int i=0; i<Generators.size(); i++)
    {
        ui->comboBox_generator_name->addItem(Generators.at(i).GeneratorName);
    }
}

void MainWindow::InitializeOmnikeyList()
{
    for (int i=0; i<Omnikeys.size(); i++)
    {
        ui->comboBox_omnikey_name->addItem(Omnikeys.at(i).Name);
    }
}

void MainWindow::InitializeOmnikeyModsList()
{
    for (int i=0; i<OmnikeyMods.size(); i++)
    {
        ui->comboBox_omnikey_submod_name->addItem(OmnikeyMods.at(i).Name);
    }
}

void MainWindow::InitializeOmnibladesList()
{
    for (int i=0; i<Omniblades.size(); i++)
    {
        ui->comboBox_omniblade_type->addItem(Omniblades.at(i).Name);
    }
}

void MainWindow::InitializeOmnibladeModsList()
{
    for (int i=0; i<OmnibladeMods.size(); i++)
    {
        ui->comboBox_omniblade_mod_name->addItem(OmnibladeMods.at(i).Name);
    }
}

void MainWindow::InitializeAmmoLeftList()
{
    ui->tableWidget_wpn_ammo->setColumnWidth(0,180);
    ui->tableWidget_wpn_ammo->setColumnWidth(1,80);
    ui->tableWidget_wpn_ammo->horizontalHeaderItem(1)->setText("Pozostało \n amunicji");
    ui->tableWidget_wpn_ammo->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::InitializePlayerList()
{
    for (int i=0; i<Players.size();i++)
        ui->comboBox_select_player->addItem(Players.at(i).PlayerName);
}
