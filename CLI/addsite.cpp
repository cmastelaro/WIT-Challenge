#include "addsite.h"
#include "ui_addsite.h"

AddSite::AddSite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSite)
{
    ui->setupUi(this);

    QObject::connect(ui->buttonAccept, SIGNAL(clicked()), this, SLOT(accept()));
}

AddSite::~AddSite()
{
    delete ui;
}

QString AddSite::getSite()
{
    return ui->editSite->text();
}

QString AddSite::getUser()
{
    return ui->editUser->text();
}

QString AddSite::getPwd()
{
    return ui->editPwd->text();
}
