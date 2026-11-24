#include <iostream>
#include <string>
#include "../include/DynamicArray.h"

int main() {
    DynamicArray<int> arr(3);

    arr.set(0, 10);
    arr.set(1, 20);
    arr.set(2, 30);

    std::cout << "массив int: " << arr << std::endl;

    DynamicArray<std::string> words(3);

    words.set(0, "Hello");
    words.set(1, "World");
    words.set(2, "C++");

    std::cout << "массив string: " << words << std::endl;

    DynamicArray<int> arr2(3);

    arr2.set(0, 13);
    arr2.set(1, 24);
    arr2.set(2, 35);

    std::cout << "расстояние: " << arr.distance(arr2) << std::endl;

    try {
        words.distance(words);
    }
    catch (const std::bad_typeid& e) {
        std::cout << "bad_typeid: расстояние для string недоступно\n";
    }

    try {
        DynamicArray<int> arr3(2);
        std::cout << arr.distance(arr3) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "invalid_argument: " << e.what() << std::endl;
    }

    return 0;
}