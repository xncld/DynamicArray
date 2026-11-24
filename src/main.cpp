
#include <iostream>
#include "../include/DynamicArray.h"

int main() {
    std::cout << "задание1\n";

    DynamicArray arr(3);

    arr.set(0, 10);
    arr.set(1, 20);
    arr.set(2, 30);

    std::cout << "исход массив: ";
    arr.print();

    std::cout << "эл 1: " << arr.get(1) << "\n";


    std::cout << "\nзадание2\n";

    DynamicArray copy(arr);

    arr.set(0, 99);

    std::cout << "ориг: ";
    arr.print();

    std::cout << "копия: ";
    copy.print();


    std::cout << "\nзадание3\n";

    copy.push_back(40);

    std::cout << "добавление: ";
    copy.print();


    std::cout << "\nзадание4\n";

    DynamicArray arrB(2);

    arrB.set(0, 5);
    arrB.set(1, 10);

    std::cout << "мас A: ";
    copy.print();

    std::cout << "мас B: ";
    arrB.print();

    copy.add(arrB);

    std::cout << "сложение: ";
    copy.print();

    copy.sub(arrB);

    std::cout << "вычитание: ";
    copy.print();

    return 0;
}