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
    ListNode* reverse(ListNode* ptr) {
        ListNode *cur = ptr, *prev = nullptr, *Next = nullptr;
        while (cur != nullptr) {
            Next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = Next;
        }
        return prev;
    }

public:
    int pairSum(ListNode* head) {
        if (head->next->next == nullptr)
            return (head->val + head->next->val);

        ListNode* slow=head,*fast=head,*prev=nullptr;
        while(fast!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        int max=0;
        ListNode* temp=reverse(slow);
        prev->next=temp;
        while(temp!=nullptr){
            if (max < (head->val + temp->val)) {
                max = (head->val + temp->val);
            }
            temp = temp->next;
            head = head->next;
        }
        return max;
    }
};