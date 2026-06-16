// #include <iostream>
// #include <math.h>
// using namespace std;

// int bit(int n)
// {
//     int bit,result=0;
//     int ans = 0 , i = 0 ;
//     if (n==0)
//     {
//         return 0;
//     }
//     while(n != 0)
//     {
//         bit = n&1;
//         if (bit == 1)
//         {
//             bit = 0 ;
//         }
//         else{
//             bit= 1;
//         }
//     ans += pow(10,i)*bit;
//     i++; 
//     n=n>>1;   
//     }

//     int j = 0;
//     while(ans != 0)
//     {
//         int digit = ans%10;
//         if (digit == 1){
//             result +=  pow(2,j);
//         }
//         ans = ans/10;
//         j++;
//     }
//     return result;
// }

// int main() {
    // int n;
    // cout<<"Enter Decimal Number : ";
    // cin>>n;
    // cout<<"Decimal after Complement of Base 10 : "<<bit(n)<<endl;
//     return 0;
// }






// #include <iostream>
// using namespace std;

// int bitwiseComplement(int n) {
        
//         int m = n;
//         int mask = 0 ;

//         if (n == 0)
//             return 1 ;

//         while(m != 0){
//             mask = (mask << 1) | 1;
//             m = m >> 1;
//         }

//         int ans = (~n) & mask ;

//         return ans ;
//     }

// int main() {
//     int n;
//     cout<<"Enter Decimal Number : ";
//     cin>>n;
//     cout<<"Decimal after Complement of Base 10 : "<<bitwiseComplement(n)<<endl;
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


