#include <iostream>
#include <string>
#include "lib.h"
#include "header.cpp"
#include <vector>

using namespace std;

// main
int main()
{
    string isbn;
    string titolo;
    string nome;
    string cognome;
    bool disponibile=true; 
   
    vector<Book> shelf;
   
    cout << "Inserisci i dati del libro per inserirlo nella libreria\n";
    //Book(string isbn, string titolo, string nome, string cognome, bool disponibile);
    cout<<"inserisci l'isbn\n";
    cin>>isbn;
    cout<<"inserisci titolo\n";
    cin>>titolo;
    cout<<"inserisci nome\n";
    cin>>nome;
    cout<<"inserisci cognome\n";
    cin>>cognome;
    cout<<"\n";
    //Crea un oggetto Book inserendo i dati :D
    Book *libro=new Book(isbn,titolo,nome,cognome,true);

    cout<< *libro << std::endl;
    //shelf.push_back();

    return 0;
}