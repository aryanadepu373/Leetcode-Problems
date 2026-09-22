int findNumbers(int* nums, int numsSize) {
    int i,res=0,count,rem;
    for(i=0;i<numsSize;i++){
        count=0;
        while(nums[i]>0){
            rem=nums[i]%10;
            count++;
            nums[i]=nums[i]/10;
        }
        if(count%2==0){
            res++;
        }
    }
    return res;
}