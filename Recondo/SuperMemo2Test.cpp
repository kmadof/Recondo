#include "SuperMemo2Test.h"
#include "SuperMemo2.h"
#include <cppunit\TestAssert.h>
#include <cppunit\TestCaller.h>
#include <cmath>

void SuperMemo2Test::setUp()
{
	memo = new SuperMemoStrategy::SuperMemo2();
}

void SuperMemo2Test::tearDown()
{
	delete memo;
}

void SuperMemo2Test::testSimple()
{
	CPPUNIT_ASSERT(0 < 1);
}

void SuperMemo2Test::CountIntervalOne()
{
	CPPUNIT_ASSERT(memo->CountInterval(1, 0, 2.5) == 1);
}

void SuperMemo2Test::CountIntervalTwo()
{
	CPPUNIT_ASSERT(memo->CountInterval(2, 0, 2.5) == 6);
}

void SuperMemo2Test::CountIntervalThree()
{
	CPPUNIT_ASSERT(memo->CountInterval(3, 6, 2.5) == 15);
}


void SuperMemo2Test::CountEFactorQualityZero()
{
	CPPUNIT_ASSERT(std::abs(memo->CountEFactor(0, 2.5) - 1.7) < doublePrecision);
}

void SuperMemo2Test::CountEFactorQualityOne()
{
	CPPUNIT_ASSERT(std::abs(memo->CountEFactor(1, 2.5) - 1.96) < doublePrecision);
}

void SuperMemo2Test::CountEFactorQualityTwo()
{
	CPPUNIT_ASSERT(std::abs(memo->CountEFactor(2, 2.5) - 2.18) < doublePrecision);
}

void SuperMemo2Test::CountEFactorQualityThree()
{
	CPPUNIT_ASSERT(std::abs(memo->CountEFactor(3, 2.5) - 2.36) < doublePrecision);
}

void SuperMemo2Test::CountEFactorQualityFour()
{
	CPPUNIT_ASSERT(std::abs(memo->CountEFactor(4, 2.5) - 2.5) < doublePrecision);
}

void SuperMemo2Test::CountEFactorQualityFive()
{
	CPPUNIT_ASSERT(std::abs(memo->CountEFactor(5, 2.5) - 2.6) < doublePrecision);
}

void SuperMemo2Test::CountEFactorSmall()
{
	CPPUNIT_ASSERT(std::abs(memo->CountEFactor(0, 2.0) - 1.3) < doublePrecision);
}

CppUnit::Test* SuperMemo2Test::suite()
{
	CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "SuperMemo2Test" );
	//suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("testSimple", &SuperMemo2Test::testSimple) );
	suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("CountIntervalOne", &SuperMemo2Test::CountIntervalOne) );
	suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("CountIntervalTwo", &SuperMemo2Test::CountIntervalTwo) );
	suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("CountIntervalThree", &SuperMemo2Test::CountIntervalThree) );

	suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("CountEFactorQualityZero", &SuperMemo2Test::CountEFactorQualityZero) );
	suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("CountEFactorQualityOne", &SuperMemo2Test::CountEFactorQualityOne) );
	suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("CountEFactorQualityTwo", &SuperMemo2Test::CountEFactorQualityTwo) );
	suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("CountEFactorQualityThree", &SuperMemo2Test::CountEFactorQualityThree) );
	suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("CountEFactorQualityFour", &SuperMemo2Test::CountEFactorQualityFour) );
	suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("CountEFactorQualityFive", &SuperMemo2Test::CountEFactorQualityFive) );
	suiteOfTests->addTest(new CppUnit::TestCaller<SuperMemo2Test>("CountEFactorSmall", &SuperMemo2Test::CountEFactorSmall) );
	return suiteOfTests;
}