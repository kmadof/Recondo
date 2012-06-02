#include "SuperMemo2Test.h"

#include <cppunit\TestAssert.h>
#include <cppunit\TestCaller.h>

void SuperMemo2Test::setUp()
{
}

void SuperMemo2Test::tearDown()
{
}

void SuperMemo2Test::testSimple()
{
	CPPUNIT_ASSERT(0 < 1);
}

void SuperMemo2Test::CountIntervalOne()
{

}

void SuperMemo2Test::CountIntervalTwo()
{

}

void SuperMemo2Test::CountIntervalThree()
{

}

CppUnit::Test* SuperMemo2Test::suite()
{
	CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "SuperMemo2Test" );
	suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("testSimple", &SuperMemo2Test::testSimple) );
	return suiteOfTests;
}