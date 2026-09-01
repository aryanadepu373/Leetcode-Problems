/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i=0,j=digitsSize-1;
    while(i<j){
        int temp=digits[i];
        digits[i]=digits[j];
        digits[j]=temp;
        i++;
        j--;
    }
    int *b=malloc((digitsSize+1)* sizeof(int));
    int k=0,sum=0,rem,carry=0;
    for(i=0;i<digitsSize;i++){
        if(i==0){
            sum=digits[i]+1;
            rem=sum%10;
            b[k++]=rem;
            carry=sum/10;
        }
        else{
            sum=carry+digits[i];
            rem=sum%10;
            b[k++]=rem;
            carry=sum/10;
        }
    }
    if(carry!=0){
        b[k++]=carry;
    }
    i=0,j=k-1;
    while(i<j){
        int temp=b[i];
        b[i]=b[j];
        b[j]=temp;
        i++;
        j--;
    }
    if(carry!=0){
        *returnSize=digitsSize+1;
        return b;
    }
    *returnSize=digitsSize;
    return b;
}