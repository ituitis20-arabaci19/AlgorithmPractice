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
    Node* reverseList(Node* head) {
        reverseRecursive(head,head);
        return head;
    }
    void reverseRecursive(Node* ptr, Node* &head)
    {
        if(ptr->next == NULL)
        {
            head = ptr;
            return;
        }
        reverseRecursive(ptr->next, head);
        ptr->next->next = ptr;
        ptr->next = NULL;
    }
};
int main()
{
    Solution sol = Solution();
    //[1,2,3,4,5,6,7]
    vector<Node*> nodes = {new Node(1),new Node(2),new Node(3),new Node(4),new Node(5),new Node(6),new Node(7)};
    nodes[0]->next = nodes[1];
    nodes[1]->next = nodes[2];
    nodes[2]->next = nodes[3];
    nodes[3]->next = nodes[4];
    nodes[4]->next = nodes[5];
    nodes[5]->next = nodes[6];
    Node* counter = sol.reverseList(nodes[0]);
    cout << counter << endl;
}