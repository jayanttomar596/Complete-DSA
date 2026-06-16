// Delete Middle Element from stack

#include <iostream>
#include <stack>
using namespace std;


void solve(stack<int> &inputStack , int count , int size)
{
    // Base Case
    if(count == size/2)
    {
        inputStack.pop() ;
        return ;
    }

    int num = inputStack.top() ;
    inputStack.pop() ;

    // RECURSIVE CALL
    solve(inputStack , count+1 , size);

    inputStack.push(num);
}


void deleteMiddle(stack<int>&inputStack , int size)
{
    int count = 0 ;
    solve(inputStack , count , size) ;
}


void PrintStack(stack<int> s)
{
    // If stack is empty then return 
    if (s.empty())
        return ;
    
    int x = s.top() ;

    // Pop the top element of the stack
    s.pop() ;

    // Recursively call the function
    PrintStack(s) ;


    // Print the stack element starting from the bottom
    cout << x << " ";


    // Push the same element onto the stack to preserve the order
    s.push(x);

}


int main() {

    stack<int> st ;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"Stack before deleting middle element : "<<endl;
    PrintStack(st) ;
    cout<<endl;


    int size = st.size();

    deleteMiddle(st,size);


    cout<<"Stack after deleting middle element : "<<endl;
    PrintStack(st) ;
    cout<<endl;
    
    return 0;
}