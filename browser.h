#ifndef BROWSER_H
#define BROWSER_H

#include <QtCore/QString>
#include <QtCore/QHash>
#include <QtGui/QBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include <QtGui/QKeyEvent>
#include <QtWebKit/QWebView>

#include <string>

class Browser;

struct command_t {
	std::string name;
	void (Browser::*funcPtr)(void);
};

class Browser : public QWebView {
	Q_OBJECT

public:
	Browser(QWidget *parent = 0);

signals:
	void commandChanged(const QString);

protected:
	void initCommands(void);
	void keyPressEvent(QKeyEvent *event);
	void parseBindings(void);
	void toggleInsertMode(void);

	QString command;
	bool commandMode;
	QHash<QPair<uint, char>, void (Browser::*)(void)> shortcuts;
	QHash<QString, void (Browser::*)(void)> commands;

protected slots:
	void resetCommandMode(void);

};

#endif // BROWSER_H
