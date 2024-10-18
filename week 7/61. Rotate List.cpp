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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0 || head->next == NULL)
            return head;
        ListNode *temp = head, *pretemp = nullptr;
        int n = 0;
        while (temp != NULL) {//count no of nodes
            n++;
            temp = temp->next;
        }
        temp = head;
        k = k % n;
        while (k--) {
            while (temp->next != NULL) {
                pretemp = temp;
                temp = temp->next;
            }
            temp->next = head;
            head = temp;
            pretemp->next = NULL;//point new last node to null
        }
        return head;
    }
};