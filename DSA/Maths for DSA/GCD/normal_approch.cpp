
#include <iostream>
using namespace std;

int main() {
    int n1 , n2 ,min , hcf;
    cout<<"Enter First Number : ";
    cin>>n1;
    cout<<"Enter Second Number : ";
    cin>>n2 ;

    if (n1>n2)
    {
        min = n2 ;
    }
    else
    {
        min = n1 ;
    }

    for (int i = 1 ; i <= min ; i++)
    {
        if ((n1%i == 0) && (n2%i == 0))
        {
            hcf = i ;
        }
    }
    cout<<"HCF/GCD = "<<hcf<<endl;
    return 0;
}