#include <bits/stdc++.h>
using namespace std; 

class IntArr
{
private: 
    int count; 
    int *value; 
public: 
    IntArr()
    {
        count = 0; 
        value = nullptr; 
    }

    IntArr(int count, int vaa)
    {
        this->count = count; 
        
        value = new int[count]; 
        for(int i = 0; i < count; i++) 
        {
            value[i] = vaa;
        }
    }

    IntArr(int count)
    {
        this->count = count; 
        value = new int[count]; 

        for(int i = 0; i < count; i++) 
        {
            value[i] = 0;
        }
    }

    IntArr concat(IntArr &arr)
    {
        int size = arr.count + count;

        IntArr a(size, 0); 
        int k = 0;
        for(int i = 0; i < count; i++) 
        {
            a.value[k++] = value[i];  
        }

        for(int i = 0; i < arr.count; i++) 
        {
            a.value[k++] = arr.value[i]; 
        }

        return a; 
    }

    IntArr push(int vaa)
    {
        IntArr temp(1, vaa);
        *this = this->concat(temp); 
    }

    friend istream& operator>> (istream& is, IntArr& a)
    {
        cout << "Nhap so phan tu: "; 
        cin >> a.count;
        a.value = new int[a.count]; 

        for(int i = 0; i < a.count; i++) 
        {
            cout << "Nhap phan tu thu: " << i << ": "; 
            cin >> a.value[i]; 
        } 
        return is; 
    }

    friend ostream& operator<< (ostream& os, IntArr& a)
    {
        cout << "Mang la: "; 
        for(int i = 0; i < a.count; i++) 
        {
            cout << a.value[i] << " "; 
        }
        cout << endl;

        return os; 
    }
};

int main() 
{
    IntArr l1; 
    IntArr l2(3, 2); 
    IntArr l3(2); 

    IntArr l4 = l2.concat(l3);

    l2.push(3); 

    cin >> l1; 
    cout << l1;
    cout << l2; 
    cout << l3; 
    cout << l4; 

    return 0; 
}