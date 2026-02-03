//Multi-threaded application without thread safe.
//Simple thread creation
#include <iostream>
#include <thread>

void display1()
{
    for(int i=0;i<10000;i++)
    {
        std::cout << "Hello";
        std::cout << i << std::endl;
    }
}
void display2()
{
    for(int i=0;i<10000;i++)
    {
        std::cout << i << std::endl;
    }
}
int main()
{
    std::thread t1(display1);
    std::thread t2(display2);
    t1.join();
    t2.join();
    return 0;
}