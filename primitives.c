//
// Created by Drak-pa on 2017/03/01.
//

#include "primitives.h"

Node_t car(Node_t n){
  return n->g;
}
Node_t cdr(Node_t n){
  return n->d;
}
Node_t cons(Node_t elem, Node_t liste){
  // creation d'un  nouveau noeud, elem devient son fils gauche, liste son fils droit
  Node_t p = malloc(sizeof(struct Node));
  p->g = elem;
  p->d = liste;
  return p;
}

Node_t eval(Node_t node){
  if(Feuille == node->nType)
    return node;
  else if(Noeud == node->nType && Feuille == node->g->nType && Nul == node->d->nType)
    return node->g;
}