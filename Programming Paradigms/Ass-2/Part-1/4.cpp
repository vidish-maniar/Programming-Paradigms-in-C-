#include<iostream> // Input/Output stream.
using std::cout; using std::cin; using std::endl; // namespace.

struct point // Structure data type.
{
    int x;
    int y;
};

template<typename T> 
inline void swap(T &x,T &y) // Generic method to swap element.
{
    T temp=x; 
    x=y;
    y=temp;
}

int main() // Supporting main Fn.
{
    // Swaping of integers.
    int i1,i2;
    cout<<"integer-1: "; cin>>i1;
    cout<<"integer-2: "; cin>>i2;
    swap(i1,i2);
    cout<<"swaping results: "<<endl;
    cout<<"integer-1: "<<i1<<endl; 
    cout<<"integer-2: "<<i2<<"\n"<<endl;
    
    // Swaping of short integers.
    short s1,s2;
    cout<<"short-1: "; cin>>s1;
    cout<<"short-2: "; cin>>s2;
    swap(s1,s2);
    cout<<"swaping results: "<<endl;
    cout<<"short-1: "<<s1<<endl;
    cout<<"short-2: "<<s2<<"\n"<<endl;

    // Swaping of floating points.
    float f1,f2;
    cout<<"float-1: "; cin>>f1;
    cout<<"float-2: "; cin>>f2;
    swap(f1,f2);
    cout<<"swaping results: "<<endl;
    cout<<"float-1: "<<f1<<endl;
    cout<<"float-2: "<<f2<<"\n"<<endl;

    // Swaping of doubles.
    double d1,d2;
    cout<<"double-1: "; cin>>d1;
    cout<<"double-2: "; cin>>d2;
    swap(d1,d2);
    cout<<"swaping results: "<<endl;
    cout<<"double-1: "<<d1<<endl;
    cout<<"double-2: "<<d2<<"\n"<<endl;

    // Swaping of structures.
    struct point p1,p2;
    cout<<"x1: "; cin>>p1.x;
    cout<<"y1: "; cin>>p1.y;
    cout<<"x2: "; cin>>p2.x;
    cout<<"y2: "; cin>>p2.y;
    swap(p1,p2);
    cout<<"swaping results: "<<endl;
    cout<<"x1: "<<p1.x<<endl;
    cout<<"y1: "<<p1.y<<endl;
    cout<<"x2: "<<p2.x<<endl;
    cout<<"y2: "<<p2.y<<"\n"<<endl;

    return 0;
}