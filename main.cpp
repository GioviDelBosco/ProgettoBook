#include <iostream>
#include <vector>
#include <string>
#include "date.h"
#include "book.h"
#include "header.cpp"

using namespace std;

//per compilare g++ -std=c++0x -o test main.cpp book.cpp date.cpp 
//spiegazione qui https://stackoverflow.com/a/32062142

// main
int main()
{
    string isbn;
    string titolo;
    string nome;
    string cognome;
    bool disponibile = true;

    vector<Book> shelf;

    cout << "Inserisci i dati del libro per inserirlo nella libreria\n";
    cout << "inserisci l'isbn\n";
    cin >> isbn;
    cout << "inserisci titolo\n";
    cin >> titolo;
    cout << "inserisci nome\n";
    cin >> nome;
    cout << "inserisci cognome\n";
    cin >> cognome;
    cout << "\n";
    // Crea un oggetto Book inserendo i dati :D
    Book *libro = new Book(isbn, titolo, nome, cognome, true);
    Date *data=new Date(5,10,2002);
    // Inserimento date
    cout << *libro << endl;
    cout << *data<<endl;

    return 0;
}