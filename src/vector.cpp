#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"
#include "../include/vector.h"

Vector::Vector() : size(0), capacity(5), data(new int[capacity])
{
}

Vector::~Vector()
{
    delete[] data;
}