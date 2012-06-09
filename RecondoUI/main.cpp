#include "RecondoUi.h"
#include <QtGui/QApplication>
#include "XmlSettingsLayer.h"
#include "CourseItem.h"
#include "tinyxml2.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RecondoUI w;
	w.show();

	return a.exec();
}
