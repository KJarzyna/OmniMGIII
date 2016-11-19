#include "calculator.h"
#include "ui_calculator.h"

void calculator::InitializeAccModTable_Manual()
{
    ui->tableWidget_AccMod_M->setColumnWidth(0,270);
    ui->tableWidget_AccMod_M->setColumnWidth(1,60);
    ui->tableWidget_AccMod_M->horizontalHeader()->setStretchLastSection(true);

}

void calculator::InitializeDmgModTable_Manual()
{
    ui->tableWidget_DmgMod_M->setColumnWidth(0,270);
    ui->tableWidget_DmgMod_M->setColumnWidth(1,60);
    ui->tableWidget_DmgMod_M->horizontalHeader()->setStretchLastSection(true);

}

void calculator::InitializeTestVisibility_Manaul(bool state)
{
   ui->label_accmod_M->setVisible(state);
   ui->tableWidget_AccMod_M->setVisible(state);
   ui->pushButton_AccMod_add_M->setVisible(state);
   ui->pushButton_AccMod_remove_M->setVisible(state);
   ui->label_select_difficultylevel_M->setVisible(state);
   ui->comboBox_select_difficultylevel_M->setVisible(state);
   ui->label_success_chance_M->setVisible(state);
   ui->spinBox_success_chance_M->setVisible(state);
}

void calculator::InitializePlayersComboBoxDamage_Manual()
{
    ui->comboBox_select_player_M->setModel(comboboxPlayersModel);
}

void calculator::ResetAdditionalDifficulty()
{
    while (ui->tableWidget_AccMod_M->rowCount() > 0)
    {
        ui->tableWidget_AccMod_M->removeRow(ui->tableWidget_AccMod_M->rowCount()-1);
    }
}

void calculator::ResetAdditionalDamage()
{
    while (ui->tableWidget_DmgMod_M->rowCount() > 0)
    {
        ui->tableWidget_DmgMod_M->removeRow(ui->tableWidget_DmgMod_M->rowCount()-1);
    }
}

int calculator::GetSumOfWidgetDiffModifiers_Manual()
{
    WidgetItemAndDifficulty_M.clear();
    int acc_sum = 0;
    for(int i=0;i<ui->tableWidget_AccMod_M->rowCount();i++)
    {
        QSpinBox *spinbox = qobject_cast<QSpinBox*>(ui->tableWidget_AccMod_M->cellWidget(i,1));
        C_ItemModificator item;
        item.name = ui->tableWidget_AccMod_M->item(i,0)->text();
        item.value = spinbox->value();
        WidgetItemAndDifficulty_M.append(item);
    }

    for(int i=0;i<WidgetItemAndDifficulty_M.size();i++)
        acc_sum += WidgetItemAndDifficulty_M.at(i).value;

    return acc_sum;
}

int calculator::GetSumOfWidgetDamageModifiers_Manual()
{
    WidgetItemAndDamage_M.clear();
    int dmg_sum = 0;
    for(int i=0;i<ui->tableWidget_DmgMod_M->rowCount();i++)
    {
        QSpinBox *spinbox = qobject_cast<QSpinBox*>(ui->tableWidget_DmgMod_M->cellWidget(i,1));
        C_ItemModificator item;
        item.name = ui->tableWidget_DmgMod_M->item(i,0)->text();
        item.value = spinbox->value();
        WidgetItemAndDamage_M.append(item);
    }

    for(int i=0;i<WidgetItemAndDamage_M.size();i++)
        dmg_sum += WidgetItemAndDamage_M.at(i).value;

    return dmg_sum;
}

QString calculator::GetVisualTextFromSelectedInfo_Manual()
{
    QString full_text;

    if(getManualModeTypeSelected() == 0)
    {
        full_text = GetVisualHeader_Manual();
        full_text += "<br>";

        if(ui->checkBox_sukces_check_M->isChecked())
        {
            full_text += GetVisualSuccessCheck_Manual();
            full_text += "<br><br>";
            full_text += "Szansa na sukces przy: &lt;";
            full_text += QString::number(successTreshold);
            full_text += "%";

            full_text += "<br><br>";
            full_text += GetVisualCalculationSteps_Difficulty_Manual();
        }

    }
    else if(getManualModeTypeSelected() == 1)
    {
        full_text = GetVisualDmgHeader_Manual();
        full_text += GetVisualTargetArmorAndShieldLeftResult_Manual();

        if(WidgetItemAndDamage_M.count() > 0)
            full_text += "<br><br>" + GetVisualCalculationSteps_Damage_Manual();

    }

    return full_text;
}

QString calculator::GetVisualHeader_Manual()
{
    QString header;
    QString player = "<font color=#FF8000> " + ui->lineEdit_select_player_M->text() + "</font>";
    QString action = "";
    if(ui->lineEdit_action_M->text() != "")
        action = "<font color=#0080FF> [" + ui->lineEdit_action_M->text().toUpper() + "]</font>";

    QString cost = "<font color=#0080FF> [" + ui->comboBox_select_actioncost_M->currentText() + "]</font>";

    QString target;
    if(ui->lineEdit_target_M->text() != "")
        target = "<font color=#FF0000> [CEL: " + ui->lineEdit_target_M->text() + "]</font>";

    header = player + action + cost + target;
    return header;
}

QString calculator::GetVisualDmgHeader_Manual()
{
    QString header;
    QString player = "<font color=#FF8000> " + ui->comboBox_select_player_M->currentText() + "</font>";

    QString dmg = "<font color=#0080FF> otrzymuje obrażenia: </font><font color=#00FFFF>" + QString::number(GetFinalDamageTaken_Manual()) + "</font>";

    QString reason = "";
    if(ui->lineEdit_select_dmg_reason_M->text() != "")
        reason = "<font color=#0080FF> (" + ui->lineEdit_select_dmg_reason_M->text() + ")</font>";


    header = player + dmg + reason;
    return header;
}

QString calculator::GetVisualSuccessCheck_Manual()
{
   QString success;
   int difficulty_value_mod = 0;
   int success_sum = 0;

   success.append(QString::number(ui->spinBox_success_chance_M->value()));
   success.append(" [Bazowo] ");
   GetSumOfWidgetDiffModifiers_Manual();

   if(ui->tableWidget_AccMod_M->rowCount() > 0)
       for(int i=0;i<WidgetItemAndDifficulty_M.size();i++)
           difficulty_value_mod += WidgetItemAndDifficulty_M.at(i).value;

   int diff_val = GetDifficultyValueFromName(ui->comboBox_select_difficultylevel_M->currentText()) + difficulty_value_mod;

   if(diff_val < 1)
       diff_val = 1;
   else if(diff_val > 6)
       diff_val = 6;

   success.append(" + ");
   success.append(QString::number(GetDifficultyModifierFromValue(diff_val)));
   success.append(" [Poziom ");
   success.append(GetDifficultyNameFromValue(diff_val));
   success.append("]");

   success_sum = ui->spinBox_success_chance_M->value() + GetDifficultyModifierFromValue(diff_val);
   setSuccessTreshold(success_sum);
   success.append(" = ");
   success.append(QString::number(success_sum));
   success.append("%");



   return success;

}

QString calculator::GetVisualCalculationSteps_Difficulty_Manual()
{
    QString text = "";

    if(WidgetItemAndDifficulty_M.size() > 0)
    {
        text += "<font color=#8040BF>[fabuleoff]</font><br>";
        text += "Poziom trudności:";
        text += "<br>";
        text += ui->comboBox_select_difficultylevel_M->currentText();

        for(int i=0;i<WidgetItemAndDifficulty_M.size();i++)
        {
            text += "<br>";
            if(WidgetItemAndDifficulty_M.at(i).value > 0)
                text += "+";
            text += QString::number(WidgetItemAndDifficulty_M.at(i).value) + " [" + WidgetItemAndDifficulty_M.at(i).name + "]";
        }
        text += "<br>";
        text += "<font color=#8040BF>[/fabuleoff]</font><br>";
    }

    return text;
}

QString calculator::GetVisualCalculationSteps_Damage_Manual()
{
    QString text = "";

    if(WidgetItemAndDamage_M.size() > 0)
    {
        text += "<font color=#8040BF>[fabuleoff]</font><br>";
        text += "Obrażenia:";
        text += "<br>";
        text += QString::number(ui->spinBox_damage_M->value()) + " [Bazowe]";

        for(int i=0;i<WidgetItemAndDamage_M.size();i++)
        {
            text += "<br>";
            if(WidgetItemAndDamage_M.at(i).value > 0)
                text += "+";
            text += QString::number(WidgetItemAndDamage_M.at(i).value) + " [" + WidgetItemAndDamage_M.at(i).name + "]";
        }
        text += "<br>";
        text += "<font color=#8040BF>[/fabuleoff]</font><br>";
    }

    return text;
}

QString calculator::GetVisualTargetArmorAndShieldLeftResult_Manual()
{
    QString text = "";
    QString shield_max = "", shield_current = "", armor_max = "", armor_current = "", barrier = "";
    int damage_taken = ui->spinBox_damage_M->value() + GetSumOfWidgetDamageModifiers_Manual();

    if(!ui->checkBox_ignore_shields_M->isChecked())
    {
        text += "<br><br>";
        text += selectedTargetName + ":<br>";

        shield_max = QString::number(GetPlayerMaxShield(selectedTargetID));
        armor_max = QString::number(GetPlayerMaxArmor(selectedTargetID));

        if(isPlayerHasBarrier(selectedTargetID))
        {
            barrier = QString::number(GetPlayerBarrierAfterDamage(selectedTargetID,damage_taken));
            shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedTargetID,0));
            armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedTargetID,0));
        }
        else if(!isPlayerHasBarrier(selectedTargetID) && isPlayerHasShield(selectedTargetID))
        {
            shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedTargetID,damage_taken));
            armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedTargetID,0));
        }
        else if(!isPlayerHasShield(selectedTargetID) && !isPlayerHasBarrier(selectedTargetID))
            armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedTargetID,damage_taken));
        else
            armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedTargetID,0));

        if(isPlayerHasBarrier(selectedTargetID))
        {
            text += "Bariera <font color=#BF80FF>";
            text += barrier + "</font> ";
        }

        text += "Tarcze <font color=#0080FF>";
        text += shield_current + "/" + shield_max + "</font> ";
        text += "Pancerz <font color=#FFBF00>";
        text += armor_current + "/" + armor_max + "</font><br>";
    }
    else
    {
        text += "<br><br>";
        text += selectedTargetName + ":<br>";


        shield_max = QString::number(GetPlayerMaxShield(selectedTargetID));
        armor_max = QString::number(GetPlayerMaxArmor(selectedTargetID));
        barrier = QString::number(GetPlayerBarrierAfterDamage(selectedTargetID,0));

        shield_current = QString::number(GetPlayerShieldCurrentAfterDamage(selectedTargetID,0));
        armor_current = QString::number(GetPlayerArmorCurrentAfterDamage(selectedTargetID,damage_taken));

        if(isPlayerHasBarrier(selectedTargetID))
        {
            text += "Bariera <font color=#BF80FF>";
            text += barrier + "</font> ";
        }
        text += "Tarcze <font color=#0080FF>";
        text += shield_current + "/" + shield_max + "</font> ";
        text += "Pancerz <font color=#FFBF00>";
        text += armor_current + "/" + armor_max + "</font><br>";
    }
    return text;
}

int calculator::GetFinalDamageTaken_Manual()
{
    int dmg = ui->spinBox_damage_M->value() + GetSumOfWidgetDamageModifiers_Manual();

    if(dmg < 0)
        dmg = 0;
    return dmg;
}

//UI SLOTS
void calculator::on_checkBox_sukces_check_M_clicked(bool checked)
{
    ResetAdditionalDifficulty();
    InitializeTestVisibility_Manaul(checked);
}

void calculator::on_pushButton_AccMod_add_M_clicked()
{
    ui->tableWidget_AccMod_M->insertRow(ui->tableWidget_AccMod_M->rowCount());
    ui->tableWidget_AccMod_M->setItem(ui->tableWidget_AccMod_M->rowCount()-1,0,new QTableWidgetItem(""));
    ui->tableWidget_AccMod_M->setItem(ui->tableWidget_AccMod_M->rowCount()-1,1,new QTableWidgetItem(5));

    QSpinBox *spinbox = new QSpinBox(this);
    spinbox->setMinimum(-5);
    spinbox->setMaximum(5);
    ui->tableWidget_AccMod_M->setCellWidget(ui->tableWidget_AccMod_M->rowCount()-1,1,spinbox);

}

void calculator::on_pushButton_AccMod_remove_M_clicked()
{
    int selected_row = ui->tableWidget_AccMod_M->currentRow();
    ui->tableWidget_AccMod_M->removeRow(selected_row);
}

void calculator::on_pushButton_DmgMod_add_M_clicked()
{
    ui->tableWidget_DmgMod_M->insertRow(ui->tableWidget_DmgMod_M->rowCount());
    ui->tableWidget_DmgMod_M->setItem(ui->tableWidget_DmgMod_M->rowCount()-1,0,new QTableWidgetItem(""));
    ui->tableWidget_DmgMod_M->setItem(ui->tableWidget_DmgMod_M->rowCount()-1,1,new QTableWidgetItem(5));

    QSpinBox *spinbox = new QSpinBox(this);
    spinbox->setMinimum(-99999);
    spinbox->setMaximum(99999);
    ui->tableWidget_DmgMod_M->setCellWidget(ui->tableWidget_DmgMod_M->rowCount()-1,1,spinbox);
}

void calculator::on_pushButton_DmgMod_remove_M_clicked()
{
    int selected_row = ui->tableWidget_DmgMod_M->currentRow();
    ui->tableWidget_DmgMod_M->removeRow(selected_row);
}

void calculator::on_comboBox_select_player_M_activated(int index)
{
    selectedTargetID = comboboxPlayersModel->item(index,1)->text().toInt();
    selectedTargetName = comboboxPlayersModel->item(index,0)->text();

    setVisualPlayerStats(selectedTargetID);
    setVisualPlayerActiveEffects(selectedTargetID);
}

void calculator::on_tabWidget_calculation_type_currentChanged(int index)
{
    if(index == 0)
    {
        InitializePlayersComboBox();
        InitializeActionsComboBox();
        InitializeTargetsComboBox();
        InitializeDifficultyLevel();
        InitializePlayerStats();
        ui->pushButton_approve_M->setVisible(false);
        ui->pushButton_disapprove_M->setVisible(false);
        ui->pushButton_continue_calculations->setVisible(true);
    }
    else
    {
        ResetAction();
        ResetTarget();
        ResetDifficulty();

        selectedTargetID = comboboxPlayersModel->item(0,1)->text().toInt();
        selectedTargetName = comboboxPlayersModel->item(0,0)->text();
        ui->comboBox_select_player_M->setCurrentIndex(0);
        setVisualPlayerStats(selectedTargetID);
        setVisualPlayerActiveEffects(selectedTargetID);

        ui->pushButton_approve_M->setVisible(true);
        ui->pushButton_disapprove_M->setVisible(true);
        ui->pushButton_continue_calculations->setVisible(false);
    }
}

void calculator::on_pushButton_approve_M_clicked()
{
    if(getManualModeTypeSelected() == 1)
    {
//        dialogbox_yesno_generic *box = new dialogbox_yesno_generic;
//        box->setAttribute(Qt::WA_DeleteOnClose);
//        box->setDialogBoxType("ApproveCalculations");
//        box->setWarningText1("Czy na pewno chcesz zaakceptować wynik? Kliknięcie TAK sprawi, że efekty obliczeń zostaną wprowadzone (skutecznie zaatakowany cel otrzyma obrażenia itd). Jeżeli nie chcesz zapisywać efektów i dodać je ręcznie (lub zmienić obliczenia), kliknij NIE, a następnie ODRZUĆ na dole strony.");
//        box->setWarningText2("Wprowadzić zmiany?");
//        connect(box,SIGNAL(YesNoSignal(bool)),this,SLOT(CalculationsApproved(bool)));
//        box->show();
        CalculationsApproved(true);
        ui->textEdit_turn_1->clear();
        ui->pushButton_approve_M->setEnabled(false);
        ui->pushButton_disapprove_M->setEnabled(false);
        ui->tabWidget_calculation_type->setEnabled(true);
        ui->tabWidget_manual_type->setEnabled(true);

    }
    else
    {
        ui->textEdit_turn_1->clear();
        ui->pushButton_approve_M->setEnabled(false);
        ui->pushButton_disapprove_M->setEnabled(false);
        ui->tabWidget_calculation_type->setEnabled(true);
        ui->tabWidget_manual_type->setEnabled(true);
    }

}

void calculator::on_pushButton_disapprove_M_clicked()
{
    ui->textEdit_turn_1->clear();
    ui->pushButton_approve_M->setEnabled(false);
    ui->pushButton_disapprove_M->setEnabled(false);
    ui->tabWidget_calculation_type->setEnabled(true);
    ui->tabWidget_manual_type->setEnabled(true);
}
