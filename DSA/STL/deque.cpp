
// A Deque (Double-Ended Queue) is a data structure that allows insertion and deletion of elements from both ends (front and rear). It is implemented in C++ using the deque class in the Standard Template Library (STL).


#include <iostream>
#include <deque>
using namespace std;

int main() {
    
    deque<int> d;

    d.push_back(1);
    d.push_front(2);

    for (int i : d)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //d.pop_front()
    d.pop_back();
    for (int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    d.push_back(1);

    cout<<"Print First Index Element -> "<<d.at(1)<<endl;

    cout<<"Front "<<d.front()<<endl;
    cout<<"End "<<d.back()<<endl;

    cout<<"Empty or not : "<<d.empty()<<endl;


    cout<<"Before Erase "<<d.size()<<endl;

    d.erase(d.begin(),d.begin() + 1);
    // this erased first element that is 2

    cout<<"After Erase "<<d.size()<<endl;

    
    cout<<d.front()<<endl;
    return 0;
}










/*
Advantages of deque:
Efficient Front Operations: It supports push_front and pop_front, making it a better choice for double-ended operations.
No Complete Reallocation: Adding elements at either end does not require reallocating and copying the entire container.

Advantages of vector:
Contiguous Memory: All elements are stored in contiguous memory, leading to better cache performance and faster iteration.
Better for Random Access: Faster iteration and access due to the contiguous layout.
*/


// CHATGPT CODES

// #include <iostream>
// #include <deque>
// using namespace std ;

// int main() {
//     // Initialize a deque
//     deque<int> dq;

//     // Insertion operations
//     dq.push_back(10);  // Add 10 to the back
//     dq.push_front(20); // Add 20 to the front
//     dq.push_back(30);  // Add 30 to the back

//     // Display elements
//     cout << "Deque elements: ";
//     for (int num : dq) {
//         cout << num << " ";
//     }
//     cout << endl;

//     // Access operations
//     cout << "Front element: " << dq.front() << endl;
//     cout << "Back element: " << dq.back() << endl;
//     cout << "Element at index 1: " << dq[1] << endl;

//     // Deletion operations
//     dq.pop_front(); // Remove front element
//     dq.pop_back();  // Remove back element

//     // Display elements after deletion
//     cout << "Deque after pop operations: ";
//     for (int num : dq) {
//         cout << num << " ";
//     }
//     cout << endl;

//     // Check size and emptiness
//     cout << "Deque size: " << dq.size() << endl;
//     cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl;

//     // Clear the deque
//     dq.clear();
//     cout << "Deque cleared. Is empty? " << (dq.empty() ? "Yes" : "No") << endl;

//     return 0;
// }

