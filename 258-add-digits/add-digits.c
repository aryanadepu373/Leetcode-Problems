int addDigits(int num) {
    int n,rem,sum;
    while(num>=10){
        n=num;
        sum=0;
        while(n>0){
            rem=n%10;
            sum=sum+rem;
            n=n/10;
        }
        num=sum;
    }  
    return num;
}