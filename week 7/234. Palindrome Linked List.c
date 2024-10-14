/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* ptr) {
    struct ListNode *curr = ptr, *fut = NULL, *prev = NULL;
    while (curr != NULL) {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    // finding middle term
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *firsthalf = head, *secondhalf = reverse(slow);
    struct ListNode* temp = secondhalf;
    while (secondhalf != NULL) {
        if (firsthalf->val != secondhalf->val) {
            // reverse(temp); //for reuse of LinkList
            return false;
        }
        firsthalf = firsthalf->next;
        secondhalf = secondhalf->next;
    }
    // reverse(temp);
    return true;
}