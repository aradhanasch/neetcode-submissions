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
        stack<ListNode* > s1;
        stack<ListNode* > s2;
        while(l1) {
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2) {
            s2.push(l2);
            l2 = l2->next;
        }
        int sum = 0, carry = 0;
        ListNode* temp = NULL;
        while(!s1.empty() || !s2.empty() || carry) {
            int digit1 = 0, digit2 = 0;
            if(!s1.empty()) {
                digit1 = s1.top()->val;
                s1.pop();
            }
            if(!s2.empty()) {
                digit2 = s2.top()->val;
                s2.pop();
            }
            sum = digit1 + digit2 + carry;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            newNode->next = temp;
            temp = newNode;
        }
        return temp;
    }
};