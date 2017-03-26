#include "stdafx.h"

pNode newEmptyNode(){
  pNode n = (pNode)malloc(sizeof(struct Node));
  (*n).ntype = Nul;
  (*n).s = (String_t)0;
  (*n).fg = (pNode)0;
  (*n).fd = (pNode)0;
  return n;
}

pNode newNode(pNode g, pNode d){
  pNode n = newEmptyNode();
  (*n).ntype = Node;
  (*n).s = (String_t)0;
  (*n).fg = g;
  (*n).fd = d;

  return n;
}

pNode copyNode(pNode a){
  pNode n = (pNode)0;
  if(!a)
    return n;
  n = newEmptyNode();
  (*n).ntype = a->ntype;
  (*n).ftype = a->ftype;
  (*n).f = a->f;
  (*n).fg = a->fg;
  (*n).fd = a->fd;

  return n;
}

pNode copyTree(pNode a){
  pNode n = (pNode)0;
  if(!a)
    return n;
  n = copyNode(a);
  (*n).fd = copyTree(a->fd);
  (*n).fg = copyTree(a->fg);

  return n;
}

pNode newPair(pNode a, pNode b){
  pNode res = newEmptyNode();
  (*res).ftype = Pair;
  (*res).ntype = Leaf;
  (*res).fg = newEmptyNode();
  res->fg->ntype = Leaf;
  res->fg->ftype = Pair;

  (*res).fd = newNode(a,b);

  return res;
}

void deleteNode(pNode a){
  if(!a)
    return;
  deleteNode(a->fg);
  deleteNode(a->fd);
  free(a);
  return;
}

void deleteString(String_t a){
  if(!a)
    return;
  deleteString(a->next);
  free(a);
}

String_t newString(){
  String_t s = (String_t)malloc(sizeof(struct CharNode));
  (*s).next = (String_t)0;
  return s;
}

pNode eval(pNode n){
  if(Leaf == n->ntype)
    return n;
  if(Nul == n->ntype)
    return (pNode)0;
  return (pNode)0;
}
