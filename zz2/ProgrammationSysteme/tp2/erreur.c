void erreur(procedure,raison,fatal)

char *procedure,*raison;
int fatal;

{
printf("\7**************************************************************\n");
printf("----------------------------------------------------------------\n\n");
printf("******* %s ********\n\n",procedure);
printf("----------------------------------------------------------------\n\n");
printf("* %s *\n\n",raison);
printf("----------------------------------------------------------------\n\n");

if (fatal!=0) {
                printf("ERREUR FATALE \7\n");
                printf("GAME OVER -> EXIT OS\n");
 printf("----------------------------------------------------------------\n\n");
 printf("\7***************************************************************\n");
                exit(fatal);
              }

}