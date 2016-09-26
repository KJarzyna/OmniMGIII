#ifndef DIALOGBOX_WARNING_GENERIC_H
#define DIALOGBOX_WARNING_GENERIC_H

#include <QFrame>

namespace Ui {
class dialogbox_warning_generic;
}

class dialogbox_warning_generic : public QFrame
{
    Q_OBJECT

public:
    explicit dialogbox_warning_generic(QWidget *parent = 0);
    ~dialogbox_warning_generic();

    void setWarningLabel(QString text);

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialogbox_warning_generic *ui;
};

#endif // DIALOGBOX_WARNING_GENERIC_H
