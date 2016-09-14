#ifndef GENERATORS_H
#define GENERATORS_H
#include <QString>

class C_Generators
{
public:
    C_Generators();

    int GeneratorID;
    QString GeneratorName;
    int ShieldPower;
    int Charges;
    int Recharge;
    QString HasAbility;

};

#endif // GENERATORS_H
