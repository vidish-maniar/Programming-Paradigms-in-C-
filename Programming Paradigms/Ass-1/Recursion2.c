#include<stdio.h>

int Find_Large(int L[],int n)
{
    if(n==1) { return L[n]; }
    else if(n>1) { return (Find_Large(L,(n-1))>L[n]?Find_Large(L,(n-1)):L[n]); }
}

void main()
{
    int i,n,a[20],Max;
    printf("Number of integers to add: "); scanf("%d",&n);
    for(i=1; i<=n; i++)
    { printf("a[%d]= ",i); scanf("%d",&a[i]); }
    Max=Find_Large(a,n);
    printf("Maximum element among all integers= %d\n",Max);
}