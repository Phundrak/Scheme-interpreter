#include "stdafx.h"

int str_isExit(char *input){
  char* str = "(exit)";
  REP(i,0,6){
    if(input[i] != str[i])
      return 0;
  }
  return 1;
}

int isExit(String_t str){
  char* exit = "(exit)";
  int retcode = 1;
  int i = 0;
  while(i < 6 && str){
    //DEBUG printf("exit: |%c | %d|\nstr: |%c | %d|\n\n",exit[i],(int)exit[i],str->key,(int)str->key);
    if(exit[i] != str->key)
      retcode = 0;
    str = str->next;
    ++i;
  }
  DEBUG printf("i: %d\n",i);
  if(i < 6)
    retcode = 0;
    
  return retcode;
}
    

int str_getUserInput(char *input){
  int openPar = 0;
  int i = 0;
  char c;
  while((c = (char)getchar()) != EOF){
    if(c == '(')
      openPar++;
    else if(c == ')')
      openPar--;

    if(openPar < 0)
      return openPar;
    if(c=='\n' && 0 == openPar){
      input[i] = '\0';
      break;
    }
    if(c=='\n'){
      REP(i,0,openPar){
	printf("\t");
      }
      input[i++]=' ';
      continue;
    }
    
    input[i] = c;
    i++;
    DEBUG printf("%c\n",c);
  }
  printf("\n");
  return openPar;
}

int getUserInput(String_t str){
  int openPar = 0;
  //int i = 0;
  char c;
  while((c = (char)getchar()) != EOF){
    if(c=='('){
      ++openPar;
    } else if(c==')'){
      --openPar;
    }

    if(0 > openPar)
      return openPar;
    
    String_t s = newString();
    (*s).next = str;
    (*s).key = c;
    
    if('\n' == c && 0 == openPar){
      (*s).key = '\0';
      break;
    }
    
    if('\n'==c && 0!= openPar){
      REP(i,0,openPar)
	printf("\t");
      (*s).key = ' ';
    }
    str = s;
  }
  printf("\n");
  DEBUG{
    printf("|");
    printStr(str);
    printf("|\n");
  }
  str = invertStr(str);
  //str = str->next;
  DEBUG{
    printf("|");
    printStr(str);
    printf("|\n");
  }
  return openPar;
}

pNode str_makeTree(char *str){
  pNode res = newEmptyNode();
  for(int i = 0; i < MAX_LEN && str[i] != '\0'; i++){
    
  }

  return res;
}

pNode makeTree(String_t str){
  pNode res = newEmptyNode();

  while(str){
    
  }
  
  return res;
}

int main(){
  int userRet=0;
  int inputs = 0;
  /*
  // pour une utilisation avec les string classiques
  char* input=malloc((MAX_LEN)*sizeof(char));
  while(1){
    printf("[%d]> ",++inputs);
    userRet = getUserInput(input);
    if(0 < userRet){
      printf("Error: too many parenthesis closed\n");
      continue;
    }
    if(0 != userRet){
      printf("Unexptected error with parenthesis\n");
      continue;
    }
    DEBUG("User input:\n%s\n",input);
    if(isExit(input))
      break;
  }
  */
  String_t str = newString();
  (*str).key = '\0';
  while(1){
    deleteString(str);
    String_t str = newString();
    printf("[%d] > ",++inputs);
    userRet = getUserInput(str);
    str = str->next;
    if(0 < userRet){
      printf("Error: too many parenthesis closed\n");
      continue;
    } else if(0 != userRet){
      printf("Unexpected error: too many opened parenthesis\n");
      continue;
    }
    DEBUG{
      String_t temp = str;
      while(temp){
	printf("char:\t%c\t%d\n",temp->key,temp->key);
	temp = temp->next;
      }
    }
    if(isExit(str))
      break;
    DEBUG
      if(strIsNum(str))
	printf("It's a number!\n");
  }
  
    
  

  return 0;
}
