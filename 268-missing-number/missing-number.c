int missingNumber(int* nums, int numsSize) {
    int n=numsSize;
    int sumtotal=(n*(n+1))/2;
    int i,arrsum=0;
    for(i=0;i<n;i++){
        arrsum=arrsum+nums[i];
    }
    int misnum=sumtotal-arrsum;
    return misnum;
}