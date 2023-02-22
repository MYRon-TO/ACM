#include <stdio.h>
#include "List.h"

inline void debug(const char* STRING);

int main(){
    int n;
    int k;
    scanf("%d %d",&n,&k);
    while(n!=-1&&k!=-1){
        debug("Now Loop");

        Node* Board= (Node*)malloc(sizeof(Node));
        Board->link=NULL;

        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
           }
        }

        scanf("%d %d",&n,&k);
    }
return 0;
}

inline void debug(const char* STRING){
    printf("\n%s\n",STRING);
}
