// PERMUTATIONS OF A STRING

/*

// You are given a string 'STR' consisting of lowercase English letters . Your task is to return all permutations of the given string in lexicographically increasing order . Lexicographical order is a generalization of dictionary order to any type of sequence. For textual data, they are the same.

// If the string is "bca" , then its permuataions in lexicographically increasing order are {"abc" , "acb" , "bac" , "bca" , "cab" , "cba"}

*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
private :
    void solve(string str , vector<string> &ans , int index)
    {
        // Base Case
        if (index >= str.size())
        {
            ans.push_back(str);
            return ;
        }

        for (int j = index ; j<str.size() ; j++)
        {
            swap(str[index],str[j]);
            solve(str,ans,index+1);
            // backtrack
            swap(str[index] , str[j]);
        }
    }

public:
    vector<string> permute(string str) {
        vector<string> ans ;

        sort(str.begin() , str.end());

        int index = 0 ;
        solve(str , ans , index);

        sort(ans.begin() , ans.end());

        return ans ;
    }
};


void Print_Vector(vector<string> v)
{
    int size = v.size() ;
    for (int i = 0 ; i < size ; i++)
    {
        cout<<v[i]<<endl;
    }
}



int main() {

    Solution sol ;
    string str ;
    cout<<"Enter the string to find permutations : ";
    cin>>str;

    vector<string> permutations = sol.permute(str);

    cout<<"Permutations of string : "<<endl;
    Print_Vector(permutations);

    return 0;
}



