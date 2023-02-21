#include<stdio.h>

int Palindrome(char s[],int n)
{
    if(n==0 || n==1) { return 1; }
    else if(s[0]==s[n-1]) { Palindrome(s+1,n-2); }
    else if(s[0]!=s[n-1]) { return 0; }
}

void main()
{
    int i=0,n,r; char c,s[100]; 
    printf("String: "); 
    do { s[i++]=c=getchar(); }while(c!='\n'); s[--i]='\0'; 
    r=Palindrome(s,i);
    if(r) { printf("String is Palindrome. \n"); }
    else { printf("String isn't Palindrome. \n"); }
}