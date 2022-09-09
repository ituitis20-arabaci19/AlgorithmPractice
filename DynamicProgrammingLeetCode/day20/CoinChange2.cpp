class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,0));        
        for(int coinIdx=coins.size()-1; coinIdx>=0; coinIdx--)
        {
            for(int amountRemain=amount; amountRemain>=0; amountRemain--)
            { 
                if(amount-amountRemain == 0)
                {
                    dp[amountRemain][coinIdx] = 1;
                    continue;
                }
                if(amount-amountRemain >= coins[coinIdx])
                {
                    /*if(amountRemain+coins[coinIdx] == amount)
                        dp[amountRemain][coinIdx] += 1;*/
                    dp[amountRemain][coinIdx] += dp[amountRemain+coins[coinIdx]][coinIdx];
                }
                dp[amountRemain][coinIdx] += dp[amountRemain][coinIdx+1];
            }
        }
        return dp[0][0];
    }
};