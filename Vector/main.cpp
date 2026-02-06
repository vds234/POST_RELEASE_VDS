#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class MyVector
{
    private:
        T* data;
        int size;
        int capacity;

        void resize(int new_capacity)  //1
        {
            T* new_data = new T[new_capacity];
            for(int i=0;i<size;i++)
            {
                new_data[i] = data[i];
            }

            delete [] data;
            data = new_data;
            capacity = new_capacity;
        }

    public:
        MyVector():data(new T[capacity]),size(0),capacity(1)
        {
            std::cout << "Constructor called...";
        }

        void push_back(const T& value)  //2
        {
            std::cout << "Pushing an element to vector...";
            if (size == capacity)
                resize(2*capacity);
            new (&data[size]) T(value);   // copy
            size++;
            //size++;
        }
        template<class ...Args>
        void emplace_back(Args&&... args)  //2
        {
            std::cout << "Pushing an element to vector...";
            if (size == capacity)
                resize(2*capacity);
            new (&data[size]) T(std::forward<Args>(args)...);   // copy
            size++;
            //size++;
        }

        void pop_back()  //3
        {
            if(size > 0)
                --size;
            else
                std::cout << "Throw exception out_of range..";
        }

        int getSize() const{  //4
            return size;
        }

        int getCapacity() const{  //5
            return capacity;
        }

        bool isEmpty() const{  //6
            if(size > 0)
                return 1;
            else
                return 0;
        }

        T at(int index) {  //7
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of range");
    }
    return data[index];
}

        void erase(size_t pos) {
        if (pos >= size) return;  // or throw

        // destroy element at pos
        data[pos].~T();

        // shift elements left
        for (int i = pos; i < size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }

        // destroy last (now duplicate)
        data[size - 1].~T();

        size--;
    }
};

int main()
{
    MyVector<int> v;
    v.push_back(20);
    std::cout << "Size of vector:" << v.getSize();
    v.push_back(10);
    std::cout << "Size of vector:" << v.getSize();
    v.pop_back();
    std::cout << "Size of vector:" << v.getSize();
    std::cout << "Capacity of vector:"<< v.getCapacity();
    v.push_back(12);
    v.push_back(13);
    std::cout << "Capacity of vector:"<< v.getCapacity();
    std::cout << "Is vector empty:" << v.isEmpty();
   
    int v1 = v.at(0);
    std::cout << "Element at index:" << v1;

    v.erase(2);

    return 0;
}