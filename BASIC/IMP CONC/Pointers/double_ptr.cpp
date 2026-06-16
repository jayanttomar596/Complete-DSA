#include <iostream>
using namespace std;

void update (int **p)
{
    // p = p + 1 ;
    // Kuch change hoga ??  ->  No , function ke undar change hoga leki globally nahi hoga 

    // *p = *p + 1 ;
    //kuch change hoga ??   ->  Yes , ptr ki value change hogi

    // **p = **p + 1 ;
    // kuch change hoga ??  -> Yes , i ki value change hogi
    
}


int main() {

    int i = 5 ;
    int* ptr = &i ;

    int** ptr2 = &ptr ; //Double Pointer 

    cout<<"\n\n"<<"Sab sahi chal rha hai "<<"\n\n";

    cout<<"Printing p = "<<ptr<<endl;
    cout<<"Address of p = "<<ptr2<<endl;
    cout<<"Ptr2 ka address ptr ki value hai matlab i ka address -> "<<*ptr2<<endl<<endl;

    cout<< i <<endl; // 5
    cout<<*ptr<<endl; // 5
    cout<<**ptr2<<endl<<endl; // 5 


    cout<< &i <<endl; // i ka address
    cout << ptr << endl; // i ka address
    cout<< *ptr2 << endl; // i ka address


    cout<<endl<< &ptr <<endl;
    cout<< ptr2 << endl;
    cout<<endl<<endl;


    cout<<"Before "<<i<<endl;
    cout<<"Before "<<ptr<<endl;
    cout<<"Before "<<ptr2<<endl;
    update(ptr2);
    cout<<"After "<<i<<endl;
    cout<<"After "<<ptr<<endl;
    cout<<"After "<<ptr2<<endl;
    cout<<endl<<endl;


    return 0;
}