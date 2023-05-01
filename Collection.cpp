//
// Created by aluas on 25.03.2023.
//

#include "Collection.h"
#include<iostream>
using namespace std;
typedef int TElem;

Collection::Collection() {
    this->distinctelements = 0;
    this->capacity = 10;
    VectorDinamic<pair<TElem,int>> v(capacity);
    this->elements = v;
}

//in: TElem
//out: -
//desc: adauga un element in colectie
void Collection::add(TElem elem) {
    if(search(elem)){
        int ok = 1;
        for(int i = 0; i< this->distinctelements&&ok; i++)
            if(this->elements.getAt(i).first == elem){
                int nrApatirii = this->elements.getAt(i).second + 1;
                pair<TElem ,int> pereche(this->elements.getAt(i).first, nrApatirii);
                this->elements.update(i,pereche);
                ok =0;
            }
    }
    else{
        if(this->distinctelements == capacity)
            redim();
        pair<TElem,int> pereche(elem,1);
        this->elements.push_back(pereche);
        this->distinctelements++;
    }
}

//in: TElem
//out: bool
//desc: elimina un element in colectie
bool Collection::remove(TElem elem) {
    if(search(elem))
    {
        int i = 0;
        while(this->elements.getAt(i).first != elem)
            i++;
        for(int j = i; j< this->distinctelements - 1;j++)
            this->elements.update(j,this->elements.getAt(j+1));
        this->distinctelements --;
        return true;
    }
    return false;
}

//in: TElem
//out: bool
//desc: cauta un element in colectie
bool Collection::search(TElem elem) {
    for(int i = 0; i< this->distinctelements; i++)
        if(this->elements.getAt(i).first == elem)
            return true;
    return false;
}

//in: -
//out: int
//desc: returneaza dimensiunea colectiei
int Collection::size() {
    int sum = 0;
    for(int i = 0; i< this->distinctelements; i++)
        sum = sum + this->elements.getAt(i).first * this->elements.getAt(i).second;
    return sum;
}

//in: TElem
//out: int
//desc: returneaza numarul de aparitii pentru un element
int Collection::nroccurrences(TElem elem) {
    if(search(elem)){
        int i = 0;
        while(this->elements.getAt(i).first != elem)
            i++;
        return this->elements.getAt(i).second;
    }
    return -1;
}

void Collection::Destructor() {
    this->capacity = 0;
    this->distinctelements = 0;
}

//in: int
//out: int
//desc: returneaza numarul de aparitii a unei bancnote aflate pe pozitia "position"
int Collection::getAt(int position) {
    return this->elements.getAt(position).second;
}

//in:
//out:
//desc: dubleaza capacitatea
void Collection::Collection::redim() {
    this->capacity = this->capacity*2;
}

//in:
//out: int
//desc: returneaza numarul de bancnote
int Collection::get_lungime() {
    return this->distinctelements;
}

//in: int
//out: TElem
//desc: returneaza valoarea elementului de tip TElem aflat pe positia "position"
TElem Collection::get_val(int position) {
    return this->elements.getAt(position).first;
}


Collection &Collection::operator=(const Collection &colectie) {
    this->distinctelements = colectie.distinctelements;
    this->capacity = colectie.capacity;
    VectorDinamic<pair<TElem, int>> aux(capacity);
    this->elements = aux;
    for(int i = 0;i<this->capacity;i++)
        this->elements.push_back(colectie.elements.getAt(i));
    return *this;
}

//in: pair<TElem,int>
//out:
//desc: modifica numarul de aparitii a unei bancnote
void Collection::set_numar_bancnote(pair<TElem,int> elem) {
    if(search(elem.first))
    {
        int i = 0;
        while(this->elements.getAt(i).first != elem.first)
            i++;
        this->elements.update(i,elem);
    }
}


