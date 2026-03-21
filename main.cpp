#include <iostream>
#include <array>
class Array
{
    public:
        int at(int index);
        int size();
        int front();
        int back();
        int operator[](int index);
        Array(int n):count(n)
        {
            arr = new int[n];
            std::cout << "Enter Elements:";
            for(int i=0;i<n;i++)
            {
                std::cin >> arr[i];
            }
            
        }

         ~Array() {
        delete[] arr; 
    }
    private:
        int *arr;
        int count;
};


int Array::at(int index)
{
    if(index >=0 && index < count)
        return arr[index];
    else
        throw std::out_of_range("Invalid Index..");
}

int Array::front()
{
    return arr[0];
}

int Array::back()
{
    return arr[count-1];
}

int Array::operator[](int index)
{
    if(index >=0 && index < count)
        return arr[index];
}

int Array::size()
{
    return count;
}


int main()
{
    std::cout << "Example Demonstrating std::array...";
    Array objArr(5);
    std::cout << "Size of array:" << objArr.size();
    //objArr.fill();
    std::cout << "Array Element at index:" << objArr.at(3);
    std::cout << "Array Element at index:" << objArr[4];

    std::cout << "First Element:" << objArr.front();
    std::cout << "Last Element:" << objArr.back();
    
    return 0;
}