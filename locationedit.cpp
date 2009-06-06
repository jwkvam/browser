#include "locationedit.h"

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
	setReadOnly(true);
	setAutoFillBackground(true);
}

void LocationEdit::setUrl(const QUrl & url) {
	setText(url.toString());
}
