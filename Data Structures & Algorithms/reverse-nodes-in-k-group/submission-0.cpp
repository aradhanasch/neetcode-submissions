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
ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
            return head;
        ListNode* h1 = head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* h2 = NULL;
        while(temp != NULL) {
            for(int i = 1; i < k; i++) {
                temp = temp->next;
                if(temp == NULL) {
                    if(prev)
                        prev->next = h1;
                    return head;
                }
            }
            h2 = temp->next;
            temp->next = NULL;
            ListNode* newHead = reverseList(h1);
            if(prev)
                prev->next = newHead;
            else
                head = newHead;
            prev = h1;
            temp = h2;
            h1 = h2;
        }
        return head;
    }
};
