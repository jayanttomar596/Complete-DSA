
#include <iostream>
#include <array>
using namespace std;

int main() {
    int basic[3] = {1,2,3};

    array<int ,4> a = {1,2,3,4};

    int size = a.size();

    for (int i = 0 ; i < size ; i++)
    {
        cout<<a[i]<<endl;
    }

    cout<<"Element at 2nd Index -> "<<a.at
    (2)<<endl;

    cout<<"Empty or not -> "<<a.empty()<<endl;

    cout<<"First Element -> "<<a.front()<<endl;
    cout<<"Last Element -> "<<a.back()<<endl;
    return 0;
}








// CHATGPT CODES


// #include <iostream>
// #include <array>
// using namespace std;

// int main() {
//     // Declare and initialize an array
//     array<int, 5> arr = {10, 20, 30, 40, 50};

//     // 1. Access elements using at() (bounds checking)
//     cout << "Element at index 2: " << arr.at(2) << endl;

//     // 2. Access first and last elements
//     cout << "First element: " << arr.front() << endl;
//     cout << "Last element: " << arr.back() << endl;

//     // 3. Check the size of the array
//     cout << "Size of the array: " << arr.size() << endl;

//     // 4. Check if the array is empty
//     cout << "Is the array empty? " << (arr.empty() ? "Yes" : "No") << endl;

//     // 5. Fill the array with a specific value
//     arr.fill(100);
//     cout << "Array after filling with 100: ";
//     for (int x : arr) {
//         cout << x << " ";
//     }
//     cout << endl;

//     // 6. Swap contents with another array
//     array<int, 5> arr2 = {1, 2, 3, 4, 5};
//     arr.swap(arr2);
//     cout << "Array after swapping with arr2: ";
//     for (int x : arr) {
//         cout << x << " ";
//     }
//     cout << endl;

//     cout << "arr2 after swapping: ";
//     for (int x : arr2) {
//         cout << x << " ";
//     }
//     cout << endl;

//     return 0;
// }




