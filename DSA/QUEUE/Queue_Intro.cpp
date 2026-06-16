#include <iostream>
#include <queue>
using namespace std;

int main() {
    
    // create a queue
    queue<int> q ;

    q.push(11) ;
    cout << "Front of q is : " << q.front() << endl ;

    q.push(15) ;
    cout << "Front of q is : " << q.front() << endl ;

    q.push(13) ;
    cout << "Front of q is : " << q.front() << endl ;

    cout << "Size of Queue is : " << q.size() << endl;

    q.pop() ;

    cout << "Size of queue is : "<<q.size() << endl;

    if(q.empty())
    {
        cout << "Queue is Empty " << endl;
    }
    else
    {
        cout << "Queue is not Empty " << endl;
    }

    return 0;
}