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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* A = list1;
        ListNode* B = list1->next;
        while (b) {
            B = B->next;
            if (a != 1) {
                A = A->next;
                a--;
            }
            b--;
        }
        A->next = list2;
        while (A->next != nullptr) {
            A = A->next;
        }
        A->next = B;
        return list1;
    }
};