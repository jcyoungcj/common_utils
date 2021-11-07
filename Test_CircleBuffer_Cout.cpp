/*
*Copyright(c) nameix.2021-2021.All right reserved.
*Description:  test CircleBuffer function.
*Author: nameix
*Create: 2021-11-1
*/

#include <iostream>
#include "utils/CircleBuffer.h"

using namespace commonUtils;
using namespace std;

int main(int argc, char** argv)
{	
	CircleBuffer<int> testBuffer{13};
	cout <<"testBufer size= " << testBuffer.size() << std::endl;
	for (size_t i = 0 ; i < testBuffer.size(); i++) {
		cout << "testBuffer: " << i << ", " << testBuffer[i]<< std::endl;
	}
	
	for (size_t i = 500; i < 1000; i++) {
		testBuffer.push(i);
		cout <<"testBufer size= " << testBuffer.size()<< std::endl;
		cout << "testBufer first element= " << testBuffer.first() <<",last element= " << 
			testBuffer.last()<< std::endl;
	}
	for (size_t i = 0 ; i < testBuffer.size(); i++) {
		cout << "testBuffer: " << i << ", " << testBuffer[i]<< std::endl;
	}
	testBuffer.pop();
	cout << "testBufer first element= " << testBuffer.first() <<",last element= " << 
			testBuffer.last()<< std::endl;	
}
