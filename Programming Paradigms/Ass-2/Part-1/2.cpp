#include<iostream> // Input/Output stream.
using namespace std; // namespace.
namespace stack_size { const int size=5; } // Const. for allocating size of stack.

typedef struct GrowingStack // Struct to keep desired info. about stack.
{ 
    int size;
    int count;
    int *data;
}stack;

void initialize(stack &s,int stacksize) // To initialied stack.
{
    s.count=0;
    s.size=stacksize;
    s.data=new int[stacksize+1]; // Create new space for integer data.
}

inline int push(stack &s,int &d) // To insert particular element in stack.
{
    if(s.count==s.size) { return 0; }
    s.count++;
    s.data[s.count]=d;
    return 1;
}

inline int pop(stack &s,int &d) // To remove top element in stack.
{
    if(s.count==0) { return 0; }
    d=s.data[s.count];
    s.count--; 
    return 1;
}

void Print(stack &s) // To print Stack from top to bottom.
{ 
    int i;
    for (i=s.count; i>0; i--) 
    { cout<<s.data[i]<<endl; }
}

inline int getMaxSize(stack &s) // Gives the maximum number of elements the stack can store.
{
    return (s.size-s.count);
}

inline int currentSize(stack &s) // Give the current number of elements in the stack.
{
    return (s.count);
}

inline int isEmpty(stack &s) // Notify if the stack is empty.
{ 
    if(s.count==0) { return 1; }
    return 0;
}

inline int isFull(stack &s) // Notify if stack is full.
{
    if(s.count==s.size) { return 1; }
    return 0;
}

stack inflate(stack &s,int growsize) // Inflates the stack size by adding extra space in it.
{
    stack s1; int i;
    s.size=s.size+growsize;
    initialize(s1,s.size);
    for(i=1; i<=s.count; i++)
    { push(s1,s.data[i]); }
    return s1; 
}

void initialize(stack &,int=stack_size::size); // Default parameter.

int main() // Suppoting main Fn.
{
    stack s[4]; int i,*a,n,n1,n2,n3,size1,size2,size3;

    // Fill stack-1.
    cout<<"Size of Stack-1: "; cin>>size1; initialize(s[1],size1); 
    cout<<"Number of elements to add in Stack-1: ";
    cin>>n1;
    a=new int[n1]; // create space for input data from user.
    for(i=0; i<n1; i++) { cout<<"element-"<<i+1<<": "; cin>>a[i]; push(s[1],a[i]); }
    delete a; // Free from mem. leak & dangling reference.

    // Fill stack-2.
    cout<<"Size of Stack-2: "; cin>>size2; initialize(s[2],size2);
    cout<<"Number of elements to add in Stack-2: ";
    cin>>n2;
    a=new int[n2]; // create space for input data from user.
    for(i=0; i<n2; i++) { cout<<"element-"<<i+1<<": "; cin>>a[i]; push(s[2],a[i]); }
    delete a; // Free from mem. leak & dangling reference.

    /* Fill stack-3 by poping at from stack 1 and 2, at odd count from stack-1, at even count from stack-2,
    If any stack gets empty first, then the remaining elements from another stack will be popped and pushed in stack3. */
    initialize(s[3],(size1+size2));
    a=new int[n1+n2];
    for(i=0; i<(n1+n2); i++)
    { if(i%2==1 && isEmpty(s[1])==0) { pop(s[1],a[i]); push(s[3],a[i]); }
    else if(i%2==0 && isEmpty(s[2])==0) { pop(s[2],a[i]); push(s[3],a[i]); }
    else if(isEmpty(s[1])==1 && isEmpty(s[2])==0) { pop(s[2],a[i]); push(s[3],a[i]); }
    else if(isEmpty(s[1])==0 && isEmpty(s[2])==1) { pop(s[1],a[i]); push(s[3],a[i]); } }
    delete a; // Free from mem. leak & dangling reference.
    cout<<"Stack-3:"<<"\n";
    Print(s[3]);

    /* State current number of elements & capacity to store elements in stacks, 
    if any stack is full Inflates the stack size by adding extra space in it. */
    for(i=1; i<=3; i++)
    { cout<<"Stack-"<<i<<") have "<<currentSize(s[i])<<" number of element(s)."<<endl;
    if(getMaxSize(s[i])) { cout<<"Stack-"<<i<<") can store maximum "<<getMaxSize(s[i])<<" element(s)."<<endl; } 
    else { cout<<"Expand stack by size: "; cin>>size3; 
    s[i]=inflate(s[i],size3);
    cout<<"Insert an element: "; cin>>n; push(s[i],n);
    cout<<"Stack-"<<i<<"\n";
    Print(s[i]); } }
    
}