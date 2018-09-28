//-----------------------------------TP3 A.C------------------------------
#include <stdio.h>
#include <conio.h>
typedef int bool;
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma argsused
#include "K8055D.h"
 //fix linux
#ifdef linux
#define CLEAR "clear"
#elif _WIN32
#define CLEAR "cls"
#endif

int led();
int ledaction();
int error();
int i;
int main(int argc, char* argv[])
{
int h = OpenDevice(0);
system("TITLE P8055-1 TP3_C");
	if(h==-1)
	{
        error();
	}
	if (h==0)
	{
        	printf("succès connexion \n");
		ClearAllAnalog();
                led();
	}
	CloseDevice();
	return 0;
}
//---------------------------------------------------------------------------

// demande l'intencité
int led(){      system(CLEAR);
                printf("\n\n");
                printf("Entrer une valeur entre 1 et 255 , pour sortir faite 0: ");
                scanf("%i",&i);
                if(i==0){return 0;}
                if(i>255||i<(-1)){printf("valeur a +255 ou negatif non autorisé");sleep(2);return 0;}
		{
                   ledaction();
                }
}
// allumme la led selon l'intencité
int ledaction(){
                        system(CLEAR);
			OutputAnalogChannel(1,i);
			printf("Voici la valeur de la sortie analogique : %i \n", i);
                        printf("\nAppuyez sur une touche pour continuer... \n", i);
			sleep(0.5);
                        while(!kbhit());
	                led();
}
//quand la carte n'est pas détéqueté
int error(){
                system(CLEAR);
  		printf("Echec connexion\n");
		system ("PAUSE");
                CloseDevice();
		return 0;
}
