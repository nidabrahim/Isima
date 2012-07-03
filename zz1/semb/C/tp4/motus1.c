/*------------------------------------------------*/
/*Maxime ESCOURBIAC                               */
/*                                                */
/*Principe du tp:                                 */
/*Version du motus a 5 lettres                    */
/*cette version n'utilisera pas de dico           */
/*------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    int i,j;
    int essai = 0;
    int hasard;
    char myst[6];
    char reponse[255];
    char visu[6];
    char tableau [][6] = {"agent","agile","aider","aimer","badge"};
    srand(time(0));             /*choix du mot au hasard*/
    hasard = rand()%5;
    strcpy(myst,tableau[hasard]); /*pour eviter de manipuler le tab principal */
    printf("vous avez 5 essais pour trouver le mot mystere \n");
    do
    {   
        printf("il vous reste %d essais\n",5-essai);
        essai++;
        printf("veuillez tapez votre essai\n");
        scanf("%s", reponse);
        if(strlen(reponse)==5)
        {   
           for(i=0;i < 5;i++)  /*boucle pour tester element par element*/
           {
               if(reponse[i]==myst[i]) visu[i]=myst[i]; /*lettre juste*/ 
               else 
               {
                   j=0;
                   while(j<5 && reponse[i]!=myst[j])   /*cas de la lettre mal placee*/
                   {
                      j++;
                   }
                   if(j==5)visu[i]='#';     /*si lettre inexistante*/
                   else visu[i]='_';        
               }
           }
           printf("reponse\n");
           printf("%s\n",visu);
        }
        else printf("essai perdu car votre reponse n'a pas 5 caracteres\n");
    }while(essai < 5 && strcmp(reponse,myst));
    if(!strcmp(reponse,myst))printf("bravo champion\n");
    else printf("vous vous etes lourdee\n");
    return 0;
}
