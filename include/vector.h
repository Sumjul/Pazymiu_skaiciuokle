#pragma once

/* A custom dynamic array class for integers, similar to std::vector<int> */
class Vector
{
private:
    int size;       // Current number of elements in the vector
    int capacity;   // Current capacity of the vector
    int* data;      // Pointer to to dynamically allocated data

public:
    // ============================
    // Constructors and Destructor
    // ============================
    /** Default constructor */ 
    Vector() : size(0), capacity(5), data(new int[capacity]) {};
    /** Copy constructor */
    Vector(const Vector& other);
    /** Parameterized constructor */
    Vector(int elements, int value = 0);
    /** Initializer list constructor */
    Vector(const std::initializer_list<int>& list);
    /** Destructor */
    ~Vector() {
        delete[] data;
    }

    // ========================
    // First element functions
    // ========================
    /* Returns reference to the first element */
    int& Front() {
        return data[0];
    }
    /* Adds an element to the beginning of the vector */
    void Push_front(int value);
    /* Removes the first element from the vector */
    void Pop_front();

    // =======================
    // Last element functions
    // =======================
    /* Returns reference to the last element */
    int& Back() {
        return data[size - 1];
    }
    /* Adds an element to the end of the vector */
    void Push_back(int value);
    /* Removes the last element from the vector */
    void Pop_back();

    // ================
    // Other functions
    // ================
    /* Returns the size of the vector */
    int Size() const {
        return size;
    }
    /* Resizes the vector to the specified size */
    void Resize(int newSize);
    /* Returns the capacity of the vector */
    int Capacity() const {
        return capacity;
    }
    /* Reserves space for the specified number of elements */
    void Reserve(int newCapacity);
    /* Shrinks the capacity of the vector to fit its size */
    void Shrink_to_fit();
    /* Checks if the vector is empty */
    bool Empty() const {
        return size == 0;
    }
    /* Clears the vector */
    void Clear() {
        size = 0;
    }
    /* Swaps the contents of this vector with another */
    void Swap(Vector& other);
    
    // =========================
    // Element access functions
    // =========================
    /* Accesses an element by index without bounds checking */
    int& operator[](int index) {
        return data[index];
    }
    /* Accesses an element by index with bounds checking */
    int& At(int index);
    /* Inserts an element at the specified index */
    void Insert(int index, int value);
    /* Removes an element at the specified index */
    void Erase(int index);

    // ===========
    // Operators
    // ===========
    /* Assignment operator */
    Vector& operator=(const Vector& other);
    /* Compares this vector with another for equality */
    bool operator==(const Vector& other) const;
    /* Compares this vector with another for inequality */
    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }
    /* Compares this vector with another for less than */
    bool operator<(const Vector& other) const;
    /* Compares this vector with another for greater than */
    bool operator>(const Vector& other) const {
        return other < *this;
    }
    /* Compares this vector with another for less than or equal to */
    bool operator<=(const Vector& other) const {
        return !(other > *this);
    }
    /* Compares this vector with another for greater than or equal to */
    bool operator>=(const Vector& other) const {
        return !(*this > other);
    }

    // ============================
    // Overloaded input and output
    // ============================
    /* Overloads the stream output operator for printing */
    friend ostream &operator<<(ostream &out, const Vector &other);
};