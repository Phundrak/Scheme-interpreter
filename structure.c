//
// Created by Drak-pa on 2017/03/01.
//

#include "structure.h"

String_t invertStringt(String_t str){
  String_t prev = NULL;
  String_t next = NULL;
  String_t temp = malloc(sizeof(struct CharNode));
  temp->key = '\0';
  temp->next = str;
  str = temp;

  while(NULL != str->next && str != str->next){
    next = str->next;
    str->next = prev;
    prev = str;
    str = next;
  }
  next = str->next;
  str->next = prev;
  prev = str;
  str = next;

  return prev;
}