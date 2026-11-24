
#include <iostream>
#include <stdexcept>
#include <new>
#include "../include/DynamicArray.h"

int main() {
    DynamicArray arr(3);

    try {
        arr.set(0, 50);
        std::cout << "Элемент добавлен\n";

        arr.set(1, 150);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "invalid_argument: " << e.what() << '\n';
    }

    try {
        arr.get(5);
    }
    catch (const std::out_of_range& e) {
        std::cout << "out_of_range: " << e.what() << '\n';
    }

    try {
        arr.push_back(200);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "invalid_argument: " << e.what() << '\n';
    }

    try {
        throw std::bad_alloc();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "bad_alloc: память не выделена\n";
    }

    return 0;
}