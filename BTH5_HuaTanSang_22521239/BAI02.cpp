#include <bits/stdc++.h>
#include <random> 
using namespace std; 

class GiaSuc
{
protected:
public: 
    virtual int LitSua() = 0; 
    virtual int SoCon() = 0; 
    virtual string Tiengkeu() = 0; 
    virtual int Loai() = 0; 
};

class Bo : public GiaSuc 
{
protected:         
    int a, b, c;    
public:       
    Bo()    
    {
        a = b = c = 0;     
    }
    ~Bo() {};    

    string Tiengkeu()                                                                                                                 
    {
        return "Bo"; 
    }

    int SoCon() 
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, 10);
        return dis(gen); 
    }

    int LitSua() 
    { 
         random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, 20);
        return dis(gen);
    }

    int Loai() 
    {
        return 1; 
    }
};

class Cuu : public GiaSuc
{
public:    
    string Tiengkeu() 
    {
        return "Cuu"; 
    }

    int SoCon() 
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, 10);
        return dis(gen);
    }

    int LitSua() 
    { 
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, 5);
        return dis(gen);     
    }

    int Loai() 
    {
        return 2; 
    }
};
     
class De : public GiaSuc
{
public:    
    string Tiengkeu() 
    {
        return "De"; 
    }

    int SoCon() 
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, 10);
        return dis(gen); 
    }

    int LitSua() 
    { 
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, 10);
        return dis(gen);
    }

    int Loai()
    {
        return 3; 
    }
};

int main() 
{
    vector<GiaSuc*> DS; 
    GiaSuc *c; 

    int SLCuu, SLBo, SLDe; 
    cout << "Nhap so luong gia suc ban dau o moi loai\n"; 
    cin >> SLBo >>SLCuu >> SLDe; 

    for(int i = 0; i < SLBo; i++) 
    {
        c = new Bo(); 
        DS.push_back(c); 
    }

    for(int i  = 0; i < SLCuu; i++) 
    {
        c = new Cuu();
        DS.push_back(c);
    }

    for(int i = 0; i < SLDe; i++) 
    {
        c = new De(); 
        DS.push_back(c); 
    }

    // Tieng keu nghe duoc; 
    cout << "Cac tieng keu se nhan duoc la\n"; 
    if(SLBo != 0)
    {
        c = new Bo(); 
        cout << c->Tiengkeu( ) << "\n"; 
    }
    if(SLCuu != 0) 
    {
        c = new Cuu(); 
        cout << c->Tiengkeu() << "\n"; 
    }
    if(SLDe != 0) 
    {
        c = new De(); 
        cout << c->Tiengkeu() << "\n"; 
    } 

    int SuaBo = 0;
    int SuaDe = 0; 
    int SuaCuu = 0;

    // Thong ke
    for(int i = 0; i < DS.size(); i++)
    {
        switch(DS[i]->Loai())
        {
            case 1: 
                SuaBo += DS[i]->LitSua();
                SLBo += DS[i]->SoCon();
                break;

            case 2: 
                SuaCuu += DS[i]->LitSua(); 
                SLCuu += DS[i]->SoCon();
                break;

            case 3: 
                SuaDe += DS[i]->LitSua(); 
                SLDe += DS[i]->SoCon(); 
                break;
        }
    }
    cout << "----------------------\n"; 
    cout << "So luong tung loai.\n"; 
    cout << "Bo: " << SLBo << endl; 
    cout << "Cuu: " << SLCuu << endl; 
    cout << "De: " << SLDe << endl; 

    cout << "----------------------\n"; 
    cout << "San luong sua.\n"; 
    cout << "Bo: " << SuaBo << " l" << endl; 
    cout << "Cuu: " << SuaCuu << " l" << endl; 
    cout << "De: " << SuaDe << " l" << endl; 

    return 0; 
}