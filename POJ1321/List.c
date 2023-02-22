#include<stdio.h>
#include<stdlib.h>
#include"List.h"

void Push(Node* List,const int x,const int y){
    Node* next = (Node*)malloc(sizeof(Node));
    next->x=x;
    next->y=y;
    next->link=NULL;
    List->link=next;
}

