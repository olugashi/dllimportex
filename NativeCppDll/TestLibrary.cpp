#include "pch.h"
#include "TestLibrary.h"

void Test()
{
	printf("Test");
	return  ;
}

void TestPoint(PointStruct p )
{
	printf("TestPoint");
	return;
}

void TestArray(TestStruct *p)
{
	printf("TestArray");

	for (size_t i = 0; i < 10; i++)
	{
		p->values[i] = p->values[i] * i;
	}
	return;
}

TestStructPtr* TestReturnArrayPtr(TestStructPtr* prt)
{
	TestStructPtr* p = new TestStructPtr();

	p->length = 5;
	p->values = new int[10];
	/*(*ptr)->length = 5;
	
	(*ptr)->values = new int[10];
	*/
	for (size_t i = 0; i < 10; i++)
	{
		p->values[i]= i;
	}

	return p;
}
