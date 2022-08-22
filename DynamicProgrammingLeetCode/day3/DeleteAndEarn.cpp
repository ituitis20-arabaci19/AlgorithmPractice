#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int numVec[20000] = {0};
        for(int num : nums)
        {
            numVec[num]++;
        }
        int prev = 0;
        int curr = 0;
        int calc = 0;
        for(int i=0; i<20000; i++)
        {
            calc = max(prev+numVec[i]*i, curr);
            prev = curr;
            curr = calc;
        }
        return curr;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> cost = {1,2,3,1};
    int counter = sol.deleteAndEarn(cost); 
    cout << counter << endl;
}