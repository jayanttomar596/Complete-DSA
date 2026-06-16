#include <iostream>
#include <stack>
using namespace std;


int main() {

    string str = "Jayant" ;

    cout<<"\nOriginal String : " << str << endl;

    stack<char> s ;

    for (int i = 0 ; i < str.length() ; i++)
    {
        char ch = str[i] ;
        s.push(ch) ;
    }

    string ans = "" ;

    while(!s.empty())
    {
        char ch = s.top() ;
        ans.push_back(ch) ;

        s.pop() ;
    }

    cout << "\nReversed String = " << ans << endl << endl;


    return 0;
}


// TIME COMPEXITY : O(n)
// SPACE COMPELXITY : O(n)



