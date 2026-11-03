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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* temp = head;
        while(temp->next != NULL) {
            ListNode* nextNode = temp->next;
            if(temp->val == nextNode->val) {
                temp->next = nextNode->next;
                delete nextNode;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
