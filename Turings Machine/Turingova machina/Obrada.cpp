#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include "Header.h"



Traka *indeks_novostanje(Stanje *nizstanja, int *curr, Traka *trenutni, int n)
{
	
	for (size_t i = 0; i < nizstanja[*curr].brnaredbi ; i++)
	{
		if (nizstanja[*curr].niz_naredbi[i].zameni_sa == trenutni->info)
		{
			if (nizstanja[*curr].niz_naredbi[i].pomeraj == 1)
			{
				if (trenutni->right == NULL)
				{
					Traka *novi = new Traka;
					trenutni->right = novi;
					novi->left = trenutni;
					novi->right = NULL;
					novi->info = "b";
				}
				trenutni = trenutni->right;
			}
			
			
			if (nizstanja[*curr].niz_naredbi[i].pomeraj == -1)
			{
				if (trenutni->left == NULL)
				{
					Traka *novi = new Traka;
					trenutni->left = novi;
					novi->right = trenutni;
					novi->left = NULL;
					novi->info = "b";
				}
				trenutni = trenutni->left;
			}

			
			if (nizstanja[*curr].niz_naredbi[i].ime_sl == "q+") {
				*curr = -1; return trenutni;
			}
			else if (nizstanja[*curr].niz_naredbi[i].ime_sl == "q-") {
				*curr = -2;
				return trenutni;
			}

			for (size_t k = 0; k < n ; k++)
			{
				if (nizstanja[*curr].niz_naredbi[i].ime_sl == nizstanja[k].ime) { *curr = k;  break; }
			}
			break;
		}
		
	}

	return trenutni;
}


void resizadatak( Stanje *nizstanja, Traka *prvi, int n)
{

	int curr=0;
	prvi=indeks_novostanje(nizstanja, &curr, prvi,n);
	while (true) {


		if (curr == -1) { cout << "Program je vratio q+" << endl; break; }
		else
			if (curr == -2) { cout << "Program je vratio q-" << endl; break; }
			else {

				prvi= indeks_novostanje(nizstanja, &curr, prvi, n);
				

			}
	}

}