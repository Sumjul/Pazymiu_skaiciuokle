#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"
#include "../include/vector.h"

/** Copy constructor */
Vector::Vector(const Vector& other)
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
Vector::Vector(const std::initializer_list<int>& list)
    : size(0), capacity(list.size() + 5), data(new int[capacity])
{
    for ( int i: list )
    {
        Push_back(i);
    }
}

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
        int* newData = new int[capacity];
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

/* Accesses an element by index with bounds checking */
int& Vector::At(int index)
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
        int* newData = new int[capacity];
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

/* Compares this vector with another for equality */
bool Vector::operator==(const Vector& other) const
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

/* Assigment operator */
Vector& Vector::operator=(const Vector& other)
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

/* Overloads the stream output operator for printing */
ostream& operator<<(ostream& out, const Vector& other)
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