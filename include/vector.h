class Vector
{
private:
    int size;
    int capacity;
    int* data;

public:
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

    /* Returns the first element of the vector */
    int& Front() {
        return data[0];
    }

    /* Returns the last element of the vector */
    int& Back() {
        return data[size - 1];
    }
    /* Adds an element to the end of the vector */
    void Push_back(int value);
    /* Removes the last element from the vector */
    void Pop_back();

    /* Returns the size of the vector */
    int Size() const {
        return size;
    }
    /* Returns the capacity of the vector */
    int Capacity() const {
        return capacity;
    }
    /* Checks if the vector is empty */
    bool Empty() const {
        return size == 0;
    }
    /* Clears the vector */
    void Clear() {
        size = 0;
    }
    
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

    /* Compares this vector with another for equality */
    bool operator==(const Vector& other) const;
    /* Compares this vector with another for inequality */
    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }
    
    /* Assignment operator */
    Vector& operator=(const Vector& other);

    /* Overloads the stream output operator for printing */
    friend ostream &operator<<(ostream &out, const Vector &other);
};