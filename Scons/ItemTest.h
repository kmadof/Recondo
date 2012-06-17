#ifndef ITEM_TEST
#define ITEM_TEST

#include "Item.h"
#include "CException.h"
#include <cppunit\TestFixture.h>
#include <cppunit\TestSuite.h>
#include <cppunit\Test.h>
#include <cppunit/extensions/HelperMacros.h>

class ItemTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(ItemTest);
	CPPUNIT_TEST(testGetQuestion);
	CPPUNIT_TEST(testGetAnswer);
	CPPUNIT_TEST(testGetNumberOfRepetitions);
	CPPUNIT_TEST(testGetInterval);
	CPPUNIT_TEST(testSetInterval);
	CPPUNIT_TEST(testGetEFactor);
	CPPUNIT_TEST(testSetEFactor);
	CPPUNIT_TEST(testGetQualityResponse);
	CPPUNIT_TEST(testSetQualityResponse);
	CPPUNIT_TEST_EXCEPTION(testSetQualityResponseException, SuperMemoStrategy::CException);
	CPPUNIT_TEST_SUITE_END();
private:
	SuperMemoStrategy::Item *item;
	const double doublePrecision;
public:
	const string Question;
	const string Answer;

	ItemTest() : Question("HEJ"), Answer("JOL"), doublePrecision(0.000001) {};

	void setUp();
	void tearDown();

	void testGetQuestion();
	void testGetAnswer();
	void testGetNumberOfRepetitions();
	void testIncreaseNumberOfRepetitions();
	void testGetInterval();
	void testSetInterval();
	void testGetEFactor();
	void testSetEFactor();
	void testGetQualityResponse();
	void testSetQualityResponse();
	void testSetQualityResponseException();
	
	//static CppUnit::Test* suite();
};

#endif