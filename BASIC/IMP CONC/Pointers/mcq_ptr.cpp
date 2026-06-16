#include <iostream>
using namespace std;

void update (int* p)
{
    *p = (*p) * 2 ;
}

void increment(int **p)
{
    ++(**p);
}


int main() {
    
    // Ques - 1 

    // int first = 8 ;
    // int second = 18 ;
    // int *ptr = &second ;
    // *ptr = 9 ;
    // cout<< first <<" "<<second << endl;




    // Ques - 2

    // int first = 6 ;
    // int *p = &first ;
    // int *q = p ;
    // (*q)++;
    // cout << first << endl;
 /*
 A pointer q of type int* is declared and initialized to store the value of p . Since p holds the address of first , q also now points to first . Now , both p and q point to sam ememory location (address of first ) */
    



    // Ques - 3
    
    // int first = 8 ;
    // int *p = &first ;
    // cout<< (*p)++ <<" ";
    // cout<< first << endl;




    // Ques - 4

    // int *p = 0 ;
    // int first = 110 ;
    // *p = first ;
    // cout<< *p << endl;
    // Output - Segmentation Fault




    // Ques - 5

    // int first = 8;
    // int second = 11 ;
    // int *third = &second ;
    // first = *third ;
    // *third = *third + 2 ;
    // cout<< first <<" "<<second << endl;




    // Ques - 6

    // float f = 12.5 ;
    // float p = 21.5 ;
    // float *ptr = &f ;
    // (*ptr)++;
    // *ptr = p ; 
    // cout<< *ptr << " "<<f << " "<< p << endl;




    // Ques - 7 

    // int arr[5];
    // int *ptr ;
    // cout<<sizeof(arr)<<" "<<sizeof(ptr)<<endl;




    // Ques - 8 
    
    // int arr[] = {11,21,13,14};
    // cout<<*(arr)<<" "<<*(arr+1)<<endl;
    // cout<<arr<<" "<<&arr<<" "<<&arr[0]<<endl;




    // Ques - 9 

    // int arr[6] = {11,21,13};
    // cout<<(arr+1)<<endl;
    // cout<<&arr[1]<<endl;




    // Ques - 10

    // int arr[6] = {11,21,31};
    // int *p = arr;
    // cout << p[2] << endl;
    // Output : 31




    // Ques - 11

    // int arr[] = {11,21,31,41};
    // int *ptr = arr++ ;
    // cout<< *ptr << endl;
    // Error - arr = arr + 1 nahi kar sakrte ptr me kar sakte hai 




    // Ques - 12

    // char ch = 'a';
    // char* ptr = &ch ;
    // ch++;
    // cout<< *ptr << endl;




    // Ques - 13
    
    // char arr[] = "abcde";
    // char* p = &arr[0];
    // cout << p << endl;




    // Ques - 14

    // char arr[] = "abcde";
    // char *p = &arr[0];
    // p++ ;
    // cout << p << endl;




    // Ques - 15

    // char str[] = "babbar";
    // char *p = str ;
    // cout << str[0] << " " << p[0] << endl;




    // Ques - 16

    // int i = 10 ;
    // update(&i);
    // cout<<i<<endl;




    // Ques - 17

    // int first = 110 ;
    // int *p = &first ;
    // int **q = &p ;
    // int second = (**q)++ + 9 ;
    // cout<<first<<" "<<second<<endl;
    // Ouput : 111 119




    // Ques - 18

    // int first = 100 ;
    // int *p = &first ;
    // int **q = &p;
    // int second = ++(**q);
    // int *r = *q ;
    // ++(*r);
    // cout<< first <<" "<<second <<endl;




    // Ques - 19
    
    // int num = 110 ;
    // int *ptr = &num ;
    // increment(&ptr);
    // cout<<num<<endl;


    return 0;
}