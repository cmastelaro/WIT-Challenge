#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#if defined(CREDENTIALMANAGEMENTLIBRARY_LIBRARY)
#  define CREDENTIALMANAGEMENTLIBRARY_EXPORT Q_DECL_EXPORT
#else
#  define CREDENTIALMANAGEMENTLIBRARY_EXPORT Q_DECL_IMPORT
#endif

#include <QMainWindow>
#include <QApplication>
#include <QTreeWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include "CredentialManagementLibrary/CredentialManagementLibrary.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCreate_Storage_triggered();
    void on_actionAdd_Site_triggered();
    void on_actionGet_Password_triggered();

private:
    Ui::MainWindow *ui;
    CredentialManagementLibrary credentialManager;
    QTreeWidget * treeWidget;
    QTreeWidgetItem * txtItem;
};
#endif // MAINWINDOW_H
