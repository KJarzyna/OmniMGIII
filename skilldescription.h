#ifndef C_SKILLDESCRIPTION_H
#define C_SKILLDESCRIPTION_H
#include <QString>

class C_SkillDescription
{
public:
    C_SkillDescription();

    int getID()const {return ID;}
    QString getSkillDescriptionFromSkillLevel(QString level) const;
    QString getSkillBaseDescription()const {return Base;}

    int ID;
    QString Base;
    QString Level1;
    QString Level2;
    QString Level3;
    QString Level4A;
    QString Level4B;
    QString Level5A;
    QString Level5B;
    QString Level6A;
    QString Level6B;

};

#endif // C_SKILLDESCRIPTION_H
