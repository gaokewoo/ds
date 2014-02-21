#include <iostream>
#include "gtest/gtest.h"

using namespace std;

class ListTest:public testing::Test{
    protected:

        virtual void SetUp(){
            s="abc";
        }

        string s;
};

TEST_F(ListTest,assign) {
	string s2("abc",2);
	EXPECT_EQ(s2,"ab");

	string s3(s,2); //attention:this function is different with the previous function
	EXPECT_EQ(s3,"c");

	string s4(s,2,2);
	EXPECT_EQ(s4,"c");

}

