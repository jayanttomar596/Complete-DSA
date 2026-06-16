// Stream First Non - Reapeating

/*

Given an input stream s consisting only of lowercase alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

NOTE:
1. You need to find the answer for every i (0 <= i < n)
2. In order to find the solution for every you need to consider the string from starting position till the ith position.






Examples:

Input: s = "aabc"
Output: "a#bb"
Explanation: For every ith character we will consider the string from index 0 till index i first non repeating character is as follow- "a" - first non-repeating character is 'a' "aa" - no non-repeating character so '#' "aab" - first non-repeating character is 'b' "aabc" - there are two non repeating characters 'b' and 'c',  first non-repeating character is 'b' because 'b' comes before 'c' in the stream.


*/






#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;


string FirstNonRepeating(string &s) {

    unordered_map<char , int> count ;

    queue<int> q ;

    string ans = "";
    

    for (int i = 0 ; i < s.length() ; i++)
    {
        char ch = s[i] ;
        
        // Increase Count 
        count[ch]++ ;
        
        // Queue me push karo
        q.push(ch) ;
        
        while(!q.empty())
        {
            if(count[q.front()] > 1)
            {
                // Repeating Character
                q.pop() ;
            }
            else
            {
                // Non-Repeating Character Milgaya
                ans.push_back(q.front());
                break ;
            }
        }
        
        if (q.empty())
            ans.push_back('#');
    }
    
    return ans ;
}



int main() {

    string s = "aabc" ;

    cout << "\nString : " << s << endl << endl;

    string ans = FirstNonRepeating(s) ;

    cout << "Answer String : "<< ans << endl << endl;
    
    return 0;
}


