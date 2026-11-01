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
    ListNode* mergeSort(int l, int h, vector<ListNode*> &lists) {
        if(l == h)
            return lists[l];
        int mid = l + (h - l) / 2;
        ListNode* left = mergeSort(l, mid, lists);
        ListNode* right = mergeSort(mid + 1, h, lists);
        return merge(left, right); 
    }

    ListNode* merge(ListNode* first, ListNode* second) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(first && second) {
            if(first->val <= second->val) {
                temp->next = first;
                first = first->next;
            } else {
                temp->next = second;
                second = second->next;
            }
            temp = temp->next;
        }
        temp->next = first ? first : second;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)
            return NULL;
        return mergeSort(0, n - 1, lists);
    }
};
