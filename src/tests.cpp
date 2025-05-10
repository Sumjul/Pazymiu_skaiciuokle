#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"
#include "../include/vector.h"

TEST_CASE("Student klases Rule of five testai")
{
    // Numatytojo konstruktoriaus testavimas
    Student A;
    A.setName("Testas");
    A.setSurname("Testinis");
    vector<int> testmarks = {10, 9, 8, 7, 10, 6, 9, 8};
    for (int mark : testmarks)
    {
        A.addMark(mark);
    }
    A.setExam(9);
    A.calculateAverage();
    A.calculateMedian();
    REQUIRE(A.getName() == "Testas");
    REQUIRE(A.getSurname() == "Testinis");
    REQUIRE(A.getExam() == 9);
    REQUIRE(A.getAverage() == 8.75);
    REQUIRE(A.getMedian() == 8.5);
    SECTION("Kopijavimo konstruktorius") {
        Student B (A);
        REQUIRE(B.getName() == "Testas");
        REQUIRE(B.getSurname() == "Testinis");
        REQUIRE(B.getExam() == 9);
        REQUIRE(B.getAverage() == 8.75);
        REQUIRE(B.getMedian() == 8.5);
    }
    SECTION("Perkelimo konstruktorius") {
        Student temp = A;
        Student C (move(temp));
        REQUIRE(C.getName() == "Testas");
        REQUIRE(C.getSurname() == "Testinis");
        REQUIRE(C.getExam() == 9);
        REQUIRE(C.getAverage() == 8.75);
        REQUIRE(C.getMedian() == 8.5);
    }
    SECTION("Kopijavimo priskyrimo operatorius") {
        Student D;
        D = A;
        REQUIRE(D.getName() == "Testas");
        REQUIRE(D.getSurname() == "Testinis");
        REQUIRE(D.getExam() == 9);
        REQUIRE(D.getAverage() == 8.75);
        REQUIRE(D.getMedian() == 8.5);
    }
    SECTION("Perkelimo priskyrimo operatorius") {
        Student temp = A;
        Student E;
        E = move(temp);
        REQUIRE(E.getName() == "Testas");
        REQUIRE(E.getSurname() == "Testinis");
        REQUIRE(E.getExam() == 9);
        REQUIRE(E.getAverage() == 8.75);
        REQUIRE(E.getMedian() == 8.5);
    }
}
TEST_CASE("Student konstruktorius su parametrais")
{
    Student F("Jonas", "Jonaitis", 10);
    F.addMark(9);
    F.addMark(8);
    F.calculateAverage();
    F.calculateMedian();
    REQUIRE(F.getName() == "Jonas");
    REQUIRE(F.getSurname() == "Jonaitis");
    REQUIRE(F.getExam() == 10);
    REQUIRE(F.getAverage() == 9.4);
    REQUIRE(F.getMedian() == 8.5);
}
TEST_CASE("Student ivesties/isvesties operatoriai")
{
    Student G("Petras", "Petraitis", 10);
    G.addMark(8);
    G.addMark(9);
    G.calculateAverage();
    G.calculateMedian();
    stringstream ss;
    ss << G;
    string output = ss.str();
    REQUIRE(output.find("Petras") != string::npos);
    REQUIRE(output.find("Petraitis") != string::npos);
    REQUIRE(output.find("8.5") != string::npos);
    REQUIRE(output.find("9.4") != string::npos);
}
TEST_CASE("Abstrakti klase Human naudojama su Student rodykle")
{
    Human *H = new Student("Jonas", "Jonaitis", 10);
    stringstream ss;
    std::streambuf* old_buf = cout.rdbuf(ss.rdbuf());
    H->print();
    cout.rdbuf(old_buf);
    delete H;
    string printed = ss.str();
    REQUIRE(printed.find("Jonas") != string::npos);
    REQUIRE(printed.find("Jonaitis") != string::npos);
}