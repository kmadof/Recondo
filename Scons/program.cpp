#include <iostream>
#include <fstream> 
#include <cppunit\ui\text\TestRunner.h>
#include <boost/archive/xml_oarchive.hpp> 
#include <boost/archive/xml_iarchive.hpp> 
#include "SuperMemo2Test.h"
#include "ItemTest.h"
#include "Item.h"
#include "Course.h"
#include "TxtLoader.h"
#include <algorithm>

//#define TEST 1

using namespace std;
using namespace SuperMemoStrategy;

void save(Course course)
{
  std::ofstream file("archive.xml"); 
  boost::archive::xml_oarchive oa(file); 
  oa & BOOST_SERIALIZATION_NVP(course); 
}

Course load() 
{ 
  std::ifstream file("archive.xml"); 
  boost::archive::xml_iarchive ia(file); 
  Course course; // Need to specify expected array size
  ia >> BOOST_SERIALIZATION_NVP(course);
  return course;
} 

int main(int argc, char *argv[]) 
{

	#if TEST
		CppUnit::TextUi::TestRunner runner;
		runner.addTest(SuperMemo2Test::suite());
		runner.addTest(ItemTest::suite());
		runner.run();
	#else
		/*SuperMemo2* memo = new SuperMemo2();

		cout << memo->CountEFactor(0, 2.5) << endl;
		cout << memo->CountEFactor(2, 2.5) << endl;*/

		//Item item("be", "byæ");
		//ItemPtr itemLoaded;


		Items items;

		//cout << item.GetQuestion() << " " << item.GetAnswer() << endl;

		TxtLoader* loader = new TxtLoader();
		items = loader->Load("d:\\Projects\\C++\\Recondo\\Debug\\example.txt");
		
		for(Items::const_iterator ptr = items.begin(); ptr != items.end(); ++ptr)
			cout << ptr->get()->GetQuestion() << " " << ptr->get()->GetAnswer() << endl;
		//Course course;
		//course.SetLastRunDate();
		//course.SetItems(items);

		//save(course);
		//getchar();

		//Course course2 = load();
		
		loader->Save(items, "d:\\Projects\\C++\\Recondo\\Debug\\test.txt");
		
		getchar();
	#endif

}