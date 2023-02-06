#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
struct node*next=NULL;
  int addFirst();
  int addLast();
  int display();
  int delFirst();
  int delLast();
  int searchElement();
  int main()
{
  int choice;   
  while(1)
  {
    printf("\n 1.insert in start");
    printf("\n 2.insert in last ");
    printf("\n 3.display");
    printf("\n 4.delete first");
    printf("\n 5.delete last");
    printf("\n 6. check element");
    printf("\n 7.Exit");
    printf("\n enter your choice");
    scanf("\n %d",&choice)
    switch(choice)
    {
        case 1:
        addFirst();
        break;
        case 2:
        addLast();
        break;
        case 3:
        display();
        break;
        case 4:
        delFirst();
        break;
        case 5:
        delLast();
        break;
        case 6:
        searchElement();
        break;
        case 7:
        Exit();
        break;
        default:
        printf("invalid choice");


    }
  }
}
//**********************************
strcut node*create()
{
    //allocate a memory
    struct node*temp=(struct node*)malloc(sizeof(struct node))
    return temp;
}
struct node*temp=create(