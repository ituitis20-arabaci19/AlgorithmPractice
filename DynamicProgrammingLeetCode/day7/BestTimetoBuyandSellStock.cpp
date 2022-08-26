#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricesSize = prices.size();
        int mostExp = prices[pricesSize-1], potentialBuy = prices[pricesSize-1];
        int maxProfit = 0;
        for(int i=pricesSize-2; i>=0; i--)
        {
            if(prices[i] > mostExp)
            {
                maxProfit = max(maxProfit, mostExp - potentialBuy);
                mostExp = prices[i];
                potentialBuy = prices[i];
            }
            if(prices[i] < potentialBuy)
                potentialBuy = prices[i];
        }
        return max(maxProfit, mostExp - potentialBuy);
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> arr = {7,1,5,3,6,4};
    int counter = sol.maxProfit(arr);
    cout << counter << endl;
}