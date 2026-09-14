/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* newnode(int val){
    struct ListNode *temp;
    temp=malloc(sizeof(struct ListNode));
    temp->val=val;
    temp->next=NULL;
    return temp;
}
struct ListNode* reverse(struct ListNode *head){
    struct ListNode *temp,*ptr,*prev;
    ptr=head;
    prev=NULL;
    while(ptr!=NULL){
        temp=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=temp;
    }
    return prev;
}
struct ListNode* doubleIt(struct ListNode* head) {
    if(head==NULL){
        return head;
    }
    int stack1[10001],top1=-1;
    int stack2[10001],top2=-1;
    struct ListNode *temp=head;
    while(temp!=NULL){
        top1++;
        stack1[top1]=temp->val;
        top2++;
        stack2[top2]=temp->val;
        temp=temp->next;
    }
    struct ListNode *ptr,*prev;
    int carry=0,sum,rem;
    ptr=newnode(0);
    temp=ptr;
    while(top1!=-1 && top2!=-1){
        sum=carry+stack1[top1]+stack2[top2];
        carry=0;
        if(sum>9){
            carry=sum/10;
            sum=sum%10;
        }
        prev=newnode(sum);
        temp->next=prev;
        temp=prev;
        top1--;
        top2--;
    }
    if(carry!=0){
        prev=newnode(carry);
        temp->next=prev;
    }
    head=reverse(ptr->next);
    return head;
}