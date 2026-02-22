//To demonstrate abstraction through example
//1. What is abstraction in c++
//  Hiding implementation details and showing only the interface to user.
//  Achieved using abstract class and interfaces

#include <iostream>
class Abstraction
{
    private:
    public:
        virtual void payment() = 0;
        virtual ~Abstraction() = default;
        
};

class UPIPayment:public Abstraction
{
    private:
    public:
        void payment() override
        {
            std::cout << "Initiate UPI Payment...";
        }
};

class CreditCardPayment:public Abstraction
{
    private:
    public:
        void payment() override
        {
            std::cout << "Initiate Credit Card Payment..";
        }
};

int main()
{
    Abstraction* ptr = new UPIPayment();
    ptr->payment();
    delete ptr;
    return 0;
}