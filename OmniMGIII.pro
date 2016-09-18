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
    dialogbox_activeeffect.cpp \
    Sources/ClassDefinitions/activeeffect.cpp \
    Sources/ClassDefinitions/playeractiveeffect.cpp \
    mainwindow-effects.cpp \
    dialogbox_save_module.cpp \
    calculator.cpp \
    calculator-actions.cpp \
    dialogbox_difficultyreason.cpp \
    dialogbox_action.cpp

HEADERS  += mainwindow.h \
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
    dialogbox_activeeffect.h \
    Headers/ActiveEffects/activeeffect.h \
    Headers/Player/playeractiveeffect.h \
    dialogbox_save_module.h \
    calculator.h \
    calculator-actions.h \
    dialogbox_difficultyreason.h \
    dialogbox_action.h


FORMS    += mainwindow.ui \
    dialogbox_activeeffect.ui \
    dialogbox_save_module.ui \
    calculator.ui \
    dialogbox_difficultyreason.ui \
    dialogbox_action.ui

RESOURCES += \
    resources.qrc
RC_ICONS = mainicon.ico

DISTFILES += \
    Data/armors.xlsx \
    Data/generators.xlsx \
    Data/player_actions.xlsx \
    Data/player_equipement.xlsx \
    Data/players.xlsx \
    Data/possible_basic_actions.xlsx \
    Data/skills.xlsx \
    Data/weapons.xlsx \
    Resources/checkbox.png \
    Resources/down_arrow.png \
    Resources/handle.png \
    me_icon.png \
    mainicon.ico

SUBDIRS += \
