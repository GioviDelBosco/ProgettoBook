//file.cpp Date
//CAMBIA NOME FILE
#include<iostream>
#include<string>
#include "Date.h"

using namespace std;


Date::Date(int d,int m,int y)
    {
        day=d;
        month=m;
        year=y;
    }
    void Date::setData()
    {
        int d,m,y;
        cout<<"Inserire giorno: ";
        cin>>d;
        day=d;
        cout<<"Inserire mese: ";
        cin>>m;
        month=m;
        cout<<"Inserire anno: ";
        cin>>y;
        year=y;
    }
    
    //risolvere sto schifo
    string Date::getData(){
            string s="";
            s=to_string(day);
            return s;
    }

    bool check_bisestile(int year){
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0){
                return true;
            }
            else{
                return true;
            }
        }
        return true;    
    }
    else{
        return false;
        }     
    }


bool Date::check_data(int day,int month,int year){
    if(year<1650 || year>2022)
    {
        return false;
    }
    else if(month<1 || month>12){       
        return false;
        
    }
    if(check_bisestile(year) == true) //è bisestile
    {
        if(month==2)
        {
            if(day<1 || day>29)
            return false;
        }
    }
    else{
        if(month==4 || month==6 || month==9 || month==11){
            if(day<1 || day>30){
                return false;
            }   
        }
        else if(day<1 || day>31){
            return false;
        }
        else if(month==2 && day>28){
        return false;
        }
    }
    return true;
}