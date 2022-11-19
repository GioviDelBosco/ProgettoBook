#include <iostream>
#include <vector>
#include <string>
#include "date.h"
#include "book.h"
#include "header.cpp"

using namespace std;

// per compilare g++ -std=c++0x -o test main.cpp book.cpp date.cpp
// spiegazione qui https://stackoverflow.com/a/32062142

// main
int main()
{
    string isbn;
    string titolo;
    string nome;
    string cognome;
    int day, month, year;
    bool disponibile = true;

    bool continua = true;

    vector<Book> shelf;
    vector<Date> date;
    vector<Book> loan; // libro prestito

    do
    {
        int scelta;
        cout << "Cosa vuoi fare?\n1-inserire un libro\n2-visualizza la libreria\n3-prendi in prestito un libro\n0-uscire\n";
        cout << "\n";
        cin >> scelta;
        cout << "\n";
        switch (scelta)
        {
        case 1:
        {
            cout << "Inserisci i dati del libro per inserirlo nella libreria\n";
            do
            {
                cout << "Inserisci l'isbn (seguendo la sintassi nnn-nnn-nnn-x)\n";
                cin >> isbn;
            } while (Book::check_isbn(isbn) == false);

            cout << "Inserisci titolo\n";
            cin >> titolo;
            cout << "Inserisci nome\n";
            cin >> nome;
            cout << "Inserisci cognome\n";
            cin >> cognome;
            cout << "\n";
            // Crea un oggetto Book inserendo i dati :D
            Book *libro = new Book(isbn, titolo, nome, cognome, true);

            // Inserimento date
            do
            {
                cout << "Inserire data nel formato dd/mm/yy\n";
                cout << "Inserisci giorno:\n";
                cin >> day;
                cout << "Inserisci mese:\n";
                cin >> month;
                cout << "Inserisci anno:\n";
                cin >> year;
                cout << "\n";
            } while (Date::check_data(day, month, year) == false);

            Date *data = new Date(day, month, year);

            shelf.push_back(*libro);
            date.push_back(*data);

            cout << "Libro inserito correttamente!\n";
        }
        break;
        case 2:
        {
            for (int i = 0; i < shelf.size(); i++)
            {
                cout << shelf[i] << "\n";
                cout << date[i] << "\n";
            }
        }
        break;
        case 3:
        {
            string cercaLibro;
            cout << "Che libro vuoi prendere in prestito? (inserisci isbn)\n";
            cin >> cercaLibro;
            for (int i = 0; i < shelf.size(); i++)
            {
                if (cercaLibro == shelf[i].getIsbn())
                {
                    Book::prestitoRestituzione(shelf[i]);
                    if(shelf[i].getDisponibile()==false){
                        cout<<"ci sono!!\n";
                        loan.push_back(shelf[i]);
                        shelf.erase(shelf.begin() + i);
                    }
                    cout << "\n";
                    break;
                }
            }
        }
        break;
        case 0:
        {
            cout << "Uscito correttamente\n";
            continua = false;
        }
        break;
        }
    } while (continua == true);

    return 0;
}