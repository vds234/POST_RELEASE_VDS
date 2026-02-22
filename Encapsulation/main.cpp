//To demonstrate encapsulation principle
//1. What is Encapsulation in C++
//  Bundling of data and function together into a single unit i.e class
//  Controlled access to private data members outside class
//  Data hiding + class invariant(valid state of object)
//  
#include <iostream>
class Encapsulation
{
    private:
        float balance;
    public:
        Encapsulation(float bal):
            balance{bal}
            {
                std::cout << "Balance was initialized..";
            }
        
        void deposit(float bal)
        {
            balance = balance + bal;
        }

        float getBal()
        {
            return balance;
        }

        void withdraw(float amt)
        {
            if(balance < 0)
                std::cout << "Insuffienct balance...";
            else
                balance = balance - amt;
        }

};

int main()
{
    Encapsulation e(0);
    e.deposit(10000);
    std::cout << "Balance:" <<e.getBal();
    e.withdraw(5000);
    std::cout << "Balance:" <<e.getBal();
    return 0;
}