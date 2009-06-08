#ifndef INSERTLABEL_H
#define INSERTLABEL_H

#include <QtGui/QLabel>

class InsertLabel : public QLabel {
	Q_OBJECT

public:
	InsertLabel(QWidget *parent = 0);

public slots:
	void modeChanged(bool insertMode);
};

#endif // INSERTLABEL_H
