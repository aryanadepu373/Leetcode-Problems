/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *newnode(int val){
    struct ListNode *temp;
    temp=malloc(sizeof(struct ListNode));
    temp->val=val;
    temp->next=NULL;
    return temp;
}
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    struct ListNode *temp,*ptr,*temph,*headt;
    temp=head;
    temph=newnode(0);
    headt=temph;
    while(temp!=NULL && temp->next!=NULL){
        ptr=newnode(temp->val);
        temph->next=ptr;
        temph=ptr;
        temp=temp->next->next;
    } 
    if(temp!=NULL){
        ptr=newnode(temp->val);
        temph->next=ptr;
        temph=ptr;
    }
    temp=head->next;
    while(temp!=NULL && temp->next!=NULL){
        ptr=newnode(temp->val);
        temph->next=ptr;
        temph=ptr;
        temp=temp->next->next;
    }
    if(temp!=NULL){
        ptr=newnode(temp->val);
        temph->next=ptr;
        temph=ptr;
    }
    return headt->next;
}