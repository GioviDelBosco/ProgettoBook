//headere file
using namespace std;
class Book{
    public:
    Book(string isbn,string titolo,string nome,string cognome,bool disponibile); 
    void setIsbn();
    string getIsbn();
    void setTitolo();
    string getTitolo();
    void setNome();
    string getNome();
    void setCognome();
    string getCognome();
    void setDisponibile();
    bool getDisponibile();

    private:
    string isbn;
    string titolo;
    string nome;
    string cognome;
    bool disponibile;
};

//per copyright

class Date{
    /*enum class Month
    {
        jan=1,feb,mar,apr,may,jun,jul,aug,sept,oct,nov,dec
    }*/ 
    public:
    Date(int y, int m, int d);
    void setData();
    void getData();
    void StampaData();

    private:
    int year;
    int month;
    int day;
};