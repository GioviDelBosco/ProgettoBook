#include <iostream>
#include <string>

using namespace std;

//file classe
class Book{
    public:
    //codice del libro
    string isbn; 
    //titolo  
    string titolo;
    //autore
    string nome;   
    string cognome;  
    //disponibilità
    bool disponibile = true;  //se true=dispoinibile, false = in prestito
    
    Date data();
    class Invalid();
    
    //COSTRUTTORE
    Book(string isbn,string titolo,string nome,string cognome,bool disponibile); 


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

    void prestitoRestituzione(){
        if(disponibile==true){
            string scelta;
            do{
            cout<<"Il libro è disponibile, vuoi prenderlo? (y=si, n=no)"
            cin>>scelta;
            }while (scelta != 'y' )
            disponibile=false;
        }else{
            cout<<
        }
    }

    private:   
    bool is_valid();        //utilizzabile da tutti i costruttori. correttezza dello stato dellì costruttore
};
/*Date::Date(int yy, int mm, int dd)
: y (yy), m(mm), d(dd)*/


class Date{
    public:
    Date (int yy, Month mm, int dd); : y (yy), m(mm), d(dd);   
    if(!is_valid()) {throw Inavlid();}
    
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
bool check_isbn(string str){ //controlla che la classe sia nel formato n-n-n-x
    if(str.empty()){
        cout<<"Non hai inserito nessun codice\n";
        return false;
    }
    else if(str.length()!=13){
        cout<<"il codice ISBN deve avere il seguente formato nnn-nnn-nnnn-x\n";
        }
    //substring
    //controllo 3a3 per gli interi
    int nnn = s.find("-");
    string sub = s.substr(0,nnn);
    if(sub)
        
    }
    
    
bool Date::is_valid()
{
    if()
}