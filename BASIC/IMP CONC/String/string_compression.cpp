
/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0 ;
        int ansIndex = 0 ;
        int n = chars.size();

        while (i<n)
        {
            int j = i + 1 ;
            while (j<n && chars[i] == chars[j])
            {
                j++;
            }
            //yaha tak aaoge
            //ya toh vector poora traverse kardia
            //ya fer new/Different character encounter kia hai

            //old char store karlo
            chars[ansIndex++] = chars[i];

            int count = j - i ;

            if (count > 1)
            {
                //converting counting into single digit and saving in answer
                string cnt = to_string(count);
                for (char ch : cnt)
                {
                    chars[ansIndex++] = ch ;
                }
            }
            //moving to new/Different Character
            i = j ;
        }

        //char.size() might return more than the actual compressed size is because the size of the chars vector does not automatically shrink or adjust when you overwrite its elements in place . In your function , you modify the contents of the vector up to ansIndex , but the original chars.size() remains unchanged .
        return ansIndex ;
    }   
};

void PrintVector(vector<char> v , int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main() {
    Solution sol;

    vector<char> chars ;
    chars.push_back('a'); 
    chars.push_back('a'); 
    chars.push_back('b'); 
    chars.push_back('b'); 
    chars.push_back('c'); 
    chars.push_back('c'); 
    chars.push_back('c');

    int size_comressed_vector = sol.compress(chars);

    cout<<"SIZE OF THE ARRAY MADE AFTER COMPRESSION = "<<size_comressed_vector<<endl;


    cout<<"Array made after compression :"<<endl;
    
    // PrintVector ka function bhi isiliye modify kiya kyoki chars jitna compressed ka size hai utna toh modify kar diya par bakki vahi hai toh size dena padega 
    PrintVector(chars,size_comressed_vector);


    return 0;
}
