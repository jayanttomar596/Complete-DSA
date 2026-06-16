/*

An array is called circular if we consider the first element as next of the last element. Circular arrays are used to implement queue (Refer to this and this).
An example problem : 
Suppose n people are sitting at a circular table with names A, B, C, D, … Given a name, we need to print all n people (in order) starting from the given name. 


For example, consider 6 people A B C D E F and given name as ‘D’. People sitting in a circular manner starting from D are D E F A B C.
A simple solution is to create an auxiliary array of size 2*n and store it in another array. For example for 6 people, we create below the auxiliary array. 
A B C D E F A B C D E F 
Now for any given index, we simply print n elements starting from it. For example, we print the following 6. 
A B C D E F A B C D E F 

*/



 
// ---------  array using extra memory space 



// #include <iostream> 
// using namespace std; 

// void print(char a[], int n, int ind) 
// { 
//     // Create an auxiliary array of twice size. 
//     char b[(2 * n)]; 
  
//     // Copy a[] to b[] two times  
//     for (int i = 0; i < n; i++)  
//         b[i] = b[n + i] = a[i]; 
  
//     // print from ind-th index to (n+i)th index. 
//     for (int i = ind; i < n + ind; i++) 
//         cout << b[i] << " "; 
//     cout<<endl;    
// } 
  
// // Driver code  
// int main() 
// { 
//     char a[] = { 'A', 'B', 'C', 'D', 'E', 'F' }; 
//     int n = sizeof(a) / sizeof(a[0]); 
//     int index ;
//     cout<<"Enter the index no to start with : ";
//     cin>>index;

//     print(a, n, index); 
//     return 0; 
// } 




/*

This approach takes of O(n) time but takes extra space of order O(n)

An efficient solution is to deal with circular arrays using the same array. If a careful observation is run through the array, then after n-th index, the next index always starts from 0 so using the mod operator, we can easily access the elements of the circular list, if we use (i)%n and run the loop from i-th index to n+i-th index. and apply mod we can do the traversal in a circular array within the given array without using any extra space. 

*/




// array without using extra memory space 


#include <iostream> 
using namespace std; 
  
// function to print circular list starting 
// from given index ind. 
void print(char a[], int n, int ind) 
{ 
    // print from ind-th index to (n+i)th index. 
    for (int i = ind; i < n + ind; i++) 
        cout << a[(i % n)] << " "; 
} 
  
// Driver code 
int main() 
{ 
    char a[] = { 'A', 'B', 'C', 'D', 'E', 'F' }; 
    int n = sizeof(a) / sizeof(a[0]); 
    print(a, n, 3); 
    return 0; 
} 