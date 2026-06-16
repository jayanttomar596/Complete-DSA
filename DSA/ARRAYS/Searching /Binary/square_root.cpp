
// First , To find integer part of the square root

// #include <iostream>
// using namespace std;

// int binarySearch(int n)
// {
//     int s = 0 ;
//     int e = n ;
//     long long int mid = s + (e-s)/2 ;

//     long long int ans = -1 ;
//     while(s <= e)
//     {
//         mid = s + (e-s)/2 ;

//         long long int square = mid*mid ;

//         if (square == n )
//             return mid ;

//         if (square < n)
//         {
//             ans = mid ;
//             s = mid+1 ;
//         }   
//         else
//         {
//             e =  mid - 1 ;
//         }

//     }
//     return ans ;
// }

// int mySqrt(int x){
//     return binarySearch(x);
// }

// int main() {
//     int n ; 
//     cout<<"Enter the Number to find Square Root = ";
//     cin>>n;

//     cout<<"Square Root of "<<n<<" = "<<mySqrt(n)<<endl;
//     return 0;
// }









// Now , with float part as well --  with more precision

#include <iostream>
using namespace std;

int sqrtInteger(int n)
{
    int s = 0 ;
    int e = n ;
    long long int mid = s + (e-s)/2 ;

    long long int ans = -1 ;
    while(s <= e)
    {
        mid = s + (e-s)/2 ;

        long long int square = mid*mid ;

        if (square == n )
            return mid ;

        if (square < n)
        {
            ans = mid ;
            s = mid+1 ;
        }   
        else
        {
            e =  mid - 1 ;
        }

    }
    return ans ;
}

double morePrecision(int n , int precision , int tempSol)
{
    double factor = 1 ;
    double ans = tempSol ;

    for (int i = 0 ; i < precision ; i++)
    {
        factor = factor / 10 ;
        for (double j = ans ; j*j < n ; j+=factor)
        {
            ans = j ;
        }
    }
    return ans ;
}

int main() {
    int n ; 
    cout<<"Enter the Number to find Square Root = ";
    cin>>n;

    int tempSol = sqrtInteger(n);
    cout<<"Answer is "<<morePrecision(n,3,tempSol)<<endl;
    return 0;
}



