#include <iostream>
#include <vector>
using namespace std;

class Solution {
private :
    bool isPrime(int n)
    {
        if (n <= 1)
            return false ;

        for (int i = 2 ; i < n ; i++)
        {
            if(n%i == 0)
            {
                return false ;
            }
        }    
        return true ;
    }  
public:
    int countPrimes(int n) {
        
        int cnt = 0 ;

        for (int i = 2 ; i < n ; i++)
        {
            if(isPrime(i))
                cnt++;
        }
        return cnt ;
    }
};


//But for large no its Time Limit Exceeds as its time complexity is n^2 
// Hence , We find SIEVE OF ERATOSTHENES
//In this we mark every no except 1 and n itself as Prime Numbers then jo jo table me aye unne non-prime mark kardo


class Solution_SOE {  
public:
    int countPrimes(int n) {

        int cnt = 0 ;
        vector<bool> prime(n+1 , true) ;

        prime[0] = prime[1] = false ;

        for (int i=2 ; i < n ; i++)
        {

            if(prime[i]){
                cnt++;

                for (int j=2*i ; j<n ; j+=i)
                {
                    prime[j] = 0 ;
                }
            }
        }
        return cnt ;
    }
};

// Time Complexity of Sieve Of Eratßosthenes - O(n*log(logn))


int main() {
    Solution sol ;
    Solution_SOE sol2 ;

    int n ;
    cout<<"Enter the value of n to find no of primes less than n = ";
    cin>>n ;

    // int count = sol.countPrimes(n);
    int count = sol2.countPrimes(n);

    cout<<"No of Prime Numbers less than "<<n<<" = "<<count<<endl;

    return 0;
}