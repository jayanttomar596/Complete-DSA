// RECURSION

/*

The idea is to pop the element of the stack and call the recursive function PrintStack. Once the stack becomes empty start printing the element which was popped last and the last element that was popped was the bottom-most element. Thus, elements will be printed from bottom to top. Now push back the element that was printed, this will preserve the order of the elements in the stack.

*/



// #include <iostream>
// #include <stack>
// using namespace std;


// void PrintStack(stack<int> s)
// {
//     // If stack is empty then return 
//     if (s.empty())
//         return ;
    
//     int x = s.top() ;

//     // Pop the top element of the stack
//     s.pop() ;

//     // Recursively call the function PrintStack
//     PrintStack(s) ;

//     // Print the stack element starting from the bottom
//     cout << x << " ";

//     // Push the same element onto the stack to preserve the order
//     s.push(x);
// }



// int main() {
//     stack<int> st ;
    
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     st.push(5);

//     cout<<endl;
//     PrintStack(st);
//     cout<<endl<<endl;

//     return 0;
// }








// USING ANOTHER STACK

/*

The idea is to push every element into another temporary stack and then print elements of the temporary stack. 

*/



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



int main() {

    stack<int> st ;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    PrintStack(st);
    
    return 0;
}



