# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created: Wed Mar 27 23:22:56 2013
#      by: PyQt4 UI code generator 4.10
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(482, 275)
        MainWindow.setMinimumSize(QtCore.QSize(0, 0))
        MainWindow.setContextMenuPolicy(QtCore.Qt.NoContextMenu)
        MainWindow.setDocumentMode(False)
        MainWindow.setDockNestingEnabled(False)
        self.centralWidget = QtGui.QWidget(MainWindow)
        self.centralWidget.setObjectName(_fromUtf8("centralWidget"))
        self.horizontalLayout = QtGui.QHBoxLayout(self.centralWidget)
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.webView = QtWebKit.QWebView(self.centralWidget)
        self.webView.setMinimumSize(QtCore.QSize(0, 200))
        self.webView.setUrl(QtCore.QUrl(_fromUtf8("about:blank")))
        self.webView.setObjectName(_fromUtf8("webView"))
        self.horizontalLayout.addWidget(self.webView)
        MainWindow.setCentralWidget(self.centralWidget)
        self.menuBar = QtGui.QMenuBar(MainWindow)
        self.menuBar.setGeometry(QtCore.QRect(0, 0, 482, 22))
        self.menuBar.setObjectName(_fromUtf8("menuBar"))
        self.menuCommand = QtGui.QMenu(self.menuBar)
        self.menuCommand.setObjectName(_fromUtf8("menuCommand"))
        self.menuTools = QtGui.QMenu(self.menuBar)
        self.menuTools.setObjectName(_fromUtf8("menuTools"))
        MainWindow.setMenuBar(self.menuBar)
        self.actionAbout_FacebookNotify = QtGui.QAction(MainWindow)
        self.actionAbout_FacebookNotify.setObjectName(_fromUtf8("actionAbout_FacebookNotify"))
        self.actionGo_Home = QtGui.QAction(MainWindow)
        self.actionGo_Home.setObjectName(_fromUtf8("actionGo_Home"))
        self.actionRefresh = QtGui.QAction(MainWindow)
        self.actionRefresh.setObjectName(_fromUtf8("actionRefresh"))
        self.actionPrevious = QtGui.QAction(MainWindow)
        self.actionPrevious.setObjectName(_fromUtf8("actionPrevious"))
        self.actionNext = QtGui.QAction(MainWindow)
        self.actionNext.setObjectName(_fromUtf8("actionNext"))
        self.actionPreferences = QtGui.QAction(MainWindow)
        self.actionPreferences.setObjectName(_fromUtf8("actionPreferences"))
        self.actionHelp = QtGui.QAction(MainWindow)
        self.actionHelp.setObjectName(_fromUtf8("actionHelp"))
        self.menuCommand.addAction(self.actionGo_Home)
        self.menuCommand.addAction(self.actionRefresh)
        self.menuCommand.addAction(self.actionPrevious)
        self.menuCommand.addAction(self.actionNext)
        self.menuTools.addAction(self.actionPreferences)
        self.menuTools.addSeparator()
        self.menuTools.addAction(self.actionHelp)
        self.menuBar.addAction(self.menuCommand.menuAction())
        self.menuBar.addAction(self.menuTools.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.menuCommand.setTitle(_translate("MainWindow", "Command", None))
        self.menuTools.setTitle(_translate("MainWindow", "Tools", None))
        self.actionAbout_FacebookNotify.setText(_translate("MainWindow", "Settings", None))
        self.actionGo_Home.setText(_translate("MainWindow", "Go Home", None))
        self.actionRefresh.setText(_translate("MainWindow", "Refresh", None))
        self.actionPrevious.setText(_translate("MainWindow", "Previous", None))
        self.actionNext.setText(_translate("MainWindow", "Next", None))
        self.actionPreferences.setText(_translate("MainWindow", "Preferences", None))
        self.actionHelp.setText(_translate("MainWindow", "Help", None))

from PyQt4 import QtWebKit
