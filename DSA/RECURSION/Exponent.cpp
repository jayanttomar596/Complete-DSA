#include <iostream>
using namespace std;


int power(int a , int b)
{
    // Base Case
    if (b == 0)
        return 1 ;

    if (b == 1)
        return a ;

    // RECURSIVE CALL
    int ans = power(a,b/2);

    // if b is even
    if (b%2 == 0)
    {
        return ans * ans ;
    }
    else
    {
        // if b is odd
        return a * ans * ans ;
    }
}


int main() {
    
    int a , b ;
    cout<<"To find a^b : "<<endl;
    cout<<"Value of a = ";
    cin>>a;
    cout<<"Value of b = ";
    cin>>b;

    int ans = power(a,b);
    cout<<a<<"^"<<b<<" = "<<ans<<endl;

    return 0;
}




