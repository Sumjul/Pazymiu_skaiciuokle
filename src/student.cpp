#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"
#include "../include/vector.h"


// Copy constructor
Student::Student(const Student &other)
	: Human(other), marks_(other.marks_), exam_(other.exam_),
	  average_(other.average_), median_(other.median_) {}

// Move constructor
Student::Student(Student &&other)
	: Human(move(other)), marks_(move(other.marks_)), exam_(move(other.exam_)), average_(move(other.average_)), median_(move(other.median_))
{
	other.name_.clear();
	other.surname_.clear();
	other.marks_.clear();
	other.exam_ = 0;
	other.average_ = 0;
	other.median_ = 0;
}

// Copy assignment operator
Student &Student::operator=(const Student &other)
{
	if (this == &other)
		return *this;
	name_ = other.name_;
	surname_ = other.surname_;
	marks_ = other.marks_;
	exam_ = other.exam_;
	average_ = other.average_;
	median_ = other.median_;
	return *this;
}

// Move assignment operator
Student &Student::operator=(Student &&other)
{
	if (this == &other)
		return *this;
	name_ = move(other.name_);
	surname_ = move(other.surname_);
	marks_ = move(other.marks_);
	exam_ = other.exam_;
	average_ = other.average_;
	median_ = other.median_;
	other.exam_ = 0;
	other.average_ = 0;
	other.median_ = 0;
	return *this;
}

// Overloaded output operator for Student class
ostream &operator<<(ostream &out, const Student &student)
{
	out << left << setw(20) << student.getSurname() << setw(20) << student.getName() << setw(20) << fixed << setprecision(2) << student.getAverage() << setw(20) << fixed << setprecision(2) << student.getMedian() << endl;
	return out;
}

// Overloaded input operator for Student class
istream &operator>>(istream &in, Student &student)
{
	cout << "Iveskite studento varda: " << endl;
	in >> student.name_;
	cout << "Iveskite studento pavarde: " << endl;
	in >> student.surname_;
	cout << "Iveskite studento atliktu namu darbu kieki (iveskite 0, jei kiekis yra nezinomas): " << endl;
	int markCount = NumberCheck(0, 100);

	bool knownCount = true;
	if (markCount == 0)
	{
		knownCount = false;
		markCount = 100;
	}
	if (!knownCount)
	{
		cout << "Iveskite studento visus atliktu namu darbu rezultatus (0 - baigti ivedima): " << endl;
		while (true)
		{
			int mark = NumberCheck(0, 10);
			if (mark == 0) break;
			student.addMark(mark);
		}
	}
	else
	{
		cout << "Iveskite studento visus atliktu namu darbu rezultatus: " << endl;
		for (int j = 0; j < markCount; j++)
		{
			int mark = NumberCheck(1, 10);
			student.addMark(mark);
		}
	}
	cout << "Iveskite studento egzamino pazymi: " << endl;
	student.setExam(NumberCheck(1, 10));
	student.calculateAverage();
	student.calculateMedian();
	return in;
}

// Function that prints the student data to the console.
void Student::print() const
{
	cout << "Vardas: " << name_ << ", " << "Pavarde: " << surname_ << ", " << "Galutinis (Vid.): " << average_ << ", " << "Galutinis (Med.): " << median_ << ", " << "Egzaminas: " << exam_ << ", " << "Pazymiai: ";
	for (auto mark : marks_)
		cout << mark << " ";
	cout << endl;
}

// Function that calculates the average marks of students.
void Student::calculateAverage()
{
	if (marks_.empty())
		average_ = 0;
	else
	{
		double sum = 0;
		for (auto temp : marks_)
			sum += temp;
		average_ = 0.4 * (sum / marks_.size()) + 0.6 * exam_;
	}
}

// Function that calculates the median marks of students.
void Student::calculateMedian()
{
	if (marks_.empty())
		median_ = 0;
	else
	{
		sort(marks_.begin(), marks_.end());
		if (marks_.size() % 2 == 0)
			median_ = (marks_[marks_.size() / 2 - 1] + marks_[marks_.size() / 2]) / 2.0;
		else
			median_ = marks_[marks_.size() / 2];
	}
}

// Function that reads a line from a file and assigns it to a student.
void Student::readLine(const string &line)
{
	istringstream lineStream(line);
	lineStream >> name_ >> surname_;
	vector<int> markInput;
	int mark;
	while (lineStream >> mark)
		markInput.emplace_back(mark);
	if (!markInput.empty())
	{
		exam_ = markInput.back();
		markInput.pop_back();
		marks_ = move(markInput);
	}
}