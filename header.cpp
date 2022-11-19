//file classe

#include <iostream>
#include <string>
#include "book.h"
#include "date.h"

using namespace std; 
//OVERLOAD
bool operator==(Book lib1, Book lib2){
    if(lib1.getIsbn()==lib2.getIsbn()){
        return true;
    }
    return false;
}

bool operator !=(Book lib1,Book lib2){
    if(lib1.getIsbn()!=lib2.getIsbn()){
        return true;
    }
    else{
        return false;
    }
}

ostream& operator<<(ostream& os, Book lib1){ //const Date& datina)
    os<< "Titolo: "<< lib1.getTitolo()<< "\n"<< "Autore: "<<lib1.getNome()<<" "<< lib1.getCognome()<< "\n"<< "Codice libro: "<<lib1.getIsbn()<< "\n";
        return os;
}    

ostream& operator<<(ostream& os, Date datina){ //const Date& datina)
    os<< "Data copyright: "<< datina.getData()<< "\n";
        return os;
}  