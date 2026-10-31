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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right)
            return head;
        ListNode* l = head;
        ListNode* r = head;
        ListNode* prev = NULL;
        for(int i = 1; i < left; i++) {
            prev = l;
            l = l->next;
        }
        for(int j = 1; j < right; j++) {
            r = r->next;
        }
        ListNode* h2 = r->next;
        r->next = NULL;
        ListNode* newL = reverseList(l);
        if(head == l) {
            head = newL;
        } else {
            prev->next = newL;
        }
        l->next = h2;
        return head;
    }
};