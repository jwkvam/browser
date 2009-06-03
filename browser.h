#ifndef BROWSER_H
#define BROWSER_H

#include <QtCore/QString>
#include <QtGui/QBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include <QtGui/QKeyEvent>
#include <QtWebKit/QWebView>

class Browser : public QWebView {
		Q_OBJECT

public:
		Browser();

signals:
		void commandChanged(const QString);

protected:
		void keyPressEvent(QKeyEvent *event);
		
private:
		QString command;
		bool command_mode;
};

#endif
