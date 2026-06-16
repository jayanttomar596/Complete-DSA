
// In C++, a set is part of the Standard Template Library (STL) and represents a collection of unique elements, sorted in ascending order by default. It is implemented as a self-balancing binary search tree, typically a Red-Black Tree. This structure ensures logarithmic time complexity for operations like insertion, deletion, and lookup.--- element dalne ke baad modify nahi hota 


#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);

    for (auto i : s)
    {
        cout<<i<<endl;
    }

    // s.erase(s.begin());
    // delete first element that is 0

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);
    // this iterator erase 2nd element that is 1
    
    for (auto i : s)
    {
        cout<<i<<endl;
    }
    cout<<endl;

    cout<<"5 is present or not : "<<s.count(5)<<endl;

    set<int>::iterator itr = s.find(5);

    for (auto it = itr ; it!=s.end() ; it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    // 5 ke aage ka sab print ho jayega
    

    return 0;
}










// CHATGPT CODES

// #include <iostream>
// #include <set>

// int main() {
//     // Declare a set of integers
//     std::set<int> mySet;

//     // Insert elements into the set
//     mySet.insert(10);
//     mySet.insert(20);
//     mySet.insert(30);
//     mySet.insert(20); // Duplicate element; ignored

//     // Display elements of the set
//     std::cout << "Elements in the set: ";
//     for (int elem : mySet) {
//         std::cout << elem << " ";
//     }
//     std::cout << "\n";

//     // Check size of the set
//     std::cout << "Size of the set: " << mySet.size() << "\n";

//     // Find an element in the set
//     int key = 20;
//     if (mySet.find(key) != mySet.end()) {
//         std::cout << key << " is found in the set.\n";
//     } else {
//         std::cout << key << " is not found in the set.\n";
//     }

//     // Remove an element from the set
//     mySet.erase(10);
//     std::cout << "After erasing 10, elements in the set: ";
//     for (int elem : mySet) {
//         std::cout << elem << " ";
//     }
//     std::cout << "\n";

//     // Check if the set is empty
//     if (mySet.empty()) {
//         std::cout << "The set is empty.\n";
//     } else {
//         std::cout << "The set is not empty.\n";
//     }

//     // Clear all elements in the set
//     mySet.clear();
//     std::cout << "After clearing, size of the set: " << mySet.size() << "\n";

//     // Using lower_bound and upper_bound
//     mySet.insert(15);
//     mySet.insert(25);
//     mySet.insert(35);
//     std::cout << "Elements in the set: ";
//     for (int elem : mySet) {
//         std::cout << elem << " ";
//     }
//     std::cout << "\n";

//     auto lower = mySet.lower_bound(20); // First element >= 20
//     auto upper = mySet.upper_bound(20); // First element > 20

//     if (lower != mySet.end()) {
//         std::cout << "Lower bound of 20: " << *lower << "\n";
//     } else {
//         std::cout << "Lower bound of 20 does not exist.\n";
//     }

//     if (upper != mySet.end()) {
//         std::cout << "Upper bound of 20: " << *upper << "\n";
//     } else {
//         std::cout << "Upper bound of 20 does not exist.\n";
//     }

//     return 0;
// }
