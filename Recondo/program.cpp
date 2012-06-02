#include <iostream>
#include <cppunit\ui\text\TestRunner.h>
#include "SuperMemo2Test.h"
#include "ItemTest.h"
#include "Item.h"
#include "TxtLoader.h"
#include <algorithm>

//#define TEST 1

using namespace std;
using namespace SuperMemoStrategy;

int main() 
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
		
	#endif

	getchar();
}