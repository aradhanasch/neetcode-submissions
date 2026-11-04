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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        ListNode* start = head;
        while(start) {
            ListNode* temp = start->next;
            if(temp) {
                ListNode* nextP = temp->next;
                temp->next = start;
                start->next = NULL;
                prev->next = temp;
                prev = start;
                start = nextP;
            } else {
                prev->next = start;
                start = start->next;
            }
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
