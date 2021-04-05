#include <iostream>
#include "AnyType.h"

int main()
{
    AnyType anyType1 = 1;
    AnyType anyType2 = 1.2f;
    anyType1.Swap(anyType2);

    try
    {
        std::cout << "anyType1 : " << anyType1.GetType() << '\n' << "anyType2 : " << anyType2.GetType() << '\n';
        anyType1.Destroy();
        std::cout << "anyType1 : " << anyType1.GetType() << '\n';
    }
    catch (InvalidCast& e)
    {
        std::cout << e.what() << std::endl;
    }
}