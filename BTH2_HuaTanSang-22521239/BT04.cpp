#include <bits/stdc++.h>
using namespace std;

class MangMotChieu
{
    int A[1000];

public:
    void CreateArray(int n)
    {
        for (int i = 0; i < n; i++)
        {
            A[i] = rand() % 100 + 1;
        }
    }

    void Print(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << "\n";
    }

    int CountX(int n, int x)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == x)
                count++;
        }
        return count;
    }

    int IncreaseCheck(int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (A[i] > A[i + 1])
                return 0;
        }
        return 1;
    }

    int Minimum(int n)
    {
        int min;

        for(int i = 0; i < n; i++) 
        {
            if(A[i] % 2 == 1)
            {
                min = A[i];
                break; 
            }
            
        }

        for (int i = 0; i < n; i++)
        {
            if (A[i] % 2 == 1 && A[i] < min)
                min = A[i];
        }

        return min;
    }

    bool isPrime(int x)
    {
        if (x < 2)
        {
            return false;
        }
        int count = 0;
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                count++;
            }
        }
        if (count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int maxPrime(int n)
    {
        int max;
        for (int i = 0; i < n; i++)
        {
            if (isPrime(A[i]) == true)
            {
                max = A[i];
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (isPrime(A[i]) == true && A[i] > max)
                max = A[i];
        }
        return max;
    }
};

int main()
{
    MangMotChieu a;
    int n, x;

    cout << "Nhap so phan tu mang: ";
    cin >> n;
    a.CreateArray(n);
    a.Print(n); 

    cout << "Nhap gia tri X can kiem tra: ";
    cin >> x;
    cout << a.CountX(n, x) << endl;

    if (a.IncreaseCheck(n) == 1)
    {
        cout << "Mang tang dan\n";
    }
    else
    {
        cout << "Mang khong tang dan\n";
    }

    cout << "So le nho nhat: " << a.Minimum(n) << "\n"; 

    cout << "So nguyen to lon nhat: " << a.maxPrime(n);
}
