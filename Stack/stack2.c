#include <stdio.h>
#include <stdlib.h>

// stack init
int size = 5;
int stack[5];
int top = -1;

int push();
int pop();
int peep();
void display();

int main()
{
    int ch;

    while (1)
    {
        printf("-------------------------stack code--------------------------------\n");
        printf("1. pop \n");
        printf("2. push \n");
        printf("3. peep \n");
        printf("4. display \n");
        printf("5. exit\n");
        printf("\n");

        printf("Enter your choice:  ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            pop();
            break;
        case 2:
            push();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
        }
    }
}

// push

int push()
{
    int x;
    printf("Enter the data: ");
    scanf("%d", &x);
    if (top == size - 1)
    {
        printf("stack is full \n");
    }
    else
    {
        top++;
        stack[top] = x;
        return x;
    }
}
// pop

int pop()
{
    if (top == -1)
    {
        printf("stack is empty \n");
    }
    else
    {
        top--;
        return stack[top + 1];
    }
}

// peep

int peep()
{
    if (top == -1)
    {
        printf("stack is empty \n");
    }
    else
    {
        printf("the element is %d \n", stack[top]);
        return stack[top];
    }
}

// display

void display()
{
    if(top==-1){
        printf("stack is empty\n");
        return;
    }
    int i = top;
    for (i = top; i >= 0; i--)
    {
        printf("%3d", stack[i]);
    }
    printf("\n");
}