#include "XmlSettingsLayer.h"
#include "tinyxml2.h"
#include <string>

using namespace tinyxml2;

XmlSettingsLayer::XmlSettingsLayer() : XML_ROOT("Recondo"), XML_COURSES("Courses"), XML_COURSE_ELEMENT("Course"), XML_COURSE_NAME_ATTRIBUTE("courseName"), 
	XML_CURRENT_COURSE("CurrentCurses"), XML_CURRENT_COURSE_ELEMENT("CurrentCourse"), XML_CURRENT_COURSE_NAME_ATTRIBUTE("courseName")
{
	_fileSettings = "settings.xml";
	_currentCourse;
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

		for( XMLNode* ele = parent->FirstChildElement();
			 ele;
			 ele = ele->NextSibling() )
		{
			XMLElement* elementCourse = ele->ToElement();
			str = std::string(elementCourse->Value());
			if(str == XML_COURSES)
			{
				node = elementCourse;
				break;
			}
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

		for( XMLNode* ele = parent->FirstChildElement();
			 ele;
			 ele = ele->NextSibling() )
		{
			XMLElement* elementCourse = ele->ToElement();
			str = std::string(elementCourse->Value());
			if(str == XML_COURSES)
			{
				node = elementCourse;
				break;
			}
		}
		//node = parent->FirstChildElement();
		//str = std::string(node->Value());
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

		for( XMLNode* ele = parent->FirstChildElement();
			 ele;
			 ele = ele->NextSibling() )
		{
			XMLElement* elementCourse = ele->ToElement();
			str = std::string(elementCourse->Value());
			if(str == XML_COURSES)
			{
				node = elementCourse;
				break;
			}
		}

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

void XmlSettingsLayer::RemoveCourse(const CourseItem& courseItem)
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

		for( XMLNode* ele = node->FirstChildElement();
			 ele;
			 ele = ele->NextSibling() )
		{
			XMLElement* elementCourse = ele->ToElement();
			std::string courseName = elementCourse->Attribute(XML_COURSE_NAME_ATTRIBUTE.c_str());
			std::string coursePath = elementCourse->GetText();
			if(courseName == courseItem.GetCourseName() && coursePath == courseItem.GetPath()) {}
			{
				node->DeleteChild(ele);
				break;
			}

		}
	
		doc.SaveFile(_fileSettings.c_str());
	}
}

void XmlSettingsLayer::SetCurrentCourse(const CourseItem& course)
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
		if(str != XML_CURRENT_COURSE)
		{
			node = doc.NewElement( XML_CURRENT_COURSE.c_str() );
			parent->InsertFirstChild(node);
		}
		
		XMLElement* child = node->FirstChildElement();
		if(child != NULL)
			node->DeleteChild(child);

		child = doc.NewElement( XML_CURRENT_COURSE_ELEMENT.c_str() );
		child->SetAttribute( XML_CURRENT_COURSE_NAME_ATTRIBUTE.c_str() , course.GetCourseName().c_str() );
		
		XMLText* text = doc.NewText( course.GetPath().c_str() );
		child->LinkEndChild(text);
		XMLNode* childNode =node->InsertFirstChild(child);
	
		doc.SaveFile(_fileSettings.c_str());
	}
}

CourseItem XmlSettingsLayer::LoadCurrentCourse()
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

		if(str != XML_CURRENT_COURSE)
		{
			node = doc.NewElement( XML_CURRENT_COURSE.c_str() );
			parent->InsertFirstChild(node);
		}
		else
		{
			XMLElement* child = node->FirstChildElement();
			if(child != NULL)
			{
				std::string courseName = child->Attribute( XML_CURRENT_COURSE_NAME_ATTRIBUTE.c_str() );
				std::string coursePath = child->GetText();

				return CourseItem(courseName, coursePath);		
			}
		}
		return CourseItem();
	}
}