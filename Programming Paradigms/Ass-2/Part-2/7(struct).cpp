#include<iostream> // Input/Output stream.
#include<cstring> // For memcpy.
using namespace std; // namespace.
namespace stack_size { const int size=5; } // Const. for allocating size of stack.
namespace name_size { const int size=30; } // Const. for allocate size to char. name.

typedef struct student_info // Structure for store student information.
{
    char *name;
    int age;
    float mark;
}record;

struct GrowingStack // Generic Struct to keep desired info. about stack.
{ 
    int size;
    int dsize;
    int count;
    unsigned char *data;
};

void initialize(struct GrowingStack &s,int datasize,int stacksize) // To initialied stack.
{
    s.count=0;
    s.size=stacksize;
    s.dsize=datasize;
    s.data=new unsigned char[datasize*stacksize];
}

inline int push(struct GrowingStack &s,void *d) // To insert particular element in stack.
{
    if(s.count==s.size) { return 0; }
    memcpy((s.data+(s.dsize*s.count)),d,s.dsize); 
    s.count++;
    return 1;
}

inline int pop(struct GrowingStack &s,void *d) // To remove top element in stack.
{
    if(s.count==0) { return 0; }
    s.count--;
    memcpy(d,(s.data+(s.dsize*s.count)),s.dsize); 
    return 1;
}

void Print_string(unsigned char *l) // Print string.
{ 
    int j;
    for(j=0; *(l+j)!='\0'; j++) { cout<<*(l+j); }
}

void print_record(unsigned char *r)
{
    Print_string(r); cout<<"\n";
    cout<<*((int*)(r+4))<<endl;
    cout<<*((float*)(r+8))<<endl;
}

void Print(struct GrowingStack &s) // Print stack from bottom to top.
{
    int i,j;
    if(s.dsize==sizeof(record))
    {
        for(i=0; i<s.count; i++)
        {
            print_record(s.data+(i*s.dsize));
        }
    }
    else
    { 
        for(i=0; i<s.count; i++)
        {
            if(s.dsize==sizeof(int)) { cout<<*((int*)(s.data+(i*s.dsize)))<<endl; }
            else if(s.dsize==sizeof(float)) { cout<<*((float*)(s.data+(i*s.dsize)))<<endl; }
            else if(s.dsize==sizeof(char)) { cout<<*((char*)(s.data+(i*s.dsize)))<<endl; }
        } 
    }
}

inline int getMaxSize(struct GrowingStack &s) // Gives the maximum number of elements the stack can store.
{
    return (s.size-s.count);
}

inline int currentSize(struct GrowingStack &s) // Give the current number of elements in the stack.
{
    return (s.count);
}

inline int isEmpty(struct GrowingStack &s) // Notify if the stack is empty.
{ 
    if(s.count==0) { return 1; }
    return 0;
}

inline int isFull(struct GrowingStack &s) // Notify if stack is full.
{
    if(s.count==s.size) { return 1; }
    return 0;
}

struct GrowingStack inflate(struct GrowingStack &s,int growsize) // Inflates the stack size by adding extra space in it.
{
    struct GrowingStack s1; int i;
    s.size=s.size+growsize;
    initialize(s1,s.dsize,(s.dsize*s.size));
    for(i=0; i<s.count; i++)
    { push(s1,(s.data+i*s.dsize)); }
    return s1; 
}

int main() // Suppoting main Fn.
{
    struct GrowingStack s[4]; int i,n1,n2,n3,size1,size2,size3; record *a;

    // Fill stack-1.
    cout<<"Size of Stack-1: "; cin>>size1; initialize(s[1],sizeof(record),size1); 
    cout<<"Number of elements to add in Stack-1: ";
    cin>>n1;
    a=new record[n1]; // create space for input data from user.
    for(i=0; i<n1; i++) 
    { a[i].name=new char[name_size::size];
    cout<<"Student-"<<i+1<<": "<<endl; 
    cout<<"Name: "; cin>>a[i].name;
    cout<<"Age: "; cin>>a[i].age;
    cout<<"Marks: "; cin>>a[i].mark;  
    push(s[1],a+i); }
    delete a; // Free from mem. leak & dangling reference.

    // Fill stack-2.
    cout<<"Size of Stack-2: "; cin>>size2; initialize(s[2],sizeof(record),size2);
    cout<<"Number of elements to add in Stack-2: ";
    cin>>n2;
    a=new record[n2]; // create space for input data from user.
    for(i=0; i<n2; i++) 
    { a[i].name=new char[name_size::size];
    cout<<"Student-"<<i+1<<": "<<endl; 
    cout<<"Name: "; cin>>a[i].name;
    cout<<"Age: "; cin>>a[i].age;
    cout<<"Marks: "; cin>>a[i].mark;
    push(s[2],a+i); }
    delete a; // Free from mem. leak & dangling reference.

    /* Fill stack-3 by poping at from stack 1 and 2, at odd count from stack-1, at even count from stack-2,
    If any stack gets empty first, then the remaining elements from another stack will be popped and pushed in stack3. */
    initialize(s[3],sizeof(record),(size1+size2));
    a=new record[n1+n2];
    for(i=0; i<(n1+n2); i++)
    { if(i%2==1 && isEmpty(s[1])==0) { pop(s[1],a+i); push(s[3],a+i); }
    else if(i%2==0 && isEmpty(s[2])==0) { pop(s[2],a+i); push(s[3],a+i); }
    else if(isEmpty(s[1])==1 && isEmpty(s[2])==0) { pop(s[2],a+i); push(s[3],a+i); }
    else if(isEmpty(s[1])==0 && isEmpty(s[2])==1) { pop(s[1],a+i); push(s[3],a+i); } }
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
    a=new record[1];
    a->name=new char[name_size::size];
    cout<<"Insert an student info: "<<endl;
    cout<<"Name: "; cin>>a->name;
    cout<<"Age: "; cin>>a->age;
    cout<<"Marks: "; cin>>a->mark;
    push(s[i],a);
    cout<<"Stack-"<<i<<"\n";
    Print(s[i]); } }
    
}