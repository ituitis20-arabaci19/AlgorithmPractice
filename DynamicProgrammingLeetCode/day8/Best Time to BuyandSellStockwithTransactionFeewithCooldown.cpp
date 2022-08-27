#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> prices) {
        bool sell = true;
        int profit = 0, lastBuy = prices[0], lastSold = INT_MIN;
        for(int i=1; i<prices.size(); i++)
        {
            int price = prices[i];
            if(sell)
            {
                if(price <= lastBuy)
                    lastBuy = price;
                else
                {
                    if(i == prices.size()-1)
                    {
                        lastSold = max(lastSold, price);
                        profit += max(0,lastSold-lastBuy);
                    }
                    else if(price > prices[i+1])
                    {
                        int curr = maxProfit(vector<int>(prices.begin()+i+1,prices.end()));
                        int next = maxProfit(vector<int>(prices.begin()+i+2,prices.end()));
                        profit += max(curr+prices[i-1]-lastBuy, next+price-lastBuy);
                        break;
                    }
                }
            }
            else
            {
                lastBuy = price;
                sell = true;
                lastSold = INT_MIN;
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