//
// Created by aluas on 14.03.2023.
//

#ifndef LAB_2_TRANZACTIE_H
#define LAB_2_TRANZACTIE_H
#include "Collection.h"
#include<iostream>
#include"VectorDinamic.h"
using namespace std;

typedef int TElem;

class Tranzactie {
    private:
        int Id_tranzatie;
        int suma;
        VectorDinamic<pair<TElem,int>> bancnote;
        int nr_banconte;
    public:
        Tranzactie();                                                        //Constructor implicit
        Tranzactie(int id, int suma, VectorDinamic<pair<TElem,int>> bancnote, int nr_bancnote);   //Constructor cu parametrii
        void Destructor();                                                   //Destructor
        friend ostream& operator<<(ostream& os, Tranzactie tranzactie);      //Supra incarcare operator afisare
        Tranzactie& operator=(const Tranzactie& tranzactie);                 //operator de atribuire
};


#endif //LAB_2_TRANZACTIE_H
