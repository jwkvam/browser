#include "insertlabel.h"
#include <iostream>

InsertLabel::InsertLabel(QWidget *parent) :
	QLabel(parent)
{
	QPalette palette;

	QBrush textBrush(Qt::darkYellow);
	palette.setBrush(QPalette::Active, QPalette::WindowText, textBrush);
	palette.setBrush(QPalette::Inactive, QPalette::WindowText, textBrush);

	QBrush bgBrush(Qt::black);
	palette.setBrush(QPalette::Active, QPalette::Window, bgBrush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, bgBrush);

	setPalette(palette);
	setAutoFillBackground(true);

	setText("-- INSERT --");
	hide();
}

void InsertLabel::modeChanged(bool insertMode) {
	if (insertMode) {
		show();
	}
	else {
		hide();
	}
}
