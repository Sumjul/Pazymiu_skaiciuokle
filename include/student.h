#pragma once

/** Base class for human data */
class Human
{
protected:
    string name_;
    string surname_;

public:
    // Constructors and destructor
    Human() = default;
    Human(const string &name = "Vardenis", const string &surname = "Pavardenis")
        : name_(name), surname_(surname) {}

    virtual ~Human()
    {
        //cout << "[~] Base destructor called for: " << name_ << " " << surname_ << endl;
        name_.clear();
        surname_.clear();
    }

    // Getters and setters
    string getName() const { return name_; }
    string getSurname() const { return surname_; }
    void setName(const string &newName) { name_ = newName; }
    void setSurname(const string &newSurname) { surname_ = newSurname; }

    virtual void print() const = 0;
};

/** Class that holds student data and inherits from Human */
class Student : public Human
{
private:
    vector<int> marks_;
    int exam_;
    double average_, median_;

public:
    // Constructors and destructor
    Student(const string &name = "Vardenis", const string &surname = "Pavardenis", int exam = 0)
        : Human(name, surname), exam_(exam), average_(0.0), median_(0.0) { marks_.reserve(20); }

    ~Student()
    {
        //cout << "[~] Destructor called for: " << name_ << " " << surname_ << endl;
        marks_.clear();
    }

    // Copy constructor and move constructor
    Student(const Student &other);
    Student(Student &&other);

    // Copy assignment operator and move assignment operator
    Student &operator=(const Student &other);
    Student &operator=(Student &&other);

    // Overloaded operators for input and output
    friend ostream &operator<<(ostream &out, const Student &student);
    friend istream &operator>>(istream &in, Student &student);

    // Getters and setters
    const vector<int> &getMarks() const { return marks_; }
    int getExam() const { return exam_; }
    double getAverage() const { return average_; }
    double getMedian() const { return median_; }

    void addMark(int mark) { marks_.push_back(move(mark)); }
    void setExam(int newExam) { exam_ = newExam; }

    // Functions
    void print() const;
    void calculateAverage();
    void calculateMedian();
    void readLine(const string &line);
};
