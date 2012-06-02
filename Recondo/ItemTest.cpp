#include "ItemTest.h"
#include "Item.h"
#include <iostream>
#include <cppunit\TestAssert.h>
#include <cppunit\TestCaller.h>
#include <cmath>

void ItemTest::setUp()
{
	item = new SuperMemoStrategy::Item(ItemTest::Question, ItemTest::Answer);
}

void ItemTest::tearDown()
{
	delete item;
}

void ItemTest::testGetQuestion()
{
	CPPUNIT_ASSERT(item->GetQuestion() == ItemTest::Question);
}

void ItemTest::testGetAnswer()
{
	CPPUNIT_ASSERT(item->GetAnswer() == ItemTest::Answer);
}

void ItemTest::testGetNumberOfRepetitions()
{
	CPPUNIT_ASSERT(item->GetNumberOfRepetitions() == 0);
}
	
void ItemTest::testIncreaseNumberOfRepetitions()
{
	CPPUNIT_ASSERT(item->GetNumberOfRepetitions() == 0);
	item->IncreaseNumberOfRepetitions();
	CPPUNIT_ASSERT(item->GetNumberOfRepetitions() == 1);
}

void ItemTest::testGetInterval()
{
	CPPUNIT_ASSERT(item->GetInterval() == 1);
}

void ItemTest::testSetInterval()
{
	CPPUNIT_ASSERT(item->GetInterval() == 1);
	item->SetInterval(10);
	CPPUNIT_ASSERT(item->GetInterval() == 10);
}

void ItemTest::testGetEFactor()
{
	double temp = item->GetEFactor();
	CPPUNIT_ASSERT(std::abs(temp - 2.5) < doublePrecision);
}

void ItemTest::testSetEFactor()
{
	double temp = item->GetEFactor();
	CPPUNIT_ASSERT(std::abs(temp - 2.5) < doublePrecision);
	item->SetEFactor(3.45);
	temp = item->GetEFactor();
	CPPUNIT_ASSERT(std::abs(temp - 3.45) < doublePrecision);
}

void ItemTest::testGetQualityResponse()
{
	CPPUNIT_ASSERT(item->GetQualityResponse() == 0);
}

void ItemTest::testSetQualityResponse()
{
	CPPUNIT_ASSERT(item->GetQualityResponse() == 0);
	item->SetQualityResponse(4);
	CPPUNIT_ASSERT(item->GetQualityResponse() == 4);
}

void ItemTest::testSetQualityResponseException()
{
	CPPUNIT_ASSERT(item->GetQualityResponse() == 0);
	item->SetQualityResponse(6);
}

//CppUnit::Test* ItemTest::suite()
//{
//	CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "ItemTest" );
//	suiteOfTests->addTest(new CppUnit::TestCaller<ItemTest>("testGetQuestion", &ItemTest::testGetQuestion) );
//	suiteOfTests->addTest(new CppUnit::TestCaller<ItemTest>("testGetAnswer", &ItemTest::testGetAnswer) );
//	suiteOfTests->addTest(new CppUnit::TestCaller<ItemTest>("testGetNumberOfRepetitions", &ItemTest::testGetNumberOfRepetitions) );
//	suiteOfTests->addTest(new CppUnit::TestCaller<ItemTest>("testIncreaseNumberOfRepetitions", &ItemTest::testIncreaseNumberOfRepetitions) );
//	suiteOfTests->addTest(new CppUnit::TestCaller<ItemTest>("testGetInterval", &ItemTest::testGetInterval) );
//	suiteOfTests->addTest(new CppUnit::TestCaller<ItemTest>("testSetInterval", &ItemTest::testSetInterval) );
//	suiteOfTests->addTest(new CppUnit::TestCaller<ItemTest>("testGetEFactor", &ItemTest::testGetEFactor) );
//	suiteOfTests->addTest(new CppUnit::TestCaller<ItemTest>("testSetEFactor", &ItemTest::testSetEFactor) );
//
//	suiteOfTests->addTest(new CppUnit::TestCaller<ItemTest>("testGetQualityResponse", &ItemTest::testGetQualityResponse) );
//	suiteOfTests->addTest(new CppUnit::TestCaller<ItemTest>("testSetQualityResponse", &ItemTest::testSetQualityResponse) );
//	suiteOfTests->addTest(new CppUnit::TestCaller<ItemTest>("testSetQualityResponseException", &ItemTest::testSetQualityResponseException) );
//	return suiteOfTests;
//}