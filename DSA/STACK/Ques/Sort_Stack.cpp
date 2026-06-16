#include <iostream>
#include <stack>
using namespace std;


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


void sortedInsert(stack<int> &stack , int num)
{
    // Base Case
    if (stack.empty() || (!stack.empty() && stack.top() < num) )
    {
        stack.push(num) ;
        return ;
    }

    int n = stack.top() ;
    stack.pop() ;

    // Recursive Call
    sortedInsert(stack , num);

    stack.push(n);
}


void sortStack(stack<int> &stack)
{
    // Base Case
    if (stack.empty())
    {
        return ;
    }

    int num = stack.top() ;
    stack.pop();

    // Recursive Call
    sortStack(stack);

    sortedInsert(stack , num);
}



int main() {

    stack<int> st ;
    st.push(4);
    st.push(2);
    st.push(5);
    st.push(3);
    st.push(1);

    cout << "\nOriginal Stack : "<<endl;
    PrintStack(st);
    cout<<endl<<endl;

    sortStack(st);

    cout << "\nSorted Stack : "<<endl;
    PrintStack(st);
    cout<<endl<<endl;
    
    return 0;
}