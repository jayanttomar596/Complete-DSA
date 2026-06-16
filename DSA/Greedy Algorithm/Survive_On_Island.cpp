// Check if it is possible to survive on Island






/*

Geekina got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive.

Example 1:

Input: S = 10, N = 16, M = 2
Output: 2
Explaination: One possible solution is to 
buy a box on the first day (Monday), 
it’s sufficient to eat from this box up to 
8th day (Monday) inclusive. Now, on the 9th 
day (Tuesday), you buy another box and use 
the chocolates in it to survive the 9th and 
10th day.

*/







#include <iostream>
using namespace std;







// Time Complexity: O(1)
// Space Complexity: O(1)








// 💡 Why It’s Greedy:
// A Greedy Algorithm always makes the best possible choice at each step — in this case, it buys as much food as possible each day, to reduce the number of days you need to go to the shop.

// The greedy decision here:
// Buy the maximum possible food per day (N units), and

// Buy only on days you're allowed to (non-Sundays),

// So you minimize the number of buying days.

// The algorithm calculates:

// Total food needed = S × M

// Max food you can buy in available days = buyingDays × N

// Then it greedily chooses:

// The minimum number of days you need to buy food (by dividing total food needed by daily limit N).

// 🔍 Why Greedy Works Here
// There’s no benefit in skipping a day if you’re allowed to buy — skipping delays your survival goal.

// The more you buy on allowed days, the fewer total buying days you need.

// So always buy as much as possible when you can — the essence of a greedy strategy.











class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        int sunday = S/7 ;
        
        int buyingDays = S - sunday ;
        int totalFood = S*M ;
        int ans = 0 ;
        
        if (sunday != 0)
        {
            if ((N-M)*6 < M)
                return -1 ;
        }
        
        if (totalFood % N == 0)
        {
            ans = totalFood/N ;
        }
        else
        {
            ans = totalFood/N + 1 ;
        }
        
        if (ans <= buyingDays)
            return ans ;
        else
            return -1 ;
        
    }
};








int main() {

    Solution sol;

    // Example test case:
    int S = 10;  // total days to survive
    int N = 16;  // food units that can be bought each day
    int M = 2;   // food units needed per day

    int result = sol.minimumDays(S, N, M);

    if (result != -1)
        cout << "Minimum days to buy food: " << result << endl;
    else
        cout << "Survival not possible." << endl;
    
    return 0;
}








