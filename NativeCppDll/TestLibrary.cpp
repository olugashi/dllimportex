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

TestStructPtr __stdcall TestReturnArrayPtr()
{
	TestStructPtr* myStruct = new TestStructPtr();

	// Allocate an array of integers
	int* myArray = new int[10];
	for (int i = 0; i < 10; i++) {
		myArray[i] = i + 1;
	}

	// Assign the array pointer to the struct
	myStruct->values = myArray;

	// Return the struct
	return myStruct[0];

}
