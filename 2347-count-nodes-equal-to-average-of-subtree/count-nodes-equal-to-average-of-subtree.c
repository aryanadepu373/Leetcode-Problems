/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum=0,res=0;
void findSum(struct TreeNode *root,int *count){
    if(root==NULL){
        return;
    }
    sum=sum+root->val;
    (*count)++;
    findSum(root->left,count);
    findSum(root->right,count);
    return;
}
void avgCount(struct TreeNode* root){
    if(root==NULL){
        return;
    }
    int count=0;
    sum=0;
    findSum(root,&count);
    int avg=sum/count;
    if(root->val==avg){
        res++;
    }
    avgCount(root->left);
    avgCount(root->right);
    return;
}
int averageOfSubtree(struct TreeNode* root) {
    sum=0,res=0;
    avgCount(root);
    return res;
}