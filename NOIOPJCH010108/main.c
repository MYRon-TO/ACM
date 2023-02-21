#include<stdio.h>

int main(){
    char c;
    c=getchar();
    for(int i=0;i<3;i++){
        for(int k=0;k<2-i;k++){
            printf(" ");
        }
        for(int j=0;j<2*i+1;j++){
            printf("%c",c);
        }
        printf("\n");
    }
    for(int i=1;i<3;i++){
        for(int j=0;j<i;j++){
            printf(" ");
        }
        for(int k=0;k<2*(2-i)+1;k++){
            printf("%c",c);
        }
        printf("\n");
    }
return 0;
}
