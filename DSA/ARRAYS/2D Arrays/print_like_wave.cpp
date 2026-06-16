
// For a given two - dimensional integer array / list 'ARR' of size (N X M) , print the 'ARR' in a sine wave order , i.e. print the first column top to bottom , next column bottom to top , and so on .

// 3 4  11                              
// 2 12 1    --->  3 2 7 8 12 4 11 1 7  
// 7 8  7                               

#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int> > arr, int rows , int cols)
{
    vector<int> ans ;
    for (int i = 0 ; i < cols ; i++)
    {
        if (i&1)
        {
            //odd Index -> Bottom to Top
            
            for(int j = rows - 1 ; j>=0 ; j--)
            {
                // cout<<arr[j][i]<<" ";
                ans.push_back(arr[j][i]);
            }
        }
        else
        {
            // 0 or even index -> top to bottom

            for (int j = 0 ; j < rows ; j++)
            {
                // cout<<arr[j][i]<<" ";
                ans.push_back(arr[j][i]);
            }
        }
    }
    return ans ;
}


void PrintVector(vector<int> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


int main() {
    int rows, cols ;
    cout<<"Enter number of Rows and Columns : ";
    cin>>rows>>cols;

    vector<vector<int> > vec(rows,vector<int>(cols));

    cout<<"Enter the elements : "<<endl;
    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < cols ; j++)
        {
            cin>>vec[i][j];
        }
    }  

    vector<int>  ans = wavePrint(vec , rows , cols);

    PrintVector(ans);

    return 0;
}




