//Adjacency List for BFS and DFS

#include<stdio.h>
#include<stdlib.h>
#define n 6
struct Node
{
    char val;
    struct Node *next;
};

struct Node *adlist[n];
int visited[n];
int q[n];
int front=0,rear=-1;

void push(int a)
{
    if(rear!=n-1)
    {
        q[++rear]=a;
    }
}

int isEmpty()
{
    if(front>rear)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int delete()
{
    if(isEmpty()==0)
    {
        return q[front++];
    }
}

void initialize()
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
}

void addnode(int i,int j)
{   
    if(adlist[i]==NULL)
    {
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        adlist[i]=temp;
        temp->val=(char)(65+i);
        temp->next=NULL;
    }
    struct Node* temp=adlist[i];
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    struct Node * p=(struct Node*)malloc(sizeof(struct Node));
    p->val=(char)(65+j);
    p->next=NULL;
    temp->next=p;
}

void BFS(int a)
{
    struct Node *point=adlist[a];
    printf("%c ",point->val);
    visited[a]=1;
    push(a);
    point=point->next;
    while(isEmpty()==0)
    {
        int u=delete();
        point=adlist[u];
        while(point)
        {
            if(visited[point->val-65]==0)
            {
                visited[point->val-65]=1;
                printf("%c ",point->val);
                push(point->val-65);
            }
            point=point->next;
        }
    }
}

void DFS(int a)
{
    struct Node *point=adlist[a];
    printf("%c ",point->val);
    visited[a]=1;
    point=point->next;
    while(point)
    {
        if(visited[point->val-65]==0)
        {
            DFS(point->val-65);
        }
        point=point->next;
    }
}

void main()
{
    char v;
    for(int i=0;i<n;i++)
    {
        adlist[i]=NULL;
    }
    FILE *fp;
    fp=fopen("VE.txt","r");
    if (fp == NULL)
    { 
        printf("\nError to open the file\n");
        exit (1);
    }
    else
    {
        int x;
        fscanf(fp,"%d",&x);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int k;
                fscanf(fp,"%d",&k);
                if(k==1)
                {
                    addnode(i,j);
                }
            }
        }
        fclose(fp);
        int ch,y;
        printf("\n1.Perform BFS\n2.Perform DFS\n\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            initialize();
            BFS(0);
            break;

            case 2:
            initialize();
            DFS(0);
            break;

            default:
            printf("\nWrong Input\n");
        }
    }
}
    