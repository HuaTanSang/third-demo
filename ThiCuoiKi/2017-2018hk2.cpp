#include <bits/stdc++.h>
using namespace std; 

class DaThuc
{
private: 
    int kich_thuoc; 
    vector<int> he_so; 

public: 
    DaThuc operator+(DaThuc const &other)
    {
        int Max = max(kich_thuoc, other.kich_thuoc);
        int Min = min(kich_thuoc, other.kich_thuoc);

        DaThuc kq; 
        kq.kich_thuoc = Max; 

        for(int i = 0; i < Min; i++) 
        {
            int x  = he_so[i] + other.he_so[i]; 
            kq.he_so.push_back(x); 
        }

        if(Max == kich_thuoc)
        {
            for(int i = Min; i <= Max; i++)
            {
                int x = he_so[i];
                kq.he_so.push_back(x);
            }
        }
        else 
        {
            for(int i = 0; i <= Max; i++) 
            {
                int x = other.he_so[i]; 
                kq.he_so.push_back(x);
            }
        }

        return kq; 
    }

    friend istream& operator>> (istream& is, DaThuc &a)
    {
        is >> a.kich_thuoc; 

        int x; 
        for(int i = 0; i <= a.kich_thuoc; i++) 
        {
            cout << "Nhap phan tu thu " << i << ": "; 
            is >> x; 
            a.he_so.push_back(x); 
        }

        return is; 
    }

    friend ostream& operator<< (ostream& os, DaThuc &a)
    {
        for(int i = a.kich_thuoc; i > 0; i--)
        {
            os << a.he_so[i] << "x +"; 
        }
        os << a.he_so[0] << "x" << endl; 

        return os; 
    }
};

