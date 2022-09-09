class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>>dp(n+2,{0,0,0});
        dp[1] = {1,1,1};
        dp[2] = {1,1,1};
        dp[3] = {1,2,2};
        int idx = 4;
        while(idx <= n)
        {
            int first = dp[idx-1][0], second = dp[idx-1][1];
            vector<int>choice1 = {first+1, second, max(first+1,dp[first+1][2])*max(second,dp[second][2])};
            vector<int>choice2 = {first, second+1, max(first,dp[first][2])*max(second+1,dp[second+1][2])};
            dp[idx] = choice1[2]>choice2[2] ? choice1 : choice2;
            idx++;
        }
        return dp[n][2];
    }
};