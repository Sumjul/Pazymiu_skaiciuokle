#pragma once

// ** Class that implements a dynamic array (vector) */
template <typename T>
class Vector
{
private:
    size_t size_;           // Current number of elements in the vector
    size_t capacity_;       // Current capacity of the vector
    T *data_;            // Pointer to to dynamically allocated data

public:
    // =============
    // Member types
    // =============
    using value_type = T;                       // Type of the elements in the vector
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
    Vector() : size_(0), capacity_(5), data_(new T[capacity_]) {};
    /** Copy constructor */
    Vector(const Vector &other) : size_(other.size()), capacity_(other.capacity()), data_(new T[capacity_])
    {
        for (int i = 0; i < other.size(); ++i)
        {
            data_[i] = other.data_[i];
        }
    }
    /** Move constructor */
    Vector(Vector &&other) : size_(other.size()), capacity_(other.capacity()), data_(other.data_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    /** Parameterized constructor */
    Vector(int elements, T value = T()) : size_(elements), capacity_(elements + 5), data_(new T[capacity_])
    {
        for (int i = 0; i < size_; ++i)
        {
            data_[i] = value;
        }
    }
    /** Initializer list constructor */
    Vector(const std::initializer_list<T> &list) : size_(0), capacity_(list.size() + 5), data_(new T[capacity_])
    {
        for (const T &i : list)
        {
            push_back(i);
        }
    }
    /** Destructor */
    ~Vector()
    {
        delete[] data_;
    }

    // ========================
    // First element functions
    // ========================
    /* Returns reference to the first element */
    const T &front() const
    {
        if (empty())
        {
            throw std::out_of_range("Vectorius yra tuscias, negalima pasiekti elemento.");
        }
        return data_[0];
    }
    /* Returns iterator to the first element */
    T* begin()
    {
        return data_;
    }
    /* Returns const iterator to the first element */
    const T* begin() const
    {
        return data_;
    }
    /* Adds an element to the beginning of the vector */
    void push_front(const T &value)
    {
        if (size_ < capacity_)
        {
            for (int i = size_; i > 0; --i)
            {
                data_[i] = data_[i - 1];
            }
            data_[0] = value;
            ++size_;
        }
        else
        {
            int newCapacity = (capacity_ == 0) ? 5 : capacity_ * 2;
            reserve(newCapacity);
            for (int i = size_; i > 0; --i)
            {
                data_[i] = data_[i - 1];
            }
            data_[0] = value;
            ++size_;
        }
    }
    /* Removes the first element from the vector */
    void pop_front()
    {
        if (size_ == 0)
        {
            throw std::out_of_range("Vectorius yra tuscias, negalima istrinti elemento.");
        }
        for (int i = 0; i < size_ - 1; ++i)
        {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    // =======================
    // Last element functions
    // =======================
    /* Returns reference to the last element */
    const T &back() const
    {
        if (empty())
        {
            throw std::out_of_range("Vectorius yra tuscias, negalima pasiekti elemento.");
        }
        return data_[size_ - 1];
    }
    /* Returns iterator to the last element */
    T* end()
    {
        return data_ + size_;
    }
    /* Returns const iterator to the last element */
    const T* end() const
    {
        return data_ + size_;
    }
    /* Adds an element to the end of the vector */
    void push_back(const T& value)
    {
        if (size_ == capacity_)
        {
            reserve(capacity_ * 2);
        }
        //cout << "[Vector] copy push_back called, size = " << size_ << ", capacity = " << capacity_ << std::endl;
        new(&data_[size_]) T(value);
        ++size_;
    }
    void push_back(T&& value)
    {
        if (size_ == capacity_)
        {
            reserve(capacity_ * 2);
        }
        //cout << "[Vector] move push_back called, size = " << size_ << ", capacity = " << capacity_ << std::endl;
        new(&data_[size_]) T(std::move(value));
        ++size_;
    }
    /* Removes the last element from the vector */
    void pop_back()
    {
        if (size_ == 0)
        {
            throw std::out_of_range("Vectorius yra tuscias, negalima istrinti elemento.");
        }
        --size_;
    }

    // ================
    // Other functions
    // ================
    /* Returns the size of the vector */
    int size() const noexcept
    {
        return size_;
    }
    /* Resizes the vector to the specified size */
    void resize(int newSize)
    {
        if (newSize < 0)
        {
            throw std::invalid_argument("Neteisingas dydis. Dydis negali buti neigiamas.");
        }
        if (newSize > capacity_)
        {
            reserve(newSize + 5);
        }
        if (newSize > size_)
        {
            for (int i = size_; i < newSize; ++i)
            {
                data_[i] = T();
            }
        }
        size_ = newSize;
    }
    /* Returns the capacity of the vector */
    int capacity() const noexcept
    {
        return capacity_;
    }
    /* Reserves space for the specified number of elements */
    void reserve(int newCapacity)
    {
        if (newCapacity <= capacity_)
            return;
        T *newData = new T[newCapacity];
        for (int i = 0; i < size_; ++i)
        {
            newData[i] = move(data_[i]);
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }
    /* Shrinks the capacity of the vector to fit its size */
    void shrink_to_fit()
    {
        if (size_ == capacity_)
            return;
        if (size_ == 0)
        {
            delete[] data_;
            data_ = nullptr;
            capacity_ = 0;
        }
        else if (capacity_ > size_)
        {
            reserve(size_);
        }
    }
    /* Checks if the vector is empty */
    bool empty() const noexcept
    {
        return size_ == 0;
    }
    /* Clears the vector */
    void clear()
    {
        size_ = 0;
    }
    /* Swaps the contents of this vector with another */
    void swap(Vector &other)
    {
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
        std::swap(data_, other.data);
    }

    // =========================
    // Element access functions
    // =========================
    /* Accesses data */
    T *data() const
    {
        return data_;
    }
    /* Accesses an element by index without bounds checking */
    T &operator[] (int index)
    {
        return data_[index];
    }
    const T &operator[] (int index) const
    {
        return data_[index];
    }
    /* Accesses an element by index with bounds checking */
    T &at(int index)
    {
        if (index < 0 || index >= size_)
        {
            throw std::out_of_range("Indeksas uz ribu. Negalima pasiekti elemento.");
        }
        return data_[index];
    }
    /* Inserts an element at the specified index */
    void insert(int index, const T &value)
    {
        if (index < 0 || index > size_)
        {
            throw std::out_of_range("Indeksas uz ribu. Negalima iterpti elemento.");
        }
        if (size_ != capacity_)
        {
            for (int i = size_ - 1; i >= index; --i)
            {
                data_[i + 1] = data_[i];
            }
            data_[index] = value;
            ++size_;
        }
        else
        {
            int newCapacity = (capacity_ == 0) ? 5 : capacity_ * 2;
            reserve(newCapacity);
            insert(index, value);
        }
    }
    /* Removes an element at the specified index */
    void erase(int index)
    {
        if (index < 0 || index >= size_)
        {
            throw std::out_of_range("Indeksas uz ribu. Negalima istrinti elemento.");
        }
        for (int i = index; i < size_ - 1; ++i)
        {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    // ===========
    // Operators
    // ===========
    /* Copy assignment operator */
    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            if (other.size_ > size_)
            {
                delete[] data_;
                capacity_ = other.size_ + 5;
                data_ = new T[capacity_];
            }
            for (int i = 0; i < other.size(); ++i)
            {
                data_[i] = other.data_[i];
            }
            size_ = other.size_;
        }
        return *this;
    }
    /* Move assignment operator */
    Vector &operator=(Vector &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }
    /* Compares this vector with another for equality */
    bool operator==(const Vector &other) const
    {
        if (size() != other.size())
            return false;
        for (size_t i = 0; i < size(); ++i)
        {
            if (data_[i] != other.data_[i])
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
        int minSize = std::min(size_, other.size_);
        for (int i = 0; i < minSize; ++i)
        {
            if (data_[i] < other.data_[i])
                return true;
            else if (data_[i] > other.data_[i])
                return false;
        }
        return size_ < other.size_;
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
        for (int i = 0; i < other.size_; ++i)
        {
            out << other.data_[i] << " ";
        }
        out << " || ";
        for (int i = other.size(); i < other.capacity_; ++i)
        {
            out << other.data_[i] << " ";
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