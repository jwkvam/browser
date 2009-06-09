#ifndef LOCATIONEDIT_H
#define LOCATIONEDIT_H

#include <QtGui/QLineEdit>
#include <QtCore/QUrl>

class LocationEdit : public QLineEdit {
	Q_OBJECT

public:
	LocationEdit(QWidget *parent = 0);

signals:
	void focusBrowser(void);
	void urlChanged(const QUrl & url);

public slots:
	void setUrl(const QUrl & url);
	void editUrl(bool selectAll);

protected:
	void keyPressEvent(QKeyEvent *event);

private:
	QString buffer;
};

#endif
