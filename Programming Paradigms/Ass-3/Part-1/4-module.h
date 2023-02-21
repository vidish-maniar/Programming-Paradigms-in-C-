#ifndef game_H
#define game_H
namespace name_size { const int size=30; } // Const. for allocate size to char. name.

typedef struct cll // Struct to as particular.
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
int Fn(int ,int ); // Fn. choose random function at each iteration for to count howmany can. to skip.
void Print_string(char *); // Print string.

#endif