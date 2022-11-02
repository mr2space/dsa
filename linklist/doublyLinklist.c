#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev,*next; 
};


struct Node * start;


struct Node * create(){
    return (struct Node *)malloc(sizeof(struct Node));
}

// ib = ib
// il = il
// is = addspecific
//db = db
//dl = del last
//ds = del x

struct Node * ib();
int il();
int display();
int db();
int dl();
int is();
int reverseLinkList() ;
int main()
{
    int a;
    
    while(1)
    {
        printf("\n==============MAIN MENU==============\n");
        printf("1.ib\n");
        printf("2.display\n");
        printf("3.exit\n");
        printf("4.add last\n");
        printf("5.delete beginning\n");
        printf("6.delete last\n");
        printf("7.Add After the x\n");
        printf("enter the option: ");
        scanf("%d",&a);
        switch(a)
        {
            case 1 : ib();break;
            case 2 : display();break;
            case 3 : exit(0);
            case 4 : il();break;
            // case 5 : addBefore();break;
            case 5 : db();break;
            case 6 : dl();break;
            case 7 : is();break;
            case 8 : reverseLinkList(); break;
            default: printf("\n*wrong choice*\n");
        }
    }
    return 0;
}

int display(){
    struct Node *p;
    p = start;
    if(start == NULL){
        return printf("No node \n");
    }
    while(p!=NULL){
        printf("%3d ",p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node * ib(){
    int x;
    struct Node * temp,*p;
    temp = create();
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->prev = NULL;
    temp->next = start;
    if(start!=NULL){
    start->prev = temp;
    }
    start = temp;
    return temp;
}


int il(){
    struct Node * temp,*p;
    temp = create();
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    if(start==NULL){
        temp->prev = NULL;
        start = temp;
    }else{
        p = start;
        while(p->next != NULL){
            p=p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}


int db(){
    struct Node * q,*p;
    if(start == NULL){
        printf("No node");
        return 0;
    }else if(start->next == NULL){
        q = start;
        start = NULL;
        free(q);
        return 0;
    }
    q = start;
    start = start->next;
    start->prev = NULL;
    free(q);
}


int dl(){
    struct Node * q,*p;
    if(start == NULL){
        printf("No node");
        return 0;
    }else if(start->next == NULL){
        q = start;
        start = NULL;
        free(q);
        return 0;
    }
    p = start;
    while(p->next != NULL){
        p=p->next;
    }
    q = p;
    p = p->prev;
    p->next = NULL;
    free(q);

}



int is(){
    int x;
    struct Node * temp,*p;
    temp = create();
    printf("Enter the x: ");
    scanf("%d",&x);
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    if(start == NULL){
        printf("No Node \n");
        return 0;
    }
    p=start;
    while(p != NULL){
        if(p->data == x){
            break;
        }
        p = p->next;
    }
    temp->next = p->next;
    temp->prev = p;
    p->next = temp;
}

int reverseLinkList(){
    struct Node * temp,*p,*nextLink;
    p = start;
    while(p->next != NULL){
        p = p->next;
    }
    temp = p;
    p = start;
    start = temp;
    while(p != NULL){
        nextLink = p->next;
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = nextLink;
    }
    
    display();


}