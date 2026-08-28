char* clearDigits(char* s) {
    int i=0,stack[101],top=-1;
    while(s[i]!='\0'){
        if(s[i]!='0' && s[i]!='1'&& s[i]!='2'&& s[i]!='3'&& s[i]!='4'&& s[i]!='5'&& s[i]!='6'&& s[i]!='7'&& s[i]!='8'&& s[i]!='9'){
            top++;
            stack[top]=s[i];
        }
        else{
            top--;
        }
        i++;
    }
    int j=0;
    if(top!=-1){
        for(i=top;i>=0;i--){
            s[j++]=stack[top-i];
        }
    }
    s[j]='\0';
    return s;
}