#include <bits/stdc++.h>
using namespace std; 

class CTime
{
private: 
    unsigned int second; 

public: 
    CTime()
    { 
        second = 0; 
    }

    CTime operator++(int k)
    {
        CTime a; 
        a.second = ++second; 
        a.second %= 84600; 
        return a;  
    }

    CTime operator+(const CTime &a)
    {
        CTime kq; 
        kq.second = second + a.second;
        kq.second %= 84600;
        return kq; 
    }

    friend istream& operator>> (istream& is, CTime &a)
    {
        int h, m, s; 
        cout << "Nhap gio: "; is >> h; 
        cout << "Nhap phut: "; is >> m; 
        cout << "Nhap giay: "; is >> s; 
        a.second = h*3600 + m*60 + s; 

        return is; 
    }

    friend ostream& operator<< (ostream& os, const CTime &a)
    {
        int h, m, s; 
        
        h = a.second/3600; 
        m = (a.second%3600)/60; 
        s = a.second - h*3600 - m*60; 

        os << "Bay gio la: " << h << ":" << m << ":" << s << "\n"; 
        return os; 
    }
};

int main() 
{
    CTime x; 
    cin >> x; 
    cout << x; 
    x++;
    cout << x;  
    CTime b; 
    cin >> b; 
    cout << b; 

    cout << x + b; 
}