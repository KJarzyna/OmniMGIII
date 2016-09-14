#ifndef PLAYER_H
#define PLAYER_H
#include <QString>

class C_Player
{
public:
    C_Player();

    int PlayerID;

    QString PlayerName;
    QString PlayerRace;
    QString PlayerClass;
    QString PlayerType;

    int ArmorCurrent;
    int ArmorMax;
    int ShieldCurrent;
    int ShieldMax;

    QString Status;
    QString ActiveEffects;

    QString SpecializationSkill;

    int MasteryBattle;
    int MasteryBiotic;
    int MasteryTechno;
    int MasterySpec;

};

#endif // PLAYER_H
