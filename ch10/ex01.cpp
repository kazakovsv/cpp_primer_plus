// Provide method definitions for the class described in Chapter Review
// Question 5 and write a short program that illustrates all the features.
// Question 5: Define a class to represent a bank account. Data members should
// include the depositor’s name, the account number (use a string), and the
// balance. Member functions should allow the following:
// - Creating an object and initializing it.
// - Displaying the depositor’s name, account number, and balance.
// - Depositing an amount of money given by an argument.
// - Withdrawing an amount of money given by an argument.

#include <iostream>

class BankAccount
{
private:
    std::string m_name;
    std::string m_iban;
    int m_balance;
public:
    BankAccount(const std::string & name, const std::string & iban, int balance = 0.0);
    void Display() const;
    void Deposit(int amount);
    void Withdraw(int amount);
};

BankAccount::BankAccount(const std::string & name, const std::string & iban, int balance)
{
    m_name = name;
    m_iban = iban;
    m_balance = balance < 0 ? 0 : balance;
}

void BankAccount::Display() const
{
    std::cout << "Name: " << m_name << ", IBAN: " << m_iban
              << ", Balance: $" << m_balance << std::endl;
}

void BankAccount::Deposit(int amount)
{
    if (amount > 0)
    {
        m_balance += amount;
    }
}

void BankAccount::Withdraw(int amount)
{
    if (m_balance >= amount)
    {
        m_balance -= amount;;
    }
}

int main()
{
    BankAccount bankAccount = BankAccount("Stas", "123412341234", 50000);
    bankAccount.Display();
    bankAccount.Deposit(5000);
    bankAccount.Display();
    bankAccount.Withdraw(3000);
    bankAccount.Display();
    
    return 0;
}