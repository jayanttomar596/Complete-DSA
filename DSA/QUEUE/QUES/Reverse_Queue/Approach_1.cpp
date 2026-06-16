// USING ARRAY

// T.C. : O(n)
// S.C. : O(n)





#include <iostream>
#include <queue>
using namespace std;


void reverseQueue(queue<int> &q) {
    int size = q.size() ;
    int *arr = new int[size] ;
    int index = size - 1 ;
    
    while(q.empty() != 1)
    {
        int x = q.front() ;
        q.pop() ;
        arr[index] = x ;
        index-- ;
    }
    
    index = 0 ;
    
    while(q.size() != size)
    {
        q.push(arr[index]) ;
        index++ ;
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




