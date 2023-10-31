#include <bits/stdc++.h> 
using namespace std; 

class DaThuc
{
private: 
    int SoMu; 
    vector<float> HeSo; 

public: 
    DaThuc(){} 
    DaThuc(float x) 
    { 
        HeSo[0] = x; 
        SoMu = 0;    
    } 

    int getBac() 
    { 
        return SoMu; 
    } 

    void NhapDaThuc() 
    { 
        cout << "Nhap bac: "; 
        cin >> SoMu; 
        float heso; 
        for(int i = 0; i <= SoMu; i++) 
        {   
            cout << "nhap he so bac " << i << ": "; 
            cin >> heso; 
            HeSo.push_back(heso); 
        }
    }

    void XuatDaThuc()
    {
        for(int i = SoMu; i > 0; i--)
        {
            cout << HeSo[i] << "x^" << i << " + "; 
        }
        cout << HeSo[0] << "\n"; 
    }

    float GiaTri(float x)
    {
        float res = 0; 
        for(int i = 0; i <= SoMu; i++) 
        {
            res += HeSo[i]*pow(x, i); 
        }

        return res; 
    }

    DaThuc CongDaThuc(DaThuc other)
    {
        DaThuc res;
        int Max = max(other.getBac(), SoMu); 
        int Min = min(other.getBac(), SoMu); 
        res.SoMu = Max; 
        float x; 
        for(int i = 0; i <= Min; i++)  
        {
            x = other.HeSo[i] + HeSo[i];  
            res.HeSo.push_back(x); 
        }
        
        if (other.getBac() > SoMu) 
        {
            float x; 
            for (int i = Min + 1; i <= Max; i++) 
            {
                x = other.HeSo[i]; 
                res.HeSo.push_back(x); 
            }
        }
        else if (other.getBac() < SoMu) 
        {
            for (int i = Min + 1; i <= Max; i++)
            {
                float x = HeSo[i]; 
                res.HeSo.push_back(x); 
            }
        }

        return res; 
    }

    DaThuc TruDaThuc(DaThuc other)
    {
        DaThuc res;
        int Max = max(other.getBac(), SoMu);
        int Min = min(other.getBac(), SoMu);
        res.SoMu = Max; 
        
        for (int i = 0; i <= Min; i++)
        {
            float x = other.HeSo[i] - HeSo[i];
            res.HeSo.push_back(x); 
        }

        if (other.getBac() > SoMu)
        {
            for (int i = Min + 1; i <= Max; i++)
            {
                float x = -other.HeSo[i];
                res.HeSo.push_back(x); 
            }
        }
        else if (other.getBac() < SoMu)
        {
            for (int i = Min + 1; i <= Max; i++)
            {
                float x = -HeSo[i];
                res.HeSo.push_back(x); 
            }
        }

        return res;
    }
    
    ~DaThuc(){}
};

int main()
{
    DaThuc a, b, c; 

    cout << "Nhap da thuc a " << "\n"; 
    a.NhapDaThuc(); 
    a.XuatDaThuc(); 
    
    cout << "Nhap da thuc b " << "\n"; 
    b.NhapDaThuc(); 
    b.XuatDaThuc(); 

    cout << "Tong hai da thuc la: "; 
    c = a.CongDaThuc(b); 
    c.XuatDaThuc(); 

    cout << "Hieu hai da thuc la: "; 
    c = a.TruDaThuc(b); 
    c.XuatDaThuc(); 

    float x; 
    cout << "Nhap x: "; 
    cin >> x;
    cout << "Gia tri cua da thuc a tai x: "; 
    cout << a.GiaTri(x) << "\n"; 
    cout << "Gia tri cua da thuc b tai x: "; 
    cout << b.GiaTri(x) << "\n"; 

    return 0; 
}