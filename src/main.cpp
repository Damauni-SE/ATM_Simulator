/* Author: Dwayne Bingham
 * Program designed to simulate an ATM bank transaction.
 */

#include "include/account.h"
#include "include/chequing.h"
#include "include/saving.h"
#include<iostream>

using namespace std;

int main()
{
    std::cout<<"\t\t+-------------+"<<std::endl;
    std::cout<<"\t\t| Bank of CPP |"<<std::endl;
    std::cout<<"\t\t+-------------+\n"<<std::endl;

    Chequing c;
    Saving s;
    
    char choice;
    int amt;
    do{
        //Prompts user to choose between Chequing and Saving account
        char selectedAccount = Account::accountSelect();

        //Prompts user to choose between Deposit and Withrawal
        char selectedTransaction = Account::transactionSelect();

        //Performs selected transaction
        if (selectedAccount == 'c' && selectedTransaction == 'd'){
            std::cout<<"Enter amount to deposit in Chequing: ";
            std::cin>>amt;
            c.deposit(amt);
            c.printReceipt(c);
        }
        else if (selectedAccount == 'c' && selectedTransaction == 'w'){
            std::cout<<"Enter amount to withdraw from Chequing: ";
            std::cin>>amt;
            c.withdrawal(amt);
            c.printReceipt(c);
        }
        else if (selectedAccount == 's' && selectedTransaction == 'd'){
            std::cout<<"Enter amount to deposit in Saving: ";
            std::cin>>amt;
            s.deposit(amt);
            s.printReceipt(s);
        }
        else if (selectedAccount == 's' && selectedTransaction == 'w'){
            std::cout<<"Enter amount to withdraw from Saving: ";
            std::cin>>amt;
            s.withdrawal(amt);
            s.printReceipt(s);
        }

        std::cout<<"\nWould you like to make another transaction (Y/N)? ";
        std::cin>>choice;
        choice = tolower(choice);
        if (choice == 'n'){
            break;
        }
    } while (choice == 'y');

    return 0;
}
