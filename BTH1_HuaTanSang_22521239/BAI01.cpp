#include <bits/stdc++.h>

using namespace std; 

class PhanSo
{
    private: 
        int TuSo, MauSo; 
    
    public: 

        int gcd(int a, int b) 
        {
            if (b == 0) return a;
            return gcd(b, a % b);
        }

        void NhapPhanSo(int x, int y) 
        {
            TuSo = x; 
            MauSo = y; 
        }

        void XuatPhanSo()
        {
            int c = gcd(TuSo, MauSo);
            TuSo/=c; 
            MauSo/=c; 
            if(MauSo < 0)
            {
                cout << -TuSo << "/" << -MauSo << endl;
                cout << (float)TuSo/MauSo << endl; 
                return; 
            }
            else if(TuSo == 0)
            {
                cout << 0;
                return; 
            }
            cout << TuSo << "/" << MauSo << endl;
            cout << (float)TuSo/MauSo << endl; 
        }

        PhanSo Cong(PhanSo X)
        {
            PhanSo kq; 
            kq.MauSo = MauSo*X.MauSo; 
            kq.TuSo = MauSo*X.TuSo + TuSo*X.MauSo; 

            return kq;  
        }

        PhanSo Tru(PhanSo X)
        {
            PhanSo kq; 
            kq.MauSo = MauSo*X.MauSo; 
            kq.TuSo = - MauSo*X.TuSo + TuSo*X.MauSo; 

            return kq; 
        }

        PhanSo Nhan(PhanSo X)
        {
            PhanSo kq; 
            kq.TuSo = TuSo*X.TuSo; 
            kq.MauSo = MauSo*X.MauSo; 

            return kq; 
        }

        PhanSo Chia(PhanSo X)
        {
            PhanSo kq; 
            kq.TuSo = TuSo*X.MauSo; 
            kq.MauSo = MauSo*X.TuSo; 

            return kq;  
        }
};

int main() 
{
    PhanSo a, b; 

    a.NhapPhanSo(1, 2); 
    b.NhapPhanSo(2, 3); 
    //a.XuatPhanSo(); 
    a.Cong(b).XuatPhanSo();
    a.Tru(b).XuatPhanSo(); 
    a.Nhan(b).XuatPhanSo(); 
    a.Chia(b).XuatPhanSo(); 
    
    return 0; 
}




