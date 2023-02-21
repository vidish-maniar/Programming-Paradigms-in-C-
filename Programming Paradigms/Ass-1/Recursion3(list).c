#include<stdio.h>
#include<stdlib.h>

typedef struct nodell
{ int data;
struct nodell *next;
}node;

node *createLL(node *L,int num)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=num;
    temp->next=L;
    L=temp;
    return L;
}

int Search(node *L,int num)
{
    if(L==NULL) { return 0; }
    else if(L->data==num) { return 1; }
    else { Search(L->next,num); }
}

void main()
{
    int i,n,num,search,r; node *ll=NULL;
    printf("Number of integers of add: "); scanf("%d",&n);
    for(i=1; i<=n; i++)
    { printf("%d) ",i); scanf("%d",&num); ll=createLL(ll,num); }
    printf("Search: "); scanf("%d",&search); 
    r=Search(ll,search); 
    if(r) { printf("Search found.\n"); }
    else { printf("Search not found.\n"); }
}