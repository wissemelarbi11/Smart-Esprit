
#include "fonction.h"
#include <stdio.h>
int verifier(char log[] ,char Pw[])
{
int trouve=-1; 
FILE *f=NULL;
char ch1[20];
char ch2[20];
f =fopen("wessutilisateur.txt","a+");
if (f!=NULL){
while (fscanf(f,"%s %s\n",ch1,ch2) !=EOF)
{
if (strcmp(ch1,log)==0 && strcmp(ch2,Pw)==0)
trouve=1;
}
fclose(f);
}
return trouve ;
}
