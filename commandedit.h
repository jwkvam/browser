#ifndef COMMANDEDIT_H
#define COMMANDEDIT_H

#include <QtGui/QLineEdit>

class CommandEdit : public QLineEdit {
	Q_OBJECT
public:
	CommandEdit(QWidget *parent = 0);
//public slots:
//	void setLink(const QString & link, const QString & title, const QString & textContent);
};

#endif // COMMANDEDIT_H
