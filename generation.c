//
// Created by drak-pa on 03/03/17.
//

#include "generation.h"


Feuille_t createPureLeaf(void){
  Feuille_t leaf = malloc(sizeof(struct Leaf));
  leaf->str = NULL;

  return leaf;
}

Feuille_t createElemLeaf(String_t str){
  Feuille_t leaf = createPureLeaf();
  leaf->str = str;
  leaf->f = 0;
  leaf->num = 0;
  leaf->den = 1;

  if(True == strIsNum(str)) { // si str represente un nombre, on initialise les membres associes
    leaf->fType = Number;
    leaf->f = strToFloat(str);
  } else if(True == strIsBool(str)){ // si le string vaut "#f" ou "#t" on l'interpretera comme etant une valeur booleenne
    leaf->fType = Boolean;
    leaf->b = strToBool(str);
  } else if(True == strIsChar(str)){ // si un seul caractere non numeral est detecte, alors on concluera qu'il s'agit d'un char et sera stocke ainsi
    leaf->fType = Character;
    leaf->c = str->key;
  } else if(True == strIsString(str)) { // sinon on en deduit qu'il s'agit d'un string
    leaf->fType = String;
  } else {
    return NULL; // erreur, string mal formate
  }

  // TODO: ajouter la possibilite ou le string designe une variable ou une fonction

  return leaf;
}

Feuille_t copyLeaf(Feuille_t feuille){
  Feuille_t res = createPureLeaf();
  res->fType = feuille->fType;
  res->f = feuille->f;
  res->str = res->str;

  return res;
}

Node_t createNulNode(void){
  Node_t res = malloc(sizeof(struct Node));
  res->nType = Nul;
  res->d = NULL;
  res->g = NULL;
  res->g = NULL;
  return res;
}

Node_t createEmptyNode(void) {
  Node_t res = createNulNode();
  res->nType = Noeud;
  return res;
}

Node_t createLeaf(String_t str){
  Feuille_t leaf = createElemLeaf(str);
  Node_t res = createNulNode();
  res->nType = Feuille;
  res->elem = leaf;
  return res;
}

Node_t createElemNode(Feuille_t leaf) {
  Node_t res = createEmptyNode();
  res->g = createEmptyNode();
  res->g->nType = Feuille;
  res->g->elem = leaf;
  res->d = createNulNode();

  return res;
}

Node_t createNode(Node_t nodeA, Node_t nodeB){
  Node_t res = createEmptyNode();
  res->nType = Noeud;
  res->g = nodeA;
  res->d = nodeB;
  return res;
}

Node_t copyNodeLeaf(Node_t node){
  if(Feuille != node->nType){
    error(3);
    return NULL;
  }
  Node_t res = createEmptyNode();
  res->nType = node->nType;
  res->elem = copyLeaf(node->elem);
  res->d = NULL;
  res->g = NULL;
}

Node_t copyNode(Node_t node) {
  Node_t res = createEmptyNode();
  if(Feuille == node->nType){
    return copyNodeLeaf(node);
  }
  else if(Nul == node->nType){
    return createNulNode();
  }
  else if(Noeud == node->nType){
    // fils gauche
    if(Feuille == node->g->nType){
      res->g = copyNodeLeaf(node->g);
    } else if(Nul == node->g->nType){
      return createNulNode();
    } else if(Noeud == node->g->nType){
      return copyNode(node->g);
    } else {
      error(4);
      return NULL;
    }

    // fils droit
    if(Feuille == node->d->nType){
      res->d = copyNodeLeaf(node->d);
    } else if(Nul == node->d->nType){
      return createNulNode();
    } else if(Noeud == node->d->nType){
      return copyNode(node->d);
    } else {
      error(4);
      return NULL;
    }
  } else{
    error(4);
    return NULL;
  }

  return res;
}

Node_t createPair_f(Feuille_t feuilleA, Feuille_t feuilleB){
  Node_t res = createEmptyNode();
  Feuille_t feuillePair = createPureLeaf();
  feuillePair->fType = Pair;
  res->g = createElemNode(feuillePair);

  res->d = createNode(createElemNode(feuilleA),
                      createNode(createElemNode(feuilleB),
                                 createEmptyNode()));


  return res;
}

Node_t createEmptyVector(void){
  Node_t res = createEmptyNode();
  res->g = createElemNode(createPureLeaf());
  res->g->elem->fType = Vector;
  res->d = createNulNode();
  return res;
}

void deleteNode(Node_t node){
  if(Nul == node->nType || (NULL == node->elem && NULL == node->d && NULL && node->g)) {
    free(node);
    return;
  }
  if(NULL != node->g){
    deleteNode(node->g);
  }
  if(NULL != node->d){
    deleteNode(node->d);
  }
  if(NULL != node->elem){
    free(node->elem);
  }
  free(node);
}