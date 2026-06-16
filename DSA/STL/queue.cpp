
// In C++, the Standard Template Library (STL) provides a queue container that operates in a FIFO (First In, First Out) manner.
// This means elements are added to the back of the queue and removed from the front, much like a line at a ticket counter.
// We cannot add element in front ony push ie at back but access from front - FIFO ORDER

// Queues are widely used in programming for scenarios where order matters, such as scheduling tasks, managing processes, and simulating real-world queues.---- DYNAMIC SIZE




// #include <iostream>
// #include <queue>
// using namespace std;

// int main() {
    
//     queue<string> q;

//     q.push("love");
//     q.push("Babbar");
//     q.push("Kumar");

//     cout<<"First Element "<<q.front()<<endl;

//     cout<<"Size before pop = "<<q.size()<<endl;
//     q.pop();// Jo pehle element dala tha vahi pop hoga 
//     cout<<"First Element "<<q.front()<<endl;

//     cout<<"Size after pop = "<<q.size()<<endl;
//     return 0;

// }






#include <iostream>
using namespace std;

class Queue {
private :
    int *arr ;
    int front ;
    int rear ;
    int capacity ;
    int size ;
public :
    // Constructor to initialize the queue 
    Queue(int capacity) {
        this->capacity = capacity ;
        arr = new int[capacity] ;
        front = 0 ;
        rear = -1 ;
        size = 0 ;
    } 

    // Destructor to free allocated memory
    ~Queue()  {
        delete[] arr ;
    }

    // Add an element to the queue

};

int main() {

    Queue q(5) ; 
    // Create a queue with capacity 5
    
    
    return 0;
}







// CHATGPT CODES

// #include <iostream>
// #include <queue> // Include the queue header

// int main() {
//     // Declare a queue of integers
//     std::queue<int> q;

//     // Push elements into the queue
//     q.push(10);
//     q.push(20);
//     q.push(30);

//     std::cout << "Queue size: " << q.size() << std::endl;
//     std::cout << "Front element: " << q.front() << std::endl;
//     std::cout << "Back element: " << q.back() << std::endl;

//     // Pop elements from the queue
//     std::cout << "Removing front element: " << q.front() << std::endl;
//     q.pop();

//     std::cout << "After pop, front element: " << q.front() << std::endl;

//     // Check if queue is empty
//     if (q.empty()) {
//         std::cout << "The queue is empty." << std::endl;
//     } else {
//         std::cout << "The queue is not empty." << std::endl;
//     }

//     // Display remaining elements
//     std::cout << "Remaining elements: ";
//     while (!q.empty()) {
//         std::cout << q.front() << " ";
//         q.pop();
//     }
//     std::cout << std::endl;

//     return 0;
// }
