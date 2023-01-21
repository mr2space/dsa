#include<stdio.h>
#include<stdlib.h>



struct node{
    int data;
    int *next;
}

struct node * start = NULL;
struct node* create(){
    return (struct node *)mallac(sizeof(struct node));
}

int insert(){
    //declaration
    int data = 0;
    struct node * temp = create() ;
    struct node * p = NULL;
    //data input
    printf("enter the data : ");
    scanf("%d",&data);
    temp->next = NULL;
    temp->data = data;
    //first node
    if(start == NULL){
        start = temp;
        return data;
    }
    //n node
    p = start;
        // finding the last element 
    while(p->next != NULL) p = p->next;
    p->next = temp;
    // return
    return data;
}

int deletion(){
    // declaration
    int data = NULL;
    struct node * q = NULL;
    // check if node empty
    if(start == NULL){
        printf("empty queue\n");
        return NULL;
    }
    // removing the first node
    q = start;
    start = start->next;
    data = q->data;
    free(q);
    // return data
    return data;
}


int main(){
    
    return 0;
}