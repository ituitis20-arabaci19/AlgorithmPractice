#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int>wordMap;
        unordered_map<string, int>dp;
        for(string str : wordDict) wordMap[str]++;
        return parse(wordMap, s, dp);
    }
    bool parse(unordered_map<string, int> wordMap, string s, unordered_map<string, int>& dp)
    {
        if(wordMap[s] == 1)
            return true;
        int canParse = false;
        if(dp[s] != 0)
            return dp[s]-1;
        for(int i=1; i<s.size(); i++)
        {
            if(wordMap[s.substr(0,i)] == 1)
                canParse = parse(wordMap,s.substr(i,s.size()-i),dp);
            if(canParse)
                break;
        }
        dp[s] = canParse+1;
        return canParse;
    }
};
int main()
{
    Solution sol = Solution();
    vector<string> arr = {"apple","pen"};
    int counter = sol.wordBreak("applepenapple",arr);
    cout << counter << endl;
}