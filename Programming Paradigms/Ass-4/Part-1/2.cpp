#include<iostream> // For I/O stream.
#include<cstring> // For string operation.
using namespace std; // namespace.
namespace Char { const int size=30; } // Const. for allocate size to char. name.

class Person {
    public:
    void virtual Read()=0;
    void virtual Display()=0;
};

class Student : public Person {
    char *Name;
    int Age;
    char *Gender;
    char *Department;
    int Year;
    public:
    Student(); // Default constructor.
    ~Student(); // Destructor.
    Student(const Student &); // copy constructor.
    Student &operator=(const Student &); // Assignment operator.
    void Read(); // Read data
    void Display(); // Display data
};

Student::Student() // Default constructor.
{
    Name=new char[Char::size];
    Gender=new char[Char::size];
    Department=new char[Char::size];
    strcpy(Name,"None");
    Age=0;
    strcpy(Gender,"Male");
    strcpy(Department,"CST");
    Year=0;
}

Student::~Student() // Destructor.
{
    Name=NULL;
    delete []Name;
    Gender=NULL;
    delete []Gender;
    Department=NULL;
    delete []Department;
}

Student::Student(const Student &OtherStudent) // copy constructor.
{
    Name=new char[Char::size];
    strcpy(Name,OtherStudent.Name);
    Age=OtherStudent.Age;
    Gender=new char[Char::size];
    strcpy(Gender,OtherStudent.Gender);
    Department=new char[Char::size];
    strcpy(Department,OtherStudent.Department);
    Year=OtherStudent.Year;
}

Student &Student::operator=(const Student &OtherStudent) // Assignment operator.
{
    if(this!=&OtherStudent)
    {
        delete []Name;
        delete []Gender;
        delete []Department;
        Name=new char[Char::size];
        strcpy(Name,OtherStudent.Name);
        Age=OtherStudent.Age;
        Gender=new char[Char::size];
        strcpy(Gender,OtherStudent.Gender);
        Department=new char[Char::size];
        strcpy(Department,OtherStudent.Department);
        Year=OtherStudent.Year;
        return *this;
    }
}

void Student::Read() //  Read data.
{
    Name=new char[Char::size];
    Gender=new char[Char::size];
    Department=new char[Char::size];
    cout<<"Name of Student: "; cin>>Name;
    cout<<"Age of Student: "; cin>>Age;
    cout<<"Gender of Student: "; cin>>Gender;
    cout<<"Department of Student: "; cin>>Department;
    cout<<"Year of Student: "; cin>>Year;    
}

void Student::Display() // Display data.
{
    cout<<"Name of Student: "<<Name<<endl;
    cout<<"Age of Student: "<<Age<<endl;
    cout<<"Gender of Student: "<<Gender<<endl;
    cout<<"Department of Student: "<<Department<<endl;
    cout<<"Year of Student: "<<Year<<endl;
}

class Clerk : public Person {
    char *Name;
    int Age;
    char *Gender;
    int WorkLoad;
    int Salary;
    public:
    Clerk(); // Default constructor.
    ~Clerk(); // Destructor.
    Clerk(const Clerk &); // copy constructor.
    Clerk &operator=(const Clerk &); // Assignment operator.
    void Read(); // Read data
    void Display(); // Display data
};

Clerk::Clerk() // Default constructor.
{
    Name=new char[Char::size];
    Gender=new char[Char::size];
    strcpy(Name,"None");
    Age=0;
    strcpy(Gender,"Female");
    WorkLoad=0;
    Salary=0;
}

Clerk::~Clerk() // Destructor.
{
    Name=NULL;
    delete []Name;
    Gender=NULL;
    delete []Gender;
}

Clerk::Clerk(const Clerk &OtherClerk) // copy constructor.
{
    Name=new char[Char::size];
    strcpy(Name,OtherClerk.Name);
    Age=OtherClerk.Age;
    Gender=new char[Char::size];
    strcpy(Gender,OtherClerk.Gender);
    WorkLoad=OtherClerk.WorkLoad;
    Salary=OtherClerk.Salary;
}

Clerk &Clerk::operator=(const Clerk &OtherClerk) // Assignment operator.
{
    if(this!=&OtherClerk)
    {
        delete []Name;
        delete []Gender;
        Name=new char[Char::size];
        strcpy(Name,OtherClerk.Name);
        Age=OtherClerk.Age;
        Gender=new char[Char::size];
        strcpy(Gender,OtherClerk.Gender);
        WorkLoad=OtherClerk.WorkLoad;
        Salary=OtherClerk.Salary;
        return *this;
    }
}

void Clerk::Read() //  Read data.
{
    Name=new char[Char::size];
    Gender=new char[Char::size];
    cout<<"Name of Clerk: "; cin>>Name;
    cout<<"Age of Clerk: "; cin>>Age;
    cout<<"Gender of Clerk: "; cin>>Gender;
    cout<<"WorkLoad of Clerk: "; cin>>WorkLoad;
    cout<<"Salary of Clerk: "; cin>>Salary;    
}

void Clerk::Display() // Display data.
{
    cout<<"Name of Clerk: "<<Name<<endl;
    cout<<"Age of Clerk: "<<Age<<endl;
    cout<<"Gender of Clerk: "<<Gender<<endl;
    cout<<"WorkLoad of Clerk: "<<WorkLoad<<endl;
    cout<<"Salary of Clerk: "<<Salary<<endl;
}

class Professor : public Person {
    char *Name;
    int Age;
    char *Gender;
    char *Department;
    int CourseLoad;
    int Salary;
    public:
    Professor(); // Default constructor.
    ~Professor(); // Destructor.
    Professor(const Professor &); // copy constructor.
    Professor &operator=(const Professor &); // Assignment operator.
    void Read(); // Read data
    void Display(); // Display data
};

Professor::Professor() // Default constructor.
{
    Name=new char[Char::size];
    Gender=new char[Char::size];
    Department=new char[Char::size];
    strcpy(Name,"None");
    Age=0;
    strcpy(Gender,"Female");
    strcpy(Department,"IT");
    CourseLoad=0;
    Salary=0;
}

Professor::~Professor() // Destructor.
{
    Name=NULL;
    delete []Name;
    Gender=NULL;
    delete []Gender;
    Department=NULL;
    delete []Department;
}

Professor::Professor(const Professor &OtherProfessor) // copy constructor.
{
    Name=new char[Char::size];
    strcpy(Name,OtherProfessor.Name);
    Age=OtherProfessor.Age;
    Gender=new char[Char::size];
    strcpy(Gender,OtherProfessor.Gender);
    Department=new char[Char::size];
    strcpy(Department,OtherProfessor.Department);
    CourseLoad=OtherProfessor.CourseLoad;
    Salary=OtherProfessor.Salary;
}

Professor &Professor::operator=(const Professor &OtherProfessor) // Assignment operator.
{
    if(this!=&OtherProfessor)
    {
        delete []Name;
        delete []Gender;
        delete []Department;
        Name=new char[Char::size];
        strcpy(Name,OtherProfessor.Name);
        Age=OtherProfessor.Age;
        Gender=new char[Char::size];
        strcpy(Gender,OtherProfessor.Gender);
        Department=new char[Char::size];
        strcpy(Department,OtherProfessor.Department);
        CourseLoad=OtherProfessor.CourseLoad;
        Salary=OtherProfessor.Salary;
        return *this;
    }
}

void Professor::Read() //  Read data.
{
    Name=new char[Char::size];
    Gender=new char[Char::size];
    Department=new char[Char::size];
    cout<<"Name of Professor: "; cin>>Name;
    cout<<"Age of Professor: "; cin>>Age;
    cout<<"Gender of Professor: "; cin>>Gender;
    cout<<"Department of Professor: "; cin>>Department;
    cout<<"CourseLoad of Professor: "; cin>>CourseLoad;
    cout<<"Salary of Professor: "; cin>>Salary;    
}

void Professor::Display() // Display data.
{
    cout<<"Name of Professor: "<<Name<<endl;
    cout<<"Age of Professor: "<<Age<<endl;
    cout<<"Gender of Professor: "<<Gender<<endl;
    cout<<"Department of Professor: "<<Department<<endl;
    cout<<"CourseLoad of Professor: "<<CourseLoad<<endl;
    cout<<"Salary of Professor: "<<Salary<<endl;
}

int main() // Supporting main fn.
{
    Person *p[3]; 
    Student S; Clerk C; Professor P;
    p[0]=&S; p[0]->Read(); p[0]->Display();
    cout<<"\n";
    p[1]=&C; p[1]->Read(); p[1]->Display();
    cout<<"\n";
    p[2]=&P; p[2]->Read(); p[2]->Display();
    cout<<"\n";
    Student s(S); // Copy constructor.
    s.Display();
    cout<<"\n";
    Clerk c; c=C; // Assignmnet operator.
    C.Display();
    cout<<"\n";
    Professor P1; // Default constructor.
    P1.Display();
}