#pragma once

// Class that holds student data.
class Student
{
private:
    string name_, surname_;
    vector<int> marks_;
    int exam_;
    double average_, median_;

public:
    Student(const string &name = "Vardenis", const string &surname = "Pavardenis", int exam = 0)
        : name_(name), surname_(surname), exam_(exam)
    {
        marks_.reserve(100);
        calculateAverage();
        calculateMedian();
    }
    ~Student() {
        marks_.clear();
    }

    // Getters
    string getName() const { return name_; }
    string getSurname() const { return surname_; }
    const vector<int> &getMarks() const { return marks_; }
    int getExam() const { return exam_; }
    double getAverage() const { return average_; }
    double getMedian() const { return median_; }

    // Setters
    void setName(const string &newName) { name_ = newName; }
    void setSurname(const string &newSurname) { surname_ = newSurname; }
    void addMark(int mark) { marks_.push_back(mark); }
    void setExam(int newExam) { exam_ = newExam; }

    // Functions
    void calculateAverage();
    void calculateMedian();
    void readLine(string line);
};
