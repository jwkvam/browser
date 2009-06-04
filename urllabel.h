#ifndef URLLABEL_H
#define URLLABEL_H

#include <QtGui/QLabel>
#include <QtCore/QUrl>

class UrlLabel : public QLabel {
	Q_OBJECT
public slots:
	void setLink(const QString & link, const QString & title, const QString & textContent);
	void setUrl(const QUrl & url);
};

#endif
