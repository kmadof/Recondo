#include <cppunit\TestFixture.h>
#include <cppunit\TestSuite.h>
#include <cppunit\Test.h>

class SuperMemo2Test : public CppUnit::TestFixture
{
public:
	void setUp();
	void tearDown();

	void testSimple();

	static CppUnit::Test* suite();
};