//  Longest Common Prefix



/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/






#include <iostream>
#include <vector>
using namespace std;


// N = number of strings in the vector strs
// M = length of the shortest string in strs




class Solution {
    public:

        // T.C. -> O(N*M)
        // S.C. -> O(1)
        string longestCommonPrefix(vector<string>& strs) {
            string ans = "" ;
    
            // For traversing all characters of first string
            for (int i = 0 ; i < strs[0].length() ; i++)
            {
                char ch = strs[0][i] ;
    
                bool match = true ;
    
                // For comparing ch with rest of the strings
                for (int j = 1 ; j < strs.size() ; j++)
                {
                    // Not Match
                    if (strs[j].size() < i || ch != strs[j][i])
                    {
                        match = false ;
                        break ;
                    }
                }
    
                if (match == false)
                    break ;
                else
                    ans.push_back(ch) ;    
            }
    
            return ans ;
        }
};








// Solution using Trie 


// T.C. -> O(M*N)
// S.C. -> O(M*N)

class TrieNode{
    public:
        char data ;
        TrieNode* children[26] ;
        int childCount ;
        bool isTerminal ;
    
        TrieNode(char ch)
        {
            data = ch ;
            for (int i = 0 ; i < 26 ; i++)
            {
                children[i] = NULL ;
            }
            childCount = 0 ;
            isTerminal = false ;
        } 
    };
    
    
    class Trie {
    public :
        TrieNode* root ;
    
        Trie(char ch)
        {
            root = new TrieNode(ch) ;
        }
    
    
        void insertUtil(TrieNode* root , string word)
        {
            // Base Case
            if (word.length() == 0)
            {
                root -> isTerminal = true ;
                return ;
            }
    
            // Assumption , word will be in CAPS
            int index = word[0] - 'a' ;
            TrieNode* child ;
    
            // present
            if (root -> children[index] != NULL)
            {
                child = root -> children[index] ;
            }
            else{
                // absent
                child = new TrieNode(word[0]) ;
                root->childCount++ ;
                root -> children[index] = child ;
            }
    
            // RECURSION
            insertUtil(child , word.substr(1)) ;
        }
    
        void insertWord(string word)
        {
            insertUtil(root , word);
        }
    
        void lcp(string str , string &ans)
        {
    
            for (int i = 0 ; i < str.length() ; i++)
            {
                char ch = str[i] ;
    
                if (root -> childCount == 1)
                {
                    ans.push_back(ch) ;
                    // Aage Badhjao
                    int index = ch - 'a' ;
                    root = root -> children[index] ;
                }
                else
                {
                    break ;
                }
    
                if (root -> isTerminal)
                    break ;
            }
        }
    };
    
    
    
    class Solution2 {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            Trie *t = new Trie('\0') ;
    
            string ans = "";
    
            // Insert kardo all strings into trie
            for (int i = 0 ; i < strs.size() ; i++)
            {
                if (strs[i] == "")
                {
                    return ans ;
                }
                t->insertWord(strs[i]) ;
            }
    
            string first = strs[0] ;
    
            t->lcp(first , ans) ;
    
            return ans ;
        }
};


    




int main() {

    vector<string> strs = {"flower","flow","flight"} ;
    

    cout << "\nVector Of Strings : " ;
    for (int i = 0 ; i < strs.size() ; i++)
    {
        cout << strs[i] << " ";
    }
    cout << endl;


    Solution sol1 ;
    cout << "\nLongest Common Prefix amoung these : " << sol1.longestCommonPrefix(strs) << endl << endl;

    Solution2 sol2 ;
    cout << "\nLongest Common Prefix amoung these : " << sol2.longestCommonPrefix(strs) << endl << endl;


    return 0;
}



