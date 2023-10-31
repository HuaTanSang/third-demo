#include <bits/stdc++.h>
using namespace std; 

class PhanSo
{
private:
    int *tuso; 
    int *mauso;

public: 
    PhanSo() 
    {
        tuso = new int(0); 
        mauso = new int(1); 
    }

    PhanSo operator= (const PhanSo &other)
    {
        this->tuso = other.tuso; 
        this->mauso = other.mauso; 
        return *this;
    }

    PhanSo operator+ (const PhanSo &other)
    {
        PhanSo *result = new PhanSo(); 
        *result->tuso = *this->tuso * *other.mauso + *other.tuso * *this->mauso;
        *result->mauso = *this->mauso * *other.mauso;
        return *result; 
    }

    PhanSo operator- (const PhanSo &p)
    {
        PhanSo *result = new PhanSo(); 
        *result->tuso = *this->tuso * *p.mauso - *p.tuso * *this->mauso;
        *result->mauso = *this->mauso * *p.mauso;
        return *result; 
    }

    PhanSo operator* (const PhanSo &p)
    {
        PhanSo *res = new PhanSo(); 
        *res->tuso = *this->tuso* (*p.tuso); 
        *res->mauso = *this->mauso* *p.mauso; 

        return *res; 
    }

    PhanSo operator/ (const PhanSo &p)
    {
        PhanSo *res = new PhanSo(); 
        *res->tuso = *this->tuso* *p.mauso; 
        *res->mauso = *this->mauso* *p.tuso; 

        return *res; 
    }

    PhanSo& operator+= (const PhanSo &p)
    {
        *this->tuso = *this->tuso * *p.mauso + *p.tuso * *this->mauso; 
        *this->mauso = *this->mauso * *p.mauso; 
        return *this; 
    }

    PhanSo& operator-= (const PhanSo &p)
    {
        *this->tuso = *this->tuso * *p.mauso - *p.tuso * *this->mauso; 
        *this->mauso = *this->mauso * *p.mauso; 
        return *this; 
    }

    PhanSo& operator*= (const PhanSo &p)
    {
        *this->tuso = *this->tuso * *p.tuso ; 
        *this->mauso = *this->mauso * *p.mauso; 
        return *this; 
    }

    PhanSo& operator/= (const PhanSo &p)
    {
        *this->tuso = *this->tuso * *p.mauso ; 
        *this->mauso = *this->mauso * *p.tuso; 
        return *this;
    }

    bool operator==(const PhanSo &a)
    {
        PhanSo *res = new PhanSo(); 
        *res->tuso  = *this->mauso* *a.tuso - *a.mauso * *this->tuso;
        
        return *res->tuso == 0;  
    }

    bool operator< (const PhanSo &p)
    {
        PhanSo *res = new PhanSo(); 
        *res->tuso  = *this->mauso* *p.tuso - *p.mauso * *this->tuso;
        
        return *res->tuso < 0; 
    }

    bool operator> (const PhanSo &p)
    {
        PhanSo *res = new PhanSo(); 
        *res->tuso  = *this->mauso* *p.tuso - *p.mauso * *this->tuso;
        
        return *res->tuso > 0; 
    }

    bool operator<= (const PhanSo &p)
    {
        PhanSo *res = new PhanSo(); 
        *res->tuso  = *this->mauso* *p.tuso - *p.mauso * *this->tuso;
        
        return *res->tuso <= 0; 
    }

    bool operator>= (const PhanSo &p)
    {
        PhanSo *res = new PhanSo(); 
        *res->tuso  = *this->mauso* *p.tuso - *p.mauso * *this->tuso;
        
        return *res->tuso >= 0; 
    }

    bool operator!= (const PhanSo &p)
    {
        PhanSo *res = new PhanSo(); 
        *res->tuso  = *this->mauso* *p.tuso - *p.mauso * *this->tuso;
        
        return *res->tuso != 0; 
    }

    PhanSo& operator++ () 
    {
        *this->tuso = *this->tuso + *this->mauso; 
        return *this; 
    }

    PhanSo& operator-- () 
    {
        *this->tuso = *this->tuso - *this->mauso; 
        return *this; 
    }

    friend istream& operator>>(istream& is, PhanSo& p);
    friend ostream& operator<<(ostream& is, const PhanSo& p);
};

istream& operator>> (istream& is, PhanSo& p)
{
    cout << "Nhap tu so: ";
    is >> *p.tuso;
    cout << "Nhap mau so: ";
    is >> *p.mauso;

    return is; 
}

ostream& operator<<(ostream& os, const PhanSo& p)
{
    
    os << *p.tuso << "/" << *p.mauso << endl;
    return os; 
}

// Nho ep mau am thanh duong
int main() 
{
    PhanSo a, b, c; 
    cin >> a; 
    cin >> b; 

    cout << a << b;
    cout << a - b; 

    bool d = (a == b); 
    cout << d; 
}
