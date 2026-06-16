//Unique Number of Occurences

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    int i = 0 ;
    sort(arr.begin(),arr.end());
    vector<int> ans;
    while (i < arr.size()){
        int count = 1 ;
        for (int j = i + 1 ; j < arr.size() ; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        ans.push_back(count);
        i+=count;
    }
    sort(ans.begin() , ans.end());
    for (int i = 0 ; i < ans.size() - 1 ; i++)
    {
        if (ans[i] == ans[i+1])
                return false ;            
    }
    return true ;    
}

int main() {
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    if (uniqueOccurrences(arr)) {
        cout << "True: All occurrences are unique" << endl;
    } 
    else {
        cout << "False: Occurrences are not unique" << endl;
    }
    return 0;
}