
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int size) {
        this->size = size;
        data = new int[size]();
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;

        data = new int[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray() {
        delete[] data;
    }
    
    void set(int index, int value) {
        if (index < 0 || index >= size) {
            std::cout << "ошибка: инд вне границ\n";
            return;
        }

        if (value < -100 || value > 100) {
            std::cout << "ошибка: значение от -100 до 100\n";
            return;
        }

        data[index] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            std::cout << "ошибка: индекс вне границ\n";
            return 0;
        }

        return data[index];
    }

    void print() const {
        std::cout << "[ ";

        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }

        std::cout << "]\n";
    }

    void push_back(int value) {
        if (value < -100 || value > 100) {
            std::cout << "ошибка: значение от -100 до 100!\n";
            return;
        }

        int* newData = new int[size + 1];

        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }

        newData[size] = value;
        delete[] data;
        data = newData;
        size++;
    }

    void add(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            if (i < other.size) {
                data[i] += other.data[i];
            }
        }
    }

    void sub(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            if (i < other.size) {
                data[i] -= other.data[i];
            }
        }
    }
};

#endif
