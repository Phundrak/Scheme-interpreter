
//
// Created by Drak-pa on 2017/03/01.
//

#ifndef SCHEME_INTERPRETER_STRUCTURE_H
#define SCHEME_INTERPRETER_STRUCTURE_H

#include "globalIncludes.h"

/********************************************************************************
 *
 * Data Structure
 *
 *******************************************************************************/

typedef enum{False,True} bool;
typedef enum {Noeud,Feuille,Nul} NodeType;
typedef enum {Boolean,Pair,Vector,Symbol,Number,Character,String,Procedure} FeuilleType;

/*
 * Les types pair indiquent qu'il n'y a normalement que deux feuilles trouvables
 * dans le fils droit du noeud parent de cette feuille. Si c'est faux, alors on a
 * une erreur.
 * Les types vecteurs indiquent que les elements contenus dans le fils droit du
 * noeud parent de cette feuille constituent les elements d'une liste.
 */

struct CharNode{
  char key;
  struct CharNode* next;
};
typedef struct CharNode* String_t;


struct Leaf{
  FeuilleType fType; // type de la feuille
  String_t str; // valeur brute sous forme de String_t
  union{
    char c; // valeur de la feuille s'ill s'agit d'un char
    bool b; // valeur booleenne (false = 0, true = 1)
    float f; // valeur float du rationnel
    int num; // DEPRECATED, numerateur de la fraction du rationnel
  };
  int den; // DEPRECATED, denominateur de la fraction du rationnel
  // le membre functPtr ne doit etre utilise que si la feuille est une procedure
};
typedef struct Leaf Feuil;
typedef Feuil* Feuille_t;

struct Node{
  NodeType nType; // type du noeud
  Feuille_t elem; // pointeur vers les valeurs en tant que feuille (NULL si nType==nul || nType==node)
  struct Node* g; // pointeur vers le fils gauche (NULL si nType==nul || nType==feuille)
  struct Node* d; // pointeur vers le fils droit (NULL si nType==nul || nType==feuille)
};
typedef struct Node* Node_t;
typedef Node_t List;

/********************************************************************************
 *
 * Functions
 *
 *******************************************************************************/



#endif //SCHEME_INTERPRETER_STRUCTURE_H
