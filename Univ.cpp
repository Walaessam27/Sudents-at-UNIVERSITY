#define _CRT_SECURE_NO_WARNINGS
#include "Univ.h"
#include<fstream>

STUDENT* UNIVERSITY::create(char n[], char add[], int id, double gpa)
{
	STUDENT* p;
	p = new STUDENT;
	strcpy(p->name, n);
	strcpy(p->address, add);
	p->id = id;
	p->gpa = gpa;
	p->next_student = NULL;
	return p;
}

void UNIVERSITY::add(STUDENT* s)
{
	STUDENT* p1, * p2;
	if (start == NULL)
	{
		start = s;
		return;
	}
	if (s->id < start->id)
	{
		s->next_student = start;
		start = s;
		return;
	}
	p1 = p2 = start;
	while (p2 != NULL)
	{
		if (s->id < p2->id)
		{
			s->next_student = p2;
			p1->next_student = s;
			return;
		}
		else
		{
			p1 = p2;
			p2 = p2->next_student;
		}
	}
	s->next_student = p2;
	p1->next_student = s;	
}

UNIVERSITY::UNIVERSITY(const UNIVERSITY& UNI)
{
	start = NULL;
	if (UNI.start == NULL)
		return;
	STUDENT* s;
	s = UNI.start;
	STUDENT* p;
	STUDENT* last = NULL;
	while (s != NULL)
	{
		p = new STUDENT;
		memcpy(p, s, sizeof(STUDENT)); 
		p->next_student = NULL;
		s = s->next_student;
		if (start == NULL)
		{
			start = p;
			last = start;
		}
		else
		{
			last->next_student = p;
			last = last->next_student;
		}
	}


}

char* UNIVERSITY::set_name(char n[20])
{
	UNIVERSITY* UNI;
	UNI = new UNIVERSITY;
	UNI->university_name = n;
	return UNI->university_name;
}

UNIVERSITY& UNIVERSITY::operator=(const UNIVERSITY& UNI)
{
	university_name = UNI.university_name;

	strcpy(university_name, UNI.university_name);
	count = UNI.count; 
	STUDENT* s;
	for (int i = 0;i <= UNI.count;i++)
	{
		s = new STUDENT;
		memcpy(s, UNI.start, sizeof (STUDENT));
		s = s->next_student;
	}

	return *this;
}

double UNIVERSITY::REC_AVG()
{
	UNIVERSITY UNI;
	double sum = 0;
	if (start == NULL)
		return 0.0;

	for (int i = 0; i <= UNI.count;i++)
	{
		STUDENT* s;
		s = new STUDENT;
		s = start;
		sum = sum + s->gpa;

	}
	return sum/(double)count;
}

UNIVERSITY::~UNIVERSITY()
{
	STUDENT* p;
	while (start != NULL)
	{
		p = start;
		start = start->next_student;
		delete p;
	}
}

UNIVERSITY operator+(UNIVERSITY& O1, STUDENT& O2)
{
	if (O1.start == NULL)
		return O1;
	else
		O1.add(&O2);

	return O1;
}

void operator<<(ostream& out, const UNIVERSITY n)
{
	char file[30] = {};
	cout << "Please enter the name of output file.";
	cin >> file;
	ofstream stud_out(file, ios::out);
	out << "the name of the University is " << n.university_name;
	out << "the number of student in it is " << n.count;
	STUDENT* p;
	for (int i = 0;i <= n.count;i++)
	{
		p = new STUDENT;
		p = n.start;
		out << p->id;
		out << p->name;
		out << p->address;
		out << p->gpa;
	}

}

void operator>>(istream& in, const UNIVERSITY n)
{
	char file[30] = {};
	cout << "Please enter the name of input file?";
	cin >> file;
	ifstream stud_in(file, ios::in);
	in >> n.university_name;
	STUDENT* p;
	for (int i = 0;i <= n.count;i++)
	{
		p = new STUDENT;
		p = n.start;
		in >> p->id;
		in >> p->name;
		in >> p->address;
		in >> p->gpa;
	}

}
