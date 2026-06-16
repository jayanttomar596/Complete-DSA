// Fibonnacci Series

// 0 1 1 2 3 5 8 13 21 34 ----------
// I assumed n = 1 -> 0  , n = 2 -> 1 , n = 3 -> 1 , n = 4 -> 2 , n = 5 -> 3 and so on 


#include <iostream>
using namespace std;


long long int fib_n_term(int n)
{
    // Base Cases
    if (n == 1)
        return 0 ;
    if (n == 2)
        return 1 ;

    return fib_n_term(n-1) + fib_n_term(n-2);        
}

void print_fib(int n)
{
    for (int i = 1 ; i <= n ; i++)
    {
        cout<<fib_n_term(i)<<" ";
    }
    cout<<endl;
}


// Iterative - as Recurrsive Method is complex and inefficient for larger values of n 
void Print_fib_iterative(int n)
{
    long long int a = 0 , b = 1 ,temp;

    for (int i = 1 ; i <= n ; i++)
    {
        cout<<a<<" ";
        temp = a ;
        a = b ;
        b = temp+b ;
    }
    cout<<endl;
}


int main() {

    int n ;
    cout<<"Enter the value of n = ";
    cin>>n ;

    cout<<n<<"th term of Fibonnacci Series = "<<fib_n_term(n)<<endl<<endl;

    cout<<"Printing the Fibonnacci Series upto "<<n<<" terms : "<<endl;

    // print_fib(n);
    Print_fib_iterative(n);

    return 0;
}



