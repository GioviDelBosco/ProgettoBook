//Progetto Book
/*
Gruppo: BGM
Membri: Mattia Colapietro, Giuseppe Santoro, Giovanni Sgaravatto

*/

//file.h Book
#ifndef LIBRO
#define LIBRO

#include<iostream>
#include<string>

using namespace std;

class Book
{
    
public:
    
    Book();
    Book(string nome, string cognome, string titolo, string isbn);
    Book(string isbn, string titolo, string nome, string cognome, bool disponibile);
    
    
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
    friend bool operator==(Book lib1, Book lib2);
    friend bool operator!=(Book lib1,Book lib2);
    friend ostream& operator<<(ostream& os, Book lib1);
    

private:
    string isbn;
    string titolo;
    string nome;
    string cognome;
    bool disponibile;
};

bool operator==(Book lib1, Book lib2);
bool operator !=(Book lib1,Book lib2);
ostream& operator<<(ostream& os, Book lib1);
#endif