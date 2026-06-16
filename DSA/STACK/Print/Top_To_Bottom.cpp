// RECURSIVE APPROACH


// #include <iostream>
// #include <stack>
// using namespace std;


// void PrintStack(stack<int> s)
// {
//     // If stack is empty
//     if (s.empty()) 
//         return ;
    
// // Extract top of the stack
//     int x = s.top() ;
    
//     // Pop the element
//     s.pop() ;


//     // Print the current top of the stack i.e. x
//     cout << x << " ";


//     // Proceed to print remaining stack
//     PrintStack(s) ;

//     // Push the element back 
//     s.push(x) ;
// }



// int main() {

//     stack<int> st ;

//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     st.push(5);

//     PrintStack(st);
//     cout << endl;
    
//     return 0;
// }








// APPROACH 2

#include <iostream>
#include <stack>
using namespace std;


void PrintStack(stack<int> st)
{
    cout<<endl;

    while(st.empty() == false)
    {
        int t = st.top();
        cout << t << " ";
        st.pop();
    }
    cout<<endl<<endl;
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


