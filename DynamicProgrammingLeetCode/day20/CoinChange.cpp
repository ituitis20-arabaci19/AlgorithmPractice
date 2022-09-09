class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,10002));        
        for(int coinIdx=coins.size()-1; coinIdx>=0; coinIdx--)
        {
            for(int amountRemain=amount; amountRemain>=0; amountRemain--)
            {
                int choice = 10002;
                if(amount-amountRemain == 0)
                {
                    dp[amountRemain][coinIdx] = 0;
                    continue;
                }    
                if(amount-amountRemain >= coins[coinIdx])
                    choice = min(dp[amountRemain+coins[coinIdx]][coinIdx]+1, dp[amountRemain+coins[coinIdx]][coinIdx+1]+1);
                dp[amountRemain][coinIdx] = min(choice, dp[amountRemain][coinIdx+1]);
            }
        }
        
        if(dp[0][0] >= 10001)
            return -1;
        return dp[0][0];
    }
};