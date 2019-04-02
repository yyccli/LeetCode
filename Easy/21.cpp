/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while(p1 != NULL && p2 != NULL){
            int val;
            if(p1->val < p2->val){
                val = p1->val;
                p1 = p1->next;
            }else{
                val = p2->val;
                p2 = p2->next;
            }

            ListNode* t = new ListNode(val);
            p->next = t;
            p = t;
        }

        if(p1 != NULL){
            p->next = p1;
        }

        if(p2 != NULL){
            p->next = p2;
        }

        return head->next;
    }
};
