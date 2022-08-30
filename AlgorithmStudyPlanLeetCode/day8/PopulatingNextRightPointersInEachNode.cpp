#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)return root;
        queue<Node*>bfsQueue;
        Node* ptr = NULL;
        bfsQueue.push(root);
        int depth = 1, currDepth = depth-1;
        while(!bfsQueue.empty())
        {
            Node* frontPtr = bfsQueue.front();
            bfsQueue.pop();
            if(frontPtr->left != NULL)
                bfsQueue.push(frontPtr->left);
            if(frontPtr->right != NULL)
                bfsQueue.push(frontPtr->right);
            
            if(ptr == NULL)
                ptr = frontPtr;
            else
            {
                ptr->next = frontPtr;
                currDepth--;
                ptr = ptr->next;
            }
            if(currDepth == 0)
            {
                ptr->next = NULL;
                depth *= 2;
                currDepth = depth-1;
                ptr = ptr->next;
            }              
        }   
        return root;
    }
};
int main()
{
    Solution sol = Solution();
    //[1,2,3,4,5,6,7]
    vector<Node*> nodes = {new Node(1),new Node(2),new Node(3),new Node(4),new Node(5),new Node(6),new Node(7)};
    nodes[0]->left = nodes[1];nodes[0]->right = nodes[2];
    nodes[1]->left = nodes[3];nodes[1]->right = nodes[4];
    nodes[2]->left = nodes[5];nodes[2]->right = nodes[6];
    Node* counter = sol.connect(nodes[0]);
    cout << counter << endl;
}