#include <QtGui/QApplication>
#include <QtGui/QBoxLayout>
#include <QtGui/QProgressBar>
#include <QtGui/QPixmap>
//#include <QtGui/QLabel>
//#include <QtGui/QWidget>
//#include <QtWebKit/QWebView>

#include <iostream>

#include "browser.h"
#include "linkedit.h"
#include "locationedit.h"
#include "commandedit.h"
#include "insertlabel.h"

int main(int argc, char * argv[]) {
	QApplication app(argc, argv);
	QWidget *widget = new QWidget;

	CommandEdit *command = new CommandEdit;

	InsertLabel *insertLabel = new InsertLabel;

	LocationEdit *address = new LocationEdit(widget); //(QString("http://www.google.com"));
	address->setFocusPolicy(Qt::ClickFocus);

	LinkEdit *link_target = new LinkEdit(widget); 
	link_target->setFocusPolicy(Qt::NoFocus);

	QHBoxLayout *statusBar = new QHBoxLayout;
	QVBoxLayout *vlayout = new QVBoxLayout;

	statusBar->setContentsMargins(0,0,0,0);
	statusBar->addWidget(insertLabel);
	statusBar->addWidget(address);
	statusBar->addWidget(link_target);

	Browser *browser = new Browser;

	vlayout->setContentsMargins(0,0,0,0);
	vlayout->setSpacing(0);

	vlayout->addLayout(statusBar);
	vlayout->addWidget(command);
	vlayout->addWidget(browser);

	widget->setLayout(vlayout);
	widget->show();

	////////////////////////////////////////////////////////////////////
	//////////////////////// SIGNALS & SLOTS ///////////////////////////
	////////////////////////////////////////////////////////////////////
	
	// command text
//	QObject::connect(browser, SIGNAL(commandChanged(const QString &)),
//			command, SLOT(setText(const QString &)));
	// display hovered link
	QObject::connect(browser->page(), SIGNAL(linkHovered(const QString &, const QString &, const QString &)),
			link_target, SLOT(setLink(const QString &, const QString &, const QString &)));
	QObject::connect(browser, SIGNAL(urlChanged(const QUrl &)),
			address, SLOT(setUrl(const QUrl &)));
	QObject::connect(browser, SIGNAL(modeChanged(bool)),
			insertLabel, SLOT(modeChanged(bool)));
	QObject::connect(browser, SIGNAL(editUrl(bool)),
			address, SLOT(editUrl(bool)));
	QObject::connect(address, SIGNAL(urlChanged(const QUrl &)),
			browser, SLOT(loadUrl(const QUrl &)));

	return app.exec();
}
