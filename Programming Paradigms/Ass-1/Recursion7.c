#include<stdio.h>

int Sort(int a[],int n)
{
    int i,temp=1,max,t;
    if(n==1) { }
    else if(n>1) { for(i=1,max=a[1]; i<=n;i++) { if(a[i]>max) { temp=i; } } t=a[n]; a[n]=a[temp]; a[temp]=t; Sort(a,n-1); }
}

void main()
{
    int i,n,a[20];
    printf("Number of integers to add: "); scanf("%d",&n);
    for(i=1; i<=n; i++) 
    { printf("a[%d]= ",i); scanf("%d",&a[i]); }
    Sort(a,n);
    printf("Sorted elements:\n");
    for(i=1; i<=n; i++)
    { printf("a[%d]=%d\n",i,a[i]); }
}