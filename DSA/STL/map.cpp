
// The std::map in C++ STL (Standard Template Library) is an associative container that stores key-value pairs in a sorted order (based on the key). It is implemented as a self-balancing binary search tree (e.g., Red-Black Tree). The keys in a std::map are unique, meaning there cannot be duplicate keys.

// SORTED DATA - UNIQUE KEYS - LOGARITHMIC TIME COMPLEXITY - DYNAMIC SIZE


#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int,string> m ;

    m[1] = "babbar";
    m[2] = "love";
    m[13] = "kumar";

    // m.insert({5,"bheem"});
    m.insert(std::pair<int, std::string>(5, "bheem"));

    cout<<"Before Erase "<<endl;
    for (auto i : m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Finding - 13 -> "<<m.count(13)<<endl;

    m.erase(13);
    cout<<"After Erase"<<endl;
    for (auto i : m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }  
    cout<<endl;

    auto it = m.find(5);

    for (auto i=it ; i!=m.end() ; i++)
    {
        cout<<(*i).first<<endl;
    }  

    return 0;
}










// CHATGPT CODES

// #include <iostream>
// #include <map>

// int main() {
//     std::map<int, std::string> myMap;

//     // Insertion
//     myMap[1] = "One";
//     myMap[2] = "Two";
//     myMap.insert({3, "Three"});

//     // Accessing elements
//     std::cout << "Key: 1, Value: " << myMap[1] << std::endl;

//     // Iterating through the map
//     for (const auto& pair : myMap) {
//         std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
//     }

//     // Finding an element
//     auto it = myMap.find(2);
//     if (it != myMap.end()) {
//         std::cout << "Found key 2 with value: " << it->second << std::endl;
//     }

//     // Erasing an element
//     myMap.erase(2);

//     // Checking size
//     std::cout << "Map size: " << myMap.size() << std::endl;

//     return 0;
// }
