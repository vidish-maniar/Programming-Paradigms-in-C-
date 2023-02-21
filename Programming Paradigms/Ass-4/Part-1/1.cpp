#include<iostream> // For I/O stream.
#include<cstring> // For string handling.
using namespace std; //namespace.
namespace Char { const int size=30; } // Const. for allocate size to char. name.

class Vehicle {
    public :
    float Price;
    char *Manufacturer;
    Vehicle(); // Default constructor
    Vehicle(float,char*); // Parametrized constructor
    Vehicle(const Vehicle &); // Copy constructor
    Vehicle &operator=(const Vehicle &); // Assignment operator
    void Read(); // Read data
    void Display(); // Display data
};

class Car : public Vehicle {
    char *Color;
    int Number_Of_Seats;
    char *Model;
    public :
    Car(); // Default constructor
    Car(char*,int,char*,float,char*); // Parametrized constructor
    Car(const Car &); // Copy constructor
    Car &operator=(const Car &); // Assignment operator
    void Read(); // Read data
    void Display(); // Display data
};

Vehicle::Vehicle() // Default constructor
{
    Price=0;
    Manufacturer=new char[Char::size];
    strcpy(Manufacturer,"None");
}

Vehicle::Vehicle(float price,char *name) // Parametrized constructor
{
    Price=price;
    Manufacturer=new char[strlen(name)+1];
    strcpy(Manufacturer,name);
}

Vehicle::Vehicle(const Vehicle &Othervehical) // Copy constructor
{
    Price=Othervehical.Price;
    Manufacturer=new char[strlen(Othervehical.Manufacturer)+1];
    strcpy(Manufacturer,Othervehical.Manufacturer);
}

Vehicle &Vehicle::operator=(const Vehicle &Othervehical) // Assignment operator
{
    if(this!=&Othervehical)
    {
        delete []Manufacturer;
        Price=Othervehical.Price;
        Manufacturer=new char[strlen(Othervehical.Manufacturer)+1];
        strcpy(Manufacturer,Othervehical.Manufacturer);
        return *this;
    }
}

void Vehicle::Read() // Read data
{
    cout<<"Price of Vehicle: "; cin>>Price;
    cout<<"Name of Manufacturer: "; cin>>Manufacturer;
}

void Vehicle::Display() // Display data
{
    cout<<"Price of Vehicle: "<<Price<<endl;
    cout<<"Name of Manufacturer: "<<Manufacturer<<endl;
}

Car::Car() // Default constructor
{
    Number_Of_Seats=4;
    Color=new char[Char::size];
    strcpy(Color,"White");
    Model=new char[Char::size];
    strcpy(Model,"2022");
    Price=0;
    Manufacturer=new char[Char::size];
    strcpy(Manufacturer,"None");
}

Car::Car(char *color,int no_of_seat,char *model,float price,char *name) // Parametrized constructor
{
    Number_Of_Seats=no_of_seat;
    Color=new char[strlen(color)+1];
    strcpy(Color,color);
    Model=new char[strlen(model)+1];
    strcpy(Model,model);
}

Car::Car(const Car &Othercar) // Copy constructor
{
    Number_Of_Seats=Othercar.Number_Of_Seats;
    Color=new char[strlen(Othercar.Color)+1];
    strcpy(Color,Othercar.Color);
    Model=new char[strlen(Othercar.Model)+1];
    strcpy(Model,Othercar.Model);
    Price=Othercar.Price;
    Manufacturer=new char[strlen(Othercar.Manufacturer)+1];
    strcpy(Manufacturer,Othercar.Manufacturer);
}

Car &Car::operator=(const Car &Othercar) // Assignment operator
{
    if(this!=&Othercar)
    {
        delete []Color;
        delete []Model;
        Number_Of_Seats=Othercar.Number_Of_Seats;
        Color=new char[strlen(Othercar.Color)+1];
        strcpy(Color,Othercar.Color);
        Model=new char[strlen(Othercar.Model)+1];
        strcpy(Model,Othercar.Model);
        Price=Othercar.Price;
        Manufacturer=new char[strlen(Othercar.Manufacturer)+1];
        strcpy(Manufacturer,Othercar.Manufacturer);
        return *this;
    }
}

void Car::Read() // Read data
{
    cout<<"No. of seats in a car: "; cin>>Number_Of_Seats;
    cout<<"color of car: "; cin>>Color;
    cout<<"Model of car: "; cin>>Model;
    cout<<"Price of car: "; cin>>Price;
    cout<<"Name of Manufacturer: "; cin>>Manufacturer;
}

void Car::Display() // Display data
{
    cout<<"No. of seats in a car: "<<Number_Of_Seats<<endl;
    cout<<"color of car: "<<Color<<endl;
    cout<<"Model of car: "<<Model<<endl;
    cout<<"Price of car: "<<Price<<endl;
    cout<<"Name of Manufacturer: "<<Manufacturer<<endl;
}

int main()
{
    Vehicle v[2]; Car c1;
    v[0].Read();
    v[0].Display();
    cout<<"Object of vehical using assignment operator: "<<endl;
    v[1]=v[0];
    v[1].Display();
    cout<<"\n";
    c1.Read();
    c1.Display();
    cout<<"Object of Car using copy constructor: "<<endl;
    Car c2(c1);
    c2.Display();
}