//file.h classe Date
//CAMBIA NOME FILE
#ifndef DATA
#define DATA
#include<iostream>
#include <string>


using namespace std;
class Date{

    public:
    Date(int day, int month , int year):  day(day), month(month), year(year){}
    //void setData(int day, int month, int year);
    void setData(int d,int m,int y);
    string getData();
    //void StampaData();
    static bool check_data(int day, int month,int year);

    private:
    int day;
    int month;
    int year;
}; 
#endif