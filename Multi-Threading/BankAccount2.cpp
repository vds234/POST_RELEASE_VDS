//Bank Account Application using Non-static memeber function(Thread Safe)
#include <iostream>
#include <thread>
#include <mutex>
std::mutex mtx;

class BankAccount
{
    private:
        int accNo{};
        double balance{0.0};
    public:
        void deposit(double amt)
        {
            std::lock_guard<std::mutex> lock(mtx);
            balance = balance + amt;
            std::cout << "updated balance:" << balance;
        }

        void withdraw(double amt)
        {
            std::unique_lock<std::mutex> lock(mtx);
            if (balance == 0)
                std::cout << "Insuffienct fund...";
            else
                balance = balance - amt;
            
            std::cout << "balance:" << balance;
            lock.unlock();
        }
};
int main()
{
    BankAccount acc;

    std::thread t1(&BankAccount::deposit,&acc,1000);
    std::thread t2(&BankAccount::deposit,&acc,2000);
    std::thread t3(&BankAccount::withdraw,&acc,500);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}