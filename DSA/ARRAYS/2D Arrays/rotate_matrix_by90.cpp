/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void rotate_transpose_method(vector<vector<int> >& matrix) {
        int n = matrix.size(); 

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {              
            for (int j = i + 1; j < n; j++) {      
                swap(matrix[i][j], matrix[j][i]);  
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {      
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};


void rotate(vector<vector<int> >& matrix) 
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int> > temp(rows , vector<int>(cols)) ;
    for (int row = 0 ; row < rows ; row++)
    {
        for (int col = 0 ; col < cols ; col++)
        {
            temp[col][rows-row-1] = matrix[row][col];
        }
    }
    matrix = temp ;
    // agar return kar sakte toh direct temp vector return kar dete !! aur pehle maine vahi kiya tha par uske liya naya vector banana padta jiska koi matlab nahi hai !!
}


void Print_2D_Array(vector<vector<int> > v)
{
    int rows = v.size();
    int cols = v[0].size();
    cout<<"The 2D Vector is :\n";
    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < cols ; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main() {
    // agar jayada rows and cols ka chaiye toh change kar dena , Ok !!
    int rows = 3 , cols = 3 ;
    vector<vector<int> > matrix(rows , vector<int>(cols));

    cout<<"Enter the elements : "<<endl;
    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < cols ; j++)
        {
            cin>>matrix[i][j];
        }
    }

    Print_2D_Array(matrix);

    rotate(matrix);

    Print_2D_Array(matrix);

    return 0;
}




