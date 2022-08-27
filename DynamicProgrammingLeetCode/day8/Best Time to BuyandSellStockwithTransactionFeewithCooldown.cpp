#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<int,vector<int>>states; //day -> 0:buy, 1: sell, 2:cooldown, 3: no buy pass, 4:buy pass
        int res = max(act(states, prices, 0, 3, false), act(states, prices, 0, 0, false));
        return res;
    }
    int act(unordered_map<int,vector<int>>& states, vector<int>& prices, int day, int state, bool lastBuy)
    {
        if(day == prices.size())
            return 0;
        
        if(states[day].size() != 0)
        {
            if(states[day][state] != -1)
            {
                return states[day][state];
            }
        }
        else
            states[day] = {-1,-1,-1,-1,-1};
        //buy
        if(state == 0)
        {    
            lastBuy = true;
            states[day][state] = max(act(states, prices, day+1, 1, lastBuy), act(states, prices, day+1, 4, lastBuy))-prices[day]; 
        }
        //sell
        else if(state == 1)
        {
            states[day][state] = act(states, prices, day+1, 2, false)+prices[day];
        }
        else if(state == 2) //cooldown
        {    
            states[day][state] = max(act(states, prices, day+1, 0, lastBuy), act(states, prices, day+1, 3, lastBuy));
        }
        else //no buy pass or buy pass
        {    
            if(lastBuy == true)
                states[day][state] = max(act(states, prices, day+1, 1, lastBuy), act(states, prices, day+1, 4, lastBuy));
            else
                states[day][state] = max(act(states, prices, day+1, 0, lastBuy), act(states, prices, day+1, 3, lastBuy));
        }
        return max(states[day][state],0);   
    }
};


int main()
{
    Solution sol = Solution();
    vector<int> arr = {6,1,3,2,4,7};
    int counter = sol.maxProfit(arr);
    cout << counter << endl;
}