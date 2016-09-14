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
            ui->tableWidget_generators->insertRow(ui->tableWidget_generators->rowCount());
            ui->tableWidget_generators->setItem(ui->tableWidget_generators->rowCount()-1,0,new QTableWidgetItem(Generators.at(i).GeneratorName));
            ui->tableWidget_generators->setItem(ui->tableWidget_generators->rowCount()-1,1,new QTableWidgetItem(QString::number(Generators.at(i).ShieldPower)));
            ui->tableWidget_generators->setItem(ui->tableWidget_generators->rowCount()-1,2,new QTableWidgetItem(QString::number(Generators.at(i).Charges)));
            ui->tableWidget_generators->setItem(ui->tableWidget_generators->rowCount()-1,3,new QTableWidgetItem(QString::number(Generators.at(i).Recharge)));
            ui->tableWidget_generators->setItem(ui->tableWidget_generators->rowCount()-1,4,new QTableWidgetItem(Generators.at(i).HasAbility));
        }
    }
}

void MainWindow::RemoveGeneratorFromTable()
{
    if(ui->tableWidget_generators->rowCount() >0)
    {
        int selected_row = ui->tableWidget_generators->currentRow();
        ui->tableWidget_generators->removeRow(selected_row);
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