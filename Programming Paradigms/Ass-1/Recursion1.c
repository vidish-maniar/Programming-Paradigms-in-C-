#include<stdio.h>

int Str_cmp(char s1[],char s2[])
{
    if(s1[0]=='\0' && s2[0]=='\0') { return 0; }
    if(s1[0]==s2[0]) { Str_cmp(s1+1,s2+1); }
    else if(s1[0]<s2[0]) { return (-1); }
    else if(s1[0]>s2[0]) { return 1; }
}

void main()
{
    int i=0,r; char c,s1[100],s2[100];
    printf("String-1: "); 
    do { s1[i++]=c=getchar(); }while(c!='\n'); s1[--i]='\0'; i=0;
    printf("String-2: "); 
    do { s2[i++]=c=getchar(); }while(c!='\n'); s2[--i]='\0';
    r=Str_cmp(s1,s2);
    if(r==0) { printf("String-1 & string-2 are same.\n"); }
    else if(r==(-1)) { printf("String-1 is alphabetically comes before String-2.\n"); }
    else { printf("String-1 is alphabetically comes after String-2.\n"); }
}