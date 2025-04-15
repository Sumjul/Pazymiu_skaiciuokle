#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"

// Copy constructor
Student::Student(const Student &other)
	: name_{other.name_}, surname_{other.surname_}, marks_{other.marks_}, exam_{other.exam_},
	  average_{other.average_}, median_{other.median_}
{
	for (int i=0; i<other.marks_.size(); i++)
		marks_.push_back(other.marks_[i]);
}

// Move constructor
Student::Student(Student &&other)
	: name_{move(other.name_)}, surname_{move(other.surname_)}, marks_{move(other.marks_)},
	  exam_{other.exam_}, average_{other.average_}, median_{other.median_}
{
	other.exam_ = 0;
	other.average_ = 0;
	other.median_ = 0;
	other.marks_.clear();
	other.marks_ = nullptr;
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