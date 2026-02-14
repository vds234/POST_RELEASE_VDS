#include <iostream>
#include <memory>
template <typename T>
class uniqueptr
{
    private:
        T* m_ptr{};
    public:
        uniqueptr(T* ptr = nullptr)
            :m_ptr(ptr)
            {
                std::cout << "Constructor Called..";
            }

        ~uniqueptr()
        {
            delete m_ptr;
        }
            //Delete Copy Constructor and Copy assignment operator
            uniqueptr(const uniqueptr&)=delete;
            uniqueptr& operator=(const uniqueptr&)=delete;

            //Move Copy Constructor
            uniqueptr(uniqueptr&& other)
            {
                m_ptr = other.m_ptr;
                other.m_ptr = nullptr;
            }

            //Move Assignment Operator
            uniqueptr& operator=(uniqueptr&& other)
            {
                if(&other!=this)
                {
                    delete m_ptr;
                    m_ptr = other.m_ptr;
                    other.m_ptr = nullptr;
                }
                return *this;
            }

            T& operator*()
            {
                return *m_ptr;
            }

            T* operator->()
            {
                return m_ptr;
            }

            T* get() const{
                return m_ptr;
            }

            void reset(T* ptr = nullptr)
            {
                if(m_ptr)
                    delete m_ptr;
                m_ptr = ptr;
                ptr = nullptr;
            }

            T* release()
            {
                T* temp = m_ptr;
                m_ptr = nullptr;
                return temp;
            }
};

int main()
{
    uniqueptr<int> ptr;
    //std::cout << "Dereferencing:" << *ptr;
    std::cout << "Get the Raw Pointer:" << ptr.get();

    uniqueptr<int> ptr1(new int(42));
    std::cout << "Dereferencing:" << *ptr1;
    std::cout << "Get the Raw Pointer:" << ptr1.get();

    uniqueptr<int> ptr4 = std::move(ptr1);
    std::cout << "Dereferencing:" << *ptr4;
    std::cout << "Get the Raw Pointer:" << ptr4.get();

    // std::cout << "Dereferencing:" << *ptr1;
    // std::cout << "Get the Raw Pointer:" << ptr1.get();

    uniqueptr<int> ptr3(new int(50));
    std::cout << "Dereferencing:" << *ptr3;
    std::cout << "Get the Raw Pointer:" << ptr3.get();

    //ptr4 = ptr3;

    ptr4 = std::move(ptr3);

    ptr4.reset(new int(60));
    std::cout << "Dereferencing:" << *ptr4;
    std::cout << "Get the Raw Pointer:" << ptr4.get();

    int* temp = ptr4.release();
    std::cout << "Raw pointer:" << *temp;


    

    //Copy Constructor deleted in unique ptr
    // uniqueptr<int> ptr2(ptr1);  //
    // std::cout << "Dereferencing:" << *ptr2;
    // std::cout << "Get the Raw Pointer:" << ptr2.get();

    //Copy assignment operator deleted.
    // uniqueptr<int> ptr3;
    // ptr3 = ptr1;
    // std::cout << "Dereferencing:" << *ptr3;
    // std::cout << "Get the Raw Pointer:" << ptr3.get();


    return 0;
}