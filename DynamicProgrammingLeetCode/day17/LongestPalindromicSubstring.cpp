class Solution {
public:
    string longestPalindrome(string s) {
        int centerLeft=0, centerRight=0;
        int currLeft=0, currRight=0;
        int longest = -1, longestLeft;
        while(centerRight < s.size())
        {
            if(s[centerLeft]==s[centerRight])
            {    
                currLeft = centerLeft;
                currRight = centerRight;
                while(currLeft >= 0 && currRight<=s.size()-1)
                {
                    if(s[currLeft]==s[currRight])
                    {
                        if(currRight-currLeft+1 > longest)
                        {
                            longest = currRight-currLeft+1;
                            longestLeft = currLeft;
                        }
                    }
                    else
                        break;
                    currRight++;
                    currLeft--;
                }
            }
            if(centerRight-centerLeft==1)
                centerLeft++;
            else
                centerRight++;
        }
        return s.substr(longestLeft,longest);
    }
};