#include "include/account.h"
#include<iostream>
#include<iomanip>
#include<ctime>

int newAccNo = 45100000;    
int Account::numAccounts = 0;  

Account::Account(){
    accountNumber = newAccNo++;
    name = "Account Holder";
    balance = 0;
    numAccounts++;
}

Account::Account(Account& account){
    std::cout<<"Copy of "<<accountNumber<<" constructed"<<std::endl;
}

Account::~Account(){
    numAccounts--;
}

double Account::withdrawal(unsigned int amount){
    if (amount > balance){
        std::cout<<"Insufficient funds."<<std::endl;
        return balance;
    }
    return balance -= amount;
}

double Account::deposit(unsigned int amount){
    return balance += amount;
}

std::string Account::getName(){return name;}

long long Account::getAccountNum(){ return accountNumber;}

double Account::getBalance(){ return balance;}

//Prompts user to choose between Chequing and Saving account
char Account::accountSelect(){
    char selectedAccount;
    do{
        std::cout<<"Which account would you like to access?\n"
                 <<"(Enter 'c' for Chequing or 's' for Saving)\n"
                 <<"C-Chequing\nS-Savings"<<std::endl;
        std::cin>>selectedAccount;
        selectedAccount = std::tolower(selectedAccount);
    } while (selectedAccount != 'c' && selectedAccount != 's');

    return selectedAccount;
}

//Prompts user to choose between Deposit and Withrawal
char Account::transactionSelect(){
    char selectedTransaction;
    do{
    std::cout<<"\nWhat transaction would you like to make?\nD - Deposit\n"
             <<"W - Withdrawal\n";
    std::cin>>selectedTransaction;
    selectedTransaction = std::tolower(selectedTransaction);
    } while (selectedTransaction != 'd' && selectedTransaction !='w');
    return selectedTransaction;
}

void Account::printReceipt (Account& acc){
    //Prints current date
    std::time_t now = std::time(nullptr);
    std::tm local_time = *std::localtime(&now);
    std::cout<<"\nDate: " << (local_time.tm_year + 1900) << "-" 
             << (local_time.tm_mon +1) << "-" << local_time.tm_mday 
             << std::endl;

    //Prints current time
    std::cout<<"Time: " << (local_time.tm_hour)<<":"
             <<(local_time.tm_min)<<std::endl;

    //Prints new balance
    std::cout<<"Balance: $"<< std::fixed << std::setprecision(2) 
             <<acc.getBalance() <<"\n\nThank you for choosing Bank of CPP"
             <<std::endl;
}