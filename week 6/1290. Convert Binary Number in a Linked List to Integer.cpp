/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    struct ListNode* ptr=head;
    int arr[30]={0};
    int i=0,ans=0,n=0;
    while(ptr!=NULL)
    {
        arr[i++]=ptr->val;
        ptr=ptr->next;
        n++;
    }
    for(int j=n-1;j>=0;j--)
    {
        int k=n-j;
        while(k>0 && arr[j]!=0)
        {
            arr[j]*=2;
            k--;
        }
        // printf("%d ",arr[j]);
        ans+=arr[j]/2;
    }
    return ans;
}