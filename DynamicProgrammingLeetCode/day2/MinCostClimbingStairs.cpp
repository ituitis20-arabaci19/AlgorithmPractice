#include <iostream>
#include <vector>

using namespace std

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp;
        int minCost = takeStairs(cost.size(), cost, dp, cost.size());
        return minCost;
    }
    int takeStairs(int n, vector<int>& cost, vector<int>& dp, int totalStairs)
    {
        int temp;
        if(n <= 0)
            return 0;       
        if(totalStairs-n+1 >= totalStairs)
            temp = 0;
        else 
            temp = cost[totalStairs-n+1];
        if(n <= dp.size())
            return dp[n-1];        
        int minCost = min(cost[totalStairs-n]+takeStairs(n-1,cost, dp, totalStairs), 
                       temp+takeStairs(n-2,cost, dp, totalStairs));
        dp.push_back(minCost);
        return minCost;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int counter = sol.minCostClimbingStairs(cost); 
    cout << counter << endl;
}