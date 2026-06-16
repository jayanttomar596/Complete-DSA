// Maximum Frequency


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;



int maximumFrequency(vector<int> &arr)
{
    unordered_map<int , int> count ;

    int maxAns = 0 ;
    int maxFreq = 0 ;

    for (int i = 0 ; i < arr.size() ; i++)
    {
        count[arr[i]]++ ;
        maxFreq = max(maxFreq , count[arr[i]]) ;
    }


    for (int i = 0 ; i < arr.size() ; i++)
    {
        if (maxFreq == count[arr[i]])
        {
            maxAns = arr[i] ;
            break ;
        }
    }    

    return maxAns ;
}




void print_vector(vector<int> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}




int main() {
    vector <int> v = {1,2,3,4,1,1,5,2,3} ;

    cout << "\nVector : ";
    print_vector(v) ;

    int max = maximumFrequency(v) ;

    cout << "\nElement with max Freqency = " << max << endl << endl;
    

    return 0;
}