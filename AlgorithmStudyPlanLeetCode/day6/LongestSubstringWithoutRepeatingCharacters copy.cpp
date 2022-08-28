class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int leftWindow = 0, rightWindow = 0;
        int longest = 0;
        unordered_map<char,int>subLetters;
        while(rightWindow < s.size())
        {
            if(subLetters[s[rightWindow]] != 0)
            { 
                subLetters[s[leftWindow]]--;
                leftWindow++;
            }
            else
            {
                subLetters[s[rightWindow]]++;
                rightWindow++;              
            }
            longest = max(longest, rightWindow-leftWindow);
        }
        return longest;
    }
};