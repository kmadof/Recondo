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

	//XmlSettingsLayer xmlLayer;
	//Courses courses;
	//courses.push_back(CoursePtr(new CourseItem("siema", "siema")));
	//courses.push_back(CoursePtr(new CourseItem("siema", "siema")));
	//courses.push_back(CoursePtr(new CourseItem("siema", "siema")));
	////xmlLayer.SaveCourses(courses);
	//xmlLayer.LoadCourses();
	return a.exec();
}
