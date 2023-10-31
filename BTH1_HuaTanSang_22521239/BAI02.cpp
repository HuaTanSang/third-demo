#include <iostream> 
#include <cmath> 

using namespace std; 

class SP
{
    private: 
        float PhanThuc, PhanAo; 

    public: 
        void NhapSoPhuc(int a, int b)
        {
            PhanThuc = a; 
            PhanAo = b; 
        }

        void XuatSoPhuc()
        {
            if(PhanAo < 0) 
                cout << PhanThuc  << PhanAo << "i" << endl; 
            else 
                cout << PhanThuc << " + " << PhanAo  << "i" << endl; 
        }

        SP Cong(SP X)
        {
            SP kq; 

            kq.PhanThuc = PhanThuc + X.PhanThuc; 
            kq.PhanAo = PhanAo + X.PhanAo; 

            return kq; 
        }

        SP Tru(SP X)
        {
            SP kq; 

            kq.PhanThuc = PhanThuc - X.PhanThuc; 
            kq.PhanAo = PhanAo - X.PhanAo; 
        }

        SP Nhan(SP X)
        {
            SP kq; 
            kq.PhanThuc = PhanThuc*X.PhanThuc - PhanAo*X.PhanAo; 
            kq.PhanAo = PhanThuc*X.PhanAo  + PhanAo*X.PhanThuc; 

            return kq; 
        }

        SP Chia(SP X)
        {
            SP kq; 

            kq.PhanThuc = (float)((PhanThuc*X.PhanThuc + PhanAo*X.PhanAo)/(X.PhanThuc*X.PhanThuc + X.PhanAo*X.PhanAo)); 
            kq.PhanAo = (float)((X.PhanThuc*PhanAo - PhanThuc*X.PhanAo)/(X.PhanThuc*X.PhanThuc + X.PhanAo*X.PhanAo)) ; 
            
            return kq; 
        }
}; 

int main() 
{
    SP a, b; 
    a.NhapSoPhuc(3, 5); 
    b.NhapSoPhuc(7, 9); 
    
    a.Cong(b).XuatSoPhuc(); 
    a.Tru(b).XuatSoPhuc(); 
    a.Nhan(b).XuatSoPhuc(); 
    a.Chia(b).XuatSoPhuc(); 

    return 0; 
}











