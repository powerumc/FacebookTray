#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkRequest>
#include <QNetworkProxyFactory>
#include <QNetworkAccessManager>
#include <QNetworkCookie>
#include <QNetworkCookieJar>
#include <QNetworkReply>
#include <QDebug>
#include <QWebView>
#include <QNetworkConfiguration>
#include <QMessageBox>
#include <QIcon>
#include <QDockWidget>
#include <QMenu>
#include <QAction>
#include <QActionEvent>
#include <QToolBar>
#include <QMenuBar>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QSslConfiguration>
#include <QSslCertificate>
#include <QSsl>
#include <QSize>
#include <QFont>
#include <QRect>
#include <QPixmap>
#include <QIconEngine>
#include <QBitmap>
#include <QPainter>
#include <QPaintEngine>
#include <QList>
#include <QWebSettings>

#include "common.h"
#include "hostwebpage.h"
#include "persistentcecookiejar.h"
#include "sslnetworkaccessmanager.h"
#include "hostsystemcountertrayicon.h"
#include "mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);

    
private slots:
    void onSystemTrayIconActivationReason(QSystemTrayIcon::ActivationReason reason);
    void onClickTrayIcon(QAction*);
    void onQuit();
    void onOpen();
    void on_btnHome_clicked();
    void on_btnPrevioous_clicked();
    void on_btnNext_clicked();
    void on_btnRefresh_clicked();
    void on_btnSettings_clicked();

private:
    Ui::MainWindow              *ui;
    QNetworkAccessManager       *manager;
    HostWebPage                 *page;
    PersistentceCookieJar       *cookieJar;
    QUrl                        qurl;
    HostSystemCounterTrayIcon   *tray;
    QMenu                       *trayMenu;

    void onLoad();

};

#endif // MAINWINDOW_H
