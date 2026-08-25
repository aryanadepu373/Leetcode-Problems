int missingMultiple(int* nums, int numsSize, int k) {
    int hash[10001]={0},i;
    for(i=0;i<numsSize;i++){
        hash[nums[i]]=1;
    }
    for(i=k;i<10001;i=i+k){
        if(hash[i]!=1){
            return i;
        }
    }
    return -1;
}
