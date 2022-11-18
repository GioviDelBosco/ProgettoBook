#include <iostream>
#include <string>
 //yo sgara arrivo  pono pono
//headere file
using namespace std;
class Date{
    /*enum class Month
    {
        jan=1,feb,mar,apr,may,jun,jul,aug,sept,oct,nov,dec
    }*/ 
    public:
    Date(int y, int m, int d);
    void setData(int day, int month, int year);
    string getData();
    void StampaData();
    bool check_data(int day, int month,int year);
    friend ostream& operator<<(ostream& os, const Date& d);

    private:
    int year;
    int month;
    int day;
}; 
 
class Book{
    public:
    Book(string isbn,string titolo,string nome,string cognome,bool disponibile); 
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
    void prestitoRestituzione(Book i);
    bool check_isbn(string& isbn_number);
    friend ostream& operator<<(ostream& os, Book& lib);

    private:
    string isbn;
    string titolo;
    string nome;
    string cognome;
    bool disponibile;
};

//per copyright