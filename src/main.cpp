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

int main()
{
	cout << "--------------------------------------" << endl;
	cout << "size()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<int> nums = {1, 2, 3, 4};
	std::vector<int> std_nums = {1, 2, 3, 4};
	std::cout << "Vector: ";
	print_container(nums);
	std::cout << "std::vector: ";
	print_container(std_nums);
	bool passed_size = (nums.size() == std_nums.size());
	for (size_t i = 0; i < nums.size() && i < std_nums.size(); ++i)
	{
		if (nums[i] != std_nums[i])
		{
			passed_size = false;
			break;
		}
	}
	cout << (passed_size ? "[PASS] size() test passed\n" : "[FAIL] size() test failed\n");

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
	// Compare with std::vector
	bool passed_at = (data.size() == std_data.size());
	for (size_t i = 0; i < data.size(); ++i)
	{
		if (data.at(i) != std_data.at(i))
		{
			passed_at = false;
			break;
		}
	}
	cout << (passed_at ? "[PASS] at() test passed\n" : "[FAIL] at() test failed\n");

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
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] != std_numbers[i])
		{
			passed_brackets = false;
			break;
		}
	}
	cout << (passed_brackets ? "[PASS] operator[] test passed\n" : "[FAIL] operator[] test failed\n");

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
	// Final correctness check
	bool passed_erase = (c.size() == std_c.size());
	for (size_t i = 0; i < c.size(); ++i)
	{
		if (c[i] != std_c[i])
		{
			passed_erase = false;
			break;
		}
	}
	cout << (passed_erase ? "[PASS] erase() test passed\n" : "[FAIL] erase() test failed\n");

	cout << "--------------------------------------" << endl;
	cout << "push_back()" << endl;
	cout << "-------------------------------------" << endl;
	Vector<std::string> letters;
	vector<string> std_letters;
	letters.push_back("abc");
	std_letters.push_back("abc");
	string s{"def"};
	string std_s{"def"};
	letters.push_back(move(s));
	std_letters.push_back(move(std_s));
	cout << "Vector letters holds: ";
	print_container(letters);
	cout << "\nMoved-from string s holds: " << std::quoted(s) << endl;
	cout << "Moved-from std_s holds: " << std::quoted(std_s) << endl;
	bool passed_pushback = (letters.size() == std_letters.size());
	for (size_t i = 0; i < letters.size() && passed_pushback; ++i)
	{
		if (letters[i] != std_letters[i])
			passed_pushback = false;
	}
	cout << (passed_pushback ? "[PASS] push_back test passed\n" : "[FAIL] push_back test failed\n");

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