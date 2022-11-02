#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
};
struct Node *head = NULL;

int addFirst();
int addLast();
int display();
int delLast();
int delFirst();
int searchElement();
int display();

int main()
{
    int choice;
    while (1)
    {
        printf("======================== \n 1. insert in start \n 2. insert at last \n 3. display \n 4. delete last \n 5. delete first \n 6. check Element \n 7. exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
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
            delLast();
            break;
        case 5:
            delFirst();
            break;
        case 6:
            searchElement();
            break;
        case 7:
            exit(0);
        default:
            printf("invalid choice\n\n");
        }
    }
}

//###############################################################################################
struct Node *create()
{
    // create memory for linklist
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    return temp;
}

//###############################################################################################

int addFirst()
{
    // storing memeory in temp
    struct Node *temp = create();
    // taking user data
    printf("enter the element: ");
    scanf("%d", &temp->data);
    // adding element in start
    temp->Next = head;
    head = temp;
}

//###############################################################################################

int addLast()
{
    struct Node *p = head;
    // storing memeory in temp
    struct Node *temp = create();
    // taking user data
    printf("enter the element: ");
    scanf("%d", &temp->data);
    // adding element in start
    while (p->Next != NULL)
    {
        p = p->Next;
    }
    p->Next = temp;
    temp->Next = NULL;
}

//###############################################################################################

int delLast()
{
    struct Node *p = head;
    while (p->Next->Next != NULL)
    {
        p = p->Next;
    }
    free(p->Next);
    p->Next = NULL;
}

//###############################################################################################

int delFirst()
{
    // storing memeory in temp
    struct Node *temp = head;
    // adding element in start
    head = temp->Next;
    free(temp);
}

//###############################################################################################

int searchElement()
{
    int x;
    if (head == NULL)
        return printf("no node\n");
    struct Node *p = head;
    printf("enter element to be search: ");
    scanf("%d", &x);
    while (p != NULL)
    {
        if (p->data == x)
        {
            printf("data found \n");
            break;
        }
        p = p->Next;
    }
    if (p == NULL)
        printf("element not found");
    printf("\n");
    printf("\n");
}

//###############################################################################################

int display()
{
    if (head == NULL)
        return printf("no node\n");
    struct Node *p = head;
    printf("data is:  ");
    while (p != NULL)
    {
        printf("%3d", p->data);
        p = p->Next;
    }
    printf("\n");
    printf("\n");
}