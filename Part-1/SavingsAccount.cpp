#include "SavingsAccount.h"

using namespace std;

// constructor initializes balance and interest rate
SavingsAccount::SavingsAccount(double initialBalance, double rate) : Account(initialBalance)
{
    // your code
    if (rate >= 0.0)
        interestRate = rate * 100;
    else
        interestRate = 0.0;
}

double SavingsAccount::calculateInterest()
{
    // your code
    return getBalance() * interestRate;
}
void SavingsAccount::display(ostream &os) const
{
    // your code
    os << fixed << setprecision(2);
    os << "Account type: Saving" << endl;
    os << "Balance: $" << getBalance() << endl;
    os << "Interest Rate (%): " << interestRate << endl;
}