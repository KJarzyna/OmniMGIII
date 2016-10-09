#ifndef DIALOGBOX_POSTCALCULATION_H
#define DIALOGBOX_POSTCALCULATION_H

#include <QFrame>

namespace Ui {
class dialogbox_postcalculation;
}

class dialogbox_postcalculation : public QFrame
{
    Q_OBJECT

public:
    explicit dialogbox_postcalculation(QWidget *parent = 0);
    ~dialogbox_postcalculation();

    void InitializeDices(int num);

signals:
    void DiceResults(QVector<int>);
    void DialogBoxClosed();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialogbox_postcalculation *ui;

};

#endif // DIALOGBOX_POSTCALCULATION_H
