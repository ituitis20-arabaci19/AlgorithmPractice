class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string reversed = string(s.rbegin(),s.rend());
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return lcsRecur(s, reversed, 0, 0, dp);  
    }
    int lcsRecur(string& s, string& r, int i, int k, vector<vector<int>>& dp)
    {
        if(i == s.size() || k == r.size())
            return 0;
        if(dp[i][k] != -1)
            return dp[i][k];
        if(s[i] == r[k])
            dp[i][k] = lcsRecur(s,r,i+1,k+1,dp) + 1;
        else
            dp[i][k] = max(lcsRecur(s,r,i+1,k,dp), lcsRecur(s,r,i,k+1,dp));
        return dp[i][k];
    }
};
    