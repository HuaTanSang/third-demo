#include <bits/stdc++.h>
using namespace std; 

class Engine
{
protected: 
    int hp;
    int petrol_left;

public: 
    void EngineInput()
    {
        cin >> petrol_left;
    }

    virtual int fuel_comsumption() = 0; 

};

class V2 : public Engine
{
public: 
    V2()
    {
        hp = 500;
        petrol_left = 0; 
    }

    float fuel_consumption(int weight)
    {
        return (float)((petrol_left - (float)450/weight)/100);
    }
};

class V2K : public V2
{
public: 
    V2K() 
    {
        hp = 600;
    }
};

class D2G8M : public Engine
{
public: 
    D2G8M()
    {
        hp = 1000; 
    }

    int fuel_comsumption(int weight)
    {
        return (float)((petrol_left - 400/weight)/100);
    }
};

class Turret
{
protected: 
    int size; 
    int num_ammos;

public: 
    void TurretInput() 
    {
        cin >> num_ammos; 
    }

    virtual int total_damage() = 0; 
};

class ML20S : public Turret
{
public: 
    ML20S()
    {
        size = 152; 
        num_ammos = 0;
    }

    int total_damage(int m)
    {
        return (float) (m/4) * size * num_ammos;
    }
};

class ML65 : public ML20S
{
public: 
    ML65()
    {
        size = 130;
        num_ammos = 0;
    }
};

class F34 : public Turret
{
public: 
    F34()
    {
        size = 76.2; 
        num_ammos = 0; 
    }

    int total_damage()
    {
        return 3 * num_ammos * size; 
    }
};

class D25T : public F34
{
public: 
    D25T()
    {
        size = 152; 
        num_ammos = 0; 
    }
};


class Tank
{
protected: 
    string name; 
    int weight; 
    int num_crews; 
    Engine *eng; 
    Turret *turr;

public: 
    void TankInput()
    {
        int type; 
        cin >> type; 
        cin >> weight; 
        eng->EngineInput(); 
        turr->TurretInput(); 
    }

    void TankOutput()
    {
        cout << name << ", weight: " << weight << ", number of crews: " << num_crews << ", damage: " << turr->total_damage();
    }

    virtual float performance()
    {
        
    }
};

class SU152 : public Tank
{
public: 
    
};


