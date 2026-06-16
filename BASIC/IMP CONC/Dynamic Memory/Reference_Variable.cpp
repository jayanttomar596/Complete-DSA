#include <iostream>
using namespace std;


void update2(int& n)
{
    n++;
}
// pass by reference - isme hum nayi memory nahi banate original memory location pe hi point hota hai 


void update1(int n)
{
    n++;
}


int& update_n(int n)
{
    int a = 10;
    int &ans = a ;
    return ans ;
}
//BAD PRACTICE - memory access nahi kar paao , kyoki ans ki memory toh is block tak limited - agar access karli toh kya patah koi dusri karlo

int* fun(int n)
{
    int *ptr = &n ;
    return ptr ;
}
// yeh upar walle func me bhi same dikkat hai - RISKY HAI 



int main() {
    
    int i = 5 ; 

    //create a refernence variable 

    int &j = i ;

    cout<<i<<endl;
    i++ ;
    cout<<i <<endl;
    j++;
    cout<<i<<endl;
    cout<<j<<endl;

    // same memory , different names

    // But , WHY ?

    int n = 5 ;
    cout<<"Before "<<n<<endl;
    // update1(n);
    update2(n);
    cout<<"After "<<n<<endl;


    // update_n(n);
    // BAD PRACTICE
// In small, simple programs, the memory for a might stay intact for a short time after the function ends, especially if no other function calls or stack allocations occur immediately. - may be correct value return karde 
     

    
    return 0;
}