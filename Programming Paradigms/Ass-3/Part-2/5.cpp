#include<iostream> // Input/Output stream.
#include<cstring> // For handling string operation.
using namespace std; // namespace.
namespace stack_size { const int size=5; } // Const. for allocating size of stack.
namespace Max_Stack_No { const int size=8; } // Max. no. of stack can be create.
namespace Stack_No { int size=0; } // Current no. of stacks.

typedef struct stack // Struct to keep desired info. about stack.
{ 
    int size;
    int count;
    int *data;
}stack;

class Stack
{  
    public:
    stack s;
    void initialize(int); // To initialied stack.
    int push(int &); // To insert particular element in stack.
    int pop( int &); // To remove top element in stack.
    void Print() const; // To print Stack from top to bottom.
    int getMaxSize() const; // Gives the maximum number of elements the stack can store.
    int currentSize() const; // Give the current number of elements in the stack.
    int isEmpty() const; // Notify if the stack is empty.
    int isFull() const; // Notify if stack is full.
    stack inflate(int); // Inflates the stack size by adding extra space in it.
    Stack(); // Default Costructor.
    ~Stack(); // Destructor.
    Stack(const Stack &); // Copy constructor.
    Stack &operator=(const Stack &); // operator '=' overloading.
    Stack &operator+(const Stack &); // operator '+' overloading.
    friend stack operator+(const Stack &,const Stack &); // operator '+' overloading for non-member object.
};

Stack::Stack() // Default Costructor.
{ 
        s.count=0; 
        s.size=0;
        s.data=NULL; // When initialize stack start with zero(0) count.
}

Stack::~Stack() // Destructor.
{
    s.data=NULL;
    delete [] s.data; // Remove all dynamically allocated data available in stack struct.
}

void Stack::initialize(int stacksize) // To initialied stack.
{
    if(Stack_No::size<Max_Stack_No::size)
    {
        Stack_No::size++;
        s.size=stacksize;
        s.data=new int[stacksize]; // Create new space for integer data.
    }
}

inline int Stack::push(int &d) // To insert particular element in stack.
{ 
    if(s.count==s.size) { return 0; }
    memcpy(s.data+s.count,&d,sizeof(d));
    s.count++;
    return 1;
}

inline int Stack::pop(int &d) // To remove top element in stack.
{
    if(s.count==0) { return 0; }
    s.count--;
    memcpy(&d,s.data+s.count,sizeof(d));
    return 1;
}

void Stack::Print() const // To print Stack from top to bottom.
{ 
    int i;
    for (i=s.count-1; i>=0; i--) 
    { cout<<s.data[i]<<endl; }
}

inline int Stack::getMaxSize() const // Gives the maximum number of elements the stack can store.
{
    return (s.size-s.count);
}

inline int Stack::currentSize() const // Give the current number of elements in the stack.
{
    return (s.count);
}

inline int Stack::isEmpty() const // Notify if the stack is empty.
{ 
    if(s.count==0) { return 1; }
    return 0;
}

inline int Stack::isFull() const // Notify if stack is full.
{
    if(s.count==s.size) { return 1; }
    return 0;
}

stack Stack::inflate(int growsize) // Inflates the stack size by adding extra space in it.
{
    Stack c; int i;
    c.initialize(s.size+growsize);
    for(i=0; i<s.count; i++)
    { c.push(s.data[i]); }
    return c.s; 
}

Stack::Stack(const Stack& otherstack) // Copy constructor.
{
    int i;
    initialize(otherstack.s.size);
    s.count=0;
    for(i=0; i<otherstack.s.count; i++)
    { push(otherstack.s.data[i]); }
}

Stack &Stack::operator=(const Stack &otherstack) // operator '=' overloading.
{
    if(this!=&otherstack) // Avoiding self-copy
    { delete s.data;
    int i;
    initialize(otherstack.s.size);
    s.count=0;
    for(i=0; i<otherstack.s.count; i++)
    { push(otherstack.s.data[i]); }
    return *this; }
}

Stack &Stack::operator+(const Stack &otherstack) // operator '+' overloading.
{
    int i;
    s=inflate(otherstack.s.size);
    for(i=0; i<otherstack.s.count; i++)
    { push(otherstack.s.data[i]); }
    return *this;
}

stack operator+(const Stack &otherstack1,const Stack &otherstack2) // operator '+' overloading for non-member object.
{
    Stack c; int i;
    c.initialize(otherstack1.s.size+otherstack2.s.size);
    for(i=0; i<otherstack1.s.count; i++)
    { c.push(otherstack1.s.data[i]); }
    for(i=0; i<otherstack2.s.count; i++)
    { c.push(otherstack2.s.data[i]); }
    return c.s; 
}

void Stack::initialize(int=stack_size::size); // Default parameter.

int main() // Suppoting main Fn.
{
    int i,*a,n,n1,n2,n3,size1,size2,size3; Stack c[4];

    // Fill stack-1.
    cout<<"Size of Stack-1: "; cin>>size1; c[1].initialize(size1); 
    cout<<"Number of elements to add in Stack-1: ";
    cin>>n1;
    a=new int[n1]; // create space for input data from user.
    for(i=0; i<n1; i++) { cout<<"element-"<<i+1<<": "; cin>>a[i]; c[1].push(a[i]); }
    delete a; // Free from mem. leak & dangling reference.

    // Fill stack-2.
    cout<<"Size of Stack-2: "; cin>>size2; c[2].initialize(size2);
    cout<<"Number of elements to add in Stack-2: ";
    cin>>n2;
    a=new int[n2]; // create space for input data from user.
    for(i=0; i<n2; i++) { cout<<"element-"<<i+1<<": "; cin>>a[i]; c[2].push(a[i]); }
    delete a; // Free from mem. leak & dangling reference.

    /* Fill stack-3 by poping at from stack 1 and 2, at odd count from stack-1, at even count from stack-2,
    If any stack gets empty first, then the remaining elements from another stack will be popped and pushed in stack3. */
    c[3].initialize((size1+size2));
    a=new int[n1+n2];
    for(i=0; i<(n1+n2); i++)
    { if(i%2==1 && c[1].isEmpty()==0) { c[1].pop(a[i]); c[3].push(a[i]); }
    else if(i%2==0 && c[2].isEmpty()==0) { c[2].pop(a[i]); c[3].push(a[i]); }
    else if(c[1].isEmpty()==1 && c[2].isEmpty()==0) { c[2].pop(a[i]); c[3].push(a[i]); }
    else if(c[1].isEmpty()==0 && c[2].isEmpty()==1) { c[1].pop(a[i]); c[3].push(a[i]); } }
    delete a; // Free from mem. leak & dangling reference.
    cout<<"Stack-3:"<<"\n";
    c[3].Print();

    /* State current number of elements & capacity to store elements in stacks, 
    if any stack is full Inflates the stack size by adding extra space in it. */
    for(i=1; i<=3; i++)
    { cout<<"Stack-"<<i<<") have "<<c[i].currentSize()<<" number of element(s)."<<endl;
    if(c[i].getMaxSize()) { cout<<"Stack-"<<i<<") can store maximum "<<c[i].getMaxSize()<<" element(s)."<<endl; } 
    else { cout<<"Expand stack by size: "; cin>>size3; 
    c[i].s=c[i].inflate(size3);
    cout<<"Insert an element: "; cin>>n; c[i].push(n);
    cout<<"Stack-"<<i<<"\n";
    c[i].Print(); } }
    Stack c1(c[3]);
    c1+c[3];
    cout<<"\n";
    c1.Print(); 
    cout<<"\n";
    Stack c2;
    c2=c[1]+c[3];
    c2.Print();
    cout<<"\nNo. of initialized stacks: "<<Stack_No::size<<endl;
    cout<<"\n";
    Stack c3; // Which can't furthur access as limit has been exceeded.
    c3=c2;
    c3.Print();
}