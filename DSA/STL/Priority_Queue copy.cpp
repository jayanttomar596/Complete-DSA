#include <iostream>
#include <queue>
using namespace std;

int main() {

    cout << "\nUsing Priority Queue here" << endl;

    // MaxHeap
    priority_queue<int> pq ;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "\nElement at Top " << pq.top() << endl;
    pq.pop() ;
    cout << "\nElement at Top " << pq.top() << endl;
    cout << "Size is " << pq.size() << endl;

    if (pq.empty())
    {
        cout << "pq is empty " << endl;
    }
    else
    {
        cout << "pq is not empty " << endl;
    }


    // Min Heap
    priority_queue<int , vector<int> , greater<int> > minheap ;

    minheap.push(4) ;
    minheap.push(2) ;
    minheap.push(5) ;
    minheap.push(3) ;

    cout << "\nElement at Top " << minheap.top() << endl;
    minheap.pop() ;
    cout << "\nElement at Top " << minheap.top() << endl;
    cout << "Size is " << minheap.size() << endl;

    if (minheap.empty())
    {
        cout << "minheap is empty " << endl;
    }
    else
    {
        cout << "minheap is not empty " << endl;
    }
    
    return 0;
}



