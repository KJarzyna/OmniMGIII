#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QFrame>
#include <QtCore>
#include <QtGui>
#include <QSpinBox>

namespace Ui {
class calculator;
}

class calculator : public QFrame
{
    Q_OBJECT

public:
    explicit calculator(QWidget *parent = 0);
    ~calculator();

    QStandardItemModel *tableModel;

private slots:
    void on_pushButton_AccMod_add_clicked();

    void on_pushButton_AccMod_remove_clicked();

    void on_pushButton_DmgMod_add_clicked();

    void on_pushButton_DmgMod_add_2_clicked();

private:
    Ui::calculator *ui;

    void InitializeDmgModTable();
    void InitializeAccModTable();
};

#endif // CALCULATOR_H
