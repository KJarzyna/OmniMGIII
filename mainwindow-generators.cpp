#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::ClearGeneratorTable()
{
    while (ui->tableWidget_generators->rowCount() > 0)
    {
        ui->tableWidget_generators->removeRow(ui->tableWidget_generators->rowCount()-1);
    }
}

void MainWindow::AddGeneratorToTable()
{
    QString selected_generatorname;
    selected_generatorname = ui->comboBox_generator_name->currentText();

    for (int i=0; i<Generators.size(); i++)
    {
        if (Generators.at(i).GeneratorName == selected_generatorname)
        {
            int new_row = ui->tableWidget_generators->rowCount();
            ui->tableWidget_generators->insertRow(new_row);
            ui->tableWidget_generators->setItem(new_row,0,new QTableWidgetItem(Generators.at(i).GeneratorName));
            ui->tableWidget_generators->setItem(new_row,1,new QTableWidgetItem(QString::number(Generators.at(i).ShieldPower)));
            ui->tableWidget_generators->setItem(new_row,2,new QTableWidgetItem(QString::number(Generators.at(i).Recharge)));
            ui->tableWidget_generators->setItem(new_row,3,new QTableWidgetItem(Generators.at(i).HasAbility));

            ui->tableWidget_generators_preview->insertRow(new_row);
            ui->tableWidget_generators_preview->setItem(new_row,0,new QTableWidgetItem(Generators.at(i).GeneratorName));
            ui->tableWidget_generators_preview->setItem(new_row,1,new QTableWidgetItem(QString::number(Generators.at(i).ShieldPower)));
            ui->tableWidget_generators_preview->setItem(new_row,2,new QTableWidgetItem(QString::number(Generators.at(i).Recharge)));
            ui->tableWidget_generators_preview->setItem(new_row,3,new QTableWidgetItem(Generators.at(i).HasAbility));

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

void MainWindow::RemoveGeneratorFromTable()
{
    if(ui->tableWidget_generators_preview->rowCount() >0)
    {
        int selected_row = ui->tableWidget_generators_preview->currentRow();
        ui->tableWidget_generators->removeRow(selected_row);
        ui->tableWidget_generators_preview->removeRow(selected_row);
    }
}

void MainWindow::RemoveGeneratorFromPlayer(int generatorID, int playerID)
{
    for(int i=0;i<PlayerGenerators.size();i++)
    {
        if(PlayerGenerators.at(i).PlayerID == playerID && PlayerGenerators.at(i).GeneratorID == generatorID)
            PlayerGenerators.remove(i);
    }
}

void MainWindow::AddGeneratorToPlayer(int generatorID, int playerID)
{
    C_PlayerGenerators generator;
    generator.PlayerID = playerID;
    generator.GeneratorID = generatorID;
    generator.ChargesLeft = 0;
    for(int i=0;i<Generators.size();i++)
        if(Generators.at(i).GeneratorID == generatorID)
            generator.ChargesLeft = Generators.at(i).Charges;

    PlayerGenerators.append(generator);
}

int MainWindow::GetGeneratorIDFromGeneratorName(QString generatorName)
{
    int generatorID = 9999;
    for(int i=0;i<Generators.size();i++)
    {
        if(Generators.at(i).GeneratorName == generatorName )
            generatorID = Generators.at(i).GeneratorID;
    }
    return generatorID;
}

QString MainWindow::GetGeneratorNameFromGeneratorID(int generatorID)
{
    QString generatorName = "NoSuchGenerator";
    for(int i=0;i<Generators.size();i++)
    {
        if(Generators.at(i).GeneratorID == generatorID )
            generatorName = Generators.at(i).GeneratorName;
    }
    return generatorName;
}

//void MainWindow::SetGeneratorChargesToZero()
//{
//    ui->lineEdit_gen_charges_left->setText("0");
//}
