#ifndef LOCATIONEDIT_H
#define LOCATIONEDIT_H

#include <QtGui/QLineEdit>
#include <QtCore/QUrl>

class LocationEdit : public QLineEdit {
	Q_OBJECT
public:
	LocationEdit(QWidget *parent = 0);
public slots:
	void setUrl(const QUrl & url);
};

#endif
