// Implement a phone directory



/*

You are given a list/array of strings which denotes the contacts that exist in your phone directory. The search query on a string ‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix as ‘str’. One special property of the search function is that when a user searches for a contact from the contact list then suggestions (contacts with prefix as the string entered so for) are shown after the user enters each character.

Note :
If no suggestions are found, return an empty 2D array.

*/





#include <iostream>
#include <vector>
using namespace std;






class TrieNode
{
public :
    char data ;
    TrieNode* children[26] ;
    bool isTerminal ;
    
    TrieNode(char ch)
    {
        data = ch ;
        for (int i = 0 ; i < 26 ; i++)
        {
            children[i] = NULL ;
        }
        isTerminal = false ;
    }
};




class Trie {

public :
    TrieNode* root ;

    Trie()
    {
        root = new TrieNode('\0') ;
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
            root -> children[index] = child ;
        }

        // RECURSION
        insertUtil(child , word.substr(1)) ;
    }

    void insertWord(string word)
    {
        insertUtil(root , word);
    }




    void printSuggestions(TrieNode* curr , vector<string> &temp , string prefix)
    {
        if (curr -> isTerminal)
        {
            temp.push_back(prefix) ;
        }

        for (char ch ='a' ; ch <= 'z' ; ch++)
        {
            TrieNode* next = curr -> children[ch - 'a'] ;

            if (next != NULL)
            {
                prefix.push_back(ch) ;
                printSuggestions(next , temp , prefix) ;
                prefix.pop_back() ;
            }
        }
    }



    vector<vector<string>> getSuggestion(string str)
    {
        TrieNode* prev = root ;
        vector<vector<string>> output ;
        string prefix = "" ;

        for (int i = 0 ; i < str.length() ; i++)
        {
            char lastch = str[i] ;

            prefix.push_back(lastch) ;

            // check for lastch
            TrieNode* curr = prev -> children[lastch - 'a'] ;

            
            // if not found 
            if (curr == NULL) {
            // No further suggestions can be found
                output.push_back({"0"});
                break; // rest of the queryStr won't have valid suggestions
            }


            // if found
            vector<string> temp ;
            printSuggestions(curr , temp , prefix) ;

            output.push_back(temp) ;
            temp.clear() ;
            prev = curr ;
        }

        return output ;
    }


};








vector<vector<string>> phoneDirectory(vector<string> &contactList , string &queryStr)
{
    // Creation of trie
    Trie *t = new Trie() ;


    // Insert all contacts in trie 
    for (int i = 0 ; i < contactList.size() ; i++)
    {
        string str = contactList[i] ;
        t->insertWord(str) ;
    }


    // Return Ans 
    return t->getSuggestion(queryStr) ;
}





void print_vector(vector<string> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}




void print_2d_vector(vector<vector<string>> v)
{
    for (const auto& row : v)
    {
        for (const auto& val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}




int main() {

    // Assumed all characters are small
    
    vector<string> contactList = {"cod" , "coding" , "codding" , "code" , "coly"} ;

    cout << "\nString Vector : " << endl;
    print_vector(contactList) ;


    string str ;
    cout << "\nEnter String to find suggestions : ";
    cin >> str ;


    vector<vector<string>> suggestion = phoneDirectory(contactList , str) ;
    print_2d_vector(suggestion) ;
    
    return 0;
}





