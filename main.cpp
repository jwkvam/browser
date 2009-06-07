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
#include "vertlayout.h"
#include "horzlayout.h"

int main(int argc, char * argv[]) {
	QApplication app(argc, argv);
	QWidget *widget = new QWidget;

	QLineEdit *command = new QLineEdit(widget);
//	QLabel *command = new QLabel;
	QFont font( "Typewriter" );
	font.setFixedPitch( true );
	command->setFont( font );
//	command->setWordWrap(true);


	QPalette palette;
	
	//white text
	QBrush brush(Qt::white);
	//black background
	QBrush brush1(Qt::black);
	//set white text    
	palette.setBrush(QPalette::Active, QPalette::Text, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
	//set black background
	palette.setBrush(QPalette::Active, QPalette::Base, brush1);
	palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
	//set palette    
	command->setFrame(false);
	command->setPalette(palette);
	command->setAutoFillBackground(true);

	LocationEdit *address = new LocationEdit(widget); //(QString("http://www.google.com"));
	LinkEdit *link_target = new LinkEdit(widget); 

	QHBoxLayout *hlayout = new QHBoxLayout;
	QVBoxLayout *vlayout = new QVBoxLayout;

	hlayout->setContentsMargins(0,0,0,0);
//	hlayout->addWidget(progress);
	hlayout->addWidget(address);
	hlayout->addWidget(link_target);
//	hlayout->addStretch(0);
//	hlayout->setSpacing(10);

	Browser *browser = new Browser(widget);

	vlayout->setContentsMargins(0,0,0,0);
	vlayout->setSpacing(0);

	// TODO: make this orientation configurable
	vlayout->addLayout(hlayout);
//	vlayout->addWidget(command);
	vlayout->addWidget(browser);

	widget->setLayout(vlayout);
	widget->show();

	////////////////////////////////////////////////////////////////////
	//////////////////////// SIGNALS & SLOTS ///////////////////////////
	////////////////////////////////////////////////////////////////////
	
	// command text
	QObject::connect(browser, SIGNAL(commandChanged(const QString &)),
			command, SLOT(setText(const QString &)));
	// display hovered link
	QObject::connect(browser->page(), SIGNAL(linkHovered(const QString &, const QString &, const QString &)),
			link_target, SLOT(setLink(const QString &, const QString &, const QString &)));
	QObject::connect(browser, SIGNAL(urlChanged(const QUrl &)),
			address, SLOT(setUrl(const QUrl &)));

	return app.exec();
}
