#include <iostream>
#include <string>

using namespace std;

//file classe
class Book{
    public:
    string isbn;  //codice del libro
    string titolo;
    string nome;
    string cognome;
    Date data();
    class Invalid();
    bool disponibile = true;  //se true=dispoinibile, false = in prestito

    //function member 

    //GET
    string getIsbn(){
        return isbn;
    }

    string getTitolo(){
        return titolo;
    }
    //getDate??????

    bool getDisponibile(){
        return disponibile;
    }

    //SET
    void setIsbn(string i){
        isbn=i;
    }

    void setTitolo(string t){
        titolo=t;
    }

    void setNome(string n){
        nome=n;
    }

    void setCognome(string c){
        cognome=c;
    }

    //setDate?????

    void setDisponibile(bool d){
        disponibile=d;
    }

    private:   
    bool is_valid();        //utilizzabile da tutti i costruttori. correttezza dello stato dellì costruttore
};
/*Date::Date(int yy, int mm, int dd)
: y (yy), m(mm), d(dd)*/


class Date{
    public:
    Date (int yy, Month mm, int dd); : y (yy), m(mm), d(dd);   
    //anno inizio<<year<<2022;    1<<day<<31 così copriamo tutti i giorni dei vari mesi  
    int year();
    int day();

    private:
    int y, m, d; // year, month, day
    
}
enum class Month
{
    jan=1,feb,mar,apr,may,jun,jul,aug,sept,oct,nov,dec   //avendo messo 1 come dato di partenza, incremento automatico da 1. 
                                                         //se non lo imposto parte da 0
}
bool check_isbn(String str){ //controlla che la classe sia nel formato n-n-n-x
    if(str.empty()){
        cout<<"Non hai inserito nessun codice\n";
        return false;
    }
    else{
        if(str.length()!=10){
        cout<<"il codice ISBN deve avere il seguente formato\n";
        }
    }
    
    //substring
    
}