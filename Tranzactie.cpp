//
// Created by aluas on 14.03.2023.
//

#include "Tranzactie.h"

Tranzactie::Tranzactie(int id, int suma, VectorDinamic<pair<TElem,int>> bancnote, int nr_bancnote) {
    this->Id_tranzatie =  id;
    this->suma = suma;
    this->nr_banconte = nr_bancnote;
    VectorDinamic<pair<TElem,int>> v(nr_bancnote);
    this->bancnote =v;
    for(int i = 0; i< nr_bancnote;i++)
        this->bancnote.push_back(bancnote.getAt(i));
}

Tranzactie::Tranzactie() {
    this->Id_tranzatie = -1;
    this->suma = -1;
    VectorDinamic<pair<TElem,int>> v(1);
    this->bancnote = v;
    this->nr_banconte = -1;
}

void Tranzactie::Destructor() {
}

Tranzactie &Tranzactie::operator=(const Tranzactie &tranzactie) {
    this->Id_tranzatie = tranzactie.Id_tranzatie;
    this->suma = tranzactie.suma;
    this->nr_banconte = tranzactie.nr_banconte;
    VectorDinamic<pair<TElem,int>> v(this->nr_banconte);
    this->bancnote = v;
    for(int i = 0;i<this->nr_banconte;i++)
        this->bancnote.push_back(tranzactie.bancnote.getAt(i));
    return *this;
}

ostream &operator<<(ostream &os, Tranzactie tranzactie) {
    cout<<"id: "<<tranzactie.Id_tranzatie<<" suma: "<<tranzactie.suma<<endl;
    cout<<"Plata: ";
    for(int i = 0;i<tranzactie.nr_banconte;i++)
        cout<<tranzactie.bancnote.getAt(i).first<<"->"<<tranzactie.bancnote.getAt(i).second<<", ";
    cout<<endl;
    return os;
}


