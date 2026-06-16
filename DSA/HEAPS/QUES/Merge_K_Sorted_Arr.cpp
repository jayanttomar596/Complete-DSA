// K-th Largest Sum Subarray



/*

Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the array.

*/




#include <iostream>
#include <queue>
using namespace std;


class node 
{
    public :
        int data ;
        int i ;
        int j ;
    
    node(int data , int row , int col)
    {
        this -> data = data ;
        i = row ;
        j = col ;
    }
};



class compare
{
public :
    bool operator()(node* a , node* b)
    {
        return a->data > b->data ;
    }
};



vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays , int k)
{
    priority_queue<node* , vector<node*> , compare > minHeap ;


    // Step1 : Saare arrays ke first element insert karo
    for (int i = 0 ; i < k ; i++)
    {
        node* tmp = new node(kArrays[i][0] , i , 0) ;
        minHeap.push(tmp) ;
    }


    vector<int> ans ;


    // Step2 :
    while(minHeap.size() > 0)
    {
        node* tmp = minHeap.top() ;

        ans.push_back(tmp -> data) ;
        minHeap.pop() ;

        int i = tmp -> i ;
        int j = tmp -> j ;

        if (j+1 < kArrays[i].size())
        {
            node* next = new node(kArrays[i][j+1] , i , j+1) ;
            minHeap.push(next) ;
        }
    }

    return ans ;
}


void print_2d_vector(vector<vector<int>> v)
{
    for (const auto& i : v)
    {
        for (const auto& j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}



void print_vector(vector<int> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}




int main() {

    vector<vector<int>> v = {{1,2,3} ,{4,5,6} , {7,8,9} , {51,70,90} , {35,60,80}} ;

    vector<int> v2 = mergeKSortedArrays(v,5) ;

    cout << "\n5 Vectors are : "<< endl;
    print_2d_vector(v) ;

    cout << "\nSorted Array : ";
    print_vector(v2);
    
    return 0;
}


