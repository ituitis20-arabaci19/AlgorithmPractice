class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        permute(s, res, "", s.size());
        return res;
    }
    void permute(string s, vector<string>& res, string perm, int size)
    {
        string temp = perm + string(1,toupper(s[0]));
        if(temp.size() == size)
            res.push_back(temp);
        else
            permute(s.substr(1,s.size()-1), res, temp, size);
        
        if(toupper(s[0]) == s[0] && tolower(s[0]) == s[0])
            return;
        
        temp = perm + string(1,tolower(s[0]));
        if(temp.size() == size)
            res.push_back(temp);
        else
            permute(s.substr(1,s.size()-1), res, temp, size);
    }
};