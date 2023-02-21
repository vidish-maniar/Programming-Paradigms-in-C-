#include<iostream> // Input/Output stream.
#include<cmath> // For pow() fn.
#include<cstring> // For handling string.
#include<ctime> // For accessing current time for seed of random number generator.
using namespace std; // namespace.
namespace name_size { const int size=30; } // Const. for allocate size to char. name.

typedef struct cll // Struct to as particular node.
{
    char *name;
    struct cll *next;
    struct cll *prev;
}node;

class Game{
public:
node *c;
node* addnode(char *); // Add node in circular linked list.
void print(); // Print the whole circular linked list.
char *Run_game(char * ,char *, int); // Run game.
Game(); // Constructor.
~Game(); // Destructor.
};

node* Game::addnode(char *s) // Add node in circular linked list.
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

void Game::print() // Print the whole circular linked list.
{   int i=1; node *t=c;
if(t!=NULL)
{
    while(t->next!=c) 
    { cout<<"Candidate-"<<i++<<") "<<*t->name<<endl; t=t->next; }
    cout<<"Candidate-"<<i++<<") "<<*t->name<<endl;
}
}

int Fn(int i,int n) // Fn. choose random function at each iteration for to count howmany can. to skip. 
{
    int j,f=1,x;
    x=time(0)%5;
    for(j=1; j<=i; j++)
    { f=f+j*pow(x,j)*pow(-1,j); }
    return f%n;
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
char* Game::Run_game(char *name,char *next_evict,int skip) 
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

Game::Game()
{
    c=NULL;
}

Game::~Game()
{
    delete c;
}