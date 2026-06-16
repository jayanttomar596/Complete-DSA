// 2D Array - Dynamic Memory Allocation

#include <iostream>
using namespace std;

int main() {
    
    int row ,col;
    cout<<"Enter no of rows = ";
    cin>>row ; 

    cout<<"Enter no of cols = ";
    cin>>col;

    // Creating a 2D Array
    int** arr = new int*[row];
    for (int i = 0 ; i < row ; i++)
    {
        arr[i] = new int[col] ;
    }


    //taking input 
    for (int i=0 ; i < row ; i++)
    {
        for (int j = 0 ; j < col ; j++)
        {
            cin >> arr[i][j] ;
        }
    }


    // Printing Output
    cout<<endl;
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < col ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // releasing memory
    for (int i = 0 ; i < row ; i++)
    {
        delete[] arr[i] ;
    }

    delete []arr;
    arr = nullptr; // Avoid dangling pointer

    
    return 0;
}




