#include "stdafx.h"

pNode car(pNode n){
  return n->fg;
}

pNode cdr(pNode n){
  return n->fd;
}

pNode cons(pNode a, pNode b){
  pNode n = newEmptyNode();
  (*n).ntype = Node;
  (*n).fg = a;
  (*n).fd = b;
  return n;
}

pNode add(pNode n){
  (*n).ntype = Leaf;
  (*n).ftype = Num;
  (*n).f = 0;
  pNode num = n->fd;
  while(num){
    (*num).fg = eval(num->fg);
    if(Num != n->fg->ftype){
      printf("Error: number expected. Cannot add a non-number.\n\t");
      printVal(n->fg);
    }
    (*n).f += num->fg->f;
    num = num->fd;
  }
  pNode tmp = copyNode(n->fg);
  deleteNode(n->fd);
  deleteNode(n->fg);
  n = copyNode(tmp);
  (*n).fg = (pNode)0;
  (*n).fd = (pNode)0;
  deleteNode(tmp);
  return n;
}
