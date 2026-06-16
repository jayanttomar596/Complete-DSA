
// #include <iostream>
// #include <math.h>
// using namespace std;

// int main() {
//     int n,ans=0,bit;
//     cout<<"Enter Decimal Number : ";
//     cin>>n;

//     int i = 0 ;

//     while(n!=0){
//         bit = n&1;

//         ans += pow(10,i)*bit;
//         i++;
//         n = n >>1;
//     }

//     cout<<"In Binary : "<<ans<<endl;
//     return 0;
// }





// #include <iostream>
// using namespace std;

// int AP(int n)
// {
//     int ap = 3*n+7;
//     return ap;
// }

// int main() {
//     int n;
//     cin>>n;
//     int ans = AP(n);
//     cout<<"Answer is = "<<ans<<endl;

//     return 0;
// }




// #include <iostream>
// using namespace std;

// int bits(int a , int b)
// {
//     int count = 0 ;

//     while (a != 0)
//     {
//         if (a&1)
//         {
//             count++;
//         }
//         a = a>>1;
//     }

//      while (b != 0)
//     {
//         if (b&1)
//         {
//             count++;
//         }
//         b = b>>1;
//     }

//     return count ;
// }

// int main() {
//     int a,b;
//     cout<<"Enter 1st Decimal Number : ";
//     cin>>a;
//     cout<<"Enter 2nd Decimal Number : ";
//     cin>>b;
//     cout<<"No of 1's in "<<a<<" and "<<b<<" = "<<bits(a,b)<<endl;
//     return 0;
// }






// #include <iostream>
// using namespace std;

// int fibonacci(int n){
//     int a = 0 , b = 1 , sum = 0 ;

//     for (int i = 1 ; i < n ; i++)
//     {
//         a = b ;
//         b = sum ; 
//         sum = a+b ; 
//     } 
//     return sum ; 
// }

// int main() {
//     int n;
//     cout<<"Enter place of term to get from fibonacci series : ";
//     cin>>n;
//     cout<<fibonacci(n)<<endl;
//     return 0;
// }







// ARRAYS


// #include <iostream>
// using namespace std;

// int main() {
    
//     //declare
//     // int number[15];

//     // cout<<"Value at 1 index "<<number[14]<<endl;

//     // cout<<endl<<" Everything is Fine "<<endl<<endl;

//     // cout<<"Value at 14 index "<<number[14]<<endl;

//     // int second[3] = {5,7,11};

//     int arr[15] = {2,7};
//     // cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;

//     int size =15;

//     cout<<"Printing the array : "<<endl;

//     //print the array
//     for (int i = 0 ; i < size ; i++)
//     {
//         cout<<arr[i]<<endl;
//     }

//     char ch[5] = {'a','b','c','d','e'};
//     cout<<ch[3]<<endl;

//     cout<<" Printing the array "<<endl;

//     for (int i = 0 ; i < 5 ; i++)
//     {
//         cout<<ch[i]<<" ";
//     }

//     double firstDouble[5];
//     float firstFloat[6];
//     bool firstBool[9];

//     cout<<endl<<"Everything is Fine "<<endl<<endl;

//     return 0 ;
// }







// #include <iostream>
// using namespace std;

// void printArray(int arr[] , int size)
// {
//     cout<<"Printing the array : "<<endl;
//     //print the array
//     for (int i = 0 ; i < size ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<" Printing Done "<<endl;
// }

// void enter_array(int arr[] , int size)
// {
//     cout<<"Enter the values for each index : ";
//     for (int i = 0 ; i < size ; i++)
//     {
//         cin>>arr[i];
//     }
// }

// int main() {
//     int number[15];
//     enter_array(number,15);
//     printArray(number,15);
//     return 0;
// }






// MAX_AND_MIN_OF_ARRAY


// #include <iostream>
// using namespace std;

// int max_arr(int arr[] , int size)
// {
//     int max = arr[0];
//     for (int i = 1 ; i < size ; i++)
//     {
//         if (arr[i]>max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }

// int min_arr(int arr[] , int size)
// {
//     int min = arr[0];
//     for (int i = 1 ; i < size ; i++)
//     {
//         if (arr[i]<min)
//         {
//             min = arr[i];
//         }
//     }
//     return min;
// }

// int main() {
    // int arr[4] = {4,12,8,10};

    // cout<<"Max element amoung array = "<<max_arr(arr,4)<<endl;
    // cout<<"Min element among array = "<<min_arr(arr,4)<<endl;
//     return 0;
// }





// #include <iostream>
// using namespace std;

// int max_arr(int arr[] , int size)
// {
//     int max = INT_MIN;
//     for (int i = 0 ; i < size ; i++)
//     {
//         if (arr[i]>max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }

// int min_arr(int arr[] , int size)
// {
//     int min = INT_MAX;
//     for (int i = 0 ; i < size ; i++)
//     {
//         if (arr[i]<min)
//         {
//             min = arr[i];
//         }
//     }
//     return min;
// }

// int main() {
    // int arr[4] = {4,12,8,10};

    // cout<<"Max element amoung array = "<<max_arr(arr,4)<<endl;
    // cout<<"Min element among array = "<<min_arr(arr,4)<<endl;
    // return 0;
// }







// #include <iostream>
// using namespace std;

// int getMax(int num[] , int size)
// {
//     int maxi = INT_MIN ; 

//     for (int i = 0 ; i < size ; i++)
//     {
//         maxi = max(maxi , num[i]);
//     }
//     return maxi ;
// }

// int getMin(int num[] , int size)
// {
//     int mini = INT_MAX;

//     for (int i = 0 ; i < size ; i++)
//     {
//         mini = min(mini , num[i]);
//     }
//     return mini ;
// }

// int main() {
//     int arr[4] = {4,12,8,10};

//     cout<<"Max element amoung array = "<<getMax(arr,4)<<endl;
//     cout<<"Min element among array = "<<getMin(arr,4)<<endl;
//     return 0;
//     return 0;
// }






// #include <iostream>
// using namespace std;

// void update(int arr[] , int n)
// {
//     cout<<"Inside the function "<<endl;

//     //Updating array's first element
//     arr[0] = 120 ;

//     //printing the array
//     for (int i = 0 ; i < 3 ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }cout<<endl;

//     cout<<"Going back to main function"<<endl;
// }

// int main() {
    
//     int arr[3] = {1,2,3};

//     update(arr,3);

//     //printing the array

//     cout<<endl<<"Printing in main function"<<endl;

//     for (int i = 0 ; i < 3 ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }






// #include <iostream>
// using namespace std;

// int main() {
//     int n ,count = 0;
//     cout<<"Enter number : ";
//     cin>>n;
//     if (n==1)
//     {
//         cout<<"No its not a even number"<<endl;
//         return 0 ;
//     }
//     while (n!=0)
//     {
//         if (n&1)
//         {
//             count++;
//         }
//         n = n >>1;
//     }
  
//     if (count == 1 || count == 0 )
//     {
//         cout<<"Yes its an even number"<<endl;
//     }
//     else
//     {
//         cout<<"No its not an even number"<<endl;
//     }
//     return 0;
// }






// SWAP ALTERNATE

// #include <iostream>
// using namespace std;

// void swap_alt(int arr[] , int size)
// {
//     for (int i = 0 ; i < size ; i+=2)
//     {
//         if (i+1 < size)
//         {
//             swap(arr[i] , arr[i+1]);
//         }
//     }
// }

// void Print_Array(int arr[] , int size)
// {
//     for (int i = 0 ; i < size ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// void Take_input(int arr[] , int size )
// {
//     cout<<"Enter each element one by one : "<<endl;
//     for (int i = 0 ; i < size ; i++)
//     {
//         cin>>arr[i];
//     }
//     cout<<endl;
// }

// int main() {
//     int size ;
//     cout<<"Enter the size of the array : ";
//     cin>>size;

//     int arr[size];
//     Take_input(arr,size);

//     Print_Array(arr,size);

//     swap_alt(arr,size);

//     Print_Array(arr,size);

//     return 0;
// }






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
//     int arr[6] = {1,2,2,1,3,2};

//     cout<<"Unique Element : "<< find_unique(arr,6)<<endl;
//     return 0;
// }





//Unique Number of Occurences

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// bool uniqueOccurrences(vector<int>& arr) {
//     int i = 0 ;
//     sort(arr.begin(),arr.end());
//     vector<int> ans;
//     while (i < arr.size()){
//         int count = 1 ;
//         for (int j = i + 1 ; j < arr.size() ; j++)
//         {
//             if (arr[i] == arr[j])
//                 count++;
//         }
//         ans.push_back(count);
//         i+=count;
//     }
//     sort(ans.begin() , ans.end());
//     for (int i = 0 ; i < ans.size() - 1 ; i++)
//     {
//         if (ans[i] == ans[i+1])
//                 return false ;            
//     }
//     return true ;    
// }

// int main() {
//     vector<int> arr = {1, 2, 2, 1, 1, 3};
//     if (uniqueOccurrences(arr)) {
//         cout << "True: All occurrences are unique" << endl;
//     } 
//     else {
//         cout << "False: Occurrences are not unique" << endl;
//     }
//     return 0;
// }






// DUPLICATE 

// #include <iostream>
// #include <vector>
// using namespace std;

// int findDuplicate(vector<int> &arr)
// {
//     int ans = 0 ; 

//     //XOR ing all array elements
//     for (int i = 0 ; i < arr.size() ; i++)
//     {
//         ans = ans^arr[i];
//     }

//     //XOR (1,n-1)
//     for (int i = 1 ; i < arr.size() ; i++)
//     {
//         ans = ans ^ i; 
//     }
//     return ans ; 
// }

// int main() {
    
//     return 0;
// }







//Intersect Array

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> intersection(int arr1[] , int arr2[] , int size1,int size2)
// {
//     std::vector<int> ans ;

//     for (int i = 0 ; i < size1 ; i++)
//     {
//         int element = arr1[i];

//         for (int j = 0 ; j < size2 ; j++)
//         {
//             if (element == arr2[j])
//             {
//                 ans.push_back(element);
//                 arr2[j] = INT_MIN;
//                 break;
//             }
//         }
//     }
//     return ans ; 
// }

// int main() {
//     int arr1[5] = {1,2,3,4,5};
//     int arr2[3] = {2,6,4};

//     // Get the intersection of arr1 and arr2
//     vector<int> result = intersection(arr1, arr2,5,3);

//     // Print the result
//     cout << "Intersection: ";
//     for (size_t i = 0; i < result.size(); i++) {
//     cout << result[i] << " ";
//     }
//     cout<<endl;
//     return 0;
// }





// PAIR SUM

// #include <iostream>
// using namespace std;

// void pair_sum(int arr[] ,int size , int sum)
// {
//     for (int i = 0 ; i < size ; i++)
//     {
//         for (int j = i+1 ; j < size ; j++)
//         {
//             if (arr[i]+arr[j] == sum)
//             {
//                 cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
//             }
//         }
//     }
// }

// int main() {
//     int arr[5] = {1,2,3,4,5};
//     int sum;
//     cout<<"Enter value of sum to find pairs = ";
//     cin>>sum;
//     pair_sum(arr,5,sum);
//     return 0;
// }




// TRIPLET SUM

// #include <iostream>
// using namespace std;

// void triplet_sum(int arr[] , int size , int sum)
// {
//     for (int i = 0 ; i < size ; i++)
//     {
//         for (int j = i+1 ; j < size ; j++)
//         {
//             for (int k = j +1 ; k < size ; k++)
//             {
//                 if (arr[i]+arr[j]+arr[k] == sum)
//                 {
//                     cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<endl;
//                 }
//             }
//         }
//     }
// }

// int main() {
//     int arr[5]={5,3,2,4,1};
//     int sum ;
//     cout<<"Enter the sum to get Triplet = ";
//     cin>>sum;

//     triplet_sum(arr,5,sum);
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int main() {
//     std::cout<<"C++ version:"<<__cplusplus<<std::endl;
//     return 0;
// }






// Sort 0 ,1 

// #include <iostream>
// using namespace std;

// void PrintArray(int arr[], int size)
// {
//     for (int i = 0 ; i < size ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// void SortOne(int arr[] , int n)
// {
//     int left = 0 , right = n - 1 ;

//     while(left < right)
//     {
//         while (arr[left] == 0 && left < right)
//         {
//             left++;
//         }

//         while (arr[right] == 1 && left < right)
//         {
//             right--;
//         }

//         //agar yha pahuch gye ho , iska matlab
//         //arr[left] == 1 and arr[right] == 0
//         if (left < right)
//         {
//             swap(arr[left],arr[right]);
//             left++;
//             right--;
//         }
//     }
// }

// int main() {
//     int arr[8] = {1,1,0,0,0,0,1,0};

//     //Before Sorting
//     PrintArray(arr,8);

//     SortOne(arr,8);

//     //After Sorting
//     PrintArray(arr,8);
//     return 0;
// }





//SORT 0 , 1 , 2

// #include <iostream>
// using namespace std;

// void PrintArray(int arr[] , int size)
// {
//     for (int i = 0 ; i < size ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// void Sort(int arr[] , int size)
// {
//     for (int i = 0 ; i < size ; i++)
//     {
//         for (int j = i + 1 ; j < size ; j++)
//         {
//             if (arr[i]>arr[j])
//             {
//                 swap(arr[i],arr[j]);
//             }
//         }
//     }
// }

// int main() {
//     int arr[8] = {1,2,1,2,1,0,1,0};

//     PrintArray(arr,8);
//     Sort(arr,8);
//     PrintArray(arr,8);
//     return 0;
// }






//BINARY SEARCH 

// #include <iostream>
// using namespace std;

// int BinarySearch(int arr[] , int size , int key)
// {
//     int start = 0 , end = size - 1;
//     int mid;
//     while (start <= end)
//     {
//         // mid = (start + end)/2 ;
//         mid = start + (end-start)/2;
//         if (arr[mid] == key)
//         {
//             return mid ;
//         }
//         else if (arr[mid]>key)
//         {
//             end = mid - 1 ;
//         }
//         else if (arr[mid]<key)
//         {
//             start = mid+1;
//         }   
//     }
//     return -1 ;
// }

// int main() {
//     int arr[9] = {1,2,3,4,5,6,7,8,9};
//     int key;
//     cout<<"Enter Key element to search for = ";
//     cin>>key;

//     int index = BinarySearch(arr,9,key);

//     if (index!=-1)
//     {
//         cout<<"Element found at index : "<<index<<endl;
//     }
//     else
//     {
//         cout<<"Element not found in array "<<endl;
//     }
//     return 0;
// }






// first and last occurance of a particular number in a sorted array

// #include <iostream>
// using namespace std;

// int first_occurance(int arr[] , int size , int key)
// {
//     for (int i = 0 ; i < size ; i++)
//     {
//         if (arr[i] == key)
//         {
//             return i ;
//         }
//     }
//     return -1 ;
// }

// int last_occurance(int arr[] , int size , int key)
// {
//     for (int i = size - 1 ; i >= 0 ; i--)
//     {
//         if (arr[i] == key)
//         {
//             return i ;
//         }
//     }
//     return -1 ;
// }

// int main() {
//     int arr[8] = {1,1,1,2,2,2,2,8};
//     int key;
//     cout<<"Enter the element to search occurance = ";
//     cin>>key;
//     int first_occ = first_occurance(arr , 8 , key);
//     int last_occ = last_occurance(arr , 8 , key);

//     cout<<"First Ocuurance = "<<first_occ<<endl;
//     cout<<"Last Occurance = "<<last_occ<<endl;
//     return 0;
// }




// #include <iostream>
// #include <vector>
// using namespace std;

// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     int i = m - 1;     // Last valid element in nums1
//     int j = n - 1;     // Last element in nums2
//     int k = m + n - 1; // Last position in nums1

//     while (i >= 0 && j >= 0) {
//         if (nums1[i] > nums2[j]) {
//             nums1[k--] = nums1[i--];
//         } else {
//             nums1[k--] = nums2[j--];
//         }
//     }

//     // Copy remaining elements from nums2 (if any)
//     while (j >= 0) {
//         nums1[k--] = nums2[j--];
//     }
// }

// void PrintArray(vector<int> &v) {
//     for (int i = 0; i < v.size(); i++) {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     vector<int> nums1 ;
//     nums1.push_back(1);
//     nums1.push_back(2);
//     nums1.push_back(3);
//     nums1.push_back(0);
//     nums1.push_back(0);
//     nums1.push_back(0);

//     vector<int> nums2 ;
//     nums2.push_back(2);
//     nums2.push_back(5);
//     nums2.push_back(6);  
    
//     int m = nums1.size();
//     int n = nums2.size();                        

//     merge(nums1, m, nums2, n);
//     PrintArray(nums1);

//     return 0;
// }





// Lenght of string

// #include <iostream>
// using namespace std;

// int getLenght(char name[])
// {
//     int count = 0 ;
//     for (int i = 0 ; name[i] != '\0' ; i++)
//     {
//         count++;
//     }
//     return count ;
// }

// void reverse(char name[] , int n)
// {
//     int s = 0 ;
//     int e = n-1 ;

//     while (s<e)
//     {
//         swap(name[s++] , name[e--]);
//     }
// }

// int main() {
//     char name[20] ;
//     cout<<"Enter your name : ";
//     cin>>name ;

//     int len = getLenght(name);
//     cout<<"Lenght : "<<len<<endl;

//     cout<<"After reversing char array : "<<endl;
//     reverse(name ,len);
//     cout<<name<<endl;

//     return 0;
// }






#include <iostream>
#include <string>
#include <stack>
using namespace std;




int findMinimumCost(string str)
{
    // Odd Condition
    if (str.length()%2 == 1)
        return -1 ;
    
    stack<char> s ;
    for (int i = 0 ; i < str.length() ; i++)
    {
        char ch = str[i] ;
        if (ch == '{')
        {
            s.push(ch) ;
        }
        else
        {
            if(!s.empty() && s.top() == '{')
                s.pop() ;
            else 
                s.push(ch) ;
        }
    }
    int a = 0 , b = 0 ;
    while(!s.empty())
    {
        if (s.top() == '{')
            b++ ;
        else 
            a++ ;
        s.pop() ;
    }

    int ans = (a+1)/2 + (b+1)/2 ;
        return ans ;
}




int main() {
    string str = "{}{}}}}{{{" ;

    cout << "\nString : " << str << endl ;
    int cost = findMinimumCost(str) ;
    cout << "\nCost = " << cost << endl; 
    
    return 0;
}


