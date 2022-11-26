#include <stdio.h>
#include<stdlib.h> 

struct node
{
    int data;
    struct node *l, *r;
};
struct node *tree = NULL;
struct node *create(){
    return (struct node *)malloc(sizeof(struct node));
}

int count = 0;

int addBst();
struct node *Inorder(struct node *p);
struct node *Postorder(struct node *p);
struct node *Preorder(struct node *p);
void countf(struct node *p);
int main()
{
    printf("----------------- BST -------------------------------\n");
    int ch;
    while (1)
    {
        printf("\n");
        printf("\n");
        printf("1.ADD in tree \n");
        printf("2.Inorder \n");
        printf("3.Preorder \n");
        printf("4.Postorder \n");
        printf("5.exit \n");
        printf("6.count \n");
        printf("\n");
        printf("Enter the number: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addBst();
            break;
        case 2:
            Inorder(tree);
            printf("\n");
            break;
        case 3:
            Preorder(tree);
            printf("\n");
            break;
        case 4:
            Postorder(tree);
            printf("\n");
            break;
        case 5:
            exit(0);
        case 6:
            Inorder(tree);
            printf("\n count is : %d ",count);
            break;
        default : printf("Invalid Char");
            break;
        }
    }

    return 0;
}

struct node *Inorder(struct node *p)
{
    if (p != NULL)
    {
        Inorder(p->l);
        count++;
        printf("%3d ", p->data);
        Inorder(p->r);
    }
}

void countf(struct node *p)
{
    if (p != NULL)
    {
        Inorder(p->l);
        count++;
        Inorder(p->r);
    }
}

struct node *Postorder(struct node *p)
{
    if (p != NULL)
    {
        Postorder(p->l);
        Postorder(p->r);
        printf("%3d ", p->data);
    }
}

struct node *Preorder(struct node *p)
{
    if (p != NULL)
    {
        printf("%3d ", p->data);
        Preorder(p->l);
        Preorder(p->r);
    }
}

int addBst()
{
    struct node *temp = create();
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->l = NULL;
    temp->r = NULL;
    struct node *p = tree;
    struct node *pn = NULL;

    if (p == NULL)
    {
        tree = temp;
        return 0;
    }

    while (p != NULL)
    {
        pn = p;
        if (p->data > temp->data)
        {
            p = p->l;
            continue;
        }
        p = p->r;
    }

    if (pn->data > temp->data)
    {
        pn->l = temp;
        return 0;
    }

    pn->r = temp;
    return 0;
}