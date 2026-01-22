//To Print array element
#include <iostream>
int main()
{
    int a[] = {1,2,3,4,5};
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        std::cout << "Array element:" << a[i] << "\n";
    }
    return 0;
}