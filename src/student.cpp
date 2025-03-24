#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/templates.h"

// Calculate the average of marks and exam (weighted).
void Student::calculateAverage()
{
	if (marks.empty())
	{
		average = 0;
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

// Calculate the median of marks
void Student::calculateMedian()
{
	if (marks.empty())
	{
		median = 0;
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