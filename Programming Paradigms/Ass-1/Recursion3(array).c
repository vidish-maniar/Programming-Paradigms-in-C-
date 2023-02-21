#include<stdio.h>

int Search(int L[],int n,int num)
{
    if (n==0) { return 0; }
    else if(L[n]==num) { return 1; }
    else { Search(L,(n-1),num); }
}

void main()
{
    int i,n,a[20],r,search;
    printf("Number of integers to add: "); scanf("%d",&n);
    for(i=1; i<=n; i++)
    { printf("a[%d]= ",i); scanf("%d",&a[i]); }
    printf("Search a number: "); scanf("%d",&search); 
    r=Search(a,n,search);
    if(r) { printf("Search found.\n"); }
    else { printf("Search not found.\n"); }
}