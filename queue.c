#include <stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue *Next;
};
struct queue *front, *rear;

int add();
int removelast();
int display();

int main()
{
    int ch;
    while (1)
    {
        printf("-------------------- queue ------------------ \n");
        printf("1: add element \n");
        printf("2: remove element \n");
        printf("3: display \n");
        printf("4: exit \n");
        printf("Enter your choice:  ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            removelast();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}

struct queue *create()
{
    return (struct queue *)malloc(sizeof(struct queue));
}

int add()
{
    struct queue *temp = create();
    printf("enter the element: ");
    scanf("%d", &temp->data);
    temp->Next = front;
    front = temp;
}

int removelast()
{
    int data;
    struct queue *p = front;
    if(front == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    if(p->Next == NULL){
        printf("data: %d \n", p->data);
        data = p->data;
        free(p);
        front = NULL;
        return data;
    }
    while (p->Next->Next != NULL)
    {
        p = p->Next;
    }
    printf("data: %d \n", p->Next->data);
    data = p->data;
    free(p->Next);
    p->Next = NULL;
    return data;
}

int display()
{
    if (front == NULL)
        return printf("no node\n");
    struct queue *p = front;
    printf("data is:  ");
    while (p != NULL)
    {
        printf("%3d", p->data);
        p = p->Next;
    }
    printf("\n");
    printf("\n");
}
