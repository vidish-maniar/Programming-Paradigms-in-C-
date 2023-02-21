#include<iostream> // For I/O stream.
#include<cstring> // For string operation.
#include<cmath> // for tan() fn.
using namespace std; // namespace.

class Shape { // Abstract class.    
    public:
    virtual void Read()=0;
    virtual double Area()=0;
};

class D_2_shape : public Shape {
};

class D_3_shape : public Shape {
};

class Rectangle : public D_2_shape { // concrete class.
    double length,breadth; 
    public:
    void Read() { cout<<"Length of Rectangle: "; cin>>length; cout<<"Breadth of Rectangle: "; cin>>breadth; }
    double Area() { return length*breadth; }
};

class Triangle : public D_2_shape { // concrete class using multi-level inheritence.
    double base,height;
    public:
    void Read() { cout<<"Base of Triangle: "; cin>>base; cout<<"Height of Triangle: "; cin>>height; }
    double Area() { return base*height/2; }
};

class Circle : public D_2_shape { // concrete class using multi-level inheritence.
    double radius;
    public:
    void Read() { cout<<"Radius of circle: "; cin>>radius; }
    double Area() { return 3.1416*radius*radius; }
};

class Polygon : public D_2_shape { // concrete class using multi-level inheritence.
    int n; double s;
    public:
    void Read() { cout<<"No. of sides in polygon: "; cin>>n; cout<<"Side length of polygon: "; cin>>s; }
    double Area() { return ( (n*s*s)/(4*tan(3.1416/n)) ); }
};

class Sphere : public D_3_shape { // concrete class using multi-level inheritence.
    double radius;
    public:
    void Read() { cout<<"Radius of Sphere: "; cin>>radius; }
    double Area() { return 4*3.1416*radius*radius; }
};

class Cuboid : public D_3_shape { // concrete class using multi-level inheritence.
    double length,breadth,height;
    public:
    void Read() { cout<<"Length of Cuboid: "; cin>>length; cout<<"Breadth of Cuboid: "; cin>>breadth; cout<<"Height of Cuboid: "; cin>>height; }
    double Area() { return 2*(length*breadth+length*height+breadth*height); }
};

int main() { // Supporting min fn.
    double TotalArea=0; Shape *p[6];
    Rectangle o1; p[0]=&o1;
    Triangle o2; p[1]=&o2;
    Circle o3; p[2]=&o3;
    Polygon o4; p[3]=&o4;
    Sphere o5; p[4]=&o5;
    Cuboid o6;p[5]=&o6;
    for (int i=0; i<=5; i++) { p[i]->Read(); }
    for (int i=0; i<=5; i++) { TotalArea+=p[i]->Area(); cout<<p[i]->Area()<<endl; }
    cout<<"Total Area= "<<TotalArea<<endl;
}