/****************************************************************************/
/*  MESNARD Emmanuel                                               ISIMA    */
/*  Novembre 2010                                                           */
/*                                                                          */
/* TD 5 et 6 -  Capteur "intelligent" et gestion des afficheurs sur PIC     */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

  // TD installant :
  //    * le capteur intelligent de temp�rature Dallas DS1820, permettant
  //      l'acquisition sur 8 bits (+ le signe) d'une temp�rature avec la
  //      pr�cision par d�faut de 0,5�C
  //    * l'afficheur LCD 2*16 lignes pour l'affichage en Temps R�el
  //      de la temp�rature mesur�e (valeur d�cimal, de pr�cision 0.5�C)
  //    * l'afficheur Graphique (GLCD) 128*64 points pour l'affichage
  //      de l'�volution temporelle de la temp�rature
  //      La courbe centr�e sur 20�C, accepte des temp�ratures comprises
  //      entre 7,5�C et 32,5�C
  //      Un pixel repr�sente ainsi 0,5�C

// Directive de compilation pour s�l�ctionner le LCD choisi pour ce TP
// -------------------------------------------------------------------
#define AFF_LCD
// #define AFF_GLCD
// NB : une seule directive a la fois, les LCD etant en conflit sur les ports


// zone de trac� : (5,10) a (125,60)
// Axe X : temps, amplitude 125-5, soit 120 unit�s (presque 2 minutes)
// Axe Y : temperature, amplitude 60-10, soit 50 demi-degres, donc, 25�C
#define Xmin 5
#define XMax 125
#define Ymin 10
#define YMax 60

// Dur�e avant rafraichissement de l'ecran
#define Temps_Maxi 120 // 125-5=120, donc 1 pixel par mesure

// Variables globales
unsigned int Temperature_ABS, Temperature_SIGN;   // Valeur et signe de �C

#ifdef  AFF_LCD
char Texte_LCD[8];
#endif

#ifdef  AFF_GLCD
char *Texte_GLCD;
int Temps_Ecoule;
#endif

// Fonction de suppression des espaces dans les chaines de caracteres
char *R_Trim(char *str1) {
  while (*str1 == ' ')
    str1++;
  return str1;
}

#ifdef  AFF_LCD
// Affichage en mode texte de la temperature sur le LCD 2 lignes
void AFF_Temp_LCD(unsigned int Temperature_ABS, unsigned int Temperature_SIGN) {
  unsigned int Partie_Entiere,  Partie_Fraction;
//
//  A  C O M P L E T E R
//

  // Effacement du LCD et affichage du titre

  // Test pour l'affichage du signe

  // Affichage de la valeur absolue Entiere

  // Affichage de la partie fractionnaire

  // Affichage des caract�res �C
  LCD_Chr_CP(223);
  LCD_Chr_CP('C');
}
#endif


#ifdef  AFF_GLCD
// Affichage en mode texte de la temperature sur le GLCD
void AFF_Temp_GLCD(unsigned int Temperature_ABS, \
                   unsigned int Temperature_SIGN) {
  unsigned int Partie_Entiere,  Partie_Fraction;

//
//  A  C O M P L E T E R
//

  // Effacement de l'ancienne fin de ligne (ancienne valeur de temp�rature)
  Glcd_Write_Text("::::::::",80,0,1);    // NB: le ":" repr�sente l'espace

  // Affichage du signe

  // Affichage de la valeur absolue Entiere

  // Affichage de la partie fractionnaire

}

void AFF_Temp_Graph_GLCD(unsigned int Temperature_ABS, \
                         unsigned int Temperature_SIGN) {
//
//  A  C O M P L E T E R
//
  // Affichage du point si presence dans la zone de trac�

}
#endif

// Programme principal
// -------------------

void main() {
  int i;
  // Configuration du ADCON1 afin de valider le
  // port A.5 en entr�e num�rique pour le DS1820

//
//  A  C O M P L E T E R
//
#ifdef  AFF_LCD
  // Initialisation du LCD
//
//  A  C O M P L E T E R
//

#endif

#ifdef  AFF_GLCD
  // Initialisation generale
  Temps_Ecoule = 0;

  // Initialisation du GLCD
//
//  A  C O M P L E T E R
//

  // Affichage du titre
//
//  A  C O M P L E T E R
//

  // Affichage de l'�chelle sur l'axe des ordonn�es
  Glcd_V_Line(Ymin,YMax,Xmin-2,1);
  Glcd_H_Line(Xmin-4,Xmin,15,1);   // haut d'�chelle   =30�C
  Glcd_H_Line(Xmin-3,Xmin-1,25,1); // haut d'�chelle   =25�C
  Glcd_H_Line(Xmin-4,Xmin,35,1);   // milieu d'�chelle =20�C
  Glcd_H_Line(Xmin-3,Xmin-1,45,1); // milieu d'�chelle =15�C
  Glcd_H_Line(Xmin-4,Xmin,55,1);   // bas d'�chelle    =10�C
#endif

  while (1) {

    // Communication avec le DS1820

    // Demande d'acquisition et de conversion
//
//  A  C O M P L E T E R
//

    // Attente n�cessaire � la conversion
    Delay_ms(500);

    // Demande de lecture de la m�moire (contenant les valeurs acquises)
//
//  A  C O M P L E T E R
//

    // Attente pour l'acc�s RAM
    Delay_ms(400);

    // Lecture du bus OneWire pour r�cup�rer la temp�rature lue
    Temperature_ABS = OW_Read(&PORTA,5);  // Temperature LSB (valeur*2)
    Temperature_SIGN= OW_Read(&PORTA,5);  // Temperature MSB (signe)

#ifdef  AFF_LCD
    // Affichage sur le LCD 2 lignes en mode texte uniquement
    AFF_Temp_LCD(Temperature_ABS, Temperature_SIGN);
    Delay_ms(100);
#endif

#ifdef  AFF_GLCD
    // Affichage sur le GLCD en mode graphique

    // Ecoulement du temps
    Temps_Ecoule++;

    // Affichage du Texte en haut du GLCD
    AFF_Temp_GLCD(Temperature_ABS, Temperature_SIGN);

    // Affichage du Graphique sur la zone de trac�
    AFF_Temp_Graph_GLCD(Temperature_ABS, Temperature_SIGN);

    // Effacement de la zone graphique si le graphe est plein
    if (Temps_Ecoule>Temps_Maxi) {
      Temps_Ecoule=0;
      Glcd_Box(Xmin+1,Ymin,XMax+1,YMax,0); // Effacement de la zone de trac�
    }
#endif
  }
}