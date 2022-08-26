#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int leftIdx = 0, rightIdx = 1;
        int maxPoint = 0;
        while(rightIdx < values.size())
        {
           maxPoint = max(maxPoint,point(leftIdx, rightIdx, values));
            if(values[rightIdx] >= (values[leftIdx]-(rightIdx-leftIdx)))
                leftIdx = rightIdx;
            rightIdx++;
        }
        return maxPoint;
    }
    int point(int i, int j, vector<int>& values)
    {
        return values[i]+values[j]+i-j;
    }
};

int main()
{    
    Solution sol = Solution();
    vector<int> vec = {7,2,6,6,9,4,3};
    int counter = sol.maxScoreSightseeingPair(vec); 
    cout << counter << endl;
}
