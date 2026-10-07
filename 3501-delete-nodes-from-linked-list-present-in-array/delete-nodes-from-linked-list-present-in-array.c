/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    struct ListNode *temp,*prev,*original;
    int hash[100001],i;
    for(i=0;i<100001;i++){
        hash[i]=0;
    }
    for(i=0;i<numsSize;i++){
        hash[nums[i]]=1;
    }
    prev=malloc(sizeof(struct ListNode));
    prev->val=0;
    prev->next=head;
    original=prev;
    temp=head;
    while(temp!=NULL){
        int data=temp->val;
        if(hash[data]==1){
            prev->next=temp->next;
            temp=prev->next;
        }
        else if(hash[data]==0){
            prev=temp;
            temp=prev->next;
        }
    } 
    return original->next;
}