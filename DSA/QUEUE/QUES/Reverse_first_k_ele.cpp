// Reverse First K elements of Queue


/*PROBLEM STATEMENT

Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.




Example 1:

Input:
5 3
1 2 3 4 5
Output: 
3 2 1 4 5
Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.

*/




#include <iostream>
#include <queue>
#include <stack>
using namespace std;


// Function to reverse first k elements of a queue.
void modifyQueue(queue<int> &q, int k) {
    // Step 1 : Pop first k from Q and put into stack
    stack <int> s ;
    
    for (int i = 0 ; i < k ; i++)
    {
        int val = q.front() ;
        q.pop() ;
        s.push(val) ;
    }
    
    // Step 2 : Fetch from stack and push into q
    while(!s.empty())
    {
        int val = s.top() ;
        s.pop() ;
        q.push(val) ;
    }
    
    // Step 3 : Fetch first (n-k) element from Q and push back
    int t = q.size() - k ;
    
    while(t--)
    {
        int val = q.front() ;
        q.pop() ;
        q.push(val) ;
    }
    
}


void printQueue(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop() ;
    }
    cout << endl;
}



int main() {

    queue<int> q ;
    int k ;

    q.push(1) ;
    q.push(2) ;
    q.push(3) ;
    q.push(4) ;
    q.push(5) ;

    cout << "Given Queue : "<<endl;
    printQueue(q);


    cout << "Enter the value of k = ";
    cin>>k ;

    modifyQueue(q,k) ;

    cout << "\nQueue after the reversing first" << k << "elements : "<<endl;
    printQueue(q);
    
    return 0;
}
