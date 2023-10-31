#include <bits/stdc++.h>
using namespace std; 

class DeTai
{
protected: 
    string MaDeTai; 
    string TenDeTai; 
    string HoTenchunhiem; 
    int SoTV; 
    int NamThucHien; 
    
public: 
    DeTai()
    {
        MaDeTai = TenDeTai = HoTenchunhiem = "0";
        SoTV = NamThucHien = 0;  
    }

    DeTai(string MaDT, string TenDT, string HvT, int Sotv, int NamTH)
    {
        MaDeTai = MaDT; 
        TenDeTai = TenDT; 
        HoTenchunhiem = HvT; 
        SoTV = Sotv; 
        NamThucHien = NamTH; 
    }

    virtual void Nhap()
    {
        cout << "Nhap ma de tai: "; 
        cin >> MaDeTai; 
        cout << "Nhap ten de tai: "; 
        getline(cin, TenDeTai); 
        cout << "Nhap ten nguoi chu nhiem: "; 
        getline(cin, HoTenchunhiem); 
        cout << "Nhap so thanh vien: "; 
        cin >> SoTV; 
        cout << "Nhap so nam thuc hien: "; 
        cin >> NamThucHien; 
    }

    virtual void Xuat() 
    {
        cout << "Ma de tai: " << MaDeTai << endl; 
        cout << "Ten de tai: " << TenDeTai << endl; 
        cout << "Ho va ten nguoi chi nhiem de tai: " << HoTenchunhiem << endl; 
        cout << "So luong thanh vien: " << SoTV << endl; 
        cout << "So nam thuc hien: " << NamThucHien << endl; 
    }

    virtual string XepLoai()  = 0; 
    virtual int KinhPhi() = 0; 
    
    ~DeTai() {}; 
};

class DeTaiUD : public DeTai
{
private: 
    int SoBSC; 
    int SoUD;

public: 
    DeTaiUD() : DeTai()
    {
        SoBSC = 0; 
        SoUD = 0; 
    }

    DeTaiUD(string MaDT, string TenDT, string HvT, int Sotv, int NamTH, int sBSC, int sUD) : DeTai( MaDT, TenDT, HvT, Sotv, NamTH)
    {
        SoBSC = sBSC; 
        SoUD = sUD; 
    }

    void Nhap() 
    { 
        DeTai::Nhap(); 
        cout << "Nhap so bang sang che: "; 
        cin >> SoBSC; 
        cout << "Nhap so ung dung: "; 
        cin >> SoUD; 
    }

    void Xuat() 
    {
        DeTai::Xuat(); 
        cout << "So bang sang che: " << SoBSC << endl; 
        cout << "So ung dung: " << SoUD << endl; 
    }

    int KinhPhi() 
    {
        return SoBSC * 10000000 + SoUD * 5000000; 
    }

    string XepLoai()
    { 
        if(SoBSC + SoUD < 1)
            return "KHT"; 
        else if(SoBSC + SoUD >= 1 && SoBSC + SoUD < 3)
            return "HT"; 
        else 
            return "HTXS"; 
    }

    ~DeTaiUD() {}
};

class BaiBao
{
private: 
    string TenBaiBao; 
    int NamCongBo; 
    int LoaiBaibao; 
    string XepLoai; 

public: 
    BaiBao()
    {
        TenBaiBao = XepLoai = "0"; 
        LoaiBaibao = 0; 
    }

    BaiBao(string tenbb, int namcongbo, int loaibb, string xeploai)
    {
        TenBaiBao = tenbb; 
        NamCongBo = namcongbo; 
        LoaiBaibao = loaibb; 
        XepLoai = xeploai; 
    }

    void NhapBao()
    {
        cout << "Nhap ten bai bao: "; 
        cin >> TenBaiBao; 
        cout << "Nhap nam cong bo: "; 
        cin >> NamCongBo; 
        cout << "Nhap loai bai bao, nhap 1. la tap chi, 2. la hoi nghi"; 
        cin >> LoaiBaibao; 
        cout << "Nhap xep loai: "; 
        cin >> XepLoai; 
    }

    void Xuat()
    {
        cout << "Ten bai bao: " << TenBaiBao << endl; 
        cout << "Nam cong bo: " << NamCongBo << endl; 
        cout << "Loai bai bao: " << LoaiBaibao << endl; 
        cout << "Xep loai: " << XepLoai << endl; 
    }

    int KinhPhiviet()
    {
        if(LoaiBaibao == 1)
        {
            if(XepLoai == "Q1")
                return 20000000; 
            if(XepLoai == "Q2")
                return 10000000; 
            if(XepLoai == "Q3")
                return 5000000; 
        }

        else 
        {
            if(XepLoai == "A")
                return 18000000; 
            if(XepLoai == "B")
                return 9500000; 
            if(XepLoai == "C")
                return 4500000;
        }
    }

    ~BaiBao() {}
};

class DeTaiLT : public DeTai
{
private: 
    int SLBaiBao; 
    vector<BaiBao> DS; 

public: 
    DeTaiLT() : DeTai()
    {
        SLBaiBao = 0;  
    }

    DeTaiLT(string MaDT, string TenDT, string HvT,int Sotv, int NamTH, int slbb) : DeTai(MaDT, TenDT, HvT, Sotv, NamTH)
    {
        SLBaiBao = slbb; 
    }

    void Nhap() 
    {
        DeTai::Nhap(); 
        cout << "Nhap so luong: "; 
        cin >> SLBaiBao; 
        if(SLBaiBao == 0) return; 

        for(int i = 0; i < SLBaiBao; i++) 
        {
            DS[i].NhapBao(); 
        }
    }

   
    int KinhPhi()
    {
        int total = 0; 
        for(int i = 0; i < SLBaiBao; i++) 
        { 
            total += DS[i].KinhPhiviet(); 
        }

        return total; 
    }

    void Xuat()
    {
        DeTai::Xuat(); 
        for(int i = 0; i < SLBaiBao; i++) 
        {
            DS[i].Xuat(); 
            cout << "Tong kinh phi: " << KinhPhi(); 
            cout << endl; 
        }
    }

    string XepLoai()
    {
        if(SLBaiBao < 1)
        {
            return "KHT";
        }
        if(SLBaiBao >= 1 && SLBaiBao <= 3)
            return "HT"; 
        if(SLBaiBao > 3)
            return "HTXS"; 
    }

    ~DeTaiLT() {}
};

class QLDT
{
private: 
    vector<DeTai*> List; 
    int n; 
    
    void SelectionSort(vector<DeTai*> List, int n)
    {
        int i, j, max_idx;
        for (i = 0; i < n - 1; i++)
        {
            max_idx = i;
            for (j = i + 1; j < n; j++)
                if (List[j]->KinhPhi() > List[max_idx]->KinhPhi())
                    max_idx = j;

            swap(List[max_idx], List[i]);
        }
    }

public:
    friend istream &operator>>(istream &is, QLDT &a)
    {
        int n;
        cout << "Nhap so luong de tai: ";
        is >> n;
        cin.ignore();
        DeTai *p;

        for (int i = 0; i < n; i++)
        {
            int choice;
            cout << "Nhap loai de tai: ";
            cin >> choice;
            cin.ignore();

            if (choice == 1)
            {
                p = new DeTaiUD();
                p->Nhap();
                a.List.push_back(p);
            }
            else if (choice == 2)
            {
                p = new DeTaiLT(); 
                p->Nhap(); 
                a.List.push_back(p); 
            }
        }

        return is;
    }

    friend ostream &operator<<(ostream &os, QLDT &a)
    {
        for(int i = 0; i < a.List.size(); i++) 
        {
           a.List[i]->Xuat();  
        }
        return os;
    }

    void XuatHTXS()
    {
        for(int i = 0; i < n; i++) 
        { 
            if(List[i]->XepLoai() == "HTXS")
            {
                List[i]->Xuat(); 
            }
        }
    }

   

    void KinhPhiTangDan()
    {
        // sort
        SelectionSort(List, n); 

        //In
        for(int i = 0; i < n; i++) 
        {
            List[i]->Xuat(); 
        }
    }
}; 

int main() 
{
    QLDT a; 
    cin >> a; 
    cout << a; 
    a.XuatHTXS(); 
    a.KinhPhiTangDan(); 
}