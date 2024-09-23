#include"Univ.h"

#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    UNIVERSITY U1;
    char f[20] = "file";
    char n[20] = "ss";
    cout << U1.set_name(n);
    ifstream input_f1(f);
    input_f1 >> U1;
    cout << "Average: " << U1.REC_AVG();

    
  
}

    /*
    ifstream input_f1("univ_1.txt");
    ifstream input_f2("univ_2.txt");
    ifstream input_f3("univ_3.txt");
    UNIVERSITY U1;
    UNIVERSITY U2;
    UNIVERSITY U3;
    input_f1 >> U1;
    input_f2 >> U2;
    input_f3 >> U3;
    {
        UNIVERSITY TEST(U1);
        UNIVERSITY TEST2;
        TEST2 = TEST1;
        cout << TEST1; // (1)
        STUDENT S;
        strcpy(S.name, "testName");
        strcpy(S.address, "testAddress");
        S.gpa = 3.4;
        S.id = 121515;
        TEST2 = TEST2 + S;
        cout << TEST2; // (2)
    }
    cout << U3; // (3)
    cout << "Average: " << U3.Rec_AVG(); // (4)
    return 0;
    */
