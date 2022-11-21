//Progetto Book
/*
Gruppo: BGM
Membri: Mattia Colapietro, Giuseppe Santoro, Giovanni Sgaravatto

*/

// file.cpp book
#include <iostream>
#include <string>
#include "book.h"

using namespace std;
Book::Book()
{
    isbn = "000-000-000-a";
    nome = "";
    cognome = "";
    titolo = "";
    disponibile = true;
};
Book::Book(string isbn, string titolo, string nome, string cognome, bool disponibile)
{
    this->isbn = isbn;
    this->titolo = titolo;
    this->nome = nome;
    this->cognome = cognome;
    this->disponibile = true;
}

Book::Book(string nome, string cognome, string titolo, string isbn)
{
    this->nome = nome;
    this->cognome = cognome;
    this->titolo = titolo;
    this->isbn = isbn;
}

string Book::getIsbn()
{
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
string Book::getTitolo()
{
    return titolo;
}

bool Book::getDisponibile()
{
    return disponibile;
}

// SET
void Book::setIsbn(string i)
{
    isbn = i;
}

void Book::setTitolo(string t)
{
    titolo = t;
}

void Book::setNome(string n)
{
    nome = n;
}

void Book::setCognome(string c)
{
    cognome = c;
}

void Book::setDisponibile(bool d)
{
    disponibile = d;
}
void Book::prestitoRestituzione(Book &i) // libro non disponibile??
{
    string scelta = "";
    Book isbn = i;
    if (isbn.getDisponibile() == false)
    {
        cout << "Il libro non e' disponibile, vuoi restituirlo? (yes=si, no=no)\n";
        cin >> scelta;
        // scelgo se prendere il libro oppure no
        if (scelta == "yes")
        {
            cout << "Hai restituito il libro!\n";
            isbn.setDisponibile(true);
        }
        else if (scelta == "no")
        {
            cout << "non hai restituito il libro\n";
        }
        else
        {
            cout << "Commando sbagliato";
        }
    }
    else if (isbn.getDisponibile() == true)
    {
        cout << "Il libro e' disponibile, vuoi prenderlo? (yes=si, no=no)\n";
        cin >> scelta;
        if (scelta == "yes")
        {
            cout << "Hai preso il libro!\n";
            isbn.setDisponibile(false);
        }
        else if (scelta == "no")
        {
            cout << "non hai preso il libro\n";
        }
        else
        {
            cout << "Commando sbagliato";
        }
    }
}

bool Book::check_isbn(string isbn_number)
{ // controlla che la classe sia nel formato n-n-n-x
  // true is valid, false is NOT valid
    if (isbn_number.empty())
    {
        cout << "Non hai inserito nessun codice\n";
        return false;
    }
    int n = isbn_number.length();
    if (n != 13)
    {
        cout << "ISBN errato\n";
        return false;
    }

    for (int i = 0; i < 12; i++)
    {

        char value = isbn_number[i];
        if (i == 3 || i == 7 || i == 11)
        {
            if (value != '-')
            {
                cout << "ISBN errato\n";
                return false;
            }
        }
        else if (value < '0' || value > '9')
        {
            cout << "ISBN errato\n";
            return false;
        }
    }
    char last_val = isbn_number[12];
    if ((last_val < 'A' || last_val > 'Z') && (last_val < 'a' || last_val > 'z') && (last_val < '0' || last_val > '9'))
    {
        cout << "ISBN errato\n";
        return false;
    }

    return true;
}
bool operator==(Book lib1, Book lib2)
{
    if (lib1.getIsbn() == lib2.getIsbn())
    {
        return true;
    }
    return false;
}

bool operator!=(Book lib1, Book lib2)
{
    if (lib1.getIsbn() != lib2.getIsbn())
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream &operator<<(ostream &os, Book lib1)
{ 
    os << "Titolo: " << lib1.getTitolo() << "\n"
       << "Autore: " << lib1.getNome() << " " << lib1.getCognome() << "\n"
       << "Codice libro: " << lib1.getIsbn() << "\n";
    return os;
}