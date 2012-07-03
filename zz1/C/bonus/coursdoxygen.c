/*------------------------------------*/
/*Maxime ESCOURBIAC         */
/*Fiche rappel doxygen           */
/*------------------------------------*/

Pour une en-tete de fichier exemple:

/**
 * \file main.c
 * \brief Programme de tests.
 * \author Franck.H
 * \version 0.1
 * \date 11 septembre 2007
 *
 * Programme de test pour l'objet de gestion des cha�nes de caract�res Str_t.
 *
 */

 documentation d'une fonction
 
/**
 * \fn static Str_t * str_new (const char * sz)
 * \brief Fonction de cr�ation d'une nouvelle instance d'un objet Str_t.
 *
 * \param sz Cha�ne � stocker dans l'objet Str_t, ne peut �tre NULL.
 * \return Instance nouvellement allou�e d'un objet de type Str_t ou NULL.
 */

 
 documentation d'une structure/union
 
 /**
 * \struct Str_t
 * \brief Objet cha�ne de caract�res.
 *
 * Str_t est un petit objet de gestion de cha�nes de caract�res. 
 * La cha�ne se termine obligatoirement par un z�ro de fin et l'objet 
 * connait la taille de cha�ne contient !
 */

 on peut aussi commenter chaque elements de la structure
 
 int k;  /*!< entier de boucle */
 
 
 Pour un enum 
 
 /**
 * \enum Str_err_e
 * \brief Constantes d'erreurs.
 *
 * Str_err_e est une s�rie de constantes pr�d�finie pour diverses futures 
 * fonctions de l'objet Str_t.
 */
 