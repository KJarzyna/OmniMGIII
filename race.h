#ifndef C_RACE_H
#define C_RACE_H
#include <QString>


class C_Race
{
public:
    C_Race();

    int ID;
    QString Name;
    int HeavyDamage;
    int LightDamage;
    int AreaDamage;
    int HitChance;
};

#endif // C_RACE_H
