//To demonstrate encapsulation with Banking Example
    //Write a class with Name Bank
    //with variable accountNo and balance
    //Operations:- Deposit(), Withdraw(), Initialize varible
//1. What is Encapsulation in C++
//  Bundling of data and function together into a single unit i.e class
//  Controlled access to private data members outside class i.e getters() and setters() and constructor
//  Data hiding + class invariant(valid state of object) i.e private or protected
//2. How Encapsulation was achieved?
//  Using Access specifier and classes.
//3. why encapsulation is needed?
//  -->Modularize the code.
//  -->Maintainability.
//  -->Data Security.
//  -->Flexibilty.
//  -->Data Consistency.
//4. What will happen if encapsulation not used?
//  --Data Corruption.
//  --Invalid Object state i.e System crashes or undefined behaviour.
//  --Direct variable access to modify.
//  --Tight Coupling
//5. Encapsulation Supports 
//  --Single Responsibilty Principle
//  --Open/Closed Principle
//  --liskov Substitution Principle
//6. IEWS Project
//  --Bundling data + members
//  --Controlled Access
//  --Data Hiding + Class invariant
#include <iostream>
class BankDetails
{
    private:
        double m_accNumber{};
        double m_balance{};
    public:
        BankDetails(double accNo,double bal)
            :m_accNumber{accNo},
            m_balance{bal}
            {
                std::cout << "Updated Account Details..";
            }

        void deposit(double amount)
        {
            m_balance = m_balance + amount;
            std::cout << "Amount of Rs " << amount << " is Deposited successfully.\n";
            std::cout << "Balance is Rs " << m_balance <<std::endl;
        }

        void withdraw(double amount)
        {
            if(m_balance < 0)
                throw std::out_of_range("Insuffienct Balance...");
            else
            {
                m_balance -= amount;
                std::cout << "Amount of Rs " << amount << " is withdraw successfully.\n";
                std::cout << "Balance is Rs " << m_balance<< std::endl;
            }
                
        }

        // double getBalance() const{
        //     return m_balance;
        // }
};

int main()
{
    BankDetails b(1234,10000);
    b.deposit(1000);
    b.withdraw(200);

   // std::cout << "Balance is:" << b.getBalance();

    return 0;
}