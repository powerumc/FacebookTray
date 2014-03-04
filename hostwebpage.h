#ifndef FACEBOOKWEBPAGE_H
#define FACEBOOKWEBPAGE_H

#include "common.h"

#include <QUrl>
#include <QWebView>
#include <QWebPage>
#include <QWebFrame>
#include <QWebElement>
#include <QNetworkAccessManager>
#include <QMessageBox>
#include <QCursor>
#include <QDesktopServices>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QDebug>




class HostWebPage : public QWebPage
{
    Q_OBJECT

public:
    explicit HostWebPage(QObject* parent = 0, QUrl baseUrl = QUrl(""));
    ~HostWebPage();

    QString userAgentForUrl(const QUrl &url) const;

protected:
    QWebPage *createWindow(WebWindowType type);

private:
    QString lastUrl;
    QUrl    _baseUrl;


private slots:
    void onLoadFinished(bool ok);
    void onLinkClicked(const QUrl &url);
    void onLinkHovered(const QString &link, const QString &title, const QString &textContent);
    bool acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type);

    void onTimer();


signals:
    void FireWebPageSignal(const uint count);


};

#endif // FACEBOOKWEBPAGE_H
