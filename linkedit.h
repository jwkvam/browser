#ifndef LINKEDIT_H
#define LINKEDIT_H

#include <QtGui/QLineEdit>
#include <QtCore/QUrl>

class LinkEdit : public QLineEdit {
	Q_OBJECT
public:
	LinkEdit(QWidget *parent = 0);
public slots:
	void setLink(const QString & link, const QString & title, const QString & textContent);
};

#endif // LINKEDIT_H
