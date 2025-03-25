#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"

// Function that calculates the average marks of students.
void Student::calculateAverage()
{
	if (marks_.empty())
	{
		average_ = 0;
		median_ = 0;
	}
	else
	{
		double sum = 0;
		for (auto temp : marks_)
		{
			sum += temp;
		}
		average_ = 0.4 * (sum / marks_.size()) + 0.6 * exam_;
	}
}

// Function that calculates the median marks of students.
void Student::calculateMedian()
{
	if (marks_.empty())
	{
	}
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
void Student::readLine(string line)
{
	istringstream lineStream(line);
	lineStream >> name_ >> surname_;
	vector<int> markInput;
	int mark;
	while (lineStream >> mark)
		markInput.push_back(mark);
	if (!markInput.empty())
	{
		exam_ = markInput.back();
		markInput.pop_back();
		marks_ = std::move(markInput);
	}
}