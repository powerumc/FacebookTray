#include "hostsystemcountertrayicon.h"

HostSystemCounterTrayIcon::HostSystemCounterTrayIcon(QObject *parent, QImage *trayimage) :
    QSystemTrayIcon(parent),
    _trayImage(trayimage)
{
}



void HostSystemCounterTrayIcon::onChangeCount(const int count)
{
    QRect iconRect(0, 0, 20, 20);
    int _textRect = iconRect.width() / 2.5;
    QRect textRect(_textRect, _textRect, iconRect.size().width() - _textRect, iconRect.size().height() - _textRect);

    QPixmap pixmap(iconRect.width(), iconRect.height());
    QPainter painter(&pixmap);
    painter.drawPixmap(iconRect, pixmap);
    painter.drawImage(iconRect, *_trayImage );

    if( count != 0 )
    {
        // 숫자
        painter.setFont(QFont("Arial", 12));
        painter.fillRect(textRect, Qt::red);
        painter.setPen(Qt::white);
        painter.drawText(textRect, QString().setNum(count), QTextOption(Qt::AlignCenter));
    }


    QIcon icon(pixmap);

    this->icon().detach();
    this->setIcon(icon);
}
