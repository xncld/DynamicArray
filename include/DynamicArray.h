
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <stdexcept>
#include <new>
#include <type_traits>
#include <cmath>
#include <string>
#include <typeinfo>

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

    void checkValue(T value) const {
        if constexpr (std::is_integral_v<T>) {
            long double num = static_cast<long double>(value);

            if (num < -100 || num > 100) {
                throw std::invalid_argument("значение от -100 до 100");
            }
        }
    }

public:
    DynamicArray(int size) {
        if (size < 0) {
            throw std::invalid_argument("размер массива не может быть отрицательным");
        }

        this->size = size;
        data = new T[size]();
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;

        data = new T[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    void set(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("индекс вне границ");
        }

        checkValue(value);
        data[index] = value;
    }

    T get(int index) const {
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

    void push_back(T value) {
        checkValue(value);

        T* newData = new T[size + 1];

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
            T value = data[i];

            if (i < other.size) {
                value += other.data[i];
            }

            checkValue(value);
            data[i] = value;
        }
    }

    void sub(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            T value = data[i];

            if (i < other.size) {
                value -= other.data[i];
            }

            checkValue(value);
            data[i] = value;
        }
    }

    int getSize() const {
        return size;
    }

    double distance(const DynamicArray& other) const {
        if constexpr (!std::is_arithmetic_v<T>) {
            throw std::bad_typeid();
        }
        else {
            if (size != other.size) {
                throw std::invalid_argument("размеры не совпадают");
            }

            double sum = 0;

            for (int i = 0; i < size; i++) {
                double diff = data[i] - other.data[i];
                sum += diff * diff;
            }

            return std::sqrt(sum);
        }
    }

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr) {
    os << "[ ";

    for (int i = 0; i < arr.getSize(); i++) {
        os << arr.get(i) << " ";
    }

    os << "]";
    return os;
}

#endif
