#include <iostream>
#include <thread>
#include <vector>

void workerThread()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "These thread sleep for 2 seconds before checking for job...";
}

int main()
{
    std::vector<std::thread> vec;
    int numThreads = 5;
    for(int i=0;i<numThreads;i++)
    {
        vec.emplace_back(workerThread);
    }

    for(auto& it:vec)
    {
        it.join();
    }
}