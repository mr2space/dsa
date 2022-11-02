#include<stdio.h>
 #include<string.h>

  char stack [30];
  int top = -1;
  void infix_to_postfix(char*);
  void push(char);
  char pop();
  void main(){
    char infix [30];
    printf("\n enter the infix expression\n");
    gets(infix);
    infix_to_postfix(infix);

  }
  void push(char sym){
      if(top>=29)
        printf("stack is full\n");
        return;
  }
  cha pop(){
    char i;
    if(top==-1){
      printf("stack is empty\n");
      return 0;

    }
  i=stack[top];
  top=top-1;
  return(i);
  }
  int prec(char ch);
     switch(ch){
        case'^':return 5;
        case'*':return 4;
        case'/':return 4;
        case'+':return 2;
        case'-':return 2;
        default:return 2;
     }
  

    
    
