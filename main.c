#include <stdio.h>

#define NIL -1
#define F 0
#define T 1

enum NodeType{ node, atom};
typedef enum NodeType NodeType_t;


struct Atome{

};
typedef struct Atome Atome_t;

struct Node{
    NodeType_t type;
    Atome_t atome;
    struct Node* g;
    struct Node* d;
};
typedef struct Node Node_t;
typedef Node_t* list;

list car(list);
list cdr(list);
list cons(list, list);

list car(list n){
    return n->g;
}
list cdr(list n){
    return n->d;
}
list cons(list n, list a){
    /*
     * malloc(list)
     * list.g = n
     * list.d = a
     * return list
     */
}

int main(){

    return 0;
}