
// A priority queue is a type of container in C++ STL that allows elements to be stored such that the largest or smallest element (based on priority) is always accessible at the top. Internally, it is implemented as a heap.

// Insertion and removal operations are O(logn)
// Accessing the top element is O(1)


#include <iostream>
#include <queue>
using namespace std;

int main() {
    //max heap
    priority_queue<int> maxi;

    // min heap
    priority_queue<int,vector<int> , greater<int> > mini ;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    cout<<"Size -> "<<maxi.size()<<endl;
    int n = maxi.size();
    for (int i = 0 ; i < n ; i++)
    {
        cout<<maxi.top()<<" ";
        maxi.pop();// remove top element that is largest walla
    }
    cout<<endl;

    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);

    int m = mini.size();
    for (int i = 0 ; i < m ; i++)
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;

    cout<<"Khaali hai kya bhai ?? "<<mini.empty()<<endl;

    return 0;
}









//CHATGPT CODES


//1. MAX HEAP (default behaviour)

// #include <iostream>
// #include <queue>
// using namespace std;

// int main() {
//     priority_queue<int> pq;

//     // Insert elements
//     pq.push(10);
//     pq.push(20);
//     pq.push(15);

//     // Display the top element
//     cout << "Top element: " << pq.top() << endl; // Output: 20

//     // Remove the top element
//     pq.pop();
//     cout << "Top element after pop: " << pq.top() << endl; // Output: 15

//     // Check size
//     cout << "Size: " << pq.size() << endl; // Output: 2

//     return 0;
// }


//2. MIN HEAP

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int main() {
//     // Min-heap using greater<int> as the comparator
//     priority_queue<int, vector<int>, greater<int>> minHeap;

//     // Insert elements
//     minHeap.push(10);
//     minHeap.push(20);
//     minHeap.push(15);

//     // Display the top element
//     cout << "Top element: " << minHeap.top() << endl; // Output: 10

//     // Remove the top element
//     minHeap.pop();
//     cout << "Top element after pop: " << minHeap.top() << endl; // Output: 15

//     return 0;
// }


//3. CUSTOM COMPARATOR

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// // Custom comparator: prioritize larger second elements
// struct CustomCompare {
//     bool operator()(pair<int, int> a, pair<int, int> b) {
//         return a.second < b.second; // Higher second value has higher priority
//     }
// };

// int main() {
//     // Priority queue with custom comparator
//     priority_queue<pair<int, int>, vector<pair<int, int>>, CustomCompare> pq;

//     // Insert elements
//     pq.push({1, 100});
//     pq.push({2, 300});
//     pq.push({3, 200});

//     // Display and remove top elements
//     while (!pq.empty()) {
//         cout << "Top element: (" << pq.top().first << ", " << pq.top().second << ")" << endl;
//         pq.pop();
//     }

//     return 0;
// }



