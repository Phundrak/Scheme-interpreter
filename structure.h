#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "stdafx.h"

	  /************************************************
	   *                  Structures
	   ***********************************************/

typedef enum{False, True} bool;
typedef enum{Node,Leaf,Nul} nType;
typedef enum{Bool,Pair,List,Num,Char,String,Proc} fType;

struct CharNode{
  char key;
  struct CharNode *next;
};
typedef struct CharNode* String_t;

struct Node{
  nType ntype;
  fType ftype; // type de la valeur
  union{
    char c; // char seul
    bool b; // valeur booleenne (False = 0, True = 1)
    float f; // valeur flottante
    String_t s; // pointeur vers un string
  };
  struct Node* fg; // pointeur vers le fils gauche
  struct Node* fd; // pointeur vers le fils droit
};
typedef struct Node Node_t;
typedef struct Node* pNode;


          /************************************************
	   *                  Functions
	   ***********************************************/

// cree un noeud vierge de type Nul
pNode newEmptyNode(void);
// cree un noeud ayant pour enfants les deux arguments
// equivalent du cons() de primitives.h
pNode newNode(pNode,pNode);
// cree une nouvelle feuille a partir d'un String_t
pNode newLeaf(String_t);
// renvoie un pointeur vers une copie exacte du noeud
// passe en argument (ne copie pas ses elements enfants)
pNode copyNode(pNode);
// renvoie un pointeur vers une copie de l'arbre passe
// en argument
pNode copyTree(pNode);
// cree un arbre representant une paire composee des
// deux arguments
pNode newPair(pNode, pNode);

// methode pour supprimer de facon securisee un arbre
void deleteNode(pNode);
// methode pour supprimer de facon securisee un String_t
void deleteString(String_t);

// cree un nouveau pointeur vers un struct CharNode vierge
String_t newString(void);

// transforme un arbre en un noeud avec pour fils gauche
// la valeur de l'arbre et pour fils droit un noeud vide
pNode eval(pNode);

#endif
