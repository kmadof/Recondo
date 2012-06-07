#include "XmlSettingsLayer.h"
#include "tinyxml2.h"
#include <string>

using namespace tinyxml2;

XmlSettingsLayer::XmlSettingsLayer() : XML_ROOT("Recondo"), XML_COURSES("Courses"), XML_COURSE_ELEMENT("Course"), XML_COURSE_NAME_ATTRIBUTE("courseName")
{
	_fileSettings = "settings.xml";
}

void XmlSettingsLayer::SaveCourses(Courses courses)
{
	XMLDocument doc;
	if(doc.LoadFile(_fileSettings.c_str()) == XML_NO_ERROR)
	{
		XMLElement* parent;
		parent = doc.FirstChildElement();
		std::string str(parent->Value());
		if(str != XML_ROOT)
		{
			parent = doc.NewElement( XML_ROOT.c_str() );
			doc.InsertFirstChild( parent );
		}
		XMLElement* node;
		node = parent->FirstChildElement();
		str = std::string(node->Value());
		if(str != XML_COURSES)
		{
			node = doc.NewElement( XML_COURSES.c_str() );
			parent->InsertFirstChild(node);
		}

		XMLElement* child;
		for(Courses::const_iterator it = courses.begin(); it != courses.end(); ++it)
		{
			child = doc.NewElement( XML_COURSE_ELEMENT.c_str() );
			child->SetAttribute(XML_COURSE_NAME_ATTRIBUTE.c_str(), it->get()->GetCourseName().c_str());
			XMLText* text = doc.NewText(it->get()->GetPath().c_str());
			child->LinkEndChild(text);
			XMLNode* childNode =node->InsertFirstChild(child);
		}
	
		doc.SaveFile(_fileSettings.c_str());
	}
}

Courses XmlSettingsLayer::LoadCourses()
{
	Courses courses;
	XMLDocument doc;
	if(doc.LoadFile(_fileSettings.c_str()) == XML_NO_ERROR)
	{
		XMLElement* parent;
		parent = doc.FirstChildElement();
		std::string str(parent->Value());
		if(str != XML_ROOT)
		{
			//TODO b³edny plik
			return courses;
		}
		XMLElement* node;
		node = parent->FirstChildElement();
		str = std::string(node->Value());
		if(str != XML_COURSES)
		{
			//TODO b³edny plik
			return courses;
		}

		for( XMLNode* ele = node->FirstChildElement();
			 ele;
			 ele = ele->NextSibling() )
		{
			XMLElement* elementCourse = ele->ToElement();
			std::string courseName = elementCourse->Attribute(XML_COURSE_NAME_ATTRIBUTE.c_str());
			std::string coursePath = elementCourse->GetText();

			courses.push_back(CoursePtr(new CourseItem(courseName, coursePath)));
		}
	}
	return courses;
}

void XmlSettingsLayer::AddCourse(const CourseItem& courseItem)
{
	XMLDocument doc;
	if(doc.LoadFile(_fileSettings.c_str()) == XML_NO_ERROR)
	{
		XMLElement* parent;
		parent = doc.FirstChildElement();
		std::string str(parent->Value());
		if(str != XML_ROOT)
		{
			parent = doc.NewElement( XML_ROOT.c_str() );
			doc.InsertFirstChild( parent );
		}
		XMLElement* node;
		node = parent->FirstChildElement();
		str = std::string(node->Value());
		if(str != XML_COURSES)
		{
			node = doc.NewElement( XML_COURSES.c_str() );
			parent->InsertFirstChild(node);
		}

		XMLElement* child = doc.NewElement( XML_COURSE_ELEMENT.c_str() );
		child->SetAttribute(XML_COURSE_NAME_ATTRIBUTE.c_str(), courseItem.GetCourseName().c_str());
		XMLText* text = doc.NewText(courseItem.GetPath().c_str());
		child->LinkEndChild(text);
		XMLNode* childNode =node->InsertFirstChild(child);
	
		doc.SaveFile(_fileSettings.c_str());
	}
}