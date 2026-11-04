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
    int pairSum(ListNode* head) {
        if(head == NULL)
            return 0;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = reverseList(slow->next);
        ListNode* temp = temp2;
        int mx = 0;
        while(temp2 != NULL) {
            int sum = temp1->val + temp2->val;
            mx = max(mx, sum);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        slow->next = reverseList(temp);
        return mx;
    }
};