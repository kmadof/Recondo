#include <cppunit\TestFixture.h>
#include <cppunit\TestSuite.h>
#include <cppunit\Test.h>

class SuperMemo2Test : public CppUnit::TestFixture
{
public:
	void setUp();
	void tearDown();

	void testSimple();

	void CountIntervalOne();

	void CountIntervalTwo();

	void CountIntervalThree();

	static CppUnit::Test* suite();
};