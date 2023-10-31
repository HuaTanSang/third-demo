#include <bits/stdc++.h>

using namespace std; 

class PhanSo
{
    private: 
        int TuSo, MauSo; 
    
    public: 
        PhanSo() 
        {
            TuSo = 1; 
            MauSo = 1; 
        }

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
            cout << TuSo << "/" << MauSo << " ";
            
        }

        
        float getReal()
        {
            return (float)TuSo/MauSo; 
        }

        float Cong(PhanSo X)
        {
            PhanSo kq; 
            float res;
            kq.MauSo = MauSo*X.MauSo; 
            kq.TuSo = MauSo*X.TuSo + TuSo*X.MauSo; 

            res = kq.getReal(); 

            return res;  
        }


        ~PhanSo(){}; 
};


class DSPhanSo
{
private: 
    PhanSo A[100]; 
    int n; 
public: 
    void Nhap() 
    {
        cout << "Nhap so luong cac phan so: "; 
        cin >> n; 

        int x, y; 
        for(int i = 0; i < n; i++)
        {
            cout << "Nhap tu so: "; 
            cin >> x; 
            cout << "Nhap mau so: "; 
            cin >> y; 

            A[i].NhapPhanSo(x, y); 
        }
    }

    float TongCacPhanSo()
    {
        float Sum = 0;
        
        for(int i = 0; i < n - 1; i++) 
        {
            Sum += A[i].Cong(A[i+1]);
        }

        return Sum; 
    }

    PhanSo PSLonNhat()
    {
        float Max = A[0].getReal(); 
        PhanSo c; 
        for(int i = 1; i < n; i++) 
        {
            if(Max < A[i].getReal())
            {
                Max = A[i].getReal(); 
                c = A[i]; 
            }
        }
        
        return c; 
    }

    PhanSo PSNhoNhat()
    {
        float Min = A[0].getReal(); 
        PhanSo c; 
        for(int i = 1; i < n; i++) 
        {
            if(Min > A[i].getReal())
            {
                Min = A[i].getReal(); 
                c = A[i]; 
            }
        }
        
        return c; 
    }

    void DSTangDan()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[i].getReal() > A[j].getReal())
                {
                    swap(A[i], A[j]);
                }
            }
        }
    }

    void DSGiamDan()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[i].getReal() < A[j].getReal())
                {
                    swap(A[i], A[j]);
                }
            }
        }
    }

    void InDS()
    {
        for(int i = 0; i < n; i++) 
        {
            A[i].XuatPhanSo(); 
            cout << " ";
        }
        cout << "\n"; 
    }

    int getQuantity()
    {
        return n; 
    }

    ~DSPhanSo(){}; 
}; 


int main() 
{
    DSPhanSo A; 
    
    A.Nhap(); 
    cout << "Tong cac phan so trong mang: "; 
    float b = A.TongCacPhanSo();
    cout << b << "\n"; 

    cout << "Phan so lon nhat trong mang: "; 
    PhanSo c = A.PSLonNhat(); 
    c.XuatPhanSo(); 
    cout << "\n"; 

    cout << "Phan so nho nhat trong mang: "; 
    PhanSo d = A.PSNhoNhat();
    d.XuatPhanSo(); 
    cout << "\n"; 

    cout << "Danh sach mang giam dan: ";
    A.DSGiamDan(); 
    A.InDS();

    cout << "Danh sach mang tang dan: "; 
    A.DSTangDan(); 
    A.InDS();

    return 0; 
}
