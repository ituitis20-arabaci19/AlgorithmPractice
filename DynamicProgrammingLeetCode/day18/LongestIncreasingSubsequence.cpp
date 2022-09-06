class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int numSize = nums.size();
        int maxLen = 0;
        vector<int>dp(numSize,1);
        for(int i=numSize-1; i>=0; i--)
        {
            int rightIdx = 1;
            while(i+rightIdx < numSize)
            {
                if(nums[i] < nums[i+rightIdx])
                    dp[i] = max(dp[i], dp[i+rightIdx]+1);            
                rightIdx++;
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};