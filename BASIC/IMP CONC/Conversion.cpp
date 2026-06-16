
// DECIMAL TO BINARY

// #include <iostream>
// #include<math.h>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter Decimal Number : ";
//     cin>>n;

//     int ans = 0 ;
//     int i = 0 ;
//     while (n != 0)
//     {
//         int bit = n & 1 ;

//         ans = (bit * pow(10,i)) + ans;
//         n = n >> 1;
//         i++;
//     }

//     cout<<"In Binary Conversion : "<<ans<<endl;
    
//     return 0;
// }








// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter Decimal Number: ";
//     cin >> n;

//     string binary = "";

//     while (n != 0) {
//         int bit = n & 1;
//         binary = to_string(bit) + binary; // Prepend the bit
//         n = n >> 1;
//     }

//     cout << "In Binary Conversion: " << binary << endl;

//     return 0;
// }







// BINARY TO DECIMAL

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter Binary Number : ";
//     cin>>n;

//     int i = 0,ans= 0 ;

//     while(n != 0)
//     {
//         int digit = n%10;
//         if (digit == 1){
//             ans +=  pow(2,i);
//         }
//         n = n/10;
//         i++;
//     }
//     cout<<"In Decimal Conversion : "<<ans<<endl;
//     return 0;
// }








// NEGATIVE DECIMAL TO BINARY

// #include <iostream>
// #include <math.h>
// using namespace std;

// int main() {
//     long long int n;
//     cin>>n;
//     unsigned long long int i = 0 , ans = 0 ;

//     if (n < 0){
//         n = pow(2,16) +n;
//     }
//     // cout<<n<<endl;
//     while(n){
//         int lastBit = n & 1;
//         ans = (pow(10,i) * lastBit) + ans;
//         n = n >>1;
//         i++;
//         // cout<<ans<<endl;
//     }
//     cout<<ans<<endl;
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



