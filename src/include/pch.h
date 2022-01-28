/* 
* this files implement the true main function, no matter cpp file with including this head file
* implement 'main' or not, it will work for sure by class deliver.
* Just remember to inlcude this file before the 'main' implement
*/
#pragma once
#include <string>
#include <bits/stdc++.h>
#include<gtest/gtest.h>
using namespace std;
function<int()> delegateMain;
template<typename T>
struct deliver{
	int _xmain();
	operator function<int()>() {
		return []() {
			return deliver<T>()._xmain();
		};
	}
};
int main() {
	if (delegateMain != nullptr)
		delegateMain();
	::testing::InitGoogleTest();
	RUN_ALL_TESTS();
	return 0;
}					
/*
* instead of declare the _ABx as static to support muilti cpp feils to include this,
* let this be global scope variable just make thing clearer
*/
#define main   _AB1 = 0;\
deliver<int>;\
int _AB2 = (delegateMain = deliver<int>(), 0);\
int deliver<int>::_xmain