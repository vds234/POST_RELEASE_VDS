#include <iostream>
#include <thread>
#include <atomic>


thread_local int shared_data = 0;
void increament()
{
    ++shared_data;
    std::cout << "Shared Data:" << shared_data << std::endl;
}

int main()
{
    std::thread t1(increament);
    std::thread t2(increament);

    t1.join();
    t2.join();

    return 0;
}