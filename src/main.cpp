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
		Student A;
		A.setName("Testas");
		A.setSurname("Testinis");
		A.addMark(10);
		A.addMark(9);
		A.setExam(10);
		A.calculateAverage();
		A.calculateMedian();
		cout << "Vardas: " << A.getName() << endl;
		cout << "Pavarde: " << A.getSurname() << endl;
		cout << "Galutinis (Vid.): " << A.getAverage() << endl;
		cout << "Galutinis (Med.): " << A.getMedian() << endl;
		cout << "\n=== Copy constructing B from A ===" << endl;
		Student B = A; // Copy constructor
		printStudent(B);

		cout << "\n=== Move constructing C from B ===" << endl;
		Student C = std::move(B); // Move constructor
		printStudent(C);

		cout << "\n=== Creating D and copy-assigning from A ===" << endl;
		Student D;
		D = A; // Copy assignment
		printStudent(D);

		cout << "\n=== Creating E and move-assigning from A ===" << endl;
		Student E;
		E = std::move(A); // Move assignment
		printStudent(E);

		cout << "\n=== End of main (destructors will be called) ===" << endl;
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