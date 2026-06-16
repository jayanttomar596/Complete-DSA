// #include <iostream>
// using namespace std;

// int main() {

//     int n;
//     cout<<"Enter the value of n = ";
//     cin>>n;

//     int i = 1;

//     while(i<=n)
//     {
//         int j = 1;
//         while(j<=n)
//         {
//             cout << "* ";
//             j = j+1;
//         }
//         cout<<endl;
//         i = i+1;
//     }
//     return 0;
// }







// #include <iostream>
// using namespace std;

// int main() {

//     int n;
//     cin>>n;

//     int i = 1;

//     while(i<=n)
//     {
//         int j = 1;
//         while(j<=n)
//         {
//             cout << i<<" ";
//             j = j+1;
//         }
//         cout<<endl;
//         i = i+1;
//     }
//     return 0;
// }







// 1 2 3 4
// 1 2 3 4
// 1 2 3 4 
// 1 2 3 4

// #include <iostream>
// using namespace std;

// int main() {
//     int n ;
//     cout << "Enter value of n / no of rows : ";
//     cin >> n ; 
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <=n ; j++)
//         {
//             cout << j <<" ";
//         }
//         cout << endl;
//     }
//     return 0;
// }







// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     int i = 1;
//     while (i<=n)
//     {
//         int j = 1;
//         while(j<=n)
//         {
//             cout<<j<<" "; //for reverse n-j-1
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }
//     return 0;
// }







// 1 2 3 
// 4 5 6 
// 7 8 9

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 0 ; i < n ; i++)
//     {
//         for (int j = 1 ; j <= n ; j++)
//         {
//             cout << j + n*i <<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin>>n;

//     int i = 1;
//     int count = 1;
//     while(i<=n)
//     {
//         int j = 1;
//         while(j<=n)
//         {
//             cout<<count<<" ";
//             count++;
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }
//     return 0;
// }








// *
// * *
// * * *
// * * * *

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter no of lines to print : ";
//     cin>>n;
//     for (int i = 1 ; i<=n ; i++)
//     {
//         for (int j= 1 ; j <=i ; j++)
//         {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// 1
// 2 2
// 3 3 3 
// 4 4 4 4 

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j<=i ; j++)
//         {
//             cout << i <<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter value of n : ";
//     cin>>n;
//     int i = 1;
//     while(i<=n)
//     {
//         int j = 1;
//         while(j<=i)
//         {
//             cout<<i<<" ";
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }
//     return 0;
// }







// 1
// 2 3
// 4 5 6
// 7 8 9 10

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     int count = 1;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j<=i ; j++)
//         {
//             cout<<count<<" ";
//             count++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// 1
// 2 3
// 3 4 5 
// 4 5 6 7

// #include <iostream>
// using namespace std;

// int main() {
//     int n,value;
//     cout<<"Enter value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         value = i;
//         for (int j = 1 ; j <= i ; j++)
//         {
//             cout<<value<<" ";
//             value++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//     int n,value;
//     cout<<"Enter value of n : ";
//     cin>>n;
//     for (int i = 0 ; i < n ; i++)
//     {
//         for (int j = 1 ; j <= i+1 ; j++)
//         {
//             cout<<j + i<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// 1
// 2 1 
// 3 2 1
// 4 3 2 1

// 1
// 1 2 
// 1 2 3
// 1 2 3 4

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter value of n : ";
//     cin>>n;
//     for (int i = 1 ; i<=n ; i++)
//     {
//         for (int j = i ; j>=1 ; j--)
//         {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter value of n : ";
//     cin>>n;
//     int i = 1;
//     while (i<=n)
//     {
//         int j = i;
//         while(j>=1)
//         {
//             cout<<j<<" ";
//             j--;
//         }
//         cout<<endl;
//         i++;
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter value of n : ";
//     cin>>n;

//     int i = 1;
//     while(i <= n)
//     {
//         int j = 1 ;
//         while(j <= i)
//         {
//             cout<<i-j+1<<" ";
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }
//     return 0;
// }







// A A A 
// B B B 
// C C C

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter value of n : ";
//     cin>>n ;
//     char ch = 'A';
//     for (int i = 0 ; i < n ; i++)
//     {
//         for (int j = 1 ; j <= n ; j++)
//         {
//             cout << char(ch+i) <<" ";   
//         }
//         cout<<endl;
//     }
//     return 0;
// }






// A B C 
// A B C
// A B C

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     char ch = 'A';
//     for (int i = 1 ; i <=n ; i++)
//     {
//         for (int j = 0 ; j < n ; j++)
//         {
//             cout<<char(ch+j)<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// A B C 
// D E F
// G H T

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     char ch = 'A';
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= n ; j++)
//         {
//             cout<<ch<<" ";
//             ch++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }








// A B C
// B C D
// C D E

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     char ch = 'A';
//     for (int i = 0; i < n ; i++)
//     {
//         for (int j = 0 ; j < n ; j++)
//         {
//             cout<<char('A'+j+i)<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// A
// B B 
// C C C 

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     char ch = 'A';
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= i ; j++)
//         {
//             cout<<char('A'+i-1)<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// A
// B C 
// D E F 
// G H I J 

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter value of n : ";
//     cin>>n;
//     char ch = 'A';
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= i ; j++)
//         {
//             cout<<ch<<" ";
//             ch++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// A 
// B C 
// C D E 
// D E F G

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= i ; j++)
//         {
//             cout<<char('A'+i+j-2)<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// D 
// C D 
// B C D 
// A B C D 

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= i ; j++)
//         {
//             cout<<char('A'+n+j-i-1)<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







//       *
//     * *
//   * * *
// * * * *

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= n-i ; j++)
//         {
//             cout<<"  ";
//         }
//         for (int k = 1 ; k <= i ; k++)
//         {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// * * * *
// * * *
// * *
// *

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= n-i+1 ; j++)
//         {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// * * * *
//   * * *
//     * *
//       *

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <=n ; i++)
//     {
//         for (int j = 1 ; j <= i-1 ; j++)
//         {
//             cout<<"  ";
//         }
//         for (int k = 1 ; k <= n-i+1 ; k++)
//         {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// 1 1 1 1
//   2 2 2
//     3 3
//       4

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= i - 1 ; j++)
//         {
//             cout<<"  ";
//         }
//         for (int k = 1 ; k <= n-i+1 ; k++)
//         {
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







//       1
//     2 2
//   3 3 3
// 4 4 4 4

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1  ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= n-i ; j++)
//         {
//             cout<<"  ";
//         }
//         for (int k = 1 ; k <= i ; k++)
//         {
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// 1 2 3 4
//   2 3 4
//     3 4
//       4

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= i-1 ; j++)
//         {
//             cout<<"  ";
//         }
//         for (int k = i ; k <= n ; k++)
//         {
//             cout<<k<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







//       1
//     2 3
//   4 5 6
// 7 8 9 10

// #include <iostream>
// using namespace std;

// int main() {
//     int n , count = 1;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= n-i ; j++)
//         {
//             cout<<"  ";
//         }
//         for (int k = 1 ; k <= i ; k++)
//         {
//             cout<<count<<" ";
//             count++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }







//       1
//     1 2 1
//   1 2 3 2 1
// 1 2 3 4 3 2 1

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i<=n ; i++)
//     {
//         for (int j = 1 ; j <= n-i ; j++)
//         {
//             cout<<"  ";
//         }
//         for (int k = 1 ; k <= i ; k++)
//         {
//             cout<<k<<" ";
//         }
//         for (int l = 1 ; l <= i-1 ; l++)
//         {
//             cout<<i-l<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// 1 2 3 4 5 5 4 3 2 1
// 1 2 3 4 * * 4 3 2 1
// 1 2 3 * * * * 3 2 1
// 1 2 * * * * * * 2 1
// 1 * * * * * * * * 1

// #include <iostream>
// using namespace std;

// int main() {
//     int n ;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         for (int j = 1 ; j <= n-i+1 ; j++)
//         {
//             cout<<j<<" ";
//         }
//         for (int k = 1 ; k <= 2*(i-1) ; k++)
//         {
//             cout<<"* ";
//         }
//         for (int l = n-i+1 ; l >= 1 ; l--)
//         {
//             cout<<l<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }






// * * * * * * *
// *           *
// *           *
// *           *
// *           *
// *           *
// * * * * * * *

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         if (i==1 || i==n)
//         {
//             for (int j = 1 ; j <= n ; j++)
//             {
//                 cout<<"* ";
//                 continue;
//             }
//         }
//         if (i>1 and i<n)
//         {
//             cout<<"* ";
//             for (int k = 1 ; k <= n-2 ; k++)
//             {
//                 cout<<"  ";
//             }
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }







// * * * * * * *
// * *       * *
// *   *   *   *
// *     *     *
// *   *   *   *
// * *       * *
// * * * * * * *

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter the size of the square (n >= 3): ";
//     cin >> n;

//     if (n < 3) {
//         cout << "Size must be at least 3." << endl;
//         return 0;
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             // Print '*' for borders or diagonals
//             if (i == 0 || i == n - 1 || j == 0 || j == n - 1 || i == j || j == n - i - 1) {
//                 cout << "* ";
//             } else {
//                 cout << "  "; // Print space for other cells
//             }
//         }
//         cout << endl; // Move to the next line
//     }

//     return 0;
// }


