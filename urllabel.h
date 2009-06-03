#ifndef URLLABEL_H
#define URLLABEL_H

#include <QtGui/QLabel>

class UrlLabel : public QLabel {
	Q_OBJECT
//public:
//	UrlLabel();
public slots:
	void setUrl(const QString & link, const QString & title, const QString & textContent);
};

#endif
