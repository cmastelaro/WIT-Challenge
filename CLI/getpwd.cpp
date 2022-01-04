#include "getpwd.h"
#include "ui_getpwd.h"

GetPwd::GetPwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetPwd)
{
    ui->setupUi(this);

    QObject::connect(ui->acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
}

GetPwd::~GetPwd()
{
    delete ui;
}

QString GetPwd::getSite()
{
    return ui->editSite->text();
}

QString GetPwd::getUser()
{
    return ui->editUser->text();
}
