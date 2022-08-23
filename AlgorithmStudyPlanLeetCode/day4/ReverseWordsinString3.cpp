class Solution {
public:
    string reverseWords(string s) {
        vector<int> emptyIdx = {-1};
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
                emptyIdx.push_back(i);
        }
        emptyIdx.push_back(s.size());
        for(int i=0; i<emptyIdx.size()-1; i++)
        {
            int left = emptyIdx[i]+1;
            int right = emptyIdx[i+1]-1;
            while(left < right)
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
        return s;
    }
};