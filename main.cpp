//Progetto Book
/*
Gruppo: BGM
Membri: Mattia Colapietro, Giuseppe Santoro, Giovanni Sgaravatto

*/

#include <iostream>
#include <vector>
#include <string>
#include "date.h"
#include "book.h"

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

    vector<Book> shelf (10);
    vector<Date> date (10);
    vector<Book> loan (10); // libro prestito

    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");
    cout<<"\n";
    cout<<my_favourite_book<<"\n";

    do
    {
        int scelta;
        cout<<"========== Benvenuti alla Biblioteca BGM ==========\n"<<endl;
        cout << "Cosa vuoi fare?\n1-inserire un libro\n2-visualizza la libreria\n3-prendi in prestito un libro\n4-Restituire libro\n0-uscire\n";
        cout << "\n";
        cout<<"===================================================\n"<<endl;
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
            
            cout << "Inserisci titolo: ";
            cin.ignore();
            getline(cin, titolo);
            cout << "Inserisci nome: ";
            getline(cin, nome);
            cout << "Inserisci cognome: ";
            getline(cin, cognome); 
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
                cout << "========== LIBRO "<<(i+1)<<" ==========\n"<<"\n";
                cout << shelf[i] << "\n";
                cout << date[i] << "\n";
            }
        }
        break;
        case 3:
        {
            if(shelf.size()==10){
                cout<<"Nessun libro presente in biblioteca!\n"<<"\n";
            }
            else{
                string cercaLibro;
                cout << "Che libro vuoi prendere in prestito? (inserisci isbn)\n";
                cin >> cercaLibro;
            for (int i = 0; i < shelf.size(); i++)
            {
                if (cercaLibro == shelf[i].getIsbn())
                {
                    Book::prestitoRestituzione(shelf[i]); 
                    if(shelf[i].getDisponibile()==true){
                        loan.push_back(shelf[i]);
                        shelf.erase(shelf.begin() + i);
                        cout<<"Libro prestato\n"<<endl;
                    }
                    else{
                        cout<<"Libro non disponibile\n"<<endl;
                    }
                    break;
                }
            }
            }
        }//restituzione libro 
        break;
        case 4:{
            string restituisciLib;
            cout << "Che libro vuoi restituire? (inserisci isbn)\n";
            cin >> restituisciLib;
            for (int i = 0; i < loan.size(); i++)
            if(restituisciLib == loan[i].getIsbn()){
                shelf.push_back(loan[i]);
                loan.erase(loan.begin()+i);
                cout<<"Libro ritirato\n"<<endl;
            }
            
        }break;

        case 0:
        {
            cout << "Programma terminato!\n";
            cout<<"Grazie e buona giornata!\n";
            continua = false;
        }
        break;
        }
    } while (continua == true);

    return 0;
    
}

//disponibile false => libreria vuota