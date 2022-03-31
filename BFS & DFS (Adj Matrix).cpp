#include<stdio.h>
#include<stdlib.h>

int visited[6];
void initialize()
{
    for(int i=0;i<6;i++)
    {
        visited[i]=0;
    }
}

int q[6];
int front=0,rear=-1;

void push(int a)
{
    if(rear!=6-1)
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

void BFS(int a,int gr[6][6])
{
    printf("%c ",(char)(a+65));
    visited[a]=1;
    push(a);
    while(isEmpty()==0)
    {
        int u=delete();
        for(int i=0;i<6;i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                printf("%c ",(char)(i+65));
                push(i);
            }
        }
    }
}

void DFS(int a,int gr[6][6])
{
    visited[a]=1;
    printf("%c ",(char)(a+65));
    for(int i=0;i<6;i++)
    {
        if(gr[a][i]==1 && visited[i]==0)
        {
            DFS(i,gr);
        }
    }
}

void main()
{
    FILE *fp;
    fp=fopen("VE.txt","r");
    if (fp == NULL)
    { 
        printf("\nError to open the file\n");
        exit (1);
    }
    else
    {
        int n;
        fscanf(fp,"%d",&n);
        int gr[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                fscanf(fp,"%d",&gr[i][j]);
            }
        }
        fclose(fp);
        
        int ch,y;
        char v;
        printf("1.Show BFS\n2.Show DFS\n\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            BFS(0,gr);
            break;

            case 2:
            DFS(0,gr);
            break;

            default:
            printf("\nWrong Input\n");
        }
    }
}
