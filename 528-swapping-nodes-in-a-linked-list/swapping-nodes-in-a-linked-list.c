/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    if(head==NULL){
        return head;
    }
    struct ListNode* ptr1,*ptr2,*temp;
    temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int klast=count-k+1;
    temp=head;
    count=1;
    while(temp!=NULL){
        if(count==k){
            ptr1=temp;
        }
        if(count==klast){
            ptr2=temp;
        }
        count++;
        temp=temp->next;
    }
    int val=ptr1->val;
    ptr1->val=ptr2->val;
    ptr2->val=val;
    return head;
}