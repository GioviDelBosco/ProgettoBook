//file classe
#include <iostream>
#include <string>
#include "lib.h"
using namespace std; 


//COSTRUTTORE
Book::Book(string nome,string cognome,string titolo,string isbn); 
: cod(isbn), tit(titolo), name(nome), surname(cognome);
    //function member 

    //GET
    string Book::getIsbn(){
        cout<<"Codice ISBN: "<<cod;
    }
    string Book::getNome()
    {
        cout<<name; 
    }
    string Book::getCognome()
    {
        cout<<surname<<"\n";
    }
    string Book::getTitolo(){
        string titolo;
        cout<<"Titolo del libro e' "<<titolo;
    }

    bool Book::getDisponibile(){

        return disponibile;
    }

    //SET
    void Book::setIsbn(string i){
        string i;
        cout<<"Inserire codice ISBN: ";
        cin>>i;
        cod=i;
    }

    void Book::setTitolo(){
        string t;
        cout<<"Inserire titolo del libbro: ";
        cin>>t;
        tit=t;
    }

    void Book::setNome(){
        string n;
        cout<<"Inserire nome autore: ";
        cin>>n;
        name=n;
    }

    void Book::setCognome(){
        string c;
        cout<<"Inserire cognome autore: ";
        cin>>c;
        surname=c;
    }

    //setDate?????

    void Book::setDisponibile(bool d){
        disponibile=d;
    }

    void Book::prestitoRestituzione(string isbn){
        string scelta;
        if(isbn.getDisponibile()==true){
            do{
                cout<<"Il libro e' disponibile, vuoi prenderlo? (y=si, n=no)";
                cin>>scelta;
            }while (scelta != 'y' || scelta != 'n');
            //scelgo se prendere il libro oppure no
            if(scelta=='y'){
                cout<<"Hai preso il libro!";
                disponibile=false;
            }else{
                cout<<"non hai preso il libro";
            }
        }else{
            do{
                cout<<"Hai il libro, vuoi restituirlo? (y=si, n=no)";
                cin>>scelta;
            }while (scelta != 'y' || scelta != 'n');
            //Scelgo se restituire il libro o no
            if(scelta=='y'){
                cout<<"Hai restituito il libro!";
                disponibile=true;
            }else{
                cout<<"non hai restituito il libro";
            }
        }
    }

    //OVERLOAD
    bool Book::operator==(Book lib1,Book lib2){
        if(strcmp(lib1.getIsbn(),lib2.getIsbn())==0){
            //==0 -> string uguale
            return true;
        }else{
            return false;
        }
    }

    bool Book::operator !=(Book lib1,Book lib2){
        if(strcmp(lib1.getIsbn(),lib2.getIsbn())!=0){
            //!=0 -> string diverso
            return true;
        }else{
            return false;
        }
    }

    void Book::operator<<(Book lib1){
        Book lib1;
        cout<< "Titolo: "<< lib1.getTitolo()<< "\n";
        cout<< "Nome: "<<lib1.getNome();
        cout<< lib1.getCognome()<< "\n";
        cout<< "Codice libro: "<<lib1.getIsbn()<< "\n";
        cout<< "Data copyright: "<<lib1.getData()<< "\n";
    }



Date::Date (int yy, int mm, int dd); : y (yy), m(mm), d(dd);   


void Date::setData()
{
    int yr;
    cout<<"Inserire anno di coyright:";
    cin>>yr;
    y=yr;
    int m=month;
    cout<<"Inserire mese: ";
    cin>>month;
    m=month;
    int day;
    cout<<"Inserire giorno: ";
    cin>>day;
    d=day;
}
void Date::getData()
{
    cout<<"L'anno del copyright ?: "<<y<<"/"<<mm<<"/"<<day<<"\n";
    //check mese 
}

bool Date::check_isbn(String isbn_number){ //controlla che la classe sia nel formato n-n-n-x
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