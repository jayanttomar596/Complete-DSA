#include <iostream>
using namespace std;

int getSum(int arr[] , int size)
{
    // Base Size
    if (size == 0)
    {
        return 0 ;
    }

    if (size == 1)
    {
        return arr[0];
    }


    int remainingPart = getSum(arr+1 , size - 1);
    int sum = arr[0] + remainingPart;
    // cout<<sum<<endl;

    return sum ;
}


int main() {
    
    int arr[5] = {2,4,9,9,9};
    int size = 5 ;

    int sum = getSum(arr , size);

    cout<< "Sum of Elements in Array = "<<sum<<endl;

    return 0;
}


