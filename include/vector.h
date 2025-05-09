class Vector
{
private:
    int size;
    int capacity;
    int* data;
public:
    Vector();
    Vector(const Vector& other);
    Vector(int elements, int value = 0);
    Vector(const std::initializer_list<int>& list);

    ~Vector();

    void Push_back(int value);
    void Pop_back();

    bool Empty() const;
    int Size() const;
    int Capacity() const;

    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

    friend ostream &operator<<(ostream &out, const Vector &other);

    Vector& operator=(const Vector& other);
    int& operator[](int index);
    int& At(int index);
    int& Front();
    int& Back();
};