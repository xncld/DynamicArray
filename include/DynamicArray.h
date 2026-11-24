
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <stdexcept>
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
    class Reference {
    private:
        DynamicArray& array;
        int index;

    public:
        Reference(DynamicArray& array, int index) : array(array), index(index) {}

        Reference& operator=(T value) {
            array.set(index, value);
            return *this;
        }

        Reference& operator=(const Reference& other) {
            return *this = static_cast<T>(other);
        }

        operator T() const {
            return array.get(index);
        }
    };

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

    Reference operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("индекс вне границ");
        }

        return Reference(*this, index);
    }

    T operator[](int index) const {
        return get(index);
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

    bool operator==(const DynamicArray& other) const {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const DynamicArray& other) const {
        return !(*this == other);
    }

    DynamicArray& operator+=(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            T value = data[i];

            if (i < other.size) {
                value += other.data[i];
            }

            checkValue(value);
            data[i] = value;
        }

        return *this;
    }

    DynamicArray& operator-=(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            T value = data[i];

            if (i < other.size) {
                value -= other.data[i];
            }

            checkValue(value);
            data[i] = value;
        }

        return *this;
    }

    DynamicArray& operator+=(T value) {
        for (int i = 0; i < size; i++) {
            T newValue = data[i] + value;
            checkValue(newValue);
            data[i] = newValue;
        }

        return *this;
    }

    DynamicArray& operator-=(T value) {
        for (int i = 0; i < size; i++) {
            T newValue = data[i] - value;
            checkValue(newValue);
            data[i] = newValue;
        }

        return *this;
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + size;
    }

    const T* begin() const {
        return data;
    }

    const T* end() const {
        return data + size;
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
