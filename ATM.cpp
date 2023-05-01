//
// Created by aluas on 14.03.2023.
//

#include "ATM.h"
#include "Collection.h"
#include<iostream>
using namespace std;

ATM::ATM(const Collection& colectie, Tranzactie tranzactie[], int nr_tranzactii) {
    this->colectie_bancnote = colectie;
    this->tranzactii = new Tranzactie[nr_tranzactii];
    this->nr_tranzactii = nr_tranzactii;
    for(int i = 0;i<nr_tranzactii;i++)
        this->tranzactii[i] = tranzactie[i];
}

//in: element de tip TElem
//out:
//desc: adauga in colectia atm-ului data bancnota "valoare"
void ATM::Add_bancnote(TElem valoare) {
    this->colectie_bancnote.add(valoare);
}

//in: element de tip TElem
//out:
//desc: elimina in colectia atm-ului data bancnota "valoare"
void ATM::Elim_bancnota(TElem valoare) {
    this->colectie_bancnote.remove(valoare);
}

//in: VectorDinamic<pair<Telem,int>>, int, int
//out: -
//desc: afiseaza datele elementului de dip VectorDinamic
void ATM::afisare_colectie(VectorDinamic<pair<TElem,int>> bancnote, int lungime, int k) {
    cout<<k<<")";
    k++;
    for(int i = 0;i<lungime;i++)
        cout<<bancnote.getAt(i).first<<"->"<<bancnote.getAt(i).second<<' ';
    cout<<endl;
}

//in: int, int, VectorDinamic<pair<Telem,int>>, int, int
//out: -
//desc: genereaza toate posibilitatile de plata a sumei "suma" transmisa ca parametru, salvand in "bancnote" fiecare astfel de posibilitate
void ATM::Generare_Tranzactii(int& indice,int suma, VectorDinamic<pair<TElem,int>> bancnote, int lungime, int poz) {
    if(suma == 0)
        afisare_colectie(bancnote, lungime,indice);
    else{
        for(int i = poz;i<this->colectie_bancnote.get_lungime();i++){
            int k = 0;
            TElem bancnota = this->colectie_bancnote.get_val(i);
            while(suma>=0){
                suma = suma - bancnota;
                k++;
                pair<TElem,int> pereche(bancnota,k);
                bancnote.update(i,pereche);
                if(suma == 0) indice++;
                Generare_Tranzactii(indice,suma, bancnote, lungime + 1, i + 1);
            }
            if(suma<0){
                suma = suma+bancnota;
                k--;
                pair<TElem,int> pereche(bancnote.getAt(lungime).first,k);
                bancnote.update(lungime,pereche);
            }
            suma = suma + k*bancnota;
        }
    }
}

//in: int, int, int, VectorDinamic<pair<Telem,int>>
//out: -
//desc: elimina din colectia atm-ului bancnotele retinute in "bancnote"
void ATM::Retragere_numerar(int id, int suma, int lungime, VectorDinamic<pair<TElem,int>> bancnote) {
    int ok = 1;
    for(int i = 0;i<lungime;i++)
        if(bancnote.getAt(i).second>this->colectie_bancnote.nroccurrences(bancnote.getAt(i).first)){
            ok = 0;
        }
    if(!ok)
         cout<<"Momentan ATM-ul nu dispune de toate bancnotele necesare tranzactiei"<<endl;
    else
    {
        cout<<"Tranzactie efectuata cu succes"<<endl;
        for(int i = 0;i<lungime;i++){
            pair<TElem,int> a;
            a.first = bancnote.getAt(i).first;
            a.second = this->colectie_bancnote.nroccurrences(a.first)- bancnote.getAt(i).second;
            this->colectie_bancnote.set_numar_bancnote(a);
        }
        Tranzactie aux(id,suma,bancnote,lungime);
        this->tranzactii[this->nr_tranzactii] = aux;
        this->nr_tranzactii++;
    }
}

//in: int, int, VectorDinamic<pair<Telem,int>>, int, int
//out: -
//desc: retine in "bancnote" posibilitatea de plata aflata pe pozitia "pos_stop"
void ATM::Get_tranzactia(int& poz_stop, int suma, VectorDinamic<pair<TElem,int>> bancnote, int lungime, int poz) {
    if(suma == 0)
    {
        poz_stop--;
        pair<TElem,int> pereche(-1,bancnote.getAt(lungime).second);
        bancnote.update(lungime,pereche);
    }
    else{
        for(int i = poz;i<this->colectie_bancnote.get_lungime()&&poz_stop;i++){
            if(poz_stop == 0) break;
            int k = 0;
            TElem bancnota = this->colectie_bancnote.get_val(i);
            while(suma>=0){
                suma = suma - bancnota;
                k++;
                pair<TElem,int> pereche(bancnota,k);
                bancnote.update(i,pereche);
                Get_tranzactia(poz_stop,suma, bancnote, lungime + 1, i + 1);
                if(poz_stop == 0) break;
            }
            if(suma<0){
                suma = suma+bancnota;
                k--;
                pair<TElem,int> pereche(bancnote.getAt(lungime).first,k);
                bancnote.update(lungime,pereche);
            }
            suma = suma + k*bancnota;
        }
    }
}

ostream &operator<<(ostream &os, ATM atm) {
    cout<<"BANCNOTE DISPONIBILE:"<<endl;
    for(int i = 0; i<atm.colectie_bancnote.get_lungime(); i++)
        cout << "val: " << atm.colectie_bancnote.get_val(i) << ", numar: " << atm.colectie_bancnote.getAt(i) << endl;
    cout<<endl<<"TRANZACTII EFECTUATE: "<<endl;
    for(int i = 0; i<atm.nr_tranzactii;i++){
        cout<<atm.tranzactii[i];
        cout<<endl;
    }
    return os;
}
