class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long>dp(target+1, 0);
        for(int t=1; t<=target; t++)
        {
            for(int n=0; n<nums.size(); n++)
            {
                if(t - nums[n] >= 0)
                    dp[t] += dp[t-nums[n]] + (t-nums[n]==0);                
            }
        }
        return dp[target];
    }
};