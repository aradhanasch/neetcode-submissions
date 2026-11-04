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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode* fast = head;
        for(int i = 1; i < k; i++) {
            fast = fast->next;
        }
        ListNode* kBeg = fast;
        ListNode* slow = head;
        while(fast && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* kEnd = slow;
        swap(kBeg->val, kEnd->val);
        return head;
    }
};
