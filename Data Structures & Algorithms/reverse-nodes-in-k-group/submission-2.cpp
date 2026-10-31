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
        while(curr) {
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
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        ListNode* start = head;
        ListNode* kth = head;
        ListNode* nextGroup = NULL;
        while(kth != NULL) {
            for(int i = 1; i < k; i++) {
                kth = kth->next;
                if(kth == NULL) {
                    prev->next = start;
                    return dummy->next;
                }
            }
            nextGroup = kth->next;
            kth->next = NULL;
            ListNode* newH = reverseList(start);
            prev->next = newH;
            prev = start;
            start = nextGroup;
            kth = start;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
