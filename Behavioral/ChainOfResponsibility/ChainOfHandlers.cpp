#include <iostream>
#include <string>

using namespace std;

struct Hero
{
    string name;
    int attack;
    int defense;

    Hero(const string &name, int attack, int defense) : name(name), attack(attack), defense(defense)
    {
    }

    friend ostream &operator<<(ostream &os, const Hero &obj)
    {
        return os << "name: " << obj.name << " attack: " << obj.attack << " defense: " << obj.defense << endl;
    }
};

class PowerHandler
{
  protected:
    Hero &hero;
    PowerHandler *next = nullptr;

  public:
    PowerHandler(Hero &h) : hero(h)
    {
    }

    void AddHandler(PowerHandler *handler)
    {
        if (next != nullptr)
            next->next = handler;
        else
            next = handler;
    }

    virtual void Handle()
    {
        if (next != nullptr)
            next->Handle();
    }
};

class NoBonus : public PowerHandler
{
  public:
    NoBonus(Hero &h) : PowerHandler(h)
    {
    }

    void Handle() override
    {
    }
};

class DoubleAttack : public PowerHandler
{
  public:
    DoubleAttack(Hero &h) : PowerHandler(h)
    {
    }

    void Handle() override
    {
        (this->hero).attack++;
        if ((this->hero).attack % 2)
            (this->hero).attack *= 2;

        else
            PowerHandler::Handle();
    }
};

class IncreaseDefense : public PowerHandler
{
  public:
    IncreaseDefense(Hero &h) : PowerHandler(h)
    {
    }

    void Handle() override
    {
        if ((this->hero).defense < (this->hero).attack)
            (this->hero).defense++;

        else
            PowerHandler::Handle();
    }
};

int main()
{
    Hero Batman("Batman", 1, 1);
    cout << Batman;

    DoubleAttack root(Batman);
    DoubleAttack r1(Batman);
    IncreaseDefense r2(Batman);
    NoBonus r3(Batman);

    //root.AddHandler(&r3); //Uncomment and see the effect
    root.AddHandler(&r1);
    root.AddHandler(&r2);

    root.Handle();
    cout << Batman;

    return 0;
}