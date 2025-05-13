#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"
#include "../include/vector.h"

template <typename Container>
void print_container(const Container &c)
{
	for (const auto &elem : c)
		cout << elem << ' ';
	cout << endl;
}

template<typename T>
bool compare_vectors(const Vector<T>& custom, const std::vector<T>& standard, const string& test_name = "") {
	if (custom.size() != standard.size()) {
		std::cout << "[FAIL] " << test_name << " — size mismatch: "
		          << custom.size() << " != " << standard.size() << '\n';
		return false;
	}
	for (size_t i = 0; i < custom.size(); ++i) {
		if (custom[i] != standard[i]) {
			std::cout << "[FAIL] " << test_name << " — mismatch at index " << i
			          << ": " << custom[i] << " != " << standard[i] << '\n';
			return false;
		}
	}
	std::cout << "[PASS] " << test_name << '\n';
	return true;
}

int main()
{
	cout << "--------------------------------------" << endl;
	cout << "Constructors" << endl;
	cout << "-------------------------------------" << endl;
	// Default constructor
	Vector<string> empty_vec;
	std::vector<string> std_empty_vec;
	cout << "Vector: ";
	print_container(empty_vec);
	compare_vectors(empty_vec, std_empty_vec, "Default constructor");
	// Initializer list constructor
    Vector<string> words1{"the", "frogurt", "is", "also", "cursed"};
	std::vector<string> std_words1{"the", "frogurt", "is", "also", "cursed"};
	cout << "Vector: ";
	print_container(words1);
	compare_vectors(words1, std_words1, "Initializer list constructor");
    // Copy constructor
    Vector<string> copy_source(words1);
	std::vector<string> std_copy_source(std_words1);
	Vector<string> copied(copy_source);
	std::vector<string> std_copied(std_copy_source);
	cout << "Copied vector: ";
	print_container(copied);
	compare_vectors(copied, std_copied, "Copy constructor");
	cout << "Copy source: ";
	print_container(copy_source);
	compare_vectors(copy_source, std_copy_source, "Copy constructor source");
	// Move constructor
	Vector<string> move_source{"move", "this"};
	std::vector<string> std_move_source{"move", "this"};
	Vector<string> moved(move(move_source));
	std::vector<string> std_moved(move(std_move_source));
	cout << "Moved vector: ";
	print_container(moved);
	compare_vectors(moved, std_moved, "Move constructor");
	std::vector<string> std_empty;
	cout << "Moved-from vector: ";
	print_container(move_source);
	compare_vectors(move_source, std_empty, "Move constructor source");
    // Parametrized constructor
    Vector<string> words3(5, "Mo");
	std::vector<string> std_words3(5, "Mo");
	cout << "Vector: ";
	print_container(words3);
	compare_vectors(words3, std_words3, "Fill constructor");

	cout << "--------------------------------------" << endl;
	cout << "front() and back()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<string> letters1{"a", "b", "c", "d"};
	std::vector<string> std_letters1{"a", "b", "c", "d"};
    letters1.front() == "a" ? cout << "front() test [PASS]"<< endl : cout << "front() test [FAIL]" << endl;
	Vector<string> empty;
	try {
		empty.front();
		cout << "Accessed front() on empty vector - [FAIL]" << endl;
	} catch (const std::out_of_range& e) {
		if (std::string(e.what()) == "Vectorius yra tuscias, negalima pasiekti elemento.")
			cout << "Correct exception message - [PASS]" << endl;
		else
			cout << "Wrong exception message: " << e.what() << " - [FAIL]" << endl;
	}
	Vector<string> letters2{"a", "b", "c", "d"};
	std::vector<string> std_letters2{"a", "b", "c", "d"};
	letters2.back() == "d" ? cout << "back() test [PASS]" << endl : cout << "back() test [FAIL]" << endl;
	Vector<string> empty2;
	try {
		empty2.back();
		cout << "Accessed back() on empty vector - [FAIL]" << endl;
	} catch (const std::out_of_range& e) {
		if (std::string(e.what()) == "Vectorius yra tuscias, negalima pasiekti elemento.")
			cout << "Correct exception message on back() - [PASS]" << endl;
		else
			cout << "Wrong exception message on back(): " << e.what() << " - [FAIL]" << endl;
	}
	
	cout << "--------------------------------------" << endl;
	cout << "push_back() and push_front()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<string> letters;
	std::vector<string> std_letters;
	letters.push_back("abc");
	std_letters.push_back("abc");
	cout << "Vector letters holds: ";
	print_container(letters);
	compare_vectors(letters, std_letters, "push_back() test");
	letters.push_front("ghi");
	std::vector<string> std_letters_push {"ghi", "abc"};
	cout << "Vector letters holds: ";
	print_container(letters);
	compare_vectors(letters, std_letters_push, "push_front() test");

	cout << "--------------------------------------" << endl;
	cout << "pop_back() and pop_front()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<string> pop_back_test{"one", "two", "three"};
	std::vector<string> std_pop_back{"one", "two", "three"};
	pop_back_test.pop_back();
	std_pop_back.pop_back();
	cout << "After pop_back(): ";
	print_container(pop_back_test);
	compare_vectors(pop_back_test, std_pop_back, "pop_back() test");
	Vector<string> empty_pop_back;
	try {
		empty_pop_back.pop_back();
		cout << "Accessed pop_back() on empty vector - [FAIL]" << endl;
	} catch (const std::out_of_range& e) {
		if (std::string(e.what()) == "Vectorius yra tuscias, negalima istrinti elemento.")
			cout << "Correct exception message on pop_back() - [PASS]" << endl;
		else
			cout << "Wrong exception message on pop_back(): " << e.what() << " - [FAIL]" << endl;
	}
	Vector<string> pop_front_test{"one", "two", "three"};
	std::vector<string> std_pop_front{"one", "two", "three"};
	pop_front_test.pop_front();
	std_pop_front.erase(std_pop_front.begin());
	cout << "After pop_front(): ";
	print_container(pop_front_test);
	compare_vectors(pop_front_test, std_pop_front, "pop_front() test");
	Vector<string> empty_pop_front;
	try {
		empty_pop_front.pop_front();
		cout << "Accessed pop_front() on empty vector - [FAIL]" << endl;
	} catch (const std::out_of_range& e) {
		if (std::string(e.what()) == "Vectorius yra tuscias, negalima istrinti elemento.")
			cout << "Correct exception message on pop_front() - [PASS]" << endl;
		else
			cout << "Wrong exception message on pop_front(): " << e.what() << " - [FAIL]" << endl;
	}

	cout << "--------------------------------------" << endl;
	cout << "clear() and empty()" << endl;
	cout << "-------------------------------------" << endl;
	std::vector<int> clearVec{1, 2, 3};
    cout << "Before clear size: " << clearVec.size() << endl;
	clearVec.clear();
	cout << "After clear size: " << clearVec.size() << endl;
	cout << "After clear: ";
	clearVec.empty() ? cout << "clear() and empty() tests [PASS]" << endl : cout << "clear() and empty() tests [FAIL]" << endl;

	cout << "--------------------------------------" << endl;
	cout << "size()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<int> nums = {1, 2, 3, 4};
	cout << "Vector: " << nums.size() << endl;
	nums.size() == 4 ? cout << "size() test [PASS]" << endl : cout << "size() test [FAIL]" << endl;

	cout << "--------------------------------------" << endl;
	cout << "at()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<int> data{1, 2, 4, 5, 5, 6};
	std::vector<int> std_data{1, 2, 4, 5, 5, 6};
	// Set element 1
	data.at(1) = 88;
	std_data.at(1) = 88;
	// Read element 2
	cout << "Element at index 2 has value " << data.at(2) << '\n';
	cout << "data size = " << data.size() << '\n';
	try
	{
		auto moon_phase = []
		{
			return std::chrono::system_clock::now().time_since_epoch().count() % 8;
		};
		data.at(data.size() + moon_phase()) = 13;
	}
	catch (const std::out_of_range &ex)
	{
		cout << "Caught exception from Vector: " << ex.what() << '\n';
	}
	try
	{
		auto moon_phase = []
		{
			return std::chrono::system_clock::now().time_since_epoch().count() % 8;
		};
		std_data.at(std_data.size() + moon_phase()) = 13;
	}
	catch (const std::out_of_range &ex)
	{
		cout << "Caught exception from std::vector: " << ex.what() << '\n';
	}
	// Final state check
	cout << "Final data: ";
	print_container(data);
	compare_vectors(data, std_data, "at() test");

	cout << "--------------------------------------" << endl;
	cout << "operator []" << endl;
	cout << "-------------------------------------" << endl;
	Vector<int> numbers{2, 4, 6, 8};
	std::vector<int> std_numbers{2, 4, 6, 8};
	cout << "Second element: " << numbers[1] << '\n';
	numbers[0] = 5;
	std_numbers[0] = 5;
	cout << "All numbers: ";
	print_container(numbers);
	// Compare with std::vector
	bool passed_brackets = (numbers.size() == std_numbers.size());
	compare_vectors(numbers, std_numbers, "operator [] test");

	cout << "--------------------------------------" << endl;
	cout << "erase()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> std_c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "Initial container: ";
	print_container(c);
	// ERASE(0)
	c.erase(0);
	std_c.erase(std_c.begin());
	cout << "After erase(0): ";
	print_container(c);
	// Erase all even numbers
	for (int i = 0; i < c.size(); ++i)
	{
		if (c[i] % 2 == 0)
		{
			c.erase(i--);
		}
	}
	for (int i = 0; i < std_c.size(); ++i)
	{
		if (std_c[i] % 2 == 0)
		{
			std_c.erase(std_c.begin() + i--);
		}
	}
	cout << "After erase all even numbers: ";
	print_container(c);
	// Erase all odd numbers
	for (int i = 0; i < c.size(); ++i)
	{
		if (c[i] % 2 != 0)
		{
			c.erase(i--);
		}
	}
	for (int i = 0; i < std_c.size(); ++i)
	{
		if (std_c[i] % 2 != 0)
		{
			std_c.erase(std_c.begin() + i--);
		}
	}
	cout << "After erase all odd numbers: ";
	print_container(c);
	compare_vectors(c, std_c, "erase() test");

	cout << endl
		 << "----------------------------------------------------------------------------";
	// Uncomment the container you want to use
	vector<Student> group, failed;
	group.reserve(maxStud);
	failed.reserve(maxStud);
	// deque<Student> group, failed;
	// list<Student> group, failed;

	srand(time(NULL));
	int action = Menu();
	switch (action)
	{
	case 0:
		return 0;
	case 4:
		ReadFromFile(group, action);
		break;
	case 5:
		GenerateFile(group);
		break;
	case 6:
		ReadFromFile(group, action);
		SeparateStudents(group, failed);
		OutputSeparated(group, failed);
		break;
	default:
		Action(group, action);
		int markAction;
		Sort(group, markAction);
		Output(group, cout, markAction);
		break;
	}
	ProgramEnd();
	return 0;
}