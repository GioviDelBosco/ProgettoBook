//Progetto Book
/*
Gruppo: BGM
Membri: Mattia Colapietro, Giuseppe Santoro, Giovanni Sgaravatto

*/

//file.cpp Date
//CAMBIA NOME FILE
#include<iostream>
#include<string>
#include "date.h"

using namespace std;
   

    Date::Date(){
        day=1;
        month=1;
        year=2000;
    };

    void Date::setData(int d,int m,int y)

    {
        day=d;
        month=m;
        year=y;
    }
    
    string Date::getData(){
            return to_string(day)+"-"+to_string(month)+"-"+to_string(year);
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
        cout<<"Data non valida\n";
        return false;
    }
    else if(month<1 || month>12){  
        cout<<"Data non valida\n";     
        return false;
        
    }
    if(check_bisestile(year) == true) //è bisestile
    {
        if(month==2)
        {
            if(day<1 || day>29){
                cout<<"Data non valida\n";
                return false;
            }
            
        }
    }
    else{
        if(month==4 || month==6 || month==9 || month==11){
            if(day<1 || day>30){
                cout<<"Data non valida\n";
                return false;
            }   
        }
        else if(day<1 || day>31){
            cout<<"Data non valida\n";
            return false;
        }
        else if(month==2 && day>28){
            cout<<"Data non valida\n";
            return false;
        }
    }
    return true;
}
ostream& operator<<(ostream& os, Date datina){
    os<< "Data copyright: "<< datina.getData()<< "\n";
        return os;
} 