#ifndef DIALOGBOX_YESNO_GENERIC_H
#define DIALOGBOX_YESNO_GENERIC_H

#include <QFrame>
#include <QString>

namespace Ui {
class dialogbox_yesno_generic;
}

class dialogbox_yesno_generic : public QFrame
{
    Q_OBJECT

public:
    explicit dialogbox_yesno_generic(QWidget *parent = 0);
    ~dialogbox_yesno_generic();

    //void SetToSwitchModule();
    //void SetToExit();
    void setDialogBoxType(QString type);
    void setWarningText1(QString text);
    void setWarningText2(QString text);
    QString getDialogBoxType();

signals:
    void YesNoSignal(bool);
    void TypeSignal(QString);

private slots:
    void on_pushButton_yes_clicked();
    void on_pushButton_no_clicked();

private:
    Ui::dialogbox_yesno_generic *ui;
    QString DB_Type;

};

#endif // DIALOGBOX_YESNO_GENERIC_H
