/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_FacebookNotify;
    QAction *actionGo_Home;
    QAction *actionRefresh;
    QAction *actionPrevious;
    QAction *actionNext;
    QAction *actionPreferences;
    QAction *actionHelp;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWebView *webView;
    QMenuBar *menuBar;
    QMenu *menuCommand;
    QMenu *menuTools;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(482, 275);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setDocumentMode(false);
        MainWindow->setDockNestingEnabled(false);
        actionAbout_FacebookNotify = new QAction(MainWindow);
        actionAbout_FacebookNotify->setObjectName(QStringLiteral("actionAbout_FacebookNotify"));
        actionGo_Home = new QAction(MainWindow);
        actionGo_Home->setObjectName(QStringLiteral("actionGo_Home"));
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        actionPrevious = new QAction(MainWindow);
        actionPrevious->setObjectName(QStringLiteral("actionPrevious"));
        actionNext = new QAction(MainWindow);
        actionNext->setObjectName(QStringLiteral("actionNext"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        webView = new QWebView(centralWidget);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setMinimumSize(QSize(0, 200));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        horizontalLayout->addWidget(webView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 482, 22));
        menuCommand = new QMenu(menuBar);
        menuCommand->setObjectName(QStringLiteral("menuCommand"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuCommand->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuCommand->addAction(actionGo_Home);
        menuCommand->addAction(actionRefresh);
        menuCommand->addAction(actionPrevious);
        menuCommand->addAction(actionNext);
        menuTools->addAction(actionPreferences);
        menuTools->addSeparator();
        menuTools->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAbout_FacebookNotify->setText(QApplication::translate("MainWindow", "Settings", 0));
        actionGo_Home->setText(QApplication::translate("MainWindow", "Go Home", 0));
        actionRefresh->setText(QApplication::translate("MainWindow", "Refresh", 0));
        actionPrevious->setText(QApplication::translate("MainWindow", "Previous", 0));
        actionNext->setText(QApplication::translate("MainWindow", "Next", 0));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        menuCommand->setTitle(QApplication::translate("MainWindow", "Command", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
