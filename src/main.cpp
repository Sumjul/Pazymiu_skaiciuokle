#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"

int main()
{
	// Uncomment the container you want to use

	vector<Student> group, failed; group.reserve(maxStud); failed.reserve(maxStud);
	//deque<Student> group, failed;
	//list<Student> group, failed;

	srand(time(NULL));
	int action = Menu();
	if (action == 7) {
		cout << "===== TESTING RULE OF FIVE IMPLEMENTATION =====" << endl;
		Student A;
		A.setName("Testas");
		A.setSurname("Testinis");
		vector<int> testmarks = { 10, 9, 8, 7, 10, 6, 9, 8 };
		for (int mark : testmarks) {
			A.addMark(mark);
		}
		A.setExam(9);
		A.calculateAverage();
		A.calculateMedian();
		cout << "=== Original Student A ===" << endl;
		A.printStudent();
		cout << endl;

		cout << "=== Copy constructing B from A ===" << endl;
		Student B = A; // Copy constructor
		B.printStudent();
		cout << endl;

		cout << "=== Move constructing C from B ===" << endl;
		Student C = std::move(B); // Move constructor
		C.printStudent();
		cout << endl;

		cout << "=== Creating D and copy-assigning from A ===" << endl;
		Student D;
		D = A; // Copy assignment
		D.printStudent();
		cout << endl;

		cout << "=== Creating E and move-assigning from A ===" << endl;
		Student E;
		E = move(A); // Move assignment
		E.printStudent();
		cout << endl;

		cout << "=== End of main (destructors will be called) ===" << endl;
		system("pause");
		return 0;
	}

	else if (action == 1 || action == 2 || action == 3)
		Action(group, action);
	else if (action == 7)
		return 0;
	else if (action == 0)
		return 0;
	else if (action == 4)
		ReadFromFile(group, action);
	else if (action == 5)
		GenerateFile(group);
	else if (action == 6)
	{
		ReadFromFile(group, action);
		SeparateStudents(group, failed);
		OutputSeparated(group, failed);
	}
	else
	{
		Action(group, action);
		Calculations(group);
		int markAction;
		Sort(group, markAction);
		Output(group, cout, markAction);
	}
	ProgramEnd();
	return 0;
}