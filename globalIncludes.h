//
// Created by Drak-pa on 2017/03/01.
//

#ifndef SCHEME_INTERPRETER_GLOBALINCLUDES_H
#define SCHEME_INTERPRETER_GLOBALINCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

extern struct Leaf* userFunc;
extern struct Leaf* predicats;

int error(int);

#endif //SCHEME_INTERPRETER_GLOBALINCLUDES_H
