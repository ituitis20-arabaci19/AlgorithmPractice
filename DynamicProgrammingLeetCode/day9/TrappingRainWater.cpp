#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

// Two pointers solution
class Solution {
public:
    int trap(vector<int>& height) {
        int leftIdx = 0, rightIdx = height.size()-1, leftNum = 0, rightNum = 0;
        int fill = 0;
        int counter = 0;
        while(leftIdx < rightIdx)
        {
            leftNum = height[leftIdx];
            rightNum = height[rightIdx];
            fill = min(leftNum, rightNum);
            if(leftNum <= rightNum)
            {
                while(leftNum >= height[leftIdx] && leftIdx < rightIdx)
                {
                    counter += fill-height[leftIdx];
                    height[leftIdx] = fill;         
                    leftIdx++;
                }
            }
            else
            {
                while(rightNum >= height[rightIdx] && leftIdx < rightIdx)
                {
                    counter += fill-height[rightIdx];
                    height[rightIdx] = fill;
                    rightIdx--;
                }   
            }         
        }
        return counter;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> arr = {4,2,0,3,2,5};
    int counter = sol.trap(arr);
    cout << counter << endl;
}