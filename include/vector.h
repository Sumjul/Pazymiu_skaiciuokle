#pragma once

/* A custom dynamic array class for integers, similar to std::vector<int> */
template <typename T>
class Vector
{
private:
    int size;     // Current number of elements in the vector
    int capacity; // Current capacity of the vector
    T *data;            // Pointer to to dynamically allocated data

public:
    // =============
    // Member types
    // =============
    using value_type = T;                       // Type of the elements in the vector
    using allocator_type = void;                // Allocator type for the vector
    using size_type = std::size_t;              // Size type for the vector
    using difference_type = std::ptrdiff_t;     // Difference type for the vector
    using reference = value_type &;             // Reference type for the vector
    using const_reference = const value_type &; // Const reference type for the vector
    using pointer = value_type *;               // Pointer type for the vector
    using const_pointer = const value_type *;   // Const pointer type for the vector
    using iterator = pointer;                   // Iterator type for the vector
    using const_iterator = const_pointer;       // Const iterator type for the vector

    // ============================
    // Constructors and Destructor
    // ============================
    /** Default constructor */
    Vector() : size(0), capacity(5), data(new int[capacity]) {};
    /** Copy constructor */
    Vector(const Vector &other)
    {
        for (int i = 0; i < other.Size(); ++i)
        {
            data[i] = other.data[i];
        }
    }
    /** Move constructor */
    Vector(Vector &&other) : size(other.size), capacity(other.capacity), data(other.data)
    {
        other.size = 0;
        other.capacity = 0;
        other.data = nullptr;
    }
    /** Parameterized constructor */
    Vector(int elements, int value = 0) : size(elements), capacity(elements + 5), data(new int[capacity])
    {
        for (int i = 0; i < size; ++i)
        {
            data[i] = value;
        }
    }
    /** Initializer list constructor */
    Vector(const std::initializer_list<int> &list) : size(0), capacity(list.size() + 5), data(new int[capacity])
    {
        for (int i : list)
        {
            Push_back(i);
        }
    }
    /** Destructor */
    ~Vector()
    {
        delete[] data;
    }

    // ========================
    // First element functions
    // ========================
    /* Returns reference to the first element */
    const int &Front() const
    {
        if (Empty())
        {
            throw std::out_of_range("Vectorius yra tuscias, negalima pasiekti elemento.");
        }
        return data[0];
    }
    /* Adds an element to the beginning of the vector */
    void Push_front(int value)
    {
        if (size < capacity)
        {
            for (int i = size; i > 0; --i)
            {
                data[i] = data[i - 1];
            }
            data[0] = value;
            ++size;
        }
        else
        {
            int newCapacity = (capacity == 0) ? 5 : capacity * 2;
            Reserve(newCapacity);
            for (int i = size; i > 0; --i)
            {
                data[i] = data[i - 1];
            }
            data[0] = value;
            ++size;
        }
    }
    /* Removes the first element from the vector */
    void Pop_front()
    {
        if (size == 0)
        {
            throw std::out_of_range("Vectorius yra tuscias, negalima istrinti elemento.");
        }
        for (int i = 0; i < size - 1; ++i)
        {
            data[i] = data[i + 1];
        }
        --size;
    }

    // =======================
    // Last element functions
    // =======================
    /* Returns reference to the last element */
    const int &Back() const
    {
        if (Empty())
        {
            throw std::out_of_range("Vectorius yra tuscias, negalima pasiekti elemento.");
        }
        return data[size - 1];
    }
    /* Adds an element to the end of the vector */
    void Push_back(int value)
    {
        if (size < capacity)
        {
            data[size] = value;
            ++size;
        }
        else
        {
            int newCapacity = (capacity == 0) ? 5 : capacity * 2;
            Reserve(newCapacity);
            data[size] = value;
            ++size;
        }
    }
    /* Removes the last element from the vector */
    void Pop_back()
    {
        if (size == 0)
        {
            throw std::out_of_range("Vectorius yra tuscias, negalima istrinti elemento.");
        }
        --size;
    }

    // ================
    // Other functions
    // ================
    /* Returns the size of the vector */
    int Size() const noexcept
    {
        return size;
    }
    /* Resizes the vector to the specified size */
    void Resize(int newSize)
    {
        if (newSize < 0)
        {
            throw std::invalid_argument("Neteisingas dydis. Dydis negali buti neigiamas.");
        }
        if (newSize > capacity)
        {
            Reserve(newSize + 5);
        }
        if (newSize > size)
        {
            for (int i = size; i < newSize; ++i)
            {
                data[i] = 0;
            }
        }
        size = newSize;
    }
    /* Returns the capacity of the vector */
    int Capacity() const noexcept
    {
        return capacity;
    }
    /* Reserves space for the specified number of elements */
    void Reserve(int newCapacity)
    {
        if (newCapacity <= capacity)
            return;
        int *newData = new int[newCapacity];
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    /* Shrinks the capacity of the vector to fit its size */
    void Shrink_to_fit()
    {
        if (size == capacity)
            return;
        if (size == 0)
        {
            delete[] data;
            data = nullptr;
            capacity = 0;
        }
        else if (capacity > size)
        {
            Reserve(size);
        }
    }
    /* Checks if the vector is empty */
    bool Empty() const noexcept
    {
        return size == 0;
    }
    /* Clears the vector */
    void Clear()
    {
        size = 0;
    }
    /* Swaps the contents of this vector with another */
    void Swap(Vector &other)
    {
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
        std::swap(data, other.data);
    }

    // =========================
    // Element access functions
    // =========================
    /* Accesses an element by index without bounds checking */
    const int &operator[](int index) const
    {
        return data[index];
    }
    /* Accesses an element by index with bounds checking */
    const int &At(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Indeksas uz ribu. Negalima pasiekti elemento.");
        }
        return data[index];
    }
    /* Inserts an element at the specified index */
    void Insert(int index, int value)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Indeksas uz ribu. Negalima iterpti elemento.");
        }
        if (size != capacity)
        {
            for (int i = size - 1; i >= index; --i)
            {
                data[i + 1] = data[i];
            }
            data[index] = value;
            ++size;
        }
        else
        {
            int newCapacity = (capacity == 0) ? 5 : capacity * 2;
            Reserve(newCapacity);
            Insert(index, value);
        }
    }
    /* Removes an element at the specified index */
    void Erase(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Indeksas uz ribu. Negalima istrinti elemento.");
        }
        for (int i = index; i < size - 1; ++i)
        {
            data[i] = data[i + 1];
        }
        --size;
    }

    // ===========
    // Operators
    // ===========
    /* Copy assignment operator */
    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            if (other.size > size)
            {
                delete[] data;
                capacity = other.size + 5;
                data = new int[capacity];
            }
            for (int i = 0; i < other.Size(); ++i)
            {
                data[i] = other.data[i];
            }
            size = other.size;
        }
        return *this;
    }
    /* Move assignment operator */
    Vector &operator=(Vector &&other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = other.data;
            other.size = 0;
            other.capacity = 0;
            other.data = nullptr;
        }
        return *this;
    }
    /* Compares this vector with another for equality */
    bool operator==(const Vector &other) const
    {
        if (Size() != other.Size())
            return false;
        for (int i = 0; i < Size(); ++i)
        {
            if (data[i] != other.data[i])
                return false;
        }
        return true;
    }
    /* Compares this vector with another for inequality */
    bool operator!=(const Vector &other) const
    {
        return !(*this == other);
    }
    /* Compares this vector with another for less than */
    bool operator<(const Vector &other) const
    {
        int minSize = std::min(size, other.size);
        for (int i = 0; i < minSize; ++i)
        {
            if (data[i] < other.data[i])
                return true;
            else if (data[i] > other.data[i])
                return false;
        }
        return size < other.size;
    }
    /* Compares this vector with another for less than or equal to */
    bool operator<=(const Vector &other) const
    {
        return (*this < other) || (*this == other);
    }
    /* Compares this vector with another for greater than */
    bool operator>(const Vector &other) const
    {
        return other < *this;
    }
    /* Compares this vector with another for greater than or equal to */
    bool operator>=(const Vector &other) const
    {
        return (other < *this) || (*this == other);
    }

    // ============================
    // Overloaded input and output
    // ============================
    /* Overloads the stream output operator for printing */
    friend ostream &operator<<(ostream &out, const Vector &other)
    {
        for (int i = 0; i < other.size; ++i)
        {
            out << other.data[i] << " ";
        }
        out << " || ";
        for (int i = other.size; i < other.capacity; ++i)
        {
            out << other.data[i] << " ";
        }
        out << endl;
        return out;
    }
    /* Overloads the stream input operator for reading */
    friend istream &operator>>(istream &in, Vector &other)
    {
    int size;
    in >> size;
    other.Resize(size);
    for (int i = 0; i < size; ++i)
    {
        in >> other.data[i];
    }
    return in;
    }
};