#include "mainwindow.h"

#include <QtCore/QEvent>

#include <QtWebKit/QWebPage>
#include <QtWebKit/QWebFrame>

#include <iostream>

MainWindow::MainWindow() 
{
	layout = new QVBoxLayout(this);
	browser = new QWebView;
	label = new QLabel;
	layout->setContentsMargins(0,0,0,0);
	layout->addWidget(label);
	layout->addWidget(browser);
	setLayout(layout);

	browser->load(QUrl("http://google.com"));
	label->setText("http://google.com");

	// Make scrollbars invisible
	browser->page()->mainFrame()->setScrollBarPolicy( Qt::Vertical,   Qt::ScrollBarAlwaysOff );
	browser->page()->mainFrame()->setScrollBarPolicy( Qt::Horizontal, Qt::ScrollBarAlwaysOff );
	
	browser->installEventFilter(this);

	setFocusPolicy(Qt::StrongFocus);
}

bool MainWindow::event(QEvent *event) {
//		std::cout << "received key event" << std::endl;
	if (event->type() == QEvent::KeyPress) {
		std::cout << "received key event" << std::endl;
		return true;
	}

	// TODO: should we be calling the inherited event 
	// function instead of QWidget::event
	return QWidget::event(event);
}

bool MainWindow::eventFilter(QObject *object, QEvent *event) {
//	if (object == target && event->type() == QEvent::KeyPress) {
//		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
//		if (keyEvent->key() == Qt::Key_Tab) {
			 //Special tab handling
//			return true;
//		} else
//			return false;
//	}
//	if (event->type() == QEvent::KeyPress) {
//		std::cout << "filtered key event" << std::endl;
//		return true;
//	}
	return false;
}
