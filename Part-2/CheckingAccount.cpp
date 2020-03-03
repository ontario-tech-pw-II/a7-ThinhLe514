#include "CheckingAccount.h"

using namespace std;

	
// constructor initializes balance and transaction fee
CheckingAccount::CheckingAccount( double initialBalance, double fee ) : Account( initialBalance ) 
{
	// your code
    if (fee >= 0.0)
    {
        transactionFee = fee;
    } else 
    {
        transactionFee = 0.0;
    }
} 

// credit (add) an amount to the account balance and charge fee
void CheckingAccount::credit( double amount )
{
	// your code
    Account::credit(amount);
    chargeFee();
} 

// debit (subtract) an amount from the account balance and charge fee
bool CheckingAccount::debit( double amount )
{
	// your code
    bool check = Account::debit(amount);
    if (check)
    {
        chargeFee();
        return true;
    }
    return check;
}

// subtract transaction fee
void CheckingAccount::chargeFee()
{
	// your code
    if (getBalance() >= transactionFee)
    {
        setBalance(getBalance() - transactionFee);
    } else
    {
        setBalance(0);
    }
}

void CheckingAccount::display(ostream & os) const
{
	// your code
    os << fixed << setprecision(2);
    os << "Account type: Checking" << endl;
    os << "Balance: $" << getBalance() << endl;
    os << "Transaction Fee: $" << transactionFee << endl;
}