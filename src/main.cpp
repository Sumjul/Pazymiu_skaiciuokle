#include "../include/global.h"
#include "../include/headers.h"
#include "../include/student.h"
#include "../include/vector.h"
#include "../include/templates.h"

int main()
{
	// Uncomment the container you want to use
	Vector<Student> group, failed; group.reserve(maxStud); failed.reserve(maxStud);
	//std::vector<Student> group, failed; group.reserve(maxStud); failed.reserve(maxStud);
	//deque<Student> group, failed;
	//list<Student> group, failed;

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