// #include <iostream>
// using namespace std;

// int main()
// {
//     cout << "Hello World";
//     return 0 ;
// }




// #include<iostream>
// using namespace std ;

// int main()
// {
//     cout << "Hello World" << endl;
// }




// #include<iostream>
// using namespace std;

// int main()
// {
//     cout << "Hello World" << endl;
//     cout << "Hello World" << '\n';
//     cout << "Hello World\n" ; 
//     cout << "\n";
// }




// #include<iostream>
// using namespace std;

// int main()
// {
//     int a = 123 ;
//     cout << a << endl;

//     char b = 'v';
//     cout<< b <<endl;

//     bool bl = true ;
//     cout << bl << endl;

//     float f = 1.2;
//     cout << f << endl;

//     double d = 1.23 ;
//     cout << d <<endl;

//     int size = sizeof(a);
//     cout << "Size of a is : " << size <<endl ;
// }




// #include<iostream>
// using namespace std;

// int main()
// // {
// //     int a = 'a';
// //     cout << a<<endl; //It typecaste value of a into int that is its ASCI Value

// //     char ch = 98;
// //     cout << ch <<endl;

// //     char ch1 = 123456;
// //     cout << ch1 <<endl;
// // }
// // {
// //     unsigned int a = 112;

// //     cout << a <<endl;

// //     int b = 2/5;
// //     int c = 2.0/5;
// //     cout << b <<endl;
// //     cout << c << endl;

// //     float d = 2.0/5;
// //     cout << d<<endl;
// // }

// {
//     // int a =2;
//     // int b=3;
//     // bool first = (a==b);
//     // cout << first <<endl;

//     int a = 0;
//     cout << !a <<endl;

// }





// #include <iostream>
// using namespace std;

// int main() {
//     int a;
//     cin >> a;
//     if (a>0)
//     {
//         cout << "A is Positive" <<endl;
//     }
//     else if (a<0){
//         cout <<"A is Negative"<<endl;
//     }
//     else{
//         cout << "A is Zero"<<endl;
//     }
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int main() {
//     int a,b;
//     // cin >> a >>b;

//     a = cin.get();

//     cout << "Value of a and b is "<<a<<" "<< b << endl;
//     return 0;
// }






// #include <iostream>
// using namespace std;

// int main() {
//     int a;
//     cout << "Enter the value of A : "<<endl;
//     cin>>a;

//     if (a>0)
//     {
//         cout<<"A is positive"<<endl;
//     }
//     else{
//         if (a<0){
//             cout <<"A is negative"<<endl;
//         }
//         else{
//             cout<<"A is 0"<<endl;
//         }
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main() {
//     int a = 9 ;
//     if (a==9)
//     {
//         cout << "NINEY";
//     }

//     if (a>0)
//     {
//         cout << "POSITIVE";
//     }
//     else{
//         cout << "NEGATIVE";
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main() {
//     int a = 2;
//     int b = a+1;

//     if ((a=3)==b)
//     {
//         cout << a;
//     }
//     else
//     {
//         cout << a+1;
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//     int a = 24;

//     if (a > 20){
//         cout << "Love ";
//     }
//     else if (a == 24){
//         cout << "Lovely";
//     }
//     else
//     {
//         cout << "Babbar";
//     }
//     cout <<a;
//     return 0;
// }





// #include <iostream>
// using namespace std;

// int main() {
//     char ch;
//     cout<<"Enter value of ch : ";
//     cin>>ch;
//     if (ch>='a' && ch<='z')
//     {
//         cout <<"This is LowerCase case"<<endl;
//     }
//     else if (ch>='A' && ch<='Z')
//     {
//         cout << "This is Upper case"<<endl;
//     }
//     else if (ch>='0' && ch<='9')
//     {
//         cout << "This is Numeric"<<endl;
//     }
//     else{
//         cout << "Try Again"<<endl;
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
//         cout << i <<" ";
//         i++;
//     }
//     cout<<endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int main() {
//     int n ,sum = 0 , i=1;
//     cin>>n;
//     while(i<=n)
//     {
//         sum+=i;
//         i++;
//     }
//     cout << "Sum of first "<<n<<" natural numbers = "<<sum<<endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int sum(int n)
// {
//     if (n==1)
//     {
//         return 1 ;
//     }
//     return n + sum(n-1);
// }

// int main() {
//     int n;
//     cout<<"Enter value of n : ";
//     cin >> n;

//     if (n>0)
//     {
//         cout << "Sum of first "<< n << " natural numbers = "<<sum(n)<<endl;
//     }
//     else{
//         cout << "Enter a positive integer or natural number ."<<endl;
//     }
//     return 0;
// }





// #include <iostream>
// using namespace std;

// int main() {
//     int n ;
//     cout << "Enter value of n : ";
//     cin>>n;
//     int sum = 0;
//     int i = 2;
//     while(i <= n)
//     {
//         sum+=i;
//         i+=2;
//     }
//     cout<<"Sum of all the even numbers upto "<<n<<" = "<<sum<<endl;
//     return 0;
// }





// #include <iostream>
// #include <iomanip> // For formatting the output

// using namespace std;

// int main() {
//     double fahrenheit, celsius;
//     int lower_limit, upper_limit, step;

//     // Input range and step size from the user
//     cout << "Enter the lower limit of Fahrenheit: ";
//     cin >> lower_limit;
//     cout << "Enter the upper limit of Fahrenheit: ";
//     cin >> upper_limit;
//     cout << "Enter the step size: ";
//     cin >> step;

//     // Print the table header
//     cout << left << setw(15) << "Fahrenheit" << "Celsius" << endl;
//     cout << "------------------------" << endl;

//     // Generate the table
//     for (fahrenheit = lower_limit; fahrenheit <= upper_limit; fahrenheit += step) {
//         celsius = (fahrenheit - 32) * 5.0 / 9.0;
//         cout << left << setw(15) << fahrenheit << fixed << setprecision(2) << celsius << endl;
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



// #include <iostream>
// using namespace std;

// int main() {
//     int a = 4;
//     int b = 6;
//     cout<<" a&b "<< (a&b) <<endl;
//     cout<<" a|b "<< (a|b) <<endl;
//     cout<<" ~a "<< ~a <<endl;
//     cout<<" a^b "<< (a^b) <<endl;

//     cout<< (17>>1) <<endl;
//     cout << (17>>2) <<endl;
//     cout<< (19<<1) <<endl;
//     cout<< (21<<2) <<endl;

//     int i = 7 ;

//     cout<<(++i)<<endl;
//     cout<< (i++)<<endl;
//     cout<< (i--)<<endl;
//     cout<< (--i)<<endl;

//     return 0;
// }





// #include <iostream>
// using namespace std;

// int main() {
//     int a = 1;
//     int b = 2;

//     if (a-- > 0 && ++b > 2 )
//     {
//         cout<<"Stage1 - Inside If ";
//     }
//     else{
//         cout<<"Stage2 - Inside else ";
//     }
//     cout<<a<<" "<<b<<endl;
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//     int a  = 1;
//     int b = 2;

//     if (a-- > 0 || ++b > 2)
//     {
//         cout<<"Stage1 - Inside If ";
//     }
//     else{
//         cout<<"Stage 2 - Inside else ";
//     }
//     cout<< a << " " << b << endl;
//     return 0;
// }

//In OR || if 1st statement gets satisfied then 2nd statement didnt executes





// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter value of n : ";
//     cin>>n;

//     int i = 1;
//     for (;;)
//     {
//         if (i <= n){
//             cout<<i<<endl;
//         }
//         else{
//             break;
//         }
//         i++;
//     }
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int main() {
//     for (int a=0 , b=1 ; a>=0 && b>=1 ; a--,b--)
//     {
//         cout<<a<<" "<<b<<endl;
//     }
//     return 0;
// }






// #include <iostream>
// using namespace std;

// int main() {
//     int n ;
//     cout<<"Enter the no of terms of fibonacci series to print : ";
//     cin>>n;

//     int a = 0;
//     int b = 1;
//     int nextNumber = 0 ;

//     for (int i = 1 ; i <= n ; i++)
//     {
//        cout<<nextNumber<<" ";
//        nextNumber = a+b;
//        a=b;
//        b=nextNumber;
//     }
//     cout<<endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int main() {
//     for (int i = 0 ; i <= 5 ; i--)
//     {
//         cout<<i<<" ";
//         i++;
//     }
//     return 0;
// }
//THIS GOES ON WHILE PRINTING 0 




// #include <iostream>
// using namespace std;

// int main() {
//     for (int i=0 ; i < 5; i++)
//     {
//         for (int j = 1 ; j <= 5 ; j++)
//         {
//             cout<<i<<" "<<j<<endl;
//         }
//     }
//     return 0;
// }





// #include <iostream>
// using namespace std;

// int main() {
//     for (int i = 0 ; i < 5 ; i++)
//     {
//         for (int j = i ; j <= 5 ; j++)
//         {
//             if (i+j == 10){
//                 break;
//             }
//             cout<<i << " "<<j<<endl;
//         }
//     }
//     return 0;
// }





// #include <iostream>
// using namespace std;

// int main() {
//     int a = 3 ;
//     cout<< a <<endl;

//     if (true){
//         int a = 5 ;
//         cout<< a <<endl;
//     }
//     if (true){
//         int b = 7 ;
//         cout<<b<<endl;
//     }

//     cout<<a<<endl;
   
//     return 0;
// }





// Reverse Int

// #include <iostream>
// using namespace std;

// int reverse(int x){

//     int ans=0;
//     while(x != 0){
//         int digit = x %10;

//         if ((ans > INT_MAX /10) || (ans < INT_MIN/10)){
//             return 0 ;
//         }
//         ans = (ans*10) + digit;
//         x/=10;
//     }
//     return ans;
// }

// int main() {
//     int n;
//     cout<<"Enter Number to Reverse : ";
//     cin>>n;
//     cout<<"Reverse No : "<<reverse(n)<<endl;
//     return 0;
// }







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
//     int n;
//     cout<<"Enter Decimal Number : ";
//     cin>>n;
//     cout<<"Decimal after Complement of Base 10 : "<<bit(n)<<endl;
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









// POWER OF 2

// #include <iostream>
// using namespace std;

// bool isPowerOfTwo(int n) {
//     for (int i = 0 ; i <= 30 ; i++){
//         int ans = pow(2,i);

//         if (ans == n){
//             return true ;
//         }
//     }
//     return false;
// }

// bool isPowerOfTwo_2(int n) {
//     int ans = 1 ;
//     for (int i = 0 ; i <= 30 ; i++){

//         if (ans == n){
//             return true ;
//         }
//         if (ans<INT_MAX/2)
//         ans = 2 * ans;
//     }
//     return false;
//     }


// int main() {
//     int n ;
//     cout<<"Enter number : ";
//     cin>>n;
//     cout<<"Result : "<<isPowerOfTwo(n)<<endl;
//     return 0;
// }








// #include <iostream>
// using namespace std;

// int main() {
//     char ch = '1';
//     int num = 1;

//     cout<<endl;

//     switch(ch){
        
//         case 1: cout<<"First"<<endl;
//                   cout<<"First again"<<endl;
//                   break;

//         case '1': switch(num){
//             case 1: cout<<"Value of num is "<<num<<endl;
//             break;
//         }
//         break;     

//         default: cout<<"It is default case"<<endl;        
//     }
//     return 0;
// }









// MINI CALCULATOR

// #include <iostream>
// using namespace std;

// int main() {
//     int a , b;

//     cout<<"Enter the value of a : ";
//     cin>>a;

//     cout<<"Enter the value of b : ";
//     cin>>b;

//     char op;
//     cout<<"Enter the Operation you want to perform : ";
//     cin>>op;

//     switch(op){
//         case '+':cout<<(a+b)<<endl;
//                  break;

//         case '-':cout<<(a-b)<<endl;
//                  break;

//         case '*':cout<<(a*b)<<endl;
//                  break;

//         case '/':cout<<(a/b)<<endl;
//                  break;

//         case '%':cout<<(a%b)<<endl;
//                  break;          
//         default:cout<<"Please enter a Valid Operation"<<endl;
//     }

//     return 0;
// }






// HOW WILL YOU EXIT IF YOU PUT SWITCH CASE INSIDE INFINITE LOOP AND WHEN YOU CAN'T USE SWITCH STATEMENT?

// #include <iostream>
// #include <stdlib.h>
// using namespace std;
// int main()
// {

// //this while condition will always be true if exit( is not put.)
// while(1)
// {
//   cout<<"HOW YOU DOIN????"<<endl;

//   int num=1;
//   switch(num)
//   {
//     case 1: cout<<"I'M FINE"<<endl;
//     break;
//   }
//   exit(0);
// }
// }





// #include <iostream>
// using namespace std;

// int main() {
//     int amount;
//     cout<<"Enter the amount : ";
//     cin>>amount;
//     int Rs100 , Rs50 , Rs20 , Rs1 ;

//     switch(1)
//     {
//         case 1 : Rs100 = amount/100;
//                  amount = amount%100;
//                  cout<<"No of 100 Rupee notes required are = "<<Rs100<<endl;

//         case 2 : Rs50 = amount/50;
//                  amount = amount%50;
//                  cout<<"No of 50 Rupee notes required are = "<<Rs50<<endl;

//         case 3 : Rs20 = amount/20;
//                  amount = amount%20;
//                  cout<<"No of 20 Rupee notes required are = "<<Rs20<<endl;

//         case 4 : Rs1 = amount/1;
//                  amount = amount%1;
//                  cout<<"No of 1 Rupee notes required are = "<<Rs1<<endl;                 
//     }
//     return 0;
// }






//POW

// #include <iostream>
// using namespace std;

// int main() {
//     int a,b;
//     cin>>a>>b;

//     int ans = 1;

//     for (int i = 1 ; i <= b ;i++)
//     {
//         ans = ans*a;
//     }
//     cout<<"Answer is : "<<ans<<endl;

//     return 0;
// }






// POWER (a,b)

// #include <iostream>
// using namespace std;

// int power(int a , int b)
// {
//     int ans = 1;

//     for (int i = 1 ; i <= b ; i++)
//     {
//         ans *= a ;
//     }
//     return ans ;
// }

// int main() {
    
//     int a ,b;
//     cout<<"Enter value of Base : ";
//     cin>>a;
//     cout<<"Enter value of Exponent : ";
//     cin>>b;

//     cout<<"Power(a,b) : "<<power(a,b)<<endl;
//     return 0;
// }








// Even Odd Program

// #include <iostream>
// using namespace std;

// //1-> Even
// //0-> Odd
// bool isEven(int a){
//     //Odd
//     if(a&1){
//         return 0 ;
//     }
//     else{ //Even
//         return 1;
//     }
// }

// int main() {
    
//     int num ;
//     cout<<"Enter Number : ";
//     cin>>num;

//     if (isEven(num)){
//         cout<<"Number is Even"<<endl;
//     }
//     else{
//         cout<<"Number is Odd"<<endl;
//     }
//     return 0;
// }







// nCr 

// #include <iostream>
// using namespace std;

// int factorial(int n)
// {
//     int fact = 1;

//     for (int i = 1 ; i <= n ; i++)
//     {
//         fact *= i ;
//     }
//     return fact ; 
// }

// int nCr(int n , int r)
// {
//     int num = factorial(n);

//     int denom = factorial(r) * factorial(n-r) ;

//     int ans = num / denom ; 

//     return ans ;
// }

// int main() {
//     int n , r ;
//     cout<<"To Get value of nCr ."<<endl;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     cout<<"Enter the value of r : ";
//     cin>>r ;
//     cout<<"Value of nCr = "<<nCr(n,r)<<endl;
//     return 0;
// }






//COUNTING PROGRAM

// #include <iostream>
// using namespace std;

// //Function Signature
// void printCounting(int n){

//     //Function Body
//     for (int i = 1 ; i <= n ; i++)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
// }

// int main() {
    
//     int n;
//     cout<<"Enter value of n : ";
//     cin>>n;

//     //Function Call
//     printCounting(n);
//     return 0;
// }






// #include <iostream>
// using namespace std;

// int Prime(int n)
// {
//     for (int i = 2 ; i < n ; i++)
//     {
//         if (n%i == 0)
//         {
//             return 0 ;
//         }
//     }
//     return 1 ;
// }

// int main() {
//     int n;
//     cout<<"Enter the value of n : ";
//     cin>>n;
//     if (Prime(n))
//     {
//         cout<<n<<" is a Prime Number"<<endl;
//     }
//     else{
//         cout<<n<<" is not a Prime Number"<<endl;
//     }
//     return 0;
// }
















