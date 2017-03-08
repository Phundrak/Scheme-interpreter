//
// Created by Drak-pa on 2017/03/01.
//

#ifndef SCHEME_INTERPRETER_PREDICATES_H
#define SCHEME_INTERPRETER_PREDICATES_H

#include "globalIncludes.h"
#include "structure.h"


Node_t car(Node_t);
Node_t cdr(Node_t);
Node_t cons(Node_t, Node_t);


#endif //SCHEME_INTERPRETER_PREDICATES_H
