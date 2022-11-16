#include <iostream>
#include <string>
#include "lib.h"
#include "header.cpp"

using namespace std;


//main
int main()
{

    Book n;
    n.setNome();
    n.getNome();
    Book s;
    s.setCognome();
    s.getCognome();
    Book t;
    t.setTitolo();
    t.getTitolo();
    Book cod;
    cod.setIsbn();
    cod.getIsbn();

    return 0;
}