//
// Created by aluas on 26.03.2023.
//

#include "teste.h"
#include "VectorDinamic.h"
#include "Tranzactie.h"
#include<iostream>
using namespace std;
#include<cassert>

void teste(){
    VectorDinamic<int> v(15);
    assert(v.size() == 0);
    v.push_back(9);
    assert(v.size() == 1);
    assert(v.getAt(0) == 9);
    v.addAt(1,8);
    assert(v.size() == 2);
    assert(v.getAt(1) == 8);
    v.addAt(1,9);
    assert(v.size() == 3);
    assert(v.getAt(1) == 9);
    assert(v.getAt(2) == 8);
    assert(v.sterge(0) == 9);
    assert(v.size() == 2);
    assert(v.update(0, 10));
    assert(v.getAt(0) == 10);

}
