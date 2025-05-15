#pragma once
#include "../include/vector.h"

/** Function that reads data from a file. */
template <typename Container>
void ReadFromFile(Container &group, int action)
{
	string readName;
	bool fileLoaded = false;
	while (!fileLoaded)
	{
		cout << "Iveskite failo pavadinima, is kurio bus skaitomi duomenys: " << endl;
		cin >> readName;
		try
		{
			ifstream input(readName, std::ios::binary);
			if (!input)
				throw std::ios_base::failure("Failas nerastas arba negali buti atidarytas.");
			else
			{
				fileLoaded = true;
				Timer inputTime;
				string line;
				getline(input, line);
				while (getline(input, line))
				{
					Student temp;
					temp.readLine(line);
					temp.calculateAverage();
					temp.calculateMedian();
					group.push_back(move(temp));
				}
				input.close();
				cout << " * Duomenu skaitymas uztruko: " << inputTime.elapsed() << " sekundziu. " << endl;
				globalTime += inputTime.elapsed();
			}
		}
		catch (...)
		{
			ProcessException();
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	if (action != 6)
	{
		string writeName = "rezultatas.txt";
		ofstream output(writeName);
		int markAction;
		Sort(group, markAction);
		Output(group, output, markAction);
		output.close();
		cout << "Duomenys nukopijuoti i faila: " << writeName << endl;
	}
}

/** Function that asks the user to input data manually or generates it randomly. */
template <typename Container>
void Action(Container &group, int action)
{
	cout << "Iveskite studentu skaiciu (iveskite 0, jei skaicius yra nezinomas): " << endl;
	int amountStud = NumberCheck(0, maxStud);
	bool amountStudKnown = (amountStud != 0);
	if (!amountStudKnown)
		amountStud = maxStud;

	for (int i = 0; i < amountStud; i++)
	{
		Student temp;
		if (action == 2)
		{
			string name, surname;
			cout << "Iveskite studento varda: ";
			cin >> name;
			temp.setName(name);
			cout << "Iveskite studento pavarde: ";
			cin >> surname;
			temp.setSurname(surname);
		}
		else if (action == 3)
		{
			temp.setName(names[rand() % names.size()]);
			temp.setSurname(surnames[rand() % surnames.size()]);
		}
		if (action == 2 || action == 3)
		{
			int amountMarks = rand() % 100 + 1;
			for (int j = 0; j < amountMarks; ++j)
				temp.addMark(rand() % 10 + 1);
			temp.setExam(rand() % 10 + 1);
			temp.calculateAverage();
			temp.calculateMedian();
		}
		else if (action == 1)
			cin >> temp;
		group.push_back(move(temp));
		if (!amountStudKnown)
		{
			cout << "1 - ivesti dar vieno studento duomenis; 0 - baigti ivedima. " << endl;
			if (NumberCheck(0, 1) == 0)
				break;
		}
	}
}

/** Function that sorts the students by name, surname or final mark. */
template <typename Container>
double Sort(Container &group, int &markAction)
{
	cout << "Pasirinkite rezultatu isvedimo metoda: " << endl;
	cout << "1 - gauti vidurkius; 2 - gauti medianas. " << endl;
	markAction = NumberCheck(1, 2);
	cout << "Pairinkite rezultatu rusiavimo metoda: " << endl;
	cout << "1 - rusiuoti pagal varda (A-Z); 2 - rusiuoti pagal pavarde (A-Z); 3 - rusiuoti pagal galutini pazymi." << endl;
	int sortAction = NumberCheck(1, 3);

	Timer sortTime;
	auto compare = [&](const Student &a, const Student &b)
	{
		if (sortAction == 1)
			return a.getName() < b.getName();
		if (sortAction == 2)
			return a.getSurname() < b.getSurname();
		if (sortAction == 3)
			return (markAction == 1) ? (a.getAverage() < b.getAverage()) : (a.getMedian() < b.getMedian());
		return false;
	};
	if constexpr (std::is_same_v<Container, std::vector<Student>> || std::is_same_v<Container, deque<Student>> || std::is_same_v<Container, Vector<Student>>)
	{
		sort(group.begin(), group.end(), compare);
	}
	else if constexpr (std::is_same_v<Container, list<Student>>)
	{
		group.sort(compare);
	}
	return sortTime.elapsed();
}

/** Function that outputs the results to the console or a file. */
template <typename Container>
void Output(Container &group, ostream &out, int markAction)
{
	Timer outputTime;
	out << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
	if (markAction == 1)
		out << setw(20) << "Galutinis (Vid.)" << endl;
	else if (markAction == 2)
		out << setw(20) << "Galutinis (Med.)" << endl;
	out << "------------------------------------------------------------" << endl;
	for (auto &final : group)
	{
		out << left << setw(20) << final.getSurname() << setw(20) << final.getName();
		if (markAction == 1)
			out << setw(20) << fixed << setprecision(2) << final.getAverage() << endl;
		else if (markAction == 2)
			out << setw(20) << fixed << setprecision(2) << final.getMedian() << endl;
	}
	globalTime += outputTime.elapsed();
	cout << " * Rezultatu isvedimas uztruko: " << outputTime.elapsed() << " sekundziu. " << endl;
}

/** Function that sorts students into two groups - those who passed and those who failed. */
template <typename Container>
void SeparateStudents(Container &group, Container &failed)
{
	Timer separationTime;
    Container passed;
    for (const auto &student : group)
    {
        if (student.getAverage() < 5)
            failed.push_back(student);
        else
            passed.push_back(student);
    }
	group.clear();
	for (auto& s : passed)
		group.push_back(std::move(s));

	cout << " * Studentu skirstymas i 2 kategorijas uztruko: " << separationTime.elapsed() << " sekundziu. " << endl;
	globalTime += separationTime.elapsed();
}

/** Function that outputs the sorted students to two files. */
template <typename Container>
void OutputSeparated(Container &group, Container &failed)
{
	int markAction;
	double sortTime1 = Sort(group, markAction);
	ofstream passedOut("kietiakai.txt");
	Timer passedTime;
	Output(group, passedOut, markAction);
	double outTime1 = passedTime.elapsed();
	passedOut.close();
	cout << "Kietiakai surasyti i faila: kietiakai.txt." << endl;
	double sortTime2 = Sort(failed, markAction);
	cout << " * Studentu rusiavimas uztruko: " << sortTime1 + sortTime2 << " sekundziu. " << endl;
	globalTime += sortTime1 + sortTime2;
	ofstream failedOut("vargsiukai.txt");
	Timer failedTime;
	Output(failed, failedOut, markAction);
	double outTime2 = failedTime.elapsed();
	failedOut.close();
	cout << "Vargsiukai surasyti i faila: vargsiukai.txt." << endl;
	cout << " * Rezultatu isvedimas i 2 failus uztruko: " << outTime1 + outTime2 << " sekundziu. " << endl;
}

/** Function that generates data and writes it to a file. */
template <typename Container>
void GenerateFile(Container &group)
{
	cout << "Iveskite failo pavadinima, i kuri bus irasyti duomenys: " << endl;
	string fout;
	cin >> fout;
	cout << "Iveskite studentu skaiciu, kuriu informacija norite sugeneruoti: " << endl;
	int amountStud = NumberCheck(1, maxStud);
	Timer generateTime;
	int amountMarks = rand() % 11 + 10;
	for (int i = 1; i <= amountStud; i++)
	{
		Student temp;
		temp.setName("VardasNr" + std::to_string(i));
		temp.setSurname("PavardeNr" + std::to_string(i));
		for (int j = 0; j < amountMarks; j++)
			temp.addMark((rand() % 10 + 1));
		temp.setExam(rand() % 10 + 1);
		group.push_back(move(temp));
	}
	ofstream out(fout);
	out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
	for (int i = 1; i <= amountMarks; i++)
		out << left << setw(10) << ("ND" + std::to_string(i));
	out << setw(10) << "Egz." << endl;
	for (auto &final : group)
	{
		out << left << setw(20) << final.getName() << setw(20) << final.getSurname();
		for (auto mark : final.getMarks())
			out << left << setw(10) << mark;
		out << setw(10) << final.getExam() << endl;
	}
	out.close();
	cout << "Duomenys buvo sekmingai sukurti faile: " << fout << endl;
	cout << " * Duomenu generavimas uztruko: " << generateTime.elapsed() << " sekundziu. " << endl;
	globalTime += generateTime.elapsed();
}