class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for(int i=word1.size(); i>=0 ; i--)
        {
            for(int k=word2.size(); k>=0; k--)
            {
                if(i==word1.size())
                    dp[i][k] = word2.size()-k;
                else if(k==word2.size())
                    dp[i][k] = word1.size()-i;
                else
                {
                    if(word1[i] == word2[k])
                        dp[i][k] = dp[i+1][k+1];
                    else
                        dp[i][k] = min(min(dp[i+1][k], dp[i][k+1]), dp[i+1][k+1])+1;
                }
            }
        }
        return dp[0][0];
    }    
};