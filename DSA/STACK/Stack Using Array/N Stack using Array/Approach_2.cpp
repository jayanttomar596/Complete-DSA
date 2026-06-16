
/* N STACKS IN AN ARRAY

Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:

push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.

pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
Two types of queries denote these operations :

Type 1: for push(X, M) operation.
Type 2: for pop(M) operation.

*/



#include <iostream>
using namespace std;


class NStack
{
    int *arr ; 
    int *top ;
    int *next ;

    int n , s ;

    int freespot ;


public :
    // Initialize your data structure
    NStack(int N , int S)
    {
        n = N ;
        s = S ;
        arr = new int[s] ;
        top = new int[n] ;
        next = new int[s] ;

        // Top Initialize
        for (int i = 0 ; i < n ; i++)
        {
            top[i] = -1 ;
        }

        // Next Initialize
        for (int i = 0 ; i < s ; i++)
        {
            next[i] = i+1 ;
        }
        // Update last index value to -1
        next[s-1] = -1 ;

        // Initialize Freespot
        freespot = 0 ;

    }


    // Pushes 'X' into the Mth stack . Returns true if it gets pushed into stack , and false otherwise
    bool push(int x , int m)
    {
        // Check for Overflow
        if (freespot == -1)
        {
            return false ;
        }

        // find index
        int index = freespot ;

        // Update freespot
        freespot = next[index] ;

        // Insert element into array
        arr[index] = x ;

        // Update Next ;
        next[index] = top[m-1] ;

        // Update Top
        top[m-1] = index ;


        return true ;
    }


    // Pops top element from Mth Stack
    int pop(int m)
    {
        // Check underflow condition
        if (top[m-1] == -1)
        {
            return -1 ;
        }

        int index = top[m-1] ;

        top[m-1] = next[index] ;

        next[index] = freespot ;

        freespot = index ;


        return arr[index] ;
    }

};



int main() {

    NStack nst(3,6) ;

    cout << "\nPush 10 in stack 1 : "<<nst.push(10,1) <<endl;

    cout << "\nPush 20 in stack 1 : "<<nst.push(20,1) <<endl;

    cout << "\nPush 30 in stack 2 : "<<nst.push(30,2) <<endl;

    cout << "\nPop Element from stack 1 = " << nst.pop(1) <<endl ;

    cout << "\nPop Element from stack 2 = " << nst.pop(2) <<endl ;
    
    return 0;
}




