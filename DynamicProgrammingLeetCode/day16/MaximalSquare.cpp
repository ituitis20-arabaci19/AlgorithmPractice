class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int maxArea = 0;
        for(int r=0; r<matrix.size(); r++)
        {
            for(int c=0; c<matrix[0].size(); c++)
            {
                if(r==0 || c==0)
                    dp[r][c] = matrix[r][c]-'0';
                else
                {
                    if(matrix[r][c] == '1')
                        dp[r][c] = min(dp[r-1][c-1], min(dp[r-1][c], dp[r][c-1]))+1;
                }
                maxArea = max(maxArea, dp[r][c]);
            }
        }
        return maxArea*maxArea;
    }
};