#include <iostream>
#include <stack>
using namespace std;

int main() {

    // creation of stack
    stack<int> s ;

    // Push Operation
    s.push(2);
    s.push(3);

    // Pop
    s.pop();

    cout << "Printing top element : "<<s.top()<<endl;

    if (s.empty())
    {
        cout<<"Stack is Empty"<<endl;
    }
    else
    {
        cout << "Stack is Not Empty"<<endl;
    }

    cout << "Size of stack is = " << s.size() << endl;
    
    return 0;
}




