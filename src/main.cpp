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
	cout << "-------------------------------------" << endl;
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

	cout << "-------------------------------------" << endl;
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
	
	cout << "-------------------------------------" << endl;
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

	cout << "-------------------------------------" << endl;
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

	cout << "-------------------------------------" << endl;
	cout << "clear() and empty()" << endl;
	cout << "-------------------------------------" << endl;
	std::vector<int> clearVec{1, 2, 3};
    cout << "Before clear size: " << clearVec.size() << endl;
	clearVec.clear();
	cout << "After clear size: " << clearVec.size() << endl;
	cout << "After clear: ";
	clearVec.empty() ? cout << "clear() and empty() tests [PASS]" << endl : cout << "clear() and empty() tests [FAIL]" << endl;

	cout << "-------------------------------------" << endl;
	cout << "size()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<int> nums = {1, 2, 3, 4};
	cout << "Vector: " << nums.size() << endl;
	nums.size() == 4 ? cout << "size() test [PASS]" << endl : cout << "size() test [FAIL]" << endl;

	cout << "-------------------------------------" << endl;
	cout << "reserve() and capacity()" << endl;
	cout << "-------------------------------------" << endl;
	int max_elements = 10;
    cout << "With reserve(): " << endl;
    {
        Vector<int> v;
        v.reserve(max_elements);
		int initial_capacity = v.capacity();
        cout << "Initial capacity: " << initial_capacity << endl;
		bool capacity_changed = false;
        for (int i = 0; i < max_elements; ++i) {
            v.push_back(i);
            cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << endl;
			if (v.capacity() != initial_capacity) {
            capacity_changed = true;
       	 	}
        }
		if (initial_capacity >= max_elements && !capacity_changed)
        cout << "reserve() test [PASS]" << endl;
    	else cout << "reserve() test [FAIL]" << endl;
	}
	// Without reserve() and check if capacity() grows
	cout << "Without reserve(): " << endl;
	{
		Vector<int> v;
		int previous_capacity = v.capacity();
		cout << "Initial capacity: " << previous_capacity << endl;
		bool capacity_increased = false;
		for (int i = 0; i < max_elements; ++i) {
			v.push_back(i);
			int current_capacity = v.capacity();
			cout << "Size: " << v.size() << ", Capacity: " << current_capacity << endl;
			if (current_capacity > previous_capacity) {
				capacity_increased = true;
				break;
			}
			previous_capacity = current_capacity;
		}
		if (capacity_increased)
			cout << "capacity() growth without reserve() [PASS]" << endl;
		else
			cout << "capacity() growth without reserve() [FAIL]" << endl;
	}

	cout << "-------------------------------------" << endl;
	cout << "resize() and shrink_to_fit()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<int> v;
	// Check initial size and capacity
	cout << "Initial size: " << v.size() << ", capacity: " << v.capacity() << endl;
	// Increase size
	v.resize(5);
	bool pass_resize_up = (v.size() == 5 && v[4] == 0);
	cout << "After resize(5): size = " << v.size() << ", capacity = " << v.capacity() << endl;
	cout << (pass_resize_up ? "Resize up test [PASS]" : "Resize up test [FAIL]") << endl;
	// Decrease size
	int cap_before_down = v.capacity();
	v.resize(2);
	bool pass_resize_down = (v.size() == 2 && v.capacity() == cap_before_down);
	cout << "After resize(2): size = " << v.size() << ", capacity = " << v.capacity() << endl;
	cout << (pass_resize_down ? "Resize down test [PASS]" : "Resize down test [FAIL]") << endl;
	// Shrink to fit after resize
	int cap_before_shrink = v.capacity();
	v.shrink_to_fit();
	bool pass_shrink = (v.capacity() <= cap_before_shrink);
	cout << "After shrink_to_fit(): size = " << v.size() << ", capacity = " << v.capacity() << endl;
	cout << (pass_shrink ? "shrink_to_fit test [PASS]" : "shrink_to_fit test [FAIL]") << endl;
	// Clear and shrink to fit
	v.clear();
	v.shrink_to_fit();
	bool pass_shrink_after_clear = (v.capacity() == 0);
	cout << "After clear() and shrink_to_fit(): size = " << v.size() << ", capacity = " << v.capacity() << endl;
	cout << (pass_shrink_after_clear ? "Shrink after clear [PASS]" : "Shrink after clear [FAIL]") << endl;
	// New push_back and shrink to fit
	for (int i = 0; i < 100; ++i) v.push_back(i);
	int cap_before_big_shrink = v.capacity();
	v.shrink_to_fit();
	bool pass_shrink_big = (v.capacity() <= cap_before_big_shrink);
	cout << "After adding 100 elements and shrink_to_fit(): capacity = " << v.capacity() << endl;
	cout << (pass_shrink_big ? "Shrink large vector test [PASS]" : "Shrink large vector test [FAIL]") << endl;

	cout << "-------------------------------------" << endl;
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

	cout << "-------------------------------------" << endl;
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

	cout << "-------------------------------------" << endl;
	cout << "insert()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<int> ins_vec{1, 3, 4};
	std::vector<int> ins_std_vec{1, 3, 4};
	ins_vec.insert(1, 2);
	ins_std_vec.insert(ins_std_vec.begin() + 1, 2);
	cout << "After insert(1, 2): ";
	print_container(ins_vec);
	bool pass_insert_middle = compare_vectors(ins_vec, ins_std_vec, "Insert in the middle");
	ins_vec.insert(0, 0);
	ins_std_vec.insert(ins_std_vec.begin(), 0);
	cout << "After insert(0, 0): ";
	print_container(ins_vec);
	bool pass_insert_front = compare_vectors(ins_vec, ins_std_vec, "Insert at front");
	ins_vec.insert(ins_vec.size(), 5);
	ins_std_vec.insert(ins_std_vec.end(), 5);
	cout << "After insert(end, 5): ";
	print_container(ins_vec);
	bool pass_insert_end = compare_vectors(ins_vec, ins_std_vec, "Insert at end");
	bool pass_invalid_insert = false;
	try {
		ins_vec.insert(100, 999);
		cout << "Insert at invalid position did not throw [FAIL]" << endl;
	} catch (...) {
		cout << "Insert at invalid position threw exception [PASS]" << endl;
		pass_invalid_insert = true;
	}
	if (pass_insert_middle && pass_insert_front && pass_insert_end && pass_invalid_insert)
		cout << "All insert() tests [PASS]" << endl;
	else
		cout << "Some insert() tests [FAIL]" << endl;

	cout << "-------------------------------------" << endl;
	cout << "erase()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<int> er{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> std_er{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "Initial container: ";
	print_container(er);
	// ERASE(0)
	er.erase(0);
	std_er.erase(std_er.begin());
	cout << "After erase(0): ";
	print_container(er);
	// Erase all even numbers
	for (int i = 0; i < er.size(); ++i)
	{
		if (er[i] % 2 == 0)
		{
			er.erase(i--);
		}
	}
	for (int i = 0; i < std_er.size(); ++i)
	{
		if (std_er[i] % 2 == 0)
		{
			std_er.erase(std_er.begin() + i--);
		}
	}
	cout << "After erase all even numbers: ";
	print_container(er);
	// Erase all odd numbers
	for (int i = 0; i < er.size(); ++i)
	{
		if (er[i] % 2 != 0)
		{
			er.erase(i--);
		}
	}
	for (int i = 0; i < std_er.size(); ++i)
	{
		if (std_er[i] % 2 != 0)
		{
			std_er.erase(std_er.begin() + i--);
		}
	}
	cout << "After erase all odd numbers: ";
	print_container(er);
	compare_vectors(er, std_er, "erase() test");

	cout << "-------------------------------------" << endl;
	cout << "copy and move assignment operator" << endl;
	cout << "-------------------------------------" << endl;
	// Copy assignment
	Vector<string> original {"a", "b", "c"};
	Vector<string> copy;
	copy = original;
	cout << "After copy assignment: ";
	print_container(copy);
	bool copy_pass = compare_vectors(copy, std::vector<string>{"a", "b", "c"}, "Copy assignment content");
	bool independence_pass = true;
	copy[0] = "z";
	if (original[0] == "z")
	{
		cout << "Copy assignment test [FAIL] — shallow copy detected" << endl;
		independence_pass = false;
	}
	else
	{
		cout << "Copy assignment test [PASS] — deep copy confirmed" << endl;
	}
	// Move assignment
	Vector<string> to_move{"x", "y"};
	Vector<string> moved_into;
	moved_into = std::move(to_move);
	cout << "After move assignment: ";
	print_container(moved_into);
	bool move_pass = compare_vectors(moved_into, std::vector<string>{"x", "y"}, "Move assignment content");
	bool moved_source_empty = (to_move.size() == 0 && to_move.capacity() == 0 && to_move.data() == nullptr);
	if (moved_source_empty)
		cout << "Move assignment state cleared [PASS]" << endl;
	else
		cout << "Move assignment state not cleared properly [FAIL]" << endl;
	if (copy_pass && independence_pass && move_pass && moved_source_empty)
		cout << "All assignment operator tests [PASS]" << endl;
	else
		cout << "Some assignment operator tests [FAIL]" << endl;

	cout << "-------------------------------------" << endl;
	cout << "operators" << endl;
	cout << "-------------------------------------" << endl;
	Vector<int> a = {1, 2, 3};
    Vector<int> b = {1, 2, 3};
    Vector<int> c = {1, 2, 4};
    Vector<int> d = {1, 2};
    Vector<int> e = {1, 2, 3, 0};
    // a vs b (equal)
    bool pass_equal = (a == b) && !(a != b) && !(a < b) && (a <= b) && !(a > b) && (a >= b);
    // a vs c (a < c)
    bool pass_less = (a != c) && (a < c) && (a <= c) && !(a > c) && !(a >= c);
    // a vs d (a > d)
    bool pass_greater = (a != d) && !(a < d) && !(a <= d) && (a > d) && (a >= d);
    // a vs e (a < e)
    bool pass_less_by_size = (a != e) && (a < e) && (a <= e) && !(a > e) && !(a >= e);
    if (pass_equal && pass_less && pass_greater && pass_less_by_size) {
        std::cout << "[PASS] Comparison operators\n";
    } else {
        std::cout << "[FAIL] Comparison operators\n";
    }
	cout << endl << "----------------------------------------------------------------------------";

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