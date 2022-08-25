#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int negCount=0, negFirst=-1,  negLast=-1, lastZero = -1;
        int subLen = 0, maxSubLen = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                maxSubLen = max(maxSubLen, findMaxLen(subLen, negFirst, negLast, negCount, lastZero));
                negFirst = -1; negLast = -1; subLen = 0; negCount = 0;
                lastZero = i;
                continue;
            }
            else if(nums[i]<0)
            {
                negFirst = negFirst==-1 ? i-(lastZero+1) : negFirst;
                negLast = i-(lastZero+1);
                negCount++;                
            }
            subLen++;
        }
        return max(maxSubLen, findMaxLen(subLen, negFirst, negLast, negCount, lastZero)); 
    }
    int findMaxLen(int subLen, int negFirst, int negLast, int negCount, int lastZero)
    {
        if(negFirst == -1 || negCount%2==0)
            return subLen;
        int firstNegMax = max(negFirst, subLen-negFirst-1);
        int lastNegMax = max(negLast, subLen-negLast-1);
        return max(lastNegMax, firstNegMax);
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> arr = {0,1,-2,-3,-4};
    int counter = sol.getMaxLen(arr);
    cout << counter << endl;
}