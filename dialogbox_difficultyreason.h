#ifndef DIALOGBOX_DIFFICULTYREASON_H
#define DIALOGBOX_DIFFICULTYREASON_H

#include <QFrame>
#include <QString>

namespace Ui {
class dialogbox_difficultyreason;
}

class dialogbox_difficultyreason : public QFrame
{
    Q_OBJECT

public:
    explicit dialogbox_difficultyreason(QWidget *parent = 0);
    ~dialogbox_difficultyreason();

signals:
    void reasonSignal(QString);


private slots:
    void on_pushButton_clicked();

private:
    Ui::dialogbox_difficultyreason *ui;
};

#endif // DIALOGBOX_DIFFICULTYREASON_H
