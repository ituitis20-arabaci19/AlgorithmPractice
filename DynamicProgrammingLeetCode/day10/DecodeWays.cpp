#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(2,-1));
        return findDecodes(s, 0, 1, dp)+findDecodes(s, 0, 2, dp);
    }
    int findDecodes(string s, int i, int size, vector<vector<int>>& dp)
    {
        if(stoi(s.substr(i,size)) > 26 || s[i] == '0' || i+size > s.size())
            return 0;
        if(i+size == s.size())
            return 1;
        if(dp[i][size-1] == -1)
            dp[i][size-1] = findDecodes(s,i+size,1,dp) + findDecodes(s,i+size,2,dp);
        return dp[i][size-1];            
    } 
};
int main()
{
    Solution sol = Solution();
    vector<vector<int>> arr = {{2,29,20,26,16,28},{12,27,9,25,13,21},{32,33,32,2,28,14},{13,14,32,27,22,26},{33,1,20,7,21,7},{4,24,1,6,32,34}};
    int counter = sol.numDecodings("51226");
    cout << counter << endl;
}