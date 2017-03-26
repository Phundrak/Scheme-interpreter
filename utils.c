#include "stdafx.h"

bool strToBool(String_t str){
  if(!strIsBool(str)){
    return False;
  }
  if(str->next->key == 'f')
    return False;
  return False;
}

int charIsNum(char c){
  if('0' <= c && '9' >= c)
    return 1;
  return 0;
}

int strIsNum(String_t str){
  if(!str)
    return 0;
  if('+' == str->key || '-' == str->key){
    str = str->next;
    if('\0' == str->key)
      return 0;
  }
  while(str && '\0' != str->key){
    if(!charIsNum(str->key)){
      //DEBUG printf("%c is not a number\n",str->key);
      return 0;
    } else{
      //DEBUG printf("%c is a number\n",str->key);
    }
    str = str->next;
  }
  return 1;
}

int strIsChar(String_t str){
  if(!str)
    return 0;
  if(!strIsNum(str))
    if(!charIsNum(str->key) && '\0' == str->next->key)
      return 1;
  return 0;
}

int strIsBool(String_t str){
  if(!str)
    return 0;
  if(strIsChar(str))
    return 0;
  if('#' == str->key)
    if('f' == str->next->key || 't' == str->next->key)
      return 1;
  return 0;
}

int strIsString(String_t str){
  if(!str)
    return 0;
  if(strIsBool(str))
    return 0;
  if('"' != str->key)
    return 0;
  while(str->next){
    if('"' == str->key && '\0' == str->next->key)
      return 1;
    str = str->next;
  }
  return 0;  
}

int strCmp(String_t a, String_t b){
  while(a && b){
    if(a->key != b->key)
      return 0;
    a = a->next;
    b = b->next;
  }
  if(!a && !b)
    return 1;
  return 0;
}

int str_strCmp(String_t a, char *b){
  int len = strlen(b);
  int i;
  for(i = 0; i < len && a; i++){
    if(a->key != b[i])
      return 0;
  }
  if(!a && i == len)
    return 1;
  return 0;
}

float charToFloat(char c){
  return c-(float)'a';
}

float strToFloat(String_t str){
  float a = 0.0, b = 1.0, res, mult = 0.1;
  bool neg = False, decim = False;

  if('-' == str->key){
    neg = True;
    str = str->next;
  }

  while('\0' != str->key && '/' != str->key){
    if('.' == str->key){
      decim = True;
    } else if(decim){
      a += mult * charToFloat(str->key);
      mult /= 10.0;
    } else {
      a = a * 10.0 + charToFloat(str->next->key);
    }
    str = str->next;
  }

  if('/' == str->key)
    b = strToFloat(str->next);

  if(neg)
    res = -1 * (a/b);
  else
    res = a/b;

  return res;
}

void printStr(String_t str){
  while(str){
    printf("%c",str->key);
    str = str->next;
  }
}

void printVal(pNode n){
  switch(n->ftype){
  case(Bool):
    printf("bool:\t");
    if(False == n->b)
      printf("#f");
    else
      printf("#t");
    break;
  case(Char):
    printf("char:\t%c",n->c);
    break;
  case(Num):
    printf("numeral:\t%f",n->f);
    break;
  case(String):
    printf("string:\t");
    printStr(n->s);
    break;
  default:
    printf("Not a valid value.");
  }
}

String_t invertStr(String_t str){
  String_t prev,next,temp;
  prev = NULL;
  next = NULL;
  temp = newString();
  (*temp).key = '\0';
  (*temp).next = str;
  str = temp;

  while(str->next && str!=str->next){
    next = str->next;
    (*str).next = prev;
    prev = str;
    str = next;
  }
  next = str->next;
  (*str).next = prev;
  prev = str;
  str = next;

  return prev;
}
