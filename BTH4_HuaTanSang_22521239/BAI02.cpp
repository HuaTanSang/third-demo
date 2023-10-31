#include <bits/stdc++.h>
using namespace std; 

class SoPhuc
{
private:
    float thuc, ao; 

public: 
    SoPhuc()
    {
        thuc = 0; 
        ao = 0;
    }

    SoPhuc operator+ (SoPhuc p)
    {
        SoPhuc res;
        res.thuc = thuc + p.thuc; 
        res.ao = ao + p.ao; 

        return res; 
    }

    SoPhuc operator- (SoPhuc p)
    {
        SoPhuc res;
        res.thuc = thuc - p.thuc; 
        res.ao = ao - p.ao; 

        return res;
    }

    SoPhuc operator* (SoPhuc p)
    {
        SoPhuc res;
        res.thuc = thuc*p.thuc - ao*p.ao;  
        res.ao = thuc*p.ao + ao*p.thuc; 

        return res;
    }

    SoPhuc operator/ (SoPhuc p)
    {
        SoPhuc res; 
        res.thuc = (thuc* p.thuc + ao+p.ao)/(p.thuc*p.thuc + p.ao*p.ao);
        res.ao = (p.thuc * ao - thuc * p.ao)/(p.thuc*p.thuc + p.ao*p.ao);
        return res; 
    }

    friend istream& operator>>(istream& is, SoPhuc& p);
    friend ostream& operator<<(ostream& is, const SoPhuc& p);
};

istream& operator>> (istream& is, SoPhuc& p)
{
    cout << "Nhap phan thuc: ";
    is >> p.thuc;
    cout << "Nhap phan ao: ";
    is >> p.ao;

    return is; 
}

ostream& operator<<(ostream& os, const SoPhuc& p)
{
    os << p.thuc << " + " << p.ao << "i" << endl;
    return os; 
}

int main() 
{
    SoPhuc a; 
    SoPhuc b; 

    cin >> a >> b; 
    cout << a / b; 
}