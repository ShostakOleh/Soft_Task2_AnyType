#include <iostream>
#include "AnyType.h"

int main()
{
    std::cout << "Hello World!\n";
    AnyType anyType1 = 1;
    AnyType anyType2 = 1.2f;
    //anyType1.Swap(anyType2);
    AnyType tmp(anyType2);
    anyType2 = anyType1;
    anyType1 = tmp;
    
    try
    {
        std::cout << anyType1.GetType()  << '\n' << anyType2.GetType();
    }
    catch (InvalidCast& e)
    {
        std::cout << e.what() << std::endl;
    }
}

