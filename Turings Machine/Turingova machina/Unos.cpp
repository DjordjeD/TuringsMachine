#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include "Header.h"

void ispis(Traka *cvor)
{
	while (cvor != NULL)
	{
		cout << cvor->info << " " << endl;
		cvor = cvor->right;
	}
}

void Unos(string *azbuka,Traka **prvit,Stanje *nizstanja ,int *n)
{	
	ifstream in;
	in.open("Unos1.txt");
	string linija;
	if (!in)
		cout << "ne radi";
	in >> *azbuka;

	string c;
	in >> c;
	Traka *poslt=NULL,*tekt = NULL;
	for (int i = 0; i < c.length(); i++)
	{
		tekt = new Traka;
		tekt->info = c.at(i);
		tekt->left = poslt;
		tekt->right = NULL;
		if (*prvit == NULL)
		{
			poslt = tekt;
			*prvit = tekt;
		}
		else
		{
			poslt->right = tekt;
			poslt = tekt;
		}
		
	}
	
	
	getline(in, linija);
	
	while (getline(in,linija))
	{ 
		int pom;
		int pos = linija.find('(');
		int pos2 = linija.find(',');
		string proveristanje = linija.substr(pos+1, pos2-pos-1);  //trenutno stanje
				
				
		int pos3 = linija.find(')');
				string ime_azbuke = linija.substr(pos2+1, pos3 - pos2-1);
				//cout << ime_azbuke<<endl;					//ako je ovo na traci

		int pos1 = linija.find('=');
				string s1 = linija.substr(pos1 + 1);
				pos = s1.find('(');
				pos2 = s1.find(',');

		string ime_sledece = s1.substr(pos + 1, pos2 - pos - 1); //sledece stanje
		//cout << ime_sledece << endl;
		
				string s2 = s1.substr(pos2 + 1);
				pos2 = s2.find(',');
	
		string zameni_sa1 = s2.substr(0, pos2);  //ono cime menjamo
		//cout << zameni_sa1 << endl;

		if (s2.at(pos2 + 1) == '+') pom = 1;
			else if (s2.at(pos2 + 1) == '-') pom = -1;
				else pom = 0;

				cout << proveristanje + " " + ime_azbuke + " " + ime_sledece + " " + zameni_sa1 + " " << pom << endl;

		bool b = 0;
		for (size_t i = 0; i < *n; i++)
		{
			if (nizstanja[i].ime == proveristanje)
			{
				nizstanja[i].niz_naredbi[nizstanja[i].brnaredbi].zameni_sa = zameni_sa1;
				nizstanja[i].niz_naredbi[nizstanja[i].brnaredbi].ime_sl = ime_sledece;
				nizstanja[i].niz_naredbi[nizstanja[i].brnaredbi++].pomeraj = pom;
				b = 1;
				break;
			}
				
		}
		if (b == 0)
		{
			nizstanja[*n].ime = proveristanje;
			nizstanja[*n].brnaredbi = 0;
			nizstanja[*n].niz_naredbi[nizstanja[*n].brnaredbi].zameni_sa = zameni_sa1;
			nizstanja[*n].niz_naredbi[nizstanja[*n].brnaredbi].ime_sl = ime_sledece;
			nizstanja[*n].niz_naredbi[nizstanja[*n].brnaredbi++].pomeraj = pom;
			*n=*n+1;

		}


	}
	
	for (size_t i = 0; i < *n; i++)
	{	

		for (size_t j = 0; j < nizstanja[i].brnaredbi ; j++)
		{
			//cout << nizstanja[i].ime + " " + nizstanja[i].niz_naredbi[j].ime_sl
				//+ " " + nizstanja[i].niz_naredbi[j].zameni_sa << endl;
		}
	}

}