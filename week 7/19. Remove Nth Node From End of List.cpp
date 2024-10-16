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
// Method 1
class Solution {
public:
    ListNode* reverse(ListNode* ptr) {
        ListNode *curr = ptr, *Next = nullptr, *prev = nullptr;
        while (curr != nullptr) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return head;
        ListNode* temp = reverse(head);//reverse the list
        ListNode* preptr=nullptr;
        if (n == 1) {
            head = temp->next;
            return reverse(head);
        }
        else {
            ListNode* ans=temp;
            int i = 1;
            while (i < n) {
                preptr=temp;
                temp = temp->next;
                i++;
            }
            preptr->next = temp->next;
            return reverse(ans);
        }
        
    }
};
//method 2
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);//create dummy ptr with node 0
        dummy->next = head;// link head with dummy
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; ++i) {//take first to node that is to be deleted 
            first = first->next;
        }

        while (first != nullptr) {//move both till second is jus
            first = first->next;
            second = second->next;
        }

        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        return dummy->next;
    }
};