#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"
#include "../include/vector.h"

// =============
// Constructors
// =============
/** Copy constructor */
Vector::Vector(const Vector &other)
    : size(other.size), capacity(other.capacity + 5), data(new int[capacity])
{
    for (int i = 0; i < other.Size(); ++i)
    {
        data[i] = other.data[i];
    }
}
/** Parameterized constructor */
Vector::Vector(int elements, int value)
    : size(elements), capacity(elements + 5), data(new int[capacity])
{
    for (int i = 0; i < size; ++i)
    {
        data[i] = value;
    }
}
/* Initializer list constructor */
Vector::Vector(const std::initializer_list<int> &list)
    : size(0), capacity(list.size() + 5), data(new int[capacity])
{
    for (int i : list)
    {
        Push_back(i);
    }
}

// ========================
// First element functions
// ========================
void Vector::Push_front(int value)
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
        capacity *= 2;
        int *newData = new int[capacity];
        newData[0] = value;
        for (int i = 0; i < size; ++i)
        {
            newData[i + 1] = data[i];
        }
        ++size;
        delete[] data;
        data = newData;
    }
}
/* Removes the first element from the vector */
void Vector::Pop_front()
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
/* Adds an element to the end of the vector */
void Vector::Push_back(int value)
{
    if (size < capacity)
    {
        data[size] = value;
        ++size;
    }
    else
    {
        capacity *= 2;
        int *newData = new int[capacity];
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }
        newData[size] = value;
        ++size;
        delete[] data;
        data = newData;
    }
}
/* Removes the last element from the vector */
void Vector::Pop_back()
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
/* Resizes the vector to the specified size */
void Vector::Resize(int newSize)
{
    if (newSize < 0)
    {
        throw std::invalid_argument("Neteisingas dydis. Dydis negali buti neigiamas.");
    }
    if (newSize > capacity)
    {
        capacity = newSize + 5;
        int *newData = new int[capacity];
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }
        for (int i = size; i < newSize; ++i)
        {
            newData[i] = 0;
        }
        delete[] data;
        data = newData;
    }
    else if (newSize > size)
    {
        for (int i = size; i < newSize; ++i)
        {
            data[i] = 0;
        }
    }
    size = newSize;
}
/* Reserves space for the specified number of elements */
void Vector::Reserve(int newCapacity)
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
void Vector::Shrink_to_fit()
{
    if (size == 0)
    {
        delete[] data;
        data = nullptr;
        capacity = 0;
    }
    else
    {
        int *newData = new int[size];
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = size;
    }
}
/* Swaps the contents of this vector with another */
void Vector::Swap(Vector &other)
{
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
    std::swap(data, other.data);
}

// =========================
// Element access functions
// =========================
/* Accesses an element by index with bounds checking */
int &Vector::At(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Indeksas uz ribu. Negalima pasiekti elemento.");
    }
    return data[index];
}
/* Inserts an element at the specified index */
void Vector::Insert(int index, int value)
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
        capacity *= 2;
        int *newData = new int[capacity];
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        Insert(index, value);
    }
}
/* Removes an element at the specified index */
void Vector::Erase(int index)
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
/* Assigment operator */
Vector &Vector::operator=(const Vector &other)
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
    return *this;
}
/* Compares this vector with another for equality */
bool Vector::operator==(const Vector &other) const
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
/* Compares this vector with another for less than */
bool Vector::operator<(const Vector &other) const
{
    int minSize = std::min(Size(), other.Size()) ? size : other.size;
    for (int i = 0; i < minSize; ++i)
    {
        if (data[i] < other.data[i])
            return true;
        else if (data[i] > other.data[i])
            return false;
    }
    return size < other.size;
}

// ============================
// Overloaded input and output
// ============================
/* Overloads the stream output operator for printing */
ostream &operator<<(ostream &out, const Vector &other)
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