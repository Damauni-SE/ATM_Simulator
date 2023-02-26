#include "include/account.h"
#include "include/chequing.h"


Chequing::Chequing(){} 

double Chequing::withdrawal(double amount){
    double temp_bal = (balance - (amount + applyFee()));
    if (temp_bal >= 0){
        std::cout<<"\n$"<<fee<<" fee applied for withdrawal."<<std::endl;
        balance = temp_bal;
        return balance;
    }
    else if(temp_bal < 0){
        std::cout<<"\nInsufficient Funds."<<std::endl;
        return balance;
    }
    return balance;
}

double Chequing::applyFee(){
    fee = 0;
    if (balance >= 500 && balance <= 5000){
        fee = 1.5;
        return fee;
    }
    else if(balance > 5000){
        fee = 3.5;
        return fee;
    }
    return fee;
}

Chequing::~Chequing(){}