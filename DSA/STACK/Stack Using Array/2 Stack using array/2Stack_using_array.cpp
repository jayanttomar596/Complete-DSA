// TWO STACK IMPLEMENTATION USING ARRAY

/*

Following functions must be supported by twoStacks.


push1(int x) –> pushes x to first stack 
push2(int x) –> pushes x to second stack
pop1() –> pops an element from first stack and return the popped element 
pop2() –> pops an element from second stack and return the popped element

Implementation of twoStack should be space efficient

*/




// #include <iostream>
// using namespace std;


// class twoStacks {
//     int* arr ;
//     int size ;
//     int top1 , top2 ;

// public :
//     // Constructor
//     twoStacks(int n)
//     {
//         size = n ;
//         arr = new int[n];
//         top1 = n/2 + 1 ;
//         top2 = n/2 ;
//     } 


//     // Method to push an element x to stack1
//     void push1(int x)
//     {
//         // There is at least one empty space for new element 
//         if (top1 > 0)
//         {
//             top1-- ;
//             arr[top1] = x ;
//         }
//         else
//         {
//             cout<<"Stack Overflow By Element : "<<x<<endl;
//             return ;
//         }
//     }

//     // Method to push an element x to stack2 
//     void push2(int x)
//     {

//         // There is at least  one empty space for new element
//         if (top2 < size - 1)
//         {
//             top2++ ;
//             arr[top2] = x ;
//         }
//         else
//         {
//             cout << "Stack Overflow By Element : "<<x<<endl;
//             return ;
//         }
//     }

//     // Method to pop an element from first stack
//     int pop1()
//     {
//         if (top1 <= size / 2)
//         {
//             int x = arr[top1];
//             top1++ ;
//             return x ;
//         }
//         else
//         {
//             cout<<"Stack Unerflow";
//             exit(1);
//         }
//     }


//     // Method to pop an element from second stack
//     int pop2()
//     {
//         if (top2 >= size/2 +1)
//         {
//             int x = arr[top2];
//             top2--;
//             return x ;
//         }
//         else
//         {
//             cout<<"Stack Underflow"<<endl;
//             exit(1);
//         }
//     }

// };



// int main() {

//     twoStacks ts(5);
//     ts.push1(5);
//     ts.push2(10);
//     ts.push2(15);
//     ts.push1(11); 
//     ts.push2(7); 
//     cout << "Popped element from stack1 is : " << ts.pop1() << endl; 

//     ts.push2(40); 

//     cout << "Popped element from stack2 is : " << ts.pop2() << endl; 
    
//     return 0;
// }








// PROBLEM IN THE ABOVE IMPLEMENTATION

/*

The problem in the above implementation is that as we reserve half of the array for a stack and another half for the another stack. So, let if 1st half is full means first stack already have n/2 numbers of elements and 2nd half is not full means it doesn’t have n/2 numbers of elements. So, if we look into the array, there are free spaces inside array(eg. in the next half) but we cannot push elements for stack 1(because first half is reserved for stack 1 and it’s already full). It means this implementation show stack overflow although the array is not full. The solution for this answer is the below implementation.

*/



// IMPLEMENT TWO STACKS IN AN ARRAY BY STARTING FROM ENDPOINTS :

/*

The idea is to start two stacks from two extreme corners of arr[]. 


Follow the steps below to solve the problem:

Stack1 starts from the leftmost corner of the array, the first element in stack1 is pushed at index 0 of the array. 
Stack2 starts from the rightmost corner of the array, the first element in stack2 is pushed at index (n-1) of the array. 
Both stacks grow (or shrink) in opposite directions. 
To check for overflow, all we need to check is for availability of space between top elements of both stacks.
To check for underflow, all we need to check is if the value of the top of the both stacks  is between 0 to (n-1) or not.

*/




#include <iostream>
using namespace std;


class twoStacks {
    int* arr ;
    int size ;
    int top1 , top2 ;

public:
    twoStacks(int n) // Contructor
    {
        size = n ; 
        arr = new int[n] ;
        top1 = -1 ;
        top2 = size ;
    }


    // Method to push an element x to stack1
    void push1(int x)
    {
        // There is at least one empty space for new element 
        if (top1 < top2 -1)
        {
            top1++;
            arr[top1] = x ;
        }
        else
        {
            cout<<"Stack Overflow"<<endl;
            exit(1);
        }
    }


    // Method to push an element x to stack2
    void push2(int x)
    {
        // There is at least one empty space for new element
        if (top1 < top2 - 1)
        {
            top2-- ;
            arr[top2] = x ;
        }
        else
        {
            cout<<"Stack Overflow"<<endl;
            exit(1);
        }
    }


    // Method to pop an element from first stack
    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1] ;
            top1-- ;
            return x ;
        }
        else
        {
            cout<<"Stack Underflow"<<endl;
            exit(1);
        }
    }


    // Method to pop an element from second stack
    int pop2()
    {
        if (top2 < size)
        {
            int x = arr[top2] ;
            top2++ ;
            return x ;
        }
        else
        {
            cout<<"Stack Underflow"<<endl;
            exit(1);
        }
    }
};



int main() {

    twoStacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "\nPopped element from stack1 is " << ts.pop1()<<endl; 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is " << ts.pop2()<<endl; 
    
    return 0;
}




