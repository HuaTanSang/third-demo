#include <iostream>
#include <string> 
using namespace std; 

class Candidate
{
    private: 
        string Ma; 
        string Ten; 
        string NgaySinh; 
        float Toan, Van, Anh; 
    
    public: 
        void SetIn4()
        {
            cin.ignore();
            cout << "Nhap ma thi sinh: "; 
            getline(cin, Ma); 
            cout << "Nhap ten thi sinh: "; 
            getline(cin, Ten); 
            cout << "Nhap ngay thang nam sinh: "; 
            getline(cin, NgaySinh); 
            cout << "Nhap diem Toan, Van, Anh: "; 
            cin >> Toan >> Van >> Anh; 
        }

        void Xuat()
        {
            cout << "Ma: " << Ma << endl; 
            cout << "Ten: " << Ten << endl; 
            cout << "DOB: " << NgaySinh << endl; 
            cout << "Diem Toan: " << Toan << endl; 
            cout << "Diem Van: " << Van << endl; 
            cout << "Diem Toan: " << Anh << endl; 
        }

        float DTB()
        {
            return (Toan + Van + Anh); 
        }
};

class TestCandidate
{
    private: 
        Candidate a[100]; 
        int n; 
        
    public:
        void CandidateIn4()
        {
            cout << "Nhap so luong thi sinh: "; 
            cin >> n;
            for(int i = 0; i < n ; i++) 
            {
                cout << "Thi sinh thu " << i + 1 << endl; 
                a[i].SetIn4(); 
            }
        }

        void XuatThongTin() 
        {
            for(int i = 0; i < n; i++) 
            {
                a[i].Xuat(); 
            }
        }

        void DiemCaoHon15() 
        {
            for(int i = 0; i < n; i++) 
            {
                if(a[i].DTB() > 15.0)
                    a[i].Xuat(); 
            }
        }
};

int main() 
{
    TestCandidate A; 
        
    A.CandidateIn4(); 
    A.XuatThongTin(); 

    cout << "Nhung thi sinh co diem tong lon hon 15 la: "; 
    A.DiemCaoHon15(); 
    return 0; 
}






