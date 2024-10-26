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
        // if (head == nullptr || head->next == nullptr)
        //     return head;
        // ListNode *temp = head, *prev = nullptr;
        // while (temp != nullptr) {
        //     if (temp->next != nullptr && temp->val == temp->next->val) {
        //         int value = temp->val;
        //         while (temp->next != nullptr && temp->val == value) {
        //             temp = temp->next;
        //         }
        //         if (prev == nullptr) {
        //             head = temp;
        //         } else {
        //             prev->next = temp;
        //         }
        //     } else {
        //         prev = temp;
        //         temp = temp->next;
        //     }
        // }
        // return head;
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            if (current->next != nullptr && current->val ==
            current->next->val) {
                int duplicateVal = current->val;
                while (current != nullptr && current->val ==
                duplicateVal) {
                    current = current->next;
                }
                if (prev == nullptr) {
                    head = current;
                } else {
                    prev->next = current;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};