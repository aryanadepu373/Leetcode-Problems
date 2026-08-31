/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    struct ListNode *temp;
    int *b=malloc(2* sizeof(int));
    temp=head;
    if(temp==NULL || temp->next==NULL || temp->next->next==NULL){
        b[0]=-1;
        b[1]=-1;
        *returnSize=2;
        return b;
    }
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int a[count],i=0;
    temp=head;
    while(temp!=NULL){
        a[i]=temp->val;
        temp=temp->next;
        i++;
    }
    int max=-1,min=-1,maxd=0,mind=100001,mindis=0;;
    for(i=1;i<count-1;i++){
        if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])){
            if(max==-1){
                max=i+1;
            }
            else if(min==-1){
                min=i+1;

                mindis=min-max;
                if(mindis<mind){
                    mind=mindis;
                }
                maxd=min-max;
            }
            else{
                maxd=(i+1)-max;
                mindis=(i+1)-min;
                if(mindis<mind){
                    mind=mindis;
                }
                min=i+1;
            }
        }
    }
    if(min==-1 || max==-1){
        b[0]=-1;
        b[1]=-1;
    }
    else{
        b[0]=mind;
        b[1]=maxd;
    }
    *returnSize=2;
    return b;
}