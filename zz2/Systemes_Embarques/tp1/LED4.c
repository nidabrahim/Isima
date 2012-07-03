/****************************************************************************/
/*  MESNARD Emmanuel                                               ISIMA    */
/*  Septembre 2010                                                          */
/*                                                                          */
/*                  TD 1 -   MultiTaskLAS - Tache 6 : LED4.c                */
/*                           Chenillard ecrit en multi-tache                */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

// Ceci est la 6�me t�che r�alis�e. On attend en premier d'avoir re�u l'information
// (de la t�che d'initialisation) via la m�moire XHEAP que les ports ont bien �t�
// initialis�s. Si ces le cas, apr�s une leg�re temporisation, on fait clignoter la Led
// N� 4 du port PD.
//  

// T�che N� 6

#define	HEAP_INIT_COMPLETE	0
  
void Delay(int pTIME)
{ 
  while(pTIME--);
}

void main(void)
{ 
  Delay(0xff);

  // Attend ' le feu vert' de la t�che d'initialisation 

  while(!HeapRdChar(HEAP_INIT_COMPLETE));

  Delay((int)0xff*5/8);

  while(1)
  { 
    PPI_BitOut(PD, 4, ~PPI_BitIn(PD, 4));
    Delay(0xff);
  }
}