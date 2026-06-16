// Fractional Knapsack






/*

Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Examples :

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 

*/








#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;







// Time Complexity: O(n log n)

// Space Complexity: O(n)








// class implemented

class Item{
    public :
    int value;
    int weight;
    
    Item(int v , int w)
    {
        value = v ;
        weight = w ;
    }
};


class Solution {
    // Function to get the maximum total value in the kanpsack
    static bool cmp(pair<double , Item> a , pair<double , Item> b)
    {
        return a.first > b.first ;
    }
    
  public:

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        vector<pair<double , Item>> v ;
        int n = val.size() ;
        
        for (int i = 0 ; i < n ; i++)
        {
            double perUnitValue = (1.0*val[i])/(wt[i]) ;
            Item Node(val[i] , wt[i]) ;
            pair<double , Item> p = make_pair(perUnitValue , Node) ;
            v.push_back(p) ;
        }
        
        sort(v.begin() , v.end() , cmp) ;
        
        double totalValue = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            if (v[i].second.weight > capacity)
            {
                // toh mai sirf fraction le sakta hu
                totalValue += capacity*v[i].first ;
                capacity = 0 ;
            }
            else
            {
                totalValue += v[i].second.value ;
                capacity = capacity - v[i].second.weight ;
            }
        }
        
        return totalValue ;
    }
};









int main() {

    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;

    Solution sol;
    double maxValue = sol.fractionalKnapsack(value, weight, capacity);

    cout << "Maximum value we can obtain = " << maxValue << endl;
    
    return 0;
}


