#include <bits/stdc++.h>
using namespace std; 

class Officcer
{
protected: 
    string ID; 
    string Name; 
    string DOB; 
    
public: 
    virtual void Input() 
    {
        cout << "Enter officer name: "; 
        getline(cin, Name); 

        cout << "Enter officer ID: "; 
        cin >> ID;

        cout << "Enter officer DOB: "; 
        cin >> DOB; 
    }

    virtual void Print() 
    {
        cout << "Name: " << Name << endl; 
        cout << "ID: " << ID << endl; 
        cout << "DOB: " << DOB << endl;       
    }

    virtual int CalculateSalary() = 0; 
};

class GovernmentOfficer : public Officcer
{
private: 
    int BasicSalary, CoefficientSalary, CoeficientBonus; 

public:     
    void Input() 
    { 
        Officcer::Input(); 
        cout << "Enter basic salary: "; 
        cin >> BasicSalary; 

        cout << "Enter coefficient salary: "; 
        cin >> CoefficientSalary; 

        cout << "Enter coefficient bonus: "; 
        cin >> CoeficientBonus; 
    }

    int CalculateSalary() 
    {
        return BasicSalary * CoefficientSalary * CoeficientBonus; 
    }

    void Print() 
    { 
        Officcer::Print(); 
        //cout << "Salary: " << CalculateSalary(); 
    }
};

class ContractualOfficer : public Officcer
{
private: 
    int Wage, WorkingDay, OTCoe; 

public:     
    void Input() 
    { 
        Officcer::Input(); 
        cout << "Enter wage: "; 
        cin >> Wage; 

        cout << "Enter working day: "; 
        cin >> WorkingDay; 

        cout << "Enter overtime coefficient: "; 
        cin >> OTCoe; 
    }

    int CalculateSalary() 
    {
        return Wage * WorkingDay * OTCoe; 
    }

    void Print() 
    { 
        Officcer::Print(); 
        //cout << "Salary: " << CalculateSalary(); 
    }
};

int main() 
{
    //vector<Officcer*> List; 
    Officcer* o; 
    Officcer** of= new Officcer*[50];
    int n; 
    cout << "Enter number of officer: "; 
    cin >> n; 
    cin.ignore(); 

    cout << "-----------------\n"; 
    cout << "1. Government staff\n"; 
    cout << "2. Contract staff\n"; 
    cout << "------------------\n"; 

    for(int i = 0; i < n; i++)
    {   
        
        int choice; 
        cin >> choice; 
        cin.ignore(); 
        if(choice == 1)
        {
            of[i] = new GovernmentOfficer(); 
            of[i]->Input(); 
        }
        else 
        {
            of[i] = new ContractualOfficer(); 
            of[i]->Input(); 
             
        }
    }

    int TotalSalary = 0; 
    for(int i = 0; i < n; i++) 
    { 
        TotalSalary += of[i]->CalculateSalary(); 
    }

    cout << "Total salary: " << TotalSalary; 
}