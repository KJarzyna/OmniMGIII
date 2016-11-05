#include "calculator.h"
#include "ui_calculator.h"
#include "calculator-initialization.cpp"
#include "calculator-actions.cpp"
#include "calculator-weapons.cpp"
#include "calculator-skills.cpp"
#include "calculator-player.cpp"
#include "calculator-effects.cpp"
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
    InitializeDifficultyLevel();
    InitializePlayerStats();

}

calculator::~calculator()
{
    delete ui;
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
    csv.ReadSkillActiveEffectsFromFileAndLoadToVector("Data/skill_effects.csv", SkillActiveEffects);
    csv.ReadActionsFromFileAndLoadToVector("Data/actions.csv", Actions);
    return true;
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

void calculator::ResetAction()
{
    ui->comboBox_select_action->setCurrentIndex(0);
    selectedActionName = "Nie wybrano akcji";
    selectedActionItemName = "";
    selectedActionItemID = -1;
    selectedActionCostName = "AD";
    setActionNameInStats("Nie wybrano akcji");
    AdditionalItemAndActionCost.clear();
}

void calculator::ResetTarget()
{
    ui->comboBox_select_target->setCurrentIndex(0);
    selectedTargetID = -1;
    selectedTargetName = "Nie wybrano celu";

}

void calculator::ResetDifficulty()
{
    ui->comboBox_select_difficultylevel->setCurrentIndex(0);
    difficulty_level_name = "Nie wybrano poziomu trudności";
    difficulty_reason = "";
    setDifficultyInStats("Nie wybrano poziomu trudności", "");
    WidgetItemAndDifficulty.clear();
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

void calculator::CalculationsApproved(bool approved)
{
    if(approved)
    {
        ImplementAfterCalculationChanges();
        setEnableAllInput(true);
        setEnableAfterSecondCalculations(false);
        setEnableAfterFirstCalculations(false);
        ui->textEdit_turn_1->clear();
        ui->textEdit_turn_2->clear();

        dice_results.clear();
        ItemAndAccuracy.clear();
        ItemAndDifficulty.clear();
        ItemAndCritical.clear();
        WidgetItemAndDifficulty.clear();
        WidgetItemAndDamage.clear();
        AdditionalItemAndDifficulty.clear();
        AdditionalItemAndDamage.clear();

        ResetAction();
        ResetTarget();
        ResetDifficulty();


    }
}

void calculator::ActiveEffectDialogBoxConfirmed(QStringList list)
{
    //set Player Barrier level if any Barrier-related skill is in the skill list
    for(int i=7;i<24;i++)
        if(list.contains(GetEffectNameFromEffectID(i)))
            setPlayerBarrier(selectedPlayerID,GetSkillBarrierFromSkillID(i+44));
    //set Player Umocnienie level if any Umocnienie-related skill is in the skill list
    for(int i=126;i<143;i++)
        if(list.contains(GetEffectNameFromEffectID(i)))
            setPlayerBarrier(selectedPlayerID,GetSkillBarrierFromSkillID(i+154));

    RemoveAllEffectsFromPlayer(selectedPlayerID);
    for(int i=0;i<list.size();i++)
        for(int j=0;j<ActiveEffect.size();j++)
            if(ActiveEffect.at(j).Name == list.at(i))
            {
                AddEffectToPlayer(selectedPlayerID,ActiveEffect.at(j).ID);
            }
    setVisualPlayerActiveEffects(selectedPlayerID);
    setVisualPlayerStats(selectedPlayerID);
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

    setVisualPlayerStats(selectedPlayerID);
    setVisualPlayerActiveEffects(selectedPlayerID);

    ResetAction();
    ResetTarget();
    ResetDifficulty();
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
        PerformAdditionalEffects();
        CalculateSuccessTresholdForActionID(GetCurrentActionID());
        CalculateCriticalTresholdForActionID(GetCurrentActionID());
        CalculateFinalActionCostForActionID(GetCurrentActionID());
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
    else
    {
        setEnableAfterSecondCalculations(true);
        setVisualTextToSecondWidget(GetFinalVisualTextFromSelectedInfo());
    }

}

void calculator::on_pushButton_approve_clicked()
{
    dialogbox_yesno_generic *box = new dialogbox_yesno_generic;
    box->setAttribute(Qt::WA_DeleteOnClose);
    box->setDialogBoxType("ApproveCalculations");
    box->setWarningText1("Czy na pewno chcesz zaakceptować wynik? Kliknięcie TAK sprawi, że efekty obliczeń zostaną wprowadzone (skutecznie zaatakowany cel otrzyma obrażenia, Regeneracja Tarcz sprawi, że tarcze gracza zostaną uzupełnione, itd). Jeżeli nie chcesz zapisywać efektów i dodać je ręcznie (lub zmienić obliczenia), kliknij NIE, a następnie ODRZUĆ na dole strony.");
    box->setWarningText2("Wprowadzić zmiany?");
    connect(box,SIGNAL(YesNoSignal(bool)),this,SLOT(CalculationsApproved(bool)));
    box->show();

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
    WidgetItemAndDifficulty.clear();
    WidgetItemAndDamage.clear();
    AdditionalItemAndDifficulty.clear();
    AdditionalItemAndDamage.clear();
    ItemAndCritical.clear();

    ResetAction();
    ResetTarget();
    ResetDifficulty();
}

void calculator::on_pushButton_deleteEffect_clicked()
{
    if(ui->listWidget_player_conditions->count() >0)
    {
        int selected_row = ui->listWidget_player_conditions->currentRow();
        int effectID = GetEffectIDFromEffectName(ui->listWidget_player_conditions->item(selected_row)->text());

        //Set Barrier/Umocnienie to 0
        if((effectID > 6 && effectID < 24) || (effectID > 125 && effectID < 143))
        {
            setPlayerBarrier(selectedPlayerID, 0);
            setVisualPlayerStats(selectedPlayerID);
        }

        RemoveEffectFromPlayer(selectedPlayerID,effectID);
        ui->listWidget_player_conditions->takeItem(selected_row);
    }
}

void calculator::on_pushButton_addEffect_clicked()
{
    DialogBox_ActiveEffect *box = new DialogBox_ActiveEffect;
    box->setAttribute(Qt::WA_DeleteOnClose);
    box->AddEffectsToRightList(ActiveEffect);
    box->AddEffectsToLeftList(ActiveEffect,PlayerActiveEffects,selectedPlayerID);
    connect(box,SIGNAL(sendActiveEffectList(QStringList)),this,SLOT(ActiveEffectDialogBoxConfirmed(QStringList)));
    box->show();
}
