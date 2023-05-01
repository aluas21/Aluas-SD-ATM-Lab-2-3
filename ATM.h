//
// Created by aluas on 14.03.2023.
//

#ifndef LAB_2_ATM_H
#define LAB_2_ATM_H
#include "Collection.h"
#include "Tranzactie.h"

#include<iostream>
#include "VectorDinamic.h"

using namespace std;

class ATM {
    private:
        Collection colectie_bancnote;
        Tranzactie* tranzactii;
        int nr_tranzactii;
        void afisare_colectie(VectorDinamic<pair<TElem,int>> bancnote, int lungime, int k);         //metoda de afisare a unei metode de plata
    public:
        ATM(const Collection& colectie, Tranzactie tranzactie[], int nr_tranzactii);                        //Contructor cu parametrii
        void Retragere_numerar(int id, int suma, int lungime, VectorDinamic<pair<TElem,int>> bancnote);     //elimina din atm bancnotele cu care s-a facut plata
        friend ostream& operator<<(ostream& os, ATM atm);                       //suparaincarcarea operatorului de afisare
        void Add_bancnote(TElem valoare);                                       //metoda de adaugare a unui bancnote in atm
        void Elim_bancnota(TElem valoare);                                      //metoda de eliminare a unei bancnote in atm
        void Get_tranzactia(int& poz_stop,int suma, VectorDinamic<pair<TElem,int>> bancnote, int lungime, int poz);     //retine metodade plata pana de la un indice dat
        void Generare_Tranzactii(int& indice,int suma, VectorDinamic<pair<TElem,int>> bancnote, int lungime, int poz);  //metoda care genereaza toate posibilitatile de plata a sumei "suma"
        //~ATM();
};

#endif //LAB_2_ATM_H