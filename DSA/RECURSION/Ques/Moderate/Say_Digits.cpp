// 432 - Four Three Two
// 167 - One Six Seven


#include <iostream>
using namespace std;

void sayDigit(int n , string arr[])
{

    // Base Case
    if (n == 0)
        return ;

    // Processing
    int digit = n % 10 ;
    n = n / 10 ;

    // Recursive Call
    sayDigit(n , arr);  

    cout<< arr[digit] <<" ";
}


int main() {
    
    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

    int n ;
    cout<<"Enter the number = ";
    cin>>n;

    cout<<"\n\n";

    sayDigit(n,arr);
    cout<<endl;

    return 0;
}




