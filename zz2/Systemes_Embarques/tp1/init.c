/****************************************************************************/
/*  MESNARD Emmanuel                                               ISIMA    */
/*  Septembre 2010                                                          */
/*                                                                          */
/*                  TD 1 -   MultiTaskLAS - Tache 1 : init.c                */
/*                           Chenillard ecrit en multi-tache                */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

// L'adresse 0 de la m�moire RAM XHEAP contient la variable partag�e entre toutes les t�ches
// Elle est utilis�e pour m�moriser le fait que les ports n'ont pas encore �t�s initialis�s (FALSE)
// Lorsque les ports ont �t� initialis�s, cette variable est mise � TRUE pour avertir les autres
// t�ches qu'elles peuvent d�buter leur traitement

// La dur�e de la temporisation apr�s la confirmation de l'initialisation des ports sera
// diff�rente pour toutes les taches afin que les clignotements de Leds de chaque
// t�che soient d�cal�s dans le temps pour cr�er un effet de d�filement.

// T�che N� 1 (initialisation)
  
#define	HEAP_INIT_COMPLETE	0


void PPI_Init(void)
{ // Initialisation des ports PA, PB et PC en entr�e
  // 0 : Broche en sortie.
  // 1 : Broche en entr�e.

  PPI_SetMode(PA,0xff);  PPI_Out(PA,0xff);
  PPI_SetMode(PB,0xff);  PPI_Out(PB,0xff);
  PPI_SetMode(PC,0xff);  PPI_Out(PC,0xff);

  // Initialisation du port PD en sortie et extinction des Leds de la platine.
  PPI_SetMode(PD,0x00);  PPI_Out    (PD,0xff);
}

void EXPORT_Init(void)
{ // Initialisation des ports EXPA, EXPB et EXPD en entr�e
  PortSetMode(EXPA,0xff);
  PortSetMode(EXPB,0xff);
  PortSetMode(EXPD,0xff);
} 

void main(void)
{
  // On indique via un emplacement de la m�moire XHEAP que les ports ne sont pas initialis�s
  HeapWrChar(HEAP_INIT_COMPLETE, FALSE);

  // Initialisation des ports  
  PPI_Init();
  EXPORT_Init();
  
  // On indique via un emplacement de la m�moire XHEAP que les ports ont �t� initialis�s
  HeapWrChar(HEAP_INIT_COMPLETE, TRUE);
}
