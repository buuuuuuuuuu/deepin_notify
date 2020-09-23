#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
#include <QtDBus>
#include <QDBusInterface>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{

}

void MainWindow::on_sendBtn_clicked()
{
    QString in0 = ui->m_in0->text();
    uint in1 = ui->m_in1->text().toInt();
    QString in2 = ui->m_in2->text();
    QString in3 = ui->m_in3->text();
    QString in4 = ui->m_in4->text();
    QString in5 = ui->m_in5->text();
    QString in6 = ui->m_in6->text();
    int in7 = ui->m_in7->text().toInt();

//    if(in0 != in2 ){
//        QMessageBox::warning(this,"错误", "程序名应该和应用名相同");
//        return;
//    }


    QDBusInterface tInterNotify("com.deepin.dde.Notification",
                                "/com/deepin/dde/Notification",
                                "com.deepin.dde.Notification",
                                QDBusConnection::sessionBus());
    QList<QVariant> arg;
//    QString in0(tr("downloader")); //下载器
//    uint in1 = 101;
//    QString in2;
//    in2 = "downloader";
//    QString in3(head);
//    QString in4(text);

    QStringList in51;
    QVariantMap in61;
//    if (isBt) {
        in51 << "_cancel" << tr("取消") << "_view" << tr("确定");
        in61["x-deepin-action-_view"] = "downloader";
//    }

//    int in7 = 5000;
    arg << in0 << in1 << in2 << in3 << in4 << in51 << in61 << in7;
    tInterNotify.callWithArgumentList(QDBus::AutoDetect, "Notify", arg);
}
























