//Multi-threaded application without thread safe.
//Simple thread creation
#include <iostream>
#include <thread>
#include <mutex>
std::mutex mtx;

void display1()
{
    mtx.lock();
    for(int i=0;i<10000;i++)
    {
        
        std::cout << i << std::endl;
        
    }
    mtx.unlock();
}

int main()
{
    std::thread t1(display1);
    std::thread t2(display1);
    t1.join();
    t2.join();
    return 0;
}