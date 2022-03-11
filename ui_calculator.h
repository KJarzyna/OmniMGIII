/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calculator
{
public:
    QLabel *label_title;
    QFrame *frame_center;
    QTabWidget *tabWidget_calculation_type;
    QWidget *tab;
    QPushButton *pushButton_DmgMod_add_2;
    QLabel *label_select_player;
    QTableWidget *tableWidget_AccMod;
    QComboBox *comboBox_select_player;
    QComboBox *comboBox_select_action;
    QPushButton *pushButton_DmgMod_add;
    QLabel *label_select_action;
    QPushButton *pushButton_AccMod_remove;
    QTableWidget *tableWidget_DmgMod;
    QLabel *label_select_difficultylevel;
    QLabel *label_dmgmod;
    QLabel *label_select_target;
    QComboBox *comboBox_select_difficultylevel;
    QPushButton *pushButton_AccMod_add;
    QComboBox *comboBox_select_target;
    QLabel *label_accmod;
    QWidget *tab_2;
    QTabWidget *tabWidget_manual_type;
    QWidget *tab_3;
    QPushButton *pushButton_AccMod_remove_M;
    QLabel *label_select_action_M;
    QLabel *label_select_target_M;
    QTableWidget *tableWidget_AccMod_M;
    QComboBox *comboBox_select_difficultylevel_M;
    QLabel *label_accmod_M;
    QLabel *label_select_difficultylevel_M;
    QPushButton *pushButton_AccMod_add_M;
    QLabel *label_select_player_M;
    QLineEdit *lineEdit_action_M;
    QLineEdit *lineEdit_target_M;
    QLineEdit *lineEdit_select_player_M;
    QLabel *label_select_action_cost_M;
    QComboBox *comboBox_select_actioncost_M;
    QCheckBox *checkBox_sukces_check_M;
    QLabel *label_success_chance_M;
    QSpinBox *spinBox_success_chance_M;
    QWidget *tab_4;
    QPushButton *pushButton_DmgMod_remove_M;
    QTableWidget *tableWidget_DmgMod_M;
    QPushButton *pushButton_DmgMod_add_M;
    QLabel *label_dmgmod_M;
    QLabel *label_damage_target_M;
    QLabel *label_damage_target_M_2;
    QSpinBox *spinBox_damage_M;
    QCheckBox *checkBox_ignore_shields_M;
    QComboBox *comboBox_select_player_M;
    QLineEdit *lineEdit_select_dmg_reason_M;
    QLabel *label_damage_target_M_3;
    QFrame *frame_right;
    QTextEdit *textEdit_turn_1;
    QPushButton *pushButton_copy;
    QPushButton *pushButton_continue_calculations;
    QTextEdit *textEdit_turn_2;
    QPushButton *pushButton_copy_2;
    QPushButton *pushButton_approve;
    QPushButton *pushButton_disapprove;
    QPushButton *pushButton_calculate;
    QPushButton *pushButton_approve_M;
    QPushButton *pushButton_disapprove_M;
    QFrame *frame_left_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_activeeffect;
    QListWidget *listWidget_player_conditions;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_armor;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_current_armor;
    QLabel *label_divider;
    QLabel *label_max_armor;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_shield;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_current_shield;
    QLabel *label_divider_2;
    QLabel *label_max_shield;
    QLabel *label_action_cost;
    QLabel *label_action_cost_2;
    QLabel *label_action_name;
    QLabel *label_action_name_2;
    QLabel *label_difficulty;
    QLabel *label_difficulty_2;
    QPushButton *pushButton_deleteEffect;
    QPushButton *pushButton_addEffect;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_barrier;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_current_barrier;

    void setupUi(QFrame *calculator)
    {
        if (calculator->objectName().isEmpty())
            calculator->setObjectName(QString::fromUtf8("calculator"));
        calculator->setWindowModality(Qt::ApplicationModal);
        calculator->resize(983, 676);
        calculator->setStyleSheet(QString::fromUtf8("QToolTip\n"
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
"    spacing: 1px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, st"
                        "op:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
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
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QToolBar::handle\n"
"{\n"
"     spacing: 3px; /* spacing between it"
                        "ems in the tool bar */\n"
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
"QTabWidget::pane {\n"
"    border: 1px solid #444;\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:last"
                        "\n"
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
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:0.4 #343434, stop:0.2 #343434, stop:0."
                        "1 #ffaa00);\n"
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
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled\n"
"{\n"
"    border: 1p"
                        "x solid #444;\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QSpinBox\n"
"{\n"
"background-color: #505050;\n"
"border: black;\n"
"}\n"
""));
        calculator->setFrameShape(QFrame::StyledPanel);
        calculator->setFrameShadow(QFrame::Raised);
        label_title = new QLabel(calculator);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(330, 10, 361, 41));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label_title->setFont(font);
        frame_center = new QFrame(calculator);
        frame_center->setObjectName(QString::fromUtf8("frame_center"));
        frame_center->setGeometry(QRect(211, 69, 401, 591));
        frame_center->setFrameShape(QFrame::Box);
        frame_center->setFrameShadow(QFrame::Plain);
        tabWidget_calculation_type = new QTabWidget(frame_center);
        tabWidget_calculation_type->setObjectName(QString::fromUtf8("tabWidget_calculation_type"));
        tabWidget_calculation_type->setGeometry(QRect(10, 10, 381, 571));
        tabWidget_calculation_type->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton_DmgMod_add_2 = new QPushButton(tab);
        pushButton_DmgMod_add_2->setObjectName(QString::fromUtf8("pushButton_DmgMod_add_2"));
        pushButton_DmgMod_add_2->setGeometry(QRect(210, 520, 111, 23));
        label_select_player = new QLabel(tab);
        label_select_player->setObjectName(QString::fromUtf8("label_select_player"));
        label_select_player->setGeometry(QRect(140, 0, 111, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_select_player->setFont(font1);
        tableWidget_AccMod = new QTableWidget(tab);
        if (tableWidget_AccMod->columnCount() < 2)
            tableWidget_AccMod->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_AccMod->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_AccMod->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_AccMod->setObjectName(QString::fromUtf8("tableWidget_AccMod"));
        tableWidget_AccMod->setGeometry(QRect(0, 221, 381, 111));
        tableWidget_AccMod->setFocusPolicy(Qt::NoFocus);
        tableWidget_AccMod->setStyleSheet(QString::fromUtf8("QCellWidget\n"
"{\n"
"background-color: #242424;\n"
"}"));
        tableWidget_AccMod->setSelectionBehavior(QAbstractItemView::SelectItems);
        comboBox_select_player = new QComboBox(tab);
        comboBox_select_player->setObjectName(QString::fromUtf8("comboBox_select_player"));
        comboBox_select_player->setGeometry(QRect(70, 20, 251, 22));
        QFont font2;
        font2.setPointSize(10);
        comboBox_select_player->setFont(font2);
        comboBox_select_action = new QComboBox(tab);
        comboBox_select_action->setObjectName(QString::fromUtf8("comboBox_select_action"));
        comboBox_select_action->setGeometry(QRect(70, 70, 251, 22));
        comboBox_select_action->setFont(font2);
        pushButton_DmgMod_add = new QPushButton(tab);
        pushButton_DmgMod_add->setObjectName(QString::fromUtf8("pushButton_DmgMod_add"));
        pushButton_DmgMod_add->setGeometry(QRect(60, 520, 111, 23));
        label_select_action = new QLabel(tab);
        label_select_action->setObjectName(QString::fromUtf8("label_select_action"));
        label_select_action->setGeometry(QRect(140, 50, 111, 16));
        label_select_action->setFont(font1);
        pushButton_AccMod_remove = new QPushButton(tab);
        pushButton_AccMod_remove->setObjectName(QString::fromUtf8("pushButton_AccMod_remove"));
        pushButton_AccMod_remove->setGeometry(QRect(210, 340, 111, 23));
        tableWidget_DmgMod = new QTableWidget(tab);
        if (tableWidget_DmgMod->columnCount() < 2)
            tableWidget_DmgMod->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_DmgMod->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_DmgMod->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidget_DmgMod->setObjectName(QString::fromUtf8("tableWidget_DmgMod"));
        tableWidget_DmgMod->setGeometry(QRect(0, 400, 381, 111));
        tableWidget_DmgMod->setFocusPolicy(Qt::NoFocus);
        tableWidget_DmgMod->setStyleSheet(QString::fromUtf8("QCellWidget\n"
"{\n"
"background-color: #242424;\n"
"}"));
        label_select_difficultylevel = new QLabel(tab);
        label_select_difficultylevel->setObjectName(QString::fromUtf8("label_select_difficultylevel"));
        label_select_difficultylevel->setGeometry(QRect(110, 150, 181, 16));
        label_select_difficultylevel->setFont(font1);
        label_dmgmod = new QLabel(tab);
        label_dmgmod->setObjectName(QString::fromUtf8("label_dmgmod"));
        label_dmgmod->setGeometry(QRect(70, 379, 271, 16));
        label_dmgmod->setFont(font1);
        label_select_target = new QLabel(tab);
        label_select_target->setObjectName(QString::fromUtf8("label_select_target"));
        label_select_target->setGeometry(QRect(150, 100, 81, 16));
        label_select_target->setFont(font1);
        comboBox_select_difficultylevel = new QComboBox(tab);
        comboBox_select_difficultylevel->addItem(QString());
        comboBox_select_difficultylevel->addItem(QString());
        comboBox_select_difficultylevel->addItem(QString());
        comboBox_select_difficultylevel->addItem(QString());
        comboBox_select_difficultylevel->addItem(QString());
        comboBox_select_difficultylevel->addItem(QString());
        comboBox_select_difficultylevel->addItem(QString());
        comboBox_select_difficultylevel->setObjectName(QString::fromUtf8("comboBox_select_difficultylevel"));
        comboBox_select_difficultylevel->setGeometry(QRect(70, 170, 251, 22));
        comboBox_select_difficultylevel->setFont(font2);
        pushButton_AccMod_add = new QPushButton(tab);
        pushButton_AccMod_add->setObjectName(QString::fromUtf8("pushButton_AccMod_add"));
        pushButton_AccMod_add->setGeometry(QRect(60, 340, 111, 23));
        comboBox_select_target = new QComboBox(tab);
        comboBox_select_target->setObjectName(QString::fromUtf8("comboBox_select_target"));
        comboBox_select_target->setGeometry(QRect(70, 120, 251, 22));
        comboBox_select_target->setFont(font2);
        label_accmod = new QLabel(tab);
        label_accmod->setObjectName(QString::fromUtf8("label_accmod"));
        label_accmod->setGeometry(QRect(0, 200, 381, 20));
        label_accmod->setFont(font1);
        label_accmod->setAlignment(Qt::AlignCenter);
        tabWidget_calculation_type->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget_manual_type = new QTabWidget(tab_2);
        tabWidget_manual_type->setObjectName(QString::fromUtf8("tabWidget_manual_type"));
        tabWidget_manual_type->setGeometry(QRect(10, 10, 351, 521));
        tabWidget_manual_type->setLayoutDirection(Qt::LeftToRight);
        tabWidget_manual_type->setAutoFillBackground(false);
        tabWidget_manual_type->setTabPosition(QTabWidget::North);
        tabWidget_manual_type->setDocumentMode(false);
        tabWidget_manual_type->setTabBarAutoHide(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        pushButton_AccMod_remove_M = new QPushButton(tab_3);
        pushButton_AccMod_remove_M->setObjectName(QString::fromUtf8("pushButton_AccMod_remove_M"));
        pushButton_AccMod_remove_M->setGeometry(QRect(190, 470, 111, 23));
        label_select_action_M = new QLabel(tab_3);
        label_select_action_M->setObjectName(QString::fromUtf8("label_select_action_M"));
        label_select_action_M->setGeometry(QRect(120, 60, 111, 16));
        label_select_action_M->setFont(font1);
        label_select_target_M = new QLabel(tab_3);
        label_select_target_M->setObjectName(QString::fromUtf8("label_select_target_M"));
        label_select_target_M->setGeometry(QRect(130, 160, 81, 16));
        label_select_target_M->setFont(font1);
        tableWidget_AccMod_M = new QTableWidget(tab_3);
        if (tableWidget_AccMod_M->columnCount() < 2)
            tableWidget_AccMod_M->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_AccMod_M->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_AccMod_M->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        tableWidget_AccMod_M->setObjectName(QString::fromUtf8("tableWidget_AccMod_M"));
        tableWidget_AccMod_M->setGeometry(QRect(10, 351, 331, 111));
        tableWidget_AccMod_M->setFocusPolicy(Qt::NoFocus);
        tableWidget_AccMod_M->setStyleSheet(QString::fromUtf8("QCellWidget\n"
"{\n"
"background-color: #242424;\n"
"}"));
        tableWidget_AccMod_M->setSelectionBehavior(QAbstractItemView::SelectItems);
        comboBox_select_difficultylevel_M = new QComboBox(tab_3);
        comboBox_select_difficultylevel_M->addItem(QString());
        comboBox_select_difficultylevel_M->addItem(QString());
        comboBox_select_difficultylevel_M->addItem(QString());
        comboBox_select_difficultylevel_M->addItem(QString());
        comboBox_select_difficultylevel_M->addItem(QString());
        comboBox_select_difficultylevel_M->addItem(QString());
        comboBox_select_difficultylevel_M->addItem(QString());
        comboBox_select_difficultylevel_M->setObjectName(QString::fromUtf8("comboBox_select_difficultylevel_M"));
        comboBox_select_difficultylevel_M->setGeometry(QRect(50, 300, 251, 22));
        comboBox_select_difficultylevel_M->setFont(font2);
        label_accmod_M = new QLabel(tab_3);
        label_accmod_M->setObjectName(QString::fromUtf8("label_accmod_M"));
        label_accmod_M->setGeometry(QRect(10, 330, 331, 20));
        label_accmod_M->setFont(font1);
        label_accmod_M->setAlignment(Qt::AlignCenter);
        label_select_difficultylevel_M = new QLabel(tab_3);
        label_select_difficultylevel_M->setObjectName(QString::fromUtf8("label_select_difficultylevel_M"));
        label_select_difficultylevel_M->setGeometry(QRect(90, 280, 181, 16));
        label_select_difficultylevel_M->setFont(font1);
        pushButton_AccMod_add_M = new QPushButton(tab_3);
        pushButton_AccMod_add_M->setObjectName(QString::fromUtf8("pushButton_AccMod_add_M"));
        pushButton_AccMod_add_M->setGeometry(QRect(40, 470, 111, 23));
        label_select_player_M = new QLabel(tab_3);
        label_select_player_M->setObjectName(QString::fromUtf8("label_select_player_M"));
        label_select_player_M->setGeometry(QRect(120, 10, 111, 16));
        label_select_player_M->setFont(font1);
        lineEdit_action_M = new QLineEdit(tab_3);
        lineEdit_action_M->setObjectName(QString::fromUtf8("lineEdit_action_M"));
        lineEdit_action_M->setGeometry(QRect(50, 80, 251, 21));
        lineEdit_action_M->setFont(font2);
        lineEdit_target_M = new QLineEdit(tab_3);
        lineEdit_target_M->setObjectName(QString::fromUtf8("lineEdit_target_M"));
        lineEdit_target_M->setGeometry(QRect(50, 180, 251, 21));
        lineEdit_target_M->setFont(font2);
        lineEdit_select_player_M = new QLineEdit(tab_3);
        lineEdit_select_player_M->setObjectName(QString::fromUtf8("lineEdit_select_player_M"));
        lineEdit_select_player_M->setGeometry(QRect(50, 30, 251, 21));
        lineEdit_select_player_M->setFont(font2);
        label_select_action_cost_M = new QLabel(tab_3);
        label_select_action_cost_M->setObjectName(QString::fromUtf8("label_select_action_cost_M"));
        label_select_action_cost_M->setGeometry(QRect(110, 110, 151, 20));
        label_select_action_cost_M->setFont(font1);
        comboBox_select_actioncost_M = new QComboBox(tab_3);
        comboBox_select_actioncost_M->addItem(QString());
        comboBox_select_actioncost_M->addItem(QString());
        comboBox_select_actioncost_M->addItem(QString());
        comboBox_select_actioncost_M->addItem(QString());
        comboBox_select_actioncost_M->addItem(QString());
        comboBox_select_actioncost_M->setObjectName(QString::fromUtf8("comboBox_select_actioncost_M"));
        comboBox_select_actioncost_M->setGeometry(QRect(50, 130, 251, 22));
        comboBox_select_actioncost_M->setFont(font2);
        checkBox_sukces_check_M = new QCheckBox(tab_3);
        checkBox_sukces_check_M->setObjectName(QString::fromUtf8("checkBox_sukces_check_M"));
        checkBox_sukces_check_M->setGeometry(QRect(110, 210, 111, 17));
        label_success_chance_M = new QLabel(tab_3);
        label_success_chance_M->setObjectName(QString::fromUtf8("label_success_chance_M"));
        label_success_chance_M->setGeometry(QRect(90, 240, 201, 20));
        label_success_chance_M->setFont(font1);
        spinBox_success_chance_M = new QSpinBox(tab_3);
        spinBox_success_chance_M->setObjectName(QString::fromUtf8("spinBox_success_chance_M"));
        spinBox_success_chance_M->setGeometry(QRect(150, 260, 51, 16));
        spinBox_success_chance_M->setAlignment(Qt::AlignCenter);
        spinBox_success_chance_M->setAccelerated(true);
        spinBox_success_chance_M->setMaximum(100);
        tabWidget_manual_type->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        pushButton_DmgMod_remove_M = new QPushButton(tab_4);
        pushButton_DmgMod_remove_M->setObjectName(QString::fromUtf8("pushButton_DmgMod_remove_M"));
        pushButton_DmgMod_remove_M->setGeometry(QRect(190, 360, 111, 23));
        tableWidget_DmgMod_M = new QTableWidget(tab_4);
        if (tableWidget_DmgMod_M->columnCount() < 2)
            tableWidget_DmgMod_M->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_DmgMod_M->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_DmgMod_M->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        tableWidget_DmgMod_M->setObjectName(QString::fromUtf8("tableWidget_DmgMod_M"));
        tableWidget_DmgMod_M->setGeometry(QRect(10, 240, 321, 111));
        tableWidget_DmgMod_M->setFocusPolicy(Qt::NoFocus);
        tableWidget_DmgMod_M->setStyleSheet(QString::fromUtf8("QCellWidget\n"
"{\n"
"background-color: #242424;\n"
"}"));
        pushButton_DmgMod_add_M = new QPushButton(tab_4);
        pushButton_DmgMod_add_M->setObjectName(QString::fromUtf8("pushButton_DmgMod_add_M"));
        pushButton_DmgMod_add_M->setGeometry(QRect(40, 360, 111, 23));
        label_dmgmod_M = new QLabel(tab_4);
        label_dmgmod_M->setObjectName(QString::fromUtf8("label_dmgmod_M"));
        label_dmgmod_M->setGeometry(QRect(50, 219, 271, 16));
        label_dmgmod_M->setFont(font1);
        label_damage_target_M = new QLabel(tab_4);
        label_damage_target_M->setObjectName(QString::fromUtf8("label_damage_target_M"));
        label_damage_target_M->setGeometry(QRect(100, 10, 141, 20));
        label_damage_target_M->setFont(font1);
        label_damage_target_M_2 = new QLabel(tab_4);
        label_damage_target_M_2->setObjectName(QString::fromUtf8("label_damage_target_M_2"));
        label_damage_target_M_2->setGeometry(QRect(110, 110, 121, 20));
        label_damage_target_M_2->setFont(font1);
        spinBox_damage_M = new QSpinBox(tab_4);
        spinBox_damage_M->setObjectName(QString::fromUtf8("spinBox_damage_M"));
        spinBox_damage_M->setGeometry(QRect(130, 130, 81, 22));
        spinBox_damage_M->setAlignment(Qt::AlignCenter);
        spinBox_damage_M->setAccelerated(true);
        spinBox_damage_M->setMaximum(99999);
        checkBox_ignore_shields_M = new QCheckBox(tab_4);
        checkBox_ignore_shields_M->setObjectName(QString::fromUtf8("checkBox_ignore_shields_M"));
        checkBox_ignore_shields_M->setGeometry(QRect(100, 170, 131, 17));
        comboBox_select_player_M = new QComboBox(tab_4);
        comboBox_select_player_M->setObjectName(QString::fromUtf8("comboBox_select_player_M"));
        comboBox_select_player_M->setGeometry(QRect(50, 30, 251, 22));
        comboBox_select_player_M->setFont(font2);
        lineEdit_select_dmg_reason_M = new QLineEdit(tab_4);
        lineEdit_select_dmg_reason_M->setObjectName(QString::fromUtf8("lineEdit_select_dmg_reason_M"));
        lineEdit_select_dmg_reason_M->setGeometry(QRect(50, 80, 251, 21));
        lineEdit_select_dmg_reason_M->setFont(font2);
        label_damage_target_M_3 = new QLabel(tab_4);
        label_damage_target_M_3->setObjectName(QString::fromUtf8("label_damage_target_M_3"));
        label_damage_target_M_3->setGeometry(QRect(90, 60, 181, 20));
        label_damage_target_M_3->setFont(font1);
        tabWidget_manual_type->addTab(tab_4, QString());
        tabWidget_calculation_type->addTab(tab_2, QString());
        frame_right = new QFrame(calculator);
        frame_right->setObjectName(QString::fromUtf8("frame_right"));
        frame_right->setGeometry(QRect(619, 69, 351, 591));
        frame_right->setFrameShape(QFrame::Box);
        frame_right->setFrameShadow(QFrame::Plain);
        textEdit_turn_1 = new QTextEdit(frame_right);
        textEdit_turn_1->setObjectName(QString::fromUtf8("textEdit_turn_1"));
        textEdit_turn_1->setEnabled(false);
        textEdit_turn_1->setGeometry(QRect(10, 40, 331, 191));
        textEdit_turn_1->setReadOnly(true);
        pushButton_copy = new QPushButton(frame_right);
        pushButton_copy->setObjectName(QString::fromUtf8("pushButton_copy"));
        pushButton_copy->setEnabled(false);
        pushButton_copy->setGeometry(QRect(120, 240, 121, 23));
        pushButton_continue_calculations = new QPushButton(frame_right);
        pushButton_continue_calculations->setObjectName(QString::fromUtf8("pushButton_continue_calculations"));
        pushButton_continue_calculations->setEnabled(false);
        pushButton_continue_calculations->setGeometry(QRect(110, 270, 141, 23));
        textEdit_turn_2 = new QTextEdit(frame_right);
        textEdit_turn_2->setObjectName(QString::fromUtf8("textEdit_turn_2"));
        textEdit_turn_2->setEnabled(false);
        textEdit_turn_2->setGeometry(QRect(10, 310, 331, 211));
        textEdit_turn_2->setReadOnly(true);
        pushButton_copy_2 = new QPushButton(frame_right);
        pushButton_copy_2->setObjectName(QString::fromUtf8("pushButton_copy_2"));
        pushButton_copy_2->setEnabled(false);
        pushButton_copy_2->setGeometry(QRect(120, 530, 121, 23));
        pushButton_approve = new QPushButton(frame_right);
        pushButton_approve->setObjectName(QString::fromUtf8("pushButton_approve"));
        pushButton_approve->setEnabled(false);
        pushButton_approve->setGeometry(QRect(90, 560, 71, 23));
        pushButton_disapprove = new QPushButton(frame_right);
        pushButton_disapprove->setObjectName(QString::fromUtf8("pushButton_disapprove"));
        pushButton_disapprove->setEnabled(false);
        pushButton_disapprove->setGeometry(QRect(210, 560, 71, 23));
        pushButton_calculate = new QPushButton(frame_right);
        pushButton_calculate->setObjectName(QString::fromUtf8("pushButton_calculate"));
        pushButton_calculate->setGeometry(QRect(120, 10, 121, 21));
        QFont font3;
        pushButton_calculate->setFont(font3);
        pushButton_calculate->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"     border: 2px solid black;\n"
"     background-color: #ffa02f;\n"
"	color: black;\n"
"}"));
        pushButton_approve_M = new QPushButton(frame_right);
        pushButton_approve_M->setObjectName(QString::fromUtf8("pushButton_approve_M"));
        pushButton_approve_M->setEnabled(false);
        pushButton_approve_M->setGeometry(QRect(80, 270, 71, 23));
        pushButton_disapprove_M = new QPushButton(frame_right);
        pushButton_disapprove_M->setObjectName(QString::fromUtf8("pushButton_disapprove_M"));
        pushButton_disapprove_M->setEnabled(false);
        pushButton_disapprove_M->setGeometry(QRect(210, 270, 71, 23));
        frame_left_2 = new QFrame(calculator);
        frame_left_2->setObjectName(QString::fromUtf8("frame_left_2"));
        frame_left_2->setGeometry(QRect(10, 68, 191, 591));
        frame_left_2->setFrameShape(QFrame::Box);
        frame_left_2->setFrameShadow(QFrame::Plain);
        layoutWidget = new QWidget(frame_left_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 100, 171, 121));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_activeeffect = new QLabel(layoutWidget);
        label_activeeffect->setObjectName(QString::fromUtf8("label_activeeffect"));
        label_activeeffect->setFont(font2);
        label_activeeffect->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_activeeffect);

        listWidget_player_conditions = new QListWidget(layoutWidget);
        listWidget_player_conditions->setObjectName(QString::fromUtf8("listWidget_player_conditions"));
        listWidget_player_conditions->setFont(font2);
        listWidget_player_conditions->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget_player_conditions->setTextElideMode(Qt::ElideLeft);
        listWidget_player_conditions->setFlow(QListView::TopToBottom);

        verticalLayout_3->addWidget(listWidget_player_conditions);

        layoutWidget1 = new QWidget(frame_left_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 10, 63, 42));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_armor = new QLabel(layoutWidget1);
        label_armor->setObjectName(QString::fromUtf8("label_armor"));
        label_armor->setFont(font2);
        label_armor->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_armor);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_current_armor = new QLabel(layoutWidget1);
        label_current_armor->setObjectName(QString::fromUtf8("label_current_armor"));
        label_current_armor->setFont(font2);
        label_current_armor->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_current_armor);

        label_divider = new QLabel(layoutWidget1);
        label_divider->setObjectName(QString::fromUtf8("label_divider"));
        label_divider->setFont(font2);
        label_divider->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_divider);

        label_max_armor = new QLabel(layoutWidget1);
        label_max_armor->setObjectName(QString::fromUtf8("label_max_armor"));
        label_max_armor->setFont(font2);
        label_max_armor->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_max_armor);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget2 = new QWidget(frame_left_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(110, 10, 63, 42));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_shield = new QLabel(layoutWidget2);
        label_shield->setObjectName(QString::fromUtf8("label_shield"));
        label_shield->setFont(font2);
        label_shield->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_shield);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_current_shield = new QLabel(layoutWidget2);
        label_current_shield->setObjectName(QString::fromUtf8("label_current_shield"));
        label_current_shield->setFont(font2);
        label_current_shield->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_current_shield);

        label_divider_2 = new QLabel(layoutWidget2);
        label_divider_2->setObjectName(QString::fromUtf8("label_divider_2"));
        label_divider_2->setFont(font2);
        label_divider_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_divider_2);

        label_max_shield = new QLabel(layoutWidget2);
        label_max_shield->setObjectName(QString::fromUtf8("label_max_shield"));
        label_max_shield->setFont(font2);
        label_max_shield->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_max_shield);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_action_cost = new QLabel(frame_left_2);
        label_action_cost->setObjectName(QString::fromUtf8("label_action_cost"));
        label_action_cost->setGeometry(QRect(60, 270, 71, 16));
        label_action_cost->setFont(font2);
        label_action_cost->setAlignment(Qt::AlignCenter);
        label_action_cost_2 = new QLabel(frame_left_2);
        label_action_cost_2->setObjectName(QString::fromUtf8("label_action_cost_2"));
        label_action_cost_2->setGeometry(QRect(60, 290, 71, 16));
        label_action_cost_2->setFont(font2);
        label_action_cost_2->setAlignment(Qt::AlignCenter);
        label_action_name = new QLabel(frame_left_2);
        label_action_name->setObjectName(QString::fromUtf8("label_action_name"));
        label_action_name->setGeometry(QRect(50, 320, 91, 16));
        label_action_name->setFont(font2);
        label_action_name->setAlignment(Qt::AlignCenter);
        label_action_name_2 = new QLabel(frame_left_2);
        label_action_name_2->setObjectName(QString::fromUtf8("label_action_name_2"));
        label_action_name_2->setGeometry(QRect(10, 340, 171, 51));
        label_action_name_2->setFont(font2);
        label_action_name_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_action_name_2->setWordWrap(true);
        label_difficulty = new QLabel(frame_left_2);
        label_difficulty->setObjectName(QString::fromUtf8("label_difficulty"));
        label_difficulty->setGeometry(QRect(40, 400, 111, 16));
        label_difficulty->setFont(font2);
        label_difficulty->setAlignment(Qt::AlignCenter);
        label_difficulty_2 = new QLabel(frame_left_2);
        label_difficulty_2->setObjectName(QString::fromUtf8("label_difficulty_2"));
        label_difficulty_2->setGeometry(QRect(10, 420, 171, 51));
        label_difficulty_2->setFont(font2);
        label_difficulty_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_difficulty_2->setWordWrap(true);
        pushButton_deleteEffect = new QPushButton(frame_left_2);
        pushButton_deleteEffect->setObjectName(QString::fromUtf8("pushButton_deleteEffect"));
        pushButton_deleteEffect->setGeometry(QRect(100, 225, 31, 21));
        pushButton_addEffect = new QPushButton(frame_left_2);
        pushButton_addEffect->setObjectName(QString::fromUtf8("pushButton_addEffect"));
        pushButton_addEffect->setGeometry(QRect(60, 225, 31, 21));
        layoutWidget_2 = new QWidget(frame_left_2);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(70, 50, 51, 42));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_barrier = new QLabel(layoutWidget_2);
        label_barrier->setObjectName(QString::fromUtf8("label_barrier"));
        label_barrier->setFont(font2);
        label_barrier->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_barrier);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_current_barrier = new QLabel(layoutWidget_2);
        label_current_barrier->setObjectName(QString::fromUtf8("label_current_barrier"));
        label_current_barrier->setFont(font2);
        label_current_barrier->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_current_barrier);


        verticalLayout_4->addLayout(horizontalLayout_4);

        QWidget::setTabOrder(tabWidget_calculation_type, comboBox_select_player);
        QWidget::setTabOrder(comboBox_select_player, comboBox_select_action);
        QWidget::setTabOrder(comboBox_select_action, comboBox_select_target);
        QWidget::setTabOrder(comboBox_select_target, comboBox_select_difficultylevel);
        QWidget::setTabOrder(comboBox_select_difficultylevel, pushButton_AccMod_add);
        QWidget::setTabOrder(pushButton_AccMod_add, pushButton_AccMod_remove);
        QWidget::setTabOrder(pushButton_AccMod_remove, pushButton_DmgMod_add);
        QWidget::setTabOrder(pushButton_DmgMod_add, pushButton_DmgMod_add_2);
        QWidget::setTabOrder(pushButton_DmgMod_add_2, listWidget_player_conditions);
        QWidget::setTabOrder(listWidget_player_conditions, pushButton_addEffect);
        QWidget::setTabOrder(pushButton_addEffect, pushButton_deleteEffect);
        QWidget::setTabOrder(pushButton_deleteEffect, pushButton_calculate);
        QWidget::setTabOrder(pushButton_calculate, pushButton_copy);
        QWidget::setTabOrder(pushButton_copy, pushButton_continue_calculations);
        QWidget::setTabOrder(pushButton_continue_calculations, pushButton_copy_2);
        QWidget::setTabOrder(pushButton_copy_2, pushButton_disapprove);
        QWidget::setTabOrder(pushButton_disapprove, pushButton_approve);
        QWidget::setTabOrder(pushButton_approve, textEdit_turn_1);
        QWidget::setTabOrder(textEdit_turn_1, textEdit_turn_2);
        QWidget::setTabOrder(textEdit_turn_2, pushButton_approve_M);
        QWidget::setTabOrder(pushButton_approve_M, pushButton_disapprove_M);
        QWidget::setTabOrder(pushButton_disapprove_M, tabWidget_manual_type);
        QWidget::setTabOrder(tabWidget_manual_type, comboBox_select_player_M);
        QWidget::setTabOrder(comboBox_select_player_M, lineEdit_select_dmg_reason_M);
        QWidget::setTabOrder(lineEdit_select_dmg_reason_M, spinBox_damage_M);
        QWidget::setTabOrder(spinBox_damage_M, checkBox_ignore_shields_M);
        QWidget::setTabOrder(checkBox_ignore_shields_M, pushButton_DmgMod_add_M);
        QWidget::setTabOrder(pushButton_DmgMod_add_M, pushButton_DmgMod_remove_M);
        QWidget::setTabOrder(pushButton_DmgMod_remove_M, lineEdit_select_player_M);
        QWidget::setTabOrder(lineEdit_select_player_M, lineEdit_action_M);
        QWidget::setTabOrder(lineEdit_action_M, comboBox_select_actioncost_M);
        QWidget::setTabOrder(comboBox_select_actioncost_M, lineEdit_target_M);
        QWidget::setTabOrder(lineEdit_target_M, checkBox_sukces_check_M);
        QWidget::setTabOrder(checkBox_sukces_check_M, spinBox_success_chance_M);
        QWidget::setTabOrder(spinBox_success_chance_M, comboBox_select_difficultylevel_M);
        QWidget::setTabOrder(comboBox_select_difficultylevel_M, pushButton_AccMod_add_M);
        QWidget::setTabOrder(pushButton_AccMod_add_M, pushButton_AccMod_remove_M);

        retranslateUi(calculator);

        tabWidget_calculation_type->setCurrentIndex(1);
        tabWidget_manual_type->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(calculator);
    } // setupUi

    void retranslateUi(QFrame *calculator)
    {
        calculator->setWindowTitle(QApplication::translate("calculator", "Frame", nullptr));
        label_title->setText(QApplication::translate("calculator", "Omni-Calculator Module", nullptr));
        pushButton_DmgMod_add_2->setText(QApplication::translate("calculator", "Usu\305\204 modyfikator", nullptr));
        label_select_player->setText(QApplication::translate("calculator", "Wybierz posta\304\207:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_AccMod->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("calculator", "Nazwa", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_AccMod->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("calculator", "Warto\305\233\304\207", nullptr));
        pushButton_DmgMod_add->setText(QApplication::translate("calculator", "Dodaj modyfikator", nullptr));
        label_select_action->setText(QApplication::translate("calculator", "Wybierz akcj\304\231:", nullptr));
        pushButton_AccMod_remove->setText(QApplication::translate("calculator", "Usu\305\204 modyfikator", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_DmgMod->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("calculator", "Nazwa", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_DmgMod->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("calculator", "Warto\305\233\304\207", nullptr));
        label_select_difficultylevel->setText(QApplication::translate("calculator", "Wybierz poziom trudno\305\233ci:", nullptr));
        label_dmgmod->setText(QApplication::translate("calculator", "Dodatkowe modyfikatory do obra\305\274e\305\204:", nullptr));
        label_select_target->setText(QApplication::translate("calculator", "Wybierz cel:", nullptr));
        comboBox_select_difficultylevel->setItemText(0, QApplication::translate("calculator", "--Wybierz poziom trudno\305\233ci--", nullptr));
        comboBox_select_difficultylevel->setItemText(1, QApplication::translate("calculator", "Bardzo \305\202atwy", nullptr));
        comboBox_select_difficultylevel->setItemText(2, QApplication::translate("calculator", "\305\201atwy", nullptr));
        comboBox_select_difficultylevel->setItemText(3, QApplication::translate("calculator", "Normalny", nullptr));
        comboBox_select_difficultylevel->setItemText(4, QApplication::translate("calculator", "Trudny", nullptr));
        comboBox_select_difficultylevel->setItemText(5, QApplication::translate("calculator", "Bardzo trudny", nullptr));
        comboBox_select_difficultylevel->setItemText(6, QApplication::translate("calculator", "Niemo\305\274liwy", nullptr));

        pushButton_AccMod_add->setText(QApplication::translate("calculator", "Dodaj modyfikator", nullptr));
        label_accmod->setText(QApplication::translate("calculator", "Dodatkowe modyfikatory do poziomu trudno\305\233ci:", nullptr));
        tabWidget_calculation_type->setTabText(tabWidget_calculation_type->indexOf(tab), QApplication::translate("calculator", "Automatyczny", nullptr));
        pushButton_AccMod_remove_M->setText(QApplication::translate("calculator", "Usu\305\204 modyfikator", nullptr));
        label_select_action_M->setText(QApplication::translate("calculator", "Wybierz akcj\304\231:", nullptr));
        label_select_target_M->setText(QApplication::translate("calculator", "Wybierz cel:", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_AccMod_M->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("calculator", "Nazwa", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_AccMod_M->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("calculator", "Warto\305\233\304\207", nullptr));
        comboBox_select_difficultylevel_M->setItemText(0, QApplication::translate("calculator", "--Wybierz poziom trudno\305\233ci--", nullptr));
        comboBox_select_difficultylevel_M->setItemText(1, QApplication::translate("calculator", "Bardzo \305\202atwy", nullptr));
        comboBox_select_difficultylevel_M->setItemText(2, QApplication::translate("calculator", "\305\201atwy", nullptr));
        comboBox_select_difficultylevel_M->setItemText(3, QApplication::translate("calculator", "Normalny", nullptr));
        comboBox_select_difficultylevel_M->setItemText(4, QApplication::translate("calculator", "Trudny", nullptr));
        comboBox_select_difficultylevel_M->setItemText(5, QApplication::translate("calculator", "Bardzo trudny", nullptr));
        comboBox_select_difficultylevel_M->setItemText(6, QApplication::translate("calculator", "Niemo\305\274liwy", nullptr));

        label_accmod_M->setText(QApplication::translate("calculator", "Dodatkowe modyfikatory do poziomu trudno\305\233ci:", nullptr));
        label_select_difficultylevel_M->setText(QApplication::translate("calculator", "Wybierz poziom trudno\305\233ci:", nullptr));
        pushButton_AccMod_add_M->setText(QApplication::translate("calculator", "Dodaj modyfikator", nullptr));
        label_select_player_M->setText(QApplication::translate("calculator", "Wybierz posta\304\207:", nullptr));
        label_select_action_cost_M->setText(QApplication::translate("calculator", "Wybierz koszt akcji:", nullptr));
        comboBox_select_actioncost_M->setItemText(0, QApplication::translate("calculator", "--Wybierz koszt akcji--", nullptr));
        comboBox_select_actioncost_M->setItemText(1, QApplication::translate("calculator", "AM", nullptr));
        comboBox_select_actioncost_M->setItemText(2, QApplication::translate("calculator", "AD", nullptr));
        comboBox_select_actioncost_M->setItemText(3, QApplication::translate("calculator", "AM+AD", nullptr));
        comboBox_select_actioncost_M->setItemText(4, QApplication::translate("calculator", "Darmowa akcja", nullptr));

        checkBox_sukces_check_M->setText(QApplication::translate("calculator", "Ma test na sukces", nullptr));
        label_success_chance_M->setText(QApplication::translate("calculator", "Bazowa szansa na sukces:", nullptr));
        tabWidget_manual_type->setTabText(tabWidget_manual_type->indexOf(tab_3), QApplication::translate("calculator", "Akcja / Test", nullptr));
        pushButton_DmgMod_remove_M->setText(QApplication::translate("calculator", "Usu\305\204 modyfikator", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_DmgMod_M->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("calculator", "Nazwa", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_DmgMod_M->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("calculator", "Warto\305\233\304\207", nullptr));
        pushButton_DmgMod_add_M->setText(QApplication::translate("calculator", "Dodaj modyfikator", nullptr));
        label_dmgmod_M->setText(QApplication::translate("calculator", "Dodatkowe modyfikatory do obra\305\274e\305\204:", nullptr));
        label_damage_target_M->setText(QApplication::translate("calculator", "Wybierz cel obra\305\274e\305\204:", nullptr));
        label_damage_target_M_2->setText(QApplication::translate("calculator", "Warto\305\233\304\207 obra\305\274e\305\204:", nullptr));
        checkBox_ignore_shields_M->setText(QApplication::translate("calculator", "Ignoruj tarcze i bariery", nullptr));
        label_damage_target_M_3->setText(QApplication::translate("calculator", "Wybierz pow\303\263d obra\305\274e\305\204:", nullptr));
        tabWidget_manual_type->setTabText(tabWidget_manual_type->indexOf(tab_4), QApplication::translate("calculator", "Obra\305\274enia", nullptr));
        tabWidget_calculation_type->setTabText(tabWidget_calculation_type->indexOf(tab_2), QApplication::translate("calculator", "Manualny", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_copy->setToolTip(QApplication::translate("calculator", "Kopiuje do schowka tekst sformatowany na format Cytadeli", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_copy->setText(QApplication::translate("calculator", "Skopiuj do schowka", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_continue_calculations->setToolTip(QApplication::translate("calculator", "Kopiuje do schowka tekst sformatowany na format Cytadeli", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_continue_calculations->setText(QApplication::translate("calculator", "Kontynuuj przeliczanie", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_copy_2->setToolTip(QApplication::translate("calculator", "Kopiuje do schowka tekst sformatowany na format Cytadeli", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_copy_2->setText(QApplication::translate("calculator", "Skopiuj do schowka", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_approve->setToolTip(QApplication::translate("calculator", "Kopiuje do schowka tekst sformatowany na format Cytadeli", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_approve->setText(QApplication::translate("calculator", "Potwierd\305\272", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_disapprove->setToolTip(QApplication::translate("calculator", "Kopiuje do schowka tekst sformatowany na format Cytadeli", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_disapprove->setText(QApplication::translate("calculator", "Odrzu\304\207", nullptr));
        pushButton_calculate->setText(QApplication::translate("calculator", "Przelicz!", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_approve_M->setToolTip(QApplication::translate("calculator", "Kopiuje do schowka tekst sformatowany na format Cytadeli", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_approve_M->setText(QApplication::translate("calculator", "Potwierd\305\272", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_disapprove_M->setToolTip(QApplication::translate("calculator", "Kopiuje do schowka tekst sformatowany na format Cytadeli", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_disapprove_M->setText(QApplication::translate("calculator", "Odrzu\304\207", nullptr));
        label_activeeffect->setText(QApplication::translate("calculator", "Aktywne efekty", nullptr));
        label_armor->setText(QApplication::translate("calculator", "Pancerz:", nullptr));
        label_current_armor->setText(QApplication::translate("calculator", "500", nullptr));
        label_divider->setText(QApplication::translate("calculator", "/", nullptr));
        label_max_armor->setText(QApplication::translate("calculator", "500", nullptr));
        label_shield->setText(QApplication::translate("calculator", "Tarcze:", nullptr));
        label_current_shield->setText(QApplication::translate("calculator", "200", nullptr));
        label_divider_2->setText(QApplication::translate("calculator", "/", nullptr));
        label_max_shield->setText(QApplication::translate("calculator", "200", nullptr));
        label_action_cost->setText(QApplication::translate("calculator", "Koszt akcji:", nullptr));
        label_action_cost_2->setText(QApplication::translate("calculator", "Brak", nullptr));
        label_action_name->setText(QApplication::translate("calculator", "Wybrana akcja:", nullptr));
        label_action_name_2->setText(QApplication::translate("calculator", "-", nullptr));
        label_difficulty->setText(QApplication::translate("calculator", "Poziom trudno\305\233ci:", nullptr));
        label_difficulty_2->setText(QApplication::translate("calculator", "-", nullptr));
        pushButton_deleteEffect->setText(QApplication::translate("calculator", "-", nullptr));
        pushButton_addEffect->setText(QApplication::translate("calculator", "+", nullptr));
        label_barrier->setText(QApplication::translate("calculator", "Bariera:", nullptr));
        label_current_barrier->setText(QApplication::translate("calculator", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calculator: public Ui_calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
