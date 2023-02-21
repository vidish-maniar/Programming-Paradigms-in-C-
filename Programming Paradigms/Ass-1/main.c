#include<stdio.h>
#include<stdlib.h>
#include"Recursion.h"

int main()
{
    int to,i,n,a[20],r,Max,search; char c,c1,c2,s[100],s1[100],s2[100];
    printf("Case-1) String compare. \n"); 
    printf("Case-2) Find lagest among all integers. \n");
    printf("Case-3) Search for an element among List integers. \n");
    printf("Case-4) Print given List in reverse order. \n");
    printf("Case-5) Check for String Palindrome or not. \n");
    printf("Case-6) Replace any one char of string by another char. \n");
    printf("Case-7) Sort all integers. \n");  
    printf("Choose option: "); scanf("%d",&to);
    switch(to)
    { case 1: 
    { i=0; getchar();
    printf("String-1: "); 
    do { s1[i++]=c=getchar(); }while(c!='\n'); s1[--i]='\0'; i=0;
    printf("String-2: "); 
    do { s2[i++]=c=getchar(); }while(c!='\n'); s2[--i]='\0';
    r=Str_cmp(s1,s2);
    if(r==0) { printf("String-1 & string-2 are same.\n"); }
    else if(r==(-1)) { printf("String-1 is alphabetically comes before String-2.\n"); }
    else { printf("String-1 is alphabetically comes after String-2.\n"); } break; }

    case 2:
    { printf("Number of integers to add: "); scanf("%d",&n);
    for(i=1; i<=n; i++)
    { printf("a[%d]= ",i); scanf("%d",&a[i]); }
    Max=Find_Large(a,n);
    printf("Maximum element among all integers= %d\n",Max); break; }

    case 3:
    { printf("Number of integers to add: "); scanf("%d",&n);
    for(i=1; i<=n; i++)
    { printf("a[%d]= ",i); scanf("%d",&a[i]); }
    printf("Search a number: "); scanf("%d",&search); 
    r=Search(a,n,search);
    if(r) { printf("Search found.\n"); }
    else { printf("Search not found.\n"); } break; }

    case 4:
    { printf("Number of integers to add: "); scanf("%d",&n);
    for(i=1; i<=n; i++)
    { printf("a[%d]= ",i); scanf("%d",&a[i]); }
    printf("List in reverse order:\n"); 
    Reverse(a,n); break; }

    case 5:
    { i=0; getchar();
    printf("String: "); 
    do { s[i++]=c=getchar(); }while(c!='\n'); s[--i]='\0'; 
    r=Palindrome(s,i);
    if(r) { printf("String is Palindrome. \n"); }
    else { printf("String isn't Palindrome. \n"); } break; }

    case 6:
    { i=0; getchar();
    printf("String: "); 
    do { s[i++]=c=getchar(); }while(c!='\n'); s[--i]='\0';
    printf("replace char: "); c1=getchar();
    c=getchar();
    printf("Replacing char: ");
    c2=getchar();
    Replacec1byc2inS(s,c1,c2); 
    printf("New String: %s\n",s); break; }

    case 7:
    { printf("Number of integers to add: "); scanf("%d",&n);
    for(i=1; i<=n; i++) 
    { printf("a[%d]= ",i); scanf("%d",&a[i]); }
    Sort(a,n);
    printf("Sorted elements:\n");
    for(i=1; i<=n; i++)
    { printf("a[%d]=%d\n",i,a[i]); } break; }

    default:
    { printf("Not valid option \n"); break; }
    }
    return 0;
}