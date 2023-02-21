#include<iostream> // For I/O stream.
using namespace std; // namespace.
int num_of_matchs=1; // Keeps record of number pf played matches.

class Cricketer {
    public:
    string name; // name of player.
    string match_against[10]; // Played v/s.
    int win; // Win/loos.
    Cricketer(); // default con.
    Cricketer(string); // con.
};

class Batsman : virtual public Cricketer {
    public:
    float run[10];
    float Best_score;
    Batsman();
};

class Bowler : virtual public Cricketer {
    public:
    int wicket[10];
    int Max_Wicket;
    Bowler();
};

class Allrounder : public Batsman, public Bowler {
    public:
    int allrounder; // allrounder or not.
    Allrounder(); // default con.
    Allrounder(int); //con.
    void Insert_record(); // Insert match wise record.
    float batting_avg(); // Gives avg. runs.
    int Total_wicket(); // Gives Total wickets.
    string Max_score(); // Gives match with max. score.
    string Max_wicket(); // Gives match with max. wicket.
};

Cricketer::Cricketer() { // default con.
    name='\0';
    win=0;
}

Cricketer::Cricketer(string s) { // Parameterize con.
    name=s;
}

Batsman::Batsman() { // default con.
    Best_score=0;
}

Bowler::Bowler() { // default con.
    Max_Wicket=0;
}

Allrounder::Allrounder() { // default con.
    allrounder=0;
}

Allrounder::Allrounder(int yes) { // Parameterize con.
    allrounder=yes;
}

void Allrounder::Insert_record() { // Insert match wise record.
    cout<<"Match with country: "; cin>>match_against[num_of_matchs];
    cout<<"Run: "; cin>>run[num_of_matchs];
    cout<<"Wickets: "; cin>>wicket[num_of_matchs];
    if(run[num_of_matchs]>Best_score) { Best_score=run[num_of_matchs]; }
    if(wicket[num_of_matchs]>Max_Wicket) { Max_Wicket=wicket[num_of_matchs]; }
    num_of_matchs++;
}

float Allrounder::batting_avg() { // Gives avg. runs.
    float avg_score=0;
    for(int k=1; k<num_of_matchs; k++)
    {
        avg_score+=run[k];
    }
    avg_score/=(num_of_matchs-1);
    return avg_score;
}

int Allrounder::Total_wicket() { // Gives Total wickets.
    int total_wicket=0;
    for(int k=1; k<num_of_matchs; k++)
    {
        total_wicket+=wicket[k];
    }
    return total_wicket;
}

string Allrounder::Max_score() { // Gives match with max. score.
    string s;
    for(int k=1; k<num_of_matchs; k++)
    {
        if(run[k]==Best_score) { return match_against[k]; }
    }
}

string Allrounder::Max_wicket() { // Gives match with max. wicket.
    string s;
    for(int k=1; k<num_of_matchs; k++)
    {
        if(wicket[k]==Max_Wicket) { return match_against[k]; }
    }
}

int main() // Supporting main function.
{
    int i,j,n; string s;
    cout<<"Name of player: "; cin>>s;
    cout<<"Number of mathces played: "; cin>>n;
    Cricketer C(s);
    Batsman B1;
    Bowler B2;
    Allrounder A;
    for(i=1; i<=n; i++)
    {
        A.Insert_record();
    }
    s=A.Max_score();
    cout<<"Best score: "<<A.Best_score<<" ,Against: "<<s<<endl;
    s=A.Max_wicket();
    cout<<"Max Wicket: "<<A.Max_Wicket<<" ,Against: "<<s<<endl;
    cout<<"Avg. score: "<<A.batting_avg()<<endl;
    cout<<"Total wicket: "<<A.Total_wicket()<<endl;
}