#include "persistentcecookiejar.h"

PersistentceCookieJar::PersistentceCookieJar(QSettings* settings): _settings(settings)
{
    onLoad(settings);
}

PersistentceCookieJar::PersistentceCookieJar(QObject *parent, QSettings* settings) : QNetworkCookieJar(parent),
                                                                                     _settings(settings)
{
    onLoad(settings);
}

PersistentceCookieJar::~PersistentceCookieJar()
{
    onSave(this->_settings);
}

void PersistentceCookieJar::load(QSettings* settings)
{
    QByteArray data = settings->value("Cookies").toByteArray();
    setAllCookies(QNetworkCookie::parseCookies(data));
}

void PersistentceCookieJar::save(QSettings* settings)
{
    QList<QNetworkCookie> list = allCookies();
    QByteArray data;
    foreach (QNetworkCookie cookie, list) {
        if (!cookie.isSessionCookie()) {
            data.append(cookie.toRawForm());
            data.append("\n");
        }
    }

    settings->setValue("Cookies",data);
}


void PersistentceCookieJar::onSave(QSettings* settings)
{
    this->save(settings);
}

void PersistentceCookieJar::onLoad(QSettings* settings)
{
    this->load(settings);
}
