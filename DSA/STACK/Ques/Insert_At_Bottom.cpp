#include <iostream>
#include <stack>
using namespace std;


void PrintStack(stack<int> s)
{
    if (s.empty())
        return ;

    int x = s.top() ;
    
    s.pop();

    PrintStack(s) ;

    cout << x << " ";

    s.push(x);
}


void solve(stack<int>& s , int x)
{
    // Base Case
    if (s.empty())
    {
        s.push(x);
        return ;
    }

    int num = s.top();
    s.pop();

    // Recursive Call
    solve(s , x);

    s.push(num);
}


stack<int> pushAtBottom(stack<int>& myStack , int x)
{
    solve(myStack , x);
    return myStack ;
}



int main() {

    stack<int> st ;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"\nStack before adding element at bottom : "<<endl;
    PrintStack(st);
    cout<<endl<<endl;


    pushAtBottom(st ,1);
    cout<<"After Inserting element at bottom : "<<endl;
    PrintStack(st);
    cout << endl << endl;
    
    return 0;
}