//headere file
class Book{
    public:
    Book(string isbn,string titolo,string nome,string cognome,bool disponibile); 
    void setIsbn();
    void getIsbn();
    void setTitolo();
    void getTitolo();
    void setNome();
    void getNome();
    void setCognome();
    void getCognome();
    void setDisponibile();
    void getDisponibile();

    private:
    string isbn;
    string Titolo;
    string Nome;
    string Cognome;
    bool disponibile;
}

//per copyright

class Date{ 
    public:
    Date(int y, Month m, int d);
    void setData();
    void getData();
    void StampaData();

    private:
    int y;
    int d;
}