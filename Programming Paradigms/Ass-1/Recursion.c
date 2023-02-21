#include<stdio.h>
#include<stdlib.h>

int Str_cmp(char s1[],char s2[]) // compare two strings alphabetically
{
    if(s1[0]=='\0' && s2[0]=='\0') { return 0; }
    if(s1[0]==s2[0]) { Str_cmp(s1+1,s2+1); }
    else if(s1[0]<s2[0]) { return (-1); }
    else if(s1[0]>s2[0]) { return 1; }
}

int Find_Large(int L[],int n) // find largest among all integers
{
    if(n==1) { return L[n]; }
    else if(n>1) { return (Find_Large(L,(n-1))>L[n]?Find_Large(L,(n-1)):L[n]); }
}

int Search(int L[],int n,int num) // search for given integer in list of integers
{
    if (n==0) { return 0; }
    else if(L[n]==num) { return 1; }
    else { Search(L,(n-1),num); }
}

void Reverse(int L[],int n) // Print list of integers in reverse order
{
    if(n==0) { }
    else if(n>0) { printf("%d ",L[n]); Reverse(L,(n-1)); }
}

int Palindrome(char s[],int n) // Check whether string is palindrome or not
{
    if(n==0 || n==1) { return 1; }
    else if(s[0]==s[n-1]) { Palindrome(s+1,n-2); }
    else if(s[0]!=s[n-1]) { return 0; }
}

void Replacec1byc2inS(char s[],char c1,char c2) // In string replace one char with other 
{
    if(s[0]=='\0') { }
    else if(s[0]==c1) { s[0]=c2; Replacec1byc2inS(s+1,c1,c2); }
    else { Replacec1byc2inS(s+1,c1,c2); }
}

int Sort(int a[],int n) // Sort list of integer
{
    int i,temp=1,max,t;
    if(n==1) { }
    else if(n>1) { for(i=1,max=a[1]; i<=n;i++) { if(a[i]>max) { temp=i; } } t=a[n]; a[n]=a[temp]; a[temp]=t; Sort(a,n-1); }
}