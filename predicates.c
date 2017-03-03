//
// Created by Drak-pa on 2017/03/01.
//

#include "predicates.h"

List car(List n){
  return n->g;
}
List cdr(List n){
  return n->d;
}
List cons(List elem, List liste){
  // creation d'un  nouveau noeud, elem devient son fils gauche, liste son fils droit
  List p = malloc(sizeof(struct Node));
  p->g = elem;
  p->d = liste;
  return p;
}