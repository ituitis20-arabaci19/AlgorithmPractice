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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = nullptr;
        ListNode* head = nullptr;
        while(list1 != nullptr && list2 != nullptr)
        {
            ListNode* add =  list1->val <= list2->val ? list1 : list2;
            if(list1->val <= list2->val)
                list1 = list1->next;
            else
                list2 = list2->next;
            if(res == nullptr)
            {    
                res = add;
                head = res;
            }
            else
            { 
                res->next = add;
                res = res->next;
            }
        }
        if(res == nullptr)
        {    
            res = list1==nullptr ? list2 : list1;
            head = res;
        }
        else
            res->next = list1==nullptr ? list2 : list1;
        return head;
    }
};