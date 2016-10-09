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
            skillName.append(" (");
            skillName.append(GetSkillLevelFromSkillID(PlayerSkills.at(i).SkillID));
            skillName.append(")");
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

void calculator::setEnableAfterFirstCalculations(bool status)
{
    ui->pushButton_calculate->setEnabled(!status);
    ui->textEdit_turn_1->setEnabled(status);
    ui->pushButton_copy->setEnabled(status);
    ui->pushButton_continue_calculations->setEnabled(status);
}

void calculator::setEnableAfterSecondCalculations(bool status)
{
    ui->pushButton_continue_calculations->setEnabled(!status);
    ui->textEdit_turn_2->setEnabled(status);
    ui->pushButton_copy_2->setEnabled(status);
    ui->pushButton_approve->setEnabled(status);
    ui->pushButton_disapprove->setEnabled(status);
}

void calculator::setEnableAllInput(bool status)
{
    ui->comboBox_select_player->setEnabled(status);
    ui->comboBox_select_action->setEnabled(status);
    ui->comboBox_select_target->setEnabled(status);
    ui->comboBox_select_difficultylevel->setEnabled(status);

    ui->tableWidget_AccMod->clearSelection();
    ui->tableWidget_AccMod->setEnabled(status);
    ui->tableWidget_DmgMod->clearSelection();
    ui->tableWidget_DmgMod->setEnabled(status);
    ui->pushButton_AccMod_add->setEnabled(status);
    ui->pushButton_AccMod_remove->setEnabled(status);
    ui->pushButton_DmgMod_add->setEnabled(status);
    ui->pushButton_DmgMod_add_2->setEnabled(status);
}

//TEXT
QString calculator::GetVisualTextFromSelectedInfo()
{
    QString full_text;

    full_text = GetVisualHeader();
    full_text += "<br>";
    if(isActionHasSuccessCheck(GetCurrentActionID()))
    {
        full_text += GetVisualSuccessCheck();
        full_text += "<br><br>";
        full_text += "Szansa na sukces przy: &lt;";
        full_text += QString::number(successTreshold);
        full_text += "%";
        full_text += "<br>";
        full_text += GetVisualCriticalCheck();
        for(int i=0;i<GetVisualEffectCheck().size();i++)
            full_text += GetVisualEffectCheck().at(i);

        full_text += "<br><br>";
        full_text += "[dice]";
        full_text += GetDiceTypeForActionID(GetCurrentActionID());
        full_text += "[/dice]";

        //full_text += "<br><br>";
        //full_text += GetVisualCalculationSteps();
    }

    return full_text;
}

QString calculator::GetFinalVisualTextFromSelectedInfo()
{
    QString full_text;

    //full_text = GetVisualHeader();
    //full_text += "<br>";
    if(isActionHasSuccessCheck(GetCurrentActionID()))
    {
//        full_text += GetVisualSuccessCheck();
//        full_text += "<br><br>";
//        full_text += "Szansa na sukces przy: &lt;";
//        full_text += QString::number(successTreshold);
//        full_text += "%";
//        full_text += "<br>";
//        full_text += GetVisualCriticalCheck();
//        for(int i=0;i<GetVisualEffectCheck().size();i++)
//            full_text += GetVisualEffectCheck().at(i);

//        full_text += "<br><br>";
//        full_text += "[dice]";
//        full_text += GetDiceTypeForActionID(GetCurrentActionID());
//        full_text += "[/dice]";

//        full_text += "<br><br>";
        full_text = GetVisualSuccessResult();
        full_text += "<br>";
        full_text += GetVisualDamageResult();

        full_text += "<br><br>";
        full_text += GetVisualCalculationSteps();
    }
    else
        full_text = "Brak innych obliczeń do wykonania.";

    return full_text;
}

QString calculator::GetVisualHeader()
{
    QString header;
    QString player = "<font color=#FF8000> " + selectedPlayerName + "</font>";
    QString action = "<font color=#0080FF> [" + selectedActionName.toUpper() + "]</font>";
    QString cost = "<font color=#0080FF> [" + selectedActionCostName + "]</font>";
    QString target = "";
    if(isActionNeedTarget(GetCurrentActionID()))
        target = "<font color=#FF0000> [CEL: " + selectedTargetName + "]</font>";

    header = player + action + cost + target;
    return header;
}

QString calculator::GetVisualSuccessCheck()
{
    int currentActionID = GetCurrentActionID();

    if(isActionHasSuccessCheck(currentActionID))
    {
        QString success;
        success.append(QString::number(GetBaseSuccessTreshold(currentActionID)));

        if(isActionWeaponRelated(currentActionID))
        {
            success.append(" + ");
            success.append(QString::number(GetWeaponAccFromWeaponID(selectedActionItemID)));
            success.append(" [Celność]");

            if(GetPlayersArmorWpnAccModifier(selectedPlayerID) != 0)
            {
                success.append(" + ");
                success.append(QString::number(GetPlayersArmorWpnAccModifier(selectedPlayerID)));
                success.append(" [Pancerz]");
            }
        }
        else if(isActionMeeleeRelated(currentActionID))
        {
            success.append(" + ");
            success.append(QString::number(GetOmnibladeAccFromOmnibladeID(GetPlayersOmnibladeID(selectedPlayerID))));
            success.append(" [Celność omni-ostrza]");
        }

        else if(isActionSkillRelated(currentActionID) || isActionAmmoRelated(currentActionID))
        {
            if(GetSkillAccFromSkillID(selectedActionItemID) != 0)
            {
                success.append(" + ");
                success.append(QString::number(GetSkillAccFromSkillID(selectedActionItemID)));
                success.append(" [Poziom zdolności]");
            }

            if(GetPlayersArmorSkillAccModifier(selectedPlayerID) != 0)
            {
                success.append(" + ");
                success.append(QString::number(GetPlayersArmorSkillAccModifier(selectedPlayerID)));
                success.append(" [Pancerz]");
            }
        }

        success.append(" + ");
        success.append(QString::number(GetDifficultyModifierFromValue(GetFinalDifficultyValueForActionID(currentActionID))));
        success.append(" [Poziom ");
        success.append(GetDifficultyNameFromValue(GetFinalDifficultyValueForActionID(currentActionID)));
        success.append("]");

        success.append(" = ");
        success.append(QString::number(successTreshold));
        success.append("%");
        return success;
    }
}

QString calculator::GetVisualCriticalCheck()
{
    QString crit = "Trafienie krytyczne przy: &#60;";
    crit.append(QString::number(criticalTreshold));
    crit.append("%");
    return crit;
}

QStringList calculator::GetVisualEffectCheck()
{
    QStringList chance;
    if(isActionSkillRelated(GetCurrentActionID()))
    {
        if(GetSkillStunChanceFromSkillID(selectedActionItemID) != 0)
        {
            QString chance_value = QString::number(GetSkillStunChanceFromSkillID(selectedActionItemID));
            QString chance_full = "<br>Ogłuszenie przy: &#60;" + chance_value + "%";
            chance.append(chance_full);
        }
        if(GetSkillKnockoutChanceFromSkillID(selectedActionItemID) != 0)
        {
            QString chance_value = QString::number(GetSkillKnockoutChanceFromSkillID(selectedActionItemID));
            QString chance_full = "<br>Powalenie przy: &#60;" + chance_value + "%";
            chance.append(chance_full);
        }
        if(GetSkillChillChanceFromSkillID(selectedActionItemID) != 0)
        {
            QString chance_value = QString::number(GetSkillChillChanceFromSkillID(selectedActionItemID));
            QString chance_full = "<br>Schłodzenie przy: &#60;" + chance_value + "%";
            chance.append(chance_full);
        }
        if(GetSkillFlameChanceFromSkillID(selectedActionItemID) != 0)
        {
            QString chance_value = QString::number(GetSkillFlameChanceFromSkillID(selectedActionItemID));
            QString chance_full = "<br>Podpalenie przy: &#60;" + chance_value + "%";
            chance.append(chance_full);
        }
        if(GetSkillUpliftChanceFromSkillID(selectedActionItemID) != 0)
        {
            QString chance_value = QString::number(GetSkillUpliftChanceFromSkillID(selectedActionItemID));
            QString chance_full = "<br>Podniesienie przy: &#60;" + chance_value + "%";
            chance.append(chance_full);
        }
    }

    return chance;
}

QString calculator::GetVisualCalculationSteps()
{
    QString text = "<font color=#8040BF>[fabuleoff]</font><br>";

    if(dice_results.size() > 1)
    {
        text += "Obrażenia: ";

        text += QString::number(GetModifiedBaseDamageDealt()) + "*" + QString::number(GetNumberOfSuccess()) + "*0.25";
        if(isCriticalHit())
        {
            text += "*1.3";
            text += " = " + QString::number(GetFinalDamageDealt()) + "<br>";
        }
        else
            text += " = " + QString::number(GetFinalDamageDealt()) + "<br>";

        for(int i=0;i<ItemAndDamage.size();i++)
        {
            text += QString::number(GetBaseDamageDealt()) + " [Obrażenia bazowe]";
            text += QString::number(ItemAndDamage.at(i).value) + " [" + ItemAndDamage.at(i).name + "]";
            text += "<br>";
        }

        text += "<br>";
    }
    else if(dice_results.size() == 1 && isCriticalHit())
    {
        text += "Obrażenia: ";
        text += QString::number(GetModifiedBaseDamageDealt()) + "*1.3 = " + QString::number(GetFinalDamageDealt()) + "<br>";
        for(int i=0;i<ItemAndDamage.size();i++)
        {
            text += QString::number(GetBaseDamageDealt()) + " [Obrażenia bazowe]";
            text += QString::number(ItemAndDamage.at(i).value) + " [" + ItemAndDamage.at(i).name + "]";
            text += "<br>";
        }
        text += "<br>";
    }

    if(ItemAndDifficulty.size() > 0 || AdditionalItemAndDifficulty.size() > 0)
    {
        text += "Poziom trudności:";
        text += "<br>";
        text += "Bazowo: ";
        text += difficulty_level_name + " [";
        text += difficulty_reason + "]";

        for(int i=0;i<ItemAndDifficulty.size();i++)
        {
            text += "<br>";
            text += QString::number(ItemAndDifficulty.at(i).value) + " [" + ItemAndDifficulty.at(i).name + "]";
        }

        for(int i=0;i<AdditionalItemAndDifficulty.size();i++)
        {
            text += "<br>";
            text += QString::number(AdditionalItemAndDifficulty.at(i).value) + " [" + AdditionalItemAndDifficulty.at(i).name + "]";
        }

        text += "<br><br>";
    }

    if(ItemAndAccuracy.size() > 0)
    {
        text += "Premia do trafienia:";

        for(int i=0;i<ItemAndAccuracy.size();i++)
        {
            text += "<br>";
            text += QString::number(ItemAndAccuracy.at(i).value) + " [" + ItemAndAccuracy.at(i).name + "]";
        }
        text += "<br><br>";
    }

    if(ItemAndCritical.size() > 0)
    {
        text += "Premia do szansy na trafienie krytyczne:";

        for(int i=0;i<ItemAndCritical.size();i++)
        {
            text += "<br>";
            text += QString::number(ItemAndCritical.at(i).value) + " [" + ItemAndCritical.at(i).name + "]";
        }
        text += "<br><br>";
    }

    if(ItemAndActionCost.size() > 0)
    {
        text += "Zmiana kosztu akcji:";

        for(int i=0;i<ItemAndActionCost.size();i++)
        {
            text += "<br>";
            text += QString::number(ItemAndActionCost.at(i).value) + " [" + ItemAndActionCost.at(i).name + "]";
        }
        text += "<br><br>";
    }
    text += "<font color=#8040BF>[/fabuleoff]</font><br>";
    return text;
}

QString calculator::GetVisualSuccessResult()
{
    QString result;
    result = "<font color=#00FFFF>Efekt: </font>";
    if(isActionHasSuccessCheck(GetCurrentActionID()))
    {
        if(dice_results.size() == 1)
        {
            if(isActionNeedTarget(GetCurrentActionID()) && isCriticalHit())
                result += "Trafienie krytyczne!";
            else if(isActionNeedTarget(GetCurrentActionID()) && GetNumberOfSuccess() > 0)
                result += "Trafienie!";
            else if(isActionNeedTarget(GetCurrentActionID()) && GetNumberOfSuccess() == 0)
                result += "Pudło!";
            else if(!isActionNeedTarget(GetCurrentActionID()) && GetNumberOfSuccess() > 0)
                result += "Sukces!";
            else
                result += "Porażka!";
        }
        else if(dice_results.size() == 4)
        {
            if(GetNumberOfSuccess() > 0)
            {
                result += "Trafienie na ";
                result += QString::number(GetNumberOfSuccess());
                result += " kościach!";
            }
            if(isCriticalHit())
                result += " Trafienie krytyczne!";
        }
        else
            result = "";
    }
    else
        result = "";

    return result;
}

QString calculator::GetVisualDamageResult()
{
    QString result;
    if(dice_results.size() == 1 && isActionNeedTarget(GetCurrentActionID()))
    {
        result = "<font color=#00FFFF>Zadane obrażenia: </font>";
        result += QString::number(GetFinalDamageDealt());
        return result;
    }
    else if(dice_results.size() > 1 && isActionNeedTarget(GetCurrentActionID()))
    {
        int damage = GetFinalDamageDealt();
        result = "<font color=#00FFFF>Zadane obrażenia: </font>";
        result += QString::number(damage);
        return result;
    }
    else
        return "";
}

void calculator::setVisualTextToWidget(QString text)
{
    ui->textEdit_turn_1->setText(text);
}

void calculator::setVisualTextToSecondWidget(QString text)
{
    ui->textEdit_turn_2->setText(text);
}

//CALCULATION
void calculator::CalculateSuccessTresholdForActionID(int actionID)
{

    int success = GetBaseSuccessTreshold(actionID);
    int difficulty = GetDifficultyModifierFromValue(GetFinalDifficultyValueForActionID(actionID));
    int armor = GetActionAccModifierForActionIDandPlayerID(actionID,selectedPlayerID);
    int weapon_acc = 0;
    int skill_acc = 0;

    if(isActionWeaponRelated(actionID))
        weapon_acc = GetWeaponAccFromWeaponID(selectedActionItemID);
    else if(isActionMeeleeRelated(actionID))
        weapon_acc = GetOmnibladeAccFromOmnibladeID(GetPlayersOmnibladeID(selectedPlayerID));
    else if(isActionSkillRelated(actionID) || isActionAmmoRelated(actionID))
        skill_acc = GetSkillAccFromSkillID(selectedActionItemID);

    int treshold = success + weapon_acc + difficulty + armor + skill_acc;
    if(treshold > 90)
        treshold = 90;
    else if(treshold < 0)
        treshold = 0;
    setSuccessTreshold(treshold);
}

void calculator::CalculateCriticalTresholdForActionID(int actionID)
{
    int base = 5;
    int crit_sum = base + GetPlayersArmorCriticalChanceModifier(selectedPlayerID);

    setCriticalTreshold(crit_sum);

}

int calculator::GetBaseSuccessTreshold(int actionID)
{
    int success;
    if(isActionWeaponRelated(actionID)) // Get base success for weapons
    {
        success = 50;
    }
    else if(isActionSkillRelated(actionID)) // Get base success for skills
    {
        if (!selectedActionItemName.contains(GetPlayerSpecializationSkill(selectedPlayerID)))
            success = GetPlayerSkillMastery(selectedPlayerID,GetSkillTypeFromSkillID(selectedActionItemID));
        else
            success = GetPlayerSkillMastery(selectedPlayerID,"Specjalizacja");
    }
    else if(isActionMeeleeRelated(actionID)) // Get base success for omniblades
    {
        success = GetPlayerEvasiveness(selectedTargetID);
    }
    else if(isActionAmmoRelated(actionID)) // // Get base success for special ammo activation
    {
        success = GetPlayerSkillMastery(selectedPlayerID,"Bojowe");
    }
    else
    {
       success = 0;
    }

    return success;
}

int calculator::GetSumOfAccModifiers()
{
    AdditionalItemAndDifficulty.clear();
    int acc_sum = 0;
    for(int i=0;i<ui->tableWidget_AccMod->rowCount();i++)
    {
        QSpinBox *spinbox = qobject_cast<QSpinBox*>(ui->tableWidget_AccMod->cellWidget(i,1));
        acc_sum += spinbox->value();

        C_ItemModificator item;
        item.name = ui->tableWidget_AccMod->item(i,0)->text();
        item.value = spinbox->value();
        AdditionalItemAndDifficulty.append(item);
    }
    return acc_sum;
}

int calculator::GetSumOfDmgModifiers()
{
    int dmg_sum = 0;
    for(int i=0;i<ui->tableWidget_DmgMod->rowCount();i++)
    {
        QSpinBox *spinbox = qobject_cast<QSpinBox*>(ui->tableWidget_DmgMod->cellWidget(i,1));
        dmg_sum += spinbox->value();
    }
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

    if(isActionWeaponRelated(actionID)) // Weapons
    {
        difficulty_value += GetPlayersArmorWpnDiffLevelModifier(selectedPlayerID);
    }
    else if(isActionSkillRelated(actionID)) // Skills
    {
        difficulty_value += GetPlayersArmorSkillDiffLevelModifier(selectedPlayerID);
    }
    else if(isActionMeeleeRelated(actionID)) // Meelee (base of player evasiveness + weapon acc)
    {
        difficulty_value += GetPlayersArmorMeeleeDiffLevelModifier(selectedPlayerID);
    }
    else if(isActionAmmoRelated(actionID)) // Ammo
    {
        difficulty_value += GetPlayersArmorSkillDiffLevelModifier(selectedPlayerID);
    }
    else
    {
        difficulty_value = difficulty_value;
    }

    difficulty_value += GetSumOfAccModifiers();

    if(difficulty_value < 1)
        difficulty_value = 1;
    else if(difficulty_value > 6)
        difficulty_value = 6;

    return difficulty_value;

}

QString calculator::GetDifficultyNameFromValue(int val)
{
    if(val == 1)
        return "Bardzo łatwy";
    else if(val == 2)
        return "Łatwy";
    else if(val == 3)
        return "Normalny";
    else if(val == 4)
        return "Trudny";
    else if(val == 5)
        return "Bardzo trudny";
    else if(val == 6)
        return "Niemożliwy";
    else
        return "Nieznany";
}

QString calculator::GetDiceTypeForActionID(int actionID)
{
    if(actionID == 1 || actionID == 2)
        return "4d100";
    else
        return "1d100";
}

bool calculator::CheckForWarnings()
{
    //Player Don't Have Enough Ammo
    if(isActionWeaponRelated(GetCurrentActionID()) && GetAmmoLeftInPlayersWeapon(selectedPlayerID,selectedActionItemID) == 0)
    {
        QString warning = selectedPlayerName + " nie posiada pocisków w magazynku " + selectedActionItemName + "!";
        PopUpWarning(warning);
        return false;
    }
    return true;
}

void calculator::PopUpWarning(QString text)
{
    dialogbox_warning_generic *box = new dialogbox_warning_generic();
    box->setAttribute(Qt::WA_DeleteOnClose);
    box->setWarningLabel(text);
    box->show();
}

void calculator::setCriticalTreshold(int treshold)
{
    criticalTreshold = treshold;
}


//CALCULATION PART 2
void calculator::PopUpDicesQuestion()
{
    dialogbox_postcalculation *box = new dialogbox_postcalculation();
    box->setAttribute(Qt::WA_DeleteOnClose);
    if(GetCurrentActionID() == 1 || GetCurrentActionID() == 2 )
        box->InitializeDices(4);
    else
        box->InitializeDices(1);
    box->show();
    connect(box,SIGNAL(DiceResults(QVector<int>)),this,SLOT(GetDiceResults(QVector<int>)));
    connect(box,SIGNAL(DialogBoxClosed()),this,SLOT(DiceDialogBoxClosed()));
}

void calculator::DiceDialogBoxClosed()
{
    setEnableAfterSecondCalculations(true);
    setVisualTextToSecondWidget(GetFinalVisualTextFromSelectedInfo());
}

int calculator::GetNumberOfSuccess()
{
    int numOfsuccess = 0;
    for(int i=0;i<dice_results.size();i++)
        if(dice_results.at(i) < successTreshold)
            numOfsuccess++;
   return numOfsuccess;
}

bool calculator::isCriticalHit()
{
    //check for Critical Hit on number of dices (numDices)

    if(GetNumberOfSuccess() > 0)
    {
        if(dice_results.at(0) < criticalTreshold)
            return true;
        return false;
    }
    else
        return false;
}

int calculator::GetBaseDamageDealt()
{
    int damage = 0;
    if(isActionWeaponRelated(GetCurrentActionID()))
    {
        damage = GetWeaponBaseDamageFromWeaponID(selectedActionItemID);

    }
    else if(isActionSkillRelated(GetCurrentActionID()))
    {
        if(isPlayerHasShield(selectedTargetID))
            damage = GetSkillDamageToShieldFromSkillID(selectedActionItemID);
        else
            damage = GetSkillDamageToArmorFromSkillID(selectedActionItemID);
    }
    else if(isActionMeeleeRelated(GetCurrentActionID()))
    {
        damage = GetOmnibladeDamageFromOmnibladeID(selectedActionItemID);
    }

    return damage;

}

int calculator::GetModifiedBaseDamageDealt()
{
    //Base damage modified by armor/special weapon effects/special ammo
    int damage = GetBaseDamageDealt();

    if(isActionWeaponRelated(GetCurrentActionID()) && !isPlayerHasShield(selectedTargetID))
        GetWeaponDamageToArmorFromWeaponID(selectedActionItemID);
    else if (isActionWeaponRelated(GetCurrentActionID()) && isPlayerHasShield(selectedTargetID))
        GetWeaponDamageToShieldFromWeaponID(selectedActionItemID);

    for(int i=0;i<ItemAndDamage.size();i++)
        damage += ItemAndDamage.at(i).value;
    return damage;
}

int calculator::GetFinalDamageDealt()
{
    int damage = GetModifiedBaseDamageDealt();

    if(dice_results.size()>1)
        damage = floor(damage*GetNumberOfSuccess()*0.25);

    if(isCriticalHit())
        damage = floor(damage*1.3);
    return damage;
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

void calculator::GetDiceResults(QVector<int> dices)
{
    dice_results.clear();
    for(int i=0;i<dices.size();i++)
        dice_results.append(dices.at(i));
}

//UI SLOTS
void calculator::on_pushButton_AccMod_add_clicked()
{
    ui->tableWidget_AccMod->insertRow(ui->tableWidget_AccMod->rowCount());
    ui->tableWidget_AccMod->setItem(ui->tableWidget_AccMod->rowCount()-1,0,new QTableWidgetItem(""));
    ui->tableWidget_AccMod->setItem(ui->tableWidget_AccMod->rowCount()-1,1,new QTableWidgetItem(5));

    QSpinBox *spinbox = new QSpinBox(this);
    spinbox->setMinimum(-5);
    spinbox->setMaximum(5);
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

    if(isActionNeedTarget(currentActionID))
        ui->comboBox_select_target->setEnabled(true);
    else
        ui->comboBox_select_target->setEnabled(false);

    if(isActionNeedDifficultyCheck(currentActionID))
        ui->comboBox_select_difficultylevel->setEnabled(true);
    else
        ui->comboBox_select_difficultylevel->setEnabled(false);

}

void calculator::on_pushButton_calculate_clicked()
{
    if(CheckForWarnings())
    {
        CalculateSuccessTresholdForActionID(GetCurrentActionID());
        CalculateCriticalTresholdForActionID(GetCurrentActionID());
        setEnableAfterFirstCalculations(true);
        setEnableAllInput(false);
        setVisualTextToWidget(GetVisualTextFromSelectedInfo());
    }
}

void calculator::on_comboBox_select_target_activated(int index)
{
    selectedTargetName = comboboxTargetsModel->item(index,0)->text();
    selectedTargetID = comboboxTargetsModel->item(index,1)->text().toInt();
}

void calculator::on_pushButton_continue_calculations_clicked()
{
    int actionID = GetCurrentActionID();
    if(isActionHasSuccessCheck(actionID))
        PopUpDicesQuestion();

}

void calculator::on_pushButton_approve_clicked()
{
    setEnableAllInput(true);
    setEnableAfterSecondCalculations(false);
    setEnableAfterFirstCalculations(false);
    ui->textEdit_turn_1->clear();
    ui->textEdit_turn_2->clear();

    dice_results.clear();
    ItemAndAccuracy.clear();
    ItemAndDifficulty.clear();
    ItemAndCritical.clear();
}

void calculator::on_pushButton_disapprove_clicked()
{
    setEnableAllInput(true);
    setEnableAfterSecondCalculations(false);
    setEnableAfterFirstCalculations(false);
    ui->textEdit_turn_1->clear();
    ui->textEdit_turn_2->clear();

    dice_results.clear();
    ItemAndAccuracy.clear();
    ItemAndDifficulty.clear();
    ItemAndCritical.clear();
}
