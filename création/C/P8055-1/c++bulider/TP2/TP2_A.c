//---------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
typedef int bool;
#include "K8055D.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
int led=0x01, temps=1, i=0;
int inp1;
int ifob;
 int h = OpenDevice(0);
 if (h==-1)
 printf("�chec de la connexion\n");
 if (h==0)
 {
        printf("succ�s connexion\n");
        while(1){
				if(ReadDigitalChannel(2)==1){
					while(!ReadDigitalChannel(1)){
						      //	do{
                                SetDigitalChannel(led);
                                sleep(temps);
                                ClearDigitalChannel(led);
                                led=led+1;
                                i++;
                                printf("%d loul\n",i);
                                if(led==9){
									led=1;
                                                                        i=0;
								}

					}
				}

		}
}
printf("FIN\n");
  system("pause");
return 0;
}
//---------------------------------------------------------------------------
