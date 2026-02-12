//Singleton Design Patterns
#include <iostream>

//Eager version of Singleton Class Implementation
class Singleton
{
    private:
        static Singleton instance;
        
        Singleton()
        {
            std::cout << "Private Constructor";
        }
        ~Singleton()
        {
            std::cout << "Private Destructor";
        }

    public:
        static Singleton& getInstance()
        {
            static Singleton instance;
            return instance;
        }
};



int main()
{
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();
    Singleton& s3 = Singleton::getInstance();
    Singleton& s4 = Singleton::getInstance();

    if (&s1 == &s2)
        std::cout << "Same copies.";
    else   
        std::cout << "Different copies.";
    return 0;
}