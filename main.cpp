#include <QtGui/QApplication>
#include <QtGui/QBoxLayout>
//#include <QtGui/QLabel>
//#include <QtGui/QWidget>
//#include <QtWebKit/QWebView>

#include <iostream>

#include "browser.h"

/*
void printRect(QRect rect) {
	std::cout << "X     : "<< rect.x();
	std::cout << "Y     : "<< rect.y();
	std::cout << "Width : "<< rect.width();
	std::cout << "Height: "<< rect.height() << std::endl;
} */

int main(int argc, char * argv[]) {
	QApplication app(argc, argv);
//	MainWindow *window = new MainWindow;
//	window->show();
	QWidget *widget = new QWidget;

	QLabel *command = new QLabel;
	QLabel *progress = new QLabel(QString("********"));
	QLabel *address = new QLabel(QString("http://www.google.com"));
	QLabel *throbber = new QLabel(QString("-"));

	QHBoxLayout *hlayout = new QHBoxLayout;
	QVBoxLayout *vlayout = new QVBoxLayout;

	hlayout->setContentsMargins(0,0,0,0);
	hlayout->addWidget(command);
	hlayout->addWidget(progress);
	hlayout->addWidget(address);
	hlayout->addWidget(throbber);

	Browser *browser = new Browser;

	vlayout->setContentsMargins(0,0,0,0);

	// TODO: make this orientation configurable
	vlayout->addLayout(hlayout);
	vlayout->addWidget(browser);

	widget->setLayout(vlayout);
	widget->show();
	
	// Connect signals
	QObject::connect(browser, SIGNAL(commandChanged(const QString)),
			command, SLOT(setText(const QString)));

	return app.exec();
}
