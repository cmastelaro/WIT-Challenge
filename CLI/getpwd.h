#ifndef GETPWD_H
#define GETPWD_H

#include <QDialog>

namespace Ui {
class GetPwd;
}

class GetPwd : public QDialog
{
    Q_OBJECT

public:
    explicit GetPwd(QWidget *parent = nullptr);
    ~GetPwd();

    QString getSite();
    QString getUser();

private:
    Ui::GetPwd *ui;
};

#endif // GETPWD_H
