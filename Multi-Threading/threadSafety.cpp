//Simple Multi-threading program with thread safety.
#include <iostream>
#include <thread>
#include <mutex>
std::mutex mtx;

void printNumbers()
{
    mtx.lock();
    for(int i=0;i<100;i++)
    {
        
        std::cout << "Number:" << i << std::endl;
        
    }
    mtx.unlock();
}

int main()
{
    std::thread t1(printNumbers);
    std::thread t2(printNumbers);
    t1.join();
    t2.join();

    return 0;
}