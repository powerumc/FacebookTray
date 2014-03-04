#include "sslnetworkaccessmanager.h"

SslNetworkAccessManager::SslNetworkAccessManager(QObject *parent) : QNetworkAccessManager(parent),
                                                                    cookieJar(NULL)
{
    onInit();
}

SslNetworkAccessManager::SslNetworkAccessManager(QObject *parent, QNetworkCookieJar *cookieJar) : QNetworkAccessManager(parent),
                                                                                                  cookieJar(cookieJar)
{
   onInit();
}

void SslNetworkAccessManager::onInit()
{
    connect(this, SIGNAL(finished(QNetworkReply*)), SLOT(onCookieReplyFinished(QNetworkReply*)));
    connect(this, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), SLOT(onHandleSslErrors(QNetworkReply*,QList<QSslError>)));
}


void SslNetworkAccessManager::onCookieReplyFinished(QNetworkReply *reply)
{
    if (reply->isFinished())
    {
        QVariant variantCookies = reply->header(QNetworkRequest::SetCookieHeader);
        QList<QNetworkCookie> cookies = qvariant_cast<QList<QNetworkCookie> >(variantCookies);

        if( cookieJar )
            cookieJar->setCookiesFromUrl(cookies, reply->request().url());

        // qDebug() << "Reply Request Url : " << reply->request().url();

//        if (cookies.count() > 0)
//        {
//            for (int i = 0; i < cookies.count(); ++i)
//            {
//                QNetworkCookie cookie = cookies.at(i);
//                QString cookieStr(cookie.toRawForm());

//                qDebug() << cookieStr;
//            }
//        }
    }
}

void SslNetworkAccessManager::onHandleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors)
{
    qDebug() << "handleSslErrors: ";
    foreach (QSslError e, errors)
    {
        qDebug() << "ssl error: " << e;
    }

    reply->ignoreSslErrors();
}
