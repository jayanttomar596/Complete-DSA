// USING STACK

// T.C. : O(n)
// S.C. : O(n)





#include <iostream>
#include <queue>
#include <stack>
using namespace std;


void reverseQueue(queue<int> &q) {
    stack<int> s ;
    
    while (!q.empty())
    {
        int element = q.front() ;
        q.pop() ;
        s.push(element) ;
    }
    
    while(! s.empty())
    {
        int element = s.top() ;
        s.pop() ;
        q.push(element) ;
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
    q.push(4) ;
    q.push(3) ;
    q.push(1) ;
    q.push(10) ;
    q.push(2) ;
    q.push(6) ;

    cout << "\nOriginal Queue : "<<endl;
    printQueue(q);
    cout << endl;

    reverseQueue(q) ;

    cout << "\nReversed Queue : "<<endl;
    printQueue(q);
    cout << endl;
    
    return 0;
}




