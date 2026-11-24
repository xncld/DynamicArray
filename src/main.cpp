
#include <iostream>
#include <string>
#include "../include/DynamicArray.h"

int main() {
    DynamicArray<int> arr(3);

    arr.set(0, 10);
    arr.set(1, 20);
    arr.set(2, 30);

    std::cout << "массив int: " << arr << std::endl;

    arr[0] = 50;
    std::cout << "operator[]: " << arr[0] << std::endl;
    std::cout << "массив после изменения: " << arr << std::endl;

    DynamicArray<int> arr2(3);

    arr2.set(0, 13);
    arr2.set(1, 24);
    arr2.set(2, 35);

    std::cout << "arr == arr2: " << (arr == arr2) << std::endl;
    std::cout << "arr != arr2: " << (arr != arr2) << std::endl;

    DynamicArray<int> arr3(3);
    arr3.set(0, 50);
    arr3.set(1, 20);
    arr3.set(2, 30);

    std::cout << "arr == arr3: " << (arr == arr3) << std::endl;

    DynamicArray<int> arithmetic(3);
    arithmetic.set(0, 10);
    arithmetic.set(1, 20);
    arithmetic.set(2, 30);

    arithmetic += arr2;
    std::cout << "массив после += array: " << arithmetic << std::endl;

    arithmetic -= arr2;
    std::cout << "массив после -= array: " << arithmetic << std::endl;

    arithmetic += 5;
    std::cout << "массив после += 5: " << arithmetic << std::endl;

    arithmetic -= 5;
    std::cout << "массив после -= 5: " << arithmetic << std::endl;

    std::cout << "перебор массива: ";

    for (const auto& x : arithmetic) {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    for (auto& x : arithmetic) {
        x += 1;
    }

    std::cout << "после изменения через итератор: "
              << arithmetic << std::endl;

    try {
        arr[1] = 150;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "operator[] invalid_argument: " << e.what() << std::endl;
    }

    try {
        arr[5] = 10;
    }
    catch (const std::out_of_range& e) {
        std::cout << "operator[] out_of_range: " << e.what() << std::endl;
    }

    DynamicArray<std::string> words(3);

    words.set(0, "Hello");
    words.set(1, "World");
    words.set(2, "C++");

    std::cout << "массив string: " << words << std::endl;

    std::cout << "расстояние: " << arr.distance(arr2) << std::endl;

    try {
        words.distance(words);
    }
    catch (const std::bad_typeid& e) {
        std::cout << "bad_typeid: расстояние для string недоступно\n";
    }

    try {
        DynamicArray<int> arr4(2);
        std::cout << arr.distance(arr4) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "invalid_argument: " << e.what() << std::endl;
    }

    return 0;
}
