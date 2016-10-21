#include "dialogbox_yesno_generic.h"
#include "ui_dialogbox_yesno_generic.h"

dialogbox_yesno_generic::dialogbox_yesno_generic(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::dialogbox_yesno_generic)
{
    this->setFixedSize(400,206);
    ui->setupUi(this);

    DB_Type = "NoType";
}

dialogbox_yesno_generic::~dialogbox_yesno_generic()
{
    delete ui;
}

void dialogbox_yesno_generic::setDialogBoxType(QString type)
{
    QStringList KnownTypes;
    KnownTypes.append("SaveModule");
    KnownTypes.append("ApproveCalculations");

    if(KnownTypes.filter(type).isEmpty())
        DB_Type = "NoType";
    else
        DB_Type = type;
}

QString dialogbox_yesno_generic::getDialogBoxType()
{
    return DB_Type;
}

void dialogbox_yesno_generic::setWarningText1(QString text)
{
    ui->label->setText(text);
}

void dialogbox_yesno_generic::setWarningText2(QString text)
{
    ui->label_2->setText(text);
}

void dialogbox_yesno_generic::on_pushButton_yes_clicked()
{
    emit YesNoSignal(true);

    close();
}


void dialogbox_yesno_generic::on_pushButton_no_clicked()
{
    emit YesNoSignal(false);
    close();
}
