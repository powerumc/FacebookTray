#ifndef PERSISTENTCECOOKIEJAR_H
#define PERSISTENTCECOOKIEJAR_H

#include "common.h"

#include <QWebView>
#include <QNetworkAccessManager>
#include <QNetworkCookieJar>
#include <QNetworkCookie>
#include <QSettings>
#include <QList>
#include <QByteArray>

class PersistentceCookieJar : public QNetworkCookieJar
{
public:
    PersistentceCookieJar(QSettings* settings);
    PersistentceCookieJar(QObject *parent, QSettings* settings);
    ~PersistentceCookieJar();

    void onLoad(QSettings* settings);
    void onSave(QSettings* settings);



private:
    void load(QSettings* settings);
    void save(QSettings* settings);

    QSettings* _settings;
};

#endif // PERSISTENTCECOOKIEJAR_H
