#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

class MainWindow : public QWidget {
		Q_OBJECT

public:
		MainWindow();

protected:
		bool event(QEvent *event);
		bool eventFilter(QObject *object, QEvent *event);
		
private:
		QLabel *label;
		QWebView *browser;
		QVBoxLayout *layout;
};

#endif
