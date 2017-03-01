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
    List p = malloc(sizeof(struct Node));
    p->d = elem;
    p->g = liste;
    return p;
}