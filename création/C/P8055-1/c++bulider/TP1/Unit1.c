  /* clinotement test des led velman
   copyright VELMAN 2003
   toute reproduction imposible méme les fautes ;D
  */

//---------------------------------------------------------------------------
// Libraires
//---------------------------------------------------------------------------
#include <stdio.h>
typedef int bool;    //Fix suport langue C
#include "K8055D.h"  //libraire Velman
#pragma hdrstop
//---------------------------------------------------------------------------
// debut du code
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
 int h = OpenDevice(0);                 //connection a la carte
 if (h==-1)                             //valeur négative = pas de connection
        printf("‚chec connexion");      //message en cas de echec de connection
 if (h==0)
{
 printf("succŠs connexion \n"); //conection établie passe a la suite
 SetAllDigital();               //met toute les sortie sur 1 (on)
 printf("Tout a 1 \n");         //mesage de confirmation
 sleep(5);
 ClearAllDigital();        //met toute les sortie sur 0 (off)
 printf("Tout a 0 \n");   //mesage de confirmation
 sleep(5);
 SetAllDigital();        //met toute les sortie sur 1 (on)
 printf("Tout a 1 \n");  //mesage de confirmation
 system("pause");        //fin du programe attente confirmation
 }
return 0;
}
//---------------------------------------------------------------------------
