/****************************************************************************/
/*  MESNARD Emmanuel                                               ISIMA    */
/*  Fevrier 2010                                                            */
/*                                                                          */
/*                 Diverses polices pour afficheur GLCD                     */
/*                                                                          */
/*                 Tailles possibles :                                      */
/*                        3 x 6                                             */
/*                        5 x 7                                             */
/*                        5 x 8                                             */
/*                        7 x 8                                             */
/*                        4 x 7 Verticale                                   */
/*                        8 x 8 Verticale                                   */
/*                                                                          */
/* polices.h                                                        PIC     */
/****************************************************************************/

// USAGE :
// -------
//    #include "polices.h"
//
//    const char Message[] = "TD 6 systemes embarques";   // Message stocke en memoire ROM
//    char  Buffer[30];                                   // Buffer en RAM pour affichage
//     
//    Glcd_Set_Font(Police5x8, 5, 8, 0x20); // Choix de la police, par exemple, Police5x8
//                                          // qui demarre avec le caractere espace (offset=32=0x20)
//
//    Rom2Ram(Buffer, Message);             // Ramene le message a afficher en memoire RAM
//
//    Glcd_Write_Text(Buffer, 0, 0, 1);     // Affiche le message, par exemple en ligne 0
//
// 
//  Avec la fonction Rom2Ram, permettant le passage d'une constante en ROM vers une variable en RAM
//
//  void Rom2Ram(char *ToRam, const char *FromRom)
//  { int i;
//    i = 0 ;
//    do {
//      ToRam[i] = FromRom[i];
//    } while (ToRam[i++]) ;
//  }



// Definitions des polices de caracteres
// -------------------------------------


/* Police3x6 (char 0x20 a 0x80)          */
/* Format :  0x78,0x14,0x78  =  A        */
/*           . # # # # ' ' .      0x78   */
/*           . ' ' # ' # ' .      0x14   */
/*           . # # # # ' ' .      0x78   */
/* Un octet est une colonne du caractere */
const unsigned short Police3x6[] = {
    0x00,0x00,0x00,  //  Espace  0x20 
    0x00,0x5c,0x00,  //  ! 
    0x0c,0x00,0x0c,  //  " 
    0x7c,0x28,0x7c,  //  # 
    0x7c,0x44,0x7c,  //  $ 
    0x24,0x10,0x48,  //  % 
    0x28,0x54,0x08,  //  & 
    0x00,0x0c,0x00,  //  ' 
    0x38,0x44,0x00,  //  ( 
    0x44,0x38,0x00,  //  ) 
    0x20,0x10,0x08,  //  * 
    0x10,0x38,0x10,  //  + 
    0x80,0x40,0x00,  //  , 
    0x10,0x10,0x10,  //  - 
    0x00,0x40,0x00,  //  . 
    0x20,0x10,0x08,  //  / 
    0x38,0x44,0x38,  //  0       0x30 
    0x00,0x7c,0x00,  //  1 
    0x64,0x54,0x48,  //  2 
    0x44,0x54,0x28,  //  3 
    0x1c,0x10,0x7c,  //  4 
    0x4c,0x54,0x24,  //  5 
    0x38,0x54,0x20,  //  6 
    0x04,0x74,0x0c,  //  7 
    0x28,0x54,0x28,  //  8 
    0x08,0x54,0x38,  //  9 
    0x00,0x50,0x00,  //  : 
    0x80,0x50,0x00,  //  ; 
    0x10,0x28,0x44,  //  < 
    0x28,0x28,0x28,  //  = 
    0x44,0x28,0x10,  //  > 
    0x04,0x54,0x08,  //  ? 
    0x38,0x4c,0x5c,  //  @       0x40 
    0x78,0x14,0x78,  //  A 
    0x7c,0x54,0x28,  //  B 
    0x38,0x44,0x44,  //  C 
    0x7c,0x44,0x38,  //  D 
    0x7c,0x54,0x44,  //  E 
    0x7c,0x14,0x04,  //  F 
    0x38,0x44,0x34,  //  G 
    0x7c,0x10,0x7c,  //  H 
    0x00,0x7c,0x00,  //  I 
    0x20,0x40,0x3c,  //  J 
    0x7c,0x10,0x6c,  //  K 
    0x7c,0x40,0x40,  //  L 
    0x7c,0x08,0x7c,  //  M 
    0x7c,0x04,0x7c,  //  N 
    0x7c,0x44,0x7c,  //  O 
    0x7c,0x14,0x08,  //  P       0x50 
    0x38,0x44,0x78,  //  Q 
    0x7c,0x14,0x68,  //  R 
    0x48,0x54,0x24,  //  S 
    0x04,0x7c,0x04,  //  T 
    0x7c,0x40,0x7c,  //  U 
    0x3c,0x40,0x3c,  //  V 
    0x7c,0x20,0x7c,  //  W 
    0x6c,0x10,0x6c,  //  X 
    0x1c,0x60,0x1c,  //  Y 
    0x64,0x54,0x4c,  //  Z 
    0x7c,0x44,0x00,  //  [ 
    0x08,0x10,0x20,  //  \ 
    0x44,0x7c,0x00,  //  ] 
    0x08,0x04,0x08,  //  ^ 
    0x80,0x80,0x80,  //  _ 
    0x04,0x08,0x00,  //  `       0x60 
    0x78,0x14,0x78,  //  A pour a     
    0x7c,0x54,0x28,  //  B pour b, ...    
    0x38,0x44,0x44,  //  C    
    0x7c,0x44,0x38,  //  D  cette police est trop
    0x7c,0x54,0x44,  //  E  petite pour accepter
    0x7c,0x14,0x04,  //  F  l'affichage de minuscules
    0x38,0x44,0x34,  //  G 
    0x7c,0x10,0x7c,  //  H 
    0x00,0x7c,0x00,  //  I 
    0x20,0x40,0x3c,  //  J 
    0x7c,0x10,0x6c,  //  K 
    0x7c,0x40,0x40,  //  L 
    0x7c,0x08,0x7c,  //  M 
    0x7c,0x04,0x7c,  //  N 
    0x7c,0x44,0x7c,  //  O 
    0x7c,0x14,0x08,  //  P       0x70 
    0x38,0x44,0x78,  //  Q 
    0x7c,0x14,0x68,  //  R 
    0x48,0x54,0x24,  //  S 
    0x04,0x7c,0x04,  //  T 
    0x7c,0x40,0x7c,  //  U 
    0x3c,0x40,0x3c,  //  V 
    0x7c,0x20,0x7c,  //  W 
    0x6c,0x10,0x6c,  //  X 
    0x1c,0x60,0x1c,  //  Y 
    0x64,0x54,0x4c,  //  Z 
    0x10,0x7c,0x44,  //  { 
    0x00,0x38,0x00,  //  | 
    0x44,0x7c,0x10,  //  } 
    0x10,0x08,0x10,  //  ~ 
    0x7e,0x42,0x7e,  //   
    0x3c,0x5a,0x42   //  �       0x80 
};

/* Police5x7 (char 0x20 a 0x80)             */
/* Format :  0x7e,0x11,0x11,0x11,0x7e  =  A */
/*           . # # # # # # '      0x7e      */
/*           . ' ' # ' ' ' #      0x11      */
/*           . ' ' # ' ' ' #      0x11      */
/*           . ' ' # ' ' ' #      0x11      */
/*           . # # # # # # '      0x7e      */
/* Un octet est une colonne du caractere    */
const unsigned short Police5x7[] = {
    0x00,0x00,0x00,0x00,0x00,  //  Espace  0x20
    0x00,0x00,0x4f,0x00,0x00,  //  ! 
    0x00,0x07,0x00,0x07,0x00,  //  " 
    0x14,0x7f,0x14,0x7f,0x14,  //  # 
    0x24,0x2a,0x7f,0x2a,0x12,  //  $ 
    0x23,0x13,0x08,0x64,0x62,  //  % 
    0x36,0x49,0x55,0x22,0x50,  //  & 
    0x00,0x05,0x03,0x00,0x00,  //  ' 
    0x1c,0x22,0x41,0x00,0x00,  //  ( 
    0x00,0x00,0x41,0x22,0x1c,  //  ) 
    0x14,0x08,0x3e,0x08,0x14,  //  * 
    0x08,0x08,0x3e,0x08,0x08,  //  + 
    0x00,0x50,0x30,0x00,0x00,  //  , 
    0x08,0x08,0x08,0x08,0x08,  //  - 
    0x00,0x60,0x60,0x00,0x00,  //  . 
    0x20,0x10,0x08,0x04,0x02,  //  / 
    0x3e,0x51,0x49,0x45,0x3e,  //  0       0x30
    0x00,0x42,0x7f,0x40,0x00,  //  1 
    0x42,0x61,0x51,0x49,0x46,  //  2
    0x21,0x41,0x45,0x4b,0x31,  //  3 
    0x18,0x14,0x12,0x7f,0x10,  //  4 
    0x27,0x45,0x45,0x45,0x39,  //  5 
    0x3c,0x4a,0x49,0x49,0x30,  //  6 
    0x01,0x71,0x09,0x05,0x03,  //  7 
    0x36,0x49,0x49,0x49,0x36,  //  8 
    0x06,0x49,0x49,0x29,0x1e,  //  9 
    0x00,0x36,0x36,0x00,0x00,  //  : 
    0x00,0x56,0x36,0x00,0x00,  //  ; 
    0x08,0x14,0x22,0x41,0x00,  //  < 
    0x14,0x14,0x14,0x14,0x14,  //  = 
    0x00,0x41,0x22,0x14,0x08,  //  > 
    0x02,0x01,0x51,0x09,0x06,  //  ? 
    0x32,0x49,0x79,0x41,0x3e,  //  @       0x40
    0x7e,0x11,0x11,0x11,0x7e,  //  A 
    0x7f,0x49,0x49,0x49,0x36,  //  B 
    0x3e,0x41,0x41,0x41,0x22,  //  C 
    0x7f,0x41,0x41,0x22,0x1c,  //  D 
    0x7f,0x49,0x49,0x49,0x41,  //  E 
    0x7f,0x09,0x09,0x09,0x01,  //  F 
    0x3e,0x41,0x49,0x49,0x7a,  //  G 
    0x7f,0x08,0x08,0x08,0x7f,  //  H 
    0x00,0x41,0x7f,0x41,0x00,  //  I 
    0x20,0x40,0x41,0x3f,0x01,  //  J 
    0x7f,0x08,0x14,0x22,0x41,  //  K 
    0x7f,0x40,0x40,0x40,0x40,  //  L 
    0x7f,0x02,0x0c,0x02,0x7f,  //  M 
    0x7f,0x04,0x08,0x10,0x7f,  //  N 
    0x3e,0x41,0x41,0x41,0x3e,  //  O 
    0x7f,0x09,0x09,0x09,0x06,  //  P       0x50
    0x3e,0x41,0x51,0x21,0x5e,  //  Q 
    0x7f,0x09,0x19,0x29,0x46,  //  R 
    0x46,0x49,0x49,0x49,0x31,  //  S 
    0x01,0x01,0x7f,0x01,0x01,  //  T 
    0x3f,0x40,0x40,0x40,0x3f,  //  U 
    0x1f,0x20,0x40,0x20,0x1f,  //  V 
    0x3f,0x40,0x38,0x40,0x3f,  //  W 
    0x63,0x14,0x08,0x14,0x63,  //  X 
    0x07,0x08,0x70,0x08,0x07,  //  Y 
    0x61,0x51,0x49,0x45,0x43,  //  Z 
    0x7f,0x41,0x41,0x00,0x00,  //  [ 
    0x02,0x04,0x08,0x10,0x20,  //  \ 
    0x00,0x00,0x41,0x41,0x7f,  //  ] 
    0x04,0x02,0x01,0x02,0x04,  //  ^ 
    0x40,0x40,0x40,0x40,0x40,  //  _ 
    0x00,0x01,0x02,0x04,0x00,  //  `       0x60
    0x20,0x54,0x54,0x54,0x78,  //  a 
    0x7f,0x48,0x44,0x44,0x38,  //  b 
    0x38,0x44,0x44,0x44,0x20,  //  c 
    0x38,0x44,0x44,0x48,0x7f,  //  d 
    0x38,0x54,0x54,0x54,0x18,  //  e 
    0x08,0x7e,0x09,0x01,0x02,  //  f 
    0x0c,0x52,0x52,0x52,0x3e,  //  g 
    0x7f,0x08,0x04,0x04,0x78,  //  h 
    0x00,0x44,0x7d,0x40,0x00,  //  i 
    0x00,0x20,0x40,0x44,0x3d,  //  j 
    0x7f,0x10,0x28,0x44,0x00,  //  k 
    0x00,0x41,0x7f,0x40,0x00,  //  l 
    0x7c,0x04,0x18,0x04,0x78,  //  m 
    0x7c,0x08,0x04,0x04,0x78,  //  n 
    0x38,0x44,0x44,0x44,0x38,  //  o 
    0x7c,0x14,0x14,0x14,0x08,  //  p       0x70
    0x08,0x14,0x14,0x18,0x7c,  //  q 
    0x7c,0x08,0x04,0x04,0x08,  //  r 
    0x48,0x54,0x54,0x54,0x20,  //  s 
    0x04,0x3f,0x44,0x40,0x20,  //  t 
    0x3c,0x40,0x40,0x20,0x7c,  //  u 
    0x1c,0x20,0x40,0x20,0x1c,  //  v 
    0x3c,0x40,0x30,0x40,0x3c,  //  w 
    0x44,0x28,0x10,0x28,0x44,  //  x 
    0x0c,0x50,0x50,0x50,0x3c,  //  y 
    0x44,0x64,0x54,0x4c,0x44,  //  z 
    0x08,0x36,0x41,0x00,0x00,  //  { 
    0x00,0x00,0x7f,0x00,0x00,  //  | 
    0x00,0x00,0x41,0x36,0x08,  //  } 
    0x00,0x08,0x04,0x08,0x04,  //  ~ 
    0x08,0x08,0x2a,0x1c,0x08,  //  ->
    0x14,0x7e,0x95,0x95,0x42   //  �       0x80
};

/* Police5x8 (char 0x20 a 0x80)             */
/* Format :  0x7e,0x11,0x11,0x11,0x7e  =  A */
/*           ' # # # # # # '      0x7e      */
/*           ' ' ' # ' ' ' #      0x11      */
/*           ' ' ' # ' ' ' #      0x11      */
/*           ' ' ' # ' ' ' #      0x11      */
/*           ' # # # # # # '      0x7e      */
/* Un octet est une colonne du caractere    */
const unsigned short Police5x8[] = {
    0x00,0x00,0x00,0x00,0x00,  //  Espace  0x20 
    0x00,0x00,0x4f,0x00,0x00,  //  ! 
    0x00,0x07,0x00,0x07,0x00,  //  " 
    0x14,0x7f,0x14,0x7f,0x14,  //  # 
    0x24,0x2a,0x7f,0x2a,0x12,  //  $ 
    0x23,0x13,0x08,0x64,0x62,  //  % 
    0x36,0x49,0x55,0x22,0x20,  //  & 
    0x00,0x05,0x03,0x00,0x00,  //  ' 
    0x00,0x1c,0x22,0x41,0x00,  //  ( 
    0x00,0x41,0x22,0x1c,0x00,  //  ) 
    0x14,0x08,0x3e,0x08,0x14,  //  * 
    0x08,0x08,0x3e,0x08,0x08,  //  + 
    0x50,0x30,0x00,0x00,0x00,  //  , 
    0x08,0x08,0x08,0x08,0x08,  //  - 
    0x00,0x60,0x60,0x00,0x00,  //  . 
    0x20,0x10,0x08,0x04,0x02,  //  / 
    0x3e,0x51,0x49,0x45,0x3e,  //  0       0x30 
    0x00,0x42,0x7f,0x40,0x00,  //  1 
    0x42,0x61,0x51,0x49,0x46,  //  2 
    0x21,0x41,0x45,0x4b,0x31,  //  3 
    0x18,0x14,0x12,0x7f,0x10,  //  4 
    0x27,0x45,0x45,0x45,0x39,  //  5 
    0x3c,0x4a,0x49,0x49,0x30,  //  6 
    0x01,0x71,0x09,0x05,0x03,  //  7 
    0x36,0x49,0x49,0x49,0x36,  //  8 
    0x06,0x49,0x49,0x29,0x1e,  //  9 
    0x00,0x36,0x36,0x00,0x00,  //  : 
    0x00,0x56,0x36,0x00,0x00,  //  ; 
    0x08,0x14,0x22,0x41,0x00,  //  < 
    0x14,0x14,0x14,0x14,0x14,  //  = 
    0x00,0x41,0x22,0x14,0x08,  //  > 
    0x02,0x01,0x51,0x09,0x06,  //  ? 
    0x3e,0x41,0x5d,0x55,0x1e,  //  @       0x40 
    0x7e,0x11,0x11,0x11,0x7e,  //  A 
    0x7f,0x49,0x49,0x49,0x36,  //  B 
    0x3e,0x41,0x41,0x41,0x22,  //  C 
    0x7f,0x41,0x41,0x22,0x1c,  //  D 
    0x7f,0x49,0x49,0x49,0x41,  //  E 
    0x7f,0x09,0x09,0x09,0x01,  //  F 
    0x3e,0x41,0x49,0x49,0x7a,  //  G 
    0x7f,0x08,0x08,0x08,0x7f,  //  H 
    0x00,0x41,0x7f,0x41,0x00,  //  I 
    0x20,0x40,0x41,0x3f,0x01,  //  J 
    0x7f,0x08,0x14,0x22,0x41,  //  K 
    0x7f,0x40,0x40,0x40,0x40,  //  L 
    0x7f,0x02,0x0c,0x02,0x7f,  //  M 
    0x7f,0x04,0x08,0x10,0x7f,  //  N 
    0x3e,0x41,0x41,0x41,0x3e,  //  O 
    0x7f,0x09,0x09,0x09,0x06,  //  P       0x50 
    0x3e,0x41,0x51,0x21,0x5e,  //  Q 
    0x7f,0x09,0x19,0x29,0x46,  //  R 
    0x26,0x49,0x49,0x49,0x32,  //  S 
    0x01,0x01,0x7f,0x01,0x01,  //  T 
    0x3f,0x40,0x40,0x40,0x3f,  //  U 
    0x1f,0x20,0x40,0x20,0x1f,  //  V 
    0x3f,0x40,0x38,0x40,0x3f,  //  W 
    0x63,0x14,0x08,0x14,0x63,  //  X 
    0x07,0x08,0x70,0x08,0x07,  //  Y 
    0x61,0x51,0x49,0x45,0x43,  //  Z 
    0x00,0x7f,0x41,0x41,0x00,  //  [ ou 0x38,0x54,0x56,0x55,0x18, pour � 
    0x02,0x04,0x08,0x10,0x20,  //  \ 
    0x00,0x41,0x41,0x7f,0x00,  //  ] ou 0x38,0x55,0x56,0x54,0x18, pour � 
    0x04,0x02,0x01,0x02,0x04,  //  ^ ou 0x38,0x56,0x55,0x56,0x18, pour � 
    0x40,0x40,0x40,0x40,0x40,  //  _ 
    0x00,0x00,0x03,0x05,0x00,  //  `       0x60   ou 0x20,0x56,0x55,0x54,0x78, pour � 
    0x20,0x54,0x54,0x54,0x78,  //  a 
    0x7f,0x44,0x44,0x44,0x38,  //  b 
    0x38,0x44,0x44,0x44,0x44,  //  c 
    0x38,0x44,0x44,0x44,0x7f,  //  d 
    0x38,0x54,0x54,0x54,0x18,  //  e 
    0x04,0x04,0x7e,0x05,0x05,  //  f 
    0x08,0x54,0x54,0x54,0x3c,  //  g 
    0x7f,0x08,0x04,0x04,0x78,  //  h 
    0x00,0x44,0x7d,0x40,0x00,  //  i 
    0x20,0x40,0x44,0x3d,0x00,  //  j 
    0x7f,0x10,0x28,0x44,0x00,  //  k 
    0x00,0x41,0x7f,0x40,0x00,  //  l 
    0x7c,0x04,0x7c,0x04,0x78,  //  m 
    0x7c,0x08,0x04,0x04,0x78,  //  n 
    0x38,0x44,0x44,0x44,0x38,  //  o 
    0x7c,0x14,0x14,0x14,0x08,  //  p       0x70 
    0x08,0x14,0x14,0x14,0x7c,  //  q 
    0x7c,0x08,0x04,0x04,0x00,  //  r 
    0x48,0x54,0x54,0x54,0x24,  //  s 
    0x04,0x04,0x3f,0x44,0x44,  //  t 
    0x3c,0x40,0x40,0x20,0x7c,  //  u 
    0x1c,0x20,0x40,0x20,0x1c,  //  v 
    0x3c,0x40,0x30,0x40,0x3c,  //  w 
    0x44,0x28,0x10,0x28,0x44,  //  x 
    0x0c,0x50,0x50,0x50,0x3c,  //  y 
    0x44,0x64,0x54,0x4c,0x44,  //  z 
    0x08,0x36,0x41,0x41,0x00,  //  { 
    0x00,0x00,0x77,0x00,0x00,  //  | 
    0x00,0x41,0x41,0x36,0x08,  //  } 
    0x08,0x04,0x08,0x10,0x08,  //  ~ 
    0x08,0x08,0x2a,0x1c,0x08,  //  -> 
    0x14,0x7e,0x95,0x95,0x42   //  �       0x80 
};

/* Police7x8 (char 0x20 a 0x80)                       */
/* Format :  0x7c,0x7e,0x13,0x13,0x7e,0x7c,0x00  =  A */
/*           . # # # # # ' '      0x7c                */
/*           . # # # # # # '      0x7e                */
/*           . ' ' # ' ' # #      0x13                */
/*           . ' ' # ' ' # #      0x13                */
/*           . # # # # # # '      0x7e                */
/*           . # # # # # ' '      0x7c                */
/*           . ' ' ' ' ' ' '      0x00                */
/* Un octet est une colonne du caractere              */
const unsigned short Police7x8[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  Espace  0x20
    0x00,0x06,0x5f,0x5f,0x06,0x00,0x00,  //  !
    0x00,0x07,0x07,0x00,0x07,0x07,0x00,  //  "
    0x14,0x7f,0x7f,0x14,0x7f,0x7f,0x14,  //  #
    0x24,0x2e,0x6b,0x6b,0x3a,0x12,0x00,  //  $
    0x46,0x66,0x30,0x18,0x0c,0x66,0x62,  //  %
    0x30,0x7a,0x4f,0x5d,0x37,0x7a,0x48,  //  &
    0x04,0x07,0x03,0x00,0x00,0x00,0x00,  //  '
    0x00,0x1c,0x3e,0x63,0x41,0x00,0x00,  //  (
    0x00,0x41,0x63,0x3e,0x1c,0x00,0x00,  //  )
    0x08,0x2a,0x3e,0x1c,0x1c,0x3e,0x2a,  //  *
    0x08,0x08,0x3e,0x3e,0x08,0x08,0x00,  //  +
    0x00,0x80,0xe0,0x60,0x00,0x00,0x00,  //  ,
    0x08,0x08,0x08,0x08,0x08,0x08,0x00,  //  -
    0x00,0x00,0x60,0x60,0x00,0x00,0x00,  //  .
    0x60,0x30,0x18,0x0c,0x06,0x03,0x01,  //  /
    0x3e,0x7f,0x71,0x59,0x4d,0x7f,0x3e,  //  0       0x30
    0x40,0x42,0x7f,0x7f,0x40,0x40,0x00,  //  1
    0x62,0x73,0x59,0x49,0x6f,0x66,0x00,  //  2
    0x22,0x63,0x49,0x49,0x7f,0x36,0x00,  //  3
    0x18,0x1c,0x16,0x53,0x7f,0x7f,0x50,  //  4
    0x27,0x67,0x45,0x45,0x7d,0x39,0x00,  //  5
    0x3c,0x7e,0x4b,0x49,0x79,0x30,0x00,  //  6
    0x03,0x03,0x71,0x79,0x0f,0x07,0x00,  //  7
    0x36,0x7f,0x49,0x49,0x7f,0x36,0x00,  //  8
    0x06,0x4f,0x49,0x69,0x3f,0x1e,0x00,  //  9
    0x00,0x00,0x66,0x66,0x00,0x00,0x00,  //  :
    0x00,0x80,0xe6,0x66,0x00,0x00,0x00,  //  ;
    0x08,0x1c,0x36,0x63,0x41,0x00,0x00,  //  <
    0x24,0x24,0x24,0x24,0x24,0x24,0x00,  //  =
    0x00,0x41,0x63,0x36,0x1c,0x08,0x00,  //  >
    0x02,0x03,0x51,0x59,0x0f,0x06,0x00,  //  ?
    0x3e,0x7f,0x41,0x5d,0x5d,0x1f,0x1e,  //  @       0x40
    0x7c,0x7e,0x13,0x13,0x7e,0x7c,0x00,  //  A
    0x41,0x7f,0x7f,0x49,0x49,0x7f,0x36,  //  B
    0x1c,0x3e,0x63,0x41,0x41,0x63,0x22,  //  C
    0x41,0x7f,0x7f,0x41,0x63,0x3e,0x1c,  //  D
    0x41,0x7f,0x7f,0x49,0x5d,0x41,0x63,  //  E
    0x41,0x7f,0x7f,0x49,0x1d,0x01,0x03,  //  F
    0x1c,0x3e,0x63,0x41,0x51,0x73,0x72,  //  G
    0x7f,0x7f,0x08,0x08,0x7f,0x7f,0x00,  //  H
    0x00,0x41,0x7f,0x7f,0x41,0x00,0x00,  //  I
    0x30,0x70,0x40,0x41,0x7f,0x3f,0x01,  //  J
    0x41,0x7f,0x7f,0x08,0x1c,0x77,0x63,  //  K
    0x41,0x7f,0x7f,0x41,0x40,0x60,0x70,  //  L
    0x7f,0x7f,0x0e,0x1c,0x0e,0x7f,0x7f,  //  M
    0x7f,0x7f,0x06,0x0c,0x18,0x7f,0x7f,  //  N
    0x1c,0x3e,0x63,0x41,0x63,0x3e,0x1c,  //  O
    0x41,0x7f,0x7f,0x49,0x09,0x0f,0x06,  //  P       0x50
    0x1e,0x3f,0x21,0x71,0x7f,0x5e,0x00,  //  Q
    0x41,0x7f,0x7f,0x09,0x19,0x7f,0x66,  //  R
    0x26,0x6f,0x4d,0x59,0x73,0x32,0x00,  //  S
    0x03,0x41,0x7f,0x7f,0x41,0x03,0x00,  //  T
    0x7f,0x7f,0x40,0x40,0x7f,0x7f,0x00,  //  U
    0x1f,0x3f,0x60,0x60,0x3f,0x1f,0x00,  //  V
    0x7f,0x7f,0x30,0x18,0x30,0x7f,0x7f,  //  W
    0x43,0x67,0x3c,0x18,0x3c,0x67,0x43,  //  X
    0x07,0x4f,0x78,0x78,0x4f,0x07,0x00,  //  Y
    0x47,0x63,0x71,0x59,0x4d,0x67,0x73,  //  Z
    0x00,0x7f,0x7f,0x41,0x41,0x00,0x00,  //  [
    0x01,0x03,0x06,0x0c,0x18,0x30,0x60,  //  \
    0x00,0x41,0x41,0x7f,0x7f,0x00,0x00,  //  ]
    0x08,0x0c,0x06,0x03,0x06,0x0c,0x08,  //  ^
    0x80,0x80,0x80,0x80,0x80,0x80,0x80,  //  _
    0x00,0x00,0x03,0x07,0x04,0x00,0x00,  //  `       0x60
    0x20,0x74,0x54,0x54,0x3c,0x78,0x40,  //  a
    0x41,0x7f,0x3f,0x48,0x48,0x78,0x30,  //  b
    0x38,0x7c,0x44,0x44,0x6c,0x28,0x00,  //  c
    0x30,0x78,0x48,0x49,0x3f,0x7f,0x40,  //  d
    0x38,0x7c,0x54,0x54,0x5c,0x18,0x00,  //  e
    0x48,0x7e,0x7f,0x49,0x03,0x02,0x00,  //  f
    0x38,0xbc,0xa4,0xa4,0xfc,0x78,0x00,  //  g
    0x41,0x7f,0x7f,0x08,0x04,0x7c,0x78,  //  h
    0x00,0x44,0x7d,0x7d,0x40,0x00,0x00,  //  i
    0x60,0xe0,0x80,0x80,0xfd,0x7d,0x00,  //  j
    0x41,0x7f,0x7f,0x10,0x38,0x6c,0x44,  //  k
    0x00,0x41,0x7f,0x7f,0x40,0x00,0x00,  //  l
    0x78,0x7c,0x1c,0x38,0x1c,0x7c,0x78,  //  m
    0x7c,0x7c,0x04,0x04,0x7c,0x78,0x00,  //  n
    0x38,0x7c,0x44,0x44,0x7c,0x38,0x00,  //  o
    0x00,0xfc,0xfc,0xa4,0x24,0x3c,0x18,  //  p       0x70
    0x18,0x3c,0x24,0xa4,0xf8,0xfc,0x84,  //  q
    0x44,0x7c,0x78,0x4c,0x04,0x1c,0x18,  //  r
    0x48,0x5c,0x54,0x54,0x74,0x24,0x00,  //  s
    0x00,0x04,0x3e,0x7f,0x44,0x24,0x00,  //  t
    0x3c,0x7c,0x40,0x40,0x3c,0x7c,0x40,  //  u
    0x1c,0x3c,0x60,0x60,0x3c,0x1c,0x00,  //  v
    0x3c,0x7c,0x70,0x38,0x70,0x7c,0x3c,  //  w
    0x44,0x6c,0x38,0x10,0x38,0x6c,0x44,  //  x
    0x3c,0xbc,0xa0,0xa0,0xfc,0x7c,0x00,  //  y
    0x4c,0x64,0x74,0x5c,0x4c,0x64,0x00,  //  z
    0x08,0x08,0x3e,0x77,0x41,0x41,0x00,  //  {
    0x00,0x00,0x00,0x77,0x77,0x00,0x00,  //  |
    0x41,0x41,0x77,0x3e,0x08,0x08,0x00,  //  }
    0x02,0x03,0x01,0x03,0x02,0x03,0x01,  //  ~
    0xff,0x81,0x81,0x81,0x81,0x81,0xff,  //  
    0x00,0x14,0x7f,0x95,0x95,0x81,0x42   //  �       0x80
};

/* Police4x7V (char 0x20 a 0x80)                      */
/* Format :  0x00,0x02,0x05,0x07,0x05,0x05,0x00  =  A */
/*           . . . . ' ' ' '      0x00                */
/*           . . . . ' ' # '      0x02                */
/*           . . . . ' # ' #      0x05                */
/*           . . . . ' # # #      0x07                */
/*           . . . . ' # ' #      0x05                */
/*           . . . . ' # ' #      0x05                */
/*           . . . . ' ' ' '      0x00                */
/* Un octet est une ligne du caractere                */
/* Donc, les caracteres sont couches                  */
const unsigned short Police4x7V[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  Espace  0x20
    0x00,0x02,0x02,0x02,0x00,0x02,0x00,  //  ! 
    0x00,0x05,0x05,0x00,0x00,0x00,0x00,  //  " 
    0x00,0x05,0x07,0x05,0x07,0x05,0x00,  //  � 
    0x02,0x03,0x06,0x07,0x03,0x06,0x02,  //  $ 
    0x00,0x04,0x01,0x02,0x04,0x01,0x00,  //  % 
    0x00,0x02,0x05,0x02,0x05,0x03,0x00,  //  & 
    0x00,0x02,0x02,0x00,0x00,0x00,0x00,  //  ' 
    0x00,0x01,0x02,0x02,0x02,0x01,0x00,  //  ( 
    0x00,0x04,0x02,0x02,0x02,0x04,0x00,  //  ) 
    0x00,0x00,0x05,0x02,0x05,0x00,0x00,  //  * 
    0x00,0x00,0x02,0x07,0x02,0x00,0x00,  //  + 
    0x00,0x00,0x00,0x00,0x00,0x02,0x04,  //  , 
    0x00,0x00,0x00,0x07,0x00,0x00,0x00,  //  - 
    0x00,0x00,0x00,0x00,0x00,0x02,0x00,  //  . 
    0x00,0x00,0x01,0x02,0x04,0x00,0x00,  //  / 
    0x00,0x07,0x05,0x05,0x05,0x07,0x00,  //  0       0x30
    0x00,0x02,0x06,0x02,0x02,0x07,0x00,  //  1 
    0x00,0x07,0x01,0x07,0x04,0x07,0x00,  //  2
    0x00,0x07,0x01,0x07,0x01,0x07,0x00,  //  3 
    0x00,0x05,0x05,0x07,0x01,0x01,0x00,  //  4 
    0x00,0x07,0x04,0x07,0x01,0x07,0x00,  //  5 
    0x00,0x07,0x04,0x07,0x05,0x07,0x00,  //  6 
    0x00,0x07,0x01,0x01,0x01,0x01,0x00,  //  7 
    0x00,0x07,0x05,0x07,0x05,0x07,0x00,  //  8 
    0x00,0x07,0x05,0x07,0x01,0x01,0x00,  //  9 
    0x00,0x00,0x02,0x00,0x02,0x00,0x00,  //  : 
    0x00,0x00,0x02,0x00,0x00,0x02,0x04,  //  ; 
    0x00,0x01,0x02,0x04,0x02,0x01,0x00,  //  < 
    0x00,0x00,0x07,0x00,0x07,0x00,0x00,  //  = 
    0x00,0x04,0x02,0x01,0x02,0x04,0x00,  //  > 
    0x00,0x06,0x01,0x02,0x00,0x02,0x00,  //  ? 
    0x00,0x02,0x05,0x05,0x04,0x03,0x00,  //  @       0x40
    0x00,0x02,0x05,0x07,0x05,0x05,0x00,  //  A 
    0x00,0x06,0x05,0x06,0x05,0x06,0x00,  //  B 
    0x00,0x03,0x04,0x04,0x04,0x03,0x00,  //  C 
    0x00,0x06,0x05,0x05,0x05,0x06,0x00,  //  D 
    0x00,0x07,0x04,0x06,0x04,0x07,0x00,  //  E 
    0x00,0x07,0x04,0x06,0x04,0x04,0x00,  //  F 
    0x00,0x03,0x04,0x05,0x05,0x03,0x00,  //  G 
    0x00,0x05,0x05,0x07,0x05,0x05,0x00,  //  H 
    0x00,0x07,0x02,0x02,0x02,0x07,0x00,  //  I 
    0x00,0x01,0x01,0x01,0x05,0x02,0x00,  //  J 
    0x00,0x05,0x05,0x06,0x05,0x05,0x00,  //  K 
    0x00,0x04,0x04,0x04,0x04,0x07,0x00,  //  L 
    0x00,0x07,0x07,0x07,0x05,0x05,0x00,  //  M 
    0x00,0x05,0x07,0x07,0x07,0x05,0x00,  //  N 
    0x00,0x02,0x05,0x05,0x05,0x02,0x00,  //  O 
    0x00,0x06,0x05,0x06,0x04,0x04,0x00,  //  P       0x50
    0x00,0x02,0x05,0x05,0x07,0x03,0x00,  //  Q 
    0x00,0x06,0x05,0x06,0x05,0x05,0x00,  //  R 
    0x00,0x03,0x04,0x02,0x01,0x06,0x00,  //  S 
    0x00,0x07,0x02,0x02,0x02,0x02,0x00,  //  T 
    0x00,0x05,0x05,0x05,0x05,0x07,0x00,  //  U 
    0x00,0x05,0x05,0x05,0x05,0x02,0x00,  //  V 
    0x00,0x05,0x05,0x07,0x07,0x05,0x00,  //  W 
    0x00,0x05,0x05,0x02,0x05,0x05,0x00,  //  X 
    0x00,0x05,0x05,0x02,0x02,0x02,0x00,  //  Y 
    0x00,0x07,0x01,0x02,0x04,0x07,0x00,  //  Z 
    0x00,0x03,0x02,0x02,0x02,0x03,0x00,  //  [ 
    0x00,0x00,0x04,0x02,0x01,0x00,0x00,  //  \ 
    0x00,0x06,0x02,0x02,0x02,0x06,0x00,  //  ] 
    0x02,0x05,0x00,0x00,0x00,0x00,0x00,  //  ^ 
    0x00,0x00,0x00,0x00,0x00,0x00,0x0f,  //  _ 
    0x00,0x04,0x02,0x00,0x00,0x00,0x00,  //  `       0x60
    0x00,0x00,0x03,0x05,0x05,0x03,0x00,  //  a 
    0x00,0x04,0x06,0x05,0x05,0x06,0x00,  //  b 
    0x00,0x00,0x03,0x04,0x04,0x03,0x00,  //  c 
    0x00,0x01,0x03,0x05,0x05,0x03,0x00,  //  d 
    0x00,0x00,0x03,0x05,0x06,0x03,0x00,  //  e 
    0x00,0x01,0x02,0x07,0x02,0x02,0x00,  //  f 
    0x00,0x00,0x03,0x05,0x03,0x01,0x02,  //  g 
    0x00,0x04,0x06,0x05,0x05,0x05,0x00,  //  h 
    0x00,0x02,0x00,0x02,0x02,0x02,0x00,  //  i 
    0x00,0x02,0x00,0x02,0x02,0x02,0x04,  //  j 
    0x00,0x04,0x04,0x05,0x06,0x05,0x00,  //  k 
    0x00,0x02,0x02,0x02,0x02,0x02,0x00,  //  l 
    0x00,0x00,0x07,0x07,0x07,0x05,0x00,  //  m 
    0x00,0x00,0x06,0x05,0x05,0x05,0x00,  //  n 
    0x00,0x00,0x02,0x05,0x05,0x02,0x00,  //  o 
    0x00,0x00,0x06,0x05,0x05,0x06,0x04,  //  p       0x70
    0x00,0x00,0x03,0x05,0x05,0x03,0x01,  //  q 
    0x00,0x00,0x06,0x05,0x04,0x04,0x00,  //  r 
    0x00,0x00,0x03,0x06,0x03,0x06,0x00,  //  s 
    0x00,0x02,0x07,0x02,0x02,0x01,0x00,  //  t 
    0x00,0x00,0x05,0x05,0x05,0x07,0x00,  //  u 
    0x00,0x00,0x05,0x05,0x05,0x02,0x00,  //  v 
    0x00,0x00,0x05,0x05,0x07,0x05,0x00,  //  w 
    0x00,0x00,0x05,0x02,0x02,0x05,0x00,  //  x 
    0x00,0x00,0x05,0x05,0x07,0x01,0x06,  //  y 
    0x00,0x00,0x07,0x03,0x06,0x07,0x00,  //  z 
    0x00,0x03,0x02,0x06,0x02,0x03,0x00,  //  { 
    0x00,0x02,0x02,0x02,0x02,0x02,0x00,  //  | 
    0x00,0x06,0x02,0x03,0x02,0x06,0x00,  //  } 
    0x03,0x06,0x00,0x00,0x00,0x00,0x00,  //  " 
    0x00,0x0f,0x09,0x09,0x09,0x0f,0x00,  //  
    0x08,0x08,0x08,0x08,0x08,0x08,0x08   //  |       0x80
};

/* Police8x8V (char 0x20 a 0x80)                           */
/* Format :  0x1c,0x22,0x22,0x3e,0x22,0x22,0x22,0x00  =  A */
/*           ' ' ' # # # ' '      0x1c                     */
/*           ' ' # ' ' ' # '      0x22                     */
/*           ' ' # ' ' ' # '      0x22                     */
/*           ' ' # # # # # '      0x3e                     */
/*           ' ' # ' ' ' # '      0x22                     */
/*           ' ' # ' ' ' # '      0x22                     */
/*           ' ' # ' ' ' # '      0x22                     */
/*           ' ' ' ' ' ' ' '      0x00                     */
/* Un octet est une ligne du caractere                     */
/* Donc, les caracteres sont couches                       */
const unsigned short Police8x8V[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  Espace  0x20 
    0x08,0x08,0x08,0x08,0x08,0x00,0x08,0x00,  //  !
    0x14,0x14,0x00,0x00,0x00,0x00,0x00,0x00,  //  "
    0x14,0x14,0x7f,0x14,0x7f,0x14,0x14,0x00,  //  #
    0x08,0x1e,0x28,0x1c,0x0a,0x3c,0x08,0x00,  //  $
    0x00,0x32,0x34,0x08,0x16,0x26,0x00,0x00,  //  %
    0x18,0x28,0x10,0x28,0x46,0x44,0x3a,0x00,  //  &
    0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,  //  '
    0x04,0x08,0x10,0x10,0x10,0x08,0x04,0x00,  //  (
    0x10,0x08,0x04,0x04,0x04,0x08,0x10,0x00,  //  )
    0x08,0x49,0x2a,0x1c,0x2a,0x49,0x08,0x00,  //  *
    0x08,0x08,0x08,0x7f,0x08,0x08,0x08,0x00,  //  +
    0x00,0x00,0x00,0x00,0x0c,0x0c,0x04,0x08,  //  ,
    0x00,0x00,0x00,0x7f,0x00,0x00,0x00,0x00,  //  -
    0x00,0x00,0x00,0x00,0x00,0x0c,0x0c,0x00,  //  .
    0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x00,  //  /
    0x1c,0x22,0x22,0x2a,0x22,0x22,0x1c,0x00,  //  0       0x30
    0x08,0x18,0x08,0x08,0x08,0x08,0x1c,0x00,  //  1
    0x1c,0x22,0x02,0x04,0x08,0x10,0x3e,0x00,  //  2
    0x1c,0x22,0x02,0x0c,0x02,0x22,0x1c,0x00,  //  3
    0x0c,0x14,0x24,0x3e,0x04,0x04,0x0e,0x00,  //  4
    0x3e,0x20,0x20,0x3c,0x02,0x22,0x1c,0x00,  //  5
    0x1c,0x22,0x20,0x3c,0x22,0x22,0x1c,0x00,  //  6
    0x3e,0x02,0x04,0x08,0x10,0x10,0x10,0x00,  //  7
    0x1c,0x22,0x22,0x1c,0x22,0x22,0x1c,0x00,  //  8
    0x1c,0x22,0x22,0x1e,0x02,0x22,0x1c,0x00,  //  9
    0x00,0x0c,0x0c,0x00,0x0c,0x0c,0x00,0x00,  //  :
    0x00,0x0c,0x0c,0x00,0x0c,0x0c,0x04,0x08,  //  ;
    0x04,0x08,0x10,0x20,0x10,0x08,0x04,0x00,  //  <
    0x00,0x00,0x7f,0x00,0x7f,0x00,0x00,0x00,  //  =
    0x20,0x10,0x08,0x04,0x08,0x10,0x20,0x00,  //  >
    0x1c,0x22,0x02,0x04,0x08,0x00,0x08,0x00,  //  ?
    0x1c,0x22,0x2e,0x2a,0x2e,0x20,0x1c,0x00,  //  @       0x40
    0x1c,0x22,0x22,0x3e,0x22,0x22,0x22,0x00,  //  A
    0x3c,0x22,0x22,0x3c,0x22,0x22,0x3c,0x00,  //  B
    0x1c,0x22,0x20,0x20,0x20,0x22,0x1c,0x00,  //  C
    0x3c,0x22,0x22,0x22,0x22,0x22,0x3c,0x00,  //  D
    0x3e,0x20,0x20,0x3c,0x20,0x20,0x3e,0x00,  //  E
    0x3e,0x20,0x20,0x3e,0x20,0x20,0x20,0x00,  //  F
    0x1c,0x22,0x20,0x2e,0x22,0x22,0x1c,0x00,  //  G
    0x22,0x22,0x22,0x3e,0x22,0x22,0x22,0x00,  //  H
    0x1c,0x08,0x08,0x08,0x08,0x08,0x1c,0x00,  //  I
    0x0e,0x04,0x04,0x04,0x24,0x24,0x18,0x00,  //  J
    0x22,0x22,0x24,0x38,0x24,0x22,0x22,0x00,  //  K
    0x10,0x10,0x10,0x10,0x10,0x10,0x1e,0x00,  //  L
    0x41,0x63,0x55,0x49,0x41,0x41,0x41,0x00,  //  M
    0x22,0x32,0x2a,0x2a,0x26,0x22,0x22,0x00,  //  N
    0x1c,0x22,0x22,0x22,0x22,0x22,0x1c,0x00,  //  O
    0x1c,0x12,0x12,0x1c,0x10,0x10,0x10,0x00,  //  P       0x50
    0x1c,0x22,0x22,0x22,0x22,0x22,0x1c,0x06,  //  Q
    0x3c,0x22,0x22,0x3c,0x28,0x24,0x22,0x00,  //  R
    0x1c,0x22,0x20,0x1c,0x02,0x22,0x1c,0x00,  //  S
    0x3e,0x08,0x08,0x08,0x08,0x08,0x08,0x00,  //  T
    0x22,0x22,0x22,0x22,0x22,0x22,0x1c,0x00,  //  U
    0x22,0x22,0x22,0x14,0x14,0x08,0x08,0x00,  //  V
    0x41,0x41,0x41,0x2a,0x2a,0x14,0x14,0x00,  //  W
    0x22,0x22,0x14,0x08,0x14,0x22,0x22,0x00,  //  X
    0x22,0x22,0x14,0x08,0x08,0x08,0x08,0x00,  //  Y
    0x3e,0x02,0x04,0x08,0x10,0x20,0x3e,0x00,  //  Z
    0x1c,0x10,0x10,0x10,0x10,0x10,0x1c,0x00,  //  [
    0x40,0x20,0x10,0x08,0x04,0x02,0x01,0x00,  //  \
    0x1c,0x04,0x04,0x04,0x04,0x04,0x1c,0x00,  //  ]
    0x08,0x14,0x22,0x00,0x00,0x00,0x00,0x00,  //  ^
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,  //  _
    0x10,0x08,0x00,0x00,0x00,0x00,0x00,0x00,  //  `       0x60
    0x00,0x1c,0x02,0x1e,0x22,0x22,0x1d,0x00,  //  a
    0x10,0x10,0x1c,0x12,0x12,0x12,0x2c,0x00,  //  b
    0x00,0x00,0x1c,0x20,0x20,0x20,0x1c,0x00,  //  c
    0x02,0x02,0x0e,0x12,0x12,0x12,0x0d,0x00,  //  d
    0x00,0x00,0x1c,0x22,0x3e,0x20,0x1c,0x00,  //  e
    0x0c,0x12,0x10,0x38,0x10,0x10,0x10,0x00,  //  f
    0x00,0x00,0x1d,0x22,0x22,0x1e,0x02,0x1c,  //  g
    0x20,0x20,0x2c,0x32,0x22,0x22,0x22,0x00,  //  h
    0x00,0x08,0x00,0x08,0x08,0x08,0x08,0x00,  //  i
    0x00,0x08,0x00,0x08,0x08,0x08,0x08,0x30,  //  j
    0x20,0x20,0x24,0x28,0x30,0x28,0x24,0x00,  //  k
    0x18,0x08,0x08,0x08,0x08,0x08,0x08,0x00,  //  l
    0x00,0x00,0xb6,0x49,0x49,0x41,0x41,0x00,  //  m
    0x00,0x00,0x2c,0x12,0x12,0x12,0x12,0x00,  //  n
    0x00,0x00,0x1c,0x22,0x22,0x22,0x1c,0x00,  //  o
    0x00,0x00,0x2c,0x12,0x12,0x1c,0x10,0x10,  //  p       0x70
    0x00,0x00,0x1a,0x24,0x24,0x1c,0x04,0x04,  //  q
    0x00,0x00,0x2c,0x30,0x20,0x20,0x20,0x00,  //  r
    0x00,0x00,0x1c,0x20,0x18,0x04,0x38,0x00,  //  s
    0x00,0x08,0x1c,0x08,0x08,0x08,0x08,0x00,  //  t
    0x00,0x00,0x24,0x24,0x24,0x24,0x1a,0x00,  //  u
    0x00,0x00,0x22,0x22,0x22,0x14,0x08,0x00,  //  v
    0x00,0x00,0x41,0x41,0x49,0x55,0x22,0x00,  //  w
    0x00,0x00,0x22,0x14,0x08,0x14,0x22,0x00,  //  x
    0x00,0x00,0x12,0x12,0x12,0x0e,0x02,0x1c,  //  y
    0x00,0x00,0x3c,0x04,0x08,0x10,0x3c,0x00,  //  z
    0x0c,0x10,0x10,0x20,0x10,0x10,0x0c,0x00,  //  {
    0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00,  //  |
    0x30,0x08,0x08,0x04,0x08,0x08,0x30,0x00,  //  }
    0x00,0x00,0x30,0x49,0x06,0x00,0x00,0x00,  //  ~
    0x3e,0x22,0x22,0x22,0x22,0x22,0x3e,0x00,  //  
    0x00,0x00,0x14,0x7f,0x95,0x95,0x81,0x42   //  �       0x80
};
