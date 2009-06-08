#include "locationedit.h"

#include <QtGui/QKeyEvent>
#include <iostream>

LocationEdit::LocationEdit(QWidget *parent)
	: QLineEdit(parent)
{
	QPalette palette;

	QBrush textBrush(Qt::green);
	palette.setBrush(QPalette::Active, QPalette::Text, textBrush);
	palette.setBrush(QPalette::Inactive, QPalette::Text, textBrush);

	QBrush bgBrush(Qt::black);
	palette.setBrush(QPalette::Active, QPalette::Base, bgBrush);
	palette.setBrush(QPalette::Inactive, QPalette::Base, bgBrush);

	setPalette(palette);
	setFrame(false);
//	setReadOnly(true);
	setAutoFillBackground(true);
}

void LocationEdit::editUrl(bool selectAll) {
	buffer = text();
	if (selectAll) this->selectAll();
	setFocus(Qt::OtherFocusReason);
}

void LocationEdit::setUrl(const QUrl & url) {
	setText(url.toString());
}

void LocationEdit::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
		QUrl url(text(), QUrl::TolerantMode);
		if (!url.isValid()) {
			std::cout << "invalid!" << std::endl;
		}
		else
			std::cout << "valid!" << std::endl;
		emit urlChanged( url );
	}
	else QLineEdit::keyPressEvent(event);
}
