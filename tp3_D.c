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
float i;
float vin;
float v;
int main(int argc, char* argv[])
{
int h = OpenDevice(0);
system("TITLE P8055-1 TP3_D");
	if(h==-1)
	{
        //led();
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
                printf("Entrer une valeur entre 1 et 5v , pour sortir faite 0: ");
                scanf("%f",&i);
                v = i;
                vin = (i * 255) / 5;    //conversion des v en nbr
                if(i==0){OutputAnalogChannel(1,0);return 0;}
                if(i>5||i<(-1)){printf("valeur a +255 ou negatif non autorisé");sleep(2);return 0;}
                   ledaction();
}
// allumme la led selon l'intencité
int ledaction(){
                        system(CLEAR);
			OutputAnalogChannel(1,vin);
			printf("Voici la valeur de la sortie analogique : %f soit %f V\n", vin, v);
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
