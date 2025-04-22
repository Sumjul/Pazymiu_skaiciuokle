#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"
double globalTime = 0;

// Function that test the Student class and its methods.
void TestStudentClass() {
	cout << "===== TESTAVIMAS: Student klases testai =====" << endl;
		cout << "\n=== Rule of Five: Sukuriamas Student A ===" << endl;
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
		cout << "A:\n" << A;

    cout << "\n=== Copy constructor: Student B(A) ===" << endl;
    Student B = A;
    cout << "B:\n" << B;

    cout << "\n=== Move constructor: Student C(std::move(B)) ===" << endl;
    Student C = std::move(B);
    cout << "C:\n" << C;

    cout << "\n=== Copy assignment: Student D = A ===" << endl;
    Student D;
    D = A;
    cout << "D:\n" << D;

    cout << "\n=== Move assignment: Student E = std::move(A) ===" << endl;
    Student E;
    E = std::move(A);
    cout << "E:\n" << E;

    // --- Testing operator >>
    cout << "\n=== Operator >> test using stringstream ===" << endl;
    Student inputStudent;
    cin >> inputStudent;

    // --- Testing operator <<
    cout << "\n=== Operator << test using stringstream ===" << endl;
    std::stringstream output;
    output << inputStudent;
    cout << "Isvestas tekstas i stringstream:\n" << output.str();

	cout << "\n=== Abstrakti klase Human: testas ===" << endl;
    //Human jonas("Jonas", "Jonaitis"); // Klaida – negalima kurti abstraktaus objekto
    Human* testHuman = new Student("Jonas", "Jonaitis", 10);
    testHuman->print();
    delete testHuman;

    cout << "\n===== TESTAVIMAS BAIGTAS =====\n" << endl;
}

// Function that checks if the input is a number and if it is within the specified range.
int NumberCheck(int min, int max)
{
	int number;
	while (true)
	{
		try
		{
			if (cin >> number && number >= min && number <= max)
				break;
			else
			{
				throw std::invalid_argument("Ivestis netinkama. Iveskite dar karta:");
			}
		}
		catch (...)
		{
			ProcessException();
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return number;
}

// Function that displays the menu and returns the selected action.
int Menu()
{
	cout << "Sveiki atvyke i pazymiu skaiciuokle! Pasirinkite veiksma spausdami skaiciu ir tada spauskite Enter." << endl;
	cout << "--------------------------------------------" << endl;
	cout << "0 - baigti darba;" << endl;
	cout << "1 - pildyti duomenis rankiniu budu;" << endl;
	cout << "2 - generuoti pazymius;" << endl;
	cout << "3 - generuoti pazymius, vardus ir pavardes;" << endl;
	cout << "4 - nauduoti duomenis is failo;" << endl;
	cout << "5 - sugeneruoti duomenis ir isvesti i faila;" << endl;
	cout << "6 - surusiuoti studentus i 2 failus." << endl;
	cout << "7 - Studento klases testavimas." << endl;
	cout << "--------------------------------------------" << endl;
	int action = NumberCheck(0, 7);
	return action;
}

// Function that ends the program.
void ProgramEnd()
{
	cout << endl;
	if (globalTime != 0) cout << " * Programa veike: " << globalTime << " sekundziu. " << endl;
	cout << "Aciu, kad naudojates pazymiu skaiciuokle!" << endl;
	cout << "Paspauskite Enter, kad uzbaigtumete programos darba." << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
}

// Function that processes exceptions.
void ProcessException()
{
	try
	{
		throw;
	}
	catch (const ios_base::failure &e)
	{
		cerr << "Ivesties/isvesties isimtis: " << e.what() << endl;
	}
	catch (const system_error &e)
	{
		cerr << "Sistemos isimtis: " << e.what() << endl;
	}
	catch (const future_error &e)
	{
		cerr << "Ateities užduoties isimtis: " << e.what() << endl;
	}
	catch (const bad_alloc &e)
	{
		cerr << "Priskyrimo klaida (bad_alloc): " << e.what() << endl;
	}
	catch (const exception &e)
	{
		cerr << "Klaida: " << e.what() << endl;
	}
	catch (...)
	{
		cerr << "Nežinoma klaida. " << endl;
	}
}
