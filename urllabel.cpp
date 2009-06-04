#include "urllabel.h"

void UrlLabel::setLink(const QString & link, const QString & title, const QString & textContent) {
	setText(link);
}

void UrlLabel::setUrl(const QUrl & url) {
	setText(url.toString());
}
