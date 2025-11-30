// HW3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "SharedPtrInt.h"

void TestPtr(SharedPtrInt<int> val)
{
    std::cout << "CountPointer = " << val.GetCount() << "\n";
}

int main()
{

    SharedPtrInt<int> objB(new int(5));
    SharedPtrInt<int> objA(new int(10));
    std::cout << "ValueObjA =  " << objA.GetPtr() << "\n";
    std::cout << "ValueObjB =  " << objB.GetPtr() << "\n";
    std::cout << "CountPointer ObjB =  " << objB.GetCount() << "\n";
    TestPtr(objB);
    std::cout << "CountPointer ObjB =  "<< objB.GetCount() << "\n";
    std::cout << "ValueObjB =  " << objB.GetPtr() << "\n";
    std::cout << "ObjAisValid =  " << objA.isValid() << "  - CountPointer ObjA =  " << objA.GetCount() << "\n";
    objB = objA;
    std::cout << "ValueObjB =  " << objB.GetPtr() << "  - CountPointer ObjB =  " << objB.GetCount() << "\n";
    std::cout << " (ObjB delete) -> ObjB references to ObjA (SharedPointer) " << "ObjAisValid =  " << objA.isValid() << "  - CountPointer ObjA =  " << objA.GetCount() << "\n";
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
