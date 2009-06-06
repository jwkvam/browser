#include "urledit.h"

void UrlEdit::setLink(const QString & link, const QString & title, const QString & textContent) {
	setText(link);
}

void UrlEdit::setUrl(const QUrl & url) {
	setText(url.toString());
}
