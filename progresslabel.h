#ifndef PROGRESSLABEL_H
#define PROGRESSLABEL_H

#include <QtGui/QLabel>

class ProgressLabel : public QLabel {
	Q_OBJECT

public:
	ProgressLabel();

public slots:
	void start();
	void progress(int progress);
	void finish(bool ok);

protected:
	const static short LENGTH = 12;
	const static char complete = '*';
	const static char incomplete = '-';
};

#endif
