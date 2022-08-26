#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool sell = true;
        int profit = 0, lastBuy = prices[0], lastSold = prices[0];
        for(int i=1; i<prices.size(); i++)
        {
            int price = prices[i];
            if(sell)
            {
                if(price <= lastBuy)
                    lastBuy = price;
                else
                {
                    lastSold = price;
                    profit += lastSold-lastBuy;
                    sell = false;
                }
            }
            else
            {
                if(price > lastSold)
                {
                    profit += price-lastSold;
                    lastSold = price;
                }
                else
                {
                    lastBuy = price;
                    sell = true;
                }
            }
        }
        return profit;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> arr = {7,1,5,3,6,4};
    int counter = sol.maxProfit(arr);
    cout << counter << endl;
}