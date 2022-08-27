#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        bool sell = true;
        int profit = 0, lastBuy = prices[0], lastSold = prices[0]+fee;
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
                    if(lastSold-lastBuy-fee<0) continue;
                    profit += lastSold-lastBuy-fee;
                    sell = false;
                }
            }
            else
            {
                if(price >= lastSold-fee)
                {
                    if(lastSold>price)
                        continue;
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
        return max(profit,0);
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> arr = {4868,4579,2307,3952,3544,651,1300,218,489};
    int counter = sol.maxProfit(arr,655);
    cout << counter << endl;
}