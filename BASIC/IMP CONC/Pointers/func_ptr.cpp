#include <iostream>
using namespace std;


void print(int *p)
{
    cout<< *p << endl;
}

void update(int *p)
{
    // p = p + 1 ;
    // cout<< "Inside "<<p<<endl;
    // Update ke andar change ho jayega p ka value par main me nahi hoga - par value kar sakte hai

    *p = *p + 1 ; // value update toh ho jayegi

}

int getSum(int arr[] , int size)
{

    // cout<<"Size -> "<<sizeof(arr)<<endl;
    // isme array ka size nahi aye pointer ka size aya hai kyoki function me pointer hi pass hota hai 

    int sum = 0 ; 
    for (int i = 0 ; i < size ; i++)
    {
        sum += arr[i] ;
    }
    return sum ;
}


int main() {

    int value = 5 ;
    int *p = &value ;

    // print(p); // Output : 5

    cout<<"Before "<<p<<endl;
    update(p);
    cout<<"After "<<p<<endl;
    cout<<*p<<endl;
/*
In your code, the Before and After outputs are the same because the update function modifies only the local copy of the pointer p, not the original pointer in the main function.
p = p + 1; increments the local copy of the pointer, pointing it to the next memory location.
*/
    
    int arr[6] = {1,2,3,4,5,6};

    cout<<"Sum is "<<getSum(arr,6)<<endl;
    //Output : 21

    cout<<"Sum of last three -> "<<getSum(arr+3,3)<<endl; // output: 17
    // Advantage of ptr , we can pass a part of array 

    return 0;
}




