/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* rmNode = dummy;
        while(ptr->next != nullptr)
        {
            ptr = ptr->next;
            if(n <= 1)
                rmNode = rmNode->next;
            n--;
        }
        rmNode->next = rmNode->next->next; 
        if(rmNode == dummy)
            return rmNode->next;
        return head;
    }
};