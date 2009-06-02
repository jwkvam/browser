//#include <QtCore/QUrl>
#include <QtGui/QApplication>
//#include <QtGui/QBoxLayout>
//#include <QtGui/QLabel>
//#include <QtGui/QWidget>
//#include <QtWebKit/QWebView>

#include <iostream>

#include "mainwindow.h"

void printRect(QRect rect) {
	std::cout << "X     : "<< rect.x();
	std::cout << "Y     : "<< rect.y();
	std::cout << "Width : "<< rect.width();
	std::cout << "Height: "<< rect.height() << std::endl;
}

int main(int argc, char * argv[]) {
	QApplication app(argc, argv);
	MainWindow *window = new MainWindow;
	window->show();
	return app.exec();
}
