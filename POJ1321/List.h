#pragma once

typedef struct Node{
    int x;
    int y;
    struct Node* link;
}Node;

void Push(Node* List,const int x,const int y);

