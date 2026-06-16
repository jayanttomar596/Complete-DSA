// Interleave the first half of the queue with second half

/*

Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.  



Examples:

Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20

*/



// USING QUEUE

/*

We can also solve the given problem by using a queue instead of a stack. The idea is to move the first half to another queue, and then push values from the temporary queue and original queue into the original queue. The original queue will get converted to the interleaved queue after the operations.


Steps to solve : 

Make a temporary queue and push the first half of the original queue into the temp queue.

Till the temp queue is empty
Pop the front of the temp queue and push it to the original queue
Pop the front of the original queue and push it to the original queue

The original queue is converted to the interleaved queue.

*/





#include <iostream>
#include <queue>
using namespace std;


void interLeaveQueue(queue<int> &q)
{
    // To check the even number of elements
    if (q.size() % 2 != 0)
        cout << "Input even number of integers ." << endl;
    

    // Initialize an empty of int type
    queue<int> temp ;
    int halfSize = q.size() / 2 ;

    // Push first half elements into the stack
    // Queue : 16 17 18 19 10 , Queue : 11 12 13 14 15
    for (int i = 0 ; i < halfSize ; i++)
    {
        temp.push(q.front());
        q.pop();
    }

    // enqueue back the queue elements alternatively
    // queue : 11 16 12 17 13 18 14 19 15 20
    while(!temp.empty())
    {
        q.push(temp.front()) ;
        q.push(q.front()) ;
        q.pop() ;
        temp.pop() ;
    }
}


void print_queue(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop() ;
    }
    cout << endl;
}



int main() {

    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    cout << "\nOriginal Queue : "<<endl;
    print_queue(q);

    interLeaveQueue(q);

    cout << "\nModified Queue : "<<endl;
    print_queue(q);
    cout << endl;
    
    return 0;
}




