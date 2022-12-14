#include<stdio.h>
#include<string.h>

int isVowel(char ele);
int isPalindrom(char str[], int size);
int StrSizeCounter(char str[]);

int main(){
    char str[100] ;
    gets(str);
    char ch = str[0];
    int i = 0;
    int size = StrSizeCounter(str);
    if(isPalindrom(str,size)){
        printf("This is palindrom \n");
    }else{
        printf("This is  not palindrom \n");
    }
}


int isVowel(char ele){
    char vowel[] = "AEIOUaeiou";
    char ch = vowel[0];
    int i=0;
    while(ch != '\0'){
        if(ele == ch){
            return 1;
        }
        ch = vowel[++i];
    }
    return 0;
}

int isPalindrom(char str[],int size){
    int first = 0,i;
    int last = size-1;
    char fCh = str[first];
    char lCh = str[last];
    for(i=0;i<size/2;){
        if(fCh != lCh){
            return 0;
        }
        // printf("%c ",fCh);
        fCh = str[++i];
        lCh = str[--last];
    }
    return 1;
}

int StrSizeCounter(char str[]){
    int i = 0;
    char ch = str[i];
    while(ch != '\0'){
        ch = str[++i];
    }
    return i;
}