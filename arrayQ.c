#include<stdio.h>
#include<stdlib.h>

#define size 3

int q[size];
int front = -1;
int rear = -1;

int add();
int displayRear() ;
int displayRear();
int removeEle();


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
            removeEle();
            break;
        case 3:
            displayRear();
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}

int add(){
    int data;
    printf("Enter the data: %d ", (rear + 1) % size);
    scanf("%d",&data);
    if((rear+1)%size == front){
        printf("stack is full \n",rear,front);
        return 0;
    }
    if(front == -1){
        front++;
        rear++;
        q[front] = data;
        return data;
    }
    rear = (rear+1)%size;
    q[rear] = data;
}

int displayRear(){
    int i = front;
    if(front == -1){
        printf("Queue is empty \n");
    }
    while (i != (rear)%size){
        printf("%3d ",q[i]);
        i = (i+1)%size;
    }
    printf("%d ",q[i]);
    printf("\n");
}

int removeEle(){
    if (front == -1)
    {
        printf("Queue is empty \n");
    }
    printf("data: %d \n",q[rear]);
    rear = (rear-1)%size;
}