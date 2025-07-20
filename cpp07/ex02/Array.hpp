#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
public:
    Array(unsigned int size) : _size(size), _data(new T[size]) {}
    Array(const Array& other) : _size(other._size), _data(new T[other._size]) {
        for (unsigned int i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }
    ~Array() {
        delete[] _data;
    }
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return _data[index];
    }
    unsigned int size() const {
        return _size;
    }
private:
    unsigned int _size;
    T* _data;
};

#endif