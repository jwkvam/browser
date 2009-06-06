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
#include "urledit.h"
#include "locationedit.h"

int main(int argc, char * argv[]) {
	QApplication app(argc, argv);
	QWidget *widget = new QWidget;

	QLineEdit *command = new QLineEdit;
//	QLabel *command = new QLabel;
	QFont font( "Typewriter" );
	font.setFixedPitch( true );
	command->setFont( font );
//	command->setWordWrap(true);


	QPalette palette;
	
	//white text
//	QBrush brush(QColor(255, 255, 255, 255));
	QBrush brush(Qt::white);
	brush.setStyle(Qt::SolidPattern);

	//black background
	QBrush brush1(Qt::black);
	brush1.setStyle(Qt::SolidPattern);
	
    //set white text    
//	palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
//	palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
	palette.setBrush(QPalette::Active, QPalette::Text, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Text, brush);

	//set black background
//	palette.setBrush(QPalette::Active, QPalette::Window, brush1);
//	palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
	palette.setBrush(QPalette::Active, QPalette::Base, brush1);
	palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
	
    //set palette    
	command->setFrame(false);
	command->setPalette(palette);
	command->setAutoFillBackground(true);
//	command->setContentsMargins(0,0,0,0);


//	ProgressLabel *progress = new ProgressLabel;
//	QProgressBar *progress = new QProgressBar;
//	progress->setRange(0,100);

//	UrlLabel *address = new UrlLabel; //(QString("http://www.google.com"));
	LocationEdit *address = new LocationEdit; //(QString("http://www.google.com"));
//	address->setReadOnly(true);
//	address->setFrame(false);
//	address->setReadOnly(true);

	UrlEdit *link_target = new UrlEdit; 
	link_target->setFrame(false);
	link_target->setReadOnly(true);

	QHBoxLayout *hlayout = new QHBoxLayout;
	QVBoxLayout *vlayout = new QVBoxLayout;

	hlayout->setContentsMargins(0,0,0,0);
//	hlayout->addWidget(progress);
	hlayout->addWidget(address);
	hlayout->addWidget(link_target);

	Browser *browser = new Browser;

	vlayout->setContentsMargins(0,0,0,0);
	vlayout->setSpacing(0);

	// TODO: make this orientation configurable
	vlayout->addLayout(hlayout);
	vlayout->addWidget(command);
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

//	QObject::connect(browser, SIGNAL(loadStarted()),
//			progress, SLOT(start()));
//	QObject::connect(browser, SIGNAL(loadStarted()),
//			progress, SLOT(reset()));
//	QObject::connect(browser, SIGNAL(loadProgress(int)),
//			progress, SLOT(progress(int)));
//	QObject::connect(browser, SIGNAL(loadProgress(int)),
//			progress, SLOT(setValue(int)));
//	QObject::connect(browser, SIGNAL(loadFinished(bool)),
//			progress, SLOT(finish(bool)));

	return app.exec();
}

/*
void printRect(QRect rect) {
	std::cout << "X     : "<< rect.x();
	std::cout << "Y     : "<< rect.y();
	std::cout << "Width : "<< rect.width();
	std::cout << "Height: "<< rect.height() << std::endl;
} */
