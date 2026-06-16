// LETTER COMBINATIONS OF A PHONE NUMBER

/*

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// 1-nothing , 2 - abc , 3 - def , 4 - ghi , 5 - jkl , 6 - mno , 7 - pqrs , 8 - tuv , 9 - wxyz

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:

// Input: digits = ""
// Output: []

// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]

*/



#include <iostream>
#include <vector>
using namespace std;

class Solution{

private: 
    void solve(string digit , string output , int index , vector<string> &ans , string mapping[])
    {
        // base case
        if (index >= digit.length())
        {
            ans.push_back(output);
            return ;
        }

        int number = digit[index] - '0';
        string value = mapping[number];

        for (int i = 0 ; i < value.length() ; i++)
        {
            output.push_back(value[i]);
            solve(digit , output , index+1 , ans , mapping);
            output.pop_back();
        }
    }

public :
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans ;
        if (digits.length() == 0)
            return ans ;

        string output = "";
        int index = 0 ;

        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits , output , index , ans , mapping);
        return ans ;    
    }

};


void Print_Array(vector<string> v)
{
    int size = v.size() ;
    cout<<"{";
    for (int i = 0 ; i < size ; i++)
    {
        cout<<"\""<<v[i]<<"\" ";
    }
    cout<<"}"<<endl;
}


int main() {
    Solution sol ;
    string digits ;

    cout<<"Enter a digit containing numbers form [2 to 9] = ";
    cin>>digits;

    vector<string> combinations = sol.letterCombinations(digits);

    Print_Array(combinations);

    return 0;
}





