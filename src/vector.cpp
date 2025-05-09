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