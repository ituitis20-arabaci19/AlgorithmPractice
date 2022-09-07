class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=0; i<text1.size(); i++)
        {
            for(int k=0; k<text2.size(); k++)
            {
                if(text1[i] == text2[k])
                    dp[i+1][k+1] = dp[i][k]+1;
                else
                    dp[i+1][k+1] = max(dp[i][k+1],dp[i+1][k]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
    
};