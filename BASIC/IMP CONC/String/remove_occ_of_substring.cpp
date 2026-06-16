
// Given two strings s and part , perform the following operation on s until all occurences of the substring part are removed :
// -- Find the leftmost occurence of the substring part and remove it from s .

// Return s after removing al occurrences of part .

// A substring is a contiguous sequence of characters in a string .



#include <iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while (s.length()!=0 && s.find(part) < s.length())
        {
            s.erase(s.find(part),part.length());
        }
        return s ;
    }
};

int main() {
    Solution sol ;
    string s ;
    s = "daabcbaabcbc";
    string part = "abc";

    cout<<"String after removing abc one by one : "<<sol.removeOccurrences(s,part)<<endl;
    return 0;
}



