#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
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
                    if(price > prices[i+1])
                    {
                        if(abs(prices[i-1]-price) > abs(prices[i+1]-prices[i+2]))
                        {
                            lastSold = price;
                            i++;
                        }
                        else
                            lastSold = prices[i-1];
                        profit += lastSold-lastBuy;
                        sell = false;
                    }
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
    vector<int> arr = {4868,4579,2307,3952,3544,651,1300,218,489};
    int counter = sol.maxProfit(arr,655);
    cout << counter << endl;
}