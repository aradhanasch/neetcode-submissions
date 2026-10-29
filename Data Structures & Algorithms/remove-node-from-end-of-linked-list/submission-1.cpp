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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int t = 0;
        while(temp != NULL) {
            temp = temp->next;
            t++;
        }
        if(t == n) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }
        temp = head;
        for(int i = 1; i < t - n; i++) {
            temp = temp->next;
        }
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;        
    }
};
