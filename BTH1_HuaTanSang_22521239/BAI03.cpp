#include <iostream> 
#include <cmath> 

using namespace std;

class ToaDo
{
    private: 
        float x, y; 
    
    public: 
        void NhapDiem(int a, int b)
        {
            x = a; 
            y = b;
        }

        void XuatDiem() 
        {
            cout << "(" << x << "," << y << ")" ; 
        }

        float KhoangCanh(ToaDo P)
        {
            return sqrt(pow(x - P.x, 2) + pow(y - P.y, 2)); 
        }
};

int main() 
{
    ToaDo P, D; 
    P.NhapDiem(2, 4); 
    D.NhapDiem(4, 7); 
    D.XuatDiem(); 
    cout << P.KhoangCanh(D); 

    return 0; 
}





