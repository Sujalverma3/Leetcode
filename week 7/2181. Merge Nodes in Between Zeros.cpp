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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=nullptr,* temp=nullptr;
        int sum=0;
        head=head->next;
        while (head!= nullptr) {
            sum += head->val;
            if (head->next->val == 0) {
                if (ans == nullptr) {
                    ans = new ListNode(sum);
                    temp=ans;
                } else {
                    temp->next= new ListNode(sum);
                    temp=temp->next;
                }
                sum = 0;
                head=head->next;
            }
            head = head->next;
        }
        return ans;
    }
};