char* reverseStr(char* s, int k) {
    int len=strlen(s);
    if(len<k){
        int i=0,j=len-1;
        while(i<j){
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
    }
    else if(len>=k && len<(2*k)){
        int i=0,j=k-1;
        while(i<j){
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
    }
    else{
        int i=0,j=k-1,start=0;
        while(i<len){
            i=start;
            j=i+k-1;
            if(j>=len){
                j=len-1;
            }
            while(i<j){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
            start=start+(2*k);
        }
    }
    return s;
}