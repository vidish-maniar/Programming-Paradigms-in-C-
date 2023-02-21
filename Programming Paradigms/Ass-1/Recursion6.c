#include<stdio.h>

void Replacec1byc2inS(char s[],char c1,char c2)
{
    if(s[0]=='\0') { }
    else if(s[0]==c1) { s[0]=c2; Replacec1byc2inS(s+1,c1,c2); }
    else { Replacec1byc2inS(s+1,c1,c2); }
}

void main()
{
    int i=0,n; char c,c1,c2,s[100];
    printf("String: "); 
    do { s[i++]=c=getchar(); }while(c!='\n'); s[--i]='\0';
    printf("replace char: "); c1=getchar();
    c=getchar();
    printf("Replacing char: ");
    c2=getchar();
    Replacec1byc2inS(s,c1,c2); 
    printf("New String: %s\n",s);
}