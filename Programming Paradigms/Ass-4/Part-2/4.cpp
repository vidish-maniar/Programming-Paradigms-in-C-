#include<iostream> // For I/O stream.
#include<cstring> // For string operation.
#include<cmath> // for tan() fn.
using namespace std; // namespace.
namespace No_of_Shape { int number=0; } // Keep track of number of shapes to be created.
int area=0;

class ShapeStack { // Abstract class.    
    public:
    virtual void Read()=0;
    virtual double Area()=0;
    ShapeStack *push(int);
    void pop(ShapeStack*);
    void Display();
    class ShapeStack *next;
};

ShapeStack *ShapeStack::push(int i) {
    ShapeStack *temp;
    if(i==1)
    {   Rectangle *R=temp; 
        double a=R->Area;
        R->Read();
        area+=a;    }
    else if(i==2)
    {   Triangle *T=temp; 
        double a=T->Area;
        T->Read();
        area+=a;    }
    else if(i==3)
    {   Circle *C=temp; 
        double a=C->Area;
        C->Read();
        area+=a;    }
    else if(i==4)
    {   Polygon *P=temp; 
        double a=P->Area;
        P->Read();
        area+=a;    }
    else if(i==5)
    {   Sphere *S=temp; 
        double a=S->Area;
        S->Read();
        area+=a;    }
    else if(i==6)
    {   Cuboid *C=temp; 
        double a=C->Area;
        C->Read();
        area+=a;    }
    temp->next=next;
    next=temp->next;
    return next;
}

ShapeStack::pop(ShapeStack *s) {
    if(s->next!=NULL)
    {
        ShapeStack *t=s->next;
        s->next=s->next->next;
        delete t;
    }
}

class Rectangle : public ShapeStack { // concrete class.
    double length,breadth; 
    public:
    void Read() { cout<<"Length of Rectangle: "; cin>>length; cout<<"Breadth of Rectangle: "; cin>>breadth; }
    double Area() { return length*breadth; }
};

class Triangle : public ShapeStack { // concrete class using multiple inheritence.
    double base,height;
    public:
    void Read() { cout<<"Base of Triangle: "; cin>>base; cout<<"Height of Triangle: "; cin>>height; }
    double Area() { return base*height/2; }
};

class Circle : public ShapeStack { // concrete class using multiple inheritence.
    double radius;
    public:
    void Read() { cout<<"Radius of circle: "; cin>>radius; }
    double Area() { return 3.1416*radius*radius; }
};

class Polygon : public ShapeStack { // concrete class using multiple inheritence.
    int n; double s;
    public:
    void Read() { cout<<"No. of sides in polygon: "; cin>>n; cout<<"Side length of polygon: "; cin>>s; }
    double Area() { return ( (n*s*s)/(4*tan(3.1416/n)) ); }
};

class Sphere : public ShapeStack { // concrete class using multiple inheritence.
    double radius;
    public:
    void Read() { cout<<"Radius of Sphere: "; cin>>radius; }
    double Area() { return 4*3.1416*radius*radius; }
};

class Cuboid : public ShapeStack { // concrete class using multiple inheritence.
    double length,breadth,height;
    public:
    void Read() { cout<<"Length of Cuboid: "; cin>>length; cout<<"Breadth of Cuboid: "; cin>>breadth; cout<<"Height of Cuboid: "; cin>>height; }
    double Area() { return 2*(length*breadth+length*height+breadth*height); }
};

int main() { // Supporting min fn.
    int i,j,n; ShapeStack *s;
    cout<<"1 for Reatangle"<<endl;
    cout<<"2 for Triangle"<<endl;
    cout<<"3 for Circle"<<endl;
    cout<<"4 for Polygon"<<endl;
    cout<<"5 for Sphere"<<endl;
    cout<<"6 for cuboid"<<endl;
    for(i=1; i<=3; i++)
    {
        cin>>n;
        s=s->push(n);
    }
    s->pop(s);
    cout<<"Total Area= "<<area<<endl;
}