char* addStrings(char* num1, char* num2) {
    int i=strlen(num1)-1,j=strlen(num2)-1;
    int sum,carry=0,rem,k=0;
    char *res=malloc((strlen(num1)+strlen(num2)+1)*sizeof(char));
    while(i>=0 && j>=0){
        sum=carry+(num1[i]-'0')+(num2[j]-'0');
        rem=sum%10;
        carry=sum/10;
        res[k++]=rem+'0';
        i--;
        j--;
    }
    while(i>=0){
        sum=carry+(num1[i]-'0');
        rem=sum%10;
        carry=sum/10;
        res[k++]=rem+'0';
        i--;
    }
    while(j>=0){
        sum=carry+(num2[j]-'0');
        rem=sum%10;
        carry=sum/10;
        res[k++]=rem+'0';
        j--;
    }
    if(carry>0){
        res[k++]=carry+'0';
    }
    i=0,j=k-1;
    while(i<j){
        int temp=res[j];
        res[j]=res[i];
        res[i]=temp;
        i++;
        j--;
    }
    res[k]='\0';
    return res;
}