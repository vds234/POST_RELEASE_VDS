//Singleton Design Patterns
#include <iostream>
#include <mutex>
std::mutex mtx;


//Thread-Safe(Double lock) version of Singleton Class Implementation
class Singleton
{
    private:
        static Singleton* instance;
        static std::mutex mtx;
        Singleton()
        {
            std::cout << "Private Constructor";
        }
        ~Singleton()
        {
            std::cout << "Private Destructor";
        }
    public:
        static Singleton* getInstance()
        {
            std::lock_guard<std::mutex> lock(mtx);
            if(instance == nullptr)
            {
                instance = new Singleton();
            }
            return instance;
        }
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;


int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    Singleton* s3 = Singleton::getInstance();
    Singleton* s4 = Singleton::getInstance();

    if (s1 == s2)
        std::cout << "Same copies.";
    else   
        std::cout << "Different copies.";
    return 0;
}