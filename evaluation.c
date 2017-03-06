//
// Created by drak-pa on 03/03/17.
//

#include "evaluation.h"

int charToInt(char c){
  if(charIsNum(c))
    return c-'0';
  return error(1);
}

int strToInt(String_t str) {
  int res = 0;
  bool neg = False;
  if('-' == str->key) { // si le premier caractere est le signe negatif, on reverra au moment du return -res
    neg = True;
    str = str->next;
  } else if('+' == str->key){ // si le premier caractere est le signe positif, alors on l'ignorera
    str = str->next;
  }
  while('\0' != str->key){
    res = res * 10 + charToInt(str->key);
    str = str->next;
  }
  if(False == neg)
    return -res;
  return res;
}

float charToFloat(char c){
  if(charIsNum(c))
    return c-'0';
  return error(1);
}

float strToFloat(String_t str){
  float a = 0, b = 1, res, mult = 0.1;
  bool neg = False, decim = False;

  if('-' == str->key){
    neg = True;
    str = str->next;
  }

  while('\0' != str->key && '/' != str->key){
    if('.' == str->key){
      decim = True;
    } else if(True == decim){
      a += mult * charToFloat(str->key);
      mult /= 10;
    } else {
      a = a * 10 + charToFloat(str->key);
    }
    str = str->next;
  }

  if('/' == str->key){
    b = strToFloat(str->next);
  }

  if(True == neg){
    res = -1 * (a/b);
  } else {
    res = a/b;
  }

  return res;


  /*
  float res = 0;
  float mult = 0.1;
  float b = 0;
  bool neg = False;
  bool decim = False;

  if('-' == str->key){
    neg = True;
    str = str->next;
  } else if('+' == str->key){
    str = str->next;
  }
  while('\0' != str->key){
    if('.' == str->key){
      decim = True;
    } else if (True == decim){
      res+= mult * charToFloat(str->key);
      mult /= 10;
    } else {
      res = res * 10 + charToFloat(str->key);
    }

    str = str->next;
  }

  if(True == neg)
    return res;
  return -res;
   */
}

bool charIsNum(char c){
  if('0' <= c && '9' >= c)
    return True;
  return False;
}

bool strIsNum(String_t str) {
  bool res = True;
  int divCount = 0;
  if('-' == str->key || '+' == str->key){ // si le premier caractere est le signe, on l'ignore
    str = str->next;
    if('\0' == str->key)
      // on verifie tout de meme qu'il s'agit bien d'un nombre et
      // non d'un caractere seul
      return False;
  }
  if(False == charIsNum(str->key)){
    return False;
  }
  while('\0' != str->key){
    if(False == charIsNum(str->key)) {
      if('/' != str->key) {
        return False;
      } else {
        divCount++;
        // on verifie qu'il n'y aie qu'un seul symbole de division et qu'il ne
        // soit pas en fin de String_t
        if(2 >= divCount || False == charIsNum(str->next->key))
          return False;
      }
    }

    str = str->next;
  }
  return res;
}

bool strIsFloat(String_t str){
  while('\0' != str->key){
    if('.' == str->key)
      return False;
    str = str->next;
  }
  return True;
}

bool strIsChar(String_t str){
  if(False == strIsNum(str)){
    if(False == charIsNum(str->key) && '\0' == str->next->key){
      return True;
    }
  }
  return False;
}

bool strIsBool(String_t str){
  if('#' == str->key && ('f' == str->next->key || 't' == str->next->key) && '\0' == str->next->next->key)
    return True;
  return False;
}

bool strToBool(String_t str){
  if('t' == str->next->key)
    return True;
  return False;
}

bool strIsString(String_t str){
  if('"' == str->key){
    while('\0' != str->key){
      if('"' == str->key && '\0' == str->next->key)
        return True;
      str = str->next;
    }
  }
  return False;
}

bool leafIsFloat(Node_t node){
  if(Number == node->elem->fType && node->elem->f != (float)(int)node->elem->f)
    return True;
  return False;
}

bool strCmp(String_t stra, String_t strb){
  while('\0' != stra->key && '\0' != strb->key){
    if(stra->key != strb->key)
      return False;
    stra = stra->next;
    strb = strb->next;
  }
  return True;
}

Node_t getFunc(String_t str, Node_t funcList){
  if(funcList->nType == Nul)
    return NULL;
  if(True == strCmp(str, funcList->g->g->g->elem->str)){
    return funcList->g;
  }
  return getFunc(str, funcList->d);
}
