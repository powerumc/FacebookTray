#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          cookieJar(new PersistentceCookieJar(new QSettings("POWERUMC", "FacebookTray"))),
                                          qurl(URL_FACEBOOK)
{
    ui->setupUi(this);

    onLoad();
}

MainWindow::~MainWindow()
{
    disconnect(this);

    delete tray;
    delete ui;
}


void MainWindow::onLoad()
{
    // 메인 창 설정
    this->menuBar()->hide();
    this->menuBar()->close();
    this->resize(500, 600);


    // SSL 구성
    QSslConfiguration sslCfg = QSslConfiguration::defaultConfiguration();
    QList<QSslCertificate> ca_list = sslCfg.caCertificates();
    QList<QSslCertificate> ca_new = QSslCertificate::fromData("CaCertificates");
    ca_list += ca_new;

    sslCfg.setCaCertificates(ca_list);
    sslCfg.setProtocol(QSsl::AnyProtocol);
    QSslConfiguration::setDefaultConfiguration(sslCfg);


    // WebView 구성
    QNetworkProxyFactory::setUseSystemConfiguration (true);
    ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);
    ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
    ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);
    ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);




    // 툴바 구성
    QToolBar *toolbar = new QToolBar("Command Toolbar", this);
    toolbar->addActions(ui->menuCommand->actions());

    toolbar->addSeparator();
    toolbar->addActions(ui->menuTools->actions());

    this->addToolBar(toolbar);

    connect(ui->actionGo_Home,      SIGNAL(triggered()), SLOT(on_btnHome_clicked()));
    connect(ui->actionRefresh,      SIGNAL(triggered()), SLOT(on_btnRefresh_clicked()));
    connect(ui->actionNext,         SIGNAL(triggered()), SLOT(on_btnNext_clicked()));
    connect(ui->actionPrevious,     SIGNAL(triggered()), SLOT(on_btnPrevioous_clicked()));
    connect(ui->actionHelp,         SIGNAL(triggered()), SLOT(onQuit()));
    connect(ui->actionPreferences,  SIGNAL(triggered()), SLOT(onQuit()));

    ui->actionHelp->setEnabled(false);
    ui->actionPreferences->setEnabled(false);


    // 트레이 아이콘 설정
    trayMenu = new QMenu("TRAY MENU", this);

#if defined(Q_OS_MACX)
    QAction *action_open = new QAction("O&pen", this);
    connect(action_open, SIGNAL(triggered()), SLOT(onOpen()));
    action_open->setMenuRole(QAction::NoRole);
    trayMenu->addAction(action_open);
    trayMenu->addSeparator();
#endif

    QAction *action_quit = new QAction("Q&uit", this);
    connect(action_quit, SIGNAL(triggered()), SLOT(onQuit()));
    action_quit->setMenuRole(QAction::NoRole);
    trayMenu->addAction(action_quit);


    tray = new HostSystemCounterTrayIcon(this, new QImage(":/icons/coupang.jpeg"));
    tray->setContextMenu(trayMenu);

    tray->setIcon(QIcon(":/icons/coupang.jpeg"));
    tray->show();


    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onSystemTrayIconActivationReason(QSystemTrayIcon::ActivationReason)));
    connect(tray, SIGNAL(messageClicked()), this, SLOT(on_btnHome_clicked()));





    // SSL 설정
    manager = new SslNetworkAccessManager(this);
    manager->setCookieJar(static_cast<QNetworkCookieJar*>(this->cookieJar));

    page = new HostWebPage(ui->webView, QUrl(URL_FACEBOOK));
    page->setNetworkAccessManager(manager);
    page->installEventFilter(this);

    connect(page, SIGNAL(FireWebPageSignal(uint)), tray, SLOT(onChangeCount(int)));





    // WebView 로드
    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    ui->webView->setContextMenuPolicy(Qt::NoContextMenu);

    ui->webView->setPage(page);
    ui->webView->load(qurl);
    //ui->webView->setHtml("<a href='http://blog.powerumc.kr' target=_blank>AAAAAAAAAAAAAAAAAAAAAAAAAA</a>");

    // div class=""inlineMediaContainer"" title=""Life""><div class=""storyAttachment inlineMedia hasMedia""><a href='http://blog.powerumc.kr' target=""_blank"">AAAAAAAAAAAAAAAAAAAAAAAAAA</div></div>

    // Qt QWebView는 target="_blank"인 링크는 클릭 시그널을 인식하지 못하고, 링크도 열리지 않는다.
    // <a class="darkTouch" href="http://m.facebook.com/l.php?u=http%3A%2F%2Fcandycrush.king.com%2FFacebookServlet%2Fopengraph%2Fcandycrush%3Alife%3F_pu%3D1469648980%26_tt%3DFB%26fb_action_ids%3D502680923127061%26fb_action_types%3Dcandycrush%253Agive%26fb_source%3Dother_multiline%26action_object_map%3D%255B218437438299003%255D%26action_type_map%3D%255B%2522candycrush%253Agive%2522%255D%26action_ref_map%3D%255B%255D&amp;h=7AQFAAsq3&amp;enc=AZOclnp2wWdpTcAexgWnvaAx2ZaAQNmQOXn_n-Z17oI4rWVKdIWrsnKxs1WOuC7D-hj7NvcVZBHL2_hboG0emjg81wiJrEDNdqpQVVQ8QIlYOLm04XfOI5sIj8d1ynytGReD6uW2_hbHYjN4BR5GKtSz&amp;s=1" target="_blank" onclick="JX.RenderLinkshim.click(this, &quot;http:\/\/candycrush.king.com\/FacebookServlet\/opengraph\/candycrush:life?_pu=1469648980&amp;_tt=FB&amp;fb_action_ids=502680923127061&amp;fb_action_types=candycrush\u00253Agive&amp;fb_source=other_multiline&amp;action_object_map=\u00255B218437438299003\u00255D&amp;action_type_map=\u00255B\u002522candycrush\u00253Agive\u002522\u00255D&amp;action_ref_map=\u00255B\u00255D&quot;, &quot;https:\/\/www.facebook.com\/si\/ajax\/l\/render_linkshim_log\/?u=http\u00253A\u00252F\u00252Fcandycrush.king.com\u00252FFacebookServlet\u00252Fopengraph\u00252Fcandycrush\u00253Alife\u00253F_pu\u00253D1469648980\u002526_tt\u00253DFB\u002526fb_action_ids\u00253D502680923127061\u002526fb_action_types\u00253Dcandycrush\u0025253Agive\u002526fb_source\u00253Dother_multiline\u002526action_object_map\u00253D\u0025255B218437438299003\u0025255D\u002526action_type_map\u00253D\u0025255B\u00252522candycrush\u0025253Agive\u00252522\u0025255D\u002526action_ref_map\u00253D\u0025255B\u0025255D&amp;h=7AQFAAsq3&amp;enc=AZOclnp2wWdpTcAexgWnvaAx2ZaAQNmQOXn_n-Z17oI4rWVKdIWrsnKxs1WOuC7D-hj7NvcVZBHL2_hboG0emjg81wiJrEDNdqpQVVQ8QIlYOLm04XfOI5sIj8d1ynytGReD6uW2_hbHYjN4BR5GKtSz&amp;s=1&amp;__user=100000339676463&amp;__a=1&quot;);"><div data-sigil="touchable touchable"><div class="storyAttachmentMedia"><i class="img img" style="background-image: url(&quot;https://fbexternal-a.akamaihd.net/safe_image.php?d=AQDF7cq-qhXxqVn-&amp;w=60&amp;h=60&amp;url=http%3A%2F%2Fcc1.midasplayer.com%2Fimages%2Fopengraph%2F90x90_life.png%3F_v%3D1ozkgyy&amp;crop&quot;);background-repeat:no-repeat;background-size:100% 100%;-webkit-background-size:100% 100%;width:60px;height:60px;" aria-label="공개되는 모습" role="img"></i></div><div class="storyAttachmentTitle">Life<div class="storyAttachmentCaption"><span><span>Candy Crush Saga</span></span></div></div><div class="clear"></div></div></a>
}

void MainWindow::onQuit()
{
    QApplication::quit();
}

void MainWindow::onOpen()
{
    this->show();
}

void MainWindow::onClickTrayIcon(QAction*)
{
    this->show();
}

void MainWindow::onSystemTrayIconActivationReason(QSystemTrayIcon::ActivationReason reason)
{
    if( reason == QSystemTrayIcon::Trigger)
    {
        this->show();
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    return QObject::eventFilter(obj, event);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (tray->isVisible() && !event->spontaneous())
    {
        tray->showMessage(tr("Systray"),
        tr("This application is still running. To quit please click this icon and select Quit"));
        hide();

        event->ignore();
    }
}

void MainWindow::on_btnHome_clicked()
{
    ui->webView->load(QUrl(URL_FACEBOOK));
}

void MainWindow::on_btnPrevioous_clicked()
{
    ui->webView->back();
}

void MainWindow::on_btnNext_clicked()
{
    ui->webView->forward();
}

void MainWindow::on_btnRefresh_clicked()
{
    ui->webView->reload();
}

void MainWindow::on_btnSettings_clicked()
{

}
