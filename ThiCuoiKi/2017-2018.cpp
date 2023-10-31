#include <bits/stdc++.h>
using namespace std;

class Date
{
private: 
    int day, month, year;
public: 
    Date()
    { 
        day = 1; 
        month = 1; 
        year = 1; 
    }

    Date(int yy, int mm)
    {
        year = yy; 
        month = mm; 
        day = 1; 
    }
 
    Date(int yy, int mm, int dd)
    {
        year = yy; 
        month = mm; 
        day = dd; 
    }

    friend istream& operator>> (istream& is, Date &a)
    {
        cout << "Nhap ngay: "; 
        is >> a.day; 
        cout << "Nhap thang: "; 
        is >> a.month; 
        cout << "Nhap nam: "; 
        is >> a.year; 

        return is; 
    }

    friend ostream& operator<< (ostream& os, const Date &a)
    {
        cout << a.day << "/" << a.month << "/" << a.year << endl; 
    }

    bool operator<(Date a)
    {
        if(year < a.year)
            return true;
        else if(year == a.year && month < a.month)
            return true; 
        else if(year == a.year && month == a.month && day < a.day)
            return day; 
        
        return false; 
    }

    Date operator++(int x)
    {
        Date a; 
        a.day = day + 1; 
        if(a.day > 30)
        {
            a.day = 1; 
            a.month  = month + 1; 

            if(a.month > 12)
            {
                a.month = 1; 
                a.year = year + 1 ; 
            }
        }
        return a; 
    }
};

int main() 
{
    Date ng1; 
    Date ng2(2017, 1); 
    Date ng3(2017, 1, 7); 

    cin >> ng1; 
    ng1++; 

    cout << ng1; 

    if(ng1 < ng2)
        cout << "Ngay 1 truoc ngay 2" << endl; 
    else 
        cout << "Ngay 1 khong truoc ngay 2" << endl; 

    return 0; 
}