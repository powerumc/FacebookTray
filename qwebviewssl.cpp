/*
#include "qwebviewssl.h"

QWebViewSsl::QWebViewSsl(QWidget *parent) : QWebView(parent)
{
    load(QUrl("https://gmail.com"));

    connect(page()->networkAccessManager(), SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> & )),
            this,                           SLOT(handleSslErrors(QNetworkReply*, const QList<QSslError> & )));


}

void QWebView::handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors)
{
    qDebug() << "handleSslErrors: ";
    foreach (QSslError e, errors)
    {
        qDebug() << "ssl error: " << e;
    }

    reply->ignoreSslErrors();
}
*/
