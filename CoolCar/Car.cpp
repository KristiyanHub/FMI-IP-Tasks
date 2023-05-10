#include <iostream>
using namespace std;

#pragma warning(disable:4996)

class CarPart
{
private:
    unsigned id;
    char* maker;
    char* description;

public:

    //id
    void setId(const unsigned setId)
    {
        this->id = setId;
    }

    unsigned getId() const
    {
        return this->id;
    }

    //maker
    void setMaker(char* setMaker)
    {
        strcpy(setMaker, maker);
    }

    char* getMaker() const
    {
        return this->maker;
    }

    //description
    void setDescription(char* setDescription)
    {
        strcpy(setDescription, maker);
    }

    char* getDescriptio() const
    {
        return this->description;
    }
};

class Tyre : public CarPart
{
private:
    unsigned wight;
    unsigned profile;
    unsigned diameter;
public:
    friend ostream& operator<<(ostream& os, const Tyre& t);

    //wight
    void setWight(unsigned setWight)
    {
        if (setWight >= 155 || setWight <= 365)
        {
            this->wight = setWight;
        }
        else
        {
            throw "Sus";
        }
    }

    unsigned getWight() const
    {
        return this->wight;
    }

    //profile
    void setProfile(unsigned setProfile)
    {
        if (setProfile >= 30 || setProfile <= 80)
        {
            this->profile = setProfile;
        }
        else
        {
            throw "Sus";
        }

    }

    unsigned getProfile() const
    {
        return this->profile;
    }

    //diameter
    void setDiameter(unsigned setDiameter)
    {
        if (setDiameter >= 13 || setDiameter <= 21)
        {
            this->diameter = setDiameter;
        }
        else
        {
            throw "Sus";
        }
    }

    unsigned getDiameter() const
    {
        return this->diameter;
    }
};

ostream& operator<<(ostream& os, const Tyre& t)
{
    os << t.getId() << " By " << t.getMaker() << " - " << t.getDescriptio() << " - " << t.getWight() << "/" << t.getProfile() << "R" << t.getDiameter();
    return os;
}

class Engine : public CarPart
{
private:
    int horsePowers;

public:
    friend ostream& operator<<(ostream& os, const Engine& e);

    void setHorsePowers(int setorsePowers)
    {
        this->horsePowers = setorsePowers;
    }

    int getHorsePowers() const
    {
        return this->horsePowers;
    }
};

ostream& operator<<(ostream& os, const Engine& e)
{
    os << e.getId() << " By " << e.getMaker() << " - " << e.getDescriptio() << " - " << e.getHorsePowers() << " hp";
    return os;
}

class Accumolator : public CarPart
{
private:
    int amperHours;
    int acId;

public:
    friend ostream& operator<<(ostream& os, Accumolator& a);

    void setAmperHours(int setAmperHours)
    {
        this->amperHours = setAmperHours;
    }

    int getAmperHours() const
    {
        return this->amperHours;
    }

};

ostream& operator<<(ostream& os, Accumolator& a)
{
    os << a.getId() << " By " << a.getMaker() << " - " << a.getDescriptio() << " - " << a.getAmperHours() << " Ah";
    return os;
}



class FuelTank
{
private:
    float capacity;
    float fuel;

public:

    FuelTank(float capacitor)
    {
        capacity = capacitor;
    }

    void FuelTankUse(float toUse)
    {
        fuel -= toUse;

        try
        {
            float canBeUsed = fuel;

            if (canBeUsed < toUse)
            {
                throw(canBeUsed);
            }
        }
        catch (float canBeUsed)
        {
            throw "insufficient_fuel_error";
        }
    }

    void FuelTankFill(float toFill)
    {
        fuel += toFill;
    }

    //capacity
    void setCapacity(float currentCapacity)
    {
        this->capacity = currentCapacity;
    }

    float getCapacity()
    {
        return this->capacity;
    }

    //fuel
    void setFuel(float currentFuel)
    {
        this->fuel = currentFuel;
    }

    float getFuel()
    {
        return this->fuel;
    }
};

class Car
{
private:
    FuelTank currentTank;
    Engine currentEngine;
    Tyre currentTyre[4];
    Accumolator currentAccumolator;
    float kilometersPassed;
    float weightInKG;

public:

    //create constructor for all of the above later ^^^

    const FuelTank& getFuelTank()
    {
        return this->currentTank;
    }

    void drive(float km, FuelTank currentFuel)
    {
        kilometersPassed += km;
        currentFuel.FuelTankUse(km);
    }
};

Car* dragRace(Car* car1, Car* car2)
{
    if (car1->drive <= 0)
    {
        return car2;
    }
    else if (car1->drive == 0 && car2->drive == 0)
    {
        return nullptr;
    }
    else
    {
        return car1;
    }


    
}


int main()
{
    std::cout << "Get out! NOW\n";

    return 0;
}
