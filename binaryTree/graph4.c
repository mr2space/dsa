        #include<stdio.h>
        //#include<alloc.c>
        struct node{
            char vertex;
            struct node*next;
        };
        struct node*gnode;

        void displaygraph(struct node*adj[],int no_of_nodes);
        void deletegraph(struct node *adj[], int no_of_nodes);
        void creategraph(struct node *adj[], int no_of_nodes);
        int main(){
            struct node*Adj[10];
            int i, no_of_nodes;
            printf();
            printf("/n enter the number of nodes in G");
            for(i=0; i< no_of_nodes;i++)
            {
                last=Null;
                printf("/n enter the number of neighbours of %d",i);
                scanf("%d",&val);
                new node=(struct node*)malloc(sizeof(struct node));
                new_node->vertex=val;
;                new_node->next=Null;
if(Adj[i]==Null)
      Adj[i]=new_node;
      else
      last->next=new_node;
      last=new_node;


            }
        }
        void displaygraph(struct node*Adj[],int no_of_node)
        {
            struct node*ptr;
            int i;
            for(i=0;i< no_of_nodes;i++)
            ptr=Adj[i];
            printf("/n the neighours of node %d are");
            while(ptr!=Null)
            {
                printf("\t%d",ptr->vertex);
                ptr=ptr->next;
            }
            }
        }
        void deletegraph(struct node*Adj[],int no_of_nodes)
        {
            int i;
            struct node*temp*ptr;
            for(i=0;i<no_of_nodes;i++)
        {
            ptr=Adj[i];
            while(ptr!=Null)
            {
                temp=ptr;
                ptr=ptyr->next;
                free(termp);
            }
            Adj[i]=Null;
        }}
