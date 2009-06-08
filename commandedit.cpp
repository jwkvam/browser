#include "commandedit.h"

//#include

CommandEdit::CommandEdit(QWidget *parent)
	: QLineEdit(parent)
{
	QPalette palette;

	QBrush textBrush(Qt::red);
	palette.setBrush(QPalette::Active, QPalette::Text, textBrush);
	palette.setBrush(QPalette::Inactive, QPalette::Text, textBrush);

	QBrush bgBrush(Qt::black);
	palette.setBrush(QPalette::Active, QPalette::Base, bgBrush);
	palette.setBrush(QPalette::Inactive, QPalette::Base, bgBrush);

	setPalette(palette);
	setFrame(false);
	setReadOnly(true);
	setAutoFillBackground(true);

	QFont font("Typewriter");
	font.setFixedPitch(true);
	font.setBold(true);
	setFont( font );

	hide();
}

//void LinkEdit::setLink(const QString & link, const QString & title, const QString & textContent) {
//	setText(link);
//}
