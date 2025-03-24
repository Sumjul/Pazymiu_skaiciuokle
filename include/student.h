#pragma once

// Class that holds student data.
class Student
{
public:
    string name, surname;
    vector<int> marks;
    int exam;
    double average, median;
    

public:
    Student() {}
    ~Student() {}

    string getName() const { return name; }
    string getSurname() const { return surname; }
    int getExam() const { return exam; }
    const vector<int>& getMarks() const { return marks; }
    double getAverage() const { return average; }
    double getMedian() const { return median; }

    void setName(const string& newName) { name = newName; }
    void setSurname(const string& newSurname) { surname = newSurname; }
    void setExam(int newExam) { exam = newExam; }
    void addMark(int mark) { marks.push_back(mark); }

    void calculateAverage();
    void calculateMedian();
};
