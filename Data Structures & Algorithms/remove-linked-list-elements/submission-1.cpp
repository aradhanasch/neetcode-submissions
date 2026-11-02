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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        ListNode* temp = head;
        while(temp) {
            if(temp->val == val) {
                ListNode* currNode = temp;
                prev->next = currNode->next;
                temp = temp->next;
                delete currNode;
            } else {
                prev->next = temp;
                prev = temp;
                temp = temp->next;
            }
        } 
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};