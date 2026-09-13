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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int stack1[101],top1=-1;
    int stack2[101],top2=-1;
    int stackres[101],topres=-1;
    struct ListNode *temp=l1;
    while(temp!=NULL){
        top1++;
        stack1[top1]=temp->val;
        temp=temp->next;
    }
    temp=l2;
    while(temp!=NULL){
        top2++;
        stack2[top2]=temp->val;
        temp=temp->next;
    }
    int carry=0,sum,data;
    while(top1!=-1 && top2!=-1){
        sum=stack1[top1]+stack2[top2]+carry;
        carry=0;
        if(sum>9){
            carry=sum/10;
            sum=sum%10;
        }
        topres++;
        stackres[topres]=sum;
        top1--;
        top2--;
    }
    while(top1!=-1){
        sum=stack1[top1]+carry;
        carry=0;
        if(sum>9){
            carry=sum/10;
            sum=sum%10;
        }
        topres++;
        stackres[topres]=sum;
        top1--;
    }
    while(top2!=-1){
        sum=stack2[top2]+carry;
        carry=0;
        if(sum>9){
            carry=sum/10;
            sum=sum%10;
        }
        topres++;
        stackres[topres]=sum;
        top2--;
    }
    struct ListNode *res=NULL,*tempres;
    int i;
    if(carry!=0){
        res=newnode(carry);
    }
    tempres=res;
    for(i=topres;i>=0;i--){
        struct ListNode *prev;
        prev=newnode(stackres[i]);
        if(res==NULL){
            res=prev;
            tempres=res;
        }
        else{
            tempres->next=prev;
            tempres=prev;
        }
    }
    return res;
}