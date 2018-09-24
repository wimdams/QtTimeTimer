#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_pbStart_clicked();
    void changeToSettings();
    void changeFromSettings();
    void timeElapsed();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
