#include<stdio.h>



int hanoi(int num,char from,char help,char to){
    if(num == 1){
        printf("Move from %c to %c\n",from,to);
        return 0;
    }

    hanoi(num-1,from,to,help);
    printf("move from %c to %c\n",from,to);
    hanoi(num-1,help,from,to);  

}
int main(){
    char from = 'A';
    char to = 'C';
    char help = 'B';
    hanoi(6, from,help,to);
    return 0;
}