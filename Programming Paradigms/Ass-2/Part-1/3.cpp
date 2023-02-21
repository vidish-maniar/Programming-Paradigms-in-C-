#include<iostream> // Input/Output stream.
#include<cstring> // For handling string.
using namespace std; // namespace.
namespace name_size { const int size=30; } // Const. for allocate size to char. name.

typedef struct cll // Struct to as particular.
{
    char *name;
    struct cll *next;
    struct cll *prev;
}node;

node *addnode(node *c,char *s) // Add node in circular linked list.
{
    node *temp,*t=c;
    temp=new node; // Create new space for store info. about candidate.
    temp->name=new char[name_size::size];
    strcpy(temp->name,s);
    if(c==NULL)
        { c=temp; c->next=c; c->prev=c; }
    else
        { while(t->next!=c) { t=t->next; }
        t->next=temp;
        temp->prev=t;
        temp->next=c;
        c->prev=temp; }
    return c;
}

void print(node *c) // Print the whole circular linked list.
{   int i=1; node *t=c;
if(t!=NULL)
{
    while(t->next!=c) 
    { cout<<"Candidate-"<<i++<<") "<<*t->name<<endl; t=t->next; }
    cout<<"Candidate-"<<i++<<") "<<*t->name<<endl;
}
}

void Print_string(char *s) // Print string.
{ 
    int j;
    for(j=0; *(s+j)!='\0'; j++) { cout<<*(s+j); }
}

/* One round of game in which counting begins at a specified point(randomly selected:name)
on the boundary(c) and proceeds around the circle in a specified direction.
After a specified number of people (skip) is counted to be skipped, a person is
evicted. The procedure is repeated with the remaining people, starting from the person
next to the evicted one(next_evict), going into the same direction and skipping the same number of
people, until only one person remains. The remaining person is selected as the winner
of the game. */
char *Run_game(node *c,char *name,char *next_evict,int skip) 
{ 
    int i=1; char *s1; node *t=c,*temp;
    s1=new char[name_size::size];
    if(skip==0)
    {
        while(strcmp(t->name,name)!=0) { t=t->next; } // Meet person to start the game.
        strcpy(s1,t->name); // Evict particular person from c.
        strcpy(next_evict,(t->next)->name);
        t->prev->next=t->next;
        t->next->prev=t->prev;
        return s1; // returns pointer to node of person to be evicted.
    }
    else if(skip>0)
    {  
        while(strcmp(t->name,name)!=0) { t=t->next; } // Meet person to start the game.
        while(i!=skip) // After skipping 'skip' number of candidate in cw(+) dir. evict the person from c.
            { t=t->next; i++; } 
        temp=t->next;
        t->next=temp->next;
        temp->next->prev=t;
        strcpy(s1,temp->name);
        strcpy(next_evict,(t->next)->name);
        return s1; // returns pointer to node of person to be evicted.
    }
    else if(skip<0)
    {
        skip=skip*(-1);
        while(strcmp(t->name,name)!=0) { t=t->next; } // Meet person to start the game.
        while(i!=skip) // After skipping 'skip' number of candidate in acw(-) dir. evict the person from c.
            { t=t->prev; i++; }
        temp=t->prev;
        t->prev=temp->prev;
        temp->prev->next=t;
        strcpy(s1,temp->name);
        strcpy(next_evict,(t->next)->name);
        return s1; // returns pointer to node of person to be evicted.
    }
}

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