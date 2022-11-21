//Progetto Book
/*
Gruppo: BGM
Membri: Mattia Colapietro, Giuseppe Santoro, Giovanni Sgaravatto

*/

//file.h classe Date
//CAMBIA NOME FILE
#ifndef DATA
#define DATA
#include<iostream>
#include <string>


using namespace std;
class Date{

    public:
    Date();
    Date(int day, int month , int year):  day(day), month(month), year(year){}
    void setData(int d,int m,int y);
    string getData();
    static bool check_data(int day, int month,int year);
    friend ostream& operator<<(ostream& os, Date datina);

    private:
    int day;
    int month;
    int year;
}; 
ostream& operator<<(ostream& os, Date datina);
#endif