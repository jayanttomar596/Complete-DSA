// MINIMUM COST TO MAKE STRING VALID

/*

Ninja has been a string 'STR' containing either '{' or '}' . 'STR' is called valid if all the brackets are balanced . Formally for each opening bracket , there must be a closing bracket right to it .

"{}{}" , "{{}}" , "{{}{}}" are valid strings while "}{}" , "{}}{{}" , "{{}}}{" are not valid strings .alignas


Ninja wants to make 'STR' valid by performing some operations on it . In one operation , he can convert '{' into '}' or vice versa , and cost of one such operation is 1 .

Your task is to help Ninja determine the minimum cost to make 'STR' valid .

*/




#include <iostream>
#include <stack>
using namespace std;


int findMinimumCost(string str)
{
    // Odd Condition
    if (str.length()%2 == 1)
    {
        return -1 ;
    }

    stack<char> s ;
    for (int i = 0 ; i < str.length() ; i++)
    {
        char ch = str[i] ;

        if (ch == '{')
            s.push(ch) ;
        else
        {
            // ch is closed brace
            if (!s.empty() && s.top() == '{')
            {
                s.pop() ;
            }
            else
            {
                s.push(ch) ;
            }
        }    
    }

    // Stack contains invalid expression
    int a = 0 , b = 0 ;
    while(!s.empty())
    {
        if (s.top() == '{')
        {
            b++ ;
        }
        else
        {
            a++ ;
        }

        s.pop() ;
    }

    int ans = (a+1)/2 + (b+1)/2 ;

    return ans ;
}



int main() {

    string str = "{}}{{}" ;

    cout << "String : "<<str<<endl<<endl;

    int ans = findMinimumCost(str) ;

    if (ans != -1)
    {
        cout << "Minimum Cost to make 'STR' valid = "<<ans << endl;
    }
    else
    {
        cout << "Can't be a Valid STR" <<endl;
    }
    
    return 0;
}
