//============================================================================
// Name        : c11test2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "singleton.h"
#include "singletonNew.h"
#include "SingleteonOnce.h"
#include "SingletonStatic.h"
using namespace std;
class LogTester
{
public:
	LogTester();
	void LogStart();
	~LogTester()
	{

	}

};
LogTester::LogTester()
{

}
void LogTester::LogStart()
{
	cout <<"start log" << endl;
}
int main() {
	atomic<int> testint;
	testint = 4;
	testint.store(6);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Singleton<LogTester>::Instance()->LogStart();
	SingletonNew<LogTester>::Instance()->LogStart();
	SingleteonOnce<LogTester>::Instance().LogStart();
	SingletonStatic<LogTester>::Instance().LogStart();

	return 0;
}
