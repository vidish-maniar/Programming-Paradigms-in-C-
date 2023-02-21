#include<stdio.h>

void Reverse(int L[],int n)
{
    if(n==0) { }
    else if(n>0) { printf("%d ",L[n]); Reverse(L,(n-1)); }
}

void main()
{
    int i,n,a[20];
    printf("Number of integers to add: "); scanf("%d",&n);
    for(i=1; i<=n; i++)
    { printf("a[%d]= ",i); scanf("%d",&a[i]); }
    printf("List in reverse order:\n"); 
    Reverse(a,n);
}