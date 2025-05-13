#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"
#include "../include/vector.h"

//Testai Vector klasei
TEST_CASE("Constructors", "[Vector]") {
    SECTION("Default constructor") {
        Vector<std::string> empty_vec;
        std::vector<std::string> std_empty_vec;
        REQUIRE(empty_vec.size() == std_empty_vec.size());
        REQUIRE(std::equal(empty_vec.begin(), empty_vec.end(), std_empty_vec.begin()));
    }
    SECTION("Initializer list constructor") {
        Vector<std::string> words1{"the", "frogurt", "is", "also", "cursed"};
        std::vector<std::string> std_words1{"the", "frogurt", "is", "also", "cursed"};
        REQUIRE(words1.size() == std_words1.size());
        REQUIRE(std::equal(words1.begin(), words1.end(), std_words1.begin()));
    }
    SECTION("Copy constructor") {
        Vector<std::string> copy_source{"the", "frogurt", "is", "also", "cursed"};
        Vector<std::string> copied(copy_source);
        std::vector<std::string> std_copy_source{"the", "frogurt", "is", "also", "cursed"};
        std::vector<std::string> std_copied = std_copy_source;
        REQUIRE(copied.size() == std_copied.size());
        REQUIRE(std::equal(copied.begin(), copied.end(), std_copied.begin()));
        REQUIRE(copy_source.size() == std_copy_source.size());
        REQUIRE(std::equal(copy_source.begin(), copy_source.end(), std_copy_source.begin()));
    }
    SECTION("Move constructor") {
        Vector<std::string> move_source{"move", "this"};
        std::vector<std::string> std_move_source{"move", "this"};
        Vector<std::string> moved(std::move(move_source));
        std::vector<std::string> std_moved = std::move(std_move_source);
        REQUIRE(moved.size() == std_moved.size());
        REQUIRE(std::equal(moved.begin(), moved.end(), std_moved.begin()));
        REQUIRE(move_source.size() == 0);
        REQUIRE(std_move_source.size() == 0);
    }
    SECTION("Parametrized constructor") {
        Vector<std::string> words3(5, "Mo");
        std::vector<std::string> std_words3(5, "Mo");
        REQUIRE(words3.size() == std_words3.size());
        REQUIRE(std::equal(words3.begin(), words3.end(), std_words3.begin()));
    }
}
TEST_CASE("front() and back()", "[Vector]") {
    SECTION("front() test") {
        Vector<std::string> letters1{"a", "b", "c", "d"};
        REQUIRE(letters1.front() == "a");
    }
    SECTION("front() on empty vector") {
        Vector<std::string> empty;
        REQUIRE_THROWS_AS(empty.front(), std::out_of_range);
        try {
            empty.front();
        } catch (const std::out_of_range& e) {
            REQUIRE(std::string(e.what()) == "Vectorius yra tuscias, negalima pasiekti elemento.");
        }
    }
    SECTION("back() test") {
        Vector<std::string> letters2{"a", "b", "c", "d"};
        REQUIRE(letters2.back() == "d");
    }
    SECTION("back() on empty vector") {
        Vector<std::string> empty2;
        REQUIRE_THROWS_AS(empty2.back(), std::out_of_range);
        try {
            empty2.back();
        } catch (const std::out_of_range& e) {
            REQUIRE(std::string(e.what()) == "Vectorius yra tuscias, negalima pasiekti elemento.");
        }
    }
}
TEST_CASE("push_back() and push_front(), pop_back() and pop_front()", "[Vector]") {
    SECTION("push_back() test") {
        Vector<std::string> letters;
        std::vector<std::string> std_letters;
        letters.push_back("abc");
        std_letters.push_back("abc");
        REQUIRE(letters.size() == std_letters.size());
        for (size_t i = 0; i < letters.size(); ++i) {
            REQUIRE(letters[i] == std_letters[i]);
        }
    }
    SECTION("push_front() test") {
        Vector<std::string> letters;
        std::vector<std::string> std_letters;
        letters.push_back("abc");
        std_letters.push_back("abc");
        letters.push_front("ghi");
        std::vector<std::string> std_letters_push{"ghi", "abc"};
        REQUIRE(letters.size() == std_letters_push.size());
        for (size_t i = 0; i < letters.size(); ++i) {
            REQUIRE(letters[i] == std_letters_push[i]);
        }
    }
    SECTION("pop_back() test") {
        Vector<std::string> pop_back_test{"one", "two", "three"};
        std::vector<std::string> std_pop_back{"one", "two", "three"};
        pop_back_test.pop_back();
        std_pop_back.pop_back();
        REQUIRE(pop_back_test.size() == std_pop_back.size());
        for (size_t i = 0; i < pop_back_test.size(); ++i) {
            REQUIRE(pop_back_test[i] == std_pop_back[i]);
        }
    }
    SECTION("pop_back() on empty vector") {
        Vector<std::string> empty_pop_back;
        REQUIRE_THROWS_AS(empty_pop_back.pop_back(), std::out_of_range);
        try {
            empty_pop_back.pop_back();
        } catch (const std::out_of_range& e) {
            REQUIRE(std::string(e.what()) == "Vectorius yra tuscias, negalima istrinti elemento.");
        }
    }
    SECTION("pop_front() test") {
        Vector<std::string> pop_front_test{"one", "two", "three"};
        std::vector<std::string> std_pop_front{"one", "two", "three"};
        pop_front_test.pop_front();
        std_pop_front.erase(std_pop_front.begin());
        REQUIRE(pop_front_test.size() == std_pop_front.size());
        for (size_t i = 0; i < pop_front_test.size(); ++i) {
            REQUIRE(pop_front_test[i] == std_pop_front[i]);
        }
    }
    SECTION("pop_front() on empty vector") {
        Vector<std::string> empty_pop_front;
        REQUIRE_THROWS_AS(empty_pop_front.pop_front(), std::out_of_range);
        try {
            empty_pop_front.pop_front();
        } catch (const std::out_of_range& e) {
            REQUIRE(std::string(e.what()) == "Vectorius yra tuscias, negalima istrinti elemento.");
        }
    }
}
TEST_CASE("clear() and empty(), size()", "[Vector]") {
    SECTION("clear() and empty() test") {
        std::vector<int> clearVec{1, 2, 3};
        REQUIRE(clearVec.size() == 3);
        clearVec.clear();
        REQUIRE(clearVec.size() == 0);
        REQUIRE(clearVec.empty() == true);
    }
    SECTION("size() test") {
        Vector<int> nums = {1, 2, 3, 4};
        REQUIRE(nums.size() == 4);
    }
}
TEST_CASE("reserve() and capacity()", "[Vector]") {
    SECTION("reserve() test") {
        int max_elements = 10;
        Vector<int> v;
        v.reserve(max_elements);
        int initial_capacity = v.capacity();
        REQUIRE(initial_capacity >= max_elements);
        bool capacity_changed = false;
        for (int i = 0; i < max_elements; ++i) {
            v.push_back(i);
            REQUIRE(v.size() == i + 1);
            REQUIRE(v.capacity() >= initial_capacity);
            if (v.capacity() != initial_capacity) {
                capacity_changed = true;
            }
        }
        REQUIRE((capacity_changed == false || initial_capacity >= max_elements));
    }
    SECTION("capacity() growth without reserve()") {
        int max_elements = 10;
        Vector<int> v;
        int previous_capacity = v.capacity();
        REQUIRE(previous_capacity > 0);
        bool capacity_increased = false;
        for (int i = 0; i < max_elements; ++i) {
            v.push_back(i);
            int current_capacity = v.capacity();
            REQUIRE(v.size() == i + 1);
            REQUIRE(current_capacity >= previous_capacity);
            if (current_capacity > previous_capacity) {
                capacity_increased = true;
                break;
            }
            previous_capacity = current_capacity;
        }
        REQUIRE(capacity_increased == true);
    }
}
TEST_CASE("resize() and shrink_to_fit()", "[Vector]") {
    SECTION("resize() up test") {
        Vector<int> v;
        REQUIRE(v.size() == 0);
        REQUIRE(v.capacity() > 0);
        v.resize(5);
        REQUIRE(v.size() == 5);
        REQUIRE(v[4] == 0);
    }
    SECTION("resize() down test") {
        Vector<int> v;
        v.resize(5);
        int cap_before_down = v.capacity();
        v.resize(2);
        REQUIRE(v.size() == 2);
        REQUIRE(v.capacity() == cap_before_down);
    }
    SECTION("shrink_to_fit() test after resize") {
        Vector<int> v;
        v.resize(5);
        int cap_before_shrink = v.capacity();
        v.shrink_to_fit();
        REQUIRE(v.capacity() <= cap_before_shrink);
    }
    SECTION("shrink_to_fit() after clear") {
        Vector<int> v;
        v.clear();
        v.shrink_to_fit();
        REQUIRE(v.capacity() == 0);
    }
    SECTION("shrink_to_fit() after adding large number of elements") {
        Vector<int> v;
        for (int i = 0; i < 100; ++i) {
            v.push_back(i);
        }
        int cap_before_big_shrink = v.capacity();
        v.shrink_to_fit();
        REQUIRE(v.capacity() <= cap_before_big_shrink);
    }
}
TEST_CASE("operator []", "[Vector]") {
    SECTION("operator [] access and modification") {
        Vector<int> numbers{2, 4, 6, 8};
        std::vector<int> std_numbers{2, 4, 6, 8};
        REQUIRE(numbers[1] == 4);
        numbers[0] = 5;
        std_numbers[0] = 5;
        REQUIRE(numbers[0] == 5);
        REQUIRE(std_numbers[0] == 5);
    }
    SECTION("operator [] consistency with std::vector") {
        Vector<int> numbers{2, 4, 6, 8};
        std::vector<int> std_numbers{2, 4, 6, 8};
        REQUIRE(numbers.size() == std_numbers.size());
        for (size_t i = 0; i < numbers.size(); ++i) {
            REQUIRE(numbers[i] == std_numbers[i]);
        }
    }
}
TEST_CASE("insert() and erase()", "[Vector]") {
    SECTION("insert() tests") {
        Vector<int> ins_vec{1, 3, 4};
        std::vector<int> ins_std_vec{1, 3, 4};
        ins_vec.insert(1, 2);
        ins_std_vec.insert(ins_std_vec.begin() + 1, 2);
        REQUIRE(ins_vec.size() == ins_std_vec.size());
        for (size_t i = 0; i < ins_vec.size(); ++i) {
            REQUIRE(ins_vec[i] == ins_std_vec[i]);
        }
        ins_vec.insert(0, 0);
        ins_std_vec.insert(ins_std_vec.begin(), 0);
        REQUIRE(ins_vec.size() == ins_std_vec.size());
        for (size_t i = 0; i < ins_vec.size(); ++i) {
            REQUIRE(ins_vec[i] == ins_std_vec[i]);
        }
        ins_vec.insert(ins_vec.size(), 5);
        ins_std_vec.insert(ins_std_vec.end(), 5);
        REQUIRE(ins_vec.size() == ins_std_vec.size());
        for (size_t i = 0; i < ins_vec.size(); ++i) {
            REQUIRE(ins_vec[i] == ins_std_vec[i]);
        }
        bool pass_invalid_insert = false;
        try {
            ins_vec.insert(100, 999);
            FAIL("Insert at invalid position did not throw exception");
        } catch (...) {
            pass_invalid_insert = true;
            REQUIRE(pass_invalid_insert == true);
        }
    }
    SECTION("erase() tests") {
        Vector<int> er{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<int> std_er{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        REQUIRE(er.size() == std_er.size());
        for (size_t i = 0; i < er.size(); ++i) {
            REQUIRE(er[i] == std_er[i]);
        }
        er.erase(0);
        std_er.erase(std_er.begin());
        REQUIRE(er.size() == std_er.size());
        for (size_t i = 0; i < er.size(); ++i) {
            REQUIRE(er[i] == std_er[i]);
        }
        for (int i = 0; i < er.size(); ++i) {
            if (er[i] % 2 == 0) {
                er.erase(i--);
            }
        }
        for (int i = 0; i < std_er.size(); ++i) {
            if (std_er[i] % 2 == 0) {
                std_er.erase(std_er.begin() + i--);
            }
        }
        REQUIRE(er.size() == std_er.size());
        for (size_t i = 0; i < er.size(); ++i) {
            REQUIRE(er[i] == std_er[i]);
        }
        for (int i = 0; i < er.size(); ++i) {
            if (er[i] % 2 != 0) {
                er.erase(i--);
            }
        }
        for (int i = 0; i < std_er.size(); ++i) {
            if (std_er[i] % 2 != 0) {
                std_er.erase(std_er.begin() + i--);
            }
        }
        REQUIRE(er.size() == std_er.size());
        for (size_t i = 0; i < er.size(); ++i) {
            REQUIRE(er[i] == std_er[i]);
        }
    }
}
TEST_CASE("at() test", "[Vector]") {
    SECTION("set and get elements") {
        Vector<int> data{1, 2, 4, 5, 5, 6};
        std::vector<int> std_data{1, 2, 4, 5, 5, 6};
        data.at(1) = 88;
        std_data.at(1) = 88;
        REQUIRE(data.at(2) == 4);
        REQUIRE(std_data.at(2) == 4);
        REQUIRE(data.size() == std_data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            REQUIRE(data[i] == std_data[i]);
        }
    }
    SECTION("out of range exception") {
        Vector<int> data{1, 2, 4, 5, 5, 6};
        std::vector<int> std_data{1, 2, 4, 5, 5, 6};
        auto moon_phase = [] {
            return std::chrono::system_clock::now().time_since_epoch().count() % 8;
        };
        bool caught_vector_exception = false;
        try {
            data.at(data.size() + moon_phase()) = 13;
        } catch (const std::out_of_range& ex) {
            caught_vector_exception = true;
            std::cout << "Caught exception from Vector: " << ex.what() << '\n';
        }
        REQUIRE(caught_vector_exception);
        bool caught_std_vector_exception = false;
        try {
            std_data.at(std_data.size() + moon_phase()) = 13;
        } catch (const std::out_of_range& ex) {
            caught_std_vector_exception = true;
            std::cout << "Caught exception from std::vector: " << ex.what() << '\n';
        }
        REQUIRE(caught_std_vector_exception);
    }
}
TEST_CASE("Copy and move assignment operator", "[Vector]") {
    SECTION("Copy assignment") {
        Vector<string> original {"a", "b", "c"};
        Vector<string> copy;
        copy = original;
        REQUIRE(copy.size() == 3);
        REQUIRE(copy[0] == "a");
        REQUIRE(copy[1] == "b");
        REQUIRE(copy[2] == "c");
        copy[0] = "z";
        REQUIRE(original[0] == "a");
        REQUIRE(copy[0] == "z");
        bool independence_pass = (original[0] != "z");
        REQUIRE(independence_pass);
    }
    SECTION("Move assignment") {
        Vector<string> to_move{"x", "y"};
        Vector<string> moved_into;
        moved_into = std::move(to_move);
        REQUIRE(moved_into.size() == 2);
        REQUIRE(moved_into[0] == "x");
        REQUIRE(moved_into[1] == "y");
        REQUIRE(to_move.size() == 0);
        REQUIRE(to_move.capacity() == 0);
        REQUIRE(to_move.data() == nullptr);
        bool move_pass = (moved_into.size() == 2 && moved_into[0] == "x" && moved_into[1] == "y");
        REQUIRE(move_pass);
    }
}
TEST_CASE("Comparison operators", "[Vector]") {
    SECTION("Equality operator (== and !=)") {
        Vector<int> a = {1, 2, 3};
        Vector<int> b = {1, 2, 3};
        Vector<int> c = {1, 2, 4};
        REQUIRE(a == b);
        REQUIRE_FALSE(a != b);
        REQUIRE(a != c);
    }
    SECTION("Less-than and greater-than operators (<, <=, >, >=)") {
        Vector<int> a = {1, 2, 3};
        Vector<int> b = {1, 2, 3};
        Vector<int> c = {1, 2, 4};
        Vector<int> d = {1, 2};
        Vector<int> e = {1, 2, 3, 0};
        REQUIRE((a == b));
        REQUIRE_FALSE(a != b);
        REQUIRE_FALSE(a < b);
        REQUIRE(a <= b);
        REQUIRE_FALSE(a > b);
        REQUIRE(a >= b);
        REQUIRE(a != c);
        REQUIRE(a < c);
        REQUIRE(a <= c);
        REQUIRE_FALSE(a > c);
        REQUIRE_FALSE(a >= c);
        REQUIRE(a != d);
        REQUIRE_FALSE(a < d);
        REQUIRE_FALSE(a <= d);
        REQUIRE(a > d);
        REQUIRE(a >= d);
        REQUIRE(a != e);
        REQUIRE(a < e);
        REQUIRE(a <= e);
        REQUIRE_FALSE(a > e);
        REQUIRE_FALSE(a >= e);
    }
}

// Testai Student klasei
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