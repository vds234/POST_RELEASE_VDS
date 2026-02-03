//Simple Multi-threading program without thread safety.
#include <iostream>
#include <thread>

void printNumbers()
{
    for(int i=0;i<100;i++)
    {
        std::cout << "Number:" << i << std::endl;
    }
}

int main()
{
    std::thread t1(printNumbers);
    std::thread t2(printNumbers);
    t1.join();
    t2.join();

    return 0;
}