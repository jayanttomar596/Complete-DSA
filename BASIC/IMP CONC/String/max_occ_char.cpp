
#include <iostream>
#include <string>
using namespace std;

char getMaxCharacter(string s)
{
    //create an array of count of characters
    int arr[26] = {0};
    
    for (int i = 0 ; i < s.length() ; i++)
    {
        char ch = s[i];

        //lowercase
        int number = 0 ;
        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        //uppercase
        else
        {
            number = ch - 'A';
        }
        arr[number]++;
    }
    int maxi = - 1, ans = 0 ;
    for (int i = 0 ; i < 26 ; i++)
    {
        if (maxi < arr[i])
        {
            ans = i ;
            maxi = arr[i];
        }
    }
    char finalAns = 'a'+ans;
    return finalAns ;
}


// agar mai assume karu ki sirf lowercase walle diye gaye hai then :
char getMaxOccCharacter(string s) {

    int arr[26] = {0};


    //create an array of count of characters
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        //lowercase
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }

    //find maximum occ character
    int maxi = -1, ans = 0;
    for(int i=0;i<26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }
    

    return 'a'+ans;

}


int main() {
    string s ;
    cout<<"Enter the string to check max occurance character : ";
    cin>>s;

    cout<<"Max Occurance Character = "<<getMaxCharacter(s)<<endl;
    return 0;
}