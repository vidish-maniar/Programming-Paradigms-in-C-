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

void reverse_list(node *L)
{
    node *t,*ptr;
    if(L==NULL) { }
    else { t=L; while(t->next!=NULL) { ptr=t; t=t->next; } printf("%d ",t->data); ptr->next=NULL; free(t); reverse_list(L); }
}

void main()
{
    int i,n,num,r; node *ll=NULL;
    printf("Number of integers of add: "); scanf("%d",&n);
    for(i=1; i<=n; i++)
    { printf("%d) ",i); scanf("%d",&num); ll=createLL(ll,num); }
    printf("List in reverse order: \n");
    reverse_list(ll);   
}