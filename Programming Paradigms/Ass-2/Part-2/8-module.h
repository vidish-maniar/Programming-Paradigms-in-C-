#ifndef game_H
#define game_H
namespace name_size { const int size=30; } // Const. for allocate size to char. name.

typedef struct cll // Struct to as particular.
{
    char *name;
    struct cll *next;
    struct cll *prev;
}node;

node *addnode(node *,char *);
void print(node *);
int Fn(int ,int );
char *Run_game(node *,char *,char *,int);
void Print_string(char *);

#endif