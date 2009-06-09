#include <QtCore/QEvent>
#include <QtWebKit/QWebPage>
#include <QtWebKit/QWebFrame>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

#include "browser.h"

//const command_t Browser::commands [] = {
//	{"back",         &Browser::back},
//	{"reload",       &Browser::reload}
//};
//const int commands_length = 2;

//const QHash<QString, void (Browser::*)(void)> 
//Browser::commands = {QString("back")   , &Browser::back}; 
//Browser::commands["reload"] = &Browser::reload;


Browser::Browser(QWidget * parent) 
	: QWebView(parent)
{
	load(QUrl("http://google.com"));

	initCommands();
	parseBindings();

	// Make scrollbars invisible
//	page()->mainFrame()->setScrollBarPolicy( Qt::Vertical,   Qt::ScrollBarAlwaysOff );
//	page()->mainFrame()->setScrollBarPolicy( Qt::Horizontal, Qt::ScrollBarAlwaysOff );
	
	setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
	commandMode = TRUE;
	command = "";

	QObject::connect( this, SIGNAL(urlChanged(const QUrl &)),
			this, SLOT(setCommandMode(void)) );
}

/* protected functions */


void Browser::initCommands() {
	commands["back"]                    = &Browser::back;
	commands["forward"]                 = &Browser::forward;
	commands["reload"]                  = &Browser::reload;
	commands["set_insert_mode"]         = &Browser::setInsertMode;
	commands["new_url"]                 = &Browser::urlNew;
	commands["edit_url"]                = &Browser::urlEdit;
}

void Browser::keyPressEvent(QKeyEvent *event) {
//	std::cout << std::hex << event->key() << std::endl;
//	std::cout << std::hex << event->modifiers() << std::endl;
//	std::cout << (int)event->text().toStdString()[0] << " " << event->key() << std::endl;
	if (commandMode) {
		if ( shortcuts[ QPair<uint, char>(event->modifiers(), event->text().toStdString()[0]) ] ) {
			(this->*shortcuts[ QPair<uint, char>(event->modifiers(), event->text().toStdString()[0]) ])(); 
		}
		else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
			QWebView::keyPressEvent(event);
		}
//		else if (event->key() == Qt::Key_Return) {
//			command = "";
//			 TODO: execute command
//		}
//		else if (event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete) {
//			command.chop(1);
//		}
//		else if (event->key() == Qt::Key_Escape || 
//				(event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_C) ) {
//			command = "";
//		}
//		else {
//			command.append(event->text());
//		}
//		emit commandChanged(command);
	}
	else if (event->key() == Qt::Key_Escape || 
				(event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_C) ) {
		setCommandMode();
	}
	else QWebView::keyPressEvent(event);
}

void Browser::parseBindings(void) {
	std::string line, cmd, function, args;
	std::ifstream myfile("config/bindings");
	if (myfile.is_open()) {
		while (! myfile.eof() ) {
			cmd = function = args = "";
			std::getline( myfile, line );
			std::istringstream iss(line, std::istringstream::in);
			iss >> cmd;
			if (cmd != "" && cmd[0] != '#') {
				iss >> function >> args;
				if (function != "") {
					if (cmd.length() == 1) {
//						std::cout << cmd << " " << function << " " << args << std::endl;
						shortcuts[ QPair<uint, char>(Qt::NoModifier, cmd[0]) ] = commands[QString::fromStdString(function)];
					}
				}
				else {
					std::cerr << "No function for command: [" << cmd << "]" << std::endl;
					continue;
				}
			}
		}
		myfile.close();
	}
	else std::cerr << "Unable to open bindings" << std::endl;
}

void Browser::setInsertMode(void) {
	if (commandMode) {
		commandMode = false;
		emit modeChanged(true);
	}
}

void Browser::urlNew(void) {
	emit editUrl(true);
}

void Browser::urlEdit(void) {
	emit editUrl(false);
}

/* protected slots */

void Browser::loadUrl(const QUrl & url) {
	setFocus(Qt::OtherFocusReason);
	load(url);
}

void Browser::receiveCommand(const Qstring & command) {
	(this->*shortcuts[ QPair<uint, char>(event->modifiers(), event->text().toStdString()[0]) ])(); 
}

void Browser::receiveFocus(void) {
	std::cout << "received focus" << std::endl;
	setFocus();
}

void Browser::setCommandMode(void) {
	if (!commandMode) {
		commandMode = true;
		emit modeChanged(false);
	}
}
