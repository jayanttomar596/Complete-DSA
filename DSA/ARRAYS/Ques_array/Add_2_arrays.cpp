//You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of length 'N' and 'M' respectively , where each array element represents a digit . You need to find the sum of these two numbers and return this sum in the form of an array .

#include <iostream>
#include <vector>
using namespace std;


vector <int> reverse(vector<int> v)
{
    int s = 0 ;
    int e = v.size() - 1 ;

    while (s<e)
    {
        swap(v[s++],v[e--]);
    }
    return v ;
}


vector<int> findArraySum(vector<int> a  , vector<int> b )
{
    int i = a.size() - 1 ;
    int j = b.size() - 1 ; 
    vector<int> ans;
    int carry = 0 ;

    while (i>=0 && j>=0)
    {
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry ;

        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }

    //first case
    while (i >= 0)
    {
        int sum = a[i] + carry ;
        carry = sum/10 ;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }

    //second case
    while (j >= 0)
    {
        int sum = b[j] + carry ;
        carry = sum/10;
        sum = sum%10 ;
        ans.push_back(sum);
        j--;
    }

    //third case
    while (carry != 0)
    {
        int sum = carry ;
        carry = sum/10 ;
        sum = sum%10 ;
        ans.push_back(sum);
    }

    return reverse(ans) ;
}


void PrintVector(vector<int> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


int main() {
    vector<int> a;
    a.push_back(4);
    a.push_back(5);
    a.push_back(1);

    vector<int> b;
    b.push_back(9);
    b.push_back(4);
    b.push_back(5);

    cout<<"Vector a :"<<endl;
    PrintVector(a);
    cout<<"Vector b :"<<endl;
    PrintVector(b);

    vector<int> sum = findArraySum(a,b);
    cout<<endl<<"Sum : "<<endl;
    PrintVector(sum);

    return 0;
}