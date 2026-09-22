int reverse(int num){
    int rem,rev=0;
    while(num>0){
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    return rev;
}
bool isSameAfterReversals(int num) {
    int rev1=reverse(num);
    int rev2=reverse(rev1);
    if(rev2==num){
        return true;
    }   
    return false;
}