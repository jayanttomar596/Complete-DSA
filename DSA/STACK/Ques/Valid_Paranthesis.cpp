#include <iostream>
#include <stack>
using namespace std;

bool isValidParentheses(string expression)
{
    stack<char> s ;
    for (int i = 0 ; i < expression.length() ; i++)
    {

        char ch = expression[i] ;

        // if opening bracket , stack push and if close bracket , stacktop check and pop

        if (ch == '(' || ch == '{'  ||  ch == '[')
        {
            s.push(ch) ;
        }
        else
        {
            // for closing bracket
            if(!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false ;
                }
            }
            else
            {
                return false ;
            }
        }
    }


    if (s.empty())
        return true ;
    else
        return false ;    

}



int main() {

    string st = "({{[]}})";

    cout << "String : "<<st<<endl;

    if (isValidParentheses(st))
    {
        cout<<"\nIts a Valid Paranthesis\n"<<endl;
    }
    else
    {
        cout<<"\nIts not a Valid Paranthesis\n"<<endl;
    }

    return 0;
}



// TIME COMPLEXITY : O(n)
// SPACE COMPEXITY : O(n)