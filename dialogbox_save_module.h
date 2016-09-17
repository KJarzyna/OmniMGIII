#ifndef DIALOGBOX_SAVE_MODULE_H
#define DIALOGBOX_SAVE_MODULE_H

#include <QFrame>

namespace Ui {
class dialogbox_save_module;
}

class dialogbox_save_module : public QFrame
{
    Q_OBJECT

public:
    explicit dialogbox_save_module(QWidget *parent = 0);
    ~dialogbox_save_module();

    void SetToSwitchModule();
    void SetToExit();

signals:
    void SaveSignal(bool);

private slots:
    void on_pushButton_yes_clicked();

    void on_pushButton_no_clicked();

private:
    Ui::dialogbox_save_module *ui;

};

#endif // DIALOGBOX_SAVE_MODULE_H
