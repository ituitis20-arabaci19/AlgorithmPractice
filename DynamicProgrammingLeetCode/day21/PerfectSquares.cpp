class Solution {
public:
    int numSquares(int n) {
        int limit = sqrt(n);
        vector<vector<int>>dp(n+2, vector<int>(limit+1,10004));
        for(int i=limit-1; i>=0; i--)
        {
            for(int k=n; k>=0; k--)
            {
                if(k==n)
                {
                    dp[k][i] = 0;
                    continue;
                }
                int choice = 10004;
                int nextK = k+(i+1)*(i+1);
                if(nextK <= n)
                    choice = min(dp[nextK][i+1]+1, dp[nextK][i]+1);
                dp[k][i] = min(choice, dp[k][i+1]);
            }
        }
        return dp[0][0];
    }
};