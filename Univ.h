#pragma once
#include <iostream>
#include <math.h>
using namespace std;

struct STUDENT {
char name[64];
char address[64];
int id;
double gpa;
STUDENT* next_student;
};

class UNIVERSITY {
private:
	STUDENT* start;
	char* university_name;
	int count; 
	STUDENT* create(char name[], char add[], int id, double gpa);
	void add(STUDENT* s);
public:
	UNIVERSITY() {
		university_name = new char[20];
		university_name = NULL;
		count = 0;
	}

	UNIVERSITY(const UNIVERSITY& UNI);
	char* set_name(char n[20]);
	friend UNIVERSITY operator +(UNIVERSITY& O1, STUDENT& O2);
	UNIVERSITY& operator=(const UNIVERSITY& UNI);
	friend void operator<< (ostream& out, const UNIVERSITY n);
	friend void operator>> (istream& in, const UNIVERSITY n);
	double REC_AVG();
	~UNIVERSITY();
};

