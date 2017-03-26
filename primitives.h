#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "stdafx.h"

// renvoie le fils gauche de l'arbre passe en argument
pNode car(pNode);
// renvoie le fils droit de l'arbre passe en argument
pNode cdr(pNode);
// renvoie un arbre avec le premier argument comme fils gauche, le second comme fils droit
pNode cons(pNode,pNode);

// additionne tous les fils droits de l'arbre passe en argument
pNode add(pNode);

#endif
