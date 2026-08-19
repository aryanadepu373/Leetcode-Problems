/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* newnode(int val){
    struct ListNode* temp;
    temp=malloc(sizeof(struct ListNode));
    temp->val=val;
    temp->next=NULL;
    return temp;
}
struct ListNode* reverse(struct ListNode* head){
    struct ListNode *prev,*ptr,*temp;
    prev=NULL;
    temp=head;
    while(temp!=NULL){
        ptr=temp->next;
        temp->next=prev;
        prev=temp;
        temp=ptr;
    }
    return prev;
}
struct ListNode* removeNodes(struct ListNode* head) {
    int stack[100001],top=-1;
    struct ListNode *temp;
    if(head->next==NULL || head==NULL){
        return head;
    }
    temp=reverse(head);
    while(temp!=NULL){
        if(top!=-1){
            if(stack[top]<=temp->val){
                top++;
                stack[top]=temp->val;
            }
        }
        else{
            top++;
            stack[top]=temp->val;
        }
        temp=temp->next;
    }
    struct ListNode *temp1,*ptr,*head1;
    temp1=newnode(0);
    head1=temp1;
    while(top!=-1){
        ptr=newnode(stack[top]);
        temp1->next=ptr;
        temp1=ptr;
        top--;
    }
    return head1->next;
}