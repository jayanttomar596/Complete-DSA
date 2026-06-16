
//Intersect Array

#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(int arr1[] , int arr2[] , int size1,int size2)
{
    std::vector<int> ans ;

    for (int i = 0 ; i < size1 ; i++)
    {
        int element = arr1[i];

        for (int j = 0 ; j < size2 ; j++)
        {
            if (element == arr2[j])
            {
                ans.push_back(element);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }
    return ans ; 
}

int main() {
    int arr1[5] = {1,2,3,4,5};
    int arr2[3] = {2,6,4};

    // Get the intersection of arr1 and arr2
    vector<int> result = intersection(arr1, arr2,5,3);

    // Print the result
    cout << "Intersection: ";
    for (size_t i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
    }
    cout<<endl;
    return 0;
}







// SORTED ARRAY 
// First we want both array to be SORTED

// int i = 0 , j = 0 ;
// vector<int> ans;
// while (i<n && j<m)
// {
//     if (arr1[i] == arr2[j])
//     {
//         ans.push_back(arr[i]);
//         i++;
//         j++;
//     }
//     else if (arr[i] < arr2[j])
//     {
//         i++;
//     }
//     else
//     {
//         j++;
//     }
// }