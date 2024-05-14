#include <iostream>
#include <stdexcept>

template <class T>
class Vector {
    T* v;
    int size;

public:
    Vector(int newSize);
    Vector(const Vector& other);
    ~Vector();

    T extract(const char* MinOrMax) const;
    Vector& sort(const char* UpOrDown);
    double norm() const;

    Vector<T> operator+(const Vector<T>& other) const;
    Vector<T>& operator+=(const Vector<T>& other);
    Vector<T> operator+(T scalar) const;
    T& operator[](int index);
    const T& operator[](int index) const;
    Vector<T>& operator=(const Vector<T>& other);

    template <class U>
    friend std::istream& operator>>(std::istream& is, Vector<U>& vector);

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vector);
};

template <class T>
Vector<T>::Vector(int newSize) : size(newSize) {
    v = new T[size];
    for (int i = 0; i < size; ++i) {
        v[i] = T();
    }
}

template <class T>
Vector<T>::Vector(const Vector& other) : size(other.size) {
    v = new T[size];
    for (int i = 0; i < size; ++i) {
        v[i] = other.v[i];
    }
}

template <class T>
Vector<T>::~Vector() {
    delete[] v;
}

template <class T>
T Vector<T>::extract(const char* MinOrMax) const {
    if (size == 0) {
        throw std::logic_error("Vector is empty");
    }

    T extracted = v[0];
    for (int i = 1; i < size; ++i) {
        if (!strcmp(MinOrMax, "min")) {
            if (v[i] < extracted) {
                extracted = v[i];
            }
        }
        else {
            if (v[i] > extracted) {
                extracted = v[i];
            }
        }
    }
    return extracted;
}

template <class T>
Vector<T>& Vector<T>::sort(const char* UpOrDown) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (!strcmp(UpOrDown, "up")) {
                if (v[i] > v[j]) {
                    T temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
            else {
                if (v[i] < v[j]) {
                    T temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
    }
    return *this;
}

template <class T>
double Vector<T>::norm() const {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += v[i] * v[i];
    }
    return sqrt(sum);
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vectors should have the same size");
    }

    Vector<T> result(size);
    for (int i = 0; i < size; ++i) {
        result.v[i] = v[i] + other.v[i];
    }
    return result;
}

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other) {
    if (size != other.size) {
        throw std::invalid_argument("Vectors should have the same size");
    }

    for (int i = 0; i < size; ++i) {
        v[i] += other.v[i];
    }
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator+(T scalar) const {
    Vector<T> result(size);
    for (int i = 0; i < size; ++i) {
        result.v[i] = v[i] + scalar;
    }
    return result;
}

template <class T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return v[index];
}

template <class T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return v[index];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        delete[] v;
        size = other.size;
        v = new T[size];
        for (int i = 0; i < size; ++i) {
            v[i] = other.v[i];
        }
    }
    return *this;
}

template <class T>
std::istream& operator>>(std::istream& is, Vector<T>& vector) {
    std::cout << "Input " << vector.size << " elements of vector" << std::endl;
    for (int i = 0; i < vector.size; ++i) {
        std::cout << "element[" << i << "] = ? ";
        is >> vector.v[i];
    }
    return is;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
    for (int i = 0; i < vector.size; ++i) {
        os << vector.v[i] << ' ';
    }
    os << std::endl;
    return os;
}
