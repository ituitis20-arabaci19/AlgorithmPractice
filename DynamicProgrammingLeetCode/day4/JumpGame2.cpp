#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumps(n,10001);
        jumps[n-1] = 0;
        for(int i=n-2; i>=0; i--)
        {
            for(int k=nums[i]; k>0; k--)
            {
                if(i+k >= n-1)
                {
                    jumps[i] = 1;
                    break;
                }
                else
                {
                    if( jumps[i+k]+1 < jumps[i])
                        jumps[i] = jumps[i+k]+1; 
                }
            }
        }
        return jumps[0];
    }
};
int main()
{
    Solution sol = Solution();
    vector<int> cost = {2,3,1,1,4};
    int counter = sol.jump(cost); 
    cout << counter << endl;
}