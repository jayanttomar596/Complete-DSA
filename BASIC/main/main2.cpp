// #include<iostream>

// int main()
// {
//     std::cout << "Hello , World!" <<std::endl;
//     return 0;
// }    





// #include<iostream>
// using namespace std;

// int main()
// {
//     cout<<"Hello , World !" << std::endl;
// }





// #include<iostream>
// using namespace std;

// int main()
// {
//     int a;
//     // this is declaration of variable a

//     a = 10;
//     // this is initialisation of a 

//     int b = 20 ;
//     //this is definition = declaration + initialisation

//     char a123 = 'a';

//     float c;
//     //this is both declaration and defination 
//     // as 'c' is allocated memory and assigned some garbage value

//     int _c , _d45 , e;
//     cout << a123 << endl; 
// }





// static int a ; //static variable

// int b; // instance variable

// fun()
// {
// int c ; // Local Variable
// }





// #include<iostream>
// using namespace std;

// int main()
// {
//     int num1 = 24;
//     int num2 = 34;

//     int result = num1 + num2;
//     cout << result << endl;
//     return 0; 
// }




// #include<iostream>
// using namespace std;

// class Calculate{
// public:
//     int num1 = 50;
//     int num2 = 30;

//     int addition(){
//         int result = num1 + num2;
//         return result;
//     }
// };

// int main()
// {
//     Calculate add;
//     cout << add.addition() << endl ;
//     return 0 ;
// }




// #include <iostream>
// using namespace std;

// class Calculate{
// public:
//    int num1;
//    int num2;

//    Calculate() : num1(50) , num2(30) {}

//    int addition(){
//     int result = num1 + num2;
//     return result ;
//    } 
// };

// int main()
// {
//     Calculate add;
//     cout << add.addition() <<endl;
//     return 0 ;
// }




// #include<iostream>

// void printvalue()
// {
//     auto int a = 10;
//     printf("%d\n",a);
// }

// int main()
// {
//     printvalue();
//     return 0 ;
// }




// #include<iostream>
// using namespace std;

// int a = 10;

// int main()
// {
//     int b = 9 ;
//     cout << a << " " << b;
//     return 0;
// }




// #include<iostream>
// using namespace std;

// void func()
// {
//     int age = 18 ;
// }

// int main()
// {
//     cout << "Age is : " <<age;
//     return 0;
// }




// #include<iostream>
// using namespace std;

// void func()
// {
//     int age = 18;
//     cout << age;
// }

// int main()
// {
//     cout << "Age is : ";
//     func();
//     cout<<'\n';
// }




// #include<iostream>
// using namespace std;

// // Global variable
// int a = 5;

// int main() {
  
//     // Local variable with same name as that of
//       // global variable
//     int a = 100;
  
//       // Accessing global a
//     cout << ::a;
  
//       return 0;
// }




// #include<iostream>
// using namespace std;

// int a = 5; //global variable

// void func()
// {
//     cout << a << endl;
// }

// int main()
// {
//     int a = 10; // local variable
//     cout << a << endl;
//     func();
//     return 0 ;
// }




// #include<iostream>
// using namespace std;

// int main()
// {
//     const float PI = 3.14 ;
//     cout << "The value of PI is "<<PI<<endl;
//     PI = 3.00 ;// ERROR SINCE CHANGING A CONST IS NOT ALLOWED
// }




// #include <iostream>
// using namespace std;
 
// int main()
// {
//     int a = 4, b = 5;
//     cout << "The value of a + b is " << a + b << endl;
//     cout << "The value of a - b is " << a - b << endl;
//     cout << "The value of a * b is " << a * b << endl;
//     cout << "The value of a / b is " << a / b << endl;
//     cout << "The value of a % b is " << a % b << endl;
//     cout << "The value of a++ is " << a++ << endl;
//     cout << "The value of a-- is " << a-- << endl;
//     cout << "The value of ++a is " << ++a << endl;
//     cout << "The value of --a is " << --a << endl;
// }



// #include<iostream>
// using namespace std;

// int main()
// {
//     int a =4 , b = 5 ;
//     cout << "The value of a == b is " <<(a==b)<<endl;
//     cout << "The value of a < b is " << (a<b) <<endl;
//     cout << "The value of a > b is " << (a>b) <<endl;
// }



// #include <iostream>
// using namespace std;
 
// int main()
// {
//     int a = 1, b = 0;
//     cout << "The value of a && b is " << (a && b) << endl;
//     cout << "The value of a || b is " << (a || b) << endl;
//     cout << "The value of !a is " << (!a) << endl;
// }




// #include <iostream>
// using namespace std;
 
// int main()
// {
//     int a = 13; //1101
//     int b = 5;  //101
//     cout << "The value of a & b is " << (a & b) << endl;
//     cout << "The value of a | b is " << (a | b) << endl;
//     cout << "The value of a ^ b is " << (a ^ b) << endl;
//     cout << "The value of ~a is " << (~a) << endl;
//     cout << "The value of a >> 2 is " << (a >> 2) << endl;
//     cout << "The value of a << 2 is " << (a << 2) << endl;
// }




// #include<iostream>
// #include<iomanip>
// using namespace std;

// int main()
// {
//     float PI = 3.14;
//     int num = 100 ;
//     cout << "Entering a new line."<< endl;
//     cout << setw(10) << "Output" << endl;
//     cout << setprecision(10) << PI << endl;
//     cout << setbase(16) << num << endl;
// }




// #include<iostream>
// using namespace std;

// int main()
// {
//     int num;
//     cout << "Entering a number : ";
//     cin >> num; //Getting input from the user
//     cout << "Your number is : " << num ;
//     // Displaying the input value
//     return 0 ;
// }




// #include<iostream>
// using namespace std;

// int main()
// {
//     int age;
//     cout << "Enter a number : ";
//     cin >> age;
//     if (age > 50)
//     {
//         cout << "Input number is greater than 50 !" <<endl;
//     }
//     else if (age == 50)
//     {
//         cout << "Input number is equal to 50 !" <<endl;
//     }
//     else
//     {
//         cout << "Input number is less than 50 !" <<endl;
//     }
// }




// #include<iostream>
// using namespace std;

// int main()
// {
//     int i = 2;
//     switch(i)
//     {
//         case 1:
//             cout << "Statement 1"<<endl;
//             break;

//         case 2:
//             cout << "Statement 2"<<endl;
//             break;

//         default:
//             cout << "Default statement"<<endl;
//     }
// }




// #include<iostream>
// using namespace std;

// int main()
// {
//     int num = 10 ;
//     for (int i = 0 ; i < num ; i++)
//     {
//         cout << i << " ";
//     }
//     cout<<endl;
//     return 0 ;
// }



// #include<iostream>
// using namespace std;

// int main()
// {
//     int i = 5 ;
//     while (i<10)
//     {
//         cout << i <<" ";
//         i++; 
//     }
//     cout<<endl;
//     return 0;   
// }



// #include <iostream>
// using namespace std;

// int main()
// {
//     int i = 5;
//     do
//     {
//         cout << i <<" ";
//         i++;
//     } while (i < 5);
//     // it executes at least once
//     cout<<endl;
//     return 0 ;    
// }



// #include<iostream>
// using namespace std;

// int main()
// {
//     int num = 10;
//     for (int i = 0 ; i < num ; i++)
//     {
//         if (i == 6)
//         {
//             break;
//         }
//         cout << i <<" ";
//     }
//     cout<<endl;
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main()
// {
//     for (int i = 0 ; i<=10 ; i++)
//     {
//         if (i < 6)
//         {
//             continue;
//         }
//         cout << i <<" ";
//     }
//     cout<<endl;
//     return 0;
// }




// int arr[] = {1,2,3};

// int arr[3];
// arr[0] = 1 , arr[1] = 2 , arr[2] = 3;



// #include<iostream>
// using namespace std;

// int main()
// {
//     int arr[] = {1,2,3};
//     cout << arr[1] <<endl;
//     arr[2] = 8 ; //changing the element on index 2
//     cout << arr[2] <<endl;
//     return 0 ;
// }




// #include<iostream>
// using namespace std;

// int main()
// {
//     int a = 100;
//     cout << "Value of variable a stored at address " <<&a<< " is "<<(*(&a))<<endl;
//     return 0;
// }




// #include<iostream>
// using namespace std;

// int main()
// {
//     int a = 100 ;
//     int *b = &a;
//     int **c = &b;
//     cout << "Value of variable a is "<<a<<endl;
//     cout<<"Address of variable a is "<<b<<endl;
//     cout<<"Address of pointer b is "<<c<<endl;
//     return 0 ;
// }




// #include <iostream>
// using namespace std;

// int main() {
//     int marks[] = {99,100,38};
//     int *p = marks;
//     cout << "The value of marks[0] is " << *p << endl;
//     cout << "The value of marks[1] is " << *(p+1) << endl;
//     cout << "The value of marks[2] is " << *(p+2) << endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int main() {
//     string str = "CodeWithHarry";
//     cout << str << endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;


// struct employee
// {
// int eId;
// char favChar;
// int salary;
// };

//     int main()
//     {
//         struct employee Harry;
//         Harry.eId = 1;
//         Harry.favChar = 'c';
//         Harry.salary = 120000000;
//         cout << "aID of Harry is "<< Harry.eId << endl;
//         cout << "favChar of Harry is " << Harry.favChar << endl;
//         cout << "salary of Harry is " << Harry.salary << endl;
//         return 0 ;
//     }
    




// #include <iostream>
// using namespace std;

// union money
// {
//     int rice;
//     char car[20]; // Fixed-size character array
//     float pounds;
// };

// int main()
// {
//     union money m1;
//     m1.rice = 34;
//     cout << m1.rice << endl;

//     // Use strcpy to set the car name
//     strcpy(m1.car, "Breeza");
//     cout << m1.car << endl;

//     return 0;
// }




// #include<iostream>
// using namespace std;

// union money
// {
//     int rice;
//     char car;
//     float pounds;
// };

// int main()
// {
//     union money m1;
//     m1.rice = 34;
//     cout << m1.rice <<endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;

// enum Meal
// {
//     breakfast,
//     lunch,
//     dinner
// };

// int main() {
//     Meal m1 = dinner;
//     if (m1 == 2)
//     {
//         cout << "The value of dinner is "<<dinner<<endl;
//     }
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int sum(int a, int b);

// int sum(int a,int b)
// {
//     return a + b;
// }

// int main() {
//     int num1 = 5;
//     int num2 = 6;
//     cout << sum(num1,num2) <<endl;
//     return 0;
// }





// #include <iostream>
// using namespace std;

// void swap(int a , int b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// int main() {
//     int x = 5 , y = 6;
//     cout << "The value of x is " << x << " and the value of y is " << y <<endl;
//     swap(x,y);
//     cout << "The value of x is " << x << " and the value of b is " << y <<endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;

// void swap(int *a , int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main() {
//     int x = 5 , y = 6 ;
//     cout << "The value of x is "<<x<<" and the value of y is "<<y<<endl;
//     swap(&x,&y);
//     cout << "The value of x is "<<x<<" and the value of y is "<<y<<endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;

// void swap(int &a,int &b)
// {
//     int temp = a;
//     a = b ;
//     b = temp;
// }

// int main() {
//     int x = 5 , y = 6 ;
//     cout << "The value of x is " << x << " and the value of y is " << y << endl;
//     swap(x, y);
//     cout << "The value of x is " << x << " and the value of y is " << y << endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int factorial(int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return 1;
//     }
//     return n * factorial(n-1);
// }

// int main() {
//     int n ;
//     cin >> n ;
//     cout << "The value of "<<n<<" factorial is "<<factorial(n)<<endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     int remainder ;
//     int temp=0;
//     int x ;
//     cout << "Enter decimal number : " ;
//     cin >> n;
//     x = n ;
//     while (n!=0)
//     {
//         remainder = n%2;
//         temp = temp + remainder*10;
//         n = n / 2; 
//     }
//     cout <<"Decimal "<<x<<" = "<<temp<<" in Binary "<<endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     int remainder;
//     int binary = 0; // Store the binary equivalent
//     int place = 1;  // Track the place value for binary digits (1, 10, 100, ...)
//     int x;

//     cout << "Enter decimal number: ";
//     cin >> n;

//     x = n; // Preserve the original number

//     while (n != 0) {
//         remainder = n % 2;
//         binary += remainder * place; // Update the binary number
//         place *= 10;                // Move to the next place value
//         n /= 2;                     // Reduce the decimal number
//     }

//     cout << "Decimal " << x << " = " << binary << " in Binary" << endl;
//     return 0;
// }







// #include<iostream>
// using namespace std;

// int main(){
//    int n;
//    cout<<"Enter the decimal number: ";
//    cin>>n;
//    int bit=0;
//    int num=0;
//    while(n!=0){
//     bit=n&1;
//     num=num*10+bit;
//     n=n>>1;
//    }
//    cout<<num<<endl;
// }
   








// OOPS


// class class_name
// {

// };

// int main()
// {
//     class_name object_name ;
// }




// #include <iostream>
// using namespace std;

// class Employee
// {
//     public:
//         int eID;
//         string eName;
// };

// int main() {
//     Employee Harry ;
//     Harry.eID = 5;
//     Harry.eName = "Harry";
//     cout << "Employee having ID "<< Harry.eID << " is "<< Harry.eName <<endl;
//     return 0;
// }





// #include <iostream>
// using namespace std;

// class Employee
// {
//     public:
//         int eID;
//         string eName;

//         void printName()
//         {
//             cout << eName << endl;
//         }
// };

// int main() {
//     Employee Harry;
//     Harry.eID = 1234;
//     Harry.eName = "Jayant";
//     Harry.printName();
//     return 0;
// }





// #include <iostream>
// using namespace std;

// class Employee
// {
// public:
//     static int count; 
//     string eName;

//     void setName(string name)
//     {
//         eName = name;
//         count ++;
//     }

//     static int getCount() // static method
//     {
//         return count;
//     }
// };

// int Employee ::count = 0; // defining value of count

// int main() {
//     Employee Harry;
//     Harry.setName("Harry");
//     cout << Employee::getCount() << endl;
//     return 0;
// }





// class class_name
// {
//     friend return_type function_name(arguements);
// };

// return_type class_name::function_name(arguements)
// {

// }




// class class_name
// {
//     friend class friend_class_name;
// };







#include <iostream>
#include<unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size() ;
        int k = value ;

        for (int i = 0 ; i < n ; i++)
        {
            if (nums[i] < 0)
            {
                while(nums[i] < 0)
                {
                    nums[i] += k ;
                }
            }
        }


        unordered_map<int , int> freq ;

        for (int i = 0 ; i < n ; i++)
        {
            freq[nums[i]]++ ;
        }

        int max_val = *max_element(nums.begin(), nums.end());

        sort(nums.begin() , nums.end()) ;
        int ans ;


        for (int i = 0 ; i < n ; i++)
        {
            if (nums[i] == i)
            {
                ans = i ;
            }
            else
            {
                bool check = false ;
                for (int j = i ; j <= max_val ; j = j+k)
                {
                    if (freq.count(j))
                    {
                        ans = i ;
                        freq[j]-- ;
                        if (freq[j] == 0)
                        {
                            freq.erase(j) ;
                        }
                        check = true ;
                        break ;
                    }
                }

                for (int j = i ; j >= 0 ; j = j-k)
                {
                    if (freq.count(j))
                    {
                        ans = i ;
                        freq[j]-- ;
                        if (freq[j] == 0)
                        {
                            freq.erase(j) ;
                        }
                        check = true; 
                        break ;
                    }
                }

                if (!check)
                {
                    ans = i ;
                    return ans ;
                }
            }
        }

        return ans+1 ;
    }
};

int main() {

    vector<int> v = {3,0,3,2,4,2,1,1,0,4} ;
    int value = 5 ;

    Solution s ;

    cout << s.findSmallestInteger(v,value) << endl;
    
    return 0;
}










































