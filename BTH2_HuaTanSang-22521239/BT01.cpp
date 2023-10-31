#include <iostream> 
#include <string> 

using namespace std; 

class NhanVien
{
private: 
    string Name; 
    int WorkingDay;
    string ID; 
    string Title;
    float CoSalary; 

public: 
    void SetName(string x)
    {
        Name = x; 
    }

    string GetName()
    {
        return Name; 
    }

    void SetWorkingDay(int x)
    {
        WorkingDay = x; 
    }

    int GetWorkingDay()
    {
        return WorkingDay; 
    }

    void SetID()
    {
        ID = GetName() + to_string(GetWorkingDay()); 
    }

    void SetTitle()
    {
        if(GetWorkingDay() <= 365) 
            Title = "Nhan vien"; 
        else if(GetWorkingDay() > 365 && GetWorkingDay() < 730)
            Title = "Quan ly"; 
        else if(GetWorkingDay() > 730 && GetWorkingDay() <= 1460)
            Title = "Truong phong"; 
        else 
            Title = "Truong ban quan ly"; 
    }

    string GetTitle() 
    {
        return Title; 
    }

    void SetCoefficientsSalary()
    {
        if(GetTitle() == "Nhan vien")
            CoSalary = 1.0; 
        else if(GetTitle() == "Quan ly")
            CoSalary = 1.5; 
        else if(GetTitle() == "Truong phong")
            CoSalary = 2.25; 
        else if(GetTitle() == "Truong ban quan ly")
            CoSalary = 4.0;
    }

    NhanVien()
    {
        Name = "A"; 
        WorkingDay = 300; 
        ID = "300A"; 
        Title = "Nhan vien"; 
        CoSalary = 1.0; 
    }

    NhanVien(string name, int workingday)
    {
        Name = name; 
        WorkingDay = workingday; 
        SetID(); 
        SetTitle(); 
        SetCoefficientsSalary(); 
    }

    NhanVien(const NhanVien &other)
    {
        Title = other.Title; 
        CoSalary = other.CoSalary; 
        WorkingDay = other.WorkingDay; 
    }

    ~NhanVien(){}; 

    void Input()
    {
        cout << "Enter name: "; 
        getline(cin, Name); 
        cout << "Enter number of working day: "; 
        cin >> WorkingDay; 
        SetTitle(); 
        SetID();
        SetCoefficientsSalary(); 
    }

    void Print() 
    {
        cout << "Name: " << Name << "\n"; 
        cout << "Number of working day: " << WorkingDay << "\n"; 
        cout << "Title: " << Title << "\n"; 
        cout << "Staff ID: " << ID << "\n"; 
        cout << "CoSalary: " << CoSalary << "\n\n"; 
    }
};


