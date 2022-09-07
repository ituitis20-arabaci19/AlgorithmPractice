class Solution {
public:
    bool isSubsequence(string s, string t) {
        int subIdx = 0, mainIdx = 0;
        while(subIdx < s.size() && mainIdx < t.size())
        {
            if(s[subIdx] == t[mainIdx])
                subIdx++;
            mainIdx++;
        }
        return subIdx == s.size();        
    }
};