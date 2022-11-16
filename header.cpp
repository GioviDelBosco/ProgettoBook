//file classe
#include <iostream>
#include <string>
#include "lib.h"
using namespace std; 
    //function member BOOK
    //GET
    string Book::getIsbn(){
        return isbn;
    }
    string Book::getNome()
    {
        return nome;
    }
    string Book::getCognome()
    {
        return cognome;
    }
    string Book::getTitolo(){
        return titolo;
    }

    bool Book::getDisponibile(){
        return disponibile;
    }

    //SET
    void Book::setIsbn(string i){
        isbn=i;
    }

    void Book::setTitolo(string t){
        titolo=t;
    }

    void Book::setNome(string n){
        nome=n;
    }

    void Book::setCognome(string c){
        cognome=c;
    }

    //setDate?????

    void Book::setDisponibile(bool d){
        disponibile=d;
    }

    void Book::prestitoRestituzione(Book i){
        string scelta;
        Book isbn=i;
        if(isbn.getDisponibile()==true){
            do{
                cout<<"Il libro e' disponibile, vuoi prenderlo? (y=si, n=no)";
                cin>>scelta;
            }while (scelta != "y" || scelta != "n");
            //scelgo se prendere il libro oppure no
            if(scelta=="y"){
                cout<<"Hai preso il libro!";
                disponibile=false;
            }else{
                cout<<"non hai preso il libro";
            }
        }else{
            do{
                cout<<"Hai il libro, vuoi restituirlo? (y=si, n=no)";
                cin>>scelta;
            }while (scelta != "y" || scelta != "n");
            //Scelgo se restituire il libro o no
            if(scelta=="y"){
                cout<<"Hai restituito il libro!";
                disponibile=true;
            }else{
                cout<<"non hai restituito il libro";
            }
        }
    }

    //OVERLOAD
    bool operator==(Book lib1, Book lib2){
        if(lib1.getIsbn()==lib2.getIsbn()){
            //==0 -> string uguale
            return true;
        }
            return false;
    }

    bool operator !=(Book lib1,Book lib2){
        if(lib1.getIsbn()!=lib2.getIsbn()){
            //!=0 -> string diverso
            return true;
        }else{
            return false;
        }
    }

    ostream& operator<<(ostream& os, Book lib1, Date datina){   
        os<< "Titolo: "<< lib1.getTitolo()<< "\n";
        os<< "Nome: "<<lib1.getNome();
        os<< lib1.getCognome()<< "\n";
        os<< "Codice libro: "<<lib1.getIsbn()<< "\n";
        os<< "Data copyright: "<<datina.getData()<< "\n";
        return os;
    }


    void Date::setData(int y, int m, int d)
    {
        year=y;
        month=m;
        day=d;    
    }
    
    string Date::getData()
    {
        return "L'anno del copyright ?: "<< year <<"/"<< month <<"/"<< day;
        //check mese 
    }

    bool Book::check_isbn(string isbn_number){ //controlla che la classe sia nel formato n-n-n-x
        if(isbn_number.empty()){
            cout<<"Non hai inserito nessun codice\n";
            return false;
        }
        int n = isbn_number.length();
        if (n != 10){
            return false;
        }
            
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            int value = isbn_number[i] - '0';

            if (0 > value || 9 < value){
                return false;
            }
            sum += (value * (10 - i));
        }
        char last_val = isbn_number[9];
        if (last_val != 'X' && (last_val < '0' || last_val > '9')){
            return false;
        }
            
        sum += ((last_val == 'X') ? 10 : (last_val - '0'));
        return (sum % 11 == 0);     
    }