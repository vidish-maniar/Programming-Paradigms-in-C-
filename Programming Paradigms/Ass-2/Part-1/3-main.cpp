#include<iostream> // Input/Output stream.
#include<cstring> // For handling string.
#include"3-module.h"
using namespace std; // namespace.

char *Run_game(node *,char *,char *,int=1);
int main()
{
    node *c=NULL; int i,n,skip; char *s,*evict,*next_evict; 
    s=new char[name_size::size];
    next_evict=new char[name_size::size];
    evict=new char[name_size::size];
    cout<<"Number of candidate: "; cin>>n; // Take info. about candidate from user.
    for(i=1; i<=n; i++)
    { cout<<"candidate-"<<i<<") "; cin>>s; c=addnode(c,s); }
    cout<<"Name of candidate to start game: "; cin>>s;
    cout<<"Number of candidates to skip before evict the person: "; cin>>skip;

    for(i=1; i<=n; i++) // Run game.
    { evict=Run_game(c,s,next_evict,skip);
    if(i!=n) { cout<<"Evicted candidate-"<<i<<": "; Print_string(evict); cout<<"\n"; }
    else { cout<<"Winner candidate: "; Print_string(evict); cout<<"\n"; }
    strcpy(s,next_evict); }
}