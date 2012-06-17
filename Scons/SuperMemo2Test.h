#ifndef SUPERMEMO_2_TEST
#define SUPERMEMO_2_TEST

#include "SuperMemo2.h"
#include <cppunit\TestFixture.h>
#include <cppunit\TestSuite.h>
#include <cppunit\Test.h>

class SuperMemo2Test : public CppUnit::TestFixture
{
private:
	SuperMemoStrategy::SuperMemo2 *memo;
	const double doublePrecision;
public:

	SuperMemo2Test() : doublePrecision(0.000001) {};

	void setUp();
	void tearDown();

	void testSimple();

	void CountIntervalOne();
	void CountIntervalTwo();
	void CountIntervalThree();

	void CountEFactorQualityZero();
	void CountEFactorQualityOne();
	void CountEFactorQualityTwo();
	void CountEFactorQualityThree();
	void CountEFactorQualityFour();
	void CountEFactorQualityFive();
	void CountEFactorSmall();

	static CppUnit::Test* suite();
};

#endif