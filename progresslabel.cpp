#include <cmath>
#include "progresslabel.h"

ProgressLabel::ProgressLabel() : QLabel(QString(LENGTH, QChar(complete))) { } 

void ProgressLabel::start() {
	setText(QString(LENGTH, QChar(incomplete)));
}

void ProgressLabel::progress(int progress) {
	short completed = floor(progress / (100 / 12));
	setText(QString(completed, QChar(complete)) + 
			QString(LENGTH-completed, QChar(incomplete)));
}

void ProgressLabel::finish(bool ok) {
	if (ok) {
		setText(QString(LENGTH, QChar(complete)));
	}
	else
		setText(QString("----ERROR---"));
}
