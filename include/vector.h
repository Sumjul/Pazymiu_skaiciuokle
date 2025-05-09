class Vector
{
private:
    int size;
    int capacity;
    int* data;
public:
    Vector();
    ~Vector();
    void Push_back(int value);
    bool Empty() const;
    int Size() const;
    int Capacity() const;
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
};