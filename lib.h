#include <iostream>
#include <string>

//headere file
using namespace std;
class Date{
    /*enum class Month
    {
        jan=1,feb,mar,apr,may,jun,jul,aug,sept,oct,nov,dec
    }*/ 
    public:
    Date(int y, int m, int d);
    void setData(int year, int month, int day);
    string getData();
    void StampaData();

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
    bool check_isbn();
    //friend ostream& operator<<(ostream& os, const Book& lib1,const Date& datina);

    private:
    string isbn;
    string titolo;
    string nome;
    string cognome;
    bool disponibile;
};

//per copyright

