// Print Counting 


#include <iostream>
using namespace std;


void print_backword(int n)
{
    // base case
    if (n == 0)
    {
        cout<<endl;
        return ;
    }
    cout<<n<<" ";
    print_backword(n-1);    
}


void print_forward(int n)
{
    //base case
    if (n == 0)
    {
        return ;
    }

    print_forward(n-1);
    cout<<n<<" ";
}


int main() {
    
    int n ;
    cout<<"Enter the value of n = ";
    cin>>n ;

    cout<<endl;

    cout<<"Printing Counting backword from "<<n<<" :"<<endl;
    print_backword(n);

    cout<<"Printing Counting forward till "<<n<<" :"<<endl;
    print_forward(n);
    cout<<endl;

    return 0;
}