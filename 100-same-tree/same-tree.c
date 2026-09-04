/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int stackp[10001],stackq[10001];
int topp=-1,topq=-1;
void preorderp(struct TreeNode *p){
    if(p==NULL){
        stackp[++topp]=10002;
        return;
    }
    topp++;
    stackp[topp]=p->val;
    preorderp(p->left);
    preorderp(p->right);
}
void preorderq(struct TreeNode *q){
    if(q==NULL){
        stackq[++topq]=10002;
        return;
    }
    topq++;
    stackq[topq]=q->val;
    preorderq(q->left);
    preorderq(q->right);
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    topp=-1,topq=-1;
    preorderp(p);
    preorderq(q);

    if(topp!=topq){
        return false;
    }
    int i;
    for(i=topp;i>=0;i--){
        if(stackp[i]!=stackq[i]){
            return false;
        }
    }
    return true;
}