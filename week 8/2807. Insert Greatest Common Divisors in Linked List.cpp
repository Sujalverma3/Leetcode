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
    int Gcd(int n1, int n2) {
        int divisor = 0;
        for (int i = 1; i <= n1 && i <= n2; i++) {
            if (n1 % i == 0 && n2 % i == 0) {
                divisor = i;
            }
        }
        return divisor;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr && head->next == nullptr) {
            return head;
        }
        ListNode *curr = head, *curnext = head->next;
        while (curr != nullptr && curnext != nullptr) {
            ListNode* temp =new ListNode(Gcd(curr->val, curnext->val),curnext);
            curr->next = temp;
            curr = curnext;
            if (curr!=nullptr || curr->next != nullptr)
                curnext = curnext->next;
            else
                break;
        }
        return head;
    }
};