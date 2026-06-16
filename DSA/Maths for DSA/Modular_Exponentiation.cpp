// (x^n)%m 

#include <iostream>
using namespace std;


int modular_Exponentiation(int x , int n , int m)
{
    int res = 1 ;

    while(n>0)
    {
        if(n&1)
        {//odd
            res = (1LL * (res) * (x)%m)%m ;
        }
        x = (1LL * (x)%m * (x)%m )%m ;
        n = n>>1 ;
    }
    return res ;
}


int main() {
    cout<<"Find (x^n)%m = ?"<<endl;
    int x , n , m ;

    cout<<"Enter the value of x = ";
    cin>>x;

    cout<<"Enter the value of n = ";
    cin>>n;

    cout<<"Enter the value of m = ";
    cin>>m;

    int ans = modular_Exponentiation(x,n,m);

    cout<<"("<<x<<"^"<<n<<")%"<<m<<" = "<<ans<<endl;
    
    return 0;
}