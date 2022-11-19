//file.h Book
#ifndef LIBRO
#define LIBRO

#include<iostream>
#include<string>

using namespace std;

class Book
{
    
public:
    

    Book(string isbn, string titolo, string nome, string cognome, bool disponibile)
    :  isbn(isbn), titolo(titolo), nome(nome), cognome(cognome), disponibile(true){}
    void setIsbn(string i);
    string getIsbn();
    void setTitolo(string t);
    string getTitolo();
    void setNome(string n);
    string getNome();
    void setCognome(string c);
    string getCognome();
    void setDisponibile(bool d);
    bool getDisponibile();
    static void prestitoRestituzione(Book& i);
    static bool check_isbn(string isbn_number);
    

private:
    string isbn;
    string titolo;
    string nome;
    string cognome;
    bool disponibile;
};
#endif