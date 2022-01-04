#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addsite.h"
#include "getpwd.h"

#include <QStringList>
#include <QTreeWidgetItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    treeWidget = new QTreeWidget(this);

    // disabling action buttons
    ui->actionAdd_Site->setEnabled(false);
    ui->actionGet_Password->setEnabled(false);

    setCentralWidget(treeWidget);

    treeWidget->setColumnCount(2);
    treeWidget->setHeaderLabels(QStringList() << "Storage" << "Sites");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCreate_Storage_triggered()
{
    // Creating a TXT storage
    auto credentialStorage = credentialManager.initCredentialsStorage(
                CredentialManagementLibrary::CREDENTIALS::TXT,
                "TXT");

    // método para capturar os registros iniciais ! (só para popular a tela inicialmente se tiver dados no database txt)
    auto initial = credentialStorage->fetchRecords();

    ui->actionAdd_Site->setEnabled(true);
    ui->actionGet_Password->setEnabled(true);
    ui->actionCreate_Storage->setEnabled(false);

    txtItem = new QTreeWidgetItem(treeWidget);
    txtItem->setText(0, "TXT - Storage");
    txtItem->setText(1, "0");

    for (auto item : initial)
    {
        uint value = txtItem->text(1).toUInt() + 1;
        txtItem->setText(1, QString::number(value));

        QTreeWidgetItem * s = new QTreeWidgetItem(txtItem);
        s->setText(0, item.site.c_str());
        s->setText(1, item.name.c_str());
    }

    treeWidget->expandAll();
}

void MainWindow::on_actionAdd_Site_triggered()
{
    AddSite * site = new AddSite(this);
    int result = site->exec();
    if (result == QDialog::Accepted)
    {
        auto credentialStorage = credentialManager.getStorage(CredentialManagementLibrary::CREDENTIALS::TXT);

        if (!credentialStorage)
            return;

        if(!credentialStorage->addSiteCredentials(site->getSite().toStdString(),
                                                  site->getUser().toStdString(),
                                                  site->getPwd().toStdString()))
            return;

        uint value = txtItem->text(1).toUInt() + 1;
        txtItem->setText(1, QString::number(value));
        QTreeWidgetItem * s = new QTreeWidgetItem(txtItem);
        s->setText(0, site->getSite());
        s->setText(1, site->getUser());

        treeWidget->expandAll();
    }
}

void MainWindow::on_actionGet_Password_triggered()
{
    GetPwd * dialog = new GetPwd(this);
    int result = dialog->exec();

    if (result == QDialog::Accepted)
    {
        auto credentialStorage = credentialManager.getStorage(CredentialManagementLibrary::CREDENTIALS::TXT);

        if (!credentialStorage)
            return;

        std::string s = credentialStorage->getSitePassword(dialog->getSite().toStdString(),
                                                           dialog->getUser().toStdString());

        if (s.empty())
        {
            QMessageBox error;
            error.setText("Credential not found");
            error.setStandardButtons(QMessageBox::Ok);
            error.setInformativeText("ERROR");
            error.exec();
            return;
        }

        QMessageBox msg;
        msg.setText(QString("Credential: %1\n%2\n%3").arg(dialog->getSite(), dialog->getUser(), QString(s.c_str())));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setInformativeText("Founded");
        msg.exec();
    }
}

