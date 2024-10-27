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

        bitset<100001> remove; 
        for (int val : nums) {
            remove.set(val);
        }
        ListNode* curr = head;
        ListNode* prev = curr;
        while (curr) {
            if (remove[curr->val]) {
                if (curr == head) {
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};