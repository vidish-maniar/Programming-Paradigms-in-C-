#include<iostream> // Input/Output stream.
#include"4-module.h"
#include<cmath> // For pow() fn.
#include<cstring> // For handling string.
#include<ctime> // For accessing current time for seed of random number generator.
using namespace std; // namespace.

int main()
{
    Game g; int i,n,skip,x; char *s,*evict,*next_evict; 
    s=new char[name_size::size];
    next_evict=new char[name_size::size];
    evict=new char[name_size::size];
    cout<<"Number of candidate: "; cin>>n;// Take info. about candidate from user.
    for(i=1; i<=n; i++)
    { cout<<"candidate-"<<i<<") "; cin>>s; g.addnode(s); }
    cout<<"Name of candidate to start game: "; cin>>s;

    for(i=1; i<=n; i++) // Run game.
    { skip=Fn(i,n);
    evict=g.Run_game(s,next_evict,skip);
    if(i!=n) { cout<<"Evicted candidate-"<<i<<": "; Print_string(evict); cout<<"\n"; }
    else { cout<<"Winner candidate: "; Print_string(evict); cout<<"\n"; }
    strcpy(s,next_evict); }
}