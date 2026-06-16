// Huffman Encoding





/*

Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

*/







#include <iostream>
#include <vector>
#include <queue>
using namespace std;









// | Part                 | Time Complexity | Space Complexity                     |
// | -------------------- | --------------- | ------------------------------------ |
// | Priority Queue Build | `O(N log N)`    | `O(N)`                               |
// | Tree Construction    | `O(N log N)`    | `O(N)`                               |
// | Tree Traversal       | `O(N)`          | `O(N^2)` (for storing codes)         |
// | **Total**            | `O(N log N)`    |  O(N^2)    (due to result storage)   |






class Node
{
public :
    int data ;
    Node* left ;
    Node* right ;
    
    Node(int d)
    {
        data = d ;
        left = NULL ;
        right = NULL ;
    }
};


class cmp 
{
public :
    bool operator()(Node* a , Node* b)
    {
        return a->data > b->data ;
    }
} ;



class Solution {
    void traverse(Node* root , vector<string>& ans , string temp)
    {
        // Base Case
        if (root -> left == NULL && root -> right == NULL)
        {
            ans.push_back(temp) ;
            return ;
        }
        
        traverse(root->left , ans , temp + '0') ;
        traverse(root->right , ans , temp + '1') ;
    }
    
    
  public:
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        
        priority_queue<Node* , vector<Node*> , cmp> pq ;
        
        for (int i = 0 ; i < N ; i++)
        {
            Node* temp = new Node(f[i]) ;
            pq.push(temp) ;
        }
        
        while(pq.size() > 1)
        {
            Node* left = pq.top() ;
            pq.pop() ;
            
            Node* right = pq.top() ;
            pq.pop() ;
            
            Node* newNode = new Node(left->data + right->data) ;
            newNode -> left = left ;
            newNode -> right = right ;
            pq.push(newNode) ;
        }
        
        Node* root = pq.top() ;
        vector<string> ans ;
        string temp = "" ;
        traverse(root , ans , temp) ;
        return ans ;
        
    }
};









int main() {

    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = S.length();

    Solution obj;
    vector<string> codes = obj.huffmanCodes(S, f, N);

    cout << "Character : Huffman Code\n";
    for (int i = 0; i < N; i++) {
        cout << S[i] << " : " << codes[i] << "\n";
    }
    
    return 0;
}


