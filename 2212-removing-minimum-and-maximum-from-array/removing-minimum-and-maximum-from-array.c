int minimumDeletions(int* nums, int numsSize) {
    int i,max=nums[0],min=nums[0],maxcountF=1,mincountF=1;
    for(i=1;i<numsSize;i++){
        if(nums[i]>max){
            max=nums[i];
            maxcountF=i+1;
        }
        if(nums[i]<min){
            min=nums[i];
            mincountF=i+1;
        }
    }   
    max=nums[numsSize-1],min=nums[numsSize-1];
    int maxcountB=1,mincountB=1;
    for(i=numsSize-2;i>=0;i--){
        if(nums[i]>max){
            max=nums[i];
            maxcountB=numsSize-i;
        }
        if(nums[i]<min){
            min=nums[i];
            mincountB=numsSize-i;
        }
    }
    int case1,case2,case3,case4,res;
    case1= maxcountF>mincountF?maxcountF:mincountF;
    case2= maxcountB>mincountB?maxcountB:mincountB;
    case3=maxcountF+mincountB;
    case4=maxcountB+mincountF;

    res=case1;
    if(case2<res){
        res=case2;
    }
    if(case3<res){
        res=case3;
    }
    if(case4<res){
        res=case4;
    }
    return res;
}