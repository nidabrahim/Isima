/*-----------------------------------*/
/*Maxime ESCOURBIAC                  */
/*Tp C 5                             */
/*Semaines Bloquees                  */
/*24/09/2009                         */
/*-----------------------------------*/

/*------------------------------------------------*/
/*But du TP:                                      */
/*Filtrer des mots correspondants a des criteres  */
/*de cast et de longueur parmi un dictionnaire de */
/*92482 mots present dans un fichier txt          */
/*------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main()
{
   FILE * fic1;                    /*ouverture des fichiers a lire*/
   FILE * fic2;                    /* et ecrire*/
   char nom1[]="dictionnaire.txt";
   char nom2[]="dicomotus.txt";
   char temp[255];
   int numb,i,j,erreur;
   fic1=fopen(nom1,"r");
   fic2=fopen(nom2,"w");
   fscanf(fic1,"%d",&numb);
   for(i=0;i<numb;i++)
   {
      erreur = 0;
      j= 0 ;
      fscanf(fic1,"%s",temp);
      if(strlen(temp)==5)
      {
          while(j<5 && !erreur)
          {
             switch(temp[j])
             {
                 case '�' : temp[j]='A';   /*modification   */
                 case '�' : temp[j]='E';   /*des caracteres */
                 case '�' : temp[j]='E';
                 case '�' : temp[j]='E';
                 case '�' : temp[j]='C';
                 case '�' : temp[j]='U';
                 case '�' : temp[j]='U';
                 case '�' : temp[j]='I';
                 case '�' : temp[j]='A';
                 case '�' : temp[j]='I';
                 case '-' : erreur = 1 ;  /*mots interdits*/
                 case 39  : erreur = 1 ;  /*interdits bis */
                 default  : temp[j]= toupper(temp[j]);
             }
             j++;
          }
          if(!erreur) fprintf(fic2,"%s\n",temp);
       }
    }
    fclose(fic1);
    fclose(fic2);
    return 0;
}
