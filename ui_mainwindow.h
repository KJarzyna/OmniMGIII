/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionZapisz;
    QAction *actionO_programie;
    QAction *actionOmni_Kalkulator;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_name_player;
    QLineEdit *lineEdit_player_name;
    QLabel *label_class_player;
    QLineEdit *lineEdit_player_class;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_shield;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_shield_current;
    QLabel *label_5;
    QLineEdit *lineEdit_shield_full;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_armor_current;
    QLabel *label_6;
    QLineEdit *lineEdit_armor_full;
    QLabel *label_armor;
    QListWidget *listWidget_player_conditions;
    QLabel *label_activeeffect;
    QPushButton *pushButton_add_activeEffect;
    QGroupBox *groupBox_6;
    QTableWidget *tableWidget_skills;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_skill_chance;
    QFormLayout *formLayout_2;
    QLabel *label_skill_bojowe;
    QLineEdit *lineEdit_skill_calcvalue_bojowe;
    QLabel *label_skill_biotyczne;
    QLineEdit *lineEdit_skill_calcvalue_biotyczne;
    QLabel *label_skill_technologiczne;
    QLineEdit *lineEdit_skill_calcvalue_technologiczne;
    QPushButton *pushButton_calculate_skills;
    QGroupBox *groupBox_7;
    QTableWidget *tableWidget_weapons;
    QGroupBox *groupBox_8;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_omnikey;
    QComboBox *comboBox_omnikey_name;
    QLabel *label_omnikey_submod;
    QComboBox *comboBox_omnikey_submod_name;
    QLabel *label_omniblade;
    QComboBox *comboBox_omniblade_type;
    QLabel *label_omniblade_mod;
    QComboBox *comboBox_omniblade_mod_name;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_mod_armor;
    QListWidget *listWidget_armormods_list;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_armor_list;
    QListWidget *listWidget_armors_list;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_armor_list_2;
    QTableWidget *tableWidget_generators;
    QPushButton *pushButton_reloadAll;
    QTableWidget *tableWidget_wpn_ammo;
    QWidget *tab_2;
    QComboBox *comboBox_player_race;
    QLabel *label_class_player_2;
    QLabel *label_race_player;
    QComboBox *comboBox_player_type;
    QPushButton *pushButton_deletePlayer;
    QGroupBox *groupBox;
    QPushButton *pushButton_skill_remove;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_skill_level;
    QComboBox *comboBox_skill_level;
    QPushButton *pushButton_skill_add;
    QTreeWidget *treeWidget_skill_list;
    QTableWidget *tableWidget_skills_preview;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_mod_remove;
    QPushButton *pushButton_weapon_remove;
    QTreeWidget *treeWidget_weapon_list;
    QPushButton *pushButton_weapon_add;
    QTreeWidget *treeWidget_wpnmod_list;
    QPushButton *pushButton_mod_add;
    QTableWidget *tableWidget_weapons_preview;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_armor_remove;
    QTreeWidget *treeWidget_armor_list;
    QPushButton *pushButton_armor_add;
    QPushButton *pushButton_mod_armor_remove;
    QComboBox *comboBox_mod_armor_name;
    QPushButton *pushButton_mod_armor_add;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_generator_remove;
    QComboBox *comboBox_generator_name;
    QPushButton *pushButton_generator_add;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_title;
    QLabel *label_subtitle;
    QComboBox *comboBox_select_player;
    QPushButton *pushButton_addNewPlayer;
    QCheckBox *checkBox_show_details;
    QMenuBar *menuBar;
    QMenu *menuPlik;
    QMenu *menuO_programie;
    QMenu *menuModu_y;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1260, 879);
        MainWindow->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"     border: 1px solid black;\n"
"     background-color: #ffa02f;\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     \n"
"	color: #000000\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QWidget:item:hover\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #ca0619);\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:item:selected\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"    background: transparent;\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"    background: #444;\n"
"    border: 1px solid #000;\n"
"    background-color: QLinearGradient(\n"
"        x1:0, y1:0,\n"
"        x2:0, y2:1,\n"
"        stop:1 #212121,\n"
"        stop:0.4 #343434/*,\n"
"        stop"
                        ":0.2 #343434,\n"
"        stop:0.1 #ffaa00*/\n"
"    );\n"
"    margin-bottom:-1px;\n"
"    padding-bottom:1px;\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"    border: 1px solid #000;\n"
"}\n"
"\n"
"QMenu::item\n"
"{\n"
"    padding: 2px 20px 2px 20px;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:disabled\n"
"{\n"
"    color: #404040;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QAbstractItemView\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0.1 #646464, stop: 1 #5d5d5d);\n"
"}\n"
"\n"
"QWidget:focus\n"
"{\n"
"    /*border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);*/\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0 #646464, stop: 1 #5d5d5d);\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"    color:"
                        " #b1b1b1;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-width: 1px;\n"
"    border-color: #1e1e1e;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    font-size: 12px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"    selection-background-color: #ffaa00;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QComboBox:hover,QPushButton:hover\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0,"
                        " y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"\n"
"QComboBox:on\n"
"{\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"    selection-background-color: #ffaa00;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    border: 2px solid darkgray;\n"
"    selection-background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     border-left-width: 0px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"     image: url(:/images/"
                        "down_arrow.png);\n"
"}\n"
"\n"
"QGroupBox:focus\n"
"{\n"
"border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QTextEdit:focus\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"     border: 1px solid #222222;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"     height: 7px;\n"
"     margin: 0px 16px 0 16px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
""
                        "      subcontrol-position: right;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"      width: 7px;\n"
"      margin: 16px 0 16px 0;\n"
"      border: 1px solid #222222;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"      background: "
                        "QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      height: 14px;\n"
"      subcontrol-position: bottom;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #d7801a, stop: 1 #ffa02f);\n"
"      height: 14px;\n"
"      subcontrol-position: top;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-pa"
                        "ge:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"	font-size: 10pt;\n"
"	font-family: \"Segoe UI\", Arial, sans-serif;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox:disabled\n"
"{\n"
"color: #414141;\n"
"}\n"
"\n"
"QDockWidget::title\n"
"{\n"
"    text-align: center;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button, QDockWidget::float-button\n"
"{\n"
"    text-align: center;\n"
"    spacing: 1px; /* spacing betw"
                        "een items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover\n"
"{\n"
"    background: #242424;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed, QDockWidget::float-button:pressed\n"
"{\n"
"    padding: 1px -1px -1px 1px;\n"
"}\n"
"\n"
"QMainWindow::separator\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #4c4c4c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QMainWindow::separator:hover\n"
"{\n"
"\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d7801a, stop:0.5 #b56c17 stop:1 #ffa02f);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"    spacing: 3px; /* spacing between items in t"
                        "he tool bar */\n"
"}\n"
"\n"
"QToolBar::handle\n"
"{\n"
"     spacing: 3px; /* spacing between items in the tool bar */\n"
"     background: url(:/images/handle.png);\n"
"}\n"
"\n"
"QMenu::separator\n"
"{\n"
"    height: 2px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QProgressBar\n"
"{\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"    background-color: #d7801a;\n"
"    width: 2.15px;\n"
"    margin: 0.5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    color: #b1b1b1;\n"
"    border: 1px solid #444;\n"
"    border-bottom-style: none;\n"
"    background-color: #323232;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 3px;\n"
"    padding-bottom: 2px;\n"
"    margin-right: -1px;\n"
"}\n"
"\n"
"QTab"
                        "Widget::pane {\n"
"    border: 1px solid #444;\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:last\n"
"{\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"    border-top-right-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:first:!selected\n"
"{\n"
" margin-left: 0px; /* the last selected tab has nothing to overlap with on the right */\n"
"\n"
"\n"
"    border-top-left-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"    color: #b1b1b1;\n"
"    border-bottom-style: solid;\n"
"    margin-top: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:.4 #343434);\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    margin-bottom: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover\n"
"{\n"
"    /*border-top: 2px solid #ffaa00;\n"
"    padding-bottom: 3px;*/\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    background-color: QL"
                        "inearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:0.4 #343434, stop:0.2 #343434, stop:0.1 #ffaa00);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked, QRadioButton::indicator:unchecked{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"    background-color: qradialgradient(\n"
"        cx: 0.5, cy: 0.5,\n"
"        fx: 0.5, fy: 0.5,\n"
"        radius: 1.0,\n"
"        stop: 0.25 #ffaa00,\n"
"        stop: 0.3 #323232\n"
"    );\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    width: 9px;\n"
"    height: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator\n"
"{\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover, QCheckBox::indicator:hover\n"
"{\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/images/checkbox.png);\n"
"}\n"
""
                        "\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled\n"
"{\n"
"    border: 1px solid #444;\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"}"));
        actionZapisz = new QAction(MainWindow);
        actionZapisz->setObjectName(QString::fromUtf8("actionZapisz"));
        actionO_programie = new QAction(MainWindow);
        actionO_programie->setObjectName(QString::fromUtf8("actionO_programie"));
        actionOmni_Kalkulator = new QAction(MainWindow);
        actionOmni_Kalkulator->setObjectName(QString::fromUtf8("actionOmni_Kalkulator"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 60, 1211, 751));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        formLayoutWidget = new QWidget(tab_1);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 20, 351, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_name_player = new QLabel(formLayoutWidget);
        label_name_player->setObjectName(QString::fromUtf8("label_name_player"));
        label_name_player->setEnabled(true);
        QFont font;
        font.setPointSize(10);
        label_name_player->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name_player);

        lineEdit_player_name = new QLineEdit(formLayoutWidget);
        lineEdit_player_name->setObjectName(QString::fromUtf8("lineEdit_player_name"));
        lineEdit_player_name->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_player_name);

        label_class_player = new QLabel(formLayoutWidget);
        label_class_player->setObjectName(QString::fromUtf8("label_class_player"));
        label_class_player->setEnabled(true);
        label_class_player->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_class_player);

        lineEdit_player_class = new QLineEdit(formLayoutWidget);
        lineEdit_player_class->setObjectName(QString::fromUtf8("lineEdit_player_class"));
        lineEdit_player_class->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_player_class);

        gridLayoutWidget = new QWidget(tab_1);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 90, 311, 51));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(15);
        gridLayout->setVerticalSpacing(4);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_shield = new QLabel(gridLayoutWidget);
        label_shield->setObjectName(QString::fromUtf8("label_shield"));
        label_shield->setFont(font);
        label_shield->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_shield, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_shield_current = new QLineEdit(gridLayoutWidget);
        lineEdit_shield_current->setObjectName(QString::fromUtf8("lineEdit_shield_current"));
        lineEdit_shield_current->setFont(font);
        lineEdit_shield_current->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_shield_current);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout->addWidget(label_5);

        lineEdit_shield_full = new QLineEdit(gridLayoutWidget);
        lineEdit_shield_full->setObjectName(QString::fromUtf8("lineEdit_shield_full"));
        lineEdit_shield_full->setFont(font);
        lineEdit_shield_full->setAlignment(Qt::AlignCenter);
        lineEdit_shield_full->setReadOnly(false);

        horizontalLayout->addWidget(lineEdit_shield_full);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_armor_current = new QLineEdit(gridLayoutWidget);
        lineEdit_armor_current->setObjectName(QString::fromUtf8("lineEdit_armor_current"));
        lineEdit_armor_current->setFont(font);
        lineEdit_armor_current->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_armor_current);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_2->addWidget(label_6);

        lineEdit_armor_full = new QLineEdit(gridLayoutWidget);
        lineEdit_armor_full->setObjectName(QString::fromUtf8("lineEdit_armor_full"));
        lineEdit_armor_full->setFont(font);
        lineEdit_armor_full->setAlignment(Qt::AlignCenter);
        lineEdit_armor_full->setReadOnly(false);

        horizontalLayout_2->addWidget(lineEdit_armor_full);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        label_armor = new QLabel(gridLayoutWidget);
        label_armor->setObjectName(QString::fromUtf8("label_armor"));
        label_armor->setFont(font);
        label_armor->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_armor, 0, 1, 1, 1);

        listWidget_player_conditions = new QListWidget(tab_1);
        listWidget_player_conditions->setObjectName(QString::fromUtf8("listWidget_player_conditions"));
        listWidget_player_conditions->setGeometry(QRect(110, 170, 171, 91));
        listWidget_player_conditions->setFont(font);
        listWidget_player_conditions->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget_player_conditions->setTextElideMode(Qt::ElideLeft);
        listWidget_player_conditions->setFlow(QListView::TopToBottom);
        label_activeeffect = new QLabel(tab_1);
        label_activeeffect->setObjectName(QString::fromUtf8("label_activeeffect"));
        label_activeeffect->setGeometry(QRect(130, 150, 132, 16));
        label_activeeffect->setFont(font);
        label_activeeffect->setAlignment(Qt::AlignCenter);
        pushButton_add_activeEffect = new QPushButton(tab_1);
        pushButton_add_activeEffect->setObjectName(QString::fromUtf8("pushButton_add_activeEffect"));
        pushButton_add_activeEffect->setGeometry(QRect(170, 270, 51, 21));
        QFont font1;
        pushButton_add_activeEffect->setFont(font1);
        groupBox_6 = new QGroupBox(tab_1);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(410, 10, 791, 241));
        tableWidget_skills = new QTableWidget(groupBox_6);
        if (tableWidget_skills->columnCount() < 4)
            tableWidget_skills->setColumnCount(4);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        tableWidget_skills->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        tableWidget_skills->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        tableWidget_skills->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        tableWidget_skills->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_skills->setObjectName(QString::fromUtf8("tableWidget_skills"));
        tableWidget_skills->setGeometry(QRect(10, 30, 521, 191));
        tableWidget_skills->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget_skills->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_skills->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_skills->setShowGrid(false);
        verticalLayoutWidget = new QWidget(groupBox_6);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(550, 30, 205, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_skill_chance = new QLabel(verticalLayoutWidget);
        label_skill_chance->setObjectName(QString::fromUtf8("label_skill_chance"));
        label_skill_chance->setFont(font2);

        verticalLayout->addWidget(label_skill_chance);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_skill_bojowe = new QLabel(verticalLayoutWidget);
        label_skill_bojowe->setObjectName(QString::fromUtf8("label_skill_bojowe"));
        label_skill_bojowe->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_skill_bojowe);

        lineEdit_skill_calcvalue_bojowe = new QLineEdit(verticalLayoutWidget);
        lineEdit_skill_calcvalue_bojowe->setObjectName(QString::fromUtf8("lineEdit_skill_calcvalue_bojowe"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        lineEdit_skill_calcvalue_bojowe->setFont(font3);
        lineEdit_skill_calcvalue_bojowe->setAutoFillBackground(false);
        lineEdit_skill_calcvalue_bojowe->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0);\n"
"color: orange;"));
        lineEdit_skill_calcvalue_bojowe->setAlignment(Qt::AlignCenter);
        lineEdit_skill_calcvalue_bojowe->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_skill_calcvalue_bojowe);

        label_skill_biotyczne = new QLabel(verticalLayoutWidget);
        label_skill_biotyczne->setObjectName(QString::fromUtf8("label_skill_biotyczne"));
        label_skill_biotyczne->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_skill_biotyczne);

        lineEdit_skill_calcvalue_biotyczne = new QLineEdit(verticalLayoutWidget);
        lineEdit_skill_calcvalue_biotyczne->setObjectName(QString::fromUtf8("lineEdit_skill_calcvalue_biotyczne"));
        lineEdit_skill_calcvalue_biotyczne->setFont(font3);
        lineEdit_skill_calcvalue_biotyczne->setAutoFillBackground(false);
        lineEdit_skill_calcvalue_biotyczne->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0);\n"
"color: orange;"));
        lineEdit_skill_calcvalue_biotyczne->setAlignment(Qt::AlignCenter);
        lineEdit_skill_calcvalue_biotyczne->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_skill_calcvalue_biotyczne);

        label_skill_technologiczne = new QLabel(verticalLayoutWidget);
        label_skill_technologiczne->setObjectName(QString::fromUtf8("label_skill_technologiczne"));
        label_skill_technologiczne->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_skill_technologiczne);

        lineEdit_skill_calcvalue_technologiczne = new QLineEdit(verticalLayoutWidget);
        lineEdit_skill_calcvalue_technologiczne->setObjectName(QString::fromUtf8("lineEdit_skill_calcvalue_technologiczne"));
        lineEdit_skill_calcvalue_technologiczne->setFont(font3);
        lineEdit_skill_calcvalue_technologiczne->setAutoFillBackground(false);
        lineEdit_skill_calcvalue_technologiczne->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0);\n"
"color: orange;"));
        lineEdit_skill_calcvalue_technologiczne->setAlignment(Qt::AlignCenter);
        lineEdit_skill_calcvalue_technologiczne->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEdit_skill_calcvalue_technologiczne);


        verticalLayout->addLayout(formLayout_2);

        pushButton_calculate_skills = new QPushButton(groupBox_6);
        pushButton_calculate_skills->setObjectName(QString::fromUtf8("pushButton_calculate_skills"));
        pushButton_calculate_skills->setGeometry(QRect(620, 160, 75, 23));
        pushButton_calculate_skills->setFont(font1);
        groupBox_7 = new QGroupBox(tab_1);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(410, 270, 791, 161));
        tableWidget_weapons = new QTableWidget(groupBox_7);
        if (tableWidget_weapons->columnCount() < 9)
            tableWidget_weapons->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        tableWidget_weapons->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        tableWidget_weapons->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        tableWidget_weapons->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font2);
        tableWidget_weapons->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font2);
        tableWidget_weapons->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font2);
        tableWidget_weapons->setHorizontalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font2);
        tableWidget_weapons->setHorizontalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font2);
        tableWidget_weapons->setHorizontalHeaderItem(7, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font2);
        tableWidget_weapons->setHorizontalHeaderItem(8, __qtablewidgetitem12);
        tableWidget_weapons->setObjectName(QString::fromUtf8("tableWidget_weapons"));
        tableWidget_weapons->setGeometry(QRect(10, 30, 771, 111));
        tableWidget_weapons->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_weapons->setDragEnabled(false);
        tableWidget_weapons->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_weapons->setShowGrid(false);
        tableWidget_weapons->setCornerButtonEnabled(true);
        tableWidget_weapons->horizontalHeader()->setDefaultSectionSize(175);
        groupBox_8 = new QGroupBox(tab_1);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 450, 1191, 251));
        verticalLayoutWidget_5 = new QWidget(groupBox_8);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(930, 20, 241, 212));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_omnikey = new QLabel(verticalLayoutWidget_5);
        label_omnikey->setObjectName(QString::fromUtf8("label_omnikey"));
        label_omnikey->setFont(font2);
        label_omnikey->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_omnikey);

        comboBox_omnikey_name = new QComboBox(verticalLayoutWidget_5);
        comboBox_omnikey_name->setObjectName(QString::fromUtf8("comboBox_omnikey_name"));
        comboBox_omnikey_name->setFont(font);

        verticalLayout_5->addWidget(comboBox_omnikey_name);

        label_omnikey_submod = new QLabel(verticalLayoutWidget_5);
        label_omnikey_submod->setObjectName(QString::fromUtf8("label_omnikey_submod"));
        label_omnikey_submod->setFont(font2);
        label_omnikey_submod->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_omnikey_submod);

        comboBox_omnikey_submod_name = new QComboBox(verticalLayoutWidget_5);
        comboBox_omnikey_submod_name->setObjectName(QString::fromUtf8("comboBox_omnikey_submod_name"));
        comboBox_omnikey_submod_name->setFont(font);

        verticalLayout_5->addWidget(comboBox_omnikey_submod_name);

        label_omniblade = new QLabel(verticalLayoutWidget_5);
        label_omniblade->setObjectName(QString::fromUtf8("label_omniblade"));
        label_omniblade->setFont(font2);
        label_omniblade->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_omniblade);

        comboBox_omniblade_type = new QComboBox(verticalLayoutWidget_5);
        comboBox_omniblade_type->setObjectName(QString::fromUtf8("comboBox_omniblade_type"));
        comboBox_omniblade_type->setFont(font);

        verticalLayout_5->addWidget(comboBox_omniblade_type);

        label_omniblade_mod = new QLabel(verticalLayoutWidget_5);
        label_omniblade_mod->setObjectName(QString::fromUtf8("label_omniblade_mod"));
        label_omniblade_mod->setFont(font2);
        label_omniblade_mod->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_omniblade_mod);

        comboBox_omniblade_mod_name = new QComboBox(verticalLayoutWidget_5);
        comboBox_omniblade_mod_name->setObjectName(QString::fromUtf8("comboBox_omniblade_mod_name"));
        comboBox_omniblade_mod_name->setFont(font);

        verticalLayout_5->addWidget(comboBox_omniblade_mod_name);

        verticalLayoutWidget_4 = new QWidget(groupBox_8);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(680, 20, 231, 99));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_mod_armor = new QLabel(verticalLayoutWidget_4);
        label_mod_armor->setObjectName(QString::fromUtf8("label_mod_armor"));
        label_mod_armor->setFont(font2);
        label_mod_armor->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_mod_armor);

        listWidget_armormods_list = new QListWidget(verticalLayoutWidget_4);
        listWidget_armormods_list->setObjectName(QString::fromUtf8("listWidget_armormods_list"));

        verticalLayout_4->addWidget(listWidget_armormods_list);

        verticalLayoutWidget_3 = new QWidget(groupBox_8);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(410, 20, 251, 181));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_armor_list = new QLabel(verticalLayoutWidget_3);
        label_armor_list->setObjectName(QString::fromUtf8("label_armor_list"));
        label_armor_list->setFont(font2);
        label_armor_list->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_armor_list);

        listWidget_armors_list = new QListWidget(verticalLayoutWidget_3);
        listWidget_armors_list->setObjectName(QString::fromUtf8("listWidget_armors_list"));
        listWidget_armors_list->setTextElideMode(Qt::ElideMiddle);

        verticalLayout_3->addWidget(listWidget_armors_list);

        verticalLayoutWidget_2 = new QWidget(groupBox_8);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 19, 381, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_armor_list_2 = new QLabel(verticalLayoutWidget_2);
        label_armor_list_2->setObjectName(QString::fromUtf8("label_armor_list_2"));
        label_armor_list_2->setFont(font2);
        label_armor_list_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_armor_list_2);

        tableWidget_generators = new QTableWidget(verticalLayoutWidget_2);
        if (tableWidget_generators->columnCount() < 5)
            tableWidget_generators->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font2);
        tableWidget_generators->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font2);
        tableWidget_generators->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font2);
        tableWidget_generators->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font2);
        tableWidget_generators->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font2);
        tableWidget_generators->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        tableWidget_generators->setObjectName(QString::fromUtf8("tableWidget_generators"));
        tableWidget_generators->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_generators->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_generators->setShowGrid(false);
        tableWidget_generators->horizontalHeader()->setDefaultSectionSize(175);

        verticalLayout_2->addWidget(tableWidget_generators);

        pushButton_reloadAll = new QPushButton(tab_1);
        pushButton_reloadAll->setObjectName(QString::fromUtf8("pushButton_reloadAll"));
        pushButton_reloadAll->setGeometry(QRect(140, 400, 111, 21));
        pushButton_reloadAll->setFont(font1);
        tableWidget_wpn_ammo = new QTableWidget(tab_1);
        if (tableWidget_wpn_ammo->columnCount() < 2)
            tableWidget_wpn_ammo->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font2);
        tableWidget_wpn_ammo->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font2);
        tableWidget_wpn_ammo->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        tableWidget_wpn_ammo->setObjectName(QString::fromUtf8("tableWidget_wpn_ammo"));
        tableWidget_wpn_ammo->setGeometry(QRect(90, 310, 211, 81));
        tableWidget_wpn_ammo->setEditTriggers(QAbstractItemView::DoubleClicked);
        tableWidget_wpn_ammo->setShowGrid(false);
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        comboBox_player_race = new QComboBox(tab_2);
        comboBox_player_race->setObjectName(QString::fromUtf8("comboBox_player_race"));
        comboBox_player_race->setGeometry(QRect(70, 20, 233, 22));
        comboBox_player_race->setFont(font);
        comboBox_player_race->setContextMenuPolicy(Qt::DefaultContextMenu);
        comboBox_player_race->setStyleSheet(QString::fromUtf8(""));
        label_class_player_2 = new QLabel(tab_2);
        label_class_player_2->setObjectName(QString::fromUtf8("label_class_player_2"));
        label_class_player_2->setEnabled(true);
        label_class_player_2->setGeometry(QRect(24, 50, 23, 22));
        label_class_player_2->setFont(font);
        label_race_player = new QLabel(tab_2);
        label_race_player->setObjectName(QString::fromUtf8("label_race_player"));
        label_race_player->setEnabled(true);
        label_race_player->setGeometry(QRect(24, 20, 31, 22));
        label_race_player->setFont(font);
        comboBox_player_type = new QComboBox(tab_2);
        comboBox_player_type->addItem(QString());
        comboBox_player_type->addItem(QString());
        comboBox_player_type->setObjectName(QString::fromUtf8("comboBox_player_type"));
        comboBox_player_type->setGeometry(QRect(70, 50, 233, 22));
        comboBox_player_type->setFont(font);
        comboBox_player_type->setContextMenuPolicy(Qt::DefaultContextMenu);
        comboBox_player_type->setStyleSheet(QString::fromUtf8(""));
        pushButton_deletePlayer = new QPushButton(tab_2);
        pushButton_deletePlayer->setObjectName(QString::fromUtf8("pushButton_deletePlayer"));
        pushButton_deletePlayer->setGeometry(QRect(320, 20, 81, 23));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(620, 20, 561, 281));
        pushButton_skill_remove = new QPushButton(groupBox);
        pushButton_skill_remove->setObjectName(QString::fromUtf8("pushButton_skill_remove"));
        pushButton_skill_remove->setGeometry(QRect(120, 230, 91, 23));
        pushButton_skill_remove->setFont(font1);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 200, 116, 26));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_skill_level = new QLabel(horizontalLayoutWidget);
        label_skill_level->setObjectName(QString::fromUtf8("label_skill_level"));
        label_skill_level->setFont(font2);

        horizontalLayout_4->addWidget(label_skill_level);

        comboBox_skill_level = new QComboBox(horizontalLayoutWidget);
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->addItem(QString());
        comboBox_skill_level->setObjectName(QString::fromUtf8("comboBox_skill_level"));
        comboBox_skill_level->setFont(font);

        horizontalLayout_4->addWidget(comboBox_skill_level);

        pushButton_skill_add = new QPushButton(groupBox);
        pushButton_skill_add->setObjectName(QString::fromUtf8("pushButton_skill_add"));
        pushButton_skill_add->setGeometry(QRect(20, 230, 91, 23));
        pushButton_skill_add->setFont(font1);
        treeWidget_skill_list = new QTreeWidget(groupBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget_skill_list);
        __qtreewidgetitem->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget_skill_list);
        __qtreewidgetitem1->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem1->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget_skill_list);
        __qtreewidgetitem2->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem2->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget_skill_list);
        __qtreewidgetitem3->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem3->setFont(0, font2);
        treeWidget_skill_list->setObjectName(QString::fromUtf8("treeWidget_skill_list"));
        treeWidget_skill_list->setGeometry(QRect(20, 30, 191, 161));
        tableWidget_skills_preview = new QTableWidget(groupBox);
        if (tableWidget_skills_preview->columnCount() < 4)
            tableWidget_skills_preview->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font2);
        tableWidget_skills_preview->setHorizontalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font2);
        tableWidget_skills_preview->setHorizontalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font2);
        tableWidget_skills_preview->setHorizontalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font2);
        tableWidget_skills_preview->setHorizontalHeaderItem(3, __qtablewidgetitem23);
        tableWidget_skills_preview->setObjectName(QString::fromUtf8("tableWidget_skills_preview"));
        tableWidget_skills_preview->setGeometry(QRect(230, 30, 311, 221));
        tableWidget_skills_preview->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_skills_preview->setSelectionBehavior(QAbstractItemView::SelectRows);
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 90, 531, 341));
        pushButton_mod_remove = new QPushButton(groupBox_2);
        pushButton_mod_remove->setObjectName(QString::fromUtf8("pushButton_mod_remove"));
        pushButton_mod_remove->setGeometry(QRect(370, 300, 91, 23));
        pushButton_mod_remove->setFont(font1);
        pushButton_weapon_remove = new QPushButton(groupBox_2);
        pushButton_weapon_remove->setObjectName(QString::fromUtf8("pushButton_weapon_remove"));
        pushButton_weapon_remove->setGeometry(QRect(120, 300, 91, 23));
        pushButton_weapon_remove->setFont(font1);
        treeWidget_weapon_list = new QTreeWidget(groupBox_2);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget_weapon_list);
        __qtreewidgetitem4->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem4->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(treeWidget_weapon_list);
        __qtreewidgetitem5->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem5->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(treeWidget_weapon_list);
        __qtreewidgetitem6->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem6->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(treeWidget_weapon_list);
        __qtreewidgetitem7->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem7->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(treeWidget_weapon_list);
        __qtreewidgetitem8->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem8->setFont(0, font2);
        treeWidget_weapon_list->setObjectName(QString::fromUtf8("treeWidget_weapon_list"));
        treeWidget_weapon_list->setGeometry(QRect(20, 130, 191, 161));
        pushButton_weapon_add = new QPushButton(groupBox_2);
        pushButton_weapon_add->setObjectName(QString::fromUtf8("pushButton_weapon_add"));
        pushButton_weapon_add->setGeometry(QRect(20, 300, 91, 23));
        pushButton_weapon_add->setFont(font1);
        treeWidget_wpnmod_list = new QTreeWidget(groupBox_2);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(treeWidget_wpnmod_list);
        __qtreewidgetitem9->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem9->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem10 = new QTreeWidgetItem(treeWidget_wpnmod_list);
        __qtreewidgetitem10->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem10->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem11 = new QTreeWidgetItem(treeWidget_wpnmod_list);
        __qtreewidgetitem11->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem11->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem12 = new QTreeWidgetItem(treeWidget_wpnmod_list);
        __qtreewidgetitem12->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem12->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem13 = new QTreeWidgetItem(treeWidget_wpnmod_list);
        __qtreewidgetitem13->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem13->setFont(0, font2);
        treeWidget_wpnmod_list->setObjectName(QString::fromUtf8("treeWidget_wpnmod_list"));
        treeWidget_wpnmod_list->setGeometry(QRect(220, 130, 291, 161));
        pushButton_mod_add = new QPushButton(groupBox_2);
        pushButton_mod_add->setObjectName(QString::fromUtf8("pushButton_mod_add"));
        pushButton_mod_add->setGeometry(QRect(270, 300, 91, 23));
        pushButton_mod_add->setFont(font1);
        tableWidget_weapons_preview = new QTableWidget(groupBox_2);
        if (tableWidget_weapons_preview->columnCount() < 4)
            tableWidget_weapons_preview->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font2);
        tableWidget_weapons_preview->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font2);
        tableWidget_weapons_preview->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font2);
        tableWidget_weapons_preview->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font2);
        tableWidget_weapons_preview->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        tableWidget_weapons_preview->setObjectName(QString::fromUtf8("tableWidget_weapons_preview"));
        tableWidget_weapons_preview->setGeometry(QRect(20, 20, 491, 101));
        tableWidget_weapons_preview->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_weapons_preview->setDragEnabled(false);
        tableWidget_weapons_preview->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableWidget_weapons_preview->setCornerButtonEnabled(true);
        tableWidget_weapons_preview->horizontalHeader()->setDefaultSectionSize(175);
        tableWidget_weapons_preview->verticalHeader()->setMinimumSectionSize(15);
        tableWidget_weapons_preview->verticalHeader()->setDefaultSectionSize(20);
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(620, 320, 561, 351));
        pushButton_armor_remove = new QPushButton(groupBox_3);
        pushButton_armor_remove->setObjectName(QString::fromUtf8("pushButton_armor_remove"));
        pushButton_armor_remove->setGeometry(QRect(150, 310, 91, 23));
        pushButton_armor_remove->setFont(font1);
        treeWidget_armor_list = new QTreeWidget(groupBox_3);
        QTreeWidgetItem *__qtreewidgetitem14 = new QTreeWidgetItem(treeWidget_armor_list);
        __qtreewidgetitem14->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem14->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem15 = new QTreeWidgetItem(treeWidget_armor_list);
        __qtreewidgetitem15->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem15->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem16 = new QTreeWidgetItem(treeWidget_armor_list);
        __qtreewidgetitem16->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem16->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem17 = new QTreeWidgetItem(treeWidget_armor_list);
        __qtreewidgetitem17->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem17->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem18 = new QTreeWidgetItem(treeWidget_armor_list);
        __qtreewidgetitem18->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem18->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem19 = new QTreeWidgetItem(treeWidget_armor_list);
        __qtreewidgetitem19->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        __qtreewidgetitem19->setTextAlignment(0, Qt::AlignLeading|Qt::AlignVCenter);
        __qtreewidgetitem19->setFont(0, font2);
        treeWidget_armor_list->setObjectName(QString::fromUtf8("treeWidget_armor_list"));
        treeWidget_armor_list->setGeometry(QRect(20, 140, 251, 161));
        pushButton_armor_add = new QPushButton(groupBox_3);
        pushButton_armor_add->setObjectName(QString::fromUtf8("pushButton_armor_add"));
        pushButton_armor_add->setGeometry(QRect(50, 310, 91, 23));
        pushButton_armor_add->setFont(font1);
        pushButton_mod_armor_remove = new QPushButton(groupBox_3);
        pushButton_mod_armor_remove->setObjectName(QString::fromUtf8("pushButton_mod_armor_remove"));
        pushButton_mod_armor_remove->setGeometry(QRect(420, 170, 91, 23));
        pushButton_mod_armor_remove->setFont(font1);
        comboBox_mod_armor_name = new QComboBox(groupBox_3);
        comboBox_mod_armor_name->setObjectName(QString::fromUtf8("comboBox_mod_armor_name"));
        comboBox_mod_armor_name->setGeometry(QRect(290, 140, 251, 21));
        comboBox_mod_armor_name->setFont(font);
        pushButton_mod_armor_add = new QPushButton(groupBox_3);
        pushButton_mod_armor_add->setObjectName(QString::fromUtf8("pushButton_mod_armor_add"));
        pushButton_mod_armor_add->setGeometry(QRect(320, 170, 91, 23));
        pushButton_mod_armor_add->setFont(font1);
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 460, 531, 161));
        pushButton_generator_remove = new QPushButton(groupBox_4);
        pushButton_generator_remove->setObjectName(QString::fromUtf8("pushButton_generator_remove"));
        pushButton_generator_remove->setGeometry(QRect(270, 120, 91, 23));
        pushButton_generator_remove->setFont(font1);
        comboBox_generator_name = new QComboBox(groupBox_4);
        comboBox_generator_name->setObjectName(QString::fromUtf8("comboBox_generator_name"));
        comboBox_generator_name->setGeometry(QRect(130, 90, 249, 20));
        comboBox_generator_name->setFont(font);
        pushButton_generator_add = new QPushButton(groupBox_4);
        pushButton_generator_add->setObjectName(QString::fromUtf8("pushButton_generator_add"));
        pushButton_generator_add->setGeometry(QRect(150, 120, 91, 23));
        pushButton_generator_add->setFont(font1);
        tabWidget->addTab(tab_2, QString());
        verticalLayoutWidget_6 = new QWidget(centralWidget);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(480, 0, 251, 63));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_title = new QLabel(verticalLayoutWidget_6);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        QFont font4;
        font4.setPointSize(22);
        font4.setBold(true);
        label_title->setFont(font4);
        label_title->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_title);

        label_subtitle = new QLabel(verticalLayoutWidget_6);
        label_subtitle->setObjectName(QString::fromUtf8("label_subtitle"));
        label_subtitle->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_subtitle);

        comboBox_select_player = new QComboBox(centralWidget);
        comboBox_select_player->setObjectName(QString::fromUtf8("comboBox_select_player"));
        comboBox_select_player->setGeometry(QRect(40, 27, 221, 26));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        comboBox_select_player->setFont(font5);
        pushButton_addNewPlayer = new QPushButton(centralWidget);
        pushButton_addNewPlayer->setObjectName(QString::fromUtf8("pushButton_addNewPlayer"));
        pushButton_addNewPlayer->setGeometry(QRect(270, 30, 21, 21));
        pushButton_addNewPlayer->setFont(font1);
        checkBox_show_details = new QCheckBox(centralWidget);
        checkBox_show_details->setObjectName(QString::fromUtf8("checkBox_show_details"));
        checkBox_show_details->setGeometry(QRect(1070, 50, 151, 17));
        checkBox_show_details->setChecked(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1260, 22));
        menuPlik = new QMenu(menuBar);
        menuPlik->setObjectName(QString::fromUtf8("menuPlik"));
        menuO_programie = new QMenu(menuBar);
        menuO_programie->setObjectName(QString::fromUtf8("menuO_programie"));
        menuModu_y = new QMenu(menuBar);
        menuModu_y->setObjectName(QString::fromUtf8("menuModu_y"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPlik->menuAction());
        menuBar->addAction(menuModu_y->menuAction());
        menuBar->addAction(menuO_programie->menuAction());
        menuPlik->addAction(actionZapisz);
        menuO_programie->addAction(actionO_programie);
        menuModu_y->addAction(actionOmni_Kalkulator);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionZapisz->setText(QApplication::translate("MainWindow", "Zapisz", nullptr));
#ifndef QT_NO_TOOLTIP
        actionZapisz->setToolTip(QApplication::translate("MainWindow", "Zapisz wszystko", nullptr));
#endif // QT_NO_TOOLTIP
        actionO_programie->setText(QApplication::translate("MainWindow", "O programie...", nullptr));
        actionOmni_Kalkulator->setText(QApplication::translate("MainWindow", "Omni-Kalkulator", nullptr));
        label_name_player->setText(QApplication::translate("MainWindow", "Miano:", nullptr));
        label_class_player->setText(QApplication::translate("MainWindow", "Klasa:", nullptr));
        label_shield->setText(QApplication::translate("MainWindow", "Tarcze", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "/", nullptr));
        lineEdit_shield_full->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "/", nullptr));
        label_armor->setText(QApplication::translate("MainWindow", "Pancerz", nullptr));
        label_activeeffect->setText(QApplication::translate("MainWindow", "Aktywne efekty", nullptr));
        pushButton_add_activeEffect->setText(QApplication::translate("MainWindow", "Edytuj", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Zdolno\305\233ci", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_skills->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Nazwa", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_skills->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Poziom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_skills->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Koszt", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_skills->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Typ", nullptr));
        label_skill_chance->setText(QApplication::translate("MainWindow", "Szansa na sukces zdolno\305\233ci:", nullptr));
        label_skill_bojowe->setText(QApplication::translate("MainWindow", "Bojowej:", nullptr));
        lineEdit_skill_calcvalue_bojowe->setText(QApplication::translate("MainWindow", "0%", nullptr));
        label_skill_biotyczne->setText(QApplication::translate("MainWindow", "Biotycznej:", nullptr));
        lineEdit_skill_calcvalue_biotyczne->setText(QApplication::translate("MainWindow", "0%", nullptr));
        label_skill_technologiczne->setText(QApplication::translate("MainWindow", "Technologicznej:", nullptr));
        lineEdit_skill_calcvalue_technologiczne->setText(QApplication::translate("MainWindow", "0%", nullptr));
        pushButton_calculate_skills->setText(QApplication::translate("MainWindow", "Przelicz", nullptr));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Bro\305\204 Palna", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_weapons->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Nazwa", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_weapons->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Obra\305\274enia", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_weapons->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Celno\305\233\304\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_weapons->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Odrzut", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_weapons->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Koszt PA", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_weapons->horizontalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Ammo (Clip)", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_weapons->horizontalHeaderItem(6);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Typ", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_weapons->horizontalHeaderItem(7);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Mod 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_weapons->horizontalHeaderItem(8);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Mod 2", nullptr));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Sprz\304\231t", nullptr));
        label_omnikey->setText(QApplication::translate("MainWindow", "Omni-klucz:", nullptr));
        label_omnikey_submod->setText(QApplication::translate("MainWindow", "Sub-mod omni-klucza:", nullptr));
        label_omniblade->setText(QApplication::translate("MainWindow", "Omni-ostrze (wariant):", nullptr));
        label_omniblade_mod->setText(QApplication::translate("MainWindow", "Omni-ostrze (mod):", nullptr));
        label_mod_armor->setText(QApplication::translate("MainWindow", "Mody", nullptr));
        label_armor_list->setText(QApplication::translate("MainWindow", "Opancerzenie", nullptr));
        label_armor_list_2->setText(QApplication::translate("MainWindow", "Generator Tarcz", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_generators->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Nazwa", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_generators->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Si\305\202a tarcz", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_generators->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\305\201adunki (Max)", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_generators->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Czas regeneracji", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_generators->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Dodatkowa zdolno\305\233\304\207", nullptr));
        pushButton_reloadAll->setText(QApplication::translate("MainWindow", "Prze\305\202aduj wszystko", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_wpn_ammo->horizontalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Nazwa", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_wpn_ammo->horizontalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Pozosta\305\202o amunicji", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "Podgl\304\205d", nullptr));
        label_class_player_2->setText(QApplication::translate("MainWindow", "Typ:", nullptr));
        label_race_player->setText(QApplication::translate("MainWindow", "Rasa:", nullptr));
        comboBox_player_type->setItemText(0, QApplication::translate("MainWindow", "Gracz", nullptr));
        comboBox_player_type->setItemText(1, QApplication::translate("MainWindow", "NPC", nullptr));

        pushButton_deletePlayer->setText(QApplication::translate("MainWindow", "Usu\305\204 gracza", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Dodawanie zdolno\305\233ci", nullptr));
        pushButton_skill_remove->setText(QApplication::translate("MainWindow", "Usu\305\204", nullptr));
        label_skill_level->setText(QApplication::translate("MainWindow", "Poziom:", nullptr));
        comboBox_skill_level->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        comboBox_skill_level->setItemText(1, QApplication::translate("MainWindow", "2", nullptr));
        comboBox_skill_level->setItemText(2, QApplication::translate("MainWindow", "3", nullptr));
        comboBox_skill_level->setItemText(3, QApplication::translate("MainWindow", "4A", nullptr));
        comboBox_skill_level->setItemText(4, QApplication::translate("MainWindow", "4B", nullptr));
        comboBox_skill_level->setItemText(5, QApplication::translate("MainWindow", "5AA", nullptr));
        comboBox_skill_level->setItemText(6, QApplication::translate("MainWindow", "5AB", nullptr));
        comboBox_skill_level->setItemText(7, QApplication::translate("MainWindow", "5BA", nullptr));
        comboBox_skill_level->setItemText(8, QApplication::translate("MainWindow", "5BB", nullptr));
        comboBox_skill_level->setItemText(9, QApplication::translate("MainWindow", "6AAA", nullptr));
        comboBox_skill_level->setItemText(10, QApplication::translate("MainWindow", "6BAA", nullptr));
        comboBox_skill_level->setItemText(11, QApplication::translate("MainWindow", "6ABA", nullptr));
        comboBox_skill_level->setItemText(12, QApplication::translate("MainWindow", "6AAB", nullptr));
        comboBox_skill_level->setItemText(13, QApplication::translate("MainWindow", "6BBA", nullptr));
        comboBox_skill_level->setItemText(14, QApplication::translate("MainWindow", "6ABB", nullptr));
        comboBox_skill_level->setItemText(15, QApplication::translate("MainWindow", "6BAB", nullptr));
        comboBox_skill_level->setItemText(16, QApplication::translate("MainWindow", "6BBB", nullptr));

        pushButton_skill_add->setText(QApplication::translate("MainWindow", "Dodaj", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_skill_list->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Zdolno\305\233ci:", nullptr));

        const bool __sortingEnabled = treeWidget_skill_list->isSortingEnabled();
        treeWidget_skill_list->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_skill_list->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Biotyczne", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget_skill_list->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Bojowe", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget_skill_list->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Technologiczne", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget_skill_list->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Klasowe", nullptr));
        treeWidget_skill_list->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_skills_preview->horizontalHeaderItem(0);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Nazwa", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_skills_preview->horizontalHeaderItem(1);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Poziom", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_skills_preview->horizontalHeaderItem(2);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "Koszt", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_skills_preview->horizontalHeaderItem(3);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Typ", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Dodawanie uzbrojenia", nullptr));
        pushButton_mod_remove->setText(QApplication::translate("MainWindow", "Usu\305\204", nullptr));
        pushButton_weapon_remove->setText(QApplication::translate("MainWindow", "Usu\305\204", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget_weapon_list->headerItem();
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Bro\305\204:", nullptr));

        const bool __sortingEnabled1 = treeWidget_weapon_list->isSortingEnabled();
        treeWidget_weapon_list->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidget_weapon_list->topLevelItem(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Pistolety Ci\304\231\305\274kie", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget_weapon_list->topLevelItem(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "Pistolety Maszynowe", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget_weapon_list->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "Karabiny Szturmowe", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget_weapon_list->topLevelItem(3);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "Karabiny Wyborowe", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = treeWidget_weapon_list->topLevelItem(4);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "Strzelby", nullptr));
        treeWidget_weapon_list->setSortingEnabled(__sortingEnabled1);

        pushButton_weapon_add->setText(QApplication::translate("MainWindow", "Dodaj", nullptr));
        QTreeWidgetItem *___qtreewidgetitem11 = treeWidget_wpnmod_list->headerItem();
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "Mody:", nullptr));

        const bool __sortingEnabled2 = treeWidget_wpnmod_list->isSortingEnabled();
        treeWidget_wpnmod_list->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem12 = treeWidget_wpnmod_list->topLevelItem(0);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "Do pistolet\303\263w ci\304\231\305\274kich", nullptr));
        QTreeWidgetItem *___qtreewidgetitem13 = treeWidget_wpnmod_list->topLevelItem(1);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "Do pistolet\303\263w maszynowych", nullptr));
        QTreeWidgetItem *___qtreewidgetitem14 = treeWidget_wpnmod_list->topLevelItem(2);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWindow", "Do karabin\303\263w szturmowych", nullptr));
        QTreeWidgetItem *___qtreewidgetitem15 = treeWidget_wpnmod_list->topLevelItem(3);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MainWindow", "Do karabin\303\263w wyborowych", nullptr));
        QTreeWidgetItem *___qtreewidgetitem16 = treeWidget_wpnmod_list->topLevelItem(4);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MainWindow", "Do strzelb", nullptr));
        treeWidget_wpnmod_list->setSortingEnabled(__sortingEnabled2);

        pushButton_mod_add->setText(QApplication::translate("MainWindow", "Dodaj", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_weapons_preview->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "Nazwa", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_weapons_preview->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "Typ", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_weapons_preview->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Mod 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_weapons_preview->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "Mod 2", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Dodawanie opancerzenia", nullptr));
        pushButton_armor_remove->setText(QApplication::translate("MainWindow", "Usu\305\204", nullptr));
        QTreeWidgetItem *___qtreewidgetitem17 = treeWidget_armor_list->headerItem();
        ___qtreewidgetitem17->setText(0, QApplication::translate("MainWindow", "Elementy pancerza:", nullptr));

        const bool __sortingEnabled3 = treeWidget_armor_list->isSortingEnabled();
        treeWidget_armor_list->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem18 = treeWidget_armor_list->topLevelItem(0);
        ___qtreewidgetitem18->setText(0, QApplication::translate("MainWindow", "He\305\202my", nullptr));
        QTreeWidgetItem *___qtreewidgetitem19 = treeWidget_armor_list->topLevelItem(1);
        ___qtreewidgetitem19->setText(0, QApplication::translate("MainWindow", "Napier\305\233niki", nullptr));
        QTreeWidgetItem *___qtreewidgetitem20 = treeWidget_armor_list->topLevelItem(2);
        ___qtreewidgetitem20->setText(0, QApplication::translate("MainWindow", "Naramienniki", nullptr));
        QTreeWidgetItem *___qtreewidgetitem21 = treeWidget_armor_list->topLevelItem(3);
        ___qtreewidgetitem21->setText(0, QApplication::translate("MainWindow", "Nagolenniki", nullptr));
        QTreeWidgetItem *___qtreewidgetitem22 = treeWidget_armor_list->topLevelItem(4);
        ___qtreewidgetitem22->setText(0, QApplication::translate("MainWindow", "R\304\231kawice", nullptr));
        QTreeWidgetItem *___qtreewidgetitem23 = treeWidget_armor_list->topLevelItem(5);
        ___qtreewidgetitem23->setText(0, QApplication::translate("MainWindow", "Pancerze specjalne", nullptr));
        treeWidget_armor_list->setSortingEnabled(__sortingEnabled3);

        pushButton_armor_add->setText(QApplication::translate("MainWindow", "Dodaj", nullptr));
        pushButton_mod_armor_remove->setText(QApplication::translate("MainWindow", "Usu\305\204", nullptr));
        pushButton_mod_armor_add->setText(QApplication::translate("MainWindow", "Dodaj", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Dodawanie generatora", nullptr));
        pushButton_generator_remove->setText(QApplication::translate("MainWindow", "Usu\305\204", nullptr));
        pushButton_generator_add->setText(QApplication::translate("MainWindow", "Dodaj", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Konfiguracja", nullptr));
        label_title->setText(QApplication::translate("MainWindow", "Omni-MG 3.0", nullptr));
        label_subtitle->setText(QApplication::translate("MainWindow", "created by Vex", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_addNewPlayer->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Dodaj nowego gracza</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_addNewPlayer->setText(QApplication::translate("MainWindow", "+", nullptr));
        checkBox_show_details->setText(QApplication::translate("MainWindow", "W\305\202\304\205cz pokazywanie detali", nullptr));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", nullptr));
        menuO_programie->setTitle(QApplication::translate("MainWindow", "Pomoc", nullptr));
        menuModu_y->setTitle(QApplication::translate("MainWindow", "Modu\305\202y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
