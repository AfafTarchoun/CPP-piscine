#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array {
public:
    // Construction with no parameter
    Array() : m_size(0), m_data(nullptr) {}

    // Construction with an unsigned int n as a parameter
    Array(unsigned int n) : m_size(n), m_data(new T[n]) {}

    // Copy constructor
    Array(const Array<T>& other) : m_size(other.m_size), m_data(new T[other.m_size]) {
        for (unsigned int i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    // Assignment operator
    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            delete[] m_data;
            m_size = other.m_size;
            m_data = new T[m_size];
            for (unsigned int i = 0; i < m_size; ++i) {
                m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] m_data;
    }

    // Subscript operator
    T& operator[](unsigned int index) {
        if (index >= m_size) {
            throw std::exception();
        }
        return m_data[index];
    }

    // Size function
    unsigned int size() const {
        return m_size;
    }

private:
    unsigned int m_size;
    T* m_data;
};
#endif