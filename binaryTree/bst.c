#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *l, *r;
};

struct node *tree = NULL;
struct node *create()
{
    return (struct node *)malloc(sizeof(struct node));
}

int count = 0;

int addBst();
struct node *Inorder(struct node *p);
struct node *Postorder(struct node *p);
struct node *Preorder(struct node *p);
void countf(struct node *p);
struct node *deletion(struct node *p, int x);

int main()
{
    printf("********** BST ************\n");
    int ch;
    int x;
    while (1)
    {
        printf("1.ADD in tree \n");
        printf("2.Inorder \n");
        printf("3.Preorder \n");
        printf("4.Postorder \n");
        printf("5.delete the node \n");
        printf("6.exit \n");
        printf("7.External count \n");
        printf("\n");
        printf("Enter the number: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addBst();
            break;
        case 2:
            if(tree == NULL){
                printf("tree is empty \n");
                break;
            }
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
            printf("Enter the element: ");
            scanf("%d", &x);
            tree = deletion(tree, x);
            break;
        case 6:
            exit(0);
        case 7:
            printf("Count is %d \n", InternalNode(tree));
            break;
        default:
            printf("Invalid Char");
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
        printf("%3d ", p->data);
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

struct node *deletion(struct node *p, int x)
{
    if(p==NULL) return NULL;
    struct node *temp, *min;
    if (p->data > x)
    {
        p->l = deletion(p->l, x);
    }
    else if (p->data < x)
    {
        p->r = deletion(p->r, x);
    }
    else
    {
        if (p->l == NULL && p->r == NULL)
        {
            free(p);
            return NULL;
        }
        else if (p->l == NULL)
        {
            temp = p->r;
            free(p);
            return temp;
        }
        else if (p->r == NULL)
        {
            temp = p->l;
            free(p);
            return temp;
        }
        min = p->r;
        while (min->l != NULL)
        {
            min = min->l;
        }
        p->data = min->data;
        p->r = deletion(p->r, min->data);
        
    }
    return p;
}


int ExternalNode(struct node * p){
    if(p == NULL) return 0;
    if(p->l == NULL && p->r == NULL){
        return 1;
    }else{
        return ExternalNode(p->l) + ExternalNode(p->r);
    }
}

int InternalNode(struct node * p){
    if(p == NULL) return 0;
    if(p->l != NULL || p->r != NULL){
        return InternalNode(p->r) + InternalNode(p->l) + 1;
    }
}