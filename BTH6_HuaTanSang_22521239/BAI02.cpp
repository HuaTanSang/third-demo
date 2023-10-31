#include <bits/stdc++.h>
using namespace std;

class NV
{
protected:
    string HoTen;
    string MaNV;
    string DOB;

public:
    virtual bool laLDTT() = 0;

    virtual void Nhap()
    {
        cout << "Nhap ten: ";
        getline(cin, HoTen);
        cout << "Nhap ma nhan vien: ";
        cin >> MaNV;
        cout << "Ngay sinh: ";
        cin >> DOB;
    }

    virtual void Xuat()
    {
        cout << "Ho ten: " << HoTen << endl;
        cout << "Ma nhan vien: " << MaNV << endl;
        cout << "Ngay sinh: " << DOB << endl;
    }
};

class GiVien : public NV
{
private:
    int SoTietGiangDay;
    int SoDeTaiKhoaLuan;

public:
    void Nhap()
    {
        NV::Nhap();
        cout << "Nhap so tiet giang day torng nam: ";
        cin >> SoTietGiangDay;

        cout << "Nhap so de tai khoa luan: ";
        cin >> SoDeTaiKhoaLuan;
    }

    void Xuat()
    {
        NV::Xuat();
        cout << "So tiet giang day: " << SoTietGiangDay << "\n";
        cout << "So de tai khoa luan: " << SoDeTaiKhoaLuan << "\n";
    }

    bool laLDTT()
    {
        if (SoTietGiangDay >= 300 && SoDeTaiKhoaLuan >= 5)
            return true;
        return false;
    }
};

class NghCuuVien : public NV
{
private:
    int SoDeTaiNghienCuu;
    int SoBaiBaoKhoaHoc;

public:
    void Nhap()
    {
        NV::Nhap();
        cout << "Nhap so de tai nghien cuu: ";
        cin >> SoDeTaiNghienCuu;
        cout << "Nhap so bai bao khoa hoc: ";
        cin >> SoBaiBaoKhoaHoc;
    }

    void Xuat()
    {
        NV::Xuat();
        cout << "So de tai: " << SoDeTaiNghienCuu;
        cout << "So bai bao: " << SoBaiBaoKhoaHoc;
    }

    bool laLDTT()
    {
        if (SoDeTaiNghienCuu >= 1 && SoBaiBaoKhoaHoc >= 2)
            return true;
        return false;
    }
};

class NhVienVP : public NV
{
private:
    int SoLopBoiDuong;
    int SoGioLaoDong;

public:
    void Nhap()
    {
        NV::Nhap();
        cout << "Nhap so lop boi duong: ";
        cin >> SoLopBoiDuong;
        cout << "Nhap so gio lao dong: ";
        cin >> SoGioLaoDong;
    }

    void Xuat()
    {
        NV::Xuat();
        cout << "So lop boi duong: " << SoLopBoiDuong;
        cout << "So gio lao dong: " << SoGioLaoDong;
    }

    bool laLDTT()
    {
        if (SoLopBoiDuong >= 1 && SoGioLaoDong >= 20)
            return true;
        return false;
    }
};

class QLNV
{
private:
    vector<NV*> List;

public:
    friend istream& operator>>(istream& is,QLNV& a)
    {
        int n; 
        cout << "Nhap so luong nhan vien: "; 
        is >> n; 
        cin.ignore(); 
        NV* p; 

        for(int i = 0; i < n; i++)  
        { 
            int choice; 
            cout << "Nhap loai nhan vien: ";
            cin >> choice; 
            cin.ignore(); 
            
            if(choice == 1)
            {
                p = new GiVien(); 
                p->Nhap(); 
                a.List.push_back(p); 
            }
            else if(choice == 2)
            {
                p = new NghCuuVien(); 
                p->Nhap(); 
                a.List.push_back(p); 
            }
            else if (choice == 3)
            {
                p = new NhVienVP(); 
                p->Nhap(); 
                a.List.push_back(p); 
            }
        }
        return is; 
    }
    
    friend ostream &operator<<(ostream &os, QLNV &a)
    {
        for(int i = 0; i < a.List.size(); i++) 
        {
            if(a.List[i]->laLDTT())
            {
                a.List[i]->Xuat(); 
                cout << endl; 
            }
        }
        return os;
    }
};

int main() 
{
    QLNV a; 
    cin >> a; 
    cout << a; 
}