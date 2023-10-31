#include <bits/stdc++.h>
using namespace std; 

class PSo
{
private: 
    int tu_so, mau_so; 

public: 
    PSo()
    {
        tu_so = 1; 
        mau_so = 1; 
    }

    PSo(int ts, int ms)
    {
        tu_so = ts; 
        mau_so = ms; 
    }

    PSo(int x)
    {
        tu_so = x; 
        mau_so = 1;
    }

    friend istream& operator>>(istream& is, PSo &a)
    {
        cout << "Nhap tu so: "; 
        is >> a.tu_so; 
        cout << "Nhap mau so: "; 
        is >> a.mau_so;

        return is; 
    }

    friend ostream& operator<<(ostream& os, PSo &a)
    {
        os << a.tu_so << "/" << a.mau_so << endl; 
    }

    PSo operator+(PSo const &other)
    {
        PSo kq; 
        kq.mau_so = mau_so * other.mau_so; 
        kq.tu_so = tu_so*other.mau_so + mau_so*other.tu_so; 

        return kq; 
    } 

    bool operator== (PSo &other)
    {
        float x = (float) (tu_so/mau_so);
        float y = (float) (other.tu_so/other.mau_so); 

        if(x == y)
        {
            return true;
        }

        return false;
    }
};

int main() 
{
    PSo a(5, 3); 
    PSo b, c, kq; 
    cin >> b >> c; 

    kq = a + b + 5 + c; 

    cout << "Ket qua la: " << kq; 
    if(a == b)
        cout << "Hai phan so bang nhau\n"; 
    
    return 0; 
}