bool checkDivisibility(int n) {
    int rem,sum=0,prod=1,n1,res;
    n1=n;
    while(n1>0){
        rem=n1%10;
        sum=sum+rem;
        prod=prod*rem;
        n1=n1/10;
    }
    res=sum+prod;
    if(n%res==0){
        return true;
    }
    return false;
}