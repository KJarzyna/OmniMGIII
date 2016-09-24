#ifndef DIALOGBOX_ACTION_H
#define DIALOGBOX_ACTION_H

#include <QFrame>
#include <QString>
#include <QStandardItemModel>

namespace Ui {
class dialogbox_action;
}

class dialogbox_action : public QFrame
{
    Q_OBJECT

public:
    explicit dialogbox_action(QWidget *parent = 0);
    ~dialogbox_action();

    //int selected_actionID;
    QStandardItemModel *ActionItem;

    void InitializeActionType(QString actionName);
    void InitializeActionItemModel(QStandardItemModel *model);

signals:
    void SelectedActionItem(int,QString);
    void DialogBoxClosed(bool);

private slots:

    void on_pushButton_clicked();

private:
    Ui::dialogbox_action *ui;

    void InitializeComboboxList();



};

#endif // DIALOGBOX_ACTION_H
