#ifndef URLLINEEDIT_H
#define URLLINEEDIT_H

#include <QtGui/QLineEdit>
#include <QtCore/QUrl>

class UrlEdit : public QLineEdit {
	Q_OBJECT
public slots:
	void setLink(const QString & link, const QString & title, const QString & textContent);
	void setUrl(const QUrl & url);
};

#endif
