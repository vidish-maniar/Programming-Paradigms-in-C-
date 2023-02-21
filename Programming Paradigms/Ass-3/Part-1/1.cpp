#include<iostream> // Input/Output stream.
#include<fstream> // File stream.
#include<cstring>
using namespace std; // namespace.
namespace name_size { const int size=30; } // Const. for allocate size to char. name. 

// Class to store and perform operations on student data.
class Student_info {
    typedef struct student // Structure of student data.
    {
    char *name;
    int age;
    char *department;
    int year;
    }data;
    public:
    data s; // Structure to store student info.
    void Read_StudentData(); // Fn. reads record.
    void Print_StudentData(); // Fn. prints record.
    Student_info(); // Default constructor.
    ~Student_info(); // Destructor.
    Student_info(const Student_info&); // Copy constructor.
    Student_info &operator=(const Student_info&); // Assignment operator.
};

void Print_string(char *s) // Print string.
{ 
    int j;
    for(j=0; *(s+j)!='\0'; j++) { cout<<*(s+j); }
}

void Student_info::Read_StudentData() // Fn. reads record.
{
    s.name=new char[name_size::size];
    s.department=new char[name_size::size];
    cout<<"First Name: "; cin>>s.name;
    cout<<"Age: "; cin>>s.age;
    cout<<"Department: "; cin>>s.department;
    cout<<"Year: "; cin>>s.year;
}

void Student_info::Print_StudentData() // Fn. prints record.
{
    cout<<"First Name: "; Print_string(s.name); cout<<"\n";
    cout<<"Age: "<<s.age<<endl;
    cout<<"Department: "; Print_string(s.department); cout<<"\n";
    cout<<"Year: "<<s.year<<endl;
}

Student_info::Student_info() // Costructor.
{
    s.name='\0';
    s.age=0;
    s.department='\0';
    s.year=0;
}

Student_info::~Student_info() // Destructor.
{
    delete s.name;
    s.age=0;
    delete s.department;
    s.year=0;
}

Student_info::Student_info(const Student_info &other_std) // Copy constructor.
{
    s.name=new char[strlen(other_std.s.name)+1];
    s.department=new char[strlen(other_std.s.department)+1];
    strcpy(s.name,other_std.s.name);
    strcpy(s.department,other_std.s.department);
    s.age=other_std.s.age;
    s.year=other_std.s.year;
}

Student_info &Student_info::operator=(const Student_info &other_std) // Assignment operator.
{
    if(this!=&other_std)
    {
        delete s.name;
        delete s.department;
        s.name=new char[strlen(other_std.s.name)+1];
        s.department=new char[strlen(other_std.s.department)+1];
        strcpy(s.name,other_std.s.name);
        strcpy(s.department,other_std.s.department);
        s.age=other_std.s.age;
        s.year=other_std.s.year;
        return *this;
    }
}

int main() // Supporting main Fn.
{
    int i,n; ofstream f;
    cout<<"Number of students: "; cin>>n;
    Student_info c[n+1]; // class of info. about student for desired size.

    for(i=1; i<=n; i++) // Reads student data.
    {  
        cout<<"Student-"<<i<<")"<<endl;
        c[i].Read_StudentData();
    }

    f.open("Student data"); // Print student data in file.
    if(!f) { cerr<<"Error: file couldn't be opened"<<endl; 
    exit(0); }
    if(n>0) { cout<<"\nStudent data:"<<endl; }
    for(i=1; i<=n; i++)
    {
        cout<<"Student-"<<i<<")"<<endl;
        c[i].Print_StudentData();
    }

    Student_info c1(c[1]),c2; // Demo of working copy constructor and assignment operator.
    c2=c[2];
    cout<<"\nStudent-1) "<<endl;
    c1.Print_StudentData();
    cout<<"\nStudent-2) "<<endl;
    c2.Print_StudentData();

}