#include <bits/stdc++.h>
using namespace std;

class HocSinh
{
private:
    string Name;
    string ID;
    string PhNums;
    float GPA;

public:
    HocSinh()
    {
        Name = "0";
        ID = "0";
        PhNums = "0";
        GPA = 0;
    }

    HocSinh(string name, string id, string phonenumber, float gpa)
    {
        Name = name;
        ID = id;
        PhNums = phonenumber;
        GPA = gpa;
    }

    string getName()
    {
        return Name;
    }

    float getGPA()
    {
        return GPA;
    }

    void EnterName()
    {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, Name);
    }

    void EnterID()
    {
        cout << "Enter ID: ";
        cin >> ID;
    }

    void EnterPhoneNum()
    {
        cout << "Enter phone number: ";
        cin >> PhNums;
    }

    void EnterGPA()
    {
        cout << "Enter GPA: ";
        cin >> GPA;
    }

    void Enter()
    {
        EnterName();
        EnterID();
        EnterPhoneNum();
        EnterGPA();
    }

    bool NameCheck()
    {
        bool check = true;
        for (int i = 0; i < Name.size(); i++)
        {
            if (Name[i] < 'A' && Name[i] > 'Z')
            {
                check = false;
            }

            if (Name[i] >= 'a' && Name[i] <= 'z')
            {
                check = true;
            }
            else
            {
                check = false;
            }
        }
        return check;
    }

    void CheckName()
    {
        if (NameCheck() == true)
        {
            return;
        }

        while (NameCheck() == false)
        {
            cout << "Invalid name.\n";
            EnterName();
        }
    }

    bool IDCheck()
    {
        for (int i = 0; i < ID.size(); i++)
        {
            if (ID[i] < '1' || ID[i] > '9')
            {
                return false;
            }
        }
        return true;
    }

    void CheckID()
    {
        if (IDCheck() == true)
        {
            return;
        }
        while (IDCheck() == false)
        {
            EnterID();
        }
    }

    bool PhoneCheck()
    {
        if (PhNums.size() < 9 || PhNums.size() > 11)
        {
            return false;
        }

        for (int i = 0; i < PhNums.size(); i++)
        {
            if (PhNums[i] < '1' || PhNums[i] > '9')
            {
                return false;
            }
        }

        return true;
    }

    void CheckPhoneNumber()
    {
        if (PhoneCheck() == true)
        {
            return;
        }

        while (PhoneCheck() == false)
        {
            cout << "Invalid phone number\n";
            EnterPhoneNum();
        }
    }

    bool GPACheck()
    {
        if (GPA < 0 || GPA > 10)
            return false;

        return true;
    }

    void CheckGPA()
    {
        if (GPACheck() == true)
            return;
        while (GPACheck() == false)
        {
            cout << "Invalid GPA";
            EnterGPA();
        }
    }

    void Print()
    {
        cout << Name << "\n";
        cout << ID << "\n";
        cout << PhNums << "\n";
        cout << GPA << "\n";
    }
};

class LopHoc
{
private:
    vector<HocSinh> A;
    int n;

public:
    int checkStudent(HocSinh temp)
    {
        int i;
        for (i = 0; i < A.size(); i++)
        {
            if (A[i].getName() == temp.getName())
            {
                return i;
            }
        }
        return -1;
    }

    void AddStudent()
    {
        HocSinh temp;
        temp.Enter();
        temp.CheckName(); 
        temp.CheckGPA(); 
        temp.CheckID(); 
        temp.CheckPhoneNumber(); 
        if (checkStudent(temp) == -1)
        {
            cout << "Adding successfully\n";
            A.push_back(temp);
            return;
        }
        else
        {
            cout << "This student already exist in class\n";
            return;
        }
    }

    void EraseStudent(HocSinh others)
    {
        int i = checkStudent(others);
        if (i == -1)
        {
            cout << "This student isn't exist in class\n";
            return;
        }

        A.erase(A.begin() + i);
        cout << "Delete successfully\n";
        return;
    }

    void PrintClass()
    {
        for (int i = 0; i < A.size(); i++)
        {
            A[i].Print();
        }
    }

    void PrintGPA8()
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i].getGPA() > 8)
            {
                A[i].Print();
            }
        }
    }

    void ReadFile()
    {
        fstream MyFile;
        MyFile.open("Sangdeptrai.txt", fstream::in);
        int n;
        MyFile >> n;

        while (n--)
        {
            MyFile.ignore();
            string name;
            getline(MyFile, name);
            string id;
            MyFile >> id;
            string phone;
            MyFile >> phone;
            float gpa;
            MyFile >> gpa;

            HocSinh tmp(name, id, phone, gpa);
            A.push_back(tmp);
        }
    }
};

int main()
{
    /****************Bai1*******************/
    HocSinh a;
    a.Enter();
    a.CheckName();
    a.CheckID();
    a.CheckGPA();
    a.CheckPhoneNumber();
    a.Print();
    /***********************************/

    /******************Bai2*****************/
    cout << "----------------MENU--------------------\n";
    LopHoc A;
    // Nhap hoc sinh cho lop hoc

    HocSinh b; 
    while (1)
    {
        cout << "1. Add student\n"; 
        cout << "2. Delete student\n"; 
        cout << "3. Print student in class\n"; 
        cout << "4. Print student that has GPA more than 8\n"; 
        cout << "0. Exit\n"; 
        int choice;
        cin >> choice; 
        switch (choice)
        {
        case 1:
            A.AddStudent();
            break;
        case 2:
            cout << "Enter the student need to delete\n"; 
            b.EnterName(); 
            A.EraseStudent(b);
            break;
        case 3:
            A.PrintClass();
            break;
        case 4:
            A.PrintGPA8();
            break;
        case 5:
            A.ReadFile();
            break;

        case 0: 
            return 0; 
        }
    }
}