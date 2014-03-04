#ifndef SSLNETWORKACCESSMANAGER_H
#define SSLNETWORKACCESSMANAGER_H

#include "common.h"
#include <QObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkCookie>
#include <QNetworkCookieJar>
#include <QSslError>
#include <QList>
#include <QDebug>

#include "persistentcecookiejar.h"


class SslNetworkAccessManager : public QNetworkAccessManager
{
    Q_OBJECT

public:
    explicit SslNetworkAccessManager(QObject *parent = 0);
    explicit SslNetworkAccessManager(QObject *parent, QNetworkCookieJar* cookieJar);

protected:

signals:
    
public slots:
    virtual void onCookieReplyFinished(QNetworkReply *reply);
    virtual void onHandleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors);

private:
    void onInit();

    QNetworkCookieJar* cookieJar;
};

#endif // SSLNETWORKACCESSMANAGER_H
