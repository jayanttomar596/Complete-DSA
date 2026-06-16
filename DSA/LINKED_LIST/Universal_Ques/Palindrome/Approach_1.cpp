// Create an array
// Copy LL content into array
// Write logic to check palindrome or not 

// T.C. :- O(n)
// S.C. :- O(n)



#include <iostream>
#include <vector>
using namespace std;


class Node {

public:
    int data ;
    Node* next ;

    // Constructor
    Node(int data)
    {
        this -> data = data ;
        this -> next = NULL ;
    }

    // Destructor
    ~Node() {
        int value = this -> data ;
        // memory free
        if(this -> next != NULL)
        {
            delete next ;
            this->next = NULL ;
        }
        cout<<"Memory is free for node with data "<<value << endl;
    }
};


void InsertAtTail(Node* &tail , int d)
{
    // new node create
    Node* temp = new Node(d);

    if (tail == NULL) { // If the list is empty
        // head = temp;
        tail = temp;
        return;
    }
    // Single List me agar list NULL hai toh InsertToHead me koi problem nahi aye sirf InsertToTail me ayegi 

    tail -> next = temp ;
    tail = tail -> next ; 
}


void print(Node* &head)
{
    Node* temp = head ;

    while (temp != NULL)
    {
        cout << temp -> data <<" ";
        temp = temp -> next ;
    } 
    cout << endl ;
}


class Solution{
private:
    bool checkPalindrome(vector<int> arr)
    {

        int n = arr.size();
        int s = 0 ;
        int e = n-1 ;

        while(s <= e)
        {

            if (arr[s] != arr[e])
            {
                return 0 ;
            }

            s++;
            e--;
        }

        return 1 ;
    }

public :
    // Function to check whether the list is palindrome
    bool isPalindrome(Node* head)
    {
        if (head == NULL || head -> next == NULL)
        {
            return true ;
        }

        vector<int> arr ;

        Node* temp = head ;
        while(temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp -> next ;
        }

        return checkPalindrome(arr);
    }
         
};



int main() {
    
    
    Node* node1 = new Node(1);
    


    
    Node* head = node1 ;
    
    Node* tail = node1 ;


    InsertAtTail(tail , 0);

    InsertAtTail(tail , 1);

    InsertAtTail(tail , 2);

    InsertAtTail(tail , 1);

    InsertAtTail(tail , 0);

    InsertAtTail(tail , 1);

    cout<<"\nLinked List :"<<endl;
    print(head);
    cout<<endl;

    Solution sol ;

    bool result = sol.isPalindrome(head);

    if (result)
    {
        cout<<"Linked List is Palindrome"<<endl;
    }
    else
    {
        cout<<"Linked List is not Palindrome"<<endl;
    }

    return 0;
}





