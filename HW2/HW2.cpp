// HW2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "uniquePtr.h"
#include <stdexcept>


int main()
{
    uniquePtr a (55);
    uniquePtr b(new int(77));
    *b = 20; // через operator *
    std::cout << "Pointer = " << * b <<"\n";
    std::cout << "Pointer = " << * b.getPtr() << "\n";
    uniquePtr p(new int(10));

    if (p.isValid())
    {
        std::cout << "The pointer is invalid = " << *p.getPtr() << "\n";
    }

    if (b) {
        
        std::cout << "The pointer is invalid = " << *b.getPtr() << "\n";
    }

    int* x = new int(34);
    uniquePtr c(x);

    uniquePtr p2(new int(10));

    p2.reset(new int(42));
    
    if (p2.isValid())
    {
        std::cout << "The pointer p2 is invalid = " << *p2.getPtr() << "\n";
    }

    p2.reset();

    try
    {
        if (p2.isValid())
        {
            std::cout << "The pointer p2 is invalid = " << *p2.getPtr() << "\n";
        }
        else
        {
            std::cout << "The pointer p2 not is invalid\n";
        }
    }

    catch (const std::exception& ex)
    {
        std::cout << "Ошибка: " << ex.what() << "\n";
    }
}

