#include <QtCore/QEvent>

#include <QtWebKit/QWebPage>
#include <QtWebKit/QWebFrame>

#include <iostream>

#include "browser.h"

Browser::Browser() 
{
	load(QUrl("http://google.com"));

	// Make scrollbars invisible
//	page()->mainFrame()->setScrollBarPolicy( Qt::Vertical,   Qt::ScrollBarAlwaysOff );
//	page()->mainFrame()->setScrollBarPolicy( Qt::Horizontal, Qt::ScrollBarAlwaysOff );
	
	command_mode = TRUE;
	command = "";
//	browser->installEventFilter(this);

//	setFocusPolicy(Qt::StrongFocus);
}

void Browser::keyPressEvent(QKeyEvent *event) {
//	std::cout << std::hex << event->key() << std::endl;
//	std::cout << std::hex << event->modifiers() << std::endl;
	if (command_mode) {
		if (event->key() == Qt::Key_I && command == "") {
			command_mode = FALSE;
		}
		else if (event->key() == Qt::Key_Return) {
			command = "";
			// TODO: execute command
		}
		else if (event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete) {
			command.chop(1);
		}
		else if (event->key() == Qt::Key_Escape || 
				(event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_C) ) {
			command = "";
		}
		else {
			command.append(event->text());
		}
		emit commandChanged(command);
	}
	else if (event->key() == Qt::Key_Escape || 
				(event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_C) ) {
		command_mode = TRUE;
	}
	else QWebView::keyPressEvent(event);
}

/*
bool Browser::event(QEvent *event) {
//		std::cout << "received key event" << std::endl;
	if (event->type() == QEvent::KeyPress) {
		std::cout << "received key event" << std::endl;
		emit commandChanged(QString("a"));
//		return true;
	}

	// TODO: should we be calling the inherited event 
	// function instead of QWidget::event
	return QWidget::event(event);
}*/
