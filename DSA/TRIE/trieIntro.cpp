#include <iostream>
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

private :
    


    // Helper function to check if node has any children
    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; ++i)
            if (node->children[i] != nullptr)
                return false;
        return true;
    }


    // Recursive helper for removing a word
    TrieNode* removeWord(TrieNode* node, const string& word, int depth) {
        if (!node) return nullptr;

        // If last character of the word
        if (depth == word.size()) {
            if (node->isTerminal)
                node->isTerminal = false;

            // If node has no children, it can be deleted
            if (isEmpty(node)) {
                delete node;
                node = nullptr;
            }

            return node;
        }

        int index = word[depth] - 'A';
        node->children[index] = removeWord(node->children[index], word, depth + 1);

        // If current node has no children and is not end of another word
        if (isEmpty(node) && !node->isTerminal) {
            delete node;
            node = nullptr;
        }

        return node;
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
        int index = word[0] - 'A' ;
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




    bool searchUtil(TrieNode* root , string word)
    {
        // Base Case
        if (word.length() == 0)
        {
            return root->isTerminal ;
        }


        int index = word[0] - 'A' ;
        TrieNode* child ;


        // Present
        if (root -> children[index] != NULL)
        {
            child = root -> children[index] ;
        }
        else
        {
            // Absent
            return false ;
        }


        // Recursion
        return searchUtil(child , word.substr(1));
    }




    bool prefixUtil(TrieNode* root , string word)
    {
        // Base Case
        if (word.length() == 0)
        {
            return true ;
        }


        int index = word[0] - 'A' ;
        TrieNode* child ;


        // Present
        if (root -> children[index] != NULL)
        {
            child = root -> children[index] ;
        }
        else
        {
            // Absent
            return false ;
        }


        // Recursion
        return prefixUtil(child , word.substr(1));
    }




public :

    TrieNode* root;


    Trie()
    {
        root = new TrieNode('\0') ;
    }


    void insertWord(string word)
    {
        insertUtil(root , word);
    }



    bool search(string word)
    {
        return searchUtil(root , word) ;
    }


    bool startsWith(string word)
    {
        return prefixUtil(root , word) ;
    }


    void remove(const string& word) {
        root = removeWord(root, word, 0);
    }

};





int main() {

    Trie *t = new Trie() ; 

    t->insertWord("ARM") ;
    t->insertWord("DO") ;
    t->insertWord("TIME") ;

    cout << "\nPresent or Not : " << t->search("TIME") << endl;

    cout << "\nStarts with or Not : " << t->startsWith("TI") << endl;

    t->remove("TIME") ;

    cout << "\nPresent or Not : " << t->search("TIME") << endl;
    
    return 0;
}





