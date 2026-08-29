/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int *arr=malloc(numsSize *sizeof(int));
    int k=0,i;
    for(i=0;i<numsSize;i++){
        if(nums[i]%2==0){
            arr[k]=nums[i];
            k++;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]%2!=0){
            arr[k]=nums[i];
            k++;
        }
    }
    *returnSize=k;
    return arr;
}