#include <iostream>
#include <vector>

using namespace std;

// Receiver
class BankAccount
{
    int balance;

  public:
    BankAccount(int v = 0) : balance(v)
    {
    }
    int withdraw(int bal)
    {
        if (this->balance - bal >= 0)
            this->balance -= bal;

        cout << "Debided amount = " << bal << " Avaiable balance = " << this->balance << endl;

        return this->balance;
    }

    int deposite(int bal)
    {
        this->balance += bal;
        cout << "Credited amount = " << bal << " Avaiable balance = " << this->balance << endl;

        return this->balance;
    }
};

class Command
{
  public:
    enum OPERATION
    {
        WITHDRAW,
        DEPOSITE
    };
    OPERATION op;
    BankAccount &ba;
    int bal;

    Command(BankAccount &ba, OPERATION op, int bal) : ba(ba), op(op), bal(bal)
    {
    }

    void execute()
    {
        if (op == WITHDRAW)
            ba.withdraw(bal);
        if (op == DEPOSITE)
            ba.deposite(bal);
    }
};

int main()
{
    BankAccount ba(0);
    vector<Command> cmd = {
        Command(ba, Command::OPERATION::DEPOSITE, 500),
        Command(ba, Command::OPERATION::WITHDRAW, 100),
        Command(ba, Command::OPERATION::DEPOSITE, 400),
        Command(ba, Command::OPERATION::WITHDRAW, 500)};

    for (auto c : cmd)
        c.execute();

    return 0;
}