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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* sentinel = new ListNode(-1000, head);
        ListNode* p = head;
        ListNode* slow = sentinel;

        while(p != nullptr && p->next != nullptr)
        {
            if(p->val == p->next->val)
            {
                int repVal = p->val;
                while(p != nullptr && p->val == repVal)
                    p = p->next;
                slow->next = p;
            }
            else
            {
                p = p->next;
                slow = slow->next;
            }
        }
        return sentinel->next;
    }
};