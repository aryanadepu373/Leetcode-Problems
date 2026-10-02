/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int n,n1,found;
    int *b=malloc((right-left)* sizeof(int));
    int i=0;
    while(left<=right){
        n=left;
        n1=n;
        found=1;
        while(n1>0){
            int val=n1%10;
            if(val==0 || n%val!=0){
                found=0;
                break;
            }
            n1=n1/10;
        }
        if(found==1){
            b[i++]=n;
        }
        left++;
    }
    *returnSize=i;
    return b;
    
}