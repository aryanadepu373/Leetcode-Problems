bool isPowerOfThree(int n) {
    if(n<=0){
        return false;
    }
    else if (n==1){
        return true;
    }
    long long i=1;
    while(i<=n){
        if(i==n){
            return true;
        }
        i=3*i;
    }
    return false;
}