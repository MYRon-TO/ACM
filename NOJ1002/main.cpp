#include<stdio.h>

int main(){
    int n =getchar();
    int max=0,min=0;
    for(int i=0;i<n;i++){
        int temp=getchar();
        if(temp>max)
            max=temp;
        else if(temp<min)
            min=temp;
        getchar();
    }
    printf("%d %d",max,min);
    return 0;
}
