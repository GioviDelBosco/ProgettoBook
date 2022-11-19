//file.cpp book
#include<iostream>
#include<string>
#include "book.h"

using namespace std;

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