#include<iostream>
#include<memory>
template<typename T>
class sharedPtr
{
    private:
        T* m_ptr{};
        int* counter;
    public:
        sharedPtr(T* p = nullptr)
            :m_ptr{p},
            counter{new int (1)}
            {
                std::cout << "Constructor Called..";
            }
        ~sharedPtr()
        {
            std::cout <<"Destructor Called..";
            delete m_ptr;
        }

        void increCounter()
        {
            if(counter)
                (*counter)++;
        }

        void decreCounter()
        {
            if(counter)
                (*counter)--;
                if((*counter) == 0)
                {
                    if(m_ptr)
                    {
                        delete m_ptr;
                        delete counter;
                        m_ptr = nullptr;
                        counter = nullptr;
                    }
                }
        }
        //Copy Constructor
        sharedPtr(const sharedPtr& other)
        {
            m_ptr = other.m_ptr;
            counter = other.counter;
            increCounter();
        }

        //Move Constructor
        sharedPtr(sharedPtr&& other)
        {
            m_ptr = other.m_ptr;
            counter = other.counter;
           other.m_ptr = nullptr;
           other.counter = nullptr;
        }

        //Move assignment operator Constructor
        sharedPtr& operator=(sharedPtr&& other)
        {
            if(this!=&other)
            {
                decreCounter();
                m_ptr = other.m_ptr;
                counter = other.counter;
                other.m_ptr = nullptr;
                other.counter = nullptr;
            }
            return *this;
            
        }

        //copy assignment operator
        sharedPtr& operator=(const sharedPtr& other)
        {
            if(this!=&other)
            {
                decreCounter();
                m_ptr = other.m_ptr;
                counter = other.counter;
                increCounter();
            }
            return *this;
        }

        T& operator*()
        {
            return *m_ptr;
        }

        T* get() const{
            return m_ptr;
        }

        int use_count()
        {
            if(counter)
                return *counter;
        }

        void reset(T* p = nullptr)
        {
            decreCounter();
            m_ptr = p;
            counter = new int(1);
        }
};
int main()
{
    sharedPtr<int> ptr;
    std::cout << "Counter:" << ptr.use_count();
    // std::cout << "Dereferencing:" << *ptr;
    // std::cout << "Get The raw pointer:" << ptr.get();

    sharedPtr<int> ptr1(new int(20));
    std::cout << "Dereferencing:" << *ptr1;
    std::cout << "Get The raw pointer:" << ptr1.get();
    std::cout << "Counter:" << ptr1.use_count();

    //Copy Constructor to allow shared access
    sharedPtr<int> ptr2(ptr1);
    std::cout << "Dereferencing:" << *ptr2;
    std::cout << "Get The raw pointer:" << ptr2.get();
    std::cout << "Counter:" << ptr2.use_count();

    sharedPtr<int> ptr3(new int(50));
    std::cout << "Dereferencing:" << *ptr3;
    std::cout << "Get The raw pointer:" << ptr3.get();
    std::cout << "Counter:" << ptr3.use_count();

    sharedPtr<int> ptr4 = ptr3;
    std::cout << "Dereferencing:" << *ptr4;
    std::cout << "Get The raw pointer:" << ptr4.get();
    std::cout << "Counter:" << ptr4.use_count();

    sharedPtr<int> ptr5 = std::move(ptr3);
    std::cout << "Dereferencing:" << *ptr4;
    std::cout << "Get The raw pointer:" << ptr4.get();
    std::cout << "Counter:" << ptr4.use_count();

    ptr5 = std::move(ptr2);
    std::cout << "Dereferencing:" << *ptr5;
    std::cout << "Get The raw pointer:" << ptr5.get();
    std::cout << "Counter:" << ptr5.use_count();

    ptr5.reset(new int(10));
    std::cout << "Dereferencing:" << *ptr5;
    std::cout << "Get The raw pointer:" << ptr5.get();
    std::cout << "Counter:" << ptr5.use_count();

    return 0;
}

