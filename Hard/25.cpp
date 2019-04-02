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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* p = head;

        while(p != NULL) {
            n++;
            p = p->next;
        }

        if(head == NULL || n < k) {
            return head;
        }

        ListNode* pp = head;
        p = head->next;
        int i = 1;
        while(i < k) {
            i++;
            p = p->next;
            pp = pp->next;
        }

        //head->next = reverseKGroup(p->next, k);

        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* aa = head;
        ListNode* t;
        while(b != p) {
            t = b->next;
            b->next = a;
            a = b;
            b = t;
        }
        aa->next = reverseKGroup(p, k);

        return pp;
    }
};
