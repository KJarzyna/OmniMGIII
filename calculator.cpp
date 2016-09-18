#include "calculator.h"
#include "ui_calculator.h"
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

QString calculator::GetPlayerNameFromPlayerID(int playerID)
{
    QString playerName = "NoPlayerNameForThisID";

    for (int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
            playerName = Players.at(i).PlayerName;
    return playerName;
}

void calculator::RemovePlayerFromTargetModel(int playerID)
{
    for(int i=0;i<comboboxTargetsModel->rowCount();i++)
        if(comboboxTargetsModel->item(i,1)->text().toInt() == playerID)
            comboboxTargetsModel->removeRow(i,QModelIndex());
}

void calculator::AddPlayerToTargetModel(int playerID)
{
    comboboxTargetsModel->insertRows(comboboxTargetsModel->rowCount(),1,QModelIndex());
    comboboxTargetsModel->setItem(comboboxTargetsModel->rowCount()-1,0,new QStandardItem(GetPlayerNameFromPlayerID(playerID)));
    comboboxTargetsModel->setItem(comboboxTargetsModel->rowCount()-1,1,new QStandardItem(QString::number(playerID)));
}

void calculator::setPlayerStats(int playerID)
{
    for(int i=0;i<Players.size();i++)
        if(Players.at(i).PlayerID == playerID)
        {
            ui->label_current_armor->setText(QString::number(Players.at(i).ArmorCurrent));
            ui->label_max_armor->setText(QString::number(Players.at(i).ArmorMax));
            ui->label_current_shield->setText(QString::number(Players.at(i).ShieldCurrent));
            ui->label_max_shield->setText(QString::number(Players.at(i).ShieldMax));
        }
}

void calculator::setPlayerActiveEffects(int playerID)
{
    ui->listWidget_player_conditions->clear();
    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID)
            ui->listWidget_player_conditions->addItem(GetEffectNameFromEffectID(PlayerActiveEffects.at(i).EffectID));
}

void calculator::OpenAdditionalDialogBox(int actionID)
{
    int currentActionID = actionID;
    dialogbox_action *box = new dialogbox_action();
    box->setAttribute(Qt::WA_DeleteOnClose);
    box->InitializeActionType(ui->comboBox_select_action->currentText());

    QStandardItemModel *model = GetItemModelBasedOnSelectedAction(currentActionID);
    box->InitializeActionItemModel(model);
    box->show();
    connect(box,SIGNAL(SelectedActionItem(int,QString)),this,SLOT(GetSelectedActionItemSlot(int,QString)));
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


int calculator::GetCurrentActionID()
{
    int currentRow = ui->comboBox_select_action->currentIndex();
    int actionID = comboboxActionModel->item(currentRow,1)->text().toInt();
    return actionID;
}

QString calculator::GetWeaponTypeFromWeaponID(int ID)
{
    QString WeaponType = "Unknown Weapon ID!";
    for(int i=0;i<Weapons.size();i++)
        if(Weapons.at(i).WeaponID == ID)
            WeaponType = Weapons.at(i).WeaponType;
    return WeaponType;

}

QString calculator::GetWeaponNameFromWeaponID(int ID)
{
    QString name = "Unknown Weapon ID!";
    for(int i=0;i<Weapons.size();i++)
        if(Weapons.at(i).WeaponID == ID)
            name = Weapons.at(i).WeaponName;
    return name;
}

QString calculator::GetGeneratorNameFromGeneratorID(int ID)
{
    QString name = "Unknown Generator ID!";
    for(int i=0;i<Generators.size();i++)
        if(Generators.at(i).GeneratorID == ID)
            name = Generators.at(i).GeneratorName;
    return name;
}

QString calculator::GetSkillNameFromSkillID(int ID)
{
    QString name = "Unknown Skill ID!";
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            name = Skills.at(i).SkillName;
    return name;
}

QString calculator::GetSkillTypeFromSkillID(int ID)
{
    QString SkillType = "Unknown Skill ID!";
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            SkillType = Skills.at(i).SkillType;
    return SkillType;

}

QString calculator::GetSkillLevelFromSkillID(int ID)
{
    QString SkillType = "Unknown Skill ID!";
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            SkillType = Skills.at(i).SkillLevel;
    return SkillType;
}

int calculator::GetActionCostFromActionID(int ID)
{
    int cost = 99;
    for(int i=0;i<Actions.size();i++)
        if(Actions.at(i).ID == ID)
            cost = Actions.at(i).Cost;
    return cost;
}

void calculator::SetActionCost()
{
    int actionID = GetCurrentActionID();
    int actionCost = 100;
    if(actionID != 7)
        actionCost = GetActionCostFromActionID(actionID);
    else
        actionCost = GetSkillCostFromSkillID(selectedActionItemID);

    if(actionCost >= 3 && actionCost < 125)
        ui->label_action_cost_2->setText("AD");
    else if(actionCost < 3)
        ui->label_action_cost_2->setText("AM");
    else
        ui->label_action_cost_2->setText("AD+AM");
}

void calculator::setPlayerFinal()
{
    playerFinal = ui->comboBox_select_player->currentText();
}

void calculator::setActionFinal()
{
    QString actionFinal = ui->comboBox_select_action->currentText();

    if(!selectedActionItemName.isEmpty())
    {
        actionFinal.append(": ");
        actionFinal.append(selectedActionItemName);
    }

}

void calculator::setTargetFinal()
{
    playerFinal = ui->comboBox_select_target->currentText();
}

void calculator::setActionCostFinal()
{
    int actionID = GetCurrentActionID();
    int cost = 100;

    if(actionID != 7)
        cost = GetActionCostFromActionID(actionID);
    else
        cost = GetSkillCostFromSkillID(selectedActionItemID);

    if(PlayersArmorCostReduction(selectedPlayerID) != 0)
    {
        cost = cost + PlayersArmorCostReduction(selectedPlayerID);
    }

    if(cost >= 3 && cost < 125)
        actionCostFinal = "AD";
    else if(cost < 3)
        actionCostFinal = "AM";
    else
        actionCostFinal = "AD+AM";

    qDebug() << "Final cost: " << actionCostFinal;
}

void calculator::setSuccessTresholdFinal()
{

}

int calculator::PlayersArmorCostReduction(int playerID)
{
    int cost_red = 0;
    for(int i=0;i<PlayerArmors.size();i++)
        if(PlayerArmors.at(i).PlayerID == playerID)
            for(int j=0;j<Armors.size();j++)
                if(Armors.at(j).ArmorID == PlayerArmors.at(i).ArmorID)
                    cost_red += Armors.at(j).ActionSkillCost;
    return cost_red;
}

void calculator::ChangeActionCost(QString newCost)
{
    actionCostFinal = newCost;
}

int calculator::GetSkillCostFromSkillID(int ID)
{
    int skillCost = 100;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            skillCost = Skills.at(i).Cost;
    return skillCost;
}

//CUSTOM SLOTS
void calculator::GetDifficultyReasonSlot(QString reason)
{
    difficulty_reason = reason;
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

    RemovePlayerFromTargetModel(selectedPlayerID);
    AddPlayerToTargetModel(previously_selected_playerID);

    setPlayerStats(selectedPlayerID);
    setPlayerActiveEffects(selectedPlayerID);
}

void calculator::on_comboBox_select_difficultylevel_activated(const QString &arg1)
{
    dialogbox_difficultyreason *box = new dialogbox_difficultyreason();
    box->setAttribute(Qt::WA_DeleteOnClose);
    box->show();
    connect(box,SIGNAL(reasonSignal(QString)),this,SLOT(GetDifficultyReasonSlot(QString)));

}


void calculator::on_comboBox_select_action_activated(int index)
{
    selectedActionItemName = "";
    int currentActionID = GetCurrentActionID();
    if(currentActionID >-1 && currentActionID <10 || currentActionID == 13 || currentActionID == 14 || currentActionID > 16 && currentActionID < 20) //this actions require new dialog box
    {
        OpenAdditionalDialogBox(currentActionID);
    }
    SetActionCost();
}




void calculator::on_pushButton_calculate_clicked()
{

    setPlayerFinal();
    setActionFinal();
    setActionCostFinal();
    setTargetFinal();
    setSuccessTresholdFinal();
}
