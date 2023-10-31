#include <bits/stdc++.h>
using namespace std; 

class HumanResource
{
protected: 
    string Name; 
    string DOB; 
    string StaffID; 

public: 
    HumanResource() 
    { 
        Name = 'A'; 
        DOB = "01011980"; 
        StaffID = "000000"; 
    }
    
    ~HumanResource(){}; 

    virtual void Input() 
    {
        cout << "Name: "; getline(cin, Name); 
        cout << "Day of birth: " ; cin >> DOB; 
        cout << "Staff ID: "; cin >>  StaffID; 
    } 

    virtual void Print() 
    {
        cout << "Name: " << Name << "\n"; 
        cout << "Day of birth: " << DOB << "\n"; 
        cout << "Staff ID: " << StaffID << "\n"; 
    }

    virtual float Income() = 0; 
};

class TeachingAssistant : public HumanResource
{
protected: 
    int NumberofSubject;  

public: 

    TeachingAssistant() : HumanResource()
    {
        NumberofSubject = 0; 
    }
    ~TeachingAssistant() {}; 

    float Income() 
    {
        cout << (NumberofSubject * 0.3 * 18000); 
    }

    void Input()
    {
        HumanResource::Input(); 
        cout << "Number of subject: "; 
        cin >> NumberofSubject; 
    }

    void Print()
    {
        HumanResource::Print();  
       
        cout << "Salary: " <<  Income() << "\n"; 
    }
};

class Lecturer : public HumanResource
{
protected: 
    string AcademicRank; 
    string Degree; 
    int YearofTeaching; 
    vector <string> ListofSubject; 

public: 
    Lecturer() : HumanResource()
    {
        AcademicRank = "None"; 
        Degree = "Master"; 
        YearofTeaching = 5;  
    }
    ~Lecturer() {} ;

    float Income() 
    {
        return (ListofSubject.size() * YearofTeaching * 0.12 * 20000); 
    }

    void Input()
    {
        HumanResource::Input(); 
        cin.ignore();  
        cout << "Academic ranking: "; getline(cin, AcademicRank);  
        cout << "Degree: "; getline(cin,Degree);  
        cout << "Number of teaching years: "; cin >> YearofTeaching;  
        int n; 
        cout << "Number of subject: "; cin >> n;  

        for(int i = 0; i < n; i++)    
        {
            string s; 
            cout << "Subject: "; 
            cin >> s;   
            ListofSubject.push_back(s);  
        }
    }

    void Print()
    {
        HumanResource::Print(); 
        cin.ignore(); 
        cout << "Academic ranking: " << AcademicRank << "\n"; 
        cout << "Degree: " << Degree << "\n"; 
        cout << "Number of teaching years: " << YearofTeaching << "\n"; 
        cout << "Salary: " << Income() << "\n"; 
    }
};

class Researcher : public HumanResource
{
private: 
    vector <string> RProjectID; 
    int NumberofResearchingYears; 

public: 
    Researcher() : HumanResource()
    {
        NumberofResearchingYears = 5;
    }
    ~Researcher(){}; 

    void Input()
    {
        HumanResource::Input(); 
        cin.ignore(); 
        cout << "Number of project: "; int n; cin >> n; 
        for(int i = 0; i < n; i++) 
        { 
            string s; 
            cout << "Enter project ID: "; 
            do
            {
                cin >> s; 
            } while (!isupper(s[0]) || !isdigit(s[1]) || !isdigit(s[2]));
            RProjectID.push_back(s); 
        }
    }

    float Income() 
    {   
        int count = 0;  
        for(int i = 0; i < RProjectID.size(); i++)  
        {
            if(RProjectID[i].front() == 'D') count++;  
        } 

        return (NumberofResearchingYears * 2 + count) * 20000; 
    } 

    void Print()  
    {
        HumanResource::Print(); 
        cout << "Salary: " << Income() << "\n"; 
    }
};


class Specialist : public HumanResource
{
private: 
    vector <string> TProjectID; 
    int NumberofWorkingYears; 

public: 
    Specialist() 
    {
        NumberofWorkingYears = 0;
    }
    ~Specialist() {}; 

    void Input()
    {
        HumanResource::Input(); 
        cin.ignore(); 
        cout << "Number of project: "; int n; cin >> n; 
        for(int i = 0; i < n; i++) 
        { 
            string s; 
            cout << "Enter project ID: "; 
            do
            {
                cin >> s; 
            } while (!isupper(s[0]) || !isdigit(s[1]) || !isdigit(s[2]));
            TProjectID.push_back(s); 
        }

    }

    float Income() 
    {   
        int count = 0; 
        for(int i = 0; i < TProjectID.size(); i++) 
        {
            if(TProjectID[i].front() == 'T') count++; 
        }

        return (NumberofWorkingYears * 2 + count) * 20000; 
    }

    void Print() 
    {
        HumanResource::Print(); 
        cout << "Salary: " << Income() << "\n"; 
    }
};

int main()          
{ 
    vector <HumanResource*> DS; 
    HumanResource *s; 
    int n, choice; 
    
    cout << "-------------------\n"; 
    cout << "1. Lecturer\n"; 
    cout << "2. Teaching Assistant\n"; 
    cout << "3. Researcher\n"; 
    cout << "4. Specialist\n"; 
    cout << "--------------------\n"; 

    cout << "Number of staff: "; cin >> n; 
    for(int i = 0; i < n; i++) 
    {
        cout << "Enter your choice: "; 
        cin >> choice; 
        cin.ignore(); 

        switch (choice)
        {
            case 1: 
                s = new Lecturer(); 
                s->Input(); 
                DS.push_back(s); 
                break; 
            case 2: 
                s = new TeachingAssistant(); 
                s->Input(); 
                DS.push_back(s); 
                break; 
            case 3: 
                s = new Researcher();  
                s->Input();  
                DS.push_back(s);  
                break;  
            case 4:  
                s = new Specialist();  
                s->Input();  
                DS.push_back(s);  
                break;  
            default:  
                break;  
        } 
    } 
    cout << "\n"; 
    cout << "------------Officers list-------------\n"; 
    for(int i = 0; i < n; i++) 
    {
        DS[i]->Print(); 
    }
    cout << "\n"; 
    cout << "-------------Total salary------------\n"; 
    int Cost = 0; 
    for(int i = 0; i < n; i++) 
    {
        Cost += DS[i]->Income(); 
    }
    cout << "Total payment: " << Cost; 
    return 0; 
}