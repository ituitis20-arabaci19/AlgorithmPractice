/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root2 == nullptr)
            return root1;
        TreeNode* head = root2;
        traverse(root1, root2, 1);
        return head;
    }
    void traverse(TreeNode* node1, TreeNode* node2, int mode) //1 add 2 append
    {
        if(node1==nullptr || mode==2)
            return;
        node2->val += node1->val;
        
        if(node2->left == nullptr)
        {
            node2->left = node1->left;
            mode = 2;
        }
        else
            mode = 1;
        traverse(node1->left, node2->left,mode);
        
        if(node2->right == nullptr)
        {
            node2->right = node1->right;
            mode = 2;
        }
        else
            mode = 1;
        traverse(node1->right, node2->right,mode);    
    }
};