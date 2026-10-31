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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        int sum = 0, carry = 0;
        while(l1 || l2 || carry) {
            int digit1 = l1 ? l1->val : 0;
            int digit2 = l2 ? l2->val : 0;
            sum = digit1 + digit2 + carry;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            res->next = newNode;
            res = res->next;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return dummy->next;
    }
};
