int sum(int val){
    int rem,sum=0;
    while(val>0){
        rem=val%10;
        sum=sum+rem;
        val=val/10;
    }
    return sum;
}
int smallestIndex(int* nums, int numsSize) {
    int i=0,val,min=1001;
    while(i<numsSize){
        val=sum(nums[i]);
        if(i==val){
            if(val<min){
                min=val;
            }
        }
        i++;
    } 
    if(min==1001){
        min=-1;
    }

    return min;  
}