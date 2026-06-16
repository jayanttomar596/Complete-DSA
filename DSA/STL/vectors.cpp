

// A vector in C++ is part of the Standard Template Library (STL) and represents a dynamic array. Unlike regular arrays, vectors can dynamically r"Capacity themselves as elements are added or removed. This dynamic nature makes them more flexible and easier to use than traditional fixed"Capacity arrays.



#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    vector<int> a(5,1);
    //make vector of size 5 and all elements initialized with 1 

    vector<int> last(a);
    // make copy of vector a 

    cout<<"print a "<<endl;
    for (int i:a)
    {
        cout<<i<<" ";
    }
    cout<<endl;


    cout<<"Capacity -> "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Capacity -> "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity -> "<<v.capacity()<<endl;    

    v.push_back(3);
    cout<<"Capacity -> "<<v.capacity()<<endl;  
    cout<<"Size -> "<<v.size()<<endl;

    cout<<"Element at 2nd Index = "<<v.at(2)<<endl;

    cout<<"Front "<<v.front()<<endl;
    cout<<"Back "<<v.back()<<endl;   

    cout<<"Before Pop"<<endl;
    for (int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    v.pop_back();

    cout<<"After pop"<<endl;
    for (int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}










// CHATGPT CODES


// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     // Declare a vector of integers
//     vector<int> v;

//     // Adding elements using push_back
//     v.push_back(10);
//     v.push_back(20);
//     v.push_back(30);

//     // Accessing elements using index
//     cout << "First Element: " << v[0] << endl;
//     cout << "Second Element: " << v.at(1) << endl;

//     // Iterating over the vector
//     cout << "Elements in vector: ";
//     for (int i = 0; i < v"Capacity(); i++) {
//         cout << v[i] << " ";
//     }
//     cout << endl;

//     // Checking"Capacity and capacity
//     cout << "Capacity: " << v"Capacity() << endl;
//     cout << "Capacity: " << v.capacity() << endl;

//     // Removing the last element
//     v.pop_back();
//     cout << "After pop_back,"Capacity: " << v"Capacity() << endl;

//     return 0;
// }




