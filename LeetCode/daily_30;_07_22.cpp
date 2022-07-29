
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <queue>
#include "insertion_sort.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>validated;
        unordered_map<char, char>patternMap;
        char map = '1';
        for(int i=0; i<pattern.size(); i++)
        {
            if(patternMap[pattern[i]] == 0)
            {
                patternMap[pattern[i]] = map;
                pattern[i] = map;
                map++;
            }
            else
                pattern[i] = patternMap[pattern[i]];
        }
        for(string word : words)
        {
            string temp = word;
            unordered_map<char, char>wordMap;
            char map = '1';
            for(int i=0; i<word.size(); i++)
            {
                if(wordMap[word[i]] == 0)
                {
                    wordMap[word[i]] = map;
                    word[i] = map;
                    map++;
                }
                else
                    word[i] = wordMap[word[i]];
            }
            if(pattern == word)
                validated.push_back(temp);
        }
        return validated;
    }
};
int main()
{
    Solution sol = Solution();
    vector<string>vec = {"abc","deq","mee","aqq","dkd","ccc"};
    vector<string>vec2 = sol.findAndReplacePattern(vec, "abb");

    printf(" ");
}