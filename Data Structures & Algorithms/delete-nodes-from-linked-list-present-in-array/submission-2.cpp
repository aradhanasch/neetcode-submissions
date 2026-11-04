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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int num : nums) {
            s.insert(num);
        }
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        while(temp) {
            if(s.find(temp->val) != s.end()) {
                ListNode* currNode = temp;
                prev->next = currNode->next;
                temp = temp->next;
                delete currNode;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
