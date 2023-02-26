#include "include/account.h"
#include "include/saving.h"

Saving::Saving(){
    transactionCount = 0;
}

double Saving::withdrawal(unsigned int amount){
    if (amount > balance){
        std::cout<<"Insufficient funds."<<std::endl;
        return balance;
    }
    if (transactionCount > 5){
        std::cout<<"\nYou have reached your withdrawal limit."<<std::endl;
        return balance;
    }
    
    transactionCount++;
    return balance -= amount;
}

Saving::~Saving(){}