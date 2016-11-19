#ifndef DIALOGBOX_DETAILS_H
#define DIALOGBOX_DETAILS_H

#include <QFrame>

namespace Ui {
class dialogbox_details;
}

class dialogbox_details : public QFrame
{
    Q_OBJECT

public:
    explicit dialogbox_details(QWidget *parent = 0);
    ~dialogbox_details();

    void setDetailsText(QString text);

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialogbox_details *ui;
};

#endif // DIALOGBOX_DETAILS_H
