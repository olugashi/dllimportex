//#pragma once

#include <iostream>
using namespace std;

#ifdef TEST_LIBRARY_EXPORTS
#define TEST_LIBRARY __declspec(dllexport)
#else
#define TEST_LIBRARY __declspec(dllimport)
#endif 

struct TestStruct { // note typedef is not needed */
    int length;
    int values[]; // specified the size
};

struct TestStructPtr { // note typedef is not needed */
    int length;
    int *values; // specified the size

public:
    TestStructPtr()
    {

    }
};
 



struct PointStruct { 
    int X;
    int Y;
};



extern "C" TEST_LIBRARY void Test();
extern "C" TEST_LIBRARY void TestPoint(PointStruct p);
extern "C" TEST_LIBRARY void TestArray(TestStruct *p);
//extern "C" TEST_LIBRARY TestStructPtr* TestReturnArrayPtr();
//extern "C" TEST_LIBRARY void TestReturnArrayPtr(TestStructPtr** ptr);
extern "C" TEST_LIBRARY TestStructPtr* TestReturnArrayPtr(TestStructPtr* prt);
//extern "C" TEST_LIBRARY TestStruct* TestArray();