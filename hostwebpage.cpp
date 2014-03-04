#include "hostwebpage.h"


HostWebPage::HostWebPage(QObject *parent, QUrl baseUrl) : QWebPage(parent), _baseUrl(baseUrl)
{
    connect(this, SIGNAL(linkHovered(QString,QString,QString)), SLOT(onLinkHovered(QString,QString,QString)));
    connect(this, SIGNAL(linkClicked(const QUrl&)), this, SLOT(onLinkClicked(const QUrl&)));
    connect(this, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));

    onTimer();
}

HostWebPage::~HostWebPage()
{
    disconnect(this);
}

/*
 * 요청 개수 숫자 class
 * <span class="count mfss fcw" data-sigil="count">1</span>
 **/

QString HostWebPage::userAgentForUrl(const QUrl &url) const
{
    return QWebPage::userAgentForUrl(url);

    // iphone
    // return "Mozilla/5.0 (iPod; U; CPU iPhone OS 3_1_3 like Mac OS X; ko-kr) AppleWebKit/528.18 (KHTML, like Gecko) Version/4.0 Mobile/7E18 Safari/528.16";

    // ipad
    // return "Mozilla/5.0(iPad; U; CPU iPhone OS 3_2 like Mac OS X; en-us) AppleWebKit/531.21.10 (KHTML, like Gecko) Version/4.0.4 Mobile/7B314 Safari/531.21.10";
}



void HostWebPage::onLinkHovered(const QString &link, const QString &title, const QString &textContent)
{
    qDebug() << "FacebookWebPage::onLinkHovered title=" << title << ", textContent=" << textContent;

    this->view()->setCursor(Qt::OpenHandCursor);

    if(link.isEmpty()) return;
    lastUrl = QString(link);

    qDebug() << "private lastUrl=" << lastUrl;
}

void HostWebPage::onLinkClicked(const QUrl &url)
{
    qDebug() << "FacebookWebPage::onLinkClicked url=" << url.url();

}

void HostWebPage::onLoadFinished(bool ok)
{
    if(!ok) return;

    QWebFrame* frame = static_cast<QWebView*>(this->view())->page()->mainFrame();
    qDebug() << "FacebookWebPage::onLoadFinished url=" << frame->url().host();

    if(frame != NULL)
    {
//        QWebElementCollection collection = frame->findAllElements("a[target=_blank]");
//        foreach(QWebElement element, collection)
//        {
//            element.setAttribute("target","_self");
//        }
    }
}

bool HostWebPage::acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type)
{
    return QWebPage::acceptNavigationRequest(frame, request, type);
}

QWebPage *HostWebPage::createWindow(WebWindowType type)
{
    qDebug() << "QWebPage::createWindow type=" << type << " " << this->view();
    qDebug() << "LastUrl=" << lastUrl;

    if(_baseUrl.url().isEmpty() == false)
    {
        if(lastUrl.toLower().contains(_baseUrl.host()) == false ||
           lastUrl.toLower().contains(LINK_ADDR_FACEBOOK))
        {
            QDesktopServices::openUrl(QUrl(lastUrl));
            return QWebPage::createWindow(type);
        }
    }

    ((QWebView*)this->view())->load(QUrl(this->lastUrl));

    return new HostWebPage(this->view());
}

static int staticCount = 0;
void HostWebPage::onTimer()
{
    QTimer::singleShot(5000, this, SLOT(onTimer()));

    int count = 0;
    QWebFrame* frame = static_cast<QWebView*>(this->view())->page()->mainFrame();
    if( !frame) return;

    QList<QWebElement> notifyCount = frame->findAllElements("span[class='count mfss fcw']").toList();
    //qDebug() << "notifyCount=" << notifyCount.count();

    for(int i=0;i<notifyCount.count();i++)
    {
        QWebElement n = notifyCount.at(i);
        if(n.isNull()) continue;

        count += n.toInnerXml().toInt();
        qDebug() << "* " << n.toOuterXml();
    }

    if( staticCount == count ) return;

    staticCount = count;
    emit FireWebPageSignal(count);

    qDebug() << "FacebookWebPage::onTimer";
}
