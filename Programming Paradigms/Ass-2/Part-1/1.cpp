#include<iostream> // Input/Output stream.
#include<fstream> // File stream.
using namespace std; // namespace.
namespace name_size { const int size=30; } // Const. for allocate size to char. name.

typedef struct student // Structure of student data.
{
    char name[name_size::size];
    int age;
    char department[name_size::size];
    int year;
}data;

void Read_StudentData(data &s) // Fn. reads record.
{
    cout<<"Name: "; cin>>s.name;
    cout<<"Age: "; cin>>s.age;
    cout<<"Department: "; cin>>s.department;
    cout<<"Year: "; cin>>s.year;
}

void Print_StudentData(data &s) // Fn. prints record.
{
    cout<<"Name: "<<s.name<<endl;
    cout<<"Age: "<<s.age<<endl;
    cout<<"Department: "<<s.department<<endl;
    cout<<"Year: "<<s.year<<endl;
}

// Overload Fn. for prints record of 's' in file 'f'. 
void Print_StudentData(data &s,ofstream &f) 
{
    int i=1;
    f<<"Student-"<<i++<<")\n";
    f<<"Name:"<<s.name<<" ";
    f<<"Age:"<<s.age<<" ";
    f<<"Department:"<<s.department<<" ";
    f<<"Year:"<<s.year<<" ";
    f<<endl;
}

void Read_file(ifstream &f) // Fn. reads file.
{
    string s;
    while(getline(f,s))
    { cout<<s<<endl; }
    f.close();
}

int main() // Supporting main Fn.
{
    int i,n; ofstream f;
    cout<<"Number of students: "; cin>>n;
    data s[n+1]; // Array of structure of desired size to store student information.

    for(i=1; i<=n; i++) // Reads student data.
    {
        cout<<"Student-"<<i<<")"<<endl;
        Read_StudentData(s[i]);
    }

    f.open("Student data"); // Print student data in file.
    if(!f) { cerr<<"Error: file couldn't be opened"<<endl; 
    exit(0); }
    if(n>0) { cout<<"Student data: "<<endl; }
    for(i=1; i<=n; i++)
    {
        Print_StudentData(s[i],f);
    }

    ifstream f1("Student data"); // Reads student data from file.
    Read_file(f1);
    return 0;
}