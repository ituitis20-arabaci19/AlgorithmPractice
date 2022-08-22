#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int rob(vector<int>& nums) {
        map<int,int> dp;
        return robHouse(nums.size(), nums, dp);
    }
    int robHouse(int n, vector<int>& nums, map<int,int>& dp)
    {
        if(n <= 0)
            return 0;
        int counter = 0;
        int temp = 0;
        while(n>0)
        {
            if(n < dp.size())
                temp = dp[n];
            else
            {   
                temp = nums[nums.size()-n] + robHouse(n-2, nums, dp);
                dp[n] = temp;
            }
            counter = counter > temp ? counter : temp;
            n--;
        }
        return counter;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> cost = {1,2,3,1};
    int counter = sol.rob(cost); 
    cout << counter << endl;
}