#pragma once

// Class that holds student data.
class Student
{
    public:
    string name, surname;
    vector<int> marks;
    int egzam;
    double average, median;

    Student(string name = "Vardenis", string surname = "Pavardenis", vector<int> marks ={0}, int egzam = 0) : name(name), surname(surname), marks(marks), egzam(egzam) {}

};
