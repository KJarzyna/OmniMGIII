#-------------------------------------------------
#
# Project created by QtCreator 2016-06-12T13:48:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OmniMGIII
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainwindow-initialization.cpp \
    mainwindow-loading.cpp \
    mainwindow-saving.cpp \
    mainwindow-skills.cpp \
    mainwindow-weapons.cpp \
    mainwindow-armors.cpp \
    mainwindow-generators.cpp \
    mainwindow-omnikeys.cpp \
    Sources/ClassDefinitions/actions.cpp \
    Sources/ClassDefinitions/armmodlist.cpp \
    Sources/ClassDefinitions/armor.cpp \
    Sources/ClassDefinitions/armorlist.cpp \
    Sources/ClassDefinitions/generatorlist.cpp \
    Sources/ClassDefinitions/generators.cpp \
    Sources/ClassDefinitions/omniblademods.cpp \
    Sources/ClassDefinitions/omniblades.cpp \
    Sources/ClassDefinitions/omnikeymods.cpp \
    Sources/ClassDefinitions/omnikeys.cpp \
    Sources/ClassDefinitions/player.cpp \
    Sources/ClassDefinitions/playerarmor.cpp \
    Sources/ClassDefinitions/playerarmormods.cpp \
    Sources/ClassDefinitions/playergenerators.cpp \
    Sources/ClassDefinitions/playeromniblademods.cpp \
    Sources/ClassDefinitions/playeromniblades.cpp \
    Sources/ClassDefinitions/playeromnikeymods.cpp \
    Sources/ClassDefinitions/playeromnikeys.cpp \
    Sources/ClassDefinitions/playerskills.cpp \
    Sources/ClassDefinitions/playerweapons.cpp \
    Sources/ClassDefinitions/readwritedata.cpp \
    Sources/ClassDefinitions/skill.cpp \
    Sources/ClassDefinitions/skilllist.cpp \
    Sources/ClassDefinitions/weapon.cpp \
    Sources/ClassDefinitions/weaponlist.cpp \
    Sources/ClassDefinitions/wpnmodlist.cpp \
    Sources/ClassDefinitions/itemmodificator.cpp \
    dialogbox_activeeffect.cpp \
    Sources/ClassDefinitions/activeeffect.cpp \
    Sources/ClassDefinitions/playeractiveeffect.cpp \
    mainwindow-effects.cpp \
    calculator.cpp \
    dialogbox_difficultyreason.cpp \
    dialogbox_action.cpp \
    calculator-actions.cpp \
    calculator-weapons.cpp \
    calculator-skills.cpp \
    calculator-player.cpp \
    dialogbox_warning_generic.cpp \
    dialogbox_postcalculation.cpp \
    calculator-initialization.cpp \
    calculator-text.cpp \
    calculator-calculationfirst.cpp \
    calculator-calculationsecond.cpp \
    dialogbox_yesno_generic.cpp \
    Sources/ClassDefinitions/skillactiveeffects.cpp \
    calculator-effects.cpp \
    calculator-manualmode.cpp \
    dialogbox_details.cpp \
    skilldescription.cpp \
    itemdescription.cpp \
    c_race.cpp

HEADERS  += mainwindow.h \
    Headers/Actions/actions.h \
    Headers/Armor/armor.h \
    Headers/Armor/armmodlist.h \
    Headers/Armor/armorlist.h \
    Headers/Generator/generatorlist.h \
    Headers/Generator/generators.h \
    Headers/Omni/omniblademods.h \
    Headers/Omni/omniblades.h \
    Headers/Omni/omnikeymods.h \
    Headers/Omni/omnikeys.h \
    Headers/Player/player.h \
    Headers/Player/playerarmor.h \
    Headers/Player/playerarmormods.h \
    Headers/Player/playergenerators.h \
    Headers/Player/playeromniblademods.h \
    Headers/Player/playeromniblades.h \
    Headers/Player/playeromnikeymods.h \
    Headers/Player/playeromnikeys.h \
    Headers/Player/playerskills.h \
    Headers/Player/playerweapons.h \
    Headers/ReadWriteData/readwritedata.h \
    Headers/Skill/skill.h \
    Headers/Skill/skilllist.h \
    Headers/Weapon/weapon.h \
    Headers/Weapon/weaponlist.h \
    Headers/Weapon/wpnmodlist.h \
    Headers/ItemModificator/itemmodificator.h \
    dialogbox_activeeffect.h \
    Headers/ActiveEffects/activeeffect.h \
    Headers/Player/playeractiveeffect.h \
    calculator.h \
    dialogbox_difficultyreason.h \
    dialogbox_action.h \
    dialogbox_warning_generic.h \
    dialogbox_postcalculation.h \
    dialogbox_yesno_generic.h \
    Headers/ActiveEffects/skillactiveeffects.h \
    dialogbox_details.h \
    skilldescription.h \
    itemdescription.h \
    race.h

FORMS    += mainwindow.ui \
    dialogbox_activeeffect.ui \
    calculator.ui \
    dialogbox_difficultyreason.ui \
    dialogbox_action.ui \
    dialogbox_warning_generic.ui \
    dialogbox_postcalculation.ui \
    dialogbox_yesno_generic.ui \
    dialogbox_details.ui

RESOURCES += \
    resources.qrc
RC_ICONS = mainicon.ico

DISTFILES += \
    Resources/checkbox.png \
    Resources/down_arrow.png \
    Resources/handle.png \
    me_icon.png \
    mainicon.ico

SUBDIRS += \
