char* removeDuplicates(char* s, int k) {
    int i,j;
    char stack[100001];
    int count[100001],top=-1;
    i=0;
    while(s[i]!='\0'){
        if(top>=0 && stack[top]==s[i]){
            count[top]++;
        }
        else{
            top++;
            count[top]=1;
            stack[top]=s[i];
        }
        if(count[top]==k){
            top--;
        }
        i++;
    }
    int l=0;
    for(i=0;i<=top;i++){
        for(j=0;j<count[i];j++){
            s[l++]=stack[i];
        }
    }
    s[l]='\0';
    return s;
}