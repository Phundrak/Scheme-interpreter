//
// Created by drak-pa on 03/03/17.
//

#ifndef SCHEME_INTERPRETER_EVALUATION_H
#define SCHEME_INTERPRETER_EVALUATION_H

#include "globalIncludes.h"
#include "structure.h"

// convertis un char numeral en int, renvoie -1 s'il ne s'agit pas d'un numeral
int charToInt(char);

// convertis un String_t en int
int strToInt(String_t);

// convertis un char en float, renvoie -1 s'il ne s'agit pas d'un numeral
float charToFloat(char);

// convertis un String_t en float
float strToFloat(String_t);

// renvoie True si le char est un numeral, False sinon
bool charIsNum(char);

// renvoie True si le String_t represente un numeral, False sinon
bool strIsNum(String_t);

// renvoie True si le String_t represente un float, False sinon
bool strIsFloat(String_t);

// renvoie True si le String_t represente un char, False sinon
bool strIsChar(String_t);

// renvoie True si le String_t represente un Bool, False sinon
bool strIsBool(String_t);

// convertis le String_t en bool
bool strToBool(String_t);

// renvoie True si le String_t represente un string (commencant
// et se terminant par la double quote " ), False sinon
bool strIsString(String_t);

// renvoie True si la valeur de la feuille est un float, False sinon
bool leafIsFloat(Node_t);

// renvoie True si les deux String_t sont identiques, False sinon
bool strCmp(String_t, String_t);

// renvoie un pointeur vers le Node_t de tete d'une fonction utilisateur
// si rien n'est trouve, renvoie NULL
Node_t getFunc(String_t, Node_t);

void deleteNode(Node_t);

#endif //SCHEME_INTERPRETER_EVALUATION_H
