
// Given an array of integers and a position M , You have to reverse the array after that position .

#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse_after_pos(vector<int> v , int pos)
{
    int s = pos + 1 , e = v.size() - 1 ;

    while (s<=e)
    {
        swap(v[s],v[e]);
        s++;
        e--;
    } 
    return v;
}

vector<int> reverse(vector<int> v)
{
    int s = 0 , e = v.size() - 1 ;

    while(s<=e)
    {
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v ;
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
    
    vector<int> v;

    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);

    int n ;
    cout<<"Enter the index (position) after that reverse = ";
    cin>>n;

    PrintVector(v);

    vector<int> ans = reverse_after_pos(v,n);

    PrintVector(ans);

    return 0;
}