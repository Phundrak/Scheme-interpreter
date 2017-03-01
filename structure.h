//
// Created by Drak-pa on 2017/03/01.
//

#ifndef SCHEME_INTERPRETER_STRUCTURE_H
#define SCHEME_INTERPRETER_STRUCTURE_H

#include "globalIncludes.h"

typedef enum {node,feuille,nul} NodeType;
typedef enum {num,nil,symbol,string,boolean} FeuilleType;

struct CharNode{
  char key;
  struct CharNode* next;
};
typedef struct CharNode* String_t;

typedef enum{false,true} bool;

typedef struct{
  FeuilleType fType; // type de la feuille
  
  String_t str; // valeur brute sous forme de String_t
  bool bVal; // valeur booleenne (false = 0, true = 1)
  float f; // valeur float du rationnel
  struct{
    int num; // numérateur de la fraction du
    int den; // denominateur
  };
} Feuille;
typedef Feuille* Feuille_t;

struct Node{
  NodeType nType; // type du noeud
  Feuille_t elem; // pointeur vers les valeurs en tant que feuille (NULL si nType==nul || nType==node)
  struct Node* g; // pointeur vers le fils gauche (NULL si nType==nul || nType==feuille)
  struct Node* d; // pointeur vers le fils droit (NULL si nType==nul || nType==feuille)
};
typedef struct Node* Node_t;
typedef Node_t List;


#endif //SCHEME_INTERPRETER_STRUCTURE_H
