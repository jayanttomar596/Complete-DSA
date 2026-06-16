// A List in C++ can be implemented using the std::list container from the Standard Template Library (STL). It is a doubly-linked list, meaning each element (node) contains pointers to both its previous and next elements.

#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;

    // list <int> n(l);
    //to make a list name n which is copy of l

    list<int> n(5,100);
    //list of size 5 and each element = 100

    cout<<"Printing n "<<endl ;
    for (int i:n)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    l.push_back(1);
    l.push_front(2);

    for (int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    l.erase(l.begin());
    // ek ek element erase karega starting me se
    cout<<"After Erase "<<endl;
    for (int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Size of List "<<l.size()<<endl;
    return 0;
}








// CHATGPT CODES

// #include <iostream>
// #include <list>
// using namespace std;

// int main() {
//     list<int> myList;

//     // Adding elements
//     myList.push_back(10);
//     myList.push_front(20);

//     // Displaying elements
//     cout << "List elements: ";
//     for (auto it = myList.begin(); it != myList.end(); ++it) {
//         cout << *it << " ";
//     }
//     cout << endl;

//     // Size
//     cout << "Size: " << myList.size() << endl;

//     // Sorting and reversing
//     myList.push_back(15);
//     myList.sort();
//     myList.reverse();

//     cout << "Sorted and reversed list: ";
//     for (auto x : myList) {
//         cout << x << " ";
//     }
//     cout << endl;

//     return 0;
// }






