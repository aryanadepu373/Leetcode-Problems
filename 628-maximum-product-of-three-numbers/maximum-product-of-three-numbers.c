void merge(int low,int mid,int high,int* nums){
    int left=low;
    int right=mid+1;
    int b[high-low+1],i=0;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            b[i++]=nums[left++];
        }
        else{
            b[i++]=nums[right++];
        }
    }
    while(left<=mid){
        b[i++]=nums[left++];
    }
    while(right<=high){
        b[i++]=nums[right++];
    }
    int j;
    for(j=low;j<=high;j++){
        nums[j]=b[j-low];
    }
    return;
}
void mergesort(int low,int high,int* nums){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(low,mid,nums);
        mergesort(mid+1,high,nums);
        merge(low,mid,high,nums);
    }
    return;
}
int maximumProduct(int* nums, int numsSize) {
    mergesort(0,numsSize-1,nums);
    int product1=nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3];
    int product2=nums[0]*nums[1]*nums[numsSize-1];
    return ((product1>product2)?product1:product2);
}