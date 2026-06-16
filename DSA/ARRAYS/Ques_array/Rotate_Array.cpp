// Given an array , rotate the array to the right by k steps , where k is a non negative integer .

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& v , int k)
{
    vector<int> temp(v.size());

    for (int i = 0 ; i < v.size() ; i++)
    {
        temp[(i+k)%v.size()] = v[i];
    }

    //copy temp into num vector
    v = temp;
}

void PrintVector(vector<int> v )
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> v ;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    int k ;
    cout<<"Enter the value of k [positions to rotate] = ";
    cin>>k ;

    PrintVector(v);
    rotate(v,k);
    PrintVector(v);
    return 0;
}