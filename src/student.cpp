#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"

void Student::readLine(string line) {
	istringstream lineStream(line);
	lineStream >> name >> surname;
	vector<int> markInput;
	int mark;
	while (lineStream >> mark)
		markInput.push_back(mark);
	if (!markInput.empty())
	{
		exam = markInput.back();
		markInput.pop_back();
		marks = std::move(markInput);
	}
}




// Function that calculates the average marks of students.
void Student::calculateAverage()
{
	if (marks.empty())
	{
		average = 0;
		median = 0;
	}
	else
	{
		double sum = 0;
		for (auto temp : marks)
		{
			sum += temp;
		}
		average = 0.4 * (sum / marks.size()) + 0.6 * exam;
	}
}

// Function that calculates the median marks of students.
void Student::calculateMedian()
{
	if (marks.empty())
	{
		
	}
	else
	{
		sort(marks.begin(), marks.end());
		if (marks.size() % 2 == 0)
			median = (marks[marks.size() / 2 - 1] + marks[marks.size() / 2]) / 2.0;
		else
			median = marks[marks.size() / 2];
	}
}