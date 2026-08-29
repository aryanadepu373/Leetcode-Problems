/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *temp;
    temp=node;
    temp->val=temp->next->val;
    temp->next=temp->next->next;
    return;
}