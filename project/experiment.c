#include<stdio.h>
#include<stdlib.h>
int main(){
    char s = 'y';
    while(1){
        scanf(" %s",&s);
        if(s == 'n' || s=='N'){
            exit(0);
        }
        if(s=='y' || s=='Y')
        printf("Welcome to ucer \n");
    }
    return 0;
}