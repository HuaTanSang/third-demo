#include <bits/stdc++.h>
using namespace std; 

class MangDong 
{ 
private: 
    int *dulieu;  
    int kichthuoc;  

public:
    MangDong()
    {
    }
    MangDong(int kichthuoc) : kichthuoc(kichthuoc)
    {
        dulieu = new int[kichthuoc];
    }
    ~MangDong() 
    {
        delete[] dulieu;
    }

    void setKichThuoc()
    {
        cout << "Nhap kich thuoc: "; 
        cin >> kichthuoc; 
        dulieu = new int[kichthuoc]; 
    }
    int getKichThuoc() 
    {
        return kichthuoc; 
    }

    MangDong &operator=(const MangDong &other)
    {
        this->kichthuoc = other.kichthuoc;

        //delete[] dulieu;
        kichthuoc = other.kichthuoc;
        dulieu = new int[kichthuoc];
        for (int i = 0; i < kichthuoc; ++i)
        {
            dulieu[i] = other.dulieu[i];
        }

        return *this;
    }

    MangDong operator+ (MangDong &b)
    {
        int Max = max(kichthuoc, b.kichthuoc); 
        int Min = min(kichthuoc, b.kichthuoc); 
        MangDong res(Max);
        for(int i = 0; i < Min; i++) 
        {
            res.dulieu[i] = dulieu[i] + b.dulieu[i] ; 
        }
 
        if(kichthuoc > b.kichthuoc)
        { 
            for(int i = Min ; i < res.kichthuoc; i++) 
            { 
                res.dulieu[i] = dulieu[i]; 
            } 
        } 
        else 
        {
            for(int i = Min ; i < res.kichthuoc; i++) 
            {
                res.dulieu[i] = b.dulieu[i]; 
            }
        } 

        return res; 
    }

    MangDong& operator++()
    {
        for(int i = 0; i < kichthuoc; i++) 
        { 
            *(dulieu + i) += 1; 
        }
        return *this; 
    }

    friend istream &operator>>(istream &is, MangDong &arr)
    {
        for (int i = 0; i < arr.kichthuoc; ++i)
        {
            is >> arr.dulieu[i];
        }
        return is;
    }

    friend ostream &operator<<(ostream &os, const MangDong& arr)
    {
        for (int i = 0; i < arr.kichthuoc; ++i)
        {
            os << arr.dulieu[i] << " ";
        }
        return os;
    }

};

int main() 
{ 
    MangDong a, b; 
    a.setKichThuoc(); 
    cout << "Nhap phan tu: "; 
    cin >> a; 
    ++a; 
    cout << a << endl; 
    b = a;     
    MangDong c; 
    c = a + b; 
    cout << c;  
    
    
}
