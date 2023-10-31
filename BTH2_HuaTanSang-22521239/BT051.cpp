#include <bits/stdc++.h>
using namespace std;

class DaThuc
{
private:
    int Bac;
    int *HeSo;

public:
    DaThuc(){}

    DaThuc(int *HeSo)
    {
        this->HeSo = new int[0];
        Bac = 0;
    }

    void Nhap()
    {
        cout << "Nhap bac: "; 
        cin >> Bac;
        HeSo = new int[Bac + 2];
        for (int i = 0; i <= Bac; i++)
        {
            cin >> HeSo[i];
        }
    }

    void Xuat()
    {
        for (int i = Bac; i > 0; i--)
        {
            cout << HeSo[i] << "x^" << i << "+";
        }
        cout << HeSo[0];
        cout << "\n";
    }

    int getBac()
    {
        return Bac;
    }

    DaThuc Cong(DaThuc b)
    {
        DaThuc c;
        int Max = max(b.getBac(), Bac);
        int Min = min(b.getBac(), Bac);
        c.Bac = max(b.getBac(), Bac);
        c.HeSo = new int[c.Bac + 2];

        for (int i = 0; i <= Min; i++)
        {
            c.HeSo[i] = b.HeSo[i] + HeSo[i];
        }

        if (b.getBac() > Bac)
        {
            for (int i = Min + 1; i <= Max; i++)
            {
                c.HeSo[i] = b.HeSo[i];
            }
        }
        else if (b.getBac() < Bac)
        {

            for (int i = Min + 1; i <= Max; i++)
            {
                c.HeSo[i] = HeSo[i];
            }
        }
        
        return c;
    }

    DaThuc Tru(DaThuc b)
    {
        DaThuc c;
        int Max = max(b.getBac(), Bac);
        int Min = min(b.getBac(), Bac);
        c.Bac = Max;
        c.HeSo = new int[c.Bac + 1];
        for (int i = 0; i <= Min; i++)
        {
            c.HeSo[i] = b.HeSo[i] - HeSo[i];
        }
        if (b.getBac() > Bac)
        {
            for (int i = Min + 1; i <= Max; i++)
            {
                c.HeSo[i] = b.HeSo[i];
            }
        }
        else if (b.getBac() < Bac)
        {
            for (int i = Min + 1; i <= Max; i++)
            {
                c.HeSo[i] = HeSo[i];
            }
        }
        return c;
    }

    int GiaTri(int x)
    {
        int sum = 0;
        for (int i = 0; i <= Bac; i++)
        {
            sum = sum + (HeSo[i] * pow(x, i));
        }
        return sum;
    }

    ~DaThuc(){}
};

int main()
{
    DaThuc a;
    a.Nhap();
    a.Xuat();
    DaThuc b;
    b.Nhap();
    b.Xuat();
    DaThuc c = a.Cong(b);
    c.Xuat();
}