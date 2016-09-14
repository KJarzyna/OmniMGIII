#ifndef DIALOGBOX_ACTIVEEFFECT_H
#define DIALOGBOX_ACTIVEEFFECT_H

#include <QFrame>
#include "Headers/ActiveEffects/activeeffect.h"
#include "Headers/Player/playeractiveeffect.h"

namespace Ui {
class DialogBox_ActiveEffect;
}

class DialogBox_ActiveEffect : public QFrame
{
    Q_OBJECT

public:
    explicit DialogBox_ActiveEffect(QWidget *parent = 0);
    ~DialogBox_ActiveEffect();

    QStringList SelectedActiveEffects;
    void AddEffectsToRightList(QVector<C_ActiveEffect> vector);
    void AddEffectsToLeftList(QVector<C_ActiveEffect> vector, QVector<C_PlayerActiveEffect> player_vector, int playerID);

signals:
    void sendActiveEffectList(QStringList);

private slots:
    void on_pushButton_confirm_clicked();

    void on_pushButton_activeEffect_FromRightToLeft_clicked();

    void on_pushButton_activeEffect_FromLeftToRight_clicked();

private:
    Ui::DialogBox_ActiveEffect *ui;

    void AddEffectFromRightToLeft();
    void AddEffectFromLeftToRight();
    QStringList ReturnSelectedEffectList();
};

#endif // DIALOGBOX_ACTIVEEFFECT_H
