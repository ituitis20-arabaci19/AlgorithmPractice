class Solution {
public:
    int uniquePaths(int m, int n) {
        int board[m][n];
        for(int i=0; i<m; i++)
        {
            for(int k=0; k<n; k++)
            {
                if(i==0 || k==0)
                    board[i][k] = 1;
                else
                    board[i][k] = board[i-1][k]+board[i][k-1];
            }
        }
        return board[m-1][n-1];
    }
};