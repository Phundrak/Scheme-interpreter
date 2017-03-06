//
// Created by drak-pa on 03/03/17.
//

#ifndef SCHEME_INTERPRETER_GENERATION_H
#define SCHEME_INTERPRETER_GENERATION_H

#include "globalIncludes.h"
#include "structure.h"
#include "evaluation.h"

// cree une feuille pure avec uniquement le membre str initialise sur NULL
Feuille_t createPureLeaf(void);

// cree une feuille dont l'information est deduite de l'argument String_t
Feuille_t createElemLeaf(String_t);

// renvoie un pointeur vers une copie de la feuille passee en argument
Feuille_t copyLeaf(Feuille_t);

// cree un noeud Nul
Node_t createNulNode(void);

// cree un noeud vide ayant pour role Noeud
Node_t createEmptyNode(void);

// cree un noeud ayant pour role une feuille
Node_t createLeaf(String_t);

// renvoie une copie de l’argument
Node_t copyNodeLeaf(Node_t);

// renvoie une copie de l'arbre entier descendant du noeud passe en argument
Node_t copyNode(Node_t);

// cree un noeud ayant pour fils gauche l'argument Feuille_t et pour fils droit
// un noeud Nul
Node_t createElemNode(Feuille_t);

// create a pair node with tw
Node_t createPair_f(Feuille_t, Feuille_t);

// cree un noeud ayant pour fils gauche le premier argument Feuille_t et pour
// fils droit le second argument Feuille_t
Node_t createNode(Node_t, Node_t);

// cree un noeud ayant pour fils gauche une feuille de role Pair, et pour fils droit
// les deux elements de la pair (le premier le fils gauche du fils droit du noeud, le
// second le fils gauche du fils droit du fils droit du noeud)
Node_t createPair(Feuille_t, Feuille_t);

// cree une noeud avec pour fils gauche une feuille de role Vecteur, et pour fils
// droit un noeud Nul
Node_t createEmptyVector(void);


// supprime de facon safe un pointeur vers un noeud, en supprimant egalement ses
// pointeurs
void deleteNode(Node_t);

#endif //SCHEME_INTERPRETER_GENERATION_H
