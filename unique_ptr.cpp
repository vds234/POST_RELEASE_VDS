#include <iostream>
template<typename T>
class Unique_ptr
{
    private:
        T* m_ptr{};

    public:
        Unique_ptr(T* p=nullptr)
            :m_ptr{p}
            {
                std::cout << "Unique pointer constructed...";
            }

        ~Unique_ptr()
        {
            std::cout << "Unique Ptr destructed..";
        }

        Unique_ptr(const Unique_ptr&) = delete;
        Unique_ptr& operator=(const Unique_ptr&) = delete;

        Unique_ptr(Unique_ptr<int>&& other)
            :m_ptr{other.m_ptr}
            {
                other.m_ptr = nullptr;
                std::cout << "Move Copy Constructor..";
            }

        Unique_ptr& operator=(Unique_ptr<int>&& other)
        {
            if(this != &other)
            {
                delete m_ptr;
                m_ptr = other.m_ptr;
                other.m_ptr = nullptr;
                std::cout << "Move assignment operator..";
            }
            return *this;
        }

        T* get() const
        {
            return m_ptr;
        }

        T& operator*() const{
            return *m_ptr;
        }

        T* operator->() const{
            return m_ptr;
        }

        void show()
        {
            std::cout << "hello Smart pointer..";
        }

        T* release() {
            T* temp = m_ptr;
            m_ptr = nullptr;
            return temp;
        }

        void reset(T* p = nullptr)
        {
            if(m_ptr!=p)
            {
                delete m_ptr;
                m_ptr = p;

            }
        }
};

int main()
{
    Unique_ptr<int> uptr(new int(10));
    //Unique_ptr<int> uptr1(uptr);  //error 
    //Unique_ptr<int> uptr2 = uptr; //error

    Unique_ptr<int> uptr1(std::move(uptr));  // Move Copy Constructor
    Unique_ptr<int> uptr2 = std::move(uptr1);  //Move Copy Constructor
    Unique_ptr<int> uptr3;  //Default Constructor
    uptr3 = std::move(uptr2);   //Move assignment operator

    std::cout << "Get the raw pointer:" << uptr.get();
    std::cout << "Dereferencing ptr:" << *uptr;

    //uptr->show();

    uptr3.release();

    uptr3.reset(new int(100));

    std::cout << "Get the raw pointer:" << uptr3.get();
    std::cout << "Dereferencing ptr:" << *uptr3;
    return 0;
}