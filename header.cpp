// file classe
#include <iostream>
#include <string>
#include "lib.h"

using namespace std;
// function member BOOK
// GET
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
    return cognome; // bella sgara
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

// CheckDate
void Date::setData(int d, int m, int y)
{
    int year = y;
    int month = m;
    int day = d;
}
bool check_bisestile(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    return false;
}

bool Date::check_data(int day, int month, int year)
{
    if (year < 1650 || year > 2022)
    {
        return false;
    }
    else if (month < 1 || month > 12)
    {

        return false;
    }
    if (check_bisestile(year) == true) //? bisestile
    {
        if (month == 2)
        {
            if (day < 1 || day > 29)
                return false;
        }
    }
    else
    {
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day < 1 || day > 30)
                return false;
        }
        else if (day < 1 || day > 31)
        {
            return false;
        }
        else if (month == 2 && day > 28)
        {
            return false;
        }
    }
    return true;
}

void Book::setDisponibile(bool d)
{
    disponibile = d;
}

void Book::prestitoRestituzione(Book i)
{
    string scelta;
    Book isbn = i;
    if (isbn.getDisponibile() == true)
    {
        do
        {
            cout << "Il libro e' disponibile, vuoi prenderlo? (y=si, n=no)";
            cin >> scelta;
        } while (scelta != "y" || scelta != "n");
        // scelgo se prendere il libro oppure no
        if (scelta == "y")
        {
            cout << "Hai preso il libro!";
            disponibile = false;
        }
        else
        {
            cout << "non hai preso il libro";
        }
    }
    else
    {
        do
        {
            cout << "Hai il libro, vuoi restituirlo? (y=si, n=no)";
            cin >> scelta;
        } while (scelta != "y" || scelta != "n");
        // Scelgo se restituire il libro o no
        if (scelta == "y")
        {
            cout << "Hai restituito il libro!";
            disponibile = true;
        }
        else
        {
            cout << "non hai restituito il libro";
        }
    }
}

// OVERLOAD
bool operator==(Book lib1, Book lib2)
{
    if (lib1.getIsbn() == lib2.getIsbn())
    {
        //==0 -> string uguale
        return true;
    }
    return false;
}

bool operator!=(Book lib1, Book lib2)
{
    if (lib1.getIsbn() != lib2.getIsbn())
    {
        //!=0 -> string diverso
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream &os, Book lib1) // const Date& datina)
{
    os << "Titolo: " << lib1.getTitolo() << "\n"
       << "Nome: " << lib1.getNome() <<" "<< lib1.getCognome() << "\n"
       << "Codice libro: " << lib1.getIsbn() << "\n";
    // os<< "Data copyright: "<<datina.getData()<< "\n";
    return os;
}

bool Book::check_isbn(string &isbn_number)
{ // controlla che la classe sia nel formato n-n-n-x
  // true is valid, false is NOT valid
    if (isbn_number.empty())
    {
        cout << "Non hai inserito nessun codice\n";
        return false;
    }
    int n = isbn_number.length();
    if (n != 13)
        return false;

    for (int i = 0; i < 12; i++)
    {

        char value = isbn_number[i];
        if (i == 3 || i == 7 || i == 11)
        {
            if (value != '-')
                return false;
        }
        else if (value < '0' || value > '9')
        {
            return false;
        }
    }
    char last_val = isbn_number[12];
    if ((last_val < 'A' || last_val > 'Z') && (last_val < 'a' || last_val > 'z') && (last_val < '0' || last_val > '9'))

        return false;

    return true;
}