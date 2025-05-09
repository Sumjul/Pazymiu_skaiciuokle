#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"
#include "../include/vector.h"

Vector::Vector()
    : size(0), capacity(5), data(new int[capacity]) {}


Vector::Vector(const Vector& other)
    : size(other.size), capacity(other.capacity + 5), data(new int[capacity])
{
    for (int i = 0; i < other.Size(); ++i)
    {
        data[i] = other.data[i];
    }
}

Vector::Vector(int elements, int value)
    : size(elements), capacity(elements + 5), data(new int[capacity])
{
    for (int i = 0; i < size; ++i)
    {
        data[i] = value;
    }
}

Vector::Vector(const std::initializer_list<int>& list)
    : size(0), capacity(list.size() + 5), data(new int[capacity])
{
    for ( int i: list )
    {
        Push_back(i);
    }
}

Vector::~Vector()
{
    delete[] data;
}





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

void Vector::Pop_back()
{
    if (size == 0)
    {
        throw std::out_of_range("Vectorius yra tuscias, negalima istrinti elemento.");
    }
    --size;
}


bool Vector::Empty() const
{
    return size == 0;
}

int Vector::Size() const
{
    return size;
}

int Vector::Capacity() const
{
    return capacity;
}

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

bool Vector::operator!=(const Vector& other) const
{
    return !(*this == other);
}

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




    Vector& Vector::operator=(const Vector& other)
    {
        
    }
    int& Vector::operator[](int index)
    {
        return data[index];
    }
    int& Vector::At(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Indeksas uz ribu. Negalima pasiekti elemento.");
        }
        return data[index];
    }
    int& Vector::Front()
    {
        return data[0];
    }
    int& Vector::Back()
    {
        return data[size - 1];
    }