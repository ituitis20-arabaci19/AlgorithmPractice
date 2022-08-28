class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>permLetters;
        for(char c : s1)permLetters[c]++;
        unordered_map<char,int>temp = permLetters;
        int leftWindow = 0, rightWindow = 0;
        
        while(rightWindow < s2.size())
        {
            if(permLetters[s2[rightWindow]] == 0)
            {
                if(leftWindow==rightWindow)
                {
                    rightWindow++;
                    leftWindow = rightWindow;
                }
                else
                {
                    permLetters[s2[leftWindow]]++;
                    leftWindow++;
                }
            }
            else
            {
                permLetters[s2[rightWindow]]--;
                rightWindow++;
            }
            if((rightWindow - leftWindow) == s1.size())
                return true;
        }
        return false;
    }
};