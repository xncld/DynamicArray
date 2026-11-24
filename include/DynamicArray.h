
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <stdexcept>
#include <new>

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int size) {
    if (size < 0) {
        throw std::invalid_argument("размер массива не может быть отрицательным");
    }

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
            throw std::out_of_range("индекс вне границ");
        }

        if (value < -100 || value > 100) {
            throw std::invalid_argument("значение от -100 до 100");
        }

        data[index] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("индекс вне границ");
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
            throw std::invalid_argument("значение от -100 до 100");
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
            int value = data[i];

            if (i < other.size) {
                value += other.data[i];
            }

            if (value < -100 || value > 100) {
                throw std::invalid_argument("результат сложения вне диапазона");
            }

            data[i] = value;
        }
    }

    void sub(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            int value = data[i];

            if (i < other.size) {
                value -= other.data[i];
            }

            if (value < -100 || value > 100) {
                throw std::invalid_argument("результат вычитания вне диапазона");
            }

            data[i] = value;
        }
    }
};

#endif
