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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return head;
        }

        ListNode* p = head;
        ListNode* q;

        while(p->next != NULL) {
            q = p->next;
            while(q != NULL) {
                if(q->val == p->val) {
                    q = q->next;
                } else {
                    break;
                }
            }

            p->next = q;
            if(q == NULL) {
                break;
            } else {
                p = q;
            }
        }

        return head;
    }
};
