#include <QtGui/QApplication>
#include <QtGui/QBoxLayout>
#include <QtGui/QProgressBar>
#include <QtGui/QPixmap>
//#include <QtGui/QLabel>
//#include <QtGui/QWidget>
//#include <QtWebKit/QWebView>

#include <iostream>

#include "browser.h"
#include "progresslabel.h"
#include "urllabel.h"

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
	command->setWordWrap(true);

//	ProgressLabel *progress = new ProgressLabel;
	QProgressBar *progress = new QProgressBar;
	progress->setRange(0,100);

	UrlLabel *address = new UrlLabel; //(QString("http://www.google.com"));

//	if ( address->pixmap() == NULL ) {
//		std::cout << "out" << std::endl;
//	}
	QPixmap *pixmap = new QPixmap(100, 10);

	pixmap->fill(Qt::white);
	address->setPixmap(*pixmap);

	UrlLabel *link_target = new UrlLabel; 
	QLabel *throbber = new QLabel(QString("-"));

	QHBoxLayout *hlayout = new QHBoxLayout;
	QVBoxLayout *vlayout = new QVBoxLayout;

	hlayout->setContentsMargins(0,0,0,0);
	hlayout->addWidget(progress);
	hlayout->addWidget(address);
	hlayout->addWidget(link_target);
	hlayout->addStretch();
	hlayout->addWidget(throbber);

	Browser *browser = new Browser;

	vlayout->setContentsMargins(0,0,0,0);

	// TODO: make this orientation configurable
	vlayout->addLayout(hlayout);
	vlayout->addWidget(command);
	vlayout->addWidget(browser);

	widget->setLayout(vlayout);
	widget->show();
	
	// command text
	QObject::connect(browser, SIGNAL(commandChanged(const QString &)),
			command, SLOT(setText(const QString &)));
	// display hovered link
	QObject::connect(browser->page(), SIGNAL(linkHovered(const QString &, const QString &, const QString &)),
			link_target, SLOT(setLink(const QString &, const QString &, const QString &)));
	QObject::connect(browser, SIGNAL(urlChanged(const QUrl &)),
			address, SLOT(setUrl(const QUrl &)));

//	QObject::connect(browser, SIGNAL(loadStarted()),
//			progress, SLOT(start()));
	QObject::connect(browser, SIGNAL(loadStarted()),
			progress, SLOT(reset()));
//	QObject::connect(browser, SIGNAL(loadProgress(int)),
//			progress, SLOT(progress(int)));
	QObject::connect(browser, SIGNAL(loadProgress(int)),
			progress, SLOT(setValue(int)));
//	QObject::connect(browser, SIGNAL(loadFinished(bool)),
//			progress, SLOT(finish(bool)));

	return app.exec();
}
