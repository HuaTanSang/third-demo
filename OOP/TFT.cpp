#include <bits/stdc++.h>
using namespace std; 

static int num_attacker = 0; 
static int num_brawler = 0; 
static int num_tech = 0; 

class Character
{
protected: 
    string Name; 
    int price; 
    int attack; 
    int defend; 

public: 
    void Nhap() 
    {
        cin >> attack >> defend; 
    }

    void Xuat() 
    {
        cout << this->Name << " - sat thuong gay ra: " << this->attack << endl; 
    }

    virtual void calculateDamage(int m) = 0; 
    virtual void activeGrant() = 0; 
};

class Technology : public Character
{
public: 
    void calulateDamage() 
    {
        
    }
};