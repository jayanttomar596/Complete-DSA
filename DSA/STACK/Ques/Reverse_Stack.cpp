#include <iostream>
#include <stack>
using namespace std;


void insertAtBottom(stack<int> &stack , int element)
{
    // BaseCase
    if (stack.empty())
    {
        stack.push(element);
        return ;
    }

    int num = stack.top() ;
    stack.pop() ;

    // Recursive Call
    insertAtBottom(stack,element);

    stack.push(num);
}


void reverseStack(stack<int> &stack)
{
    // Base Case
    if (stack.empty())
        return ;
    
    int num = stack.top() ;
    stack.pop() ;
    
    // Recursive Call
    reverseStack(stack);
    
    insertAtBottom(stack , num) ;
}


void PrintStack(stack<int> s)
{
    stack<int> temp ;
    while(s.empty() == false)
    {
        temp.push(s.top());
        s.pop();
    }


    while (temp.empty() == false)
    {
        int t = temp.top();
        cout << t << " ";
        temp.pop();

        // To restore contents of the original stack
        s.push(t) ;
    }
    cout<<endl;

}



int main() {

    stack<int> st ;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "\nOriginal Stack : [Bottom To Top] "<<endl;
    PrintStack(st);
    cout << endl;

    reverseStack(st) ;


    cout << "\nReversed Stack : [Bottom To Top] "<<endl;
    PrintStack(st) ;
    cout << endl ;
    
    return 0;
}