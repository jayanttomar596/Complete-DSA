
//UNIQUE ELEMENT IN ARRAY


// #include <iostream>
// using namespace std;

// int unique_element(int arr[] , int size)
// {
//     int unique ;
//     for (int i = 0 ; i < size ; i++)
//     {
//         for (int j = 0 ; j < size ; j++)
//         {
//             if (j == size - 1)
//             {
//             unique = arr[i];
//             }
//             if (i == j)
//             {
//                 continue;
//             }
//             if (arr[i] == arr[j])
//             {
//                 break ;
//             }
//         }
        
//     }
//     return unique ; 
// }

// int main() {
//     int arr[9] = {1,2,2,3,3,4,4,1,9};

//     cout<<"Unique Element = "<<unique_element(arr,9)<<endl;
//     return 0;
// }






// #include <iostream>
// using namespace std;

// int unique_element(int arr[], int size) {
//     int unique = -1; // Initialize unique to a value that doesn't match any array element
//     for (int i = 0; i < size; i++) {
//         bool foundDuplicate = false;
//         for (int j = 0; j < size; j++) {
//             if (i != j && arr[i] == arr[j]) {
//                 foundDuplicate = true;
//                 break; // Break if duplicate found
//             }
//         }
//         if (!foundDuplicate) {
//             unique = arr[i]; // If no duplicate found, it's the unique element
//             break; // Break after finding the unique element
//         }
//     }
//     return unique;
// }

// int main() {
//     int arr[9] = {1, 2, 2, 3, 3, 4, 4, 1, 9};

//     cout << "Unique Element = " << unique_element(arr, 9) << endl;
//     return 0;
// }






// #include <iostream>
// using namespace std;

// int unique_element(int arr[], int size) {
//     int unique = 0;
//     for (int i = 0; i < size; i++) {
//         unique ^= arr[i]; // XOR operation
//     }
//     return unique; // The unique element will be left
// }

// int main() {
//     int arr[9] = {1, 2, 2, 3, 3, 4, 4, 1, 9};

//     cout << "Unique Element = " << unique_element(arr, 9) << endl;
//     return 0;
// }






// #include <iostream>
// using namespace std;

// int find_unique(int arr[] , int size)
// {
//     int unique = 0 ;

//     for (int i = 0 ; i < size ; i++)
//     {
//         unique = unique^arr[i];
//     }
//     return unique ;
// }

// int main() {
//     int arr[5] = {1,2,1,3,2};

//     cout<<"Unique Element : "<< find_unique(arr,5)<<endl;
//     return 0;
// }