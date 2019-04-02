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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p = ans;
        int carry = 0;

        while(p1 != NULL || p2 != NULL)
        {
            int x = p1 != NULL ? p1->val : 0;
            int y = p2 != NULL ? p2->val : 0;
            int z = x + y + carry;
            carry = z / 10;
            p->next = new ListNode(z % 10);
            p = p->next;

            if(p1 != NULL)
                p1 = p1->next;

            if(p2 != NULL)
                p2 = p2->next;
        }

        if(carry > 0)
        {
            p->next = new ListNode(carry);
        }

        return ans->next;

    }

};
