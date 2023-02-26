#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>

class Account
{
public:
    Account();
    Account(Account&);
    ~Account();

    virtual double withdrawal(unsigned int);
    double deposit(unsigned int);
    double getBalance();
    std::string getName();
    long long getAccountNum();
    static char accountSelect();
    static char transactionSelect();
    void printReceipt(Account&);

protected:
    long long accountNumber;
    std::string name;
    double balance;
    static int numAccounts;
};
#endif