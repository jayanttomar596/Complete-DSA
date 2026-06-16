// B. Kevin and Permutation (Codeforces)

// For his birthday, Kevin received the set of pairwise distinct numbers 1,2,3,…,𝑛
//  as a gift.

// He is going to arrange these numbers in a way such that the minimum absolute difference between two consecutive numbers be maximum possible. More formally, if he arranges numbers in order 𝑝1,𝑝2,…,𝑝𝑛 , he wants to 
// maximize the value min|𝑝𝑖+1−𝑝𝑖| from i = 1 to n-1 , where |𝑥| denotes the absolute value of 𝑥 .

#include <iostream>
#include <vector>
using namespace std;


vector<int> kevin_permutation(int n)
{
    vector<int> ans ;
    int first_half = 1 ;
    int second_half = n/2 + 1 ;

    while(ans.size() != n)
    {
        ans.push_back(second_half++);
        ans.push_back(first_half++);
    }
    cout<<"Max of min|Pi+1 - Pi| = "<<ans[0]-ans[1]<<endl;

    return ans ;
}


void Print_Vector(vector<int> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


int main() {
    int n ;
    cout<<"Enter the value of n = ";
    cin>>n;

    vector<int> ans = kevin_permutation(n);
    Print_Vector(ans);

    return 0;
}