#include <iostream>
#include <cppunit\ui\text\TestRunner.h>
#include "SuperMemo2Test.h"

using namespace std;


int main() 
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(SuperMemo2Test::suite());
	runner.run();
	getchar();
}

