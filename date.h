//file.h classe Date
//CAMBIA NOME FILE
#ifndef DATA
#define DATA
#include<iostream>
#include <string>


using namespace std;
class Date{

    public:
    Date(int d=0, int m=0, int y=0);
    //void setData(int day, int month, int year);
    void setData();
    string getData();
    //void StampaData();
    bool check_data(int day, int month,int year);

    private:
    int day;
    int month;
    int year;
}; 
#endif