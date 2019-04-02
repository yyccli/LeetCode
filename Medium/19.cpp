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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = p1;
        int i;

        for(i = 0; i < n; i++){
            if(p2->next == NULL){
                break;
            }else{
                p2 = p2->next;
            }
        }

        if(i == n-1){
            return head->next;
        }

        while(p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }

        p1->next = p1->next->next;

        return head;
    }
};
