#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"

TEST_CASE("Student Class Tests")
{
    // Test default constructor
    Student student1;
    REQUIRE(student1.getName() == "Vardenis");
    REQUIRE(student1.getSurname() == "Pavardenis");
    REQUIRE(student1.getExam() == 0);
    REQUIRE(student1.getAverage() == 0.0);
    REQUIRE(student1.getMedian() == 0.0);

    // Test parameterized constructor
    Student student2("John", "Doe", 5);
    REQUIRE(student2.getName() == "John");
    REQUIRE(student2.getSurname() == "Doe");
    REQUIRE(student2.getExam() == 5);
    REQUIRE(student2.getAverage() == 0.0);
    REQUIRE(student2.getMedian() == 0.0);

    // Test copy constructor
    Student student3 = student2;
    REQUIRE(student3.getName() == "John");
    REQUIRE(student3.getSurname() == "Doe");
    REQUIRE(student3.getExam() == 5);
    REQUIRE(student3.getAverage() == 0.0);
    REQUIRE(student3.getMedian() == 0.0);

    // Test move constructor
    Student student4 = std::move(student2);
    REQUIRE(student4.getName() == "John");
    REQUIRE(student4.getSurname() == "Doe");
    REQUIRE(student4.getExam() == 5);
}