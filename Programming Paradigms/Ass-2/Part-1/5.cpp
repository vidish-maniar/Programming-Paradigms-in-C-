#include<iostream> // Input/Output stream.
using std::cout; using std::cin; using std::endl; // namespace.

template<typename T>
inline void swap(T &x,T &y) // Generic method to swap elements.
{
    T temp=x; 
    x=y;
    y=temp;
}

template<typename T>                                                         
void Sort(T arr[],int n) // Generic method to sort elements.
{
    int i,j;
    for(i=n; i>1; i--)
    { for(j=1; j<i; j++) 
    { if(arr[j]>arr[j+1]) { swap(arr[j],arr[j+1]); } } }
}

int main() // Supporting main Fn.
{
    int a[10],i,n; double d[10];
    cout<<"Number of elements to add: "; cin>>n;
    
    // Sort the integers.
    for(i=1; i<=n; i++)
    { cout<<"int-"<<i<<": "; cin>>a[i]; }
    Sort(a,n);
    cout<<"Sorted integers elements: "<<endl;
    for(i=1; i<=n; i++)
    { cout<<"int-"<<i<<": "<<a[i]<<endl; }

    // Sort the doubles.
    for(i=1; i<=n; i++)
    { cout<<"double-"<<i<<": "; cin>>d[i]; }
    Sort(d,n);
    cout<<"Sorted doubles elements: "<<endl;
    for(i=1; i<=n; i++)
    { cout<<"double-"<<i<<": "<<d[i]<<endl; }
    return 0;
}