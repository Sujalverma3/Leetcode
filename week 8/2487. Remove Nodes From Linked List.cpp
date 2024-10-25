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
    ListNode* reverse(ListNode* ptr){
        ListNode* cur=ptr,*prev=nullptr,*fut=nullptr;
        while(cur!=nullptr){
            fut=cur->next;
            cur->next=prev;
            prev=cur;
            cur=fut;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        if(head == nullptr|| head->next == nullptr)return head;
        ListNode* newhead=reverse(head),*ans=nullptr,*prev=nullptr;
        int max=newhead->val;;
        while(newhead!=nullptr){
            if(newhead->val >= max){
                max=newhead->val;
                if(ans==nullptr){
                    ans=new ListNode(newhead->val);
                    prev=ans;
                }else{
                    prev->next=new ListNode(newhead->val);
                    prev=prev->next;
                }
            }
            newhead=newhead->next;
        }
        return reverse(ans);
    }
};
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
    ListNode* rev(ListNode* head){
         ListNode* prev,* curr,* next;
         prev=NULL,curr = head,next =head;
         while(next!=NULL){
            curr = next;
            next = curr->next;
            curr->next = prev;
            prev = curr;
         }
         return curr;
    }
     
public:
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(0);
        if(head == NULL || head->next == NULL)return head;
        head = rev(head);
        ListNode* prev,* head2;
        prev = head2 = head;
        int mx = 0;
        while(head!= NULL){
            if(head->val >= mx){
                if(prev!=head){
                  prev->next = head;
                  prev = head;}
                  mx = head->val;
            }
            head=head->next;
        }
        prev->next = NULL;
        return rev(head2);
    }
};