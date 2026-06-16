// CHECK PALINDROME 


// #include <iostream>
// using namespace std;

// char toLowerCase(char ch)
// {
//     if (ch >= 'a' && ch <= 'z')
//         return ch;
//     else{
//         char temp = ch - 'A' + 'a';
//         return temp;
//     }    
// }

// bool checkPalindrome(char a[] , int n)
// {
//     int s = 0 ;
//     int e = n-1 ;

//     while (s<=e)
//     {
//         if (toLowerCase(a[s]) != toLowerCase(a[e]))
//         {
//             return 0 ;
//         }
//         else{
//             s++;
//             e--;
//         }
//     }
//     return 1 ;
// }

// int getLength(char name[])
// {
//     int count = 0 ;
//     for (int i = 0 ; name[i] != '\0' ; i++)
//     {
//         count++;
//     }
//     return count ;
// }

// int main() {
//     char name[20] ;
//     cout<<"Enter your char array : ";
//     cin>>name ;

//     int len = getLength(name);
//     cout<<"Lenght : "<<len<<endl;

//     cout<<"Palindrome or Not : "<<checkPalindrome(name,len)<<endl;

//     return 0;
// }


// par isme yeh N and n ko alag alag treat kar rha hai toh uska solution btata hu !!
// toh isilye maine baad me code me ek naya function laya 
// special character or spaces vagera ke liye kya change hoga socho









// VALID PALINDROME - LEETCODE
// remove non aplphanumeric characters and do lowercase then check palindrome


#include <iostream>
#include <string>
using namespace std;

class Solution {
private :
    bool valid(char ch){
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return 1 ;
        }
        return 0 ;
    }

    char toLowerCase(char ch){
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            return ch ;
        }
        else
        {
            char temp = ch - 'A' + 'a' ;
            return temp ;
        }
    }

    bool checkPalindrome(string a)
    {
        int s = 0 ;
        int e = a.length() -1 ;

        while (s<=e)
        {
            if (a[s] != a[e])
            {
                return 0 ;
            }
            else
            {
                s++;
                e--;
            }
        }
        return 1 ;
    }

public:
    bool isPalindrome(string s) {
        
        // faltu character hatado
        string temp = "" ;

        for (int j = 0 ; j < s.length() ; j++)
        {
            if (valid(s[j])){
                temp.push_back(s[j]);
            }
        }

        // lowercase me kardo
        for (int j = 0 ; j<temp.length() ; j++)
        {
            temp[j] = toLowerCase(temp[j]);
        }

        //check palindrome
        return checkPalindrome(temp) ;
    }
};

int main() {
    string s ;
    cout<<"Enter string : ";
    cin>>s;

    Solution sol ;
    bool result  = sol.isPalindrome(s);

    if (result)
    {
        cout<<"This string is Palindrome"<<endl;
    }
    else{
        cout<<"This string is not Palindrome"<<endl;
    }
    return 0;
}




