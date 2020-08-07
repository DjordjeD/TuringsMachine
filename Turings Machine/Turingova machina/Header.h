#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <fstream>

#define MAX_AZBUKA 500
using namespace std;

typedef struct traka {
	struct traka *left;
	struct traka *right;
	string info;
}Traka;

typedef struct naredba {
	int pomeraj;
	string ime_sl;
	string zameni_sa;

}Naredba;

typedef struct stanje{
	string ime;
	int brnaredbi;
	Naredba niz_naredbi[MAX_AZBUKA];
}Stanje;

void Unos(string *azbuka, Traka **prvit, Stanje *nizstanja, int *n);
void ispis(Traka *cvor);
void resizadatak(Stanje *nizstanja, Traka *prvi, int n);


