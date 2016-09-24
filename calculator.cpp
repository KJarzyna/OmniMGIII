#include "calculator.h"
#include "ui_calculator.h"
#include "calculator-actions.cpp"
#include "calculator-weapons.cpp"
#include "calculator-skills.cpp"
#include "calculator-player.cpp"
#include "QDebug"

calculator::calculator(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::calculator)
{
    ui->setupUi(this);
    InitializeAccModTable();
    InitializeDmgModTable();
    ReadDataFromFiles();
    InitializePlayersComboBox();
    InitializeActionsComboBox();
    InitializeTargetsComboBox();
    InitializePlayerStats();

}

calculator::~calculator()
{
    delete ui;
}

//INITIALIZATION
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
    for (int i=0; i<Actions.size();i++)
    {
        comboboxActionModel->setItem(i,0,new QStandardItem(Actions.at(i).Name));
        comboboxActionModel->setItem(i,1,new QStandardItem(QString::number(Actions.at(i).ID)));
        comboboxActionModel->setItem(i,2,new QStandardItem(QString::number(Actions.at(i).Cost)));
    }
    ui->comboBox_select_action->setModel(comboboxActionModel);
}

void calculator::InitializeTargetsComboBox()
{
    comboboxTargetsModel = new QStandardItemModel(Players.size(),2,this);
    for (int i=0; i<Players.size();i++)
    {
        comboboxTargetsModel->setItem(i,0,new QStandardItem(Players.at(i).PlayerName));
        comboboxTargetsModel->setItem(i,1,new QStandardItem(QString::number(Players.at(i).PlayerID)));
    }
    comboboxTargetsModel->removeRow(0,QModelIndex());
    ui->comboBox_select_target->setModel(comboboxTargetsModel);

    selectedTargetID = comboboxTargetsModel->item(0,1)->text().toInt();
    selectedTargetName = comboboxTargetsModel->item(0,0)->text();
}

void calculator::InitializePlayerStats()
{
    int playerID = comboboxPlayersModel->item(0,1)->text().toInt();
    setPlayerStats(playerID);
    setPlayerActiveEffects(playerID);
}

//METHODS
bool calculator::ReadDataFromFiles()
{
    ReadWriteData csv;
    csv.ReadPlayersFromFileAndLoadToVector("Data/players.csv", Players);
    csv.ReadSkillsFromFileAndLoadToVector("Data/skills.csv", Skills);
    csv.ReadPlayerSkillFromFileAndLoadToVector("Data/player_skills.csv", PlayerSkills);
    csv.ReadWeaponsFromFileAndLoadToVector("Data/weapons.csv", Weapons);
    csv.ReadPlayerWeaponsFromFileAndLoadToVector("Data/player_weapons.csv", PlayerWeapons);
    csv.ReadWpnModListFromFileAndLoadToVector("Data/wpnmods_baselist.csv", WpnModList);
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
    csv.ReadActionsFromFileAndLoadToVector("Data/actions.csv", Actions);
    return true;
}

QString calculator::GetEffectNameFromEffectID(int ID)
{
    QString name = "NoName";
    for(int i=0;i<ActiveEffect.size();i++)
    {
        if(ActiveEffect.at(i).ID == ID)
            name = ActiveEffect.at(i).Name;
    }
    return name;
}

QStandardItemModel* calculator::GetItemModelBasedOnSelectedAction(int actionID)
{

    switch(actionID)
    {
    case 0:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("PC");
        return model;
        break;
    }
    case 1:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("PM");
        return model;
        break;
    }
    case 2:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("KS");
        return model;
        break;
    }
    case 3:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("KW");
        return model;
        break;
    }
    case 4:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("Strz");
        return model;
        break;
    }
    case 5:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerWeapons();
        return model;
        break;
    }
    case 6:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerGenerators();
        return model;
        break;
    }
    case 7:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerSkills();
        return model;
        break;
    }
    case 8:
    {
        QStandardItemModel *model = GetItemModelForGelUsage();
        return model;
        break;
    }
    case 9:
    {
        QStandardItemModel *model = GetItemModelForGelUsage();
        return model;
        break;
    }
    case 13:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerWeapons();
        return model;
        break;
    }
    case 14:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerWeapons();
        return model;
        break;
    }
    case 17:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerGenerators();
        return model;
        break;
    }
    case 18:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerSkills();
        return model;
        break;
    }
    case 19:
    {
        QStandardItemModel *model = GetItemModelForSpecialAmmo();
        return model;
        break;
    }
    default:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("IntentionallyWrongType"); //returns empty model
        return model;
        break;
    }

    }

}

QStandardItemModel* calculator::GetItemModelForWeaponType(QString weaponType)
{
    QVector<QString> itemNameVector;
    QVector<int> itemIDVector;
    QStandardItemModel *empty_model = new QStandardItemModel(1,2,this);
    empty_model->setItem(0,0, new QStandardItem("Brak")); //model returned if player don't have any items
    empty_model->setItem(0,1, new QStandardItem("-1")); //model returned if player don't have any items

    for(int i=0;i<PlayerWeapons.size();i++)
        if(PlayerWeapons.at(i).PlayerID == selectedPlayerID && GetWeaponTypeFromWeaponID(PlayerWeapons.at(i).WeaponID) == weaponType)
        {
            itemNameVector.append(GetWeaponNameFromWeaponID(PlayerWeapons.at(i).WeaponID));
            itemIDVector.append(PlayerWeapons.at(i).WeaponID);
        }
    if(!itemNameVector.isEmpty())
    {
        QStandardItemModel *model = new QStandardItemModel(itemNameVector.size(),2,this);
        for(int i=0;i<itemNameVector.size();i++)
        {
            model->setItem(i,0, new QStandardItem(itemNameVector.at(i)));
            model->setItem(i,1, new QStandardItem(QString::number(itemIDVector.at(i))));
        }
        return model;
    }
    else
        {
        return empty_model;
        }
}

QStandardItemModel* calculator::GetItemModelForAllPlayerWeapons()
{
    QVector<QString> itemNameVector;
    QVector<int> itemIDVector;
    QStandardItemModel *empty_model = new QStandardItemModel(1,1,this);
    empty_model->setItem(0,0, new QStandardItem("Brak")); //model returned if player don't have any items
    empty_model->setItem(0,1, new QStandardItem("-1")); //model returned if player don't have any items

    for(int i=0;i<PlayerWeapons.size();i++)
        if(PlayerWeapons.at(i).PlayerID == selectedPlayerID)
        {
            itemNameVector.append(GetWeaponNameFromWeaponID(PlayerWeapons.at(i).WeaponID));
            itemIDVector.append(PlayerWeapons.at(i).WeaponID);
        }
    if(!itemNameVector.isEmpty())
    {
        QStandardItemModel *model = new QStandardItemModel(itemNameVector.size(),2,this);
        for(int i=0;i<itemNameVector.size();i++)
        {
            model->setItem(i,0, new QStandardItem(itemNameVector.at(i)));
            model->setItem(i,1, new QStandardItem(QString::number(itemIDVector.at(i))));
        }
        return model;
    }
    else
        {
        return empty_model;
        }
}

QStandardItemModel* calculator::GetItemModelForAllPlayerGenerators()
{
    QVector<QString> itemNameVector;
    QVector<int> itemIDVector;
    QStandardItemModel *empty_model = new QStandardItemModel(1,1,this);
    empty_model->setItem(0,0, new QStandardItem("Brak")); //model returned if player don't have any items
    empty_model->setItem(0,1, new QStandardItem("-1")); //model returned if player don't have any items

    for(int i=0;i<PlayerGenerators.size();i++)
        if(PlayerGenerators.at(i).PlayerID == selectedPlayerID)
        {
            itemNameVector.append(GetGeneratorNameFromGeneratorID(PlayerGenerators.at(i).GeneratorID));
            itemIDVector.append(PlayerGenerators.at(i).GeneratorID);
        }
    if(!itemNameVector.isEmpty())
    {
        QStandardItemModel *model = new QStandardItemModel(itemNameVector.size(),2,this);
        for(int i=0;i<itemNameVector.size();i++)
        {
            model->setItem(i,0, new QStandardItem(itemNameVector.at(i)));
            model->setItem(i,1, new QStandardItem(QString::number(itemIDVector.at(i))));
        }
        return model;
    }
    else
        {
        return empty_model;
        }
}

QStandardItemModel* calculator::GetItemModelForAllPlayerSkills()
{
    QVector<QString> itemNameVector;
    QVector<int> itemIDVector;
    QStandardItemModel *empty_model = new QStandardItemModel(1,1,this);
    empty_model->setItem(0,0, new QStandardItem("Brak")); //model returned if player don't have any items
    empty_model->setItem(0,1, new QStandardItem("-1")); //model returned if player don't have any items

    for(int i=0;i<PlayerSkills.size();i++)
        if(PlayerSkills.at(i).PlayerID == selectedPlayerID)
        {
            QString skillName = GetSkillNameFromSkillID(PlayerSkills.at(i).SkillID);
            skillName.append(" [");
            skillName.append(GetSkillLevelFromSkillID(PlayerSkills.at(i).SkillID));
            skillName.append("]");
            itemNameVector.append(skillName);
            itemIDVector.append(PlayerSkills.at(i).SkillID);
        }
    if(!itemNameVector.isEmpty())
    {
        QStandardItemModel *model = new QStandardItemModel(itemNameVector.size(),2,this);
        for(int i=0;i<itemNameVector.size();i++)
        {
            model->setItem(i,0, new QStandardItem(itemNameVector.at(i)));
            model->setItem(i,1, new QStandardItem(QString::number(itemIDVector.at(i))));
        }
        return model;
    }
    else
        {
        return empty_model;
        }
}

QStandardItemModel* calculator::GetItemModelForGelUsage()
{
    QStandardItemModel *model = new QStandardItemModel(2,2,this);
    model->setItem(0,0, new QStandardItem("Na sobie"));
    model->setItem(0,1, new QStandardItem("0"));
    model->setItem(1,0, new QStandardItem("Na celu"));
    model->setItem(1,1, new QStandardItem("1"));

    return model;
}

QStandardItemModel* calculator::GetItemModelForSpecialAmmo()
{
    QVector<QString> itemNameVector;
    QVector<int> itemIDVector;
    QStandardItemModel *empty_model = new QStandardItemModel(1,1,this);
    empty_model->setItem(0,0, new QStandardItem("Brak")); //model returned if player don't have any items
    empty_model->setItem(0,1, new QStandardItem("-1")); //model returned if player don't have any items

    for(int i=0;i<PlayerSkills.size();i++)
        if(PlayerSkills.at(i).PlayerID == selectedPlayerID && GetSkillTypeFromSkillID(PlayerSkills.at(i).SkillID) == "Amunicja")
        {
            itemNameVector.append(GetWeaponNameFromWeaponID(PlayerSkills.at(i).SkillID));
            itemIDVector.append(PlayerSkills.at(i).SkillID);
        }
    if(!itemNameVector.isEmpty())
    {
        QStandardItemModel *model = new QStandardItemModel(itemNameVector.size(),2,this);
        for(int i=0;i<itemNameVector.size();i++)
        {
            model->setItem(i,0, new QStandardItem(itemNameVector.at(i)));
            model->setItem(i,1, new QStandardItem(QString::number(itemIDVector.at(i))));
        }
        return model;
    }
    else
        {
        return empty_model;
        }
}

QString calculator::GetGeneratorNameFromGeneratorID(int ID)
{
    QString name = "Unknown Generator ID!";
    for(int i=0;i<Generators.size();i++)
        if(Generators.at(i).GeneratorID == ID)
            name = Generators.at(i).GeneratorName;
    return name;
}

void calculator::setDifficultyInStats(QString level, QString reason)
{
    QString difficulty_full = level + " [" + reason + "]";
    ui->label_difficulty_2->setText(difficulty_full);
}



//CALCULATION
void calculator::CalculateSuccessTresholdForActionID(int actionID)
{

    int success = GetBaseSuccessTreshold(actionID);
    int difficulty = GetFinalDifficultyValueForActionID(actionID);

    successTreshold = success + GetSumOfAccModifiers() + difficulty;
    qDebug() << successTreshold;
}

int calculator::GetBaseSuccessTreshold(int actionID)
{
    int success;
    if(actionID > -1 && actionID < 5) // Get base success for weapons (base weapon + weapon acc + armor modifiers)
    {
        success = 50 + GetWeaponAccFromWeaponID(selectedActionItemID) + GetPlayersArmorWpnAccModifier(selectedPlayerID);
        setSuccessTreshold(success);
    }
    else if(actionID == 7 || actionID == 18) // Get base success for skills (base skill mastery + armor modifiers)
    {
        if (!selectedActionItemName.contains(GetPlayerSpecializationSkill(selectedPlayerID)))
            success = GetPlayerSkillMastery(selectedPlayerID,GetSkillTypeFromSkillID(selectedActionItemID)) + GetPlayersArmorSkillAccModifier(selectedPlayerID);
        else
            success = GetPlayerSkillMastery(selectedPlayerID,"Specjalizacja") + GetPlayersArmorSkillAccModifier(selectedPlayerID);

        setSuccessTreshold(success);
    }
    else if(actionID > 9 && actionID < 13) // Get base success for omniblades (base of player evasiveness + weapon acc)
    {
        success = GetPlayerEvasiveness(selectedTargetID) + GetOmnibladeAccFromOmnibladeID(selectedActionItemID);
        setSuccessTreshold(success);
    }
    else if(actionID == 19) // // Get base success for special ammo activation (base battle mastery + armor modifiers)
    {
        success = GetPlayerSkillMastery(selectedPlayerID,"Bojowe") + GetPlayersArmorSkillAccModifier(selectedPlayerID);
        setSuccessTreshold(success);
    }
    else
    {
       success = 0;
    }

    return success;
}

int calculator::GetSumOfAccModifiers()
{
    int acc_sum = 0;
    for(int i=0;i<ui->tableWidget_AccMod->rowCount();i++)
        acc_sum += ui->tableWidget_AccMod->item(i,1)->text().toInt();
    return acc_sum;
}

int calculator::GetSumOfDmgModifiers()
{
    int dmg_sum = 0;
    for(int i=0;i<ui->tableWidget_DmgMod->rowCount();i++)
        dmg_sum += ui->tableWidget_DmgMod->item(i,1)->text().toInt();
    return dmg_sum;
}

int calculator::GetDifficultyValueFromName(QString diff_name)
{
    if(diff_name == "Bardzo łatwy")
        return 1;
    else if(diff_name == "Łatwy")
        return 2;
    else if(diff_name == "Normalny")
        return 3;
    else if(diff_name == "Trudny")
        return 4;
    else if(diff_name == "Bardzo trudny")
        return 5;
    else if(diff_name == "Niemożliwy")
        return 6;
    else
        return 99;
}

int calculator::GetDifficultyModifierFromValue(int val)
{
    switch(val)
    {
    case 1:
        return 30;
    case 2:
        return 15;
    case 3:
        return 0;
    case 4:
        return -15;
    case 5:
        return -30;
    case 6:
        return -50;
    default:
        return 9999;
    }
}

int calculator::GetFinalDifficultyValueForActionID(int actionID)
{
    int difficulty_value = GetDifficultyValueFromName(difficulty_level_name);

    if(actionID > -1 && actionID < 5) // Weapons
    {
        difficulty_value += GetPlayersArmorWpnDiffLevelModifier(selectedPlayerID);
    }
    else if(actionID == 7 || actionID == 18) // Skills
    {
        difficulty_value += GetPlayersArmorSkillDiffLevelModifier(selectedPlayerID);
    }
    else if(actionID > 9 && actionID < 13) // Meelee (base of player evasiveness + weapon acc)
    {
        difficulty_value += GetPlayersArmorMeeleeDiffLevelModifier(selectedPlayerID);
    }
    else if(actionID == 19) // Ammo
    {
        difficulty_value += GetPlayersArmorSkillDiffLevelModifier(selectedPlayerID);
    }
    else
    {
        difficulty_value = difficulty_value;
    }

    if(difficulty_value < 1)
        difficulty_value = 1;
    else if(difficulty_value > 6)
        difficulty_value = 6;

    return GetDifficultyModifierFromValue(difficulty_value);

}

//CUSTOM SLOTS
void calculator::GetDifficultyReasonSlot(QString reason)
{
    difficulty_reason = reason;
    setDifficultyInStats(difficulty_level_name,difficulty_reason);
}

void calculator::GetSelectedActionItemSlot(int id, QString name)
{
    selectedActionItemID = id;
    selectedActionItemName = name;
}

//UI SLOTS
void calculator::on_pushButton_AccMod_add_clicked()
{
    ui->tableWidget_AccMod->insertRow(ui->tableWidget_AccMod->rowCount());
    ui->tableWidget_AccMod->setItem(ui->tableWidget_AccMod->rowCount()-1,0,new QTableWidgetItem(""));
    ui->tableWidget_AccMod->setItem(ui->tableWidget_AccMod->rowCount()-1,1,new QTableWidgetItem(5));

    QSpinBox *spinbox = new QSpinBox(this);
    spinbox->setMinimum(-100);
    spinbox->setMaximum(100);
    ui->tableWidget_AccMod->setCellWidget(ui->tableWidget_AccMod->rowCount()-1,1,spinbox);
}

void calculator::on_pushButton_AccMod_remove_clicked()
{
    int selected_row = ui->tableWidget_AccMod->currentRow();
    ui->tableWidget_AccMod->removeRow(selected_row);
}

void calculator::on_pushButton_DmgMod_add_clicked()
{
    ui->tableWidget_DmgMod->insertRow(ui->tableWidget_DmgMod->rowCount());
    ui->tableWidget_DmgMod->setItem(ui->tableWidget_DmgMod->rowCount()-1,0,new QTableWidgetItem(""));
    ui->tableWidget_DmgMod->setItem(ui->tableWidget_DmgMod->rowCount()-1,1,new QTableWidgetItem(5));

    QSpinBox *spinbox = new QSpinBox(this);
    spinbox->setMinimum(-20000);
    spinbox->setMaximum(20000);
    ui->tableWidget_DmgMod->setCellWidget(ui->tableWidget_DmgMod->rowCount()-1,1,spinbox);
}

void calculator::on_pushButton_DmgMod_add_2_clicked()
{
    int selected_row = ui->tableWidget_DmgMod->currentRow();
    ui->tableWidget_DmgMod->removeRow(selected_row);
}

void calculator::on_comboBox_select_player_activated(int index)
{
    int previously_selected_playerID = selectedPlayerID;
    selectedPlayerID = comboboxPlayersModel->item(index,1)->text().toInt();
    selectedPlayerName = comboboxPlayersModel->item(index,0)->text();

    RemovePlayerFromTargetModel(selectedPlayerID);
    AddPlayerToTargetModel(previously_selected_playerID);

    setPlayerStats(selectedPlayerID);
    setPlayerActiveEffects(selectedPlayerID);
}

void calculator::on_comboBox_select_difficultylevel_activated(const QString &arg1)
{
    difficulty_level_name = arg1;
    dialogbox_difficultyreason *box = new dialogbox_difficultyreason();
    box->setAttribute(Qt::WA_DeleteOnClose);
    box->show();
    connect(box,SIGNAL(reasonSignal(QString)),this,SLOT(GetDifficultyReasonSlot(QString)));

}

void calculator::on_comboBox_select_action_activated(int index)
{
    int currentActionID = GetCurrentActionID();
    if((currentActionID >-1 && currentActionID <10) || currentActionID == 13 || currentActionID == 14 || (currentActionID > 16 && currentActionID < 20)) //this actions require new dialog box
    {
        OpenAdditionalActionDialogBoxForActionID(currentActionID);
    }
    else
    {
        int actionCost = GetActionCostAfterCalculations(currentActionID);
        QString actionType = GetActionTypeFromActionCost(actionCost);

        setSelectedActionCostName(actionType);
        setActionCostInStats(actionType);
        setSelectedActionName();
        setActionNameInStats(selectedActionName);
    }

}

void calculator::on_pushButton_calculate_clicked()
{
    CalculateSuccessTresholdForActionID(GetCurrentActionID());
}

void calculator::on_comboBox_select_target_activated(int index)
{
    selectedTargetName = comboboxTargetsModel->item(index,0)->text();
    selectedTargetID = comboboxTargetsModel->item(index,1)->text().toInt();
}
