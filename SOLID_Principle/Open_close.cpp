//Open-Close Principle
//Open for extension but Close for modification
//New functionality can be added but existing code not be modified.
#include <iostream>
// class Payments
// {
//     private:
//     public:
//         void pay(std::string type)
//         {
//             if(type == "CreditCard")
//             {
//                 std::cout << "Payment initiated..,";
//             }
//             else if(type == "UPI")
//             {
//                 std::cout << "Payment initiated..,";
//             }

//             //Suppose if  we add new payment type in above code like
//             //These breaks the Open Close principle.
//             //Existing code should not get modified, so we are adding new type in it.

//             else if(type == "DebitCard")
//             {
//                 std::cout << "Payment initiated..,";
//             }

//             else if(type == "Cash")
//             {
//                 std::cout << "Payment initiated..,";
//             }
//             else 
//             {
//                 std::cout << "Payment not initiated..,";
//             }
            
//         }
// };

//Solution
//Will create an anstract class of Payment.
//Subsequet type class will inherit it provide its own implementation

class Payments
{
    public:
        virtual void pay() = 0;
};

class CreditCard:public Payments
{
    public:
        void pay() override
        {
            std::cout << "Credit Card Payment Initiated...";
        }
};

class UPI:public Payments
{
    public:
        void pay() override
        {
            std::cout << "UPI Payment Initiated...";
        }
};

class PayPal:public Payments
{
    public:
        void pay() override
        {
            std::cout << "PayPal Payment Initiated...";
        }
};
int main()
{
    Payments* p = new UPI();
    p->pay();
    return 0;
}