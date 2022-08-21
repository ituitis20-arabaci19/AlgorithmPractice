#include <iostream>
#include <vector>

using namespace std

class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp = {1};
        int counter = takeStep(n, dp);
        return counter;
    }
    int takeStep(int n, vector<int>&dp)
    {
        int counter = 0;
        if(n == 1)
            return 1;
        if(n <= 0)
            return 0;
        if(n == 2)
            counter++;
        if(n <= dp.size())
            return dp[n-1];
        counter += takeStep(n-1, dp) + takeStep(n-2, dp);
        dp.push_back(counter);
        return counter;
    }
};

int main()
{
    Solution sol = Solution();
    int counter = sol.minCostClimbingStairs(10); 
    cout << counter << endl;
}