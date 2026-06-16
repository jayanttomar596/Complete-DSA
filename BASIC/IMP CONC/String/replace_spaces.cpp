
// You have been given a string 'STR' of words . You need to replace the spaces between words with "@40" 

#include <iostream>
#include <string>
using namespace std;

string replace_spaces(string &str)
{
    string temp = "";

    for (int i = 0 ; i < str.length() ; i++)
    {
        if (str[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else{
            temp.push_back(str[i]);
        }
    }
    return temp ;
}

int main() {
    string s ;
    cout<<"Enter a string with spaces : ";
    getline(cin,s);
    cout<<replace_spaces(s)<<endl;
}


// ab socho replace_spaces me nayi string banane ke bajay ussi string me kar skate hai kya ?? --- kaise ?

// space complexity - O(1) KARO ABHI O(n) hai