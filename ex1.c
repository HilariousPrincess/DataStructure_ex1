#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node NODE;
struct node{
    int data;
    NODE* next;
};
void iswap(int*a,int*b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
NODE* add(int a)
{
    NODE*p=(NODE*)malloc(sizeof(NODE));
    p->next=NULL;
    p->data=a;
    return p;
}
int main()
{
    srand(time(NULL));
    int n,i,j;
    scanf("%d",&n);
    NODE*pHead=(NODE*)malloc(sizeof(NODE));
    pHead->next=NULL;
    NODE* p=pHead,*q=NULL;
    int*target=(int*)malloc(n*sizeof(int));
    int*crew=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        *(target+i)=i+1;
    }
    for(i=0;i<n;i++)
    {
        iswap(target+i,target+rand()%n);
    }
    for(i=0;i<n;i++)
    {
        *(crew+i)=i+1;
    }
    for(i=0;i<n;i++)
    {
        iswap(crew+i,crew+rand()%n);
    }
    //initializing
    for(i=0;i<=n;i++)
    {
        p->next=add(*(crew+i));
        p=p->next;
    }
    for(p=pHead->next;p->next!=NULL;p=p->next)
    {
        for(i=0;i<n;i++)
        {
            //if(p->data==i+1)
            if(p->data==*(target+i))
            {
                printf("%d%c",i+1,p->next==NULL?'\n':' ');
            }
        }
    }
    for(p=pHead;p->next!=NULL;)
    {
        q=p;
        p=p->next;
        free(q);
    }
    free(target);
    free(crew);
    return 0;
}
