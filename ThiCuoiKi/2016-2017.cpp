#include <bits/stdc++.h>
using namespace std; 

class DaThuc
{
private: 
    int a, b, c; 

public: 

    void Nhap() 
    { 
        cin >> a >> b >> c; 
    }

    int GiaTri(int x)
    {
        return (a*x*x + b*x + c);
    }

    DaThuc operator+(const DaThuc &A)
    {
        DaThuc kq; 
        kq.a = a + A.a; 
        kq.b = b + A.b; 
        kq.c = c + A.c; 

        return kq; 
    }
};