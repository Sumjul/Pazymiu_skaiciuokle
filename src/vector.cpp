#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"
#include "../include/vector.h"

Vector::Vector()
    : size(0), capacity(5), data(new int[capacity]) {}

Vector::~Vector()
{
    delete[] data;
}

Vector::Vector(const Vector& other)
    : size(other.size), capacity(other.capacity), data(new int[capacity])
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

void Vector::Push_back(int value)
{
    data[size] = value;
    ++size;
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