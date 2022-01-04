#ifndef ADDSITE_H
#define ADDSITE_H

#include <QDialog>

namespace Ui {
class AddSite;
}

class AddSite : public QDialog
{
    Q_OBJECT

public:
    explicit AddSite(QWidget *parent = nullptr);
    ~AddSite();

    QString getSite();
    QString getUser();
    QString getPwd();

private slots:

private:
    Ui::AddSite *ui;
};

#endif // ADDSITE_H
