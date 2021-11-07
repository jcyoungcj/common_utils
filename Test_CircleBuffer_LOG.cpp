/*
*Copyright(c) nameix.2021-2021.All right reserved.
*Description:  test CircleBuffer function.
*Author: nameix
*Create: 2021-11-1
*/

#include <gflags/gflags.h>
#include <glog/logging.h>
#include "utils/CircleBuffer.h"

using namespace commonUtils;
using namespace std;

int main(int argc, char** argv)
{
	// log init
	google::InitGoogleLoggig(argv[0]);
	FLAGS_alsologtostdder = true;
	
	CircleBuffer<int> testBuffer{13};
	LOG(INFO) <<"testBufer size= " << testBuffer.size();
	for (size_t i = 0 ; i < testBuffer.size(); i++) {
		LOG(INFO) << "testBuffer: " << i << ", " << testBuffer[i];
	}
	
	for (size_t i = 500; i < 1000; i++) {
		testBuffer.push(i);
		LOG(INFO) <<"testBufer size= " << testBuffer.size();
		LOG(INFO) << "testBufer first element= " << testBuffer.first() <<",last element= " << 
			testBuffer.last();
	}
	for (size_t i = 0 ; i < testBuffer.size(); i++) {
		LOG(INFO) << "testBuffer: " << i << ", " << testBuffer[i];
	}
	testBuffer.pop();
	LOG(INFO) << "testBufer first element= " << testBuffer.first() <<",last element= " << 
			testBuffer.last();	
}
