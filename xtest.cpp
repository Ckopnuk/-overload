#include "xtest.h"
#include <iostream>

void XTest(int test)
{
    std::cout << "Inside Xtest, test is: " << test << std::endl;

    try {
        if (test) throw test;
    }  catch (int i) {
        std::cout << "Caught an exception -- value is: ";
        std::cout << i << std::endl;
    }
}
