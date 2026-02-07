#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l1;
    cout << "Empty List:" << l1.size();

    //Inserting elements to the list
    l1.push_back(20);
    l1.push_front(10);
    l1.emplace_back(30);
    l1.emplace_front(40);
    l1.insert(l1.begin(),50);
    cout <<"List Contains:" << l1.size();

    //Display front and back
    cout << "Front Element:" << l1.front();
    cout <<"Back Element:" << l1.back();

    //Display list elements
    for(int& lEle:l1)
    {
        cout << "Each Element in the list:"<< lEle;
    }

    //Remove elements from the list
    l1.pop_back();
    l1.pop_front();
    l1.erase(l1.begin());
    l1.remove(2);

    cout << "Element left in the list:"<< l1.size();
    for(int& lEl:l1)
    {
        cout << "Each Element in the list:"<< lEl;
    }

    return 0;
}