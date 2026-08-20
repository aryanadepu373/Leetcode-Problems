/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    int *arr1=malloc(numsSize* sizeof(int));
    int *arr2=malloc(numsSize* sizeof(int));
    int i,j=0,k=0;
    arr1[j]=nums[0];
    arr2[k]=nums[1];
    i=2;
    while(i<numsSize){
        if(arr1[j]>arr2[k]){
            j++;
            arr1[j]=nums[i];
        }
        else{
            k++;
            arr2[k]=nums[i];
        }
        i++;
    }
    int *result=malloc(numsSize* sizeof(int));
    int l=0;
    for(i=0;i<=j;i++){
        result[l++]=arr1[i];
    }
    for(i=0;i<=k;i++){
        result[l++]=arr2[i];
    }
    *returnSize=numsSize;
    return result;
}