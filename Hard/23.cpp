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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v_num;
        ListNode* p;

        if(lists.empty()){
            return NULL;
        }

        for(int i = 0; i < lists.size(); i++) {
            p = lists[i];
            while(p != NULL) {
                v_num.push_back(p->val);
                p = p->next;
            }
        }

        sort(v_num.begin(), v_num.end());

        ListNode* head = new ListNode(-1);
        p = head;

        for(int i = 0; i < v_num.size(); i++) {
            ListNode* t = new ListNode(v_num[i]);
            p->next = t;
            p = t;
        }

        return head->next;

    }

};
