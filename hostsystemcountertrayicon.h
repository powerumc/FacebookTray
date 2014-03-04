#ifndef HOSTSYSTEMCOUNTERTRAYICON_H
#define HOSTSYSTEMCOUNTERTRAYICON_H

#include <QSystemTrayIcon>
#include <QRect>
#include <QPixmap>
#include <QPainter>
#include <QPaintEngine>
#include <QFont>
#include <QIcon>

class HostSystemCounterTrayIcon : public QSystemTrayIcon
{
    Q_OBJECT

public:
    explicit HostSystemCounterTrayIcon(QObject *parent = 0, QImage* trayimage = 0);


private:
    QImage *_trayImage;


public slots:
    void onChangeCount(const int count);

    
};

#endif // HOSTSYSTEMCOUNTERTRAYICON_H
