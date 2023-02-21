#include<iostream> // Input/Output stream.
#include<cmath> // For pow() fn.
#include<cstring> // For handling string.
#include"8-module.h"
using namespace std; // namespace.

int main()
{
    node *c=NULL; int i,j,n,skip,x; char *s,*evict,*next_evict;
    s=new char[name_size::size];
    next_evict=new char[name_size::size];
    evict=new char[name_size::size];
    cout<<"Number of candidate: "; cin>>n;// Take info. about candidate from user.
    for(i=1; i<=n; i++)
    { cout<<"candidate-"<<i<<") "; cin>>s; c=addnode(c,s); }
    cout<<"Name of candidate to start game: "; cin>>s;

    for(i=1; i<=n; i++) // Run game.
    { skip=Fn(i,n);
    evict=Run_game(c,s,next_evict,skip);
    if(i!=n) { cout<<"Evicted candidate-"<<i<<": "; Print_string(evict); cout<<"\n"; }
    else { cout<<"Winner candidate: "; Print_string(evict); cout<<"\n"; }
    strcpy(s,next_evict); }
}