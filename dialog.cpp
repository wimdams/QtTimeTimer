#include "dialog.h"
#include "ui_dialog.h"

#include <QColorDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->clock, SIGNAL(triggered()), this, SLOT(changeToSettings()));
    connect(ui->pbSave, SIGNAL(clicked()), this, SLOT(changeFromSettings()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pbStart_clicked()
{
    if(ui->pbStart->text() == tr("Start")){
        ui->clock->start();
        ui->pbStart->setText("Reset");
    }else{
        ui->clock->reset();
        ui->pbStart->setText("Start");
    }

}

void Dialog::changeToSettings()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::changeFromSettings()
{
    ui->clock->setBGColor(ui->bgColor->color());
    ui->clock->setFGColor(ui->fgColor->color());
    ui->stackedWidget->setCurrentIndex(0);
}

