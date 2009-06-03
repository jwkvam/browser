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
	
	setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
	command_mode = TRUE;
	command = "";
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
